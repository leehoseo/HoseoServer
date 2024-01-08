#pragma once
#include "Lobby/LobbyAppManager.h"

class CLinkToQueryPolicy;
class CAsyncEvent;
class CTradeServerAppManager : public CLobbyAppManager
{
public:
	CTradeServerAppManager();
	virtual ~CTradeServerAppManager();

public:
	virtual bool Setup() override;

public:
	bool ToQuery(CAsyncEvent* sendEvent);
private:
	CLinkToQueryPolicy* m_ToQueryPolicy;
};

typedef CSingleton<CTradeServerAppManager> g_TradeServerAppManager;


#define SendToQuery(sendEvent) g_TradeServerAppManager::GetInstance()->ToQuery(sendEvent)