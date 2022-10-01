#include <iostream>

#include "Base/Memory/MemorySystem.h"

class testClass : public CSingleton<testClass>
{
public:
	testClass() {}
	virtual ~testClass() {}
};

int main()
{
	testClass::GetInstance();
	CMemorySystem::GetInstance();
	return 0;
}