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
	//상황에 따라서  Enqueue, 직접 호출, Peer Send가 될 수 있어야 한다.
	g_AsyncDispatcher::GetInstance()->Enqueue(nullptr, &sendEvent->GetTag());
	return true;
}
