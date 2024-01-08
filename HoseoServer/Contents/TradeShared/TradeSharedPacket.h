#pragma once

#include "Network/PacketBase.h"

struct CT_Login : public CPacketBase
{
PACKET_FOUNDATION(CT_Login, PacketType::NO_DELAY)

public:
	virtual uint8_t* Pack() final;
	virtual void UnPack(uint8_t* buffer) final;

public:
	std::string m_Name;
	std::string m_Pwd;
};

struct TQ_Login : public CPacketBase
{
	PACKET_FOUNDATION(TQ_Login, PacketType::NO_DELAY)

public:
	virtual uint8_t* Pack() final;
	virtual void UnPack(uint8_t* buffer) final;

public:
	std::string m_Name;
	std::string m_Pwd;
};

