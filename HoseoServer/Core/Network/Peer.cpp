#include "pch.h"
#include "Peer.h"
#include "AsyncTcpComponent.h"

CPeer::CPeer()
{
	InsertComponent<CAsyncTcpComponent>();
}

CPeer::~CPeer()
{
}

CSocket* CPeer::GetSocket()
{
	return GetComponent<CAsyncTcpComponent>()->GetSocket();
}

void CPeer::SetSocket(CSocket* socket)
{
	GetComponent<CAsyncTcpComponent>()->SetSocket(socket);
}