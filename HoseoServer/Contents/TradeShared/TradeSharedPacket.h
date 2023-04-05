#pragma once

#include "Generated/Trade_generated.h"

template<typename... Args>
void testFunc(Args&&... args)
{

}

template<typename T, typename... Args>
uint8_t* MakePacketBuffer(Args&&... args)
{
    CPacketWriter<T> writer;
    T* newPacket = new T(std::forward<Args>(args)...);

    writer.SetBody(newPacket->Pack());

    testFunc<Args>(std::forward<Args>(args)...);

    return writer.GetBuffer();
}

class CTradePacket : public Person
{
public:
	CTradePacket(int age, const std::string& name);
public:
	uint8_t* Pack();
	void UnPack(uint8_t* buffer);

private:
	int m_Age;
	std::string m_Name;
};

