#include <iostream>
#include "Network/AsyncDispatcher.h"

int main()
{
	CAsyncDispatcher::GetInstance()->Start();

	return 0;
}