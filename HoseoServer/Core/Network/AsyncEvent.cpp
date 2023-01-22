#include "pch.h"
#include "AsyncEvent.h"
#include "AsyncEventSink.h"

CAsyncEvent::CAsyncEvent()
{
	ZeroMemory(&m_Body, sizeof(m_Body));
	m_Body.m_Owner = this;
}

CAsyncEvent::~CAsyncEvent()
{
}

CAsyncEvent::Body& CAsyncEvent::GetBody()
{
	return m_Body;
}

int CAsyncEvent::Execute(CAsyncEventSink* sink)
{
	// ¹¹ ¾ø´ç
	return 0;
}
