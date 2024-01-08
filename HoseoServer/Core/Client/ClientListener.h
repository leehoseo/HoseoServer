#pragma once
#include "Network/PeerListener.h"

class CAsyncTcpEvent;
class CClientListener : public CPeerListener
{
public:
	CClientListener();
	~CClientListener();

public:
	virtual void Start() override;
	virtual void OnConnectEvent(CAsyncTcpEvent* tcpEvent) override;
};

