#include "TradeClientAppManager.h"
#include "TradeShared/TradeSharedPacket.h"
#include "Network/PacketWriter.h"
#include "Network/AsyncDispatcher.h"

int main()
{
	g_TradeClientAppManager::GetInstance()->Setup();

	return 0;
}