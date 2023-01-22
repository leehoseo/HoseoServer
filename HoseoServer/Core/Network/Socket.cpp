#include "pch.h"
#include "Socket.h"
#include "AsyncTcpEvent.h"


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
	const bool result = ::AcceptEx(GetHandle(), newSocket->GetHandle(), (PVOID)&outputBuffer,
		0, sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16, &receivedByte, (LPOVERLAPPED)(&acceptEvent->GetBody()));

	return result;
}

bool CSocket::Connect()
{
	return false;
}
