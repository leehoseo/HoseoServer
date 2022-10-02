#include "MemoryUtil.h"
#include "MemorySystem.h"

namespace MemoryUtil
{
	template<typename T, typename... Types>
	T* Alloc(Types&&... args)
	{
		return CMemorySystem::GetInstance()->Alloc<T>(std::forward<Types>(args)...);
	}
}
