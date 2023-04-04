#pragma once

#include "Generated/Trade_generated.h"

class TradePacket : public Person
{
public:
	uint8_t* Pack(int age,  const std::string& name);
	void UnPack(uint8_t* buffer);
};

