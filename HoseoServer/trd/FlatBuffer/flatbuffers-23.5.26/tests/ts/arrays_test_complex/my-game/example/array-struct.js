﻿// automatically generated by the FlatBuffers compiler, do not modify
import { NestedStruct, NestedStructT } from '../../my-game/example/nested-struct.js';
import { OuterStruct, OuterStructT } from '../../my-game/example/outer-struct.js';
export class ArrayStruct {
    constructor() {
        this.bb = null;
        this.bb_pos = 0;
    }
    __init(i, bb) {
        this.bb_pos = i;
        this.bb = bb;
        return this;
    }
    aUnderscore() {
        return this.bb.readFloat32(this.bb_pos);
    }
    bUnderscore(index) {
        return this.bb.readInt32(this.bb_pos + 4 + index * 4);
    }
    c() {
        return this.bb.readInt8(this.bb_pos + 64);
    }
    d(index, obj) {
        return (obj || new NestedStruct()).__init(this.bb_pos + 72 + index * 1072, this.bb);
    }
    e() {
        return this.bb.readInt32(this.bb_pos + 2216);
    }
    f(index, obj) {
        return (obj || new OuterStruct()).__init(this.bb_pos + 2224 + index * 208, this.bb);
    }
    g(index) {
        return this.bb.readInt64(this.bb_pos + 2640 + index * 8);
    }
    static getFullyQualifiedName() {
        return 'MyGame.Example.ArrayStruct';
    }
    static sizeOf() {
        return 2656;
    }
    static createArrayStruct(builder, a_underscore, b_underscore, c, d, e, f, g) {
        builder.prep(8, 2656);
        for (let i = 1; i >= 0; --i) {
            builder.writeInt64(BigInt(g?.[i] ?? 0));
        }
        for (let i = 1; i >= 0; --i) {
            const item = f?.[i];
            if (item instanceof OuterStructT) {
                item.pack(builder);
                continue;
            }
            OuterStruct.createOuterStruct(builder, item?.a, item?.b, (item?.cUnderscore?.a ?? 0), (item?.cUnderscore?.b ?? []), (item?.cUnderscore?.c ?? 0), (item?.cUnderscore?.dUnderscore ?? BigInt(0)), item?.d, (item?.e?.a ?? 0), (item?.e?.b ?? []), (item?.e?.c ?? 0), (item?.e?.dUnderscore ?? BigInt(0)), item?.f);
        }
        builder.pad(4);
        builder.writeInt32(e);
        for (let i = 1; i >= 0; --i) {
            const item = d?.[i];
            if (item instanceof NestedStructT) {
                item.pack(builder);
                continue;
            }
            NestedStruct.createNestedStruct(builder, item?.a, item?.b, item?.cUnderscore, item?.dOuter, item?.e);
        }
        builder.pad(7);
        builder.writeInt8(c);
        for (let i = 14; i >= 0; --i) {
            builder.writeInt32((b_underscore?.[i] ?? 0));
        }
        builder.writeFloat32(a_underscore);
        return builder.offset();
    }
    unpack() {
        return new ArrayStructT(this.aUnderscore(), this.bb.createScalarList(this.bUnderscore.bind(this), 15), this.c(), this.bb.createObjList(this.d.bind(this), 2), this.e(), this.bb.createObjList(this.f.bind(this), 2), this.bb.createScalarList(this.g.bind(this), 2));
    }
    unpackTo(_o) {
        _o.aUnderscore = this.aUnderscore();
        _o.bUnderscore = this.bb.createScalarList(this.bUnderscore.bind(this), 15);
        _o.c = this.c();
        _o.d = this.bb.createObjList(this.d.bind(this), 2);
        _o.e = this.e();
        _o.f = this.bb.createObjList(this.f.bind(this), 2);
        _o.g = this.bb.createScalarList(this.g.bind(this), 2);
    }
}
export class ArrayStructT {
    constructor(aUnderscore = 0.0, bUnderscore = [], c = 0, d = [], e = 0, f = [], g = []) {
        this.aUnderscore = aUnderscore;
        this.bUnderscore = bUnderscore;
        this.c = c;
        this.d = d;
        this.e = e;
        this.f = f;
        this.g = g;
    }
    pack(builder) {
        return ArrayStruct.createArrayStruct(builder, this.aUnderscore, this.bUnderscore, this.c, this.d, this.e, this.f, this.g);
    }
}
