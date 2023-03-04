#pragma once
#include "Base/Component.h"

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>
#include <mswsock.h>
#include <stdio.h>

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
	bool Bind(sockaddr_in& addr);
	bool Listen();
	bool Accept(CSocket* newSocket, CAsyncTcpEvent* acceptEvent);
	void OnAccepted(CAsyncTcpEvent* acceptEvent);
	bool Connect(sockaddr_in& addr);
	bool PostRecv();
	bool PostSend(char* buffer);
private:
	CSocket* m_Socket;
	CAsyncTcpEvent* m_RecvEvent;
};

