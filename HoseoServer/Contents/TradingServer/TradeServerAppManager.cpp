#include "TradeServerAppManager.h"
#include "TradeServerHandlerSetup.h"
#include "Network/AsyncDispatcher.h"
#include "Lobby/LobbyPeerListener.h"
#include "Network/ListenSystem.h"
#include "LinkToQueryPolicy.h"

CTradeServerAppManager::CTradeServerAppManager()
    : m_ToQueryPolicy(nullptr)
{
}

CTradeServerAppManager::~CTradeServerAppManager()
{
}

bool CTradeServerAppManager::Setup()
{
    bool result = __super::Setup();
    if (false == result)
    {
        return false;
    }

    // ���� ���� ����
    {
        m_ToQueryPolicy = New(CLinkToQueryPolicy);
    }

    // �ڵ鷯 �߰�
    {
        TradeServerHandlerSetup::Setup();
    }

    g_AsyncDispatcher::GetInstance()->Start();
    //������ ����
    g_ListenSystem::GetInstance()->Init(New(CLobbyPeerListener));
    g_ListenSystem::GetInstance()->Start();

    g_AsyncDispatcher::GetInstance()->Join();


    return result;
}

bool CTradeServerAppManager::ToQuery(CAsyncEvent* sendEvent)
{
    return m_ToQueryPolicy->Send(sendEvent);
}