#include "pch.h"
#include "Entity.h"

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
