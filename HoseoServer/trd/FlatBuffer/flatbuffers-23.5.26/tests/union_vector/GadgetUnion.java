﻿// automatically generated by the FlatBuffers compiler, do not modify

import com.google.flatbuffers.FlatBufferBuilder;

public class GadgetUnion {
  private byte type;
  private Object value;

  public byte getType() { return type; }

  public void setType(byte type) { this.type = type; }

  public Object getValue() { return value; }

  public void setValue(Object value) { this.value = value; }

  public GadgetUnion() {
    this.type = Gadget.NONE;
    this.value = null;
  }

  public FallingTubT asFallingTub() { return (FallingTubT) value; }
  public HandFanT asHandFan() { return (HandFanT) value; }

  public static int pack(FlatBufferBuilder builder, GadgetUnion _o) {
    switch (_o.type) {
      case Gadget.FallingTub: return FallingTub.pack(builder, _o.asFallingTub());
      case Gadget.HandFan: return HandFan.pack(builder, _o.asHandFan());
      default: return 0;
    }
  }
}

