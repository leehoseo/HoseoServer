#include "LobbyPeer.h"

CLobbyPeer::CLobbyPeer()
{
}

CLobbyPeer::~CLobbyPeer()
{
}

void CLobbyPeer::OnReceiveEvent(bool result, int ioByteSize, CAsyncTcpEvent* tcpEvent)
{
	// 로비용 패킷 검증 로직

	__super::OnReceiveEvent(result, ioByteSize, tcpEvent);
}
