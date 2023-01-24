#include "pch.h"
#include "Component.h"
#include "Entity.h"

CComponent::CComponent(CEntity* owner)
	: m_Owner(owner)
{
}

CComponent::~CComponent()
{
}
