/*
Copyright (C) 1996-1997 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/
// quakedef.h -- primary header for client

#include <math.h>
#include <stdio.h>

#define MAX_NUM_ARGVS 50

#if defined(_M_IX86)
#define __i386__ 1
#endif

#if defined __i386__
#define id386 1
#else
#define id386 0
#endif

// up / down
#define PITCH 0

// left / right
#define YAW 1

// fall over
#define ROLL 2

#include "mathlib.h"
#include "const.h"
#include "cvardef.h"
#include "common.h"

/**
 *	the host system specifies the base of the directory tree, the
 *	command line parms passed to the program, and the amount of memory
 *	available for the program to use
 */
struct quakeparms_t
{
	const char* basedir;
	const char* cachedir; // for development over ISDN lines
	int argc;
	const char** argv;
	void* membase;
	int memsize;
};

/**
 *	true if into command execution
 */

/**
 *	not bounded in any way, changed at
 *	start of every frame, never reset
 */

void Host_Error(const char* error, ...);

/**
 *	Loads the server dll if needed.
 */
void Host_InitializeGameDLL();

void Host_ClearSaveDirectory();

// PERFORMANCE INFO
#define MIN_FPS 0.5	  // Host minimum fps value for maxfps.
#define MAX_FPS 100.0 // Upper limit for maxfps.

#define MAX_FRAMETIME 0.25
#define MIN_FRAMETIME 0.001