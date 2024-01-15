#include "CT_LoginHandler.h"
#include "TradeServerAppManager.h"

int CT_LoginHandler::Execute(CPeer* peer, uint8_t* buffer, int len)
{
	CPacketReader<CT_Login> reader(buffer);
	
	CPacketWriter<TQ_Login> writer;
	
	writer->m_Name = reader->m_Name;
	writer->m_Pwd = reader->m_Pwd;


	SendToQuery(writer());

	return 0;
}