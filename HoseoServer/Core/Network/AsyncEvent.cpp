#include "pch.h"
#include "AsyncEvent.h"
#include "AsyncEventSink.h"

CAsyncEvent::CAsyncEvent()
{
	ZeroMemory(&m_Buffer, sizeof(m_Buffer));
	m_Buffer.m_Owner = this;
}

CAsyncEvent::~CAsyncEvent()
{
}

CAsyncEvent::Buffer& CAsyncEvent::GetBuffer()
{
	return m_Buffer;
}

int CAsyncEvent::Execute(CAsyncEventSink* sink)
{
	// ¹¹ ¾ø´ç
	return 0;
}
