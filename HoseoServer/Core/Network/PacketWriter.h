#pragma once

#include "Packet.h"

template<typename T>
class CPacketWriter
{
public:
	inline CPacketWriter()
	{
		m_Body = new T();
		const int size = sizeof(T) + sizeof(PacketHeader);
		m_Buffer = new char[size];

		CPacket::SetSize(m_Buffer, size);
		CPacket::SetId(m_Buffer);
		CPacket::SetCompressType(0);
		CPacket::SetEncryptionType(0);
	}

	inline ~CPacketWriter()
	{

	}

private:
	char* m_Buffer;
	T* m_Body;
};

