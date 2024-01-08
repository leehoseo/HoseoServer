#pragma once
#include "Network/NetworkAppManager.h"

class CClientAppManager : public CNetworkAppManager
{
public:
	CClientAppManager() {};
	virtual ~CClientAppManager() {};

public:
	virtual bool Setup();
};

