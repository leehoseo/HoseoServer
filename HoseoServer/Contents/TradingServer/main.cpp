#include "TradeServerAppManager.h"
#include "Network/PacketWriter.h"
#include "TradeShared/TradeSharedPacket.h"

int main()
{
	CPacketWriter<CTradePacket> writer;
	writer->m_Age = 5;
	writer->m_Name = "hey";


	uint8_t* buffer = writer();



	g_TradeServerAppManager::GetInstance()->Setup();
	return 0;
}