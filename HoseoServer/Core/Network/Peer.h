#pragma once

#include "Base/ECS/Entity.h"
#include "AsyncTcpEventSink.h"

class CSocket;
class CAsyncTcpEvent;
class CPeer : public CEntity, public CAsyncTcpEventSink
{
public:
	CPeer();
	~CPeer();

public:
	virtual void OnReceiveEvent(CAsyncTcpEvent* tcpEvent);

public:
	CSocket* GetSocket();
	void SetSocket(CSocket* socket);
};

