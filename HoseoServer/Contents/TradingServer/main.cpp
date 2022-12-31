#include "Server/ListenSystem.h"
#include "Lobby/LobbyPeerListener.h"
#include "Network/AsyncDispatcher.h"
#include "Network/AsyncEvent.h"
#include "Base/Task.h"
#include "Network/AsyncTask.h"
int main()
{
	CAsyncTask* task = new CAsyncTask([]()
		{
			CAsyncDispatcher::GetInstance()->Start();
		});

	CAsyncDispatcher::GetInstance()->Start();

	// 데이터 세팅
	CListenSystem::GetInstance()->Init(new CLobbyPeerListener());
	CListenSystem::GetInstance()->Start();


	CAsyncTask::PostTask(task);

	CAsyncDispatcher::GetInstance()->Join();

	return 0;
}