#include "PeerFacade.h"
#include "AsyncTcpEventSink.h"
#include "Peer.h"

void CPeerFacade::Disconnected(CAsyncTcpEventSink* sink)
{
	CPeer* peer = dynamic_cast<CPeer*>(sink);

	peer->Disconnect();
}
