#pragma once
#include "Base/ECS/Component.h"

class CAsyncTcpEvent;

class CMarshalerComponent : public CComponent
{
	COMPONENT_FOUNDATION(CMarshalerComponent);

protected:

	virtual void Init();

public:
	void UnMarshal(CAsyncTcpEvent* tcpEvent);
};

