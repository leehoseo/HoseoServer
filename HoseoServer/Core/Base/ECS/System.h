#pragma once
#include "Base/Pattern/Singleton.h"
/// <summary>
/// ECS�� System �ֻ��� Ŭ����
/// </summary>

class CSystem : public CSingleton<CSystem>
{
public:
	CSystem() {};
	virtual ~CSystem() {};
};

