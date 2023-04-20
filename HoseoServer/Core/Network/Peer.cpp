#include "Peer.h"
#include "AsyncTcpComponent.h"
#include "MarshalerComponent.h"
#include "AsyncTcpEvent.h"
#include "AsyncDispatcher.h"
#include "SendPolicy.h"

CPeer::CPeer()
{
	InsertComponent<CAsyncTcpComponent>();
	InsertComponent<CMarshalerComponent>();

	m_SendPolicy = New(CSendPolicy);
}

CPeer::~CPeer()
{
}

int CPeer::OnReceiveEvent(CAsyncTcpEvent* tcpEvent)
{
	CMarshalerComponent* marshaler = GetComponent<CMarshalerComponent>();

	int size = marshaler->UnMarshal(this, tcpEvent->GetBuffer());

	CAsyncTcpComponent* tcpComponent = GetComponent<CAsyncTcpComponent>();
	tcpComponent->Recv();
	
	return size;
}

void CPeer::OnAccepted(CAsyncTcpEvent* tcpEvent)
{
	CAsyncTcpComponent* component = GetComponent<CAsyncTcpComponent>();
	if (nullptr == component)
	{
		return;
	}

	component->OnAccepted(tcpEvent);

	component->Recv();
}

bool CPeer::PostSend(CAsyncTcpEvent* sendEvent)
{
	return m_SendPolicy->PostSend(this, sendEvent);;
}

bool CPeer::Send(CAsyncTcpEvent* sendEvent)
{
	return GetComponent<CAsyncTcpComponent>()->Send(sendEvent);
}

CSocket* CPeer::GetSocket()
{
	return GetComponent<CAsyncTcpComponent>()->GetSocket();
}

void CPeer::SetSocket(CSocket* socket)
{
	GetComponent<CAsyncTcpComponent>()->SetSocket(socket);
}

void CPeer::Disconnect()
{
	CAsyncTcpComponent* component = GetComponent<CAsyncTcpComponent>();
	if (nullptr == component)
	{
		return;
	}

	component->Disconnect();
}
