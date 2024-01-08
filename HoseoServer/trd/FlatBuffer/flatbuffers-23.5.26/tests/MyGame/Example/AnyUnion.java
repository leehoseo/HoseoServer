﻿// automatically generated by the FlatBuffers compiler, do not modify

package MyGame.Example;

import com.google.flatbuffers.FlatBufferBuilder;

public class AnyUnion {
  private byte type;
  private Object value;

  public byte getType() { return type; }

  public void setType(byte type) { this.type = type; }

  public Object getValue() { return value; }

  public void setValue(Object value) { this.value = value; }

  public AnyUnion() {
    this.type = Any.NONE;
    this.value = null;
  }

  public MyGame.Example.MonsterT asMonster() { return (MyGame.Example.MonsterT) value; }
  MyGame.Example.TestSimpleTableWithEnumT asTestSimpleTableWithEnum() { return (MyGame.Example.TestSimpleTableWithEnumT) value; }
  public MyGame.Example2.MonsterT asMyGame_Example2_Monster() { return (MyGame.Example2.MonsterT) value; }

  public static int pack(FlatBufferBuilder builder, AnyUnion _o) {
    switch (_o.type) {
      case Any.Monster: return MyGame.Example.Monster.pack(builder, _o.asMonster());
      case Any.TestSimpleTableWithEnum: return MyGame.Example.TestSimpleTableWithEnum.pack(builder, _o.asTestSimpleTableWithEnum());
      case Any.MyGame_Example2_Monster: return MyGame.Example2.Monster.pack(builder, _o.asMyGame_Example2_Monster());
      default: return 0;
    }
  }
}

