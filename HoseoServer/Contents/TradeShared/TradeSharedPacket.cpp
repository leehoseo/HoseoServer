#include "TradeSharedPacket.h"
#include "Network/PacketWriter.h"
#include "Network/PacketReader.h"

template<typename T>
void UnPacket(T* packet, uint8_t* buffer)
{
    CPacketReader<T> reader(packet);

    packet = GetPerson(buffer);
}

uint8_t* TradePacket::Pack(int age, const std::string& name)
{
    m_Builder.Finish(CreatePersonDirect(m_Builder , name.c_str(), age));
 
    if (false == CheckVerify())
    {
        return nullptr;
    }

    return m_Builder.GetBufferPointer();
}

//NewPack<TradePacket, int, std::string>(5, "hoseo");

void TradePacket::UnPack(uint8_t* buffer)
{
    GetPerson(buffer);
}