#include "pch.h"
#include "PeerListener.h"

#include "Network/AsyncDispatcher.h"
//#include "Network/AsyncEvent.h"
#include "Network/AsyncTcpComponent.h"
#include "Network/AsyncTcpEvent.h"
#include "Network/Socket.h"

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

	component->Assosiate(this, component->GetSocket());

	// �ѹ��� ���� �� �ִ� Ŭ���̾�Ʈ�� ��
	for (int index = 0; index < 1; ++index)
	{
		CSocket* newSocket = new CSocket();
		CAsyncTcpEvent* acceptEvent = New(CAsyncTcpEvent, CAsyncTcpEvent::EventType::ACCEPT);
		acceptEvent->SetSocket(newSocket);
		
		if (true == component->Accept(newSocket, acceptEvent))
		{
			// �߰� ó���� ���� �̺�Ʈ�� Enqueue
			CAsyncDispatcher::GetInstance()->Enqueue(nullptr, &acceptEvent->GetTag());
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
	// ���� ������ �ȵȴ�.
	return nullptr;
}

void CPeerListener::OnAcceptEvent(CAsyncTcpEvent* tcpEvent)
{
	CPeer* newPeer = CreatePeer();
	//newPeer->SetSocket(tcpEvent->GetSocket());

	CAsyncTcpComponent* component = newPeer->GetComponent<CAsyncTcpComponent>();
	if (nullptr == component)
	{
		return;
	}

	component->Assosiate(newPeer, component->GetSocket());
	component->PostRecv();
}
