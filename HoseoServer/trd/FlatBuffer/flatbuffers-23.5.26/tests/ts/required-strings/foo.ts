﻿// automatically generated by the FlatBuffers compiler, do not modify

import * as flatbuffers from 'flatbuffers';

export class Foo {
  bb: flatbuffers.ByteBuffer|null = null;
  bb_pos = 0;
  __init(i:number, bb:flatbuffers.ByteBuffer):Foo {
  this.bb_pos = i;
  this.bb = bb;
  return this;
}

static getRootAsFoo(bb:flatbuffers.ByteBuffer, obj?:Foo):Foo {
  return (obj || new Foo()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

static getSizePrefixedRootAsFoo(bb:flatbuffers.ByteBuffer, obj?:Foo):Foo {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new Foo()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

strA():string|null
strA(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
strA(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 4);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

strB():string|null
strB(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
strB(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 6);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

static startFoo(builder:flatbuffers.Builder) {
  builder.startObject(2);
}

static addStrA(builder:flatbuffers.Builder, strAOffset:flatbuffers.Offset) {
  builder.addFieldOffset(0, strAOffset, 0);
}

static addStrB(builder:flatbuffers.Builder, strBOffset:flatbuffers.Offset) {
  builder.addFieldOffset(1, strBOffset, 0);
}

static endFoo(builder:flatbuffers.Builder):flatbuffers.Offset {
  const offset = builder.endObject();
  builder.requiredField(offset, 4) // str_a
  builder.requiredField(offset, 6) // str_b
  return offset;
}

static createFoo(builder:flatbuffers.Builder, strAOffset:flatbuffers.Offset, strBOffset:flatbuffers.Offset):flatbuffers.Offset {
  Foo.startFoo(builder);
  Foo.addStrA(builder, strAOffset);
  Foo.addStrB(builder, strBOffset);
  return Foo.endFoo(builder);
}
}
