﻿// automatically generated by the FlatBuffers compiler, do not modify

package MyGame.Example

@Suppress("unused")
class Race private constructor() {
    companion object {
        const val None: Byte = -1
        const val Human: Byte = 0
        const val Dwarf: Byte = 1
        const val Elf: Byte = 2
        val names : Array<String> = arrayOf("None", "Human", "Dwarf", "Elf")
        fun name(e: Int) : String = names[e - None.toInt()]
    }
}
