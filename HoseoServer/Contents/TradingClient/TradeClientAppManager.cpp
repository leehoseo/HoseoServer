#include "TradeClientAppManager.h"
#include "TradeClientHandlerSetup.h"
#include "Network/AsyncDispatcher.h"
#include "Client/ClientListener.h"
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

    // 데이터 세팅
    g_ListenSystem::GetInstance()->Init(new CClientListener());
    g_ListenSystem::GetInstance()->Start();

    g_AsyncDispatcher::GetInstance()->Join();
}
