#include "pch.h"
#include "Component.h"
#include "Memory/MemoryUtil.h"

CComponent::CComponent(CEntity* owner)
	: m_Owner(owner)
{
}

CComponent::~CComponent()
{
}
