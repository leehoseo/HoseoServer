#include "AsyncTcpEventSink.h"
#include "AsyncTcpEvent.h"

CAsyncTcpEventSink::CAsyncTcpEventSink()
{
}

CAsyncTcpEventSink::~CAsyncTcpEventSink()
{
}

void CAsyncTcpEventSink::OnAcceptEvent(CAsyncTcpEvent* tcpEvent)
{
}

void CAsyncTcpEventSink::OnConnectEvent(CAsyncTcpEvent* tcpEvent)
{
	return;
}

int CAsyncTcpEventSink::OnReceiveEvent(CAsyncTcpEvent* tcpEvent)
{
	return 0;
}

void CAsyncTcpEventSink::OnSendEvent(CAsyncTcpEvent* tcpEvent)
{
}

void CAsyncTcpEventSink::OnDisconnectEvent(CAsyncTcpEvent* tcpEvent)
{
}