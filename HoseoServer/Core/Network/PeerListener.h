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
	virtual void Start();
	virtual CPeer* CreatePeer();
	void PostAccept(CAsyncTcpEvent* acceptEvent);
public:
	virtual void OnAcceptEvent(CAsyncTcpEvent* tcpEvent);
};

