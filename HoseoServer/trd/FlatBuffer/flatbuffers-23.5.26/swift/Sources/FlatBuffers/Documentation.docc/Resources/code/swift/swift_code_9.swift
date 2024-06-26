﻿import FlatBuffers
import Foundation

func run() {
  // create a `FlatBufferBuilder`, which will be used to serialize objects
  let builder = FlatBufferBuilder(initialSize: 1024)

  let weapon1Name = builder.create(string: "Sword")
  let weapon2Name = builder.create(string: "Axe")

  // start creating the weapon by calling startWeapon
  let weapon1Start = Weapon.startWeapon(&builder)
  Weapon.add(name: weapon1Name, &builder)
  Weapon.add(damage: 3, &builder)
  // end the object by passing the start point for the weapon 1
  let sword = Weapon.endWeapon(&builder, start: weapon1Start)

  let weapon2Start = Weapon.startWeapon(&builder)
  Weapon.add(name: weapon2Name, &builder)
  Weapon.add(damage: 5, &builder)
  let axe = Weapon.endWeapon(&builder, start: weapon2Start)

  // Create a FlatBuffer `vector` that contains offsets to the sword and axe
  // we created above.
  let weaponsOffset = builder.createVector(ofOffsets: [sword, axe])

  // Name of the Monster.
  let name = builder.create(string: "Orc")

  let pathOffset = fbb.createVector(ofStructs: [
    Vec3(x: 0, y: 0),
    Vec3(x: 5, y: 5),
  ])

  // startVector(len, elementSize: MemoryLayout<Offset>.size)
  // for o in offsets.reversed() {
  //   push(element: o)
  // }
  // endVector(len: len)

  let orc = Monster.createMonster(
    &builder,
    pos: Vec3(x: 1, y: 2),
    hp: 300,
    nameOffset: name,
    color: .red,
    weaponsVectorOffset: weaponsOffset,
    equippedType: .weapon,
    equippedOffset: axe,
    pathOffset: pathOffset)

  // let start = Monster.startMonster(&builder)
  // Monster.add(pos: Vec3(x: 1, y: 2), &builder)
  // Monster.add(hp: 300, &builder)
  // Monster.add(name: name, &builder)
  // Monster.add(color: .red, &builder)
  // Monster.addVectorOf(weapons: weaponsOffset, &builder)
  // Monster.add(equippedType: .weapon, &builder)
  // Monster.addVectorOf(paths: weaponsOffset, &builder)
  // Monster.add(equipped: axe, &builder)
  // var orc = Monster.endMonster(&builder, start: start)
}
