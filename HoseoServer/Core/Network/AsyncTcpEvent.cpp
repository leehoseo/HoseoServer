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

int CAsyncTcpEvent::Execute(CAsyncEventSink* sink)
{
	CAsyncTcpEventSink* tcpEventSink = dynamic_cast<CAsyncTcpEventSink*>(sink);
	int byte = 0;
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
		byte = tcpEventSink->OnReceiveEvent(this);
		break;
	}
	default:
		break;
	}

	return byte;
}