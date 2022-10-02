#include "pch.h"
#include "Peer.h"
#include "AsyncTcpComponent.h"
#include "TaskComponent.h"

CPeer::CPeer()
{
	InsertComponent<CAsyncTcpComponent>();
	InsertComponent<CTaskComponent>();
}

CPeer::~CPeer()
{
}
