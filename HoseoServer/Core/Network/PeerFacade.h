#pragma once

class CAsyncTcpEventSink;
class CPeerFacade
{
public:
	static void Disconnected(CAsyncTcpEventSink* sink);
};

