﻿/*
 * Copyright 2016 Google Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "flatbuffers/code_generators.h"

#include <assert.h>

#include <cmath>

#include "flatbuffers/base.h"
#include "flatbuffers/util.h"

#if defined(_MSC_VER)
#  pragma warning(push)
#  pragma warning(disable : 4127)  // C4127: conditional expression is constant
#endif

namespace flatbuffers {

std::string JavaCSharpMakeRule(const bool java, const Parser &parser,
                               const std::string &path,
                               const std::string &file_name) {
  const std::string file_extension = java ? ".java" : ".cs";
  std::string make_rule;

  for (auto it = parser.enums_.vec.begin(); it != parser.enums_.vec.end();
       ++it) {
    auto &enum_def = **it;
    if (!make_rule.empty()) make_rule += " ";
    std::string directory =
        BaseGenerator::NamespaceDir(parser, path, *enum_def.defined_namespace);
    make_rule += directory + enum_def.name + file_extension;
  }

  for (auto it = parser.structs_.vec.begin(); it != parser.structs_.vec.end();
       ++it) {
    auto &struct_def = **it;
    if (!make_rule.empty()) make_rule += " ";
    std::string directory = BaseGenerator::NamespaceDir(
        parser, path, *struct_def.defined_namespace);
    make_rule += directory + struct_def.name + file_extension;
  }

  make_rule += ": ";
  auto included_files = parser.GetIncludedFilesRecursive(file_name);
  for (auto it = included_files.begin(); it != included_files.end(); ++it) {
    make_rule += " " + *it;
  }
  return make_rule;
}

void CodeWriter::operator+=(std::string text) {
  if (!ignore_ident_ && !text.empty()) AppendIdent(stream_);

  while (true) {
    auto begin = text.find("{{");
    if (begin == std::string::npos) { break; }

    auto end = text.find("}}");
    if (end == std::string::npos || end < begin) { break; }

    // Write all the text before the first {{ into the stream.
    stream_.write(text.c_str(), begin);

    // The key is between the {{ and }}.
    const std::string key = text.substr(begin + 2, end - begin - 2);

    // Find the value associated with the key.  If it exists, write the
    // value into the stream, otherwise write the key itself into the stream.
    auto iter = value_map_.find(key);
    if (iter != value_map_.end()) {
      const std::string &value = iter->second;
      stream_ << value;
    } else {
      FLATBUFFERS_ASSERT(false && "could not find key");
      stream_ << key;
    }

    // Update the text to everything after the }}.
    text = text.substr(end + 2);
  }
  if (!text.empty() && text.back() == '\\') {
    text.pop_back();
    ignore_ident_ = true;
    stream_ << text;
  } else {
    ignore_ident_ = false;
    stream_ << text << std::endl;
  }
}

void CodeWriter::AppendIdent(std::stringstream &stream) {
  int lvl = cur_ident_lvl_;
  while (lvl--) {
    stream.write(pad_.c_str(), static_cast<std::streamsize>(pad_.size()));
  }
}

const char *BaseGenerator::FlatBuffersGeneratedWarning() {
  return "automatically generated by the FlatBuffers compiler,"
         " do not modify";
}

std::string BaseGenerator::NamespaceDir(const Parser &parser,
                                        const std::string &path,
                                        const Namespace &ns,
                                        const bool dasherize) {
  EnsureDirExists(path);
  if (parser.opts.one_file) return path;
  std::string namespace_dir = path;  // Either empty or ends in separator.
  auto &namespaces = ns.components;
  for (auto it = namespaces.begin(); it != namespaces.end(); ++it) {
    namespace_dir +=
        !dasherize ? *it : ConvertCase(*it, Case::kDasher, Case::kUpperCamel);
    namespace_dir += kPathSeparator;
    EnsureDirExists(namespace_dir);
  }
  return namespace_dir;
}

std::string BaseGenerator::NamespaceDir(const Namespace &ns,
                                        const bool dasherize) const {
  return BaseGenerator::NamespaceDir(parser_, path_, ns, dasherize);
}

std::string BaseGenerator::FullNamespace(const char *separator,
                                         const Namespace &ns) {
  std::string namespace_name;
  auto &namespaces = ns.components;
  for (auto it = namespaces.begin(); it != namespaces.end(); ++it) {
    if (namespace_name.length()) namespace_name += separator;
    namespace_name += *it;
  }
  return namespace_name;
}

std::string BaseGenerator::LastNamespacePart(const Namespace &ns) {
  if (!ns.components.empty())
    return ns.components.back();
  else
    return std::string("");
}

// Ensure that a type is prefixed with its namespace.
std::string BaseGenerator::WrapInNameSpace(const Namespace *ns,
                                           const std::string &name) const {
  std::string qualified_name = qualifying_start_;
  for (auto it = ns->components.begin(); it != ns->components.end(); ++it)
    qualified_name += *it + qualifying_separator_;
  return qualified_name + name;
}

std::string BaseGenerator::WrapInNameSpace(const Definition &def,
                                           const std::string &suffix) const {
  return WrapInNameSpace(def.defined_namespace, def.name + suffix);
}

std::string BaseGenerator::GetNameSpace(const Definition &def) const {
  const Namespace *ns = def.defined_namespace;
  if (CurrentNameSpace() == ns) return "";
  std::string qualified_name = qualifying_start_;
  for (auto it = ns->components.begin(); it != ns->components.end(); ++it) {
    qualified_name += *it;
    if ((it + 1) != ns->components.end()) {
      qualified_name += qualifying_separator_;
    }
  }

  return qualified_name;
}

std::string BaseGenerator::GeneratedFileName(const std::string &path,
                                             const std::string &file_name,
                                             const IDLOptions &options) const {
  return path + file_name + options.filename_suffix + "." +
         (options.filename_extension.empty() ? default_extension_
                                             : options.filename_extension);
}

// Generate a documentation comment, if available.
void GenComment(const std::vector<std::string> &dc, std::string *code_ptr,
                const CommentConfig *config, const char *prefix) {
  if (dc.begin() == dc.end()) {
    // Don't output empty comment blocks with 0 lines of comment content.
    return;
  }

  std::string &code = *code_ptr;
  if (config != nullptr && config->first_line != nullptr) {
    code += std::string(prefix) + std::string(config->first_line) + "\n";
  }
  std::string line_prefix =
      std::string(prefix) +
      ((config != nullptr && config->content_line_prefix != nullptr)
           ? config->content_line_prefix
           : "///");
  for (auto it = dc.begin(); it != dc.end(); ++it) {
    code += line_prefix + *it + "\n";
  }
  if (config != nullptr && config->last_line != nullptr) {
    code += std::string(prefix) + std::string(config->last_line) + "\n";
  }
}

template<typename T>
std::string FloatConstantGenerator::GenFloatConstantImpl(
    const FieldDef &field) const {
  const auto &constant = field.value.constant;
  T v;
  auto done = StringToNumber(constant.c_str(), &v);
  FLATBUFFERS_ASSERT(done);
  if (done) {
#if (!defined(_MSC_VER) || (_MSC_VER >= 1800))
    if (std::isnan(v)) return NaN(v);
    if (std::isinf(v)) return Inf(v);
#endif
    return Value(v, constant);
  }
  return "#";  // compile time error
}

std::string FloatConstantGenerator::GenFloatConstant(
    const FieldDef &field) const {
  switch (field.value.type.base_type) {
    case BASE_TYPE_FLOAT: return GenFloatConstantImpl<float>(field);
    case BASE_TYPE_DOUBLE: return GenFloatConstantImpl<double>(field);
    default: {
      FLATBUFFERS_ASSERT(false);
      return "INVALID_BASE_TYPE";
    }
  };
}

TypedFloatConstantGenerator::TypedFloatConstantGenerator(
    const char *double_prefix, const char *single_prefix,
    const char *nan_number, const char *pos_inf_number,
    const char *neg_inf_number)
    : double_prefix_(double_prefix),
      single_prefix_(single_prefix),
      nan_number_(nan_number),
      pos_inf_number_(pos_inf_number),
      neg_inf_number_(neg_inf_number) {}

std::string TypedFloatConstantGenerator::MakeNaN(
    const std::string &prefix) const {
  return prefix + nan_number_;
}
std::string TypedFloatConstantGenerator::MakeInf(
    bool neg, const std::string &prefix) const {
  if (neg)
    return !neg_inf_number_.empty() ? (prefix + neg_inf_number_)
                                    : ("-" + prefix + pos_inf_number_);
  else
    return prefix + pos_inf_number_;
}

std::string TypedFloatConstantGenerator::Value(double v,
                                               const std::string &src) const {
  (void)v;
  return src;
}

std::string TypedFloatConstantGenerator::Inf(double v) const {
  return MakeInf(v < 0, double_prefix_);
}

std::string TypedFloatConstantGenerator::NaN(double v) const {
  (void)v;
  return MakeNaN(double_prefix_);
}

std::string TypedFloatConstantGenerator::Value(float v,
                                               const std::string &src) const {
  (void)v;
  return src + "f";
}

std::string TypedFloatConstantGenerator::Inf(float v) const {
  return MakeInf(v < 0, single_prefix_);
}

std::string TypedFloatConstantGenerator::NaN(float v) const {
  (void)v;
  return MakeNaN(single_prefix_);
}

SimpleFloatConstantGenerator::SimpleFloatConstantGenerator(
    const char *nan_number, const char *pos_inf_number,
    const char *neg_inf_number)
    : nan_number_(nan_number),
      pos_inf_number_(pos_inf_number),
      neg_inf_number_(neg_inf_number) {}

std::string SimpleFloatConstantGenerator::Value(double v,
                                                const std::string &src) const {
  (void)v;
  return src;
}

std::string SimpleFloatConstantGenerator::Inf(double v) const {
  return (v < 0) ? neg_inf_number_ : pos_inf_number_;
}

std::string SimpleFloatConstantGenerator::NaN(double v) const {
  (void)v;
  return nan_number_;
}

std::string SimpleFloatConstantGenerator::Value(float v,
                                                const std::string &src) const {
  return this->Value(static_cast<double>(v), src);
}

std::string SimpleFloatConstantGenerator::Inf(float v) const {
  return this->Inf(static_cast<double>(v));
}

std::string SimpleFloatConstantGenerator::NaN(float v) const {
  return this->NaN(static_cast<double>(v));
}

}  // namespace flatbuffers

#if defined(_MSC_VER)
#  pragma warning(pop)
#endif
