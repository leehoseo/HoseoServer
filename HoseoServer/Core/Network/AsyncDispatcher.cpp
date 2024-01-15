#include "AsyncDispatcher.h"
#include <thread>
#include "AsyncEvent.h"
#include "AsyncTcpEventSink.h"
#include "Socket.h"
#include "PeerFacade.h"

CAsyncDispatcher::CAsyncDispatcher()
{
	m_Iocp = New(CIocp);
}

CAsyncDispatcher::~CAsyncDispatcher()
{
}

void CAsyncDispatcher::Start()
{
	m_Iocp->Start();

	const int threadCount = 4;
	for (int index = 0; index < threadCount; ++index)
	{
		CIocpThread* workerThread = New(CIocpThread);
		workerThread->Init();

		m_ThreadList.push_back(workerThread);
	}
}

void CAsyncDispatcher::Join()
{
	const int count = m_ThreadList.size();

	for (auto thread : m_ThreadList)
	{
		thread->Join();
	}
}

bool CAsyncDispatcher::Associate(CAsyncTcpEventSink* sink, CSocket* socket)
{
	return nullptr != CreateIoCompletionPort((HANDLE)socket->GetHandle(), m_Iocp->GetHandle(), (ULONG_PTR)sink, 0);
}

void CAsyncDispatcher::Enqueue(CAsyncEventSink* sink, CAsyncEvent::Tag* buffer)
{
	PostQueuedCompletionStatus(m_Iocp->GetHandle(), 0, (ULONG_PTR)sink, (LPOVERLAPPED)(buffer));
}

void CAsyncDispatcher::Dequeue(ULONG_PTR* sink, LPOVERLAPPED* buffer, DWORD& ioByte)
{
	GetQueuedCompletionStatus(m_Iocp->GetHandle(), &ioByte, sink, buffer, INFINITE);
}


CAsyncDispatcher::CIocpThread::CIocpThread()
{
}

CAsyncDispatcher::CIocpThread::~CIocpThread()
{
}

void CAsyncDispatcher::CIocpThread::Run()
{
	while (true)
	{
		CAsyncEventSink* sink = nullptr;
		CAsyncEvent::Tag* buffer = nullptr;
		DWORD ioByte = 0;

		g_AsyncDispatcher::GetInstance()->Dequeue(
												  reinterpret_cast<ULONG_PTR*>(&sink)
												, reinterpret_cast<LPOVERLAPPED*>(&buffer)
												, ioByte);

		const DWORD lastError = GetLastError();
		if ( 0 < ioByte && 0 != lastError)
		{
			int result = buffer->m_Owner->Execute(sink);
			if (result <= 0)
			{
				CPeerFacade::Disconnected(sink);
				break; // 더 이상 읽을 수 있는 것이 없거나, 에러가 발생
			}

			if (ioByte != result)
			{
				// 무슨 문제일까...
			}
		}
		else
		{
			CPeerFacade::Disconnected(sink);
		}
	}
}
