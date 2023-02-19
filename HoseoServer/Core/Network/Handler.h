#pragma once

class CPeer;
class CHandler
{
public:
	CHandler();
	virtual ~CHandler();
public:
	virtual int Execute(CPeer* peer, char* buffer, int receiveLen);
};




#define HANDLER_FOUNDATION(name)\
public:\
	name() {} \
	virtual ~name() {} \
	static std::string	GetName() { return #name; }\
	static int			GetHash() { return std::hash<std::string>()(#name); } \
	static CPacketHandler* GetClone() \
	{ \
		return new name(); \
	}\
public:\
	virtual int Execute( CPeer* peer, char* buffer, int receiveLen) final;