#pragma once
#include "Packet.h"
#include "PacketBase.h"
#include "AsyncTcpEvent.h"

template<typename T>
class CPacketWriter
{
public:
	CPacketWriter()
	{
		m_Packet = New(T);
		// ��ȿ�� ���� ������ �ؾ��ϳ�?
	}

	~CPacketWriter()
	{
	}

public:
	T* operator->()
	{
		return m_Packet;
	}

	CAsyncTcpEvent* operator()()
	{
		CAsyncTcpEvent* sendEvent = New(CAsyncTcpEvent, CAsyncTcpEvent::EventType::Send);
		sendEvent->SetBuffer(MakeBuffer());

		return sendEvent;
	}

private:
	uint8_t* MakeBuffer()
	{
		uint8_t* bodyBuffer = m_Packet->Pack(); // ��Ŷ�� ���̳ʸ���

		if (nullptr == bodyBuffer)
		{
			return nullptr;
		}

		const int bodySize = sizeof(bodyBuffer);
		const int size = bodySize + sizeof(PacketHeader);
		uint8_t* packetBuffer = new uint8_t[size];

		// ��Ŷ�� header �κ� ����
		CPacket::SetSize(packetBuffer, size);
		CPacket::SetId(packetBuffer, T::GetHash());
		CPacket::SetCompressType(packetBuffer, 0);
		CPacket::SetEncryptionType(packetBuffer, 0);

		// ���������� ����� �������� Body ����
		CPacket::SetBody(packetBuffer, bodyBuffer, bodySize);

		return packetBuffer;
	}

private:
	T* m_Packet;
};

