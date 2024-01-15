#include "LobbyPeer.h"

CLobbyPeer::CLobbyPeer()
{
}

CLobbyPeer::~CLobbyPeer()
{
}

int CLobbyPeer::OnReceiveEvent(CAsyncTcpEvent* tcpEvent)
{
	// 로비용 패킷 검증 로직

	return __super::OnReceiveEvent(tcpEvent);
}
