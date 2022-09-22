#pragma once
#include "Component.h"

class CComponent;

/// <summary>
/// \brief Entity�� �ֻ��� Ŭ���� 
/// ECS ���Ͽ��� E�� ����Ѵ�.
/// Component ���հ� Component�� ȣ���� �Լ���,, Component�� ����� ��� ������ ���� �ִ�.
/// </summary>
class CEntity
{
public:
	CEntity();
	virtual ~CEntity();

protected:
	unordered_map<int, CComponent*> m_ComponentList;
};