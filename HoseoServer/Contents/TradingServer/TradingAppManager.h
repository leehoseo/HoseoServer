#pragma once
#include "Lobby/LobbyAppManager.h"

class CTradingAppManager : public CLobbyAppManager
{
public:
	CTradingAppManager() {};
	virtual ~CTradingAppManager() {};

public:
	virtual bool Setup();

	void hello();
};

typedef CSingleton<CTradingAppManager> g_TradingAppManager;