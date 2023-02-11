#pragma once
#include "Base/ECS/Component.h"

class CSocket;
class CAsyncTcpEvent;
class CAsyncTcpEventSink;
class CAsyncTcpComponent : public CComponent
{
	COMPONENT_FOUNDATION(CAsyncTcpComponent);

public:
	CSocket* GetSocket();
	void SetSocket(CSocket* socket);
protected:
	virtual void Init();

public:
	bool Bind(const int port);
	bool Listen();
	bool Accept(CSocket* newSocket, CAsyncTcpEvent* acceptEvent);
	void OnAccepted(CAsyncTcpEvent* acceptEvent);
	bool Connect();
	bool PostRecv();
private:
	CSocket* m_Socket;
	CAsyncTcpEvent* m_RecvEvent;
};

