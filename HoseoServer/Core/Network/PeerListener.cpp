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

	CSocket* newSocket = New(CSocket);
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
			// ����
		}
		else
		{
			// ����
		}

	}
}

void CPeerListener::OnAcceptEvent(CAsyncTcpEvent* tcpEvent)
{
	CPeer* newPeer = CreatePeer();
	newPeer->SetSocket(tcpEvent->GetSocket());
	
	newPeer->OnAccepted(tcpEvent);

	g_AsyncDispatcher::GetInstance()->Associate(newPeer, newPeer->GetSocket());

	// �̺�Ʈ �ٽ� ��Ȱ���Ѵ�.
	tcpEvent->SetSocket(nullptr);
	tcpEvent->CleanBuffer();
	
	PostAccept(tcpEvent);
}