#pragma once
#include "Base/ECS/System.h"
#include "PeerListener.h"

class CListenSystem : public CSystem<CListenSystem>
{
public:
	CListenSystem();
	virtual ~CListenSystem();

private:
	CPeerListener* m_Listener;
};

