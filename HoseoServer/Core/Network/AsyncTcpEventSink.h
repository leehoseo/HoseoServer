#pragma once
#include "AsyncEventSink.h"

class CAsyncTcpEvent;
class CAsyncTcpEventSink : public CAsyncEventSink
{
public:
	CAsyncTcpEventSink();
	virtual ~CAsyncTcpEventSink();

public:
	virtual void OnAccept(CAsyncTcpEvent* tcpEvent);
	virtual void OnReceive(CAsyncTcpEvent* tcpEvent);
	virtual void OnSend(CAsyncTcpEvent* tcpEvent);
};

