#pragma once
#include "AsyncEventSink.h"

class CAsyncTcpEvent;
class CAsyncTcpEventSink : public CAsyncEventSink
{
public:
	CAsyncTcpEventSink();
	virtual ~CAsyncTcpEventSink();

public:
	virtual void OnAcceptEvent(CAsyncTcpEvent* tcpEvent);
	virtual void OnReceiveEvent(CAsyncTcpEvent* tcpEvent);
	virtual void OnSendEvent(CAsyncTcpEvent* tcpEvent);
};

