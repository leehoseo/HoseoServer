#pragma once
#include "Server/ServerListener.h"

class CLobbyPeerListener : public CServerListener
{
public:
	CLobbyPeerListener();
	virtual ~CLobbyPeerListener();

public:
	virtual CPeer* CreatePeer();
};

