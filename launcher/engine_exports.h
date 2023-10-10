#ifndef __ENGINE_EXPORTS__
#define __ENGINE_EXPORTS__

// TODO: move it somewhere
typedef int qboolean;

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef void (*xcommand_t) (void);

// TODO: rename arguments - ScriptedSnark
typedef void (*_GameInit)(const char* a1, int a2, int a3, int* a4, int a5, const char* a6, int a7);
typedef int (*_GameSetState)(int a1);
typedef int (*_GameSetBackground)(int a1);
typedef int (*_GameSetSubState)(int a1);
typedef int (*_Host_Frame)(float a1, int a2, int* a3);
typedef void (*_Host_Shutdown)();
typedef int (*_Key_Event)(int a1, int a2);
typedef void (*_Key_ClearStates)();
typedef double (*_Sys_FloatTime)();
typedef void (*_IN_ClearStates)();
typedef void (*_IN_MouseEvent)(int a1);
typedef void (*_IN_ActivateMouse)();
typedef void (*_IN_DeactivateMouse)();
typedef void (*_Snd_AcquireBuffer)();
typedef void (*_Snd_ReleaseBuffer)();
typedef void (*_S_UnblockSound)();
typedef void (*_S_BlockSound)();
typedef void (*_S_ClearBuffer)();
typedef void (*_SNDDMA_Shutdown)();
typedef void* (*_S_GetWAVPointer)();
typedef void (*_S_GetDSPointer)(LPDIRECTSOUND* a1, LPDIRECTSOUNDBUFFER* a2);
typedef void (*_DeinitConProc)();
typedef void (*_Con_Printf)(char* fmt, ...);
typedef void (*_Con_SafePrintf)(char* fmt, ...);
typedef void (*_VID_UpdateVID)(const void* a1); // TODO: viddef_t
typedef void (*_VID_UpdateWindowVars)(void* prc, int x, int y); // not so sure
typedef void (*_Cvar_Set)(char* var_name, char* value);
typedef void (*_Cvar_SetValue)(char* var_name, float value);
typedef float (*_Cvar_VariableValue)(const char* var_name);
typedef int (*_Cvar_VariableInt)(const char* var_name);
typedef const char* (*_Cvar_VariableString)(const char* var_name);
typedef const char* (*_Cvar_CompleteVariable)(const char* partial);
typedef void (*_Cbuf_AddText)(char* text);
typedef void (*_Cmd_AddCommand)(char* cmd_name, xcommand_t function);
typedef int	(*_Cmd_Argc)();
typedef char* (*_Cmd_Argv)(int arg);
typedef char* (*_Cmd_Args)();
typedef BOOL(WINAPI* _qwglSwapBuffers)(HDC);
typedef void (*_GL_Init)();
typedef qboolean(*_GL_SetMode)(HWND hWnd, HDC* a2, HGLRC* a3, int a4, char* pszCmdLine);
typedef void (*_GL_Shutdown)(HWND hWnd, HDC hDC, int a3);
typedef int (*_GetGameInfo)(int* a1, char* String2);
typedef void (*_QGL_D3DShared)(int a1);
typedef void (*_ForceReloadProfile)(char* a1);
typedef void (*_SetStartupMode)(int a1);
typedef void (*_SetPauseState)(int a1);
typedef int (*_GetPauseState)();
typedef void (*_Keyboard_ReturnToGame)();
typedef void (*_SetMessagePumpDisableMode)(int a1);
typedef void (*_StoreProfile)();

extern _GameInit GameInit;
extern _GameSetState GameSetState;
extern _GameSetBackground GameSetBackground;
extern _GameSetSubState GameSetSubState;
extern _Host_Frame Host_Frame;
extern _Host_Shutdown Host_Shutdown;
extern _Key_Event Key_Event;
extern _Key_ClearStates Key_ClearStates;
extern _Sys_FloatTime Sys_FloatTime;
extern _IN_ClearStates IN_ClearStates;
extern _IN_MouseEvent IN_MouseEvent;
extern _IN_ActivateMouse IN_ActivateMouse;
extern _IN_DeactivateMouse IN_DeactivateMouse;
extern _Snd_AcquireBuffer Snd_AcquireBuffer;
extern _Snd_ReleaseBuffer Snd_ReleaseBuffer;
extern _S_UnblockSound S_UnblockSound;
extern _S_BlockSound S_BlockSound;
extern _S_ClearBuffer S_ClearBuffer;
extern _SNDDMA_Shutdown SNDDMA_Shutdown;
extern _S_GetWAVPointer S_GetWAVPointer;
extern _S_GetDSPointer S_GetDSPointer;
extern _DeinitConProc DeinitConProc;
extern _Con_Printf Con_Printf;
extern _Con_SafePrintf Con_SafePrintf;
extern _VID_UpdateVID VID_UpdateVID;
extern _VID_UpdateWindowVars VID_UpdateWindowVars;
extern _Cvar_Set Cvar_Set;
extern _Cvar_SetValue Cvar_SetValue;
extern _Cvar_VariableValue Cvar_VariableValue;
extern _Cvar_VariableInt Cvar_VariableInt;
extern _Cvar_VariableString Cvar_VariableString;
extern _Cvar_CompleteVariable Cvar_CompleteVariable;
extern _Cbuf_AddText Cbuf_AddText;
extern _Cmd_AddCommand Cmd_AddCommand;
extern _Cmd_Argc Cmd_Argc;
extern _Cmd_Argv Cmd_Argv;
extern _Cmd_Args Cmd_Args;
extern _qwglSwapBuffers qwglSwapBuffers;
extern _GL_Init GL_Init;
extern _GL_SetMode GL_SetMode;
extern _GL_Shutdown GL_Shutdown;
extern _GetGameInfo GetGameInfo;
extern _QGL_D3DShared QGL_D3DShared;
extern _ForceReloadProfile ForceReloadProfile;
extern _SetStartupMode SetStartupMode;
extern _SetPauseState SetPauseState;
extern _GetPauseState GetPauseState;
extern _Keyboard_ReturnToGame Keyboard_ReturnToGame;
extern _SetMessagePumpDisableMode SetMessagePumpDisableMode;
extern _StoreProfile StoreProfile;

#endif // __ENGINE_EXPORTS__