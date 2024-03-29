﻿// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

using global::System;
using global::System.Collections.Generic;
using global::Google.FlatBuffers;

public struct FCT_Login : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static void ValidateVersion() { FlatBufferConstants.FLATBUFFERS_23_5_26(); }
  public static FCT_Login GetRootAsFCT_Login(ByteBuffer _bb) { return GetRootAsFCT_Login(_bb, new FCT_Login()); }
  public static FCT_Login GetRootAsFCT_Login(ByteBuffer _bb, FCT_Login obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public void __init(int _i, ByteBuffer _bb) { __p = new Table(_i, _bb); }
  public FCT_Login __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public string Name { get { int o = __p.__offset(4); return o != 0 ? __p.__string(o + __p.bb_pos) : null; } }
#if ENABLE_SPAN_T
  public Span<byte> GetNameBytes() { return __p.__vector_as_span<byte>(4, 1); }
#else
  public ArraySegment<byte>? GetNameBytes() { return __p.__vector_as_arraysegment(4); }
#endif
  public byte[] GetNameArray() { return __p.__vector_as_array<byte>(4); }
  public string Pwd { get { int o = __p.__offset(6); return o != 0 ? __p.__string(o + __p.bb_pos) : null; } }
#if ENABLE_SPAN_T
  public Span<byte> GetPwdBytes() { return __p.__vector_as_span<byte>(6, 1); }
#else
  public ArraySegment<byte>? GetPwdBytes() { return __p.__vector_as_arraysegment(6); }
#endif
  public byte[] GetPwdArray() { return __p.__vector_as_array<byte>(6); }

  public static Offset<FCT_Login> CreateFCT_Login(FlatBufferBuilder builder,
      StringOffset nameOffset = default(StringOffset),
      StringOffset pwdOffset = default(StringOffset)) {
    builder.StartTable(2);
    FCT_Login.AddPwd(builder, pwdOffset);
    FCT_Login.AddName(builder, nameOffset);
    return FCT_Login.EndFCT_Login(builder);
  }

  public static void StartFCT_Login(FlatBufferBuilder builder) { builder.StartTable(2); }
  public static void AddName(FlatBufferBuilder builder, StringOffset nameOffset) { builder.AddOffset(0, nameOffset.Value, 0); }
  public static void AddPwd(FlatBufferBuilder builder, StringOffset pwdOffset) { builder.AddOffset(1, pwdOffset.Value, 0); }
  public static Offset<FCT_Login> EndFCT_Login(FlatBufferBuilder builder) {
    int o = builder.EndTable();
    return new Offset<FCT_Login>(o);
  }
}


static public class FCT_LoginVerify
{
  static public bool Verify(Google.FlatBuffers.Verifier verifier, uint tablePos)
  {
    return verifier.VerifyTableStart(tablePos)
      && verifier.VerifyString(tablePos, 4 /*Name*/, false)
      && verifier.VerifyString(tablePos, 6 /*Pwd*/, false)
      && verifier.VerifyTableEnd(tablePos);
  }
}
