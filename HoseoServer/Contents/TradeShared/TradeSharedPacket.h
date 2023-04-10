#pragma once

#include "Generated/Trade_generated.h"

//template<typename T, typename... Args>
//uint8_t* MakePacketBuffer(Args&&... args)
//{
//    CPacketWriter<T> writer;
//    T* newPacket = new T(std::forward<Args>(args)...);
//
//    writer.SetBody(newPacket->Pack());
//
//    return writer.GetBuffer();
//}

struct CTradePacket : public CPacketBase
{
PACKET_FOUNDATION(CTradePacket)

public:
	virtual uint8_t* Pack() final;
	virtual void UnPack(uint8_t* buffer) final;

public:
	int m_Age;
	std::string m_Name;
};

