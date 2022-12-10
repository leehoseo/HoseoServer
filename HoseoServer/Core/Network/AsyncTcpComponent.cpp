#include "pch.h"
#include "AsyncTcpComponent.h"
#include "Socket.h"
#include "AsyncTcpEvent.h"
#include "AsyncDispatcher.h"

CSocket* CAsyncTcpComponent::GetSocket()
{
    return m_Socket;
}

void CAsyncTcpComponent::Assosiate()
{
    //CAsyncDispatcher::GetInstance()->Associate(reinterpret_cast<CAsyncTcpEventSink*>(m_Owner), m_Socket->GetSocket());
}

void CAsyncTcpComponent::Init()
{
    m_Socket = New(CSocket);
    m_RecvEvent = New(CAsyncTcpEvent);
}
