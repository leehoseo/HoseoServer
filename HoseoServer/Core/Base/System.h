#pragma once
#include "Singleton.h"
/// <summary>
/// ECS�� System �ֻ��� Ŭ����
/// </summary>

class CSystem : public CSingleton<CSystem>
{
public:
	CSystem() {};
	virtual ~CSystem() {};
};

