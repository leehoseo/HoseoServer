﻿# automatically generated by the FlatBuffers compiler, do not modify

# namespace: Example

class AnyAmbiguousAliases(object):
    NONE = 0
    M1 = 1
    M2 = 2
    M3 = 3

def AnyAmbiguousAliasesCreator(unionType, table):
    from flatbuffers.table import Table
    if not isinstance(table, Table):
        return None
    if unionType == AnyAmbiguousAliases().M1:
        import MyGame.Example.Monster
        return MyGame.Example.Monster.MonsterT.InitFromBuf(table.Bytes, table.Pos)
    if unionType == AnyAmbiguousAliases().M2:
        import MyGame.Example.Monster
        return MyGame.Example.Monster.MonsterT.InitFromBuf(table.Bytes, table.Pos)
    if unionType == AnyAmbiguousAliases().M3:
        import MyGame.Example.Monster
        return MyGame.Example.Monster.MonsterT.InitFromBuf(table.Bytes, table.Pos)
    return None
