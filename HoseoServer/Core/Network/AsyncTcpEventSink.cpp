#include "pch.h"
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

int CAsyncTcpEventSink::OnReceiveEvent(CAsyncTcpEvent* tcpEvent)
{
	return 0;
}

void CAsyncTcpEventSink::OnSendEvent(CAsyncTcpEvent* tcpEvent)
{
	int num = 0;
	++num;

	num++;
}
