#include "pch.h"
#include "Dispatcher.h"
#include "Memory/MemoryUtil.hpp"

CDispatcher::CDispatcher()
{
	m_Iocp = New(CIocp);
}

CDispatcher::~CDispatcher()
{
}

void CDispatcher::Start()
{
	m_Iocp->Start();
}

void CDispatcher::Run()
{
}

void CDispatcher::Enqueue()
{
}

void CDispatcher::Dequeue()
{
}
