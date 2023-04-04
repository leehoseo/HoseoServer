#pragma once

#include "Packet.h"

template<typename T>
class CPacketWriter
{
public:
	CPacketWriter()
	{
		const int size = sizeof(T) + sizeof(PacketHeader);
		m_Buffer = new char[size];

		CPacket::SetSize(m_Buffer, size);
		CPacket::SetId(m_Buffer, T::GetId());
		CPacket::SetCompressType(m_Buffer, 0);
		CPacket::SetEncryptionType(m_Buffer, 0);
	}

	~CPacketWriter()
	{
	}

public:
	uint8_t* GetBuffer()
	{
		return m_Buffer;
	}

	void SetBody(uint8_t* bodyBuffer)
	{
		CPacket::SetBody(m_Buffer, bodyBuffer, sizeof(bodyBuffer));
	}
private:
	uint8_t* m_Buffer;
};

