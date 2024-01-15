#pragma once
#include "Base/Thread.h"

class CWorkerThread : public CThread
{
public:
	CWorkerThread();
	~CWorkerThread();

public:
	virtual void Run();
	virtual const wchar_t* GetName() { return L"Worker Thread"; }
};

