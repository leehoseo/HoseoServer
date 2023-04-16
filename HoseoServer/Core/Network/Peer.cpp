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
	tcpComponent->PostRecv();
	
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

	component->PostRecv();
}

bool CPeer::PostSend(CAsyncTcpEvent* sendEvent)
{
	m_SendPolicy->PostSend(this, sendEvent);
	return true;
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
