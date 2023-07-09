#include "pch.h"
#include "ClientListener.h"
#include "Network/AsyncDispatcher.h"
#include "Network/AsyncTcpComponent.h"
#include "Network/AsyncTcpEvent.h"
#include "Network/Socket.h"
#include "ClientConfig.h"

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
	component->SetSocket(New(CSocket));

	sockaddr_in server_addr;
	ZeroMemory(&server_addr, sizeof(server_addr));

	server_addr.sin_family = PF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	component->Bind(server_addr);

	g_AsyncDispatcher::GetInstance()->Associate(this, component->GetSocket());
	
	std::string addr = g_ClientConfig::GetInstance()->m_LoginAddr;
	u_short port = g_ClientConfig::GetInstance()->m_LoginPort;

	server_addr.sin_port = htons(port);
	inet_pton(AF_INET, addr.c_str(), &server_addr.sin_addr.s_addr);
	component->Connect(server_addr, New(CAsyncTcpEvent, CAsyncTcpEvent::EventType::Connect));
}

void CClientListener::OnConnectEvent(CAsyncTcpEvent* tcpEvent)
{
	CAsyncTcpComponent* component = GetComponent<CAsyncTcpComponent>();
	if (nullptr == component)
	{
		return;
	}

	component->Recv();

	CAsyncTcpEvent* sendEvent = New(CAsyncTcpEvent, CAsyncTcpEvent::EventType::Send);
	component->Send(sendEvent);

}
