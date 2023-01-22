#include "pch.h"
#include "Peer.h"
#include "AsyncTcpComponent.h"
#include "MarshalerComponent.h"
#include "AsyncTcpEvent.h"

CPeer::CPeer()
{
	InsertComponent<CAsyncTcpComponent>();
	InsertComponent<CMarshalerComponent>();
}

CPeer::~CPeer()
{
}

int CPeer::OnReceiveEvent(CAsyncTcpEvent* tcpEvent)
{
	CMarshalerComponent* marshaler = GetComponent<CMarshalerComponent>();

	if (nullptr == marshaler)
	{
		return 0;
	}

	return marshaler->UnMarshal(tcpEvent->GetBuffer());
}

CSocket* CPeer::GetSocket()
{
	return GetComponent<CAsyncTcpComponent>()->GetSocket();
}

void CPeer::SetSocket(CSocket* socket)
{
	GetComponent<CAsyncTcpComponent>()->SetSocket(socket);
}