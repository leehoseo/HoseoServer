#pragma once
#include "ECS/System.h"
#include "Iocp.h"

class CDispatcher : public CSystem<CDispatcher>
{
public:
	CDispatcher();
	virtual ~CDispatcher();

public:
	void Start();
	void Run();

	void Enqueue();
	void Dequeue();

private:
	CIocp* m_Iocp;
};

