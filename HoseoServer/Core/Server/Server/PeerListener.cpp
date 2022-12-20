#include "pch.h"
#include "PeerListener.h"

#include "Network/AsyncDispatcher.h"
//#include "Network/AsyncEvent.h"
#include "Network/AsyncTcpComponent.h"
#include "Network/AsyncTcpEvent.h"

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

	component->Listen();

	component->Assosiate();

	// �ѹ��� ���� �� �ִ� Ŭ���̾�Ʈ�� ��
	for (int index = 0; index < 4; ++index)
	{
		CPeer* newPeer = CreatePeer();
		CAsyncTcpEvent* acceptEvent = New(CAsyncTcpEvent);
		if (true == component->Accept(newPeer->GetHandle(), acceptEvent))
		{
			// �߰� ó���� ���� �̺�Ʈ�� Enqueue
			CAsyncDispatcher::GetInstance()->Enqueue(nullptr, &acceptEvent->GetBuffer());
		}
		else
		{
			DWORD lastError = GetLastError();
			if (ERROR_SIGNAL_PENDING == lastError)
			{
				// ����
			}
			else
			{
				// ����
			}
		}
	}
}

CPeer* CPeerListener::CreatePeer()
{
	return New(CPeer);
}