#pragma once

class CPeer;
class CHandler
{
public:
	CHandler();
	virtual ~CHandler();
public:
	virtual int Execute(CPeer* peer, char* buffer);
};