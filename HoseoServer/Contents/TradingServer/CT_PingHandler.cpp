#include "CT_PingHandler.h"

int CT_PingHandler::Execute(CPeer* peer, uint8_t* buffer, int len)
{
	CPacketReader<CT_Ping> reader(buffer);
	

	return 0;
}