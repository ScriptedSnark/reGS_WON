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
	namespace launcher
	{
		PATTERNS(Eng_Load,
			"WON-738",
			"83 EC 0C 53 56 57 55 33 FF");
	}

	namespace engine
	{
		PATTERNS(build_number,
			"WON-738",
			"83 EC 04 A1 ?? ?? ?? ?? 53 56 57 55 33 FF 3B C7");

		PATTERNS(GL_Upload32,
			"WON-738",
			"83 EC 10 C7 44 24 00 00 00 00 00");

		PATTERNS(GL_Upload16,
			"WON-738",
			"8B 44 24 ?? 83 EC 08 0F AF 44 24 ??");
	}
}

#endif //GS738_PATTERNS_HPP_GUARD

#undef GS738_PATTERNS_HPP_RECURSE_GUARD
#endif //GS738_PATTERNS_HPP_RECURSE_GUARD