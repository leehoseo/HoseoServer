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
	static T* Alloc(Types&&... args)
	{
		CMemorySystem::GetInstance();

		return new T(std::forward<Types>(args)...);
	}
private:
	CMemoryEntity* m_MemoryEntity;
};


#define New(name , ...) CMemorySystem::GetInstance()->Alloc<name>(##__VA_ARGS__);