#pragma once
#include "Server/PeerListener.h"

class CLobbyPeerListener : public CPeerListener
{
public:
	CLobbyPeerListener();
	virtual ~CLobbyPeerListener();

public:
	virtual CPeer* CreatePeer();
};

