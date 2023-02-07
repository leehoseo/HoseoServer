#pragma once
#include "Pattern/Singleton.h"

class CAppManager : public CSingleton<CAppManager>
{
public:
	CAppManager() {};
	virtual ~CAppManager() {};

public:
	virtual bool Setup();
};

