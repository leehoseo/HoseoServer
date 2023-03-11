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

		if ( 0 < ioByte)
		{
			int byte = 0;

			// �� ������ �ƴϴ� �պ�����
			int handled = 0;
			// ó�� ������ ����Ʈ ��
			int total = 0; //m_RecvEvent->TotalBytes + ioByte;


			while (handled < total)
			{
				int result = buffer->m_Owner->Execute(sink);
				//int result = m_Marshaller->Unmarshall(this, m_RecvEvent->Buffer + handled, total - handled);
				if (result <= 0)
				{
					break; // �� �̻� ���� �� �ִ� ���� ���ų�, ������ �߻�
				}
				else if (result > 0)
				{
					handled += result; // ���� ó��
				}
			}

			// ���� ���� �ִٸ� �������� �Ű��ش�.
			//if (mySocket->GetErrorCount() == 0 && 0 < handled && handled < total)
			//{
			//	memmove(m_RecvEvent->Buffer, m_RecvEvent->Buffer + handled, total - handled);
			//}

			if (nullptr != buffer)
			{
				byte = buffer->m_Owner->Execute(sink);
			}

			if (byte != ioByte)
			{
				// ���� �ֳ�..?
			}
		}
		else
		{
			CPeerFacade::Disconnected(dynamic_cast<CAsyncTcpEventSink*>(sink));
		}
	}
}
