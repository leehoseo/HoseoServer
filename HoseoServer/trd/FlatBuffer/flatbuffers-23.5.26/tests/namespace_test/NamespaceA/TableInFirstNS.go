﻿// Code generated by the FlatBuffers compiler. DO NOT EDIT.

package NamespaceA

import (
	flatbuffers "github.com/google/flatbuffers/go"

	NamespaceA__NamespaceB "NamespaceA/NamespaceB"
)

type TableInFirstNST struct {
	FooTable *NamespaceA__NamespaceB.TableInNestedNST
	FooEnum NamespaceA__NamespaceB.EnumInNestedNS
	FooUnion *NamespaceA__NamespaceB.UnionInNestedNST
	FooStruct *NamespaceA__NamespaceB.StructInNestedNST
}

func (t *TableInFirstNST) Pack(builder *flatbuffers.Builder) flatbuffers.UOffsetT {
	if t == nil { return 0 }
	fooTableOffset := t.FooTable.Pack(builder)
	fooUnionOffset := t.FooUnion.Pack(builder)
	
	TableInFirstNSStart(builder)
	TableInFirstNSAddFooTable(builder, fooTableOffset)
	TableInFirstNSAddFooEnum(builder, t.FooEnum)
	if t.FooUnion != nil {
		TableInFirstNSAddFooUnionType(builder, t.FooUnion.Type)
	}
	TableInFirstNSAddFooUnion(builder, fooUnionOffset)
	fooStructOffset := t.FooStruct.Pack(builder)
	TableInFirstNSAddFooStruct(builder, fooStructOffset)
	return TableInFirstNSEnd(builder)
}

func (rcv *TableInFirstNS) UnPackTo(t *TableInFirstNST) {
	t.FooTable = rcv.FooTable(nil).UnPack()
	t.FooEnum = rcv.FooEnum()
	fooUnionTable := flatbuffers.Table{}
	if rcv.FooUnion(&fooUnionTable) {
		t.FooUnion = rcv.FooUnionType().UnPack(fooUnionTable)
	}
	t.FooStruct = rcv.FooStruct(nil).UnPack()
}

func (rcv *TableInFirstNS) UnPack() *TableInFirstNST {
	if rcv == nil { return nil }
	t := &TableInFirstNST{}
	rcv.UnPackTo(t)
	return t
}

type TableInFirstNS struct {
	_tab flatbuffers.Table
}

func GetRootAsTableInFirstNS(buf []byte, offset flatbuffers.UOffsetT) *TableInFirstNS {
	n := flatbuffers.GetUOffsetT(buf[offset:])
	x := &TableInFirstNS{}
	x.Init(buf, n+offset)
	return x
}

func GetSizePrefixedRootAsTableInFirstNS(buf []byte, offset flatbuffers.UOffsetT) *TableInFirstNS {
	n := flatbuffers.GetUOffsetT(buf[offset+flatbuffers.SizeUint32:])
	x := &TableInFirstNS{}
	x.Init(buf, n+offset+flatbuffers.SizeUint32)
	return x
}

func (rcv *TableInFirstNS) Init(buf []byte, i flatbuffers.UOffsetT) {
	rcv._tab.Bytes = buf
	rcv._tab.Pos = i
}

func (rcv *TableInFirstNS) Table() flatbuffers.Table {
	return rcv._tab
}

func (rcv *TableInFirstNS) FooTable(obj *NamespaceA__NamespaceB.TableInNestedNS) *NamespaceA__NamespaceB.TableInNestedNS {
	o := flatbuffers.UOffsetT(rcv._tab.Offset(4))
	if o != 0 {
		x := rcv._tab.Indirect(o + rcv._tab.Pos)
		if obj == nil {
			obj = new(NamespaceA__NamespaceB.TableInNestedNS)
		}
		obj.Init(rcv._tab.Bytes, x)
		return obj
	}
	return nil
}

func (rcv *TableInFirstNS) FooEnum() NamespaceA__NamespaceB.EnumInNestedNS {
	o := flatbuffers.UOffsetT(rcv._tab.Offset(6))
	if o != 0 {
		return NamespaceA__NamespaceB.EnumInNestedNS(rcv._tab.GetInt8(o + rcv._tab.Pos))
	}
	return 0
}

func (rcv *TableInFirstNS) MutateFooEnum(n NamespaceA__NamespaceB.EnumInNestedNS) bool {
	return rcv._tab.MutateInt8Slot(6, int8(n))
}

func (rcv *TableInFirstNS) FooUnionType() NamespaceA__NamespaceB.UnionInNestedNS {
	o := flatbuffers.UOffsetT(rcv._tab.Offset(8))
	if o != 0 {
		return NamespaceA__NamespaceB.UnionInNestedNS(rcv._tab.GetByte(o + rcv._tab.Pos))
	}
	return 0
}

func (rcv *TableInFirstNS) MutateFooUnionType(n NamespaceA__NamespaceB.UnionInNestedNS) bool {
	return rcv._tab.MutateByteSlot(8, byte(n))
}

func (rcv *TableInFirstNS) FooUnion(obj *flatbuffers.Table) bool {
	o := flatbuffers.UOffsetT(rcv._tab.Offset(10))
	if o != 0 {
		rcv._tab.Union(obj, o)
		return true
	}
	return false
}

func (rcv *TableInFirstNS) FooStruct(obj *NamespaceA__NamespaceB.StructInNestedNS) *NamespaceA__NamespaceB.StructInNestedNS {
	o := flatbuffers.UOffsetT(rcv._tab.Offset(12))
	if o != 0 {
		x := o + rcv._tab.Pos
		if obj == nil {
			obj = new(NamespaceA__NamespaceB.StructInNestedNS)
		}
		obj.Init(rcv._tab.Bytes, x)
		return obj
	}
	return nil
}

func TableInFirstNSStart(builder *flatbuffers.Builder) {
	builder.StartObject(5)
}
func TableInFirstNSAddFooTable(builder *flatbuffers.Builder, fooTable flatbuffers.UOffsetT) {
	builder.PrependUOffsetTSlot(0, flatbuffers.UOffsetT(fooTable), 0)
}
func TableInFirstNSAddFooEnum(builder *flatbuffers.Builder, fooEnum NamespaceA__NamespaceB.EnumInNestedNS) {
	builder.PrependInt8Slot(1, int8(fooEnum), 0)
}
func TableInFirstNSAddFooUnionType(builder *flatbuffers.Builder, fooUnionType NamespaceA__NamespaceB.UnionInNestedNS) {
	builder.PrependByteSlot(2, byte(fooUnionType), 0)
}
func TableInFirstNSAddFooUnion(builder *flatbuffers.Builder, fooUnion flatbuffers.UOffsetT) {
	builder.PrependUOffsetTSlot(3, flatbuffers.UOffsetT(fooUnion), 0)
}
func TableInFirstNSAddFooStruct(builder *flatbuffers.Builder, fooStruct flatbuffers.UOffsetT) {
	builder.PrependStructSlot(4, flatbuffers.UOffsetT(fooStruct), 0)
}
func TableInFirstNSEnd(builder *flatbuffers.Builder) flatbuffers.UOffsetT {
	return builder.EndObject()
}
