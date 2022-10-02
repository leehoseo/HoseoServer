#pragma once

namespace MemoryUtil
{
	template<typename T, typename... Types>
	T* Alloc(Types&&... args);
}

#define New(name , ...) MemoryUtil::Alloc<name>(##__VA_ARGS__);