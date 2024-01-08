﻿#include "AsyncEvent.h"
#include "AsyncEventSink.h"

CAsyncEvent::CAsyncEvent()
{
	ZeroMemory(&m_Body, sizeof(m_Body));
	m_Body.m_Owner = this;
}

CAsyncEvent::~CAsyncEvent()
{
}

CAsyncEvent::Tag& CAsyncEvent::GetTag()
{
	return m_Body;
}

int CAsyncEvent::Execute(CAsyncEventSink* sink)
{
	// 뭐 없당
	return 0;
}
