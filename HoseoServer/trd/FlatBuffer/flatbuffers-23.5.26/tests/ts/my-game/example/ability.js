﻿// automatically generated by the FlatBuffers compiler, do not modify
export class Ability {
    constructor() {
        this.bb = null;
        this.bb_pos = 0;
    }
    __init(i, bb) {
        this.bb_pos = i;
        this.bb = bb;
        return this;
    }
    id() {
        return this.bb.readUint32(this.bb_pos);
    }
    mutate_id(value) {
        this.bb.writeUint32(this.bb_pos + 0, value);
        return true;
    }
    distance() {
        return this.bb.readUint32(this.bb_pos + 4);
    }
    mutate_distance(value) {
        this.bb.writeUint32(this.bb_pos + 4, value);
        return true;
    }
    static getFullyQualifiedName() {
        return 'MyGame.Example.Ability';
    }
    static sizeOf() {
        return 8;
    }
    static createAbility(builder, id, distance) {
        builder.prep(4, 8);
        builder.writeInt32(distance);
        builder.writeInt32(id);
        return builder.offset();
    }
    unpack() {
        return new AbilityT(this.id(), this.distance());
    }
    unpackTo(_o) {
        _o.id = this.id();
        _o.distance = this.distance();
    }
}
export class AbilityT {
    constructor(id = 0, distance = 0) {
        this.id = id;
        this.distance = distance;
    }
    pack(builder) {
        return Ability.createAbility(builder, this.id, this.distance);
    }
}
