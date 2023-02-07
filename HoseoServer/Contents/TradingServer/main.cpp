#include "Server/ListenSystem.h"
#include "Lobby/LobbyPeerListener.h"
#include "Network/AsyncDispatcher.h"
#include "Network/AsyncEvent.h"
#include "Base/Task.h"
#include "Network/AsyncTask.h"
#include "Network/Packet.h"
#include "Network/PacketWriter.h"
#include "TradingAppManager.h"
int main()
{
	g_TradingAppManager::GetInstance()->Setup();

	//CPacketWriter<CLogin> packet();
	g_AsyncDispatcher::GetInstance()->Start();

	// ������ ����
	g_ListenSystem::GetInstance()->Init(new CLobbyPeerListener());
	g_ListenSystem::GetInstance()->Start();

	g_AsyncDispatcher::GetInstance()->Join();

	return 0;
}