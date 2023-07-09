#include "TradeClientAppManager.h"
#include "TradeShared/TradeSharedPacket.h"
#include "Network/PacketWriter.h"
#include "Network/AsyncDispatcher.h"
#include "Network/ListenSystem.h"

int main()
{
	// ��Ÿ ������ ����
	g_TradeClientAppManager::GetInstance()->Setup();

	// ���� ���� ����
	g_ListenSystem::GetInstance()->Start();

	// main ������� �ϴ��� ����.
	g_AsyncDispatcher::GetInstance()->Join();

	return 0;
}