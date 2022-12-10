#include "pch.h"
#include "PeerListener.h"

#include "Network/AsyncDispatcher.h"
#include "Network/AsyncEvent.h"
#include "Network/AsyncTcpComponent.h"

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

	component->Assosiate();
	component
	//CAsyncDispatcher::GetInstance()->Enqueue(nullptr, &m_listenEvent->GetBuffer());
}

void CPeerListener::Accept()
{
	/*OverlappedBuffer* overlappedBuffer = PoolManager::getInstance()->getOverlappedBufferPool().pop();
	Session* newSession = PoolManager::getInstance()->getSessionPool().pop();
	addSession(newSession);

	overlappedBuffer->_sessionKey = newSession->getSessionKey();
	overlappedBuffer->_type = BufferType::ACCEPT;

	LPFN_ACCEPTEX acceptFunc = nullptr;

	DWORD dwbyte{ 0 };
	GUID GuidAccept = WSAID_ACCEPTEX;
	WSAIoctl(_mainSession->getSocketHandle(), SIO_GET_EXTENSION_FUNCTION_POINTER,
		&GuidAccept, sizeof(GuidAccept),
		&acceptFunc, sizeof(acceptFunc),
		&dwbyte, NULL, NULL);


	acceptFunc(_mainSession->getSocketHandle(), newSession->getSocketHandle(), &overlappedBuffer->_buffer, sizeof(TrNetworkConnectReq)
		, sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16, &dwbyte, reinterpret_cast<LPOVERLAPPED>(&overlappedBuffer->_overlapped));*/

}