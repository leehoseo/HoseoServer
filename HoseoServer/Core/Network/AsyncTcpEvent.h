#pragma once
#include "AsyncEvent.h"

class CSocket;
class CAsyncEventSink;
class CSendPolicy;
class CAsyncTcpEvent : public CAsyncEvent
{
public:
	enum class EventType
	{
		  Accept = 0
		, Send
		, Receive
		, Connect
		, Disconnect
		, Count
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
	
	uint8_t* GetBuffer() { return m_Buffer; };
	void SetBuffer(uint8_t* buffer) { m_Buffer = buffer; };

	void CleanBuffer();
	WSABUF* GetWsaBuffer() { return &m_WsaBuffer; };
	
private:
	CSocket* m_Socket;
	EventType m_Type;

	uint8_t* m_Buffer;
	int m_TotalSize;
	WSABUF m_WsaBuffer;
};