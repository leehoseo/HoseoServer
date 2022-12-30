#include "pch.h"
#include "AsyncTcpEvent.h"
#include "Socket.h"
#include "AsyncTcpEventSink.h"

CAsyncTcpEvent::CAsyncTcpEvent(const EventType type)
	: m_Type(type)
{
}

CAsyncTcpEvent::~CAsyncTcpEvent()
{
}

void CAsyncTcpEvent::Execute(CAsyncEventSink* sink)
{
	CAsyncTcpEventSink* tcpEventSink = static_cast<CAsyncTcpEventSink*>(sink);

	switch (GetType())
	{
	case ACCEPT:
	{
		tcpEventSink->
		break;
	}
	case SEND:
	{
		break;
	}
	case RECEIVE:
	{
		break;
	}
	default:
		break;
	}
}
