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

	// 한번에 받을 수 있는 클라이언트의 수 4
	for (int index = 0; index < 4; ++index)
	{
		CAsyncTcpEvent* acceptEvent = New(CAsyncTcpEvent, CAsyncTcpEvent::EventType::ACCEPT);
		PostAccept(acceptEvent);
	}
}

CPeer* CPeerListener::CreatePeer()
{
	// 여긴 들어오면 안된다.
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
		// 추가 처리를 위해 이벤트를 Enqueue
		g_AsyncDispatcher::GetInstance()->Enqueue(nullptr, &acceptEvent->GetTag());
	}
	else
	{
		DWORD lastError = GetLastError();
		if (ERROR_IO_PENDING == lastError)
		{
			int num = 0;
			++num;
			// 성공
		}
		else
		{
			int num = 0;
			++num;
			// 실패
		}

	}
}

void CPeerListener::OnAcceptEvent(CAsyncTcpEvent* tcpEvent)
{
	CPeer* newPeer = CreatePeer();

	newPeer->OnAccepted(tcpEvent);

	// 이벤트 다시 재활용한다.
	tcpEvent->SetSocket(nullptr);
	tcpEvent->CleanBuffer();
	
	PostAccept(tcpEvent);
}
