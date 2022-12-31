#pragma once

#include <functional>

class CTask
{
public:
	typedef std::function<void()> Callback;

public:
	CTask( const Callback& callback);
	virtual ~CTask();

public:
	virtual void Execute();


	void OnCallbackEvent();

private:
	Callback m_Callback;
};

