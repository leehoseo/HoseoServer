#include "pch.h"
#include "PacketRegistry.h"
#include "PacketHandler.h"

CPacketRegistry::CPacketRegistry()
{
}

CPacketRegistry::~CPacketRegistry()
{
}

void CPacketRegistry::Insert(CPacketHandler* handler)
{
	m_List.insert(std::make_pair(handler->GetId(), handler));
}

CPacketHandler* CPacketRegistry::Find(int id)
{
	auto findItor = m_List.find(id);
	if (m_List.end() == findItor)
	{
		return nullptr;
	}

	return findItor->second;
}
