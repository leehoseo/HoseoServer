#include "TradeServerHandlerSetup.h"
#include "Network/HandlerRegistry.h"
#include "CT_LoginHandler.h"
#include "TQ_LoginHandler.h"
#include "CT_PingHandler.h"

void TradeServerHandlerSetup::Setup()
{
	g_HandlerRegistry::GetInstance()->Resist(CT_LoginHandler::GetHash(), CT_LoginHandler::GetClone());
	g_HandlerRegistry::GetInstance()->Resist(TQ_LoginHandler::GetHash(), TQ_LoginHandler::GetClone());
	g_HandlerRegistry::GetInstance()->Resist(CT_PingHandler::GetHash(), CT_PingHandler::GetClone());
}
