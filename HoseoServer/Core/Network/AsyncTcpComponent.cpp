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

bool CAsyncTcpComponent::Bind(sockaddr_in& addr)
{
    return m_Socket->Bind(addr);
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

void CAsyncTcpComponent::OnAccepted(CAsyncTcpEvent* acceptEvent)
{
    m_Socket->OnAccepted(acceptEvent);
}

bool CAsyncTcpComponent::Connect(sockaddr_in& addr)
{
    return m_Socket->Connect(addr);
}

bool CAsyncTcpComponent::PostRecv()
{
    // �ޱ� �� recvEvent�� ���� ó��
    return m_Socket->Recv(m_RecvEvent);
}

bool CAsyncTcpComponent::PostSend(char* buffer)
{
    CAsyncTcpEvent* sendEvent = new CAsyncTcpEvent(CAsyncTcpEvent::EventType::SEND);
    sendEvent->SetBuffer(buffer);

    return m_Socket->Send(sendEvent);
}
