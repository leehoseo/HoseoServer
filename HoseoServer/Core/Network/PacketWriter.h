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

	/*	CPacket::SetSize();
		CPacket::SetId();
		CPacket::SetCompressType();
		CPacket::SetEncryptionType();
		CPacket::SetBody();*/
	}

	inline ~CPacketWriter()
	{

	}

private:
	char* m_Buffer;
	T* m_Body;
};

