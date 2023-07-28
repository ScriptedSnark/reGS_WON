/***
*
*	Copyright (c) 1999, Valve LLC. All rights reserved.
*
*	This product contains software technology licensed from Id
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc.
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/

#include "quakedef.h"
#include "winquake.h"
#include "console.h"

#ifdef REGS_HOOKED
_Con_Printf ORIG_Con_Printf = NULL;
#endif

#define MAXPRINTMSG 4096
qboolean con_debuglog;

/*
================
Con_Init
================
*/
void Con_Init()
{
    con_debuglog = FALSE; //COM_CheckParm("-condebug");
}

/*
================
Con_DebugLog
================
*/
void Con_DebugLog(char* file, char* fmt, ...)
{
    va_list argptr;
    static char data[1024];

    va_start(argptr, fmt);
    vsprintf(data, fmt, argptr);
    va_end(argptr);

    FILE* fp = fopen(file, "a");
    if (fp)
    {
        fwrite(data, sizeof(char), strlen(data), fp);
        fclose(fp);
    }
}

/*
================
Con_Printf
================
*/
#ifndef REGS_HOOKED
void EXPORT Con_Printf(char* fmt, ...)
#else
void Con_Printf(char* fmt, ...)
#endif
{
    va_list	argptr;
    char msg[MAXPRINTMSG];

    va_start(argptr, fmt);
    vsprintf(msg, fmt, argptr);
    va_end(argptr);

    Sys_Printf("%s", msg);

    if (con_debuglog)
        Con_DebugLog(va("%s/qconsole.log", com_gamedir), "%s", msg);

#ifdef REGS_HOOKED
    ORIG_Con_Printf("%s", msg);
#endif
}