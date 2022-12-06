#include "pch.h"
#include "Thread.h"
#include <Windows.h>

CThread::CThread()
{
}

CThread::~CThread()
{
	m_Thread.detach();
}

void CThread::Init()
{
	m_Thread = std::thread(&CThread::Start, this);
}

void CThread::Start()
{
	// ������ ����
	const wchar_t* threadName = GetName();
	SetThreadDescription(GetCurrentThread(), threadName);

	Run();
}