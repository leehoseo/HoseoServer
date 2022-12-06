#include "pch.h"
#include "AsyncTcpComponent.h"


CSocket* CAsyncTcpComponent::GetSocket()
{
    return m_Socket;
}

void CAsyncTcpComponent::Init()
{
    m_Socket = New(CSocket);
}
