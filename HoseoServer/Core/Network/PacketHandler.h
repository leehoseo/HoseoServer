#pragma once
#include "Handler.h"

class CPeer;
class CPacketHandler : public CHandler
{
public:
	CPacketHandler();
	virtual ~CPacketHandler();

public:
	virtual int Execute( CPeer* peer, char* buffer, int receiveLen) override;
};