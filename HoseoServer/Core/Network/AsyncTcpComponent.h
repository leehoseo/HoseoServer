#pragma once
#include "Base/ECS/Component.h"
#include "Socket.h"

class CAsyncTcpComponent : public CComponent
{
	COMPONENT_FOUNDATION(CAsyncTcpComponent);

public:
	CSocket* GetSocket();

protected:
	virtual void Init();

private:
	CSocket* m_Socket;
};

