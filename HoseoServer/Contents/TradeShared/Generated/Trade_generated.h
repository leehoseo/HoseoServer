// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_TRADE_H_
#define FLATBUFFERS_GENERATED_TRADE_H_

#include "flatbuffers/flatbuffers.h"
#include "Network/PacketBase.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 1 &&
              FLATBUFFERS_VERSION_REVISION == 21,
             "Non-compatible flatbuffers version included");

struct Person;
struct PersonBuilder;

struct Person : public CPacketBase, private ::flatbuffers::Table {
  typedef PersonBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_AGE = 6
  };
  const ::flatbuffers::String *name() const {
    return GetPointer<const ::flatbuffers::String *>(VT_NAME);
  }
  int32_t age() const {
    return GetField<int32_t>(VT_AGE, 0);
  }
  virtual bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<int32_t>(verifier, VT_AGE, 4) &&
           verifier.EndTable();
  }
};

struct PersonBuilder {
  typedef Person Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_name(::flatbuffers::Offset<::flatbuffers::String> name) {
    fbb_.AddOffset(Person::VT_NAME, name);
  }
  void add_age(int32_t age) {
    fbb_.AddElement<int32_t>(Person::VT_AGE, age, 0);
  }
  explicit PersonBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Person> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Person>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Person> CreatePerson(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::String> name = 0,
    int32_t age = 0) {
  PersonBuilder builder_(_fbb);
  builder_.add_age(age);
  builder_.add_name(name);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Person> CreatePersonDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    int32_t age = 0) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  return CreatePerson(
      _fbb,
      name__,
      age);
}

inline const Person *GetPerson(const void *buf) {
  return ::flatbuffers::GetRoot<Person>(buf);
}

inline const Person *GetSizePrefixedPerson(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<Person>(buf);
}

inline bool VerifyPersonBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Person>(nullptr);
}

inline bool VerifySizePrefixedPersonBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Person>(nullptr);
}

inline void FinishPersonBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<Person> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedPersonBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<Person> root) {
  fbb.FinishSizePrefixed(root);
}

#endif  // FLATBUFFERS_GENERATED_TRADE_H_
