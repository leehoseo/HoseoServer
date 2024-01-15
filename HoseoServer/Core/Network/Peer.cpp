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

	//while (handled < total)
	//{
	//	int result = buffer->m_Owner->Execute(sink);
	//	//int result = m_Marshaller->Unmarshall(this, m_RecvEvent->Buffer + handled, total - handled);
	//	if (result <= 0)
	//	{
	//		CPeerFacade::Disconnected(dynamic_cast<CAsyncTcpEventSink*>(sink));
	//		break; // 더 이상 읽을 수 있는 것이 없거나, 에러가 발생
	//	}
	//	else if (result > 0)
	//	{
	//		handled += result; // 정상 처리
	//	}
	//}

	int size = marshaler->UnMarshal(this, tcpEvent->GetBuffer());

	CAsyncTcpComponent* tcpComponent = GetComponent<CAsyncTcpComponent>();
	tcpComponent->Recv();
	
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

	component->Recv();
}

bool CPeer::PostSend(CAsyncTcpEvent* sendEvent)
{
	return m_SendPolicy->PostSend(this, sendEvent);;
}

bool CPeer::Send(CAsyncTcpEvent* sendEvent)
{
	return GetComponent<CAsyncTcpComponent>()->Send(sendEvent);
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
