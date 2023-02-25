#include "Packet.h"
#include <string>
#include <Windows.h>

void CPacket::GetSize(const char* buffer, PacketSize_t& outValue)
{
	memcpy(&outValue, buffer, sizeof(PacketSize_t));
}

void CPacket::SetSize(char* outBuffer, const PacketSize_t& value)
{
	memcpy(outBuffer, &value, sizeof(PacketSize_t));
}

void CPacket::GetId(const char* buffer, PacketId_t& outValue)
{
	memcpy(&outValue, buffer + 2, sizeof(PacketId_t));
}

void CPacket::SetId(char* outBuffer, const PacketId_t& value)
{
	memcpy(outBuffer + 2, &value, sizeof(PacketId_t));
}

void CPacket::GetCompressType(const char* buffer, CompressType_t& outValue)
{
	memcpy(&outValue, buffer + 4, sizeof(CompressType_t));
}

void CPacket::SetCompressType(char* outBuffer, const CompressType_t& value)
{
	memcpy(outBuffer + 4, &value, sizeof(CompressType_t));
}

void CPacket::GetEncryptionType(const char* buffer, EncryptionType_t& outValue)
{
	memcpy(&outValue, buffer + 5, sizeof(EncryptionType_t));
}

void CPacket::SetEncryptionType(char* outBuffer, const EncryptionType_t& value)
{
	memcpy(outBuffer + 5, &value, sizeof(EncryptionType_t));
}

void CPacket::GetBody(const char* buffer, char* outBody)
{
	PacketSize_t size = 0;
	CPacket::GetSize(buffer, size);

	PacketSize_t bodySize = size - sizeof(PacketHeader);
	outBody = new char[bodySize];

	memcpy(&outBody, buffer + 6, bodySize);
}

void CPacket::SetBody(char* outBuffer, const char* body, const int len)
{
	memcpy(outBuffer + 6, &body, len);
}

int CPacket::FindPacket(int value)
{
	return 0;
}
