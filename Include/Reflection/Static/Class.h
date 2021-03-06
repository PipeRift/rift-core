// Copyright 2015-2021 Piperift - All rights reserved
#pragma once

#include "PCH.h"

#include "Object/BaseObject.h"
#include "Reflection/Static/Type.h"


namespace Rift
{
	template <typename T>
	struct ObjectBuilder;
}

namespace Rift::Refl
{
	class CORE_API Class : public Type
	{
	public:
		virtual OwnPtr<BaseObject, ObjectBuilder<BaseObject>> CreateInstance(
		    const Ptr<BaseObject>& owner) = 0;

		// NOTE: Most of the class comparison functions do actually
		// call Type to reduce complexity and code duplication.
		//
		// We can cast safely to Type since Classes only inherit Classes

		Class* GetParent() const
		{
			return static_cast<Class*>(parent);
		}

		void GetAllChildren(TArray<Class*>& outChildren)
		{
			__GetAllChildren(reinterpret_cast<TArray<Type*>&>(outChildren));
		}

		Class* FindChild(const Name& className) const
		{
			return static_cast<Class*>(__FindChild(className));
		}

		bool IsA(Class* other) const
		{
			return this == other;
		}
	};
}    // namespace Rift::Refl
