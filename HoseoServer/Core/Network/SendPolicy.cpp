#include "SendPolicy.h"
#include "Peer.h"
#include "AsyncTcpEvent.h"

CSendPolicy::CSendPolicy()
{
}

CSendPolicy::~CSendPolicy()
{
}

void CSendPolicy::PostSend(CPeer* peer, CAsyncTcpEvent* sendEvent)
{
	// �ϴ� �׳� ������.
	
}
