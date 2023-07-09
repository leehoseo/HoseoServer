#pragma once
#include "Base/Singleton.h"

class CClientConfig
{
public:
	void Load();

public:
	std::string m_LoginAddr;
	int m_LoginPort;
};

typedef CSingleton<CClientConfig> g_ClientConfig;