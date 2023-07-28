#ifdef GS738_PATTERNS_HPP_RECURSE_GUARD
#error Recursive header files inclusion detected in gs738_patterns.hpp
#else //GS738_PATTERNS_HPP_RECURSE_GUARD

#define GS738_PATTERNS_HPP_RECURSE_GUARD

#ifndef GS738_PATTERNS_HPP_GUARD
#define GS738_PATTERNS_HPP_GUARD
#pragma once

#include "patterns.hpp"
#include "MemUtils.h"

namespace patterns
{
	namespace engine
	{
		PATTERNS(build_number,
			"WON-738",
			"83 EC 04 A1 ?? ?? ?? ?? 53 56 57 55 33 FF 3B C7");
	}
}

#endif //GS738_PATTERNS_HPP_GUARD

#undef GS738_PATTERNS_HPP_RECURSE_GUARD
#endif //GS738_PATTERNS_HPP_RECURSE_GUARD