#include "Server/ListenSystem.h"
#include "Lobby/LobbyPeerListener.h"
#include "Network/AsyncDispatcher.h"
#include "Network/AsyncEvent.h"
#include "Base/Task.h"
#include "Network/AsyncTask.h"
#include "Network/Packet.h"
#include "Network/PacketWriter.h"
#include "TradePacket.h"

int main()
{
	//CPacketWriter<CLogin> packet();
	CAsyncDispatcher::GetInstance()->Start();

	// 데이터 세팅
	CListenSystem::GetInstance()->Init(new CLobbyPeerListener());
	CListenSystem::GetInstance()->Start();

	CAsyncDispatcher::GetInstance()->Join();

	return 0;
}