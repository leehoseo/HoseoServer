#pragma once
#include "AsyncEventSink.h"

class CAsyncTcpEvent;
class CAsyncTcpEventSink : public CAsyncEventSink
{
public:
	CAsyncTcpEventSink();
	virtual ~CAsyncTcpEventSink();

public:
	virtual void ExecuteTcpEvent(CAsyncTcpEvent* tcpEvent);
};

