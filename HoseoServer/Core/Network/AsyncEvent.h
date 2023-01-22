#pragma once

#include <WS2tcpip.h>

class CAsyncEventSink;
class CAsyncEvent
{
public:
	struct Body : public OVERLAPPED
	{
	public:
		CAsyncEvent* m_Owner;
	};

	CAsyncEvent();
	virtual ~CAsyncEvent();

public:
	Body& GetBody();

public:
	virtual int Execute(CAsyncEventSink* sink);

private:
	Body m_Body;
};

