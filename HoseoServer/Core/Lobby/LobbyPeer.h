#pragma once
#include "Network/Peer.h"

/// <summary>
/// 로비와 연결된 PC
/// </summary>
class CLobbyPeer : public CPeer
{
public:
	CLobbyPeer();
	virtual ~CLobbyPeer();

public:
	/// <summary>
	/// 소켓 통신에서 IO를 받았을때 호출
	/// </summary>
	/// <param name="tcpEvent"> 받은 이벤트 </param>
	/// <returns>성공시 처리한 바이트 수</returns>
	virtual void OnReceiveEvent(bool result, int ioByteSize, CAsyncTcpEvent* tcpEvent);
};

