#pragma once
#include "AsyncEventSink.h"
#include "Peer.h"

class CAsyncTcpEventSink : public CAsyncEventSink , CPeer
{
public:
	CAsyncTcpEventSink();
	virtual ~CAsyncTcpEventSink();
};

