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
	C##name##Component() {} \
	virtual ~C##name##Component() {} \
	static string	GetName() { return #name; }\
	static int		GetHash() { return hash<string>()(#name); } \
	static CComponent* GetClone() \
	{ \
		return new C##name##Component(); \
	}