// Copyright 2015-2020 Piperift - All rights reserved
#pragma once

#include "Reflection/ReflectionTypeTraits.h"
#include "Strings/Name.h"
#include "Strings/String.h"

#include <map>
#include <nlohmann/json.hpp>
#include <vector>


namespace Rift
{
	using Json =
		nlohmann::basic_json<std::map, std::vector, String, bool, i64, u64, double, std::allocator>;

	DECLARE_REFLECTION_TYPE(Json);
}	 // namespace Rift