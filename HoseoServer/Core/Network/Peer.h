#pragma once

#include "Base/ECS/Entity.h"
#include "AsyncTcpEventSink.h"

class CSocket;
class CPeer : public CEntity, public CAsyncTcpEventSink
{
public:
	CPeer();
	~CPeer();

public:
	CSocket* GetSocket();
	void SetSocket(CSocket* socket);
};

