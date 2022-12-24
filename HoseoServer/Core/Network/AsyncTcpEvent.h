#pragma once
#include "AsyncEvent.h"

class CSocket;
class CAsyncEventSink;

class CAsyncTcpEvent : public CAsyncEvent
{
public:
	CAsyncTcpEvent();
	virtual ~CAsyncTcpEvent();
public:
	virtual void Execute(CAsyncEventSink* sink);

public:
	CSocket* m_Socket;
	int m_Num;


};

