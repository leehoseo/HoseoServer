#include "TradeSharedPacket.h"
#include "Network/PacketWriter.h"
#include "Network/PacketReader.h"

template<typename T>
void UnPacket(T* packet, uint8_t* buffer)
{
    packet->UnPack(buffer);
}




CTradePacket::CTradePacket(int age, const std::string& name)
    : m_Age(age)
    , m_Name(name)
{
}

uint8_t* CTradePacket::Pack()
{
    m_Builder.Finish(CreatePersonDirect(m_Builder, m_Name.c_str(), m_Age));
 
    if (false == CheckVerify())
    {
        return nullptr;
    }

    return m_Builder.GetBufferPointer();
}

void CTradePacket::UnPack(uint8_t* buffer)
{
    auto person = GetPerson(buffer);
    m_Age = person->age();
    m_Name = person->name()->c_str();
}