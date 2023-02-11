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
	virtual int Execute(CAsyncEventSink* sink);
	
public:
	EventType GetType() { return m_Type; }
	CSocket* GetSocket() const { return m_Socket; };
	void SetSocket(CSocket* socket) { m_Socket = socket; }

	const int GetTotalSize() const { return m_TotalSize; }
	
	char* GetBuffer() { return m_Buffer; };
	void SetBuffer(char* buffer) { m_Buffer = buffer; };

	void CleanBuffer();
	WSABUF* GetWsaBuffer() { return &m_WsaBuffer; };
	
private:
	CSocket* m_Socket;
	EventType m_Type;

	char* m_Buffer;
	int m_TotalSize;
	WSABUF m_WsaBuffer;
};