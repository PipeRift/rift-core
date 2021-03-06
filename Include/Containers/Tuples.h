// Copyright 2015-2021 Piperift - All rights reserved

#pragma once

#include <cassert>
#include <utility>


namespace Rift
{
	template <typename T1, typename T2>
	using Pair = std::pair<T1, T2>;

	template <typename... T>
	using Tuple = std::tuple<T...>;
}    // namespace Rift
