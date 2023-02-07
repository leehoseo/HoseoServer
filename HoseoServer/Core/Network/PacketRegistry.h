#pragma once
#include "Base/ECS/System.h"
#include <unordered_map>

class CPacketHandler;
class CPacketRegistry : public CSingleton<CPacketRegistry>
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

