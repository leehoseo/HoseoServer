#pragma once

#define _WINSOCKAPI_
#include <windows.h>
#include <WinSock2.h>

class CSocket
{
public:
	CSocket();
	~CSocket();

public:
	SOCKET& GetSocket();

private:

	SOCKET m_Socket; // 소켓 핸들
};

