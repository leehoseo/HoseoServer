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
    m_RecvEvent = New(CAsyncTcpEvent, CAsyncTcpEvent::EventType::RECEIVE);
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
    // Owner�� Listener���� ���ĵ�
    return result;
}

bool CAsyncTcpComponent::Connect()
{
    return m_Socket->Connect();
}

bool CAsyncTcpComponent::PostRecv()
{
//       evt->TotalBytes = offset;
//
//#ifdef ZERO_BYTE_RECV_ENABLED
//   evt->WsaBuf.buf = nullptr;
//   evt->WsaBuf.len = 0;
//#else
//   evt->WsaBuf.buf = evt->Buffer + offset;
//   evt->WsaBuf.len = evt->Capacity - offset;
//#endif

    return m_Socket->Connect();
}