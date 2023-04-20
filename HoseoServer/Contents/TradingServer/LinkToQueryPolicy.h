#pragma once
#include "Server/LinkPolicy.h"

class CAsyncEvent;

class CLinkToQueryPolicy : public CLinkPolicy
{
public:
	CLinkToQueryPolicy();
	virtual ~CLinkToQueryPolicy();
	
public:
	virtual void Setup();
	virtual bool Send(CAsyncEvent* sendEvent);
};

