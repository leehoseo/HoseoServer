#pragma once
#include "Packet.h"
#include "PacketBase.h"

template<typename T>
class CPacketReader
{
public:
	CPacketReader(uint8_t* buffer)
	{

		// ���������� ����� �������� Body ����
		uint8_t* bodyBuffer = nullptr;
		CPacket::GetBody(buffer, bodyBuffer);

		m_Packet = New(T);
		// ��ȿ�� ���� ������ �ؾ��ϳ�?
		m_Packet->UnPack(bodyBuffer);
	}

	~CPacketReader()
	{
	}

public:
	T* operator->()
	{
		return m_Packet;
	}
private:
	T* m_Packet;
};

