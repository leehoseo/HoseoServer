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
	/// ���� ��ſ��� IO�� �޾����� ȣ��
	/// </summary>
	/// <param name="tcpEvent"> ���� �̺�Ʈ </param>
	/// <returns>������ ó���� ����Ʈ ��</returns>
	virtual int OnReceiveEvent(CAsyncTcpEvent* tcpEvent);

public:
	CSocket* GetSocket();
	void SetSocket(CSocket* socket);

public:

	/// <summary>
	/// Accept ������ ȣ��Ǵ� �Լ�
	/// </summary>
	/// <param name="tcpEvent"> accept�� ���� �̺�Ʈ </param>
	virtual void OnAccepted(CAsyncTcpEvent* tcpEvent);
	void Disconnect();
};

