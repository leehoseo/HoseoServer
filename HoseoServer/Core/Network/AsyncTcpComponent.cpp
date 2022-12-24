#include "pch.h"

#include "AsyncTcpComponent.h"
#include "Socket.h"
#include "AsyncTcpEvent.h"
#include "AsyncDispatcher.h"

CSocket* CAsyncTcpComponent::GetSocket()
{
    return m_Socket;
}

void CAsyncTcpComponent::SetSocket(CSocket* socket)
{
    m_Socket = socket;
}

void CAsyncTcpComponent::Assosiate()
{
    const bool result = CAsyncDispatcher::GetInstance()->Associate(reinterpret_cast<CAsyncTcpEventSink*>(m_Owner), GetSocket());
    if (false == result)
    {
        int num = 0;
        ++num;
    }
}

void CAsyncTcpComponent::Init()
{
    //m_Socket = New(CSocket);
    //m_Socket =  new CSocket();
    m_RecvEvent = New(CAsyncTcpEvent);
}

bool CAsyncTcpComponent::Bind(const int port)
{
    return m_Socket->Bind(port);
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

bool CAsyncTcpComponent::PostRecv()
{
    return m_Socket->Connect();
}