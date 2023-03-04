#pragma once
#include "Client/ClientAppManager.h"

class CTradeClientAppManager : public CClientAppManager
{
public:
	CTradeClientAppManager();
	~CTradeClientAppManager();

public:
	virtual bool Setup() override;
};


typedef CSingleton<CTradeClientAppManager> g_TradeClientAppManager;