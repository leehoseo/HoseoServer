#include "pch.h"
#include "PeerListener.h"

#include "Network/AsyncDispatcher.h"
//#include "Network/AsyncEvent.h"
#include "Network/AsyncTcpComponent.h"
#include "Network/AsyncTcpEvent.h"
#include "Network/Socket.h"

class CPeerListener::CPeerListenEvent : public CAsyncEvent
{
public:
	CPeerListenEvent() {};
	virtual ~CPeerListenEvent() {};

public:
	int Execute(CAsyncEventSink* sink)
	{
		CAsyncDispatcher::GetInstance()->Enqueue(nullptr, &GetBody());

		return 0;
	}
};

CPeerListener::CPeerListener()
{

}

CPeerListener::~CPeerListener()
{
}

void CPeerListener::Start()
{
	CAsyncTcpComponent* component = GetComponent<CAsyncTcpComponent>();
	if (nullptr == component)
	{
		return;
	}
	component->SetSocket(new CSocket());
	component->Bind(13480);
	component->Listen();

	component->Assosiate();

	// �ѹ��� ���� �� �ִ� Ŭ���̾�Ʈ�� ��
	for (int index = 0; index < 4; ++index)
	{
		CSocket* newSocket = new CSocket();
		CAsyncTcpEvent* acceptEvent = New(CAsyncTcpEvent, CAsyncTcpEvent::EventType::ACCEPT);
		acceptEvent->SetSocket(newSocket);
		
		if (true == component->Accept(newSocket, acceptEvent))
		{
			// �߰� ó���� ���� �̺�Ʈ�� Enqueue
			CAsyncDispatcher::GetInstance()->Enqueue(nullptr, &acceptEvent->GetBody());
		}
		else
		{
			DWORD lastError = GetLastError();
			if (ERROR_IO_PENDING == lastError)
			{
				int num = 0;
				++num;
				// ����
			}
			else
			{
				int num = 0;
				++num;
				// ����
			}

		}
	}
}

CPeer* CPeerListener::CreatePeer()
{
	return New(CPeer);
}

void CPeerListener::OnAcceptEvent(CAsyncTcpEvent* tcpEvent)
{
	CPeer* newPeer = CreatePeer();
	newPeer->SetSocket(tcpEvent->GetSocket());

	CAsyncTcpComponent* component = newPeer->GetComponent<CAsyncTcpComponent>();
	if (nullptr == component)
	{
		return;
	}

	component->Assosiate();

	component->PostRecv();
}
