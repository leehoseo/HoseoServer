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
	case EventType::ACCEPT:
	{
		tcpEventSink->OnAcceptEvent(this);
		break;
	}
	case EventType::SEND:
	{
		tcpEventSink->OnSendEvent(this);
		break;
	}
	case EventType::RECEIVE:
	{
		tcpEventSink->OnReceiveEvent(this);
		break;
	}
	default:
		break;
	}
}