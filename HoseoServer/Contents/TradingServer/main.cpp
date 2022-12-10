#include <iostream>

#include "Server/PeerListener.h"
#include "Network/AsyncDispatcher.h"
#include "Network/AsyncEvent.h"

int main()
{
	CAsyncDispatcher::GetInstance()->Start();

	// ������ ����
	CPeerListener::GetInstance()->Start();
	CAsyncDispatcher::GetInstance()->Join();

	return 0;
}