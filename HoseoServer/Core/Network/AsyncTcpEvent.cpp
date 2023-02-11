#include "AsyncTcpEvent.h"
#include "Socket.h"
#include "AsyncTcpEventSink.h"

CAsyncTcpEvent::CAsyncTcpEvent(const EventType type)
	: m_Type(type)
	, m_TotalSize(0)
{
	m_Buffer = new char[1204]; // 일단 이렇게
	ZeroMemory(&m_WsaBuffer, sizeof(m_WsaBuffer));
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

void CAsyncTcpEvent::CleanBuffer()
{
	ZeroMemory(m_Buffer, sizeof(m_Buffer));
}