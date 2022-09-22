#include "pch.h"
#include "MemoryEntity.h"
#include "AllocComponent.h"

CMemoryEntity::CMemoryEntity()
{
	// 기본 Component  설정
	m_ComponentList.insert(std::make_pair(CAllocComponent::GetInstance()->GetHash() , CAllocComponent::GetInstance()));
}

CMemoryEntity::~CMemoryEntity()
{
}
