#include <iostream>
#include "Network/AsyncDispatcher.h"

int main()
{
	g_AsyncDispatcher::GetInstance()->Start();

	return 0;
}