#pragma once
#include "Handler.h"

class CPeer;
class CPacketHandler : public CHandler
{
public:
	CPacketHandler();
	virtual ~CPacketHandler();

public:
	virtual int Execute( CPeer* peer, char* buffer) override;
};



#define PACKET_HANDLER_CLASS(name)\
class name##Handler : public CPacketHandler\
{\
public:\
	name##Handler() {} \
	virtual ~name##Handler() {} \
	static std::string	GetName() { return #name; }\
	static int			GetHash() { return std::hash<std::string>()(#name); } \
	static CPacketHandler* GetClone() \
	{ \
		return new name##Handler(); \
	}\
public:\
	virtual int Execute( CPeer* peer, char* buffer) final;\
};