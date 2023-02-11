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

	g_AsyncDispatcher::GetInstance()->Associate(this, component->GetSocket());

	// �ѹ��� ���� �� �ִ� Ŭ���̾�Ʈ�� �� 4
	for (int index = 0; index < 4; ++index)
	{
		CAsyncTcpEvent* acceptEvent = New(CAsyncTcpEvent, CAsyncTcpEvent::EventType::ACCEPT);
		PostAccept(acceptEvent);
	}
}

CPeer* CPeerListener::CreatePeer()
{
	// ���� ������ �ȵȴ�.
	return nullptr;
}

void CPeerListener::PostAccept(CAsyncTcpEvent* acceptEvent)
{
	CAsyncTcpComponent* component = GetComponent<CAsyncTcpComponent>();
	if (nullptr == component)
	{
		return;
	}

	CSocket* newSocket = new CSocket();
	acceptEvent->SetSocket(newSocket);

	if (true == component->Accept(newSocket, acceptEvent))
	{
		// �߰� ó���� ���� �̺�Ʈ�� Enqueue
		g_AsyncDispatcher::GetInstance()->Enqueue(nullptr, &acceptEvent->GetTag());
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

void CPeerListener::OnAcceptEvent(CAsyncTcpEvent* tcpEvent)
{
	CPeer* newPeer = CreatePeer();

	newPeer->OnAccepted(tcpEvent);

	// �̺�Ʈ �ٽ� ��Ȱ���Ѵ�.
	tcpEvent->SetSocket(nullptr);
	tcpEvent->CleanBuffer();
	
	PostAccept(tcpEvent);
}
