#include "pch.h"
#include "ListenSystem.h"

CListenSystem::CListenSystem()
{
	// 나중에 서버 타입별로 나뉠거다
	m_Listener = New(CPeerListener);
}

CListenSystem::~CListenSystem()
{
}
