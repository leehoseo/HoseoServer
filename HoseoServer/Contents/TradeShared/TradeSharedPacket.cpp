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
    auto person = GetFTQ_Login(buffer);
    m_Name = person->name()->c_str();
    m_Pwd = person->pwd()->c_str();
}

uint8_t* TQ_Login::Pack()
{
    flatbuffers::FlatBufferBuilder builder;
    builder.Finish(CreateFTQ_LoginDirect(builder, m_Name.c_str(), m_Pwd.c_str()));

    return builder.GetBufferPointer();
}

void TQ_Login::UnPack(uint8_t* buffer)
{
    auto person = GetFTQ_Login(buffer);
    m_Name = person->name()->c_str();
    m_Pwd = person->pwd()->c_str();
}
