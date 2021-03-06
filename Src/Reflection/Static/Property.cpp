// Copyright 2015-2021 Piperift - All rights reserved

#include "Reflection/Static/Property.h"

#include "Reflection/Runtime/PropertyHandle.h"
#include "Reflection/Static/Class.h"
#include "Reflection/Static/Struct.h"


namespace Rift::Refl
{
	void Property::SetDisplayName(const String& inDisplayName)
	{
		displayName = inDisplayName;

		// Remove bX preffix
		if (displayName.size() > 1 && CString::StartsWith(displayName, "b") &&
		    isupper(displayName[1]))
		{
			CString::RemoveFromStart(displayName, 1);
			displayName[0] = std::tolower(displayName[0]);
		}
	}

	const Type* Property::GetInstanceType(const Ptr<BaseObject>& instance)
	{
		return instance->GetType();
	}
	const Type* Property::GetInstanceType(BaseObject* instance)
	{
		return instance->GetType();
	}
}    // namespace Rift::Refl
