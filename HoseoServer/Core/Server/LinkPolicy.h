#pragma once

class CAsyncEvent;

/// <summary>
/// ������ ���� ��å�� ����Ѵ�.
/// Lib���� �����Ǹ� �Լ� ȣ��, �Ǵ� ServerPeer���� ������ ����Ѵ�.
/// </summary>
class CLinkPolicy
{
public:
	CLinkPolicy();
	virtual ~CLinkPolicy();

public:
	virtual void Setup() = 0;
	virtual bool Send(CAsyncEvent* sendEvent) = 0;
};