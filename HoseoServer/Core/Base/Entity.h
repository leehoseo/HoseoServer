#pragma once

//#include "Component.h"

#include <unordered_map>
#include <string>

class CComponent;

/// <summary>
/// Component(���� - ���)�� ����� ����� ( Peer, ...er , System �� )�� �ֻ��� Ŭ����
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