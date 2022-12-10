#include "pch.h"
#include "AsyncDispatcher.h"
#include "Base/Memory/MemoryUtil.hpp"
#include <WS2tcpip.h>
#include <thread>
#include "AsyncEvent.h"
#include "AsyncTcpEventSink.h"

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


bool CAsyncDispatcher::Associate(CAsyncTcpEventSink* sink, HANDLE& socket)
{
	//m_Iocp->Assosiate(peer);
	return CreateIoCompletionPort(socket, m_Iocp->GetHandle(), (ULONG_PTR)sink, 0);
}

void CAsyncDispatcher::Enqueue(CAsyncEventSink* sink, CAsyncEvent::Buffer* buffer)
{
	PostQueuedCompletionStatus(m_Iocp->GetHandle(), 0, (ULONG_PTR)sink, (LPOVERLAPPED)(buffer));
}

void CAsyncDispatcher::Dequeue(CAsyncEventSink** sink, CAsyncEvent::Buffer** buffer)
{
	DWORD ioByte = 0;

	GetQueuedCompletionStatus(m_Iocp->GetHandle(), &ioByte, (PULONG_PTR)&*sink, reinterpret_cast<LPOVERLAPPED*>(&*buffer), INFINITE);
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

		CAsyncDispatcher::GetInstance()->Dequeue(&sink, &buffer);

		buffer->m_Owner->Execute(sink);
	}
}
