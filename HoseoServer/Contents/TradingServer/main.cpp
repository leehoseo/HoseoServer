#include "Server/ListenSystem.h"
#include "Network/AsyncDispatcher.h"

int main()
{
	CAsyncDispatcher::GetInstance()->Start();

	// 데이터 세팅
	CListenSystem::GetInstance()->Start();

	CAsyncDispatcher::GetInstance()->Join();
	
	return 0;
}