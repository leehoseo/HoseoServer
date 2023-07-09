#include "pch.h"
#include "ClientAppManager.h"
#include "ClientConfig.h"

bool CClientAppManager::Setup()
{
    const bool result = __super::Setup();

    g_ClientConfig::GetInstance()->Load();

    return result;
}
