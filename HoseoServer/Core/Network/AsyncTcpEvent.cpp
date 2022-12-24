#include "pch.h"
#include "AsyncTcpEvent.h"
#include "Socket.h"
#include "AsyncTcpEventSink.h"

CAsyncTcpEvent::CAsyncTcpEvent()
{
}

CAsyncTcpEvent::~CAsyncTcpEvent()
{
}

void CAsyncTcpEvent::Execute(CAsyncEventSink* sink)
{
	CAsyncTcpEventSink* tcpEventSink = static_cast<CAsyncTcpEventSink*>(sink);
}
