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
	void Execute(CAsyncEventSink* sink)
	{
		CAsyncDispatcher::GetInstance()->Enqueue(nullptr, &GetBuffer());
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

	// 한번에 받을 수 있는 클라이언트의 수
	for (int index = 0; index < 4; ++index)
	{
		CSocket* newSocket = new CSocket();
		CAsyncTcpEvent* acceptEvent = New(CAsyncTcpEvent);
		acceptEvent->m_Socket = newSocket;
		
		if (true == component->Accept(newSocket, acceptEvent))
		{
			// 추가 처리를 위해 이벤트를 Enqueue
			CAsyncDispatcher::GetInstance()->Enqueue(nullptr, &acceptEvent->GetBuffer());
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
}

CPeer* CPeerListener::CreatePeer()
{
	return New(CPeer);
}

void CPeerListener::ExecuteTcpEvent(CAsyncTcpEvent* tcpEvent)
{
	CPeer* newPeer = CreatePeer();
	newPeer->SetSocket(tcpEvent->m_Socket);

	CAsyncTcpComponent* component = newPeer->GetComponent<CAsyncTcpComponent>();
	if (nullptr == component)
	{
		return;
	}

	component->Assosiate();

	component->PostRecv();
}
