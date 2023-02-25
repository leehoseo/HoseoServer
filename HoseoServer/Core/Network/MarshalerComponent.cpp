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

int CMarshalerComponent::UnMarshal(CPeer* peer, char* buffer)
{
	// 암호화 여부
	
	// 패킷 처리
	PacketId_t id;
	CPacket::GetId(buffer, id);

	CHandler* handler = g_HandlerRegistry::GetInstance()->Find(id);

	if (nullptr == handler) 
	{
		return 0;
	}

	char* packetBody = nullptr;
	CPacket::GetBody(buffer, packetBody);

	// 패킷 핸들러 처리
	return handler->Execute(peer, packetBody);
}
