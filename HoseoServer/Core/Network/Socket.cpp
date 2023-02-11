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
	// 소켓 통신에 사용할 함수 포인터 모음
	LPFN_ACCEPTEX lpfnAcceptEx = nullptr;
	LPFN_CONNECTEX lpfnConnectEx = nullptr;
	LPFN_DISCONNECTEX lpfnDisconnectEx = nullptr;
	LPFN_WSARECVMSG lpfnWsaRecvMsg = nullptr;
	LPFN_WSASENDMSG lpfnWsaSendMsg = nullptr;
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

			if (false == LinkSocketFunc(WSAID_WSARECVMSG, &lpfnWsaRecvMsg, funcSocket->GetHandle()))
			{
				result = GetLastError();
				break;
			}

			if (false == LinkSocketFunc(WSAID_WSASENDMSG, &lpfnWsaSendMsg, funcSocket->GetHandle()))
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

		return result != NO_ERROR;
	}
}


CSocket::CSocket()
{
	m_Handle = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);	// windows

	{
		// https://snowfleur.tistory.com/193?category=756631
		// Page Locking 최소화를 위해 송 수신 버퍼를 0으로 설정함
		// 커널 레벨에서의 송수신버퍼를 이용하지 않고 애플리케이션에서 제공하는 버퍼로 바로 복사를 해버리기 때문에 
		// 복사 횟수가 한 번 줄어 속도가 굉장히 빨라진다.

		// 각각 함수로 빼야한다.
		const int zero = 0;
		::setsockopt(m_Handle, SOL_SOCKET, SO_SNDBUF, (char*)&zero, sizeof(zero));
		::setsockopt(m_Handle, SOL_SOCKET, SO_RCVBUF, (char*)&zero, sizeof(zero));

		// AcceptEx()를 사용할 경우, listen() 에서 자동적으로 accept를 받지 못하도록 한다.
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

bool CSocket::Bind(const int port)
{
	sockaddr_in socketAddr;
	memset(&socketAddr, 0, sizeof(socketAddr));
	socketAddr.sin_family = AF_INET;
	socketAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	socketAddr.sin_port = htons(port);

	if (SOCKET_ERROR == ::bind(GetHandle(), reinterpret_cast<sockaddr*>(&socketAddr), sizeof(socketAddr)))
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

bool CSocket::Connect()
{
	return true;
}

bool CSocket::Recv(CAsyncTcpEvent* recvEvent)
{
	/*WSABUF ioBuf;
	ioBuf.buf = recvEvent->GetBuffer();
	ioBuf.len = 


	int error = WSARecv(GetHandle(), &overlappedBuffer->_wsaBuffer, 1, NULL, &flag, &overlappedBuffer->_overlapped, 0);

	if (SOCKET_ERROR == error)
	{
		if (WSA_IO_PENDING != GetLastError())
		{
			Logger::getInstance()->log(Logger::Level::WARNING, "Error");
		}
	}*/
	return true;
}

bool CSocket::Send(CAsyncTcpEvent* sendEvent)
{
	return true;
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
