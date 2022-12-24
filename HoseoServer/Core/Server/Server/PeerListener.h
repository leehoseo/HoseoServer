#pragma once

#include "Network/Peer.h"

class CAsyncTcpEvent;

/// <summary>
/// Peer의 연결을 담당할 Peer
/// </summary>
class CPeerListener : public CPeer
{
	class CPeerListenEvent;

public:
	CPeerListener();
	virtual ~CPeerListener();

public:
	void Start();
	virtual CPeer* CreatePeer();

public:
	virtual void ExecuteTcpEvent(CAsyncTcpEvent* tcpEvent);
};

