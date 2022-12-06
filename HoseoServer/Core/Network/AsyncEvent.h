#pragma once

#include "AsyncEventSink.h"
#include <WS2tcpip.h>

class CAsyncEvent
{
public:
	struct Buffer : public OVERLAPPED
	{
	public:
		CAsyncEvent* m_Owner;
	};

	CAsyncEvent();
	virtual ~CAsyncEvent();

public:
	Buffer& GetBuffer();

public:
	virtual void Execute(CAsyncEventSink* sink);

	int m_Num;
private:
	Buffer m_Buffer;
};

