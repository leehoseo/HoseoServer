﻿<?php
// automatically generated by the FlatBuffers compiler, do not modify

namespace MyGame\Example;

use \Google\FlatBuffers\Struct;
use \Google\FlatBuffers\Table;
use \Google\FlatBuffers\ByteBuffer;
use \Google\FlatBuffers\FlatBufferBuilder;

class TypeAliases extends Table
{
    /**
     * @param ByteBuffer $bb
     * @return TypeAliases
     */
    public static function getRootAsTypeAliases(ByteBuffer $bb)
    {
        $obj = new TypeAliases();
        return ($obj->init($bb->getInt($bb->getPosition()) + $bb->getPosition(), $bb));
    }

    public static function TypeAliasesIdentifier()
    {
        return "MONS";
    }

    public static function TypeAliasesBufferHasIdentifier(ByteBuffer $buf)
    {
        return self::__has_identifier($buf, self::TypeAliasesIdentifier());
    }

    public static function TypeAliasesExtension()
    {
        return "mon";
    }

    /**
     * @param int $_i offset
     * @param ByteBuffer $_bb
     * @return TypeAliases
     **/
    public function init($_i, ByteBuffer $_bb)
    {
        $this->bb_pos = $_i;
        $this->bb = $_bb;
        return $this;
    }

    /**
     * @return sbyte
     */
    public function getI8()
    {
        $o = $this->__offset(4);
        return $o != 0 ? $this->bb->getSbyte($o + $this->bb_pos) : 0;
    }

    /**
     * @return byte
     */
    public function getU8()
    {
        $o = $this->__offset(6);
        return $o != 0 ? $this->bb->getByte($o + $this->bb_pos) : 0;
    }

    /**
     * @return short
     */
    public function getI16()
    {
        $o = $this->__offset(8);
        return $o != 0 ? $this->bb->getShort($o + $this->bb_pos) : 0;
    }

    /**
     * @return ushort
     */
    public function getU16()
    {
        $o = $this->__offset(10);
        return $o != 0 ? $this->bb->getUshort($o + $this->bb_pos) : 0;
    }

    /**
     * @return int
     */
    public function getI32()
    {
        $o = $this->__offset(12);
        return $o != 0 ? $this->bb->getInt($o + $this->bb_pos) : 0;
    }

    /**
     * @return uint
     */
    public function getU32()
    {
        $o = $this->__offset(14);
        return $o != 0 ? $this->bb->getUint($o + $this->bb_pos) : 0;
    }

    /**
     * @return long
     */
    public function getI64()
    {
        $o = $this->__offset(16);
        return $o != 0 ? $this->bb->getLong($o + $this->bb_pos) : 0;
    }

    /**
     * @return ulong
     */
    public function getU64()
    {
        $o = $this->__offset(18);
        return $o != 0 ? $this->bb->getUlong($o + $this->bb_pos) : 0;
    }

    /**
     * @return float
     */
    public function getF32()
    {
        $o = $this->__offset(20);
        return $o != 0 ? $this->bb->getFloat($o + $this->bb_pos) : 0.0;
    }

    /**
     * @return double
     */
    public function getF64()
    {
        $o = $this->__offset(22);
        return $o != 0 ? $this->bb->getDouble($o + $this->bb_pos) : 0.0;
    }

    /**
     * @param int offset
     * @return sbyte
     */
    public function getV8($j)
    {
        $o = $this->__offset(24);
        return $o != 0 ? $this->bb->getSbyte($this->__vector($o) + $j * 1) : 0;
    }

    /**
     * @return int
     */
    public function getV8Length()
    {
        $o = $this->__offset(24);
        return $o != 0 ? $this->__vector_len($o) : 0;
    }

    /**
     * @param int offset
     * @return double
     */
    public function getVf64($j)
    {
        $o = $this->__offset(26);
        return $o != 0 ? $this->bb->getDouble($this->__vector($o) + $j * 8) : 0;
    }

    /**
     * @return int
     */
    public function getVf64Length()
    {
        $o = $this->__offset(26);
        return $o != 0 ? $this->__vector_len($o) : 0;
    }

    /**
     * @param FlatBufferBuilder $builder
     * @return void
     */
    public static function startTypeAliases(FlatBufferBuilder $builder)
    {
        $builder->StartObject(12);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @return TypeAliases
     */
    public static function createTypeAliases(FlatBufferBuilder $builder, $i8, $u8, $i16, $u16, $i32, $u32, $i64, $u64, $f32, $f64, $v8, $vf64)
    {
        $builder->startObject(12);
        self::addI8($builder, $i8);
        self::addU8($builder, $u8);
        self::addI16($builder, $i16);
        self::addU16($builder, $u16);
        self::addI32($builder, $i32);
        self::addU32($builder, $u32);
        self::addI64($builder, $i64);
        self::addU64($builder, $u64);
        self::addF32($builder, $f32);
        self::addF64($builder, $f64);
        self::addV8($builder, $v8);
        self::addVf64($builder, $vf64);
        $o = $builder->endObject();
        return $o;
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param sbyte
     * @return void
     */
    public static function addI8(FlatBufferBuilder $builder, $i8)
    {
        $builder->addSbyteX(0, $i8, 0);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param byte
     * @return void
     */
    public static function addU8(FlatBufferBuilder $builder, $u8)
    {
        $builder->addByteX(1, $u8, 0);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param short
     * @return void
     */
    public static function addI16(FlatBufferBuilder $builder, $i16)
    {
        $builder->addShortX(2, $i16, 0);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param ushort
     * @return void
     */
    public static function addU16(FlatBufferBuilder $builder, $u16)
    {
        $builder->addUshortX(3, $u16, 0);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param int
     * @return void
     */
    public static function addI32(FlatBufferBuilder $builder, $i32)
    {
        $builder->addIntX(4, $i32, 0);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param uint
     * @return void
     */
    public static function addU32(FlatBufferBuilder $builder, $u32)
    {
        $builder->addUintX(5, $u32, 0);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param long
     * @return void
     */
    public static function addI64(FlatBufferBuilder $builder, $i64)
    {
        $builder->addLongX(6, $i64, 0);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param ulong
     * @return void
     */
    public static function addU64(FlatBufferBuilder $builder, $u64)
    {
        $builder->addUlongX(7, $u64, 0);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param float
     * @return void
     */
    public static function addF32(FlatBufferBuilder $builder, $f32)
    {
        $builder->addFloatX(8, $f32, 0.0);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param double
     * @return void
     */
    public static function addF64(FlatBufferBuilder $builder, $f64)
    {
        $builder->addDoubleX(9, $f64, 0.0);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param VectorOffset
     * @return void
     */
    public static function addV8(FlatBufferBuilder $builder, $v8)
    {
        $builder->addOffsetX(10, $v8, 0);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param array offset array
     * @return int vector offset
     */
    public static function createV8Vector(FlatBufferBuilder $builder, array $data)
    {
        $builder->startVector(1, count($data), 1);
        for ($i = count($data) - 1; $i >= 0; $i--) {
            $builder->putSbyte($data[$i]);
        }
        return $builder->endVector();
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param int $numElems
     * @return void
     */
    public static function startV8Vector(FlatBufferBuilder $builder, $numElems)
    {
        $builder->startVector(1, $numElems, 1);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param VectorOffset
     * @return void
     */
    public static function addVf64(FlatBufferBuilder $builder, $vf64)
    {
        $builder->addOffsetX(11, $vf64, 0);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param array offset array
     * @return int vector offset
     */
    public static function createVf64Vector(FlatBufferBuilder $builder, array $data)
    {
        $builder->startVector(8, count($data), 8);
        for ($i = count($data) - 1; $i >= 0; $i--) {
            $builder->putDouble($data[$i]);
        }
        return $builder->endVector();
    }

    /**
     * @param FlatBufferBuilder $builder
     * @param int $numElems
     * @return void
     */
    public static function startVf64Vector(FlatBufferBuilder $builder, $numElems)
    {
        $builder->startVector(8, $numElems, 8);
    }

    /**
     * @param FlatBufferBuilder $builder
     * @return int table offset
     */
    public static function endTypeAliases(FlatBufferBuilder $builder)
    {
        $o = $builder->endObject();
        return $o;
    }
}
