#pragma once

#include <thread>
#include <string>

/// <summary>
/// Thread�� �ֻ��� Ŭ����
/// </summary>
class CThread
{
	enum class EState
	{
		// Tr ó����
		WAIT = 0,
		RUN,

		Count,
	};

public:
	CThread();
	virtual ~CThread();

	void Init();
	void Start();
	virtual void Run() = 0;
	virtual const wchar_t* GetName() { return L"Default Thread"; }
private:
	std::thread m_Thread;
};

