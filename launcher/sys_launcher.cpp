/*
*	hl.exe (build 738)
*   Kind of clean room reimplementation
*	sys_launcher.cpp: entry point
*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <mmeapi.h>
#include <dsound.h>

#include <stdio.h>

#include "engine_exports.h"

_GameInit GameInit = NULL;
_GameSetState GameSetState = NULL;
_GameSetBackground GameSetBackground = NULL;
_GameSetSubState GameSetSubState = NULL;
_Host_Frame Host_Frame = NULL;
_Host_Shutdown Host_Shutdown = NULL;
_Key_Event Key_Event = NULL;
_Key_ClearStates Key_ClearStates = NULL;
_Sys_FloatTime Sys_FloatTime = NULL;
_IN_ClearStates IN_ClearStates = NULL;
_IN_MouseEvent IN_MouseEvent = NULL;
_IN_ActivateMouse IN_ActivateMouse = NULL;
_IN_DeactivateMouse IN_DeactivateMouse = NULL;
_Snd_AcquireBuffer Snd_AcquireBuffer = NULL;
_Snd_ReleaseBuffer Snd_ReleaseBuffer = NULL;
_S_UnblockSound S_UnblockSound = NULL;
_S_BlockSound S_BlockSound = NULL;
_S_ClearBuffer S_ClearBuffer = NULL;
_SNDDMA_Shutdown SNDDMA_Shutdown = NULL;
_S_GetWAVPointer S_GetWAVPointer = NULL;
_S_GetDSPointer S_GetDSPointer = NULL;
_DeinitConProc DeinitConProc = NULL;
_Con_Printf Con_Printf = NULL;
_Con_SafePrintf Con_SafePrintf = NULL;
_VID_UpdateVID VID_UpdateVID = NULL;
_VID_UpdateWindowVars VID_UpdateWindowVars = NULL;
_Cvar_Set Cvar_Set = NULL;
_Cvar_SetValue Cvar_SetValue = NULL;
_Cvar_VariableValue Cvar_VariableValue = NULL;
_Cvar_VariableInt Cvar_VariableInt = NULL;
_Cvar_VariableString Cvar_VariableString = NULL;
_Cvar_CompleteVariable Cvar_CompleteVariable = NULL;
_Cbuf_AddText Cbuf_AddText = NULL;
_Cmd_AddCommand Cmd_AddCommand = NULL;
_Cmd_Argc Cmd_Argc = NULL;
_Cmd_Argv Cmd_Argv = NULL;
_Cmd_Args Cmd_Args = NULL;
_qwglSwapBuffers qwglSwapBuffers = NULL;
_GL_Init GL_Init = NULL;
_GL_SetMode GL_SetMode = NULL;
_GL_Shutdown GL_Shutdown = NULL;
_GetGameInfo GetGameInfo = NULL;
_QGL_D3DShared QGL_D3DShared = NULL;
_ForceReloadProfile ForceReloadProfile = NULL;
_SetStartupMode SetStartupMode = NULL;
_SetPauseState SetPauseState = NULL;
_GetPauseState GetPauseState = NULL;
_Keyboard_ReturnToGame Keyboard_ReturnToGame = NULL;
_SetMessagePumpDisableMode SetMessagePumpDisableMode = NULL;
_StoreProfile StoreProfile = NULL;

qboolean Eng_LoadFunctions()
{
    // load engine
    HMODULE engine = ::LoadLibrary("hw"); // TODO: load specific library by parsing registry (sw/hw)

    if (!engine)
    {
        printf("Eng_LoadFunctions: couldn't load engine.\n");
        return FALSE;
    }

    // import funcs
    GameInit = (_GameInit)GetProcAddress(engine, "GameInit");
    GameSetState = (_GameSetState)GetProcAddress(engine, "GameSetState");
    GameSetBackground = (_GameSetBackground)GetProcAddress(engine, "GameSetBackground");
    GameSetSubState = (_GameSetSubState)GetProcAddress(engine, "GameSetSubState");
    Host_Frame = (_Host_Frame)GetProcAddress(engine, "Host_Frame");
    Host_Shutdown = (_Host_Shutdown)GetProcAddress(engine, "Host_Shutdown");
    Key_Event = (_Key_Event)GetProcAddress(engine, "Key_Event");
    Key_ClearStates = (_Key_ClearStates)GetProcAddress(engine, "Key_ClearStates");
    Sys_FloatTime = (_Sys_FloatTime)GetProcAddress(engine, "Sys_FloatTime");
    IN_ClearStates = (_IN_ClearStates)GetProcAddress(engine, "IN_ClearStates");
    IN_MouseEvent = (_IN_MouseEvent)GetProcAddress(engine, "IN_MouseEvent");

    // IN_HideMouse doesn't have any code inside engine so it's useless, I think? - ScriptedSnark
    //IN_HideMouse = (_IN_HideMouse)GetProcAddress(engine, "IN_HideMouse");

    IN_ActivateMouse = (_IN_ActivateMouse)GetProcAddress(engine, "IN_ActivateMouse");

    // same
    //IN_ShowMouse = (_IN_ShowMouse)GetProcAddress(engine, "IN_ShowMouse");

    IN_DeactivateMouse = (_IN_DeactivateMouse)GetProcAddress(engine, "IN_DeactivateMouse");

    // same
    //IN_UpdateClipCursor = (_IN_UpdateClipCursor)GetProcAddress(engine, "IN_UpdateClipCursor");

    // doesn't exist in engine
    /*
    IN_RestoreOriginalMouseState = (_IN_RestoreOriginalMouseState)GetProcAddress(engine, "IN_RestoreOriginalMouseState");
    IN_SetQuakeMouseState = (_IN_SetQuakeMouseState)GetProcAddress(engine, "IN_SetQuakeMouseState");
    */

    Snd_AcquireBuffer = (_Snd_AcquireBuffer)GetProcAddress(engine, "Snd_AcquireBuffer");
    Snd_ReleaseBuffer = (_Snd_ReleaseBuffer)GetProcAddress(engine, "Snd_ReleaseBuffer");
    S_UnblockSound = (_S_UnblockSound)GetProcAddress(engine, "S_UnblockSound");
    S_BlockSound = (_S_BlockSound)GetProcAddress(engine, "S_BlockSound");
    S_ClearBuffer = (_S_ClearBuffer)GetProcAddress(engine, "S_ClearBuffer");
    SNDDMA_Shutdown = (_SNDDMA_Shutdown)GetProcAddress(engine, "SNDDMA_Shutdown");
    S_GetWAVPointer = (_S_GetWAVPointer)GetProcAddress(engine, "S_GetWAVPointer");
    S_GetDSPointer = (_S_GetDSPointer)GetProcAddress(engine, "S_GetDSPointer");
    DeinitConProc = (_DeinitConProc)GetProcAddress(engine, "DeinitConProc");
    //ClientDLL_HudVidInit = (_ClientDLL_HudVidInit)GetProcAddress(engine, "ClientDLL_HudVidInit");
    Con_Printf = (_Con_Printf)GetProcAddress(engine, "Con_Printf");
    Con_SafePrintf = (_Con_SafePrintf)GetProcAddress(engine, "Con_SafePrintf");
    //D_InitCaches = (_D_InitCaches)GetProcAddress(engine, "D_InitCaches");
    //VID_AllocBuffers = (_VID_AllocBuffers)GetProcAddress(engine, "VID_AllocBuffers");
    VID_UpdateVID = (_VID_UpdateVID)GetProcAddress(engine, "VID_UpdateVID");
    VID_UpdateWindowVars = (_VID_UpdateWindowVars)GetProcAddress(engine, "VID_UpdateWindowVars");
    Cvar_Set = (_Cvar_Set)GetProcAddress(engine, "Cvar_Set");
    Cvar_SetValue = (_Cvar_SetValue)GetProcAddress(engine, "Cvar_SetValue");
    Cvar_VariableValue = (_Cvar_VariableValue)GetProcAddress(engine, "Cvar_VariableValue");
    Cvar_VariableInt = (_Cvar_VariableInt)GetProcAddress(engine, "Cvar_VariableInt");
    Cvar_VariableString = (_Cvar_VariableString)GetProcAddress(engine, "Cvar_VariableString");
    Cvar_CompleteVariable = (_Cvar_CompleteVariable)GetProcAddress(engine, "Cvar_CompleteVariable");
    //COM_CheckParmEx = (_COM_CheckParmEx)GetProcAddress(engine, "COM_CheckParmEx");
    //GetEngineState = (_GetEngineState)GetProcAddress(engine, "GetEngineState");
    Cbuf_AddText = (_Cbuf_AddText)GetProcAddress(engine, "Cbuf_AddText");
    //Cbuf_InsertText = (_Cbuf_InsertText)GetProcAddress(engine, "Cbuf_InsertText");
    Cmd_AddCommand = (_Cmd_AddCommand)GetProcAddress(engine, "Cmd_AddCommand");
    Cmd_Argc = (_Cmd_Argc)GetProcAddress(engine, "Cmd_Argc");
    Cmd_Argv = (_Cmd_Argv)GetProcAddress(engine, "Cmd_Argv");
    Cmd_Args = (_Cmd_Args)GetProcAddress(engine, "Cmd_Args");
    qwglSwapBuffers = (_qwglSwapBuffers)GetProcAddress(engine, "qwglSwapBuffers");
    GL_Init = (_GL_Init)GetProcAddress(engine, "GL_Init");
    GL_SetMode = (_GL_SetMode)GetProcAddress(engine, "GL_SetMode");
    GL_Shutdown = (_GL_Shutdown)GetProcAddress(engine, "GL_Shutdown");
    GetGameInfo = (_GetGameInfo)GetProcAddress(engine, "GetGameInfo");
    QGL_D3DShared = (_QGL_D3DShared)GetProcAddress(engine, "QGL_D3DShared");
    ForceReloadProfile = (_ForceReloadProfile)GetProcAddress(engine, "ForceReloadProfile");
    SetStartupMode = (_SetStartupMode)GetProcAddress(engine, "SetStartupMode");
    SetPauseState = (_SetPauseState)GetProcAddress(engine, "SetPauseState");
    GetPauseState = (_GetPauseState)GetProcAddress(engine, "GetPauseState");
    Keyboard_ReturnToGame = (_Keyboard_ReturnToGame)GetProcAddress(engine, "Keyboard_ReturnToGame");
    SetMessagePumpDisableMode = (_SetMessagePumpDisableMode)GetProcAddress(engine, "SetMessagePumpDisableMode");
    StoreProfile = (_StoreProfile)GetProcAddress(engine, "StoreProfile");

    return TRUE;
}

int Eng_Frame()
{
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // load GoldSrc engine
    if (!Eng_LoadFunctions())
        return 1;

    // load GUI

    return 0;
}