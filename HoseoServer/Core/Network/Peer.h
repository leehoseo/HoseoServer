#pragma once

#include "Base/Entity.h"
#include "AsyncTcpEventSink.h"

class CSendPolicy;
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

	/// <summary>
	/// Accept ������ ȣ��Ǵ� �Լ�
	/// </summary>
	/// <param name="tcpEvent"> accept�� ���� �̺�Ʈ </param>
	virtual void OnAccepted(CAsyncTcpEvent* tcpEvent);
public:

	// ��Ŷ�� ������ ���� ���� �۾�
	bool PostSend(CAsyncTcpEvent* sendEvent);

	// ��Ŷ�� ������ ������.
	bool Send(CAsyncTcpEvent* sendEvent);

	CSocket* GetSocket();
	void SetSocket(CSocket* socket);

public:

	void Disconnect();

private:
	CSendPolicy* m_SendPolicy;
};

