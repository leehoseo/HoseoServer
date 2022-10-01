#include "pch.h"
#include "System.h"

template< typename T>
CSystem<T>::CSystem()
{
	CSystem::GetInstance();
}

template< typename T>
CSystem<T>::~CSystem()
{
}
