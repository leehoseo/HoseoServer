#pragma once

#define _WINSOCKAPI_
#include <windows.h>
#include <WinSock2.h>
#include <winsock.h>
#include <MSWSock.h>

class CAsyncTcpEvent;
class CSocket
{
public:
	CSocket();
	~CSocket();

public:
	SOCKET& GetHandle();
	void Close();

	bool Listen();
	bool Accept(CSocket* newSocket, CAsyncTcpEvent* acceptEvent);
	bool Connect();

private:
	SOCKET m_Handle; // 소켓 핸들
};

