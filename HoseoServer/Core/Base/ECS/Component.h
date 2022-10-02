#pragma once

#include "Entity.h"
#include "Memory/MemoryUtil.h"
class CEntity;

/// <summary>
/// ECS�� Component �ֻ��� Ŭ����
/// </summary>
class CComponent
{
public:
	CComponent(CEntity* owner);
	virtual ~CComponent();

protected:
	CEntity* m_Owner;
};

#define COMPONENT_FOUNDATION(name)\
public:\
	name( CEntity* owner ) : CComponent(owner) {} \
	virtual ~name() {} \
	static std::string	GetName() { return #name; }\
	static int			GetHash() { return std::hash<std::string>()(#name); } \
	static CComponent* GetClone(CEntity* owner) \
	{ \
		return new name(owner); \
	}