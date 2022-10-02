#pragma once
#include <cstdarg>

#include "ECS/System.h"
#include "MemoryEntity.h"

class CMemorySystem : public CSystem<CMemorySystem>
{
public:
	CMemorySystem();
	virtual ~CMemorySystem();

public:
	template<typename T, typename... Types>
	T* Alloc(Types&&... args)
	{
		return m_MemoryEntity->Alloc<T>(std::forward<Types>(args)...);
	}

private:
	CMemoryEntity* m_MemoryEntity;
};