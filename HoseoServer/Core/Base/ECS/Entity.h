#pragma once
#include "Component.h"

class CComponent;

/// <summary>
/// \brief Entity의 최상위 클래스 
/// ECS 페턴에서 E를 담당한다.
/// Component 집합과 Component를 호출할 함수와,, Component가 사용할 멤버 변수를 갖고 있다.
/// </summary>
class CEntity
{
public:
	CEntity();
	virtual ~CEntity();

protected:
	unordered_map<int, CComponent*> m_ComponentList;
};