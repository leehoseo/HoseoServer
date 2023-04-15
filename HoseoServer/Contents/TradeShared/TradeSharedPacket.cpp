#include "TradeSharedPacket.h"
#include "Generated/Trade_generated.h"

uint8_t* CTradePacket::Pack()
{
    flatbuffers::FlatBufferBuilder builder;
    builder.Finish(CreateTradeDirect(builder, m_Name.c_str(), m_Age));
 
    return builder.GetBufferPointer();
}

void CTradePacket::UnPack(uint8_t* buffer)
{
    auto person = GetTrade(buffer);
    m_Age = person->age();
    m_Name = person->name()->c_str();
}
