#include "LobbyPeerListener.h"
#include "LobbyPeer.h"

CLobbyPeerListener::CLobbyPeerListener()
{
}

CLobbyPeerListener::~CLobbyPeerListener()
{
}

CPeer* CLobbyPeerListener::CreatePeer()
{
	return New(CLobbyPeer);
}
