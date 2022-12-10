#pragma once
#include "Base/ECS/Component.h"

class CSocket;
class CAsyncTcpEvent;
class CAsyncTcpComponent : public CComponent
{
	COMPONENT_FOUNDATION(CAsyncTcpComponent);

public:
	CSocket* GetSocket();
	void Assosiate();
protected:
	virtual void Init();

private:
	CSocket* m_Socket;
	CAsyncTcpEvent* m_RecvEvent;
};

