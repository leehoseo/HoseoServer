#include "MarshalerComponent.h"
#include "AsyncTcpEvent.h"
#include "PacketRegistry.h"
#include "PacketHandler.h"
#include "HandlerRegistry.h"
#include "Packet.h"
#include "Peer.h"

void CMarshalerComponent::Init()
{
}

int CMarshalerComponent::UnMarshal(CPeer* peer, uint8_t* buffer)
{
	// ��ȣȭ ����
	
	// ��Ŷ ó��
	PacketId_t id;
	PacketSize_t size;
	CPacket::GetId(buffer, id);
	CPacket::GetSize(buffer, size);

	if (sizeof(buffer) < size)
	{
		return 0;
	}

	CHandler* handler = g_HandlerRegistry::GetInstance()->Find(id);

	if (nullptr == handler) 
	{
		return 0;
	}

	uint8_t* packetBody = nullptr;
	CPacket::GetBody(buffer, packetBody);

	// ��Ŷ �ڵ鷯 ó��
	return handler->Execute(peer, packetBody);
}
