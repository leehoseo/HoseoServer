#pragma once

class CPeer;
class CAsyncTcpEvent;

class CSendPolicy
{
public:
	CSendPolicy();
	~CSendPolicy();

public:
	void PostSend(CPeer* peer, CAsyncTcpEvent* sendEvent);
};

