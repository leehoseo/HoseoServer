#include "TradeSharedPacket.h"
#include "Generated/Trade_generated.h"

uint8_t* CT_Login::Pack()
{
    flatbuffers::FlatBufferBuilder builder;
    builder.Finish(CreateFCT_LoginDirect(builder, m_Name.c_str(), m_Pwd.c_str()));
 
    return builder.GetBufferPointer();
}

void CT_Login::UnPack(uint8_t* buffer)
{
    auto packet = flatbuffers::GetRoot<CT_Login>(buffer);

    m_Name = packet->m_Name;
    m_Pwd = packet->m_Pwd;
}

uint8_t* TQ_Login::Pack()
{
    flatbuffers::FlatBufferBuilder builder;
    builder.Finish(CreateFTQ_LoginDirect(builder, m_Name.c_str(), m_Pwd.c_str()));

    return builder.GetBufferPointer();
}

void TQ_Login::UnPack(uint8_t* buffer)
{
    auto packet = flatbuffers::GetRoot<TQ_Login>(buffer);

    m_Name = packet->m_Name;
    m_Pwd = packet->m_Pwd;
}

uint8_t* CT_Ping::Pack()
{
    flatbuffers::FlatBufferBuilder builder;
    
    auto dataVector = builder.CreateVector<uint8_t>(m_Data);
    auto offset = CreateFTC_Pong(builder, dataVector);
    builder.Finish(offset);

    return builder.GetBufferPointer();
}

void CT_Ping::UnPack(uint8_t* buffer)
{
    auto packet = flatbuffers::GetRoot<CT_Ping>(buffer);

    m_Data = packet->m_Data;
}

uint8_t* TC_Pong::Pack()
{
    flatbuffers::FlatBufferBuilder builder;
    
    auto dataVector = builder.CreateVector<uint8_t>(m_Data);
    auto offset = CreateFTC_Pong(builder, dataVector);
    builder.Finish(offset);

    return builder.GetBufferPointer();
}

void TC_Pong::UnPack(uint8_t* buffer)
{
    auto packet = flatbuffers::GetRoot<TC_Pong>(buffer);

    m_Data = packet->m_Data;
}

