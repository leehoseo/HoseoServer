#include "pch.h"
#include "NetworkAppManager.h"
#include "Socket.h"

bool CNetworkAppManager::Setup()
{
    bool result = __super::Setup();

    Network::Setup();

    return result;
}
