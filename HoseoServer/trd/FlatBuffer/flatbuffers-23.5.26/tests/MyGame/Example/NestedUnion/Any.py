﻿# automatically generated by the FlatBuffers compiler, do not modify

# namespace: NestedUnion

class Any(object):
    NONE = 0
    Vec3 = 1
    TestSimpleTableWithEnum = 2

def AnyCreator(unionType, table):
    from flatbuffers.table import Table
    if not isinstance(table, Table):
        return None
    if unionType == Any().Vec3:
        import MyGame.Example.NestedUnion.Vec3
        return MyGame.Example.NestedUnion.Vec3.Vec3T.InitFromBuf(table.Bytes, table.Pos)
    if unionType == Any().TestSimpleTableWithEnum:
        import MyGame.Example.NestedUnion.TestSimpleTableWithEnum
        return MyGame.Example.NestedUnion.TestSimpleTableWithEnum.TestSimpleTableWithEnumT.InitFromBuf(table.Bytes, table.Pos)
    return None
