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
	case EventType::Accept:
	{
		tcpEventSink->OnAcceptEvent(this);
		break;
	}
	case EventType::Send:
	{
		tcpEventSink->OnSendEvent(this);
		break;
	}
	case EventType::Receive:
	{
		byte = tcpEventSink->OnReceiveEvent(this);
		break;
	}
	case EventType::Connect:
	{
		tcpEventSink->OnConnectEvent(this);
		break;
	}
	case EventType::Disconnect:
	{
		tcpEventSink->OnReceiveEvent(this);
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