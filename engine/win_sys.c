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

#include "winquake.h"
#include "quakedef.h"

// Stub functions which are necessary for loading engine inside hl.exe - ScriptedSnark
// Of course, these funcs will be in their files in the future and will have correct types and arguments.

int EXPORT LoadGame() {
    return 1;
}

int EXPORT SaveGame() {
    return 1;
}

int EXPORT GameSetState() {
    return 1;
}

int EXPORT GameSetBackground() {
    return 1;
}

int EXPORT GameSetSubState() {
    return 1;
}

int EXPORT Host_Frame() {
    return 1;
}

int EXPORT Host_Shutdown() {
    return 1;
}

int EXPORT Key_Event() {
    return 1;
}

int EXPORT Key_ClearStates() {
    return 1;
}

int EXPORT Sys_FloatTime() {
    return 1;
}

int EXPORT IN_ClearStates() {
    return 1;
}

int EXPORT IN_MouseEvent() {
    return 1;
}

int EXPORT IN_HideMouse() {
    return 1;
}

int EXPORT IN_ActivateMouse() {
    return 1;
}

int EXPORT IN_ShowMouse() {
    return 1;
}

int EXPORT IN_DeactivateMouse() {
    return 1;
}

int EXPORT IN_UpdateClipCursor() {
    return 1;
}

int EXPORT IN_RestoreOriginalMouseState() {
    return 1;
}

int EXPORT IN_SetQuakeMouseState() {
    return 1;
}

int EXPORT Snd_AcquireBuffer() {
    return 1;
}

int EXPORT Snd_ReleaseBuffer() {
    return 1;
}

int EXPORT S_UnblockSound() {
    return 1;
}

int EXPORT S_BlockSound() {
    return 1;
}

int EXPORT S_ClearBuffer() {
    return 1;
}

int EXPORT SNDDMA_Shutdown() {
    return 1;
}

int EXPORT S_GetWAVPointer() {
    return 1;
}

int EXPORT S_GetDSPointer() {
    return 1;
}

int EXPORT DeinitConProc() {
    return 1;
}

int EXPORT ClientDLL_HudVidInit() {
    return 1;
}

int EXPORT Con_Printf() {
    return 1;
}

int EXPORT Con_SafePrintf() {
    return 1;
}

int EXPORT D_InitCaches() {
    return 1;
}

int EXPORT VID_AllocBuffers() {
    return 1;
}

int EXPORT VID_UpdateVID() {
    return 1;
}

int EXPORT VID_UpdateWindowVars() {
    return 1;
}

int EXPORT Cvar_Set() {
    return 1;
}

int EXPORT Cvar_SetValue() {
    return 1;
}

int EXPORT Cvar_VariableValue() {
    return 1;
}

int EXPORT Cvar_VariableInt() {
    return 1;
}

int EXPORT Cvar_VariableString() {
    return 1;
}

int EXPORT Cvar_CompleteVariable() {
    return 1;
}

int EXPORT COM_CheckParmEx() {
    return 1;
}

int EXPORT GetEngineState() {
    return 1;
}

int EXPORT Cbuf_AddText() {
    return 1;
}

int EXPORT Cbuf_InsertText() {
    return 1;
}

int EXPORT Cmd_AddCommand() {
    return 1;
}

int EXPORT Cmd_Argc() {
    return 1;
}

int EXPORT Cmd_Argv() {
    return 1;
}

int EXPORT Cmd_Args() {
    return 1;
}

int EXPORT qwglSwapBuffers() {
    return 1;
}

int EXPORT GL_Init() {
    return 1;
}

int EXPORT GL_SetMode() {
    return 1;
}

int EXPORT GL_Shutdown() {
    return 1;
}

int EXPORT GetGameInfo() {
    return 1;
}

int EXPORT QGL_D3DShared() {
    return 1;
}

int EXPORT ForceReloadProfile() {
    return 1;
}

int EXPORT SetStartupMode() {
    return 1;
}

int EXPORT SetPauseState() {
    return 1;
}

int EXPORT GetPauseState() {
    return 1;
}

int EXPORT Keyboard_ReturnToGame() {
    return 1;
}

int EXPORT SetMessagePumpDisableMode() {
    return 1;
}

int EXPORT StoreProfile() {
    return 1;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    /*
    if (fdwReason == 1)
    {
        dword_105790FC = (int)hinstDLL;
        return 1;
    }
    else
    {
        if (!fdwReason)
        {
            dword_10579104 = (int)nullsub_7;
            dword_10579108 = (int)nullsub_7;
            dword_10578EF0 = (int)nullsub_7;
            sub_1006F4D0();
        }
        return 1;
    }
    */

    // for debugging and getting info - ScriptedSnark
    AllocConsole();
    FILE* in, *out;
    freopen_s(&in, "conin$", "r", stdin);
    freopen_s(&out, "conout$", "w+", stdout);

    return TRUE;
}

// WARNING! Hypothetical variable names and types! - ScriptedSnark
void EXPORT GameInit(
    const char* cmdLine,
    HGLOBAL hmem,
    int memSize,
    int* hasMMXTechnology,
    HWND hwnd,
    const char* playerName,
    int unknown)
{
    printf("Game_Init\n================\ncmdLine: %s\nmemSize: %i\nplayerName: %s\n================\n", cmdLine, memSize, playerName);
}