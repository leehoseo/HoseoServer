#pragma once
#include "flatbuffers/flatbuffers.h"

namespace PacketBuilder
{
	template<typename T>
	uint8_t* PackPacketBuffer(T* packet)
	{
		flatbuffers::FlatBufferBuilder builder;
		packet->Pack(builder);

		return builder.GetBufferPointer();
	}

	template<typename T>
	T* UnPackPacketBuffer(uint8_t* buffer)
	{
		T* packet = new T();
		packet->UnPack(buffer);

		return packet;
	}
};