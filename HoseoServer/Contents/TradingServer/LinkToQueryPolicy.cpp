#include "LinkToQueryPolicy.h"
#include "Network/AsyncDispatcher.h"
#include "Network/AsyncEvent.h"

CLinkToQueryPolicy::CLinkToQueryPolicy()
{
}

CLinkToQueryPolicy::~CLinkToQueryPolicy()
{
}

void CLinkToQueryPolicy::Setup()
{
}

bool CLinkToQueryPolicy::Send(CAsyncEvent* sendEvent)
{
	//��Ȳ�� ����  Enqueue, ���� ȣ��, Peer Send�� �� �� �־�� �Ѵ�.
	g_AsyncDispatcher::GetInstance()->Enqueue(nullptr, &sendEvent->GetTag());
	return true;
}
