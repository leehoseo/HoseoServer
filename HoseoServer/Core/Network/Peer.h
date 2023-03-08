#pragma once

#include "Base/Entity.h"
#include "AsyncTcpEventSink.h"

class CSocket;
class CAsyncTcpEvent;
class CPeer : public CEntity, public CAsyncTcpEventSink
{
public:
	CPeer();
	virtual ~CPeer();

public:

	/// <summary>
	/// 소켓 통신에서 IO를 받았을때 호출
	/// </summary>
	/// <param name="tcpEvent"> 받은 이벤트 </param>
	/// <returns>성공시 처리한 바이트 수</returns>
	virtual int OnReceiveEvent(CAsyncTcpEvent* tcpEvent);

public:
	CSocket* GetSocket();
	void SetSocket(CSocket* socket);

public:

	/// <summary>
	/// Accept 성공시 호출되는 함수
	/// </summary>
	/// <param name="tcpEvent"> accept시 받은 이벤트 </param>
	virtual void OnAccepted(CAsyncTcpEvent* tcpEvent);
	void Disconnect();
};

