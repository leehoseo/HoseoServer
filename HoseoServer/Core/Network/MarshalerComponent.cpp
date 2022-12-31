#include "pch.h"
#include "MarshalerComponent.h"
#include "AsyncTcpEvent.h"
#include "PacketRegistry.h"
#include "PacketHandler.h"

void CMarshalerComponent::Init()
{
}

void CMarshalerComponent::UnMarshal(CAsyncTcpEvent* tcpEvent)
{
	// 암호화 여부

	// PacketHeader로 올바른 Handler 검색

	// Handler에 PacketBody 보내주기
}
