#pragma once

class CPeer;
class CPacketHandler
{
public:
	CPacketHandler();
	virtual ~CPacketHandler();

public:
	const int& GetId() { return 0; };

public:
	// ��Ŷ�� ��ȿ�� �˻� ( ������������ )
	void Execute( CPeer* peer );

	// ��Ŷ�� ���� �ڵ鷯 ���� - ���߿� �Ű������� ���еɰ���
	virtual void OnExecute(CPeer* peer) {};
};

