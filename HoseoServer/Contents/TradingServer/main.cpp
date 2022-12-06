#include <iostream>

#include "Network/AsyncDispatcher.h"
#include "Network/AsyncEvent.h"

#include <thread>
int main()
{
	//std::thread thread = std::thread(&CThread::Run);

	CAsyncDispatcher::GetInstance()->Start();

	CAsyncEventSink* sink = new CAsyncEventSink();
	sink->m_Num = 3;
	CAsyncEvent* event = new CAsyncEvent();
	event->m_Num = 7;
	CAsyncDispatcher::GetInstance()->Enqueue(sink, &event->GetBuffer());

	while (true)
	{

	}

	return 0;
}