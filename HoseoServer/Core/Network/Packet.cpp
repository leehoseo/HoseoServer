#include "pch.h"
#include "Packet.h"

CPacket::CPacket()
{
	m_Header.m_Size = 0;
	m_Header.m_Id = 0;
	m_Header.m_CompressType = 0;
	m_Header.m_EncryptionType = 0;
}

void CPacket::GetSize(const char* buffer, PacketSize_t& outSize)
{
}

void CPacket::SetSize(char* outBuffer, const PacketSize_t& size)
{
}

void CPacket::GetId(const char* buffer, PacketId_t& outSize)
{
}

void CPacket::SetId(char* outBuffer, const PacketId_t& size)
{
}

void CPacket::GetCompressType(const char* buffer, CompressType_t& outSize)
{
}

void CPacket::SetCompressType(char* outBuffer, const CompressType_t& size)
{
}

void CPacket::GetEncryptionType(const char* buffer, EncryptionType_t& outSize)
{
}


void CPacket::SetEncryptionType(char* outBuffer, const EncryptionType_t& size)
{
}
