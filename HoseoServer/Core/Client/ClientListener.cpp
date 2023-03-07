#include "pch.h"
#include "ClientListener.h"
#include "Network/AsyncDispatcher.h"
//#include "Network/AsyncEvent.h"
#include "Network/AsyncTcpComponent.h"
#include "Network/AsyncTcpEvent.h"
#include "Network/Socket.h"


CClientListener::CClientListener()
{
}

CClientListener::~CClientListener()
{
}

void CClientListener::Start()
{
	CAsyncTcpComponent* component = GetComponent<CAsyncTcpComponent>();
	if (nullptr == component)
	{
		return;
	}
	component->SetSocket(new CSocket());

	sockaddr_in server_addr;
	ZeroMemory(&server_addr, sizeof(server_addr));

	server_addr.sin_family = PF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	component->Bind(server_addr);

	g_AsyncDispatcher::GetInstance()->Associate(this, component->GetSocket());
	
	CAsyncTcpEvent* connectEvent = new CAsyncTcpEvent(CAsyncTcpEvent::EventType::Connect);

	server_addr.sin_port = htons(13480);
	inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr.s_addr);
	component->Connect(server_addr, connectEvent);
}

void CClientListener::OnConnectEvent(CAsyncTcpEvent* tcpEvent)
{
	CAsyncTcpComponent* component = GetComponent<CAsyncTcpComponent>();
	if (nullptr == component)
	{
		return;
	}

	component->PostRecv();
}
