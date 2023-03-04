#pragma once
#include "Network/PeerListener.h"

class CClientListener : public CPeerListener
{
public:
	CClientListener();
	~CClientListener();

public:
	virtual void Start() override;
};

