#include "pch.h"
#include "TradeServerAppManager.h"
#include "TradeServerHandlerSetup.h"
#include "Network/AsyncDispatcher.h"
#include "Lobby/LobbyPeerListener.h"
#include "Network/ListenSystem.h"


bool CTradeServerAppManager::Setup()
{
    bool result = __super::Setup();
    if (false == result)
    {
        return false;
    }

    // �ڵ鷯 �߰�
    {
        TradeServerHandlerSetup::Setup();
    }

    g_AsyncDispatcher::GetInstance()->Start();

    // ������ ����
    g_ListenSystem::GetInstance()->Init(new CLobbyPeerListener());
    g_ListenSystem::GetInstance()->Start();

    g_AsyncDispatcher::GetInstance()->Join();


    return result;
}