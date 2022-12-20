#pragma once
#include "Base/ECS/System.h"
#include "PeerListener.h"

class CListenSystem : public CSystem<CListenSystem>
{
public:
	CListenSystem();
	virtual ~CListenSystem();

	void Init(CPeerListener* listener);
	void Start();
private:
	CPeerListener* m_Listener;
};

