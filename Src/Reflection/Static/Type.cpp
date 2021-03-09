// Copyright 2015-2021 Piperift - All rights reserved

#include "Reflection/Static/Type.h"

#include "Reflection/Static/Property.h"


namespace Rift::Refl
{
	void DataType::__GetAllChildren(TArray<DataType*>& outChildren)
	{
		// Yes, we loop two times children, but
		// also do one single allocation in each recursion
		outChildren.Append(children);
		for (auto* const child : children)
		{
			child->__GetAllChildren(outChildren);
		}
	}

	DataType* DataType::__FindChild(const Name& className) const
	{
		if (className.IsNone())
			return nullptr;

		for (auto* const child : children)
		{
			if (child->GetName() == className)
			{
				return child;
			}
			else if (DataType* found = child->__FindChild(className))
			{
				return found;
			}
		}
		return nullptr;
	}

	bool DataType::IsChildOf(const DataType* other) const
	{
		if (!other || !parent)
			return false;

		const DataType* current = parent;
		while (current)
		{
			if (other == current)
				return true;

			current = current->parent;
		}
		return false;
	}

	const Property* DataType::FindProperty(const Name& propertyName) const
	{
		const auto* prop = properties.Find(propertyName);
		return prop ? *prop : nullptr;
	}

	void DataType::GetOwnProperties(PropertyMap& outProperties) const
	{
		outProperties.Resize(outProperties.Size() + properties.Size());
		for (const auto& prop : properties)
		{
			outProperties.Insert(prop.first, prop.second);
		}
	}

	void DataType::GetAllProperties(PropertyMap& outProperties) const
	{
		if (parent)
		{
			parent->GetAllProperties(outProperties);
		}
		GetOwnProperties(outProperties);
	}
}    // namespace Rift::Refl
