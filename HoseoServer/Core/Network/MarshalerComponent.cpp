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
	// ��ȣȭ ����

	// PacketHeader�� �ùٸ� Handler �˻�

	// Handler�� PacketBody �����ֱ�
}
