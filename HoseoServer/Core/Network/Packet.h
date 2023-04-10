#pragma once

typedef unsigned short PacketSize_t;
typedef unsigned short PacketId_t;
typedef unsigned char CompressType_t;
typedef unsigned char EncryptionType_t;

struct PacketHeader
{
	PacketSize_t m_Size;
	PacketId_t m_Id;
	CompressType_t m_CompressType;
	EncryptionType_t m_EncryptionType;
};

class CPacket
{
public:
	static void GetSize(const uint8_t* buffer, PacketSize_t& outSize);
	static void SetSize(uint8_t* outBuffer, const PacketSize_t& size);

	static void GetId(const uint8_t* buffer, PacketId_t& outSize);
	static void SetId(uint8_t* outBuffer, const PacketId_t& size);

	static void GetCompressType(const uint8_t* buffer, CompressType_t& outSize);
	static void SetCompressType(uint8_t* outBuffer, const CompressType_t& size);

	static void GetEncryptionType(const uint8_t* buffer, EncryptionType_t& outSize);
	static void SetEncryptionType(uint8_t* outBuffer, const EncryptionType_t& size);

	static void GetBody(const uint8_t* buffer, uint8_t* outBody);
	static void SetBody(uint8_t* outBuffer, const uint8_t* body, const int len);
	
	static int FindPacket(int value);
};