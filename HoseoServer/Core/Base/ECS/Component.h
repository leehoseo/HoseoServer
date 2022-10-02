#pragma once

#include "Entity.h"

/// <summary>
/// ECS�� Component �ֻ��� Ŭ����
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