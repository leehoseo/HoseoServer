#pragma once
#include "pch.h"
/// <summary>
/// \brief Entity의 최상위 클래스 
/// ECS 페턴에서 E를 담당한다.
/// Component 집합과 Component를 호출할 함수와,, Component가 사용할 멤버 변수를 갖고 있다.
/// </summary>
class CEntity
{
// 생성자, 소멸자
public:
	CEntity();
	virtual ~CEntity();

protected:
};

