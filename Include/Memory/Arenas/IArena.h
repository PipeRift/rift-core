// Copyright 2015-2021 Piperift - All rights reserved
#pragma once

#include "PCH.h"


namespace Rift::Memory
{
	/** IArena defines the API used on all other arena types */
	class CORE_API IArena
	{
	protected:
		IArena() {}

	public:
		virtual ~IArena() {}
		virtual void* Allocate(sizet size)                  = 0;
		virtual void* Allocate(sizet size, sizet alignment) = 0;
		virtual void Free(void* ptr)                        = 0;
		// Reallocate allows for optimizations between free and alocate
		virtual void* Reallocate(void* oldPtr, sizet newSize, sizet alignment = 0)
		{
			Free(oldPtr);
			return Allocate(newSize, alignment);
		}


		/* Helpers */

		template <typename T>
		T* Allocate()
		{
			return static_cast<T*>(Allocate(sizeof(T), alignof(T)));
		}

		template <typename T>
		T* AllocateArray(u32 count)
		{
			return static_cast<T*>(Allocate(sizeof(T) * count, alignof(T)));
		}
	};
}    // namespace Rift::Memory
