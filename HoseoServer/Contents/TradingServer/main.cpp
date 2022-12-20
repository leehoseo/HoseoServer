#include "Server/ListenSystem.h"
#include "Lobby/LobbyPeerListener.h"
#include "Network/AsyncDispatcher.h"
#include "Network/AsyncEvent.h"

int main()
{
	CAsyncDispatcher::GetInstance()->Start();

	// 데이터 세팅
	CListenSystem::GetInstance()->Init(new CLobbyPeerListener());
	CListenSystem::GetInstance()->Start();
	CAsyncDispatcher::GetInstance()->Join();

	return 0;
}