#pragma once
#include "Pattern/Singleton.h"
/// <summary>
/// ECS�� System �ֻ��� Ŭ����
/// </summary>

template< typename T>
class CSystem : public CSingleton<T>
{
public:
	CSystem();
	virtual ~CSystem();
};

