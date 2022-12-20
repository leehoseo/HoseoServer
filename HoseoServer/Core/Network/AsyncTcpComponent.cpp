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
    CAsyncDispatcher::GetInstance()->Associate(reinterpret_cast<CAsyncTcpEventSink*>(m_Owner), GetSocket());
}

void CAsyncTcpComponent::Init()
{
    m_Socket = New(CSocket);
    m_RecvEvent = New(CAsyncTcpEvent);
}

bool CAsyncTcpComponent::Listen()
{
    return m_Socket->Listen();
}

///
bool CAsyncTcpComponent::Accept(CSocket* newSocket, CAsyncTcpEvent* acceptEvent)
{
    const bool result = m_Socket->Accept(newSocket, acceptEvent);
    // https://programmingdiary.tistory.com/4
    // Owner가 Listener여야 될탠데
    return result;
}

bool CAsyncTcpComponent::Connect()
{
    return m_Socket->Connect();
}