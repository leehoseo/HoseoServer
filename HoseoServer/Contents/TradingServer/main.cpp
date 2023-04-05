#include "TradeServerAppManager.h"
#include "TradeShared/TradeSharedPacket.h"

int main()
{
	auto hey = MakePacketBuffer();

	g_TradeServerAppManager::GetInstance()->Setup();
	return 0;
}