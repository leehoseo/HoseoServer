﻿// automatically generated by the FlatBuffers compiler, do not modify

import * as flatbuffers from 'flatbuffers';

import { InnerStruct, InnerStructT } from '../../my-game/example/inner-struct.js';


export class OuterStruct implements flatbuffers.IUnpackableObject<OuterStructT> {
  bb: flatbuffers.ByteBuffer|null = null;
  bb_pos = 0;
  __init(i:number, bb:flatbuffers.ByteBuffer):OuterStruct {
  this.bb_pos = i;
  this.bb = bb;
  return this;
}

a():boolean {
  return !!this.bb!.readInt8(this.bb_pos);
}

b():number {
  return this.bb!.readFloat64(this.bb_pos + 8);
}

cUnderscore(obj?:InnerStruct):InnerStruct|null {
  return (obj || new InnerStruct()).__init(this.bb_pos + 16, this.bb!);
}

d(index: number, obj?:InnerStruct):InnerStruct|null {
    return (obj || new InnerStruct()).__init(this.bb_pos + 48 + index * 32, this.bb!);
}

e(obj?:InnerStruct):InnerStruct|null {
  return (obj || new InnerStruct()).__init(this.bb_pos + 144, this.bb!);
}

f(index: number):number|null {
    return this.bb!.readFloat64(this.bb_pos + 176 + index * 8);
}

static getFullyQualifiedName():string {
  return 'MyGame.Example.OuterStruct';
}

static sizeOf():number {
  return 208;
}

static createOuterStruct(builder:flatbuffers.Builder, a: boolean, b: number, c_underscore_a: number, c_underscore_b: number[]|null, c_underscore_c: number, c_underscore_d_underscore: bigint, d: (any|InnerStructT)[]|null, e_a: number, e_b: number[]|null, e_c: number, e_d_underscore: bigint, f: number[]|null):flatbuffers.Offset {
  builder.prep(8, 208);

  for (let i = 3; i >= 0; --i) {
    builder.writeFloat64((f?.[i] ?? 0));

  }

  builder.prep(8, 32);
  builder.writeInt64(BigInt(e_d_underscore ?? 0));
  builder.pad(2);
  builder.writeInt8(e_c);

  for (let i = 12; i >= 0; --i) {
    builder.writeInt8((e_b?.[i] ?? 0));

  }

  builder.writeFloat64(e_a);

  for (let i = 2; i >= 0; --i) {
    const item = d?.[i];

    if (item instanceof InnerStructT) {
      item.pack(builder);
      continue;
    }

    InnerStruct.createInnerStruct(builder,
    item?.a,
    item?.b,
    item?.c,
    item?.dUnderscore
    );
  }

  builder.prep(8, 32);
  builder.writeInt64(BigInt(c_underscore_d_underscore ?? 0));
  builder.pad(2);
  builder.writeInt8(c_underscore_c);

  for (let i = 12; i >= 0; --i) {
    builder.writeInt8((c_underscore_b?.[i] ?? 0));

  }

  builder.writeFloat64(c_underscore_a);
  builder.writeFloat64(b);
  builder.pad(7);
  builder.writeInt8(Number(Boolean(a)));
  return builder.offset();
}


unpack(): OuterStructT {
  return new OuterStructT(
    this.a(),
    this.b(),
    (this.cUnderscore() !== null ? this.cUnderscore()!.unpack() : null),
    this.bb!.createObjList<InnerStruct, InnerStructT>(this.d.bind(this), 3),
    (this.e() !== null ? this.e()!.unpack() : null),
    this.bb!.createScalarList<number>(this.f.bind(this), 4)
  );
}


unpackTo(_o: OuterStructT): void {
  _o.a = this.a();
  _o.b = this.b();
  _o.cUnderscore = (this.cUnderscore() !== null ? this.cUnderscore()!.unpack() : null);
  _o.d = this.bb!.createObjList<InnerStruct, InnerStructT>(this.d.bind(this), 3);
  _o.e = (this.e() !== null ? this.e()!.unpack() : null);
  _o.f = this.bb!.createScalarList<number>(this.f.bind(this), 4);
}
}

export class OuterStructT implements flatbuffers.IGeneratedObject {
constructor(
  public a: boolean = false,
  public b: number = 0.0,
  public cUnderscore: InnerStructT|null = null,
  public d: (InnerStructT)[] = [],
  public e: InnerStructT|null = null,
  public f: (number)[] = []
){}


pack(builder:flatbuffers.Builder): flatbuffers.Offset {
  return OuterStruct.createOuterStruct(builder,
    this.a,
    this.b,
    (this.cUnderscore?.a ?? 0),
    (this.cUnderscore?.b ?? []),
    (this.cUnderscore?.c ?? 0),
    (this.cUnderscore?.dUnderscore ?? BigInt(0)),
    this.d,
    (this.e?.a ?? 0),
    (this.e?.b ?? []),
    (this.e?.c ?? 0),
    (this.e?.dUnderscore ?? BigInt(0)),
    this.f
  );
}
}
