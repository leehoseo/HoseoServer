#pragma once
#include "Component.h"
#include <unordered_map>

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

private:
	std::unordered_map<int, CComponent*> m_ComponentList;

public:
	template< typename T>
	T* GetComponent()
	{
		const int hash = T::GetHash();
		auto findItor = m_ComponentList.find(hash);

		if (m_ComponentList.end() == findItor)
		{
			return nullptr;
		}

		return static_cast<T*>(findItor->second);
	}

protected:
	template< typename T>
	void InsertComponent()
	{
		m_ComponentList.insert(std::make_pair(T::GetHash(), T::GetClone()));
	}
};