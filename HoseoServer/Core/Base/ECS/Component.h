#pragma once

#include "Entity.h"

class CEntity;

/// <summary>
/// ECS의 Component 최상위 클래스
/// </summary>
class CComponent
{
public:
	CComponent(CEntity* owner);
	virtual ~CComponent();

protected:
	virtual void Init() {};

protected:
	CEntity* m_Owner;
};

#define COMPONENT_FOUNDATION(name)\
public:\
	name( CEntity* owner ) : CComponent(owner) { Init(); } \
	virtual ~name() {} \
	static std::string	GetName() { return #name; }\
	static int			GetHash() { return std::hash<std::string>()(#name); } \
	static CComponent* GetClone(CEntity* owner) \
	{ \
		return new name(owner); \
	}