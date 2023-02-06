#include "Entity.h"
#include "Component.h"
#include "Memory/MemoryUtil.h"

CEntity::CEntity()
{
}

CEntity::~CEntity()
{
	for (auto component : m_ComponentList)
	{
		delete component.second;
	}
}