#include "Socket.h"
#include "AsyncTcpEvent.h"

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>
#include <mswsock.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

namespace Network
{
	// ���� ��ſ� ����� �Լ� ������ ����
	LPFN_ACCEPTEX lpfnAcceptEx = nullptr;
	LPFN_CONNECTEX lpfnConnectEx = nullptr;
	LPFN_DISCONNECTEX lpfnDisconnectEx = nullptr;
	LPFN_GETACCEPTEXSOCKADDRS lpfnGetAcceptExSocketAddrs = nullptr;

	bool LinkSocketFunc(GUID&& funcId, void* funcPtr, SOCKET& socket)
	{
		DWORD dwBytes;
		int result = NO_ERROR;
		result = WSAIoctl(socket, SIO_GET_EXTENSION_FUNCTION_POINTER,
							&funcId, sizeof(funcId),
							funcPtr, sizeof(funcPtr),
							&dwBytes, NULL, NULL);

		if (result == SOCKET_ERROR) {
			wprintf(L"WSAIoctl failed with error: %u\n", WSAGetLastError());
			closesocket(socket);
			WSACleanup();
			return 1;
		}
		return true;
	}

	bool Setup()
	{
		WSADATA w;
		WSAStartup(MAKEWORD(2, 2), &w);

		int result = 0;
		do
		{
			CSocket* funcSocket = new CSocket();

			if (false == LinkSocketFunc(WSAID_ACCEPTEX, &lpfnAcceptEx, funcSocket->GetHandle()))
			{
				result = GetLastError();
				break;
			}

			if (false == LinkSocketFunc(WSAID_CONNECTEX, &lpfnConnectEx, funcSocket->GetHandle()))
			{
				result = GetLastError();
				break;
			}

			if (false == LinkSocketFunc(WSAID_DISCONNECTEX, &lpfnDisconnectEx, funcSocket->GetHandle()))
			{
				result = GetLastError();
				break;
			}

			if (false == LinkSocketFunc(WSAID_GETACCEPTEXSOCKADDRS, &lpfnGetAcceptExSocketAddrs, funcSocket->GetHandle()))
			{
				result = GetLastError();
				break;
			}
			delete funcSocket;

		} while (false);

		return result == NO_ERROR;
	}
}


CSocket::CSocket()
{
	m_Handle = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);	// windows

	{
		// https://snowfleur.tistory.com/193?category=756631
		// Page Locking �ּ�ȭ�� ���� �� ���� ���۸� 0���� ������
		// Ŀ�� ���������� �ۼ��Ź��۸� �̿����� �ʰ� ���ø����̼ǿ��� �����ϴ� ���۷� �ٷ� ���縦 �ع����� ������ 
		// ���� Ƚ���� �� �� �پ� �ӵ��� ������ ��������.

		// ���� �Լ��� �����Ѵ�.
		const int zero = 0;
		::setsockopt(m_Handle, SOL_SOCKET, SO_SNDBUF, (char*)&zero, sizeof(zero));
		::setsockopt(m_Handle, SOL_SOCKET, SO_RCVBUF, (char*)&zero, sizeof(zero));

		// AcceptEx()�� ����� ���, listen() ���� �ڵ������� accept�� ���� ���ϵ��� �Ѵ�.
		BOOL on = TRUE;
		//::setsockopt(m_Handle, SOL_SOCKET, SO_CONDITIONAL_ACCEPT, (char*)&on, sizeof(on));
	}
}

CSocket::~CSocket()
{
	::closesocket(m_Handle);
}

SOCKET& CSocket::GetHandle()
{
	return m_Handle;
}

void CSocket::Close()
{
	::closesocket(m_Handle);
}

bool CSocket::Listen()
{
	if (SOCKET_ERROR == ::listen(GetHandle(), SOMAXCONN))
	{
		return false;
	}

	return true;
}

bool CSocket::Bind(sockaddr_in& addr)
{
	if (SOCKET_ERROR == ::bind(GetHandle(), reinterpret_cast<sockaddr*>(&addr), sizeof(addr)))
	{
		//Logger::getInstance()->log(Logger::Level::WARNING, "Error_Bind");
		return false;
	}
	return true;
}

bool CSocket::Accept(CSocket* newSocket, CAsyncTcpEvent* acceptEvent)
{
	DWORD outputBuffer{ 0 };
	DWORD receivedByte{ 0 };
	//const bool result = ::AcceptEx(GetHandle(), newSocket->GetHandle(), (PVOID)&outputBuffer,
	//	0, sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16, &receivedByte, (LPOVERLAPPED)(&acceptEvent->GetTag()));


	 const bool result = Network::lpfnAcceptEx(GetHandle(), newSocket->GetHandle()
											, (PVOID)acceptEvent->GetBuffer(), (sizeof(sockaddr_in) + 16) * 2, sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16
											, &receivedByte
											, (LPOVERLAPPED)(&acceptEvent->GetTag()));
	return result;
}

bool CSocket::Connect(sockaddr_in& addr, CAsyncTcpEvent* connectEvent)
{
	DWORD outputBuffer{ 0 };
	DWORD receivedByte{ 0 };
	//const bool result = ::AcceptEx(GetHandle(), newSocket->GetHandle(), (PVOID)&outputBuffer,
	//	0, sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16, &receivedByte, (LPOVERLAPPED)(&acceptEvent->GetTag()));

	WSABUF* wsaBuffer = connectEvent->GetWsaBuffer();
	wsaBuffer->buf = connectEvent->GetBuffer();
	wsaBuffer->len = sizeof(connectEvent->GetBuffer());


	const bool result = Network::lpfnConnectEx(GetHandle(), reinterpret_cast<SOCKADDR*>(&addr), sizeof(addr)
		, (PVOID)wsaBuffer, wsaBuffer->len, NULL, &connectEvent->GetTag());
	
	return result;
}

bool CSocket::Disconnect(CAsyncTcpEvent* disconnectEvent)
{
	// disconnectEvent�� �޾Ƶ� ioByte�� 0�̶� Disconnect�� �� ������. Status�� �б� ó���� ������ҵ�
	const bool result = Network::lpfnDisconnectEx(GetHandle(), NULL, 0, 0);

	return result;
}

bool CSocket::Recv(CAsyncTcpEvent* recvEvent)
{
	// �� ó�� ���
	DWORD recvBytes = {};
	DWORD flags = {};

	WSABUF* wsaBuffer = recvEvent->GetWsaBuffer();
	
	wsaBuffer->buf = recvEvent->GetBuffer() + recvEvent->GetTotalSize();
	wsaBuffer->len = sizeof(recvEvent->GetBuffer()) - recvEvent->GetTotalSize();
	
	WSARecv(GetHandle(), wsaBuffer, 1, &recvBytes, &flags, &recvEvent->GetTag(), NULL);

	return WSA_IO_PENDING != GetLastError();
}

bool CSocket::Send(CAsyncTcpEvent* sendEvent)
{
	DWORD sendBytes = {};
	DWORD flags = {};

	WSABUF* wsaBuffer = sendEvent->GetWsaBuffer();
	wsaBuffer->buf = sendEvent->GetBuffer();
	wsaBuffer->len = sizeof(sendEvent->GetBuffer());

	WSASend(GetHandle(), wsaBuffer, 1, &sendBytes, flags, &sendEvent->GetTag(), NULL);

	return WSA_IO_PENDING != GetLastError();
}

bool CSocket::OnAccepted(CAsyncTcpEvent* acceptEvent)
{
	sockaddr* localAddr = nullptr;
	sockaddr* remoteAddr = nullptr;

	int localLen = 0;
	int remoteLen = 0;
	
	Network::lpfnGetAcceptExSocketAddrs(acceptEvent->GetBuffer(), (sizeof(sockaddr_in) + 16) * 2, sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16
		, &localAddr, &localLen, &remoteAddr, &remoteLen);

	return true;
}
