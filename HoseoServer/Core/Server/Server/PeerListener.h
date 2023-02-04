#pragma once

#include "Network/Peer.h"

class CAsyncTcpEvent;

/// <summary>
/// Peer�� ������ ����� Peer
/// </summary>
class CPeerListener : public CPeer
{
public:
	CPeerListener();
	virtual ~CPeerListener();

public:
	void Start();
	virtual CPeer* CreatePeer();

public:
	virtual void OnAcceptEvent(CAsyncTcpEvent* tcpEvent);
};

