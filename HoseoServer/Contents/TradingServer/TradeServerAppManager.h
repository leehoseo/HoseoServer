#pragma once
#include "Lobby/LobbyAppManager.h"

class CTradeServerAppManager : public CLobbyAppManager
{
public:
	CTradeServerAppManager() {};
	virtual ~CTradeServerAppManager() {};

public:
	virtual bool Setup() override;
};

typedef CSingleton<CTradeServerAppManager> g_TradeServerAppManager;