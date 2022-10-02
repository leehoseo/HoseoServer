#pragma once

#include "Peer.h"
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib,"mswsock.lib")

class CIocp : public CPeer
{
public:
	CIocp();
	~CIocp();

public:
	void Start();

private:
	void Accept();
private:
	HANDLE m_IocpHandle;
};

