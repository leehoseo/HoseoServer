#include <iostream>

#include "Base/Memory/MemoryUtil.hpp"

class testClass
{
private:
	int num1;
	int num2;
public:
	testClass(int t1, int t2) 
	{
		num1 = t1;
	}
	virtual ~testClass() {}
};

int main()
{
	testClass* newClass = New(testClass, 1, 2);
	return 0;
}