#pragma once
#include "AsyncEvent.h"

class CSocket;
class CAsyncEventSink;

class CAsyncTcpEvent : public CAsyncEvent
{
public:
	enum class EventType
	{
		  ACCEPT = 0
		, SEND
		, RECEIVE
		, COUNT
	};
public:
	CAsyncTcpEvent(const EventType type);
	virtual ~CAsyncTcpEvent();

public:
	virtual void Execute(CAsyncEventSink* sink);
	EventType GetType() { return m_Type; }

public:
	CSocket* m_Socket;

private:
	EventType m_Type;
};

