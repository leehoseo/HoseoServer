﻿// automatically generated by the FlatBuffers compiler, do not modify

import * as flatbuffers from 'flatbuffers';

import { Color } from '../../my-game/example/color.js';


export class TestSimpleTableWithEnum implements flatbuffers.IUnpackableObject<TestSimpleTableWithEnumT> {
  bb: flatbuffers.ByteBuffer|null = null;
  bb_pos = 0;
  __init(i:number, bb:flatbuffers.ByteBuffer):TestSimpleTableWithEnum {
  this.bb_pos = i;
  this.bb = bb;
  return this;
}

static getRootAsTestSimpleTableWithEnum(bb:flatbuffers.ByteBuffer, obj?:TestSimpleTableWithEnum):TestSimpleTableWithEnum {
  return (obj || new TestSimpleTableWithEnum()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

static getSizePrefixedRootAsTestSimpleTableWithEnum(bb:flatbuffers.ByteBuffer, obj?:TestSimpleTableWithEnum):TestSimpleTableWithEnum {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new TestSimpleTableWithEnum()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

color():Color {
  const offset = this.bb!.__offset(this.bb_pos, 4);
  return offset ? this.bb!.readUint8(this.bb_pos + offset) : Color.Green;
}

mutate_color(value:Color):boolean {
  const offset = this.bb!.__offset(this.bb_pos, 4);

  if (offset === 0) {
    return false;
  }

  this.bb!.writeUint8(this.bb_pos + offset, value);
  return true;
}

static getFullyQualifiedName():string {
  return 'MyGame.Example.TestSimpleTableWithEnum';
}

static startTestSimpleTableWithEnum(builder:flatbuffers.Builder) {
  builder.startObject(1);
}

static addColor(builder:flatbuffers.Builder, color:Color) {
  builder.addFieldInt8(0, color, Color.Green);
}

static endTestSimpleTableWithEnum(builder:flatbuffers.Builder):flatbuffers.Offset {
  const offset = builder.endObject();
  return offset;
}

static createTestSimpleTableWithEnum(builder:flatbuffers.Builder, color:Color):flatbuffers.Offset {
  TestSimpleTableWithEnum.startTestSimpleTableWithEnum(builder);
  TestSimpleTableWithEnum.addColor(builder, color);
  return TestSimpleTableWithEnum.endTestSimpleTableWithEnum(builder);
}

serialize():Uint8Array {
  return this.bb!.bytes();
}

static deserialize(buffer: Uint8Array):TestSimpleTableWithEnum {
  return TestSimpleTableWithEnum.getRootAsTestSimpleTableWithEnum(new flatbuffers.ByteBuffer(buffer))
}

unpack(): TestSimpleTableWithEnumT {
  return new TestSimpleTableWithEnumT(
    this.color()
  );
}


unpackTo(_o: TestSimpleTableWithEnumT): void {
  _o.color = this.color();
}
}

export class TestSimpleTableWithEnumT implements flatbuffers.IGeneratedObject {
constructor(
  public color: Color = Color.Green
){}


pack(builder:flatbuffers.Builder): flatbuffers.Offset {
  return TestSimpleTableWithEnum.createTestSimpleTableWithEnum(builder,
    this.color
  );
}
}
