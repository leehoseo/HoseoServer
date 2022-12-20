#include "Server/ListenSystem.h"
#include "Network/AsyncDispatcher.h"

int main()
{
	CAsyncDispatcher::GetInstance()->Start();

	// ������ ����
	CListenSystem::GetInstance()->Start();

	CAsyncDispatcher::GetInstance()->Join();
	
	return 0;
}