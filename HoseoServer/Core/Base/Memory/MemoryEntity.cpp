#include "pch.h"
#include "MemoryEntity.h"
#include "AllocComponent.h"

CMemoryEntity::CMemoryEntity()
{
	// �⺻ Component  ����
	InsertComponent<CAllocComponent>();
}

CMemoryEntity::~CMemoryEntity()
{

}
