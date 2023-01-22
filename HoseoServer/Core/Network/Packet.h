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
	static void GetSize(char* buffer, PacketSize_t& outSize);
	static void SetSize(char* outBuffer, const PacketSize_t& size);

	static void GetId(const char* buffer, PacketId_t& outSize);
	static void SetId(char* outBuffer, const PacketId_t& size);

	static void GetCompressType(const char* buffer, CompressType_t& outSize);
	static void SetCompressType(char* outBuffer, const CompressType_t& size);

	static void GetEncryptionType(const char* buffer, EncryptionType_t& outSize);
	static void SetEncryptionType(char* outBuffer, const EncryptionType_t& size);

	static void GetBody(const char* buffer, char* outBody, const int len);
	static void SetBody(char* outBuffer, const char* body, const int len);
};

