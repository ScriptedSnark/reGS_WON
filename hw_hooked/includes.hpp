#ifdef INCLUDES_HPP_RECURSE_GUARD
#error Recursive header files inclusion detected in includes.hpp
#else //INCLUDES_HPP_RECURSE_GUARD

#define INCLUDES_HPP_RECURSE_GUARD

#ifndef INCLUDES_HPP_GUARD
#define INCLUDES_HPP_GUARD
#pragma once

 //WinAPI
#include <Windows.h>
#include <psapi.h>

//STL
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <array>

//Patterns
#include "Utils.hpp"
#include "gs738_patterns.hpp"

//MinHook
#include "MinHook.h"

//HLSDK
#include "quakedef.h"
#include "console.h"

//OpenGL
#include <gl/GL.h>

//Own things
#include "conutils.hpp"

extern void* g_lpHwDLL;

#define Find(future_name)                                                                                                                  \
	{                                                                                                                                      \
		auto f##future_name = utils.FindAsync(ORIG_##future_name, patterns::engine::future_name);                                          \
		auto pattern = f##future_name.get();                                                                                               \
		if (ORIG_##future_name)                                                                                                            \
		{                                                                                                                                  \
			PrintCalm("[hw dll] Found " #future_name " at %p (using the %s pattern).\n", ORIG_##future_name, pattern->name()); \
		}                                                                                                                                  \
		else																														       \
		{																																   \
			PrintWarning("[hw dll] Could not find " #future_name "!\n");								   \
		}																																   \
	}

#define FindbySymbol(func_name) \
	if ((ORIG_##func_name = reinterpret_cast<_##func_name>(GetProcAddress(reinterpret_cast<HMODULE>(g_lpHwDLL), "" #func_name "")))) \
		PrintCalm("[hw dll] Found " #func_name " at %p.\n", ORIG_##func_name); \
	else \
		PrintWarning("[hw dll] Could not find " #func_name ".\n"); \

#define CreateHook(func_name) \
	status = MH_CreateHook(ORIG_##func_name, ##func_name, reinterpret_cast<void**>(&ORIG_##func_name)); \
	if (status != MH_OK) { \
		PrintWarning("[hw dll] Couldn't create hook for " #func_name ": %s\n", MH_StatusToString(status)); \
	}

#pragma comment(lib, "opengl32.lib")

#endif //INCLUDES_HPP_GUARD

#undef INCLUDES_HPP_RECURSE_GUARD
#endif //INCLUDES_HPP_RECURSE_GUARD