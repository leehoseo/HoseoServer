#pragma once

#include "Network/Peer.h"
/// <summary>
/// Peer�� ������ ����� Peer
/// </summary>
class CPeerListener : public CPeer
{
	class CPeerListenEvent;

public:
	CPeerListener();
	virtual ~CPeerListener();

public:
	void Start();
	void Accept();
};

