﻿#[ Universe
  Automatically generated by the FlatBuffers compiler, do not modify.
  Or modify. I'm a message, not a cop.

  flatc version: 23.5.9

  Declared by  : //basic.fbs
  Rooting type : Universe (//basic.fbs)
]#

import Galaxy as Galaxy
import flatbuffers
import std/options

type Universe* = object of FlatObj
func age*(self: Universe): float64 =
  let o = self.tab.Offset(4)
  if o != 0:
    return Get[float64](self.tab, self.tab.Pos + o)
  return 0.0
func `age=`*(self: var Universe, n: float64): bool =
  return self.tab.MutateSlot(4, n)
func galaxiesLength*(self: Universe): int = 
  let o = self.tab.Offset(6)
  if o != 0:
    return self.tab.VectorLen(o)
func galaxies*(self: Universe, j: int): Galaxy.Galaxy = 
  let o = self.tab.Offset(6)
  if o != 0:
    var x = self.tab.Vector(o)
    x += j.uoffset * 4.uoffset
    return Galaxy.Galaxy(tab: Vtable(Bytes: self.tab.Bytes, Pos: x))
func galaxies*(self: Universe): seq[Galaxy.Galaxy] = 
  let len = self.galaxiesLength
  for i in countup(0, len - 1):
    result.add(self.galaxies(i))
proc UniverseStart*(builder: var Builder) =
  builder.StartObject(2)
proc UniverseAddage*(builder: var Builder, age: float64) =
  builder.PrependSlot(0, age, default(float64))
proc UniverseAddgalaxies*(builder: var Builder, galaxies: uoffset) =
  builder.PrependSlot(1, galaxies, default(uoffset))
proc UniverseStartgalaxiesVector*(builder: var Builder, numElems: uoffset) =
  builder.StartVector(4, numElems, 4)
proc UniverseEnd*(builder: var Builder): uoffset =
  return builder.EndObject()
