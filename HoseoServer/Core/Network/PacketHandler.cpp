#include "PacketHandler.h"
#include "Peer.h"

CPacketHandler::CPacketHandler()
{
}

CPacketHandler::~CPacketHandler()
{
}

void CPacketHandler::Execute(CPeer* peer)
{
	// �������� ���������� �� ����ó��

	OnExecute(peer);
}
