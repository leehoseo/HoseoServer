#pragma once
#include "Base/ECS/System.h"
#include <unordered_map>

class CPacketHandler;
class CPacketRegistry : public CSystem<CPacketRegistry>
{
public:
	CPacketRegistry();
	virtual ~CPacketRegistry();

public:
	void Insert(CPacketHandler* handler);
	CPacketHandler* Find(int id);
private:
	std::unordered_map<int, CPacketHandler*> m_List;
};

