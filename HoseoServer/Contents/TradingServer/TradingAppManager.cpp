#include "pch.h"
#include "TradingAppManager.h"
#include "TradeHandlerSetup.h"

bool CTradingAppManager::Setup()
{
    bool result = __super::Setup();
    if (false == result)
    {
        return false;
    }

    TradeHandlerSetup::Setup();

    return result;
}

void CTradingAppManager::hello()
{
}
