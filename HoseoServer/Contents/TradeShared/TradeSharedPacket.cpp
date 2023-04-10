#include "TradeSharedPacket.h"

uint8_t* CTradePacket::Pack()
{
    m_Builder.Finish(CreateTradeDirect(m_Builder, m_Name.c_str(), m_Age));
 
    return m_Builder.GetBufferPointer();
}

void CTradePacket::UnPack(uint8_t* buffer)
{
    auto person = GetTrade(buffer);
    m_Age = person->age();
    m_Name = person->name()->c_str();
}
