﻿// Code generated by the FlatBuffers compiler. DO NOT EDIT.

package Example

import "strconv"

type LongEnum uint64

const (
	LongEnumLongOne LongEnum = 2
	LongEnumLongTwo LongEnum = 4
	LongEnumLongBig LongEnum = 1099511627776
)

var EnumNamesLongEnum = map[LongEnum]string{
	LongEnumLongOne: "LongOne",
	LongEnumLongTwo: "LongTwo",
	LongEnumLongBig: "LongBig",
}

var EnumValuesLongEnum = map[string]LongEnum{
	"LongOne": LongEnumLongOne,
	"LongTwo": LongEnumLongTwo,
	"LongBig": LongEnumLongBig,
}

func (v LongEnum) String() string {
	if s, ok := EnumNamesLongEnum[v]; ok {
		return s
	}
	return "LongEnum(" + strconv.FormatInt(int64(v), 10) + ")"
}
