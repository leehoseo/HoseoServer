#include "TradeClientAppManager.h"
#include "TradeShared/TradeSharedPacket.h"
#include "Network/PacketWriter.h"
#include "Network/AsyncDispatcher.h"
#include "Network/ListenSystem.h"

int main()
{
	// 기타 데이터 세팅
	g_TradeClientAppManager::GetInstance()->Setup();

	// 서버 연결 시작
	g_ListenSystem::GetInstance()->Start();

	// main 스래드는 하는일 없다.
	g_AsyncDispatcher::GetInstance()->Join();

	return 0;
}