#include "pch.h"
#include "ListenSystem.h"

CListenSystem::CListenSystem()
{
	// ���߿� ���� Ÿ�Ժ��� �����Ŵ�
	m_Listener = New(CPeerListener);
}

CListenSystem::~CListenSystem()
{
}
