#include <iostream>

#include "Server/PeerListener.h"
#include "Network/AsyncDispatcher.h"
#include "Network/AsyncEvent.h"

int main()
{
	CAsyncDispatcher::GetInstance()->Start();

	// 데이터 세팅
	CPeerListener::GetInstance()->Start();
	CAsyncDispatcher::GetInstance()->Join();

	return 0;
}