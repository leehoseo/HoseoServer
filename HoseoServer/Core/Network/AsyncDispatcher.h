#pragma once
#include <vector>

#include "Base/ECS/System.h"
#include "Base/Thread.h"

#include "AsyncEvent.h"
#include "Iocp.h"

class CPeer;
class CSocket;
class CAsyncTcpEventSink;
class CAsyncEventSink;

class CAsyncDispatcher : public CSystem<CAsyncDispatcher>
{
public:
	CAsyncDispatcher();
	virtual ~CAsyncDispatcher();

public:
	void Start();
	void Join();
	bool Associate(CAsyncTcpEventSink* sink, CSocket* socket);
	void Enqueue(CAsyncEventSink* sink, CAsyncEvent::Body* buffer);
	void Dequeue(ULONG_PTR* sink, LPOVERLAPPED* buffer, DWORD& ioByte);

private:
	class CIocpThread : public CThread
	{
	public:
		CIocpThread();
		~CIocpThread();

	public:
		virtual void Run();
		virtual const wchar_t* GetName() { return L"Iocp Thread"; }
	};

private:
	CIocp* m_Iocp;
	std::vector<CIocpThread*> m_ThreadList;
};

