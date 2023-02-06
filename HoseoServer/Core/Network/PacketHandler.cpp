#include "PacketHandler.h"
#include "Peer.h"

CPacketHandler::CPacketHandler()
{
}

CPacketHandler::~CPacketHandler()
{
}

void CPacketHandler::Execute(CPeer* peer)
{
	// 최종적인 컨텐츠로직 전 검증처리

	OnExecute(peer);
}
