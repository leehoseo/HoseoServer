#pragma once

#include "Base/ECS/Entity.h"
#include "AsyncEventSink.h"

class CSocket;
class CPeer : public CEntity
{
public:
	CPeer();
	~CPeer();

public:
	CSocket* GetHandle();
};

