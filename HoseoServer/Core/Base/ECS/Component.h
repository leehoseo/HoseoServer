#pragma once

#include "Entity.h"

/// <summary>
/// ECS의 Component 최상위 클래스
/// </summary>
class CComponent
{
public:
	CComponent();
	virtual ~CComponent();
};

#define COMPONENT_FOUNDATION(name)\
public:\
	name() {} \
	virtual ~name() {} \
	static std::string	GetName() { return #name; }\
	static int			GetHash() { return std::hash<std::string>()(#name); } \
	static CComponent* GetClone() \
	{ \
		return new name(); \
	}