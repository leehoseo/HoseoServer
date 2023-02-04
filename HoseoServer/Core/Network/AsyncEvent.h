#pragma once

#include <WS2tcpip.h>

class CAsyncEventSink;
class CAsyncEvent
{
public:
	struct Tag : public OVERLAPPED
	{
	public:
		CAsyncEvent* m_Owner;
	};

	CAsyncEvent();
	virtual ~CAsyncEvent();

public:
	Tag& GetTag();

public:
	virtual int Execute(CAsyncEventSink* sink);

private:
	Tag m_Body;
};

