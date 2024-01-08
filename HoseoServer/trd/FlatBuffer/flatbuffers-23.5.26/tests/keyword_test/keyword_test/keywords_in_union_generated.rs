﻿// automatically generated by the FlatBuffers compiler, do not modify
// @generated
extern crate alloc;
extern crate flatbuffers;
use alloc::boxed::Box;
use alloc::string::{String, ToString};
use alloc::vec::Vec;
use core::mem;
use core::cmp::Ordering;
use self::flatbuffers::{EndianScalar, Follow};
use super::*;
#[deprecated(since = "2.0.0", note = "Use associated constants instead. This will no longer be generated in 2021.")]
pub const ENUM_MIN_KEYWORDS_IN_UNION: u8 = 0;
#[deprecated(since = "2.0.0", note = "Use associated constants instead. This will no longer be generated in 2021.")]
pub const ENUM_MAX_KEYWORDS_IN_UNION: u8 = 2;
#[deprecated(since = "2.0.0", note = "Use associated constants instead. This will no longer be generated in 2021.")]
#[allow(non_camel_case_types)]
pub const ENUM_VALUES_KEYWORDS_IN_UNION: [KeywordsInUnion; 3] = [
  KeywordsInUnion::NONE,
  KeywordsInUnion::static_,
  KeywordsInUnion::internal,
];

#[derive(Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash, Default)]
#[repr(transparent)]
pub struct KeywordsInUnion(pub u8);
#[allow(non_upper_case_globals)]
impl KeywordsInUnion {
  pub const NONE: Self = Self(0);
  pub const static_: Self = Self(1);
  pub const internal: Self = Self(2);

  pub const ENUM_MIN: u8 = 0;
  pub const ENUM_MAX: u8 = 2;
  pub const ENUM_VALUES: &'static [Self] = &[
    Self::NONE,
    Self::static_,
    Self::internal,
  ];
  /// Returns the variant's name or "" if unknown.
  pub fn variant_name(self) -> Option<&'static str> {
    match self {
      Self::NONE => Some("NONE"),
      Self::static_ => Some("static_"),
      Self::internal => Some("internal"),
      _ => None,
    }
  }
}
impl core::fmt::Debug for KeywordsInUnion {
  fn fmt(&self, f: &mut core::fmt::Formatter) -> core::fmt::Result {
    if let Some(name) = self.variant_name() {
      f.write_str(name)
    } else {
      f.write_fmt(format_args!("<UNKNOWN {:?}>", self.0))
    }
  }
}
impl<'a> flatbuffers::Follow<'a> for KeywordsInUnion {
  type Inner = Self;
  #[inline]
  unsafe fn follow(buf: &'a [u8], loc: usize) -> Self::Inner {
    let b = flatbuffers::read_scalar_at::<u8>(buf, loc);
    Self(b)
  }
}

impl flatbuffers::Push for KeywordsInUnion {
    type Output = KeywordsInUnion;
    #[inline]
    unsafe fn push(&self, dst: &mut [u8], _written_len: usize) {
        flatbuffers::emplace_scalar::<u8>(dst, self.0);
    }
}

impl flatbuffers::EndianScalar for KeywordsInUnion {
  type Scalar = u8;
  #[inline]
  fn to_little_endian(self) -> u8 {
    self.0.to_le()
  }
  #[inline]
  #[allow(clippy::wrong_self_convention)]
  fn from_little_endian(v: u8) -> Self {
    let b = u8::from_le(v);
    Self(b)
  }
}

impl<'a> flatbuffers::Verifiable for KeywordsInUnion {
  #[inline]
  fn run_verifier(
    v: &mut flatbuffers::Verifier, pos: usize
  ) -> Result<(), flatbuffers::InvalidFlatbuffer> {
    use self::flatbuffers::Verifiable;
    u8::run_verifier(v, pos)
  }
}

impl flatbuffers::SimpleToVerifyInSlice for KeywordsInUnion {}
pub struct KeywordsInUnionUnionTableOffset {}

#[allow(clippy::upper_case_acronyms)]
#[non_exhaustive]
#[derive(Debug, Clone, PartialEq)]
pub enum KeywordsInUnionT {
  NONE,
  Static_(Box<KeywordsInTableT>),
  Internal(Box<KeywordsInTableT>),
}
impl Default for KeywordsInUnionT {
  fn default() -> Self {
    Self::NONE
  }
}
impl KeywordsInUnionT {
  pub fn keywords_in_union_type(&self) -> KeywordsInUnion {
    match self {
      Self::NONE => KeywordsInUnion::NONE,
      Self::Static_(_) => KeywordsInUnion::static_,
      Self::Internal(_) => KeywordsInUnion::internal,
    }
  }
  pub fn pack(&self, fbb: &mut flatbuffers::FlatBufferBuilder) -> Option<flatbuffers::WIPOffset<flatbuffers::UnionWIPOffset>> {
    match self {
      Self::NONE => None,
      Self::Static_(v) => Some(v.pack(fbb).as_union_value()),
      Self::Internal(v) => Some(v.pack(fbb).as_union_value()),
    }
  }
  /// If the union variant matches, return the owned KeywordsInTableT, setting the union to NONE.
  pub fn take_static_(&mut self) -> Option<Box<KeywordsInTableT>> {
    if let Self::Static_(_) = self {
      let v = core::mem::replace(self, Self::NONE);
      if let Self::Static_(w) = v {
        Some(w)
      } else {
        unreachable!()
      }
    } else {
      None
    }
  }
  /// If the union variant matches, return a reference to the KeywordsInTableT.
  pub fn as_static_(&self) -> Option<&KeywordsInTableT> {
    if let Self::Static_(v) = self { Some(v.as_ref()) } else { None }
  }
  /// If the union variant matches, return a mutable reference to the KeywordsInTableT.
  pub fn as_static__mut(&mut self) -> Option<&mut KeywordsInTableT> {
    if let Self::Static_(v) = self { Some(v.as_mut()) } else { None }
  }
  /// If the union variant matches, return the owned KeywordsInTableT, setting the union to NONE.
  pub fn take_internal(&mut self) -> Option<Box<KeywordsInTableT>> {
    if let Self::Internal(_) = self {
      let v = core::mem::replace(self, Self::NONE);
      if let Self::Internal(w) = v {
        Some(w)
      } else {
        unreachable!()
      }
    } else {
      None
    }
  }
  /// If the union variant matches, return a reference to the KeywordsInTableT.
  pub fn as_internal(&self) -> Option<&KeywordsInTableT> {
    if let Self::Internal(v) = self { Some(v.as_ref()) } else { None }
  }
  /// If the union variant matches, return a mutable reference to the KeywordsInTableT.
  pub fn as_internal_mut(&mut self) -> Option<&mut KeywordsInTableT> {
    if let Self::Internal(v) = self { Some(v.as_mut()) } else { None }
  }
}
