#pragma once

#define _WINSOCKAPI_
#include <windows.h>
#include <WinSock2.h>
#include <winsock.h>
#include <MSWSock.h>

// ��Ʈ��ũ ���� ����
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
	bool Bind(const int port);
	bool Connect();
	bool Recv(CAsyncTcpEvent* recvEvent);
	bool Send(char* buffer);

	bool OnAccepted(CAsyncTcpEvent* acceptEvent);
private:
	SOCKET m_Handle; // ���� �ڵ�
};