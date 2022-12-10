#pragma once

#include <WS2tcpip.h>

class CAsyncEventSink;
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

private:
	Buffer m_Buffer;
};

