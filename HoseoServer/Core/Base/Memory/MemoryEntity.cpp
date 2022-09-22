#include "pch.h"
#include "MemoryEntity.h"
#include "AllocComponent.h"

CMemoryEntity::CMemoryEntity()
{
	// �⺻ Component  ����
	m_ComponentList.insert(std::make_pair(CAllocComponent::GetInstance()->GetHash() , CAllocComponent::GetInstance()));
}

CMemoryEntity::~CMemoryEntity()
{
}
