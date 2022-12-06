#pragma once

#include "Peer.h"
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib,"mswsock.lib")

class CIocp
{
public:
	CIocp();
	~CIocp();

public:
	void Start();
	HANDLE& GetHandle() { return m_IocpHandle; }

private:
	void Accept();

private:
	HANDLE m_IocpHandle;
};

