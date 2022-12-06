#include "pch.h"
#include "Socket.h"

CSocket::CSocket()
{
	m_Socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);	// windows

	{
		// https://snowfleur.tistory.com/193?category=756631
		// Page Locking �ּ�ȭ�� ���� �� ���� ���۸� 0���� ������
		// Ŀ�� ���������� �ۼ��Ź��۸� �̿����� �ʰ� ���ø����̼ǿ��� �����ϴ� ���۷� �ٷ� ���縦 �ع����� ������ 
		// ���� Ƚ���� �� �� �پ� �ӵ��� ������ ��������.
		const int zero = 0;
		::setsockopt(m_Socket, SOL_SOCKET, SO_SNDBUF, (char*)&zero, sizeof(zero));
		::setsockopt(m_Socket, SOL_SOCKET, SO_RCVBUF, (char*)&zero, sizeof(zero));
	}
}

CSocket::~CSocket()
{
	::closesocket(m_Socket);
}

SOCKET& CSocket::GetSocket()
{
	return m_Socket;
}
