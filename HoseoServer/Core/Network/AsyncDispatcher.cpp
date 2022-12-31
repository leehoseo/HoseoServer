#include "pch.h"
#include "AsyncDispatcher.h"
#include "Base/Memory/MemoryUtil.hpp"
#include <WS2tcpip.h>
#include <thread>
#include "AsyncEvent.h"
#include "AsyncTcpEventSink.h"
#include "Socket.h"

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

void CAsyncDispatcher::Enqueue(CAsyncEventSink* sink, CAsyncEvent::Buffer* buffer)
{
	PostQueuedCompletionStatus(m_Iocp->GetHandle(), 0, (ULONG_PTR)sink, (LPOVERLAPPED)(buffer));
}

void CAsyncDispatcher::Dequeue(ULONG_PTR* sink, LPOVERLAPPED* buffer)
{
	DWORD ioByte = 0;

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
		CAsyncEvent::Buffer* buffer = nullptr;

		CAsyncDispatcher::GetInstance()->Dequeue(
												 reinterpret_cast<ULONG_PTR*>(&sink)
												,reinterpret_cast<LPOVERLAPPED*>(&buffer));

		if (nullptr != buffer)
		{
			buffer->m_Owner->Execute(sink);
		}
	}
}
