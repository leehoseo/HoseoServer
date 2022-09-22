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
	string	GetName() const { return ""; }
	int		GetHash() const { return 0; }
};

#define MAKE_COMPONENT_FOUNDATION(name)\
public:\
	C##name##Component() {} \
	virtual ~C##name##Component() {} \
	string GetName() const { return #name; }\
	int	  GetHash() const { return hash<string>()(#name); } \
	static CComponent* GetInstance() \
	{ \
		static CComponent* instance = nullptr; \
		if (nullptr == instance) \
		{ \
			instance = new C##name##Component(); \
		} \
		return instance; \
	}