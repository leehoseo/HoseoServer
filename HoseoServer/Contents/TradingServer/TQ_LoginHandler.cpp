#include "TQ_LoginHandler.h"
#include "Query/QuerySystem.h"

int TQ_LoginHandler::Execute(CPeer* peer, uint8_t* buffer)
{
	CPacketReader<TQ_Login> reader(buffer);

	std::string m_Name = reader->m_Name;
	std::string m_Pwd = reader->m_Pwd;

	g_QuerySystem::GetInstance()->SendQuery();
	return 0;
}