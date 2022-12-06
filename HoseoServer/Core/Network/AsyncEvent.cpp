#include "pch.h"
#include "AsyncEvent.h"

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

void CAsyncEvent::Execute(CAsyncEventSink* sink)
{
	// ¹¹ ¾ø´ç
}
