#include "pch.h"
#include "Peer.h"
#include "AsyncTcpComponent.h"

CPeer::CPeer()
{
	InsertComponent<CAsyncTcpComponent>();
}

CPeer::~CPeer()
{
}
