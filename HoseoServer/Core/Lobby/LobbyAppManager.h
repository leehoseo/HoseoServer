#pragma once
#include "Server/ServerAppManager.h"

class CLobbyAppManager : public CServerAppManager
{
public:
	CLobbyAppManager() {};
	virtual ~CLobbyAppManager() {};

public:
	virtual bool Setup();
};

