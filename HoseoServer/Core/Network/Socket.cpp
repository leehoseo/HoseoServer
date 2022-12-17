#include "pch.h"
#include "Socket.h"
#include "AsyncTcpEvent.h"

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

bool CSocket::Accept(CSocket* newSocket, CAsyncTcpEvent* acceptEvent)
{
	return ::AcceptEx(GetHandle(), newSocket->GetHandle(), 0,
		sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16, 0, 0, (LPOVERLAPPED)(&acceptEvent->GetBuffer()));
}

bool CSocket::Connect()
{
	return false;
}
