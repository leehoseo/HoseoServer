#include "TradeHandlerSetup.h"
#include "Network/HandlerRegistry.h"
#include "CT_LoginHandler.h"

void TradeHandlerSetup::Setup()
{
	g_HandlerRegistry::GetInstance()->Resist(CT_LoginHandler::GetHash(), CT_LoginHandler::GetClone());
}
