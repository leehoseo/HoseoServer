#pragma once
#include "Network/Peer.h"

class CAsyncTcpEvent;
class CClientNetworkPeer : public CPeer
{
public:
	CClientNetworkPeer();
	~CClientNetworkPeer();

public:
	void ConnectToServer();
	virtual void OnConnectEvent(CAsyncTcpEvent* tcpEvent) override;
};

