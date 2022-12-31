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
	// 패킷의 유효성 검사 ( 컨텐츠적으로 )
	void Execute( CPeer* peer );

	// 패킷의 실제 핸들러 실행 - 나중에 매개변수로 구분될거임
	virtual void OnExecute(CPeer* peer) {};
};

