#include "MarshalerComponent.h"
#include "AsyncTcpEvent.h"
#include "PacketRegistry.h"
#include "PacketHandler.h"

void CMarshalerComponent::Init()
{
}

int CMarshalerComponent::UnMarshal(char* buffer)
{
	// 암호화 여부

	// PacketHeader로 올바른 Handler 검색

	// Handler에 PacketBody 보내주기
	return 0;
}
