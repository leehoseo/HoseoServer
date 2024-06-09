#include "TradeClientAppManager.h"
#include "TradeClientHandlerSetup.h"
#include "Network/AsyncDispatcher.h"
#include "Client/ClientNetworkPeer.h"
#include "Network/ListenSystem.h"

CTradeClientAppManager::CTradeClientAppManager()
{
}

CTradeClientAppManager::~CTradeClientAppManager()
{
}

bool CTradeClientAppManager::Setup()
{
    bool result = __super::Setup();
    if (false == result)
    {
        return false;
    }

    // 핸들러 추가
    {
        TradeClientHandlerSetup::Setup();
    }

    g_AsyncDispatcher::GetInstance()->Start();

    CClientNetworkPeer* peer = New(CClientNetworkPeer);
    peer->ConnectToServer();
    // 데이터 세팅
    //g_ListenSystem::GetInstance()->Init(New(CClientNetworkPeer));

    return true;
}
