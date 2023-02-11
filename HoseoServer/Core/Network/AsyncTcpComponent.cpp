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
    // Owner가 Listener여야 될탠데
    return result;
}

void CAsyncTcpComponent::OnAccepted(CAsyncTcpEvent* acceptEvent)
{
    m_Socket->OnAccepted(acceptEvent);
}

bool CAsyncTcpComponent::Connect()
{
    return m_Socket->Connect();
}

bool CAsyncTcpComponent::PostRecv()
{
    //m_RecvEvent->GetBuffer
//       evt->TotalBytes = offset;
//
//#ifdef ZERO_BYTE_RECV_ENABLED
//   evt->WsaBuf.buf = nullptr;
//   evt->WsaBuf.len = 0;
//#else
//   evt->WsaBuf.buf = evt->Buffer + offset;
//   evt->WsaBuf.len = evt->Capacity - offset;
//#endif
//
//
//   m_RecvEvent;

    return m_Socket->Connect();
}