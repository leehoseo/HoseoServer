#pragma once
#include "Pattern/Singleton.h"
/// <summary>
/// ECS의 System 최상위 클래스
/// </summary>

template< typename T>
class CSystem : public CSingleton<T>
{
public:
	CSystem();
	virtual ~CSystem();
};

