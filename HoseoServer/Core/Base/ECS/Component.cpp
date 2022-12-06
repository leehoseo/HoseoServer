#include "pch.h"
#include "Component.h"

CComponent::CComponent(CEntity* owner)
	: m_Owner(owner)
{
}

CComponent::~CComponent()
{
}
