#pragma once

#define _WINSOCKAPI_
#include <windows.h>
#include <WinSock2.h>
#include <winsock.h>
#include <MSWSock.h>

// 匙飘况农 技泼 包访
namespace Network
{
	bool Setup();
}

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
	bool Bind(sockaddr_in& addr);
	bool Connect(sockaddr_in& addr);
	bool Disconnect();
	bool Recv(CAsyncTcpEvent* recvEvent);
	bool Send(CAsyncTcpEvent* sendEvent);

	bool OnAccepted(CAsyncTcpEvent* acceptEvent);

private:
	SOCKET m_Handle; // 家南 勤甸
	sockaddr m_Addr;
};