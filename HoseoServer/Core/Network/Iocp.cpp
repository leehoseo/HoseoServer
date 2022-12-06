#include "pch.h"
#include "Iocp.h"
#include <WS2tcpip.h>
#include <thread>

CIocp::CIocp()
	: m_IocpHandle()
{
}

CIocp::~CIocp()
{
	CloseHandle(m_IocpHandle);
}

void CIocp::Start()
{
	const int processCount = std::thread::hardware_concurrency();
	m_IocpHandle = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, processCount);

	//sockaddr_in server_addr;
	//memset(&server_addr, 0, sizeof(server_addr));
	//server_addr.sin_family = AF_INET;
	//server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	//server_addr.sin_port = htons(13480);

	//bool isStart = false;
	//do
	//{
	//	if (SOCKET_ERROR == ::bind(session->getSocketHandle(), reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr)))
	//	{
	//		break;
	//	}

	//	if (SOCKET_ERROR == ::listen(session->getSocketHandle(), SOMAXCONN))
	//	{
	//		break;
	//	}

	//} while (false);

	//if (false == isStart)
	//{
	//	// 로그를 넣을거에요~
	//}
}

void CIocp::Accept()
{
	/*OverlappedBuffer* overlappedBuffer = PoolManager::getInstance()->getOverlappedBufferPool().pop();
	Session* newSession = PoolManager::getInstance()->getSessionPool().pop();
	addSession(newSession);

	overlappedBuffer->_sessionKey = newSession->getSessionKey();
	overlappedBuffer->_type = BufferType::ACCEPT;

	LPFN_ACCEPTEX acceptFunc = nullptr;

	DWORD dwbyte{ 0 };
	GUID GuidAccept = WSAID_ACCEPTEX;
	WSAIoctl(_mainSession->getSocketHandle(), SIO_GET_EXTENSION_FUNCTION_POINTER,
		&GuidAccept, sizeof(GuidAccept),
		&acceptFunc, sizeof(acceptFunc),
		&dwbyte, NULL, NULL);


	acceptFunc(_mainSession->getSocketHandle(), newSession->getSocketHandle(), &overlappedBuffer->_buffer, sizeof(TrNetworkConnectReq)
		, sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16, &dwbyte, reinterpret_cast<LPOVERLAPPED>(&overlappedBuffer->_overlapped));*/

}