#include "SendPolicy.h"
#include "Peer.h"
#include "AsyncTcpEvent.h"

CSendPolicy::CSendPolicy()
{
}

CSendPolicy::~CSendPolicy()
{
}

bool CSendPolicy::PostSend(CPeer* peer, CAsyncTcpEvent* sendEvent)
{
	// �ϴ� �׳� ������.
	return peer->Send(sendEvent);
}
