#include "includes.hpp"

// WinAPI things
typedef HMODULE(WINAPI* _LoadLibraryA)(LPCSTR lpLibFileName);
typedef BOOL(WINAPI* _FreeLibrary)(HMODULE hModule);

_LoadLibraryA ORIG_LoadLibraryA = NULL;
_FreeLibrary ORIG_FreeLibrary = NULL;

// long pointer to hw.dll
void* g_lpHwDLL;

bool HookEngine();
bool UnhookEngine();

/*
================
HOOKED_LoadLibraryA
================
*/
HMODULE WINAPI HOOKED_LoadLibraryA(LPCSTR lpLibFileName)
{
    HMODULE hModule = ORIG_LoadLibraryA(lpLibFileName);

    if (hModule)
        PrintMessage("[WinAPI] Loaded DLL: %s\n", lpLibFileName);
    else
        return hModule;

    if (strstr(lpLibFileName, "hw.dll"))
    {
        HookEngine();
    }

    return hModule;
}

/*
================
HOOKED_FreeLibrary
================
*/
BOOL WINAPI HOOKED_FreeLibrary(HMODULE hModule)
{
    char moduleFileName[MAX_PATH];
    if (GetModuleFileName(hModule, moduleFileName, MAX_PATH))
    {
        PrintMessage("[WinAPI] Unloading DLL: %s\n", moduleFileName);

        if (strstr(moduleFileName, "hw.dll"))
        {
            g_lpHwDLL = nullptr;
            UnhookEngine();
        }
    }

    BOOL result = ORIG_FreeLibrary(hModule);

    return result;
}

/*
================
Sys_Printf
================
*/
void Sys_Printf(char* fmt, ...)
{
    return;

    va_list	argptr;
    char msg[4096];

    va_start(argptr, fmt);
    vsprintf(msg, fmt, argptr);
    va_end(argptr);

    PrintMessage("%s", msg);
}

/*
================
HookEngine
================
*/
bool HookEngine()
{
    void* handle;
    void* base;
    size_t size;

    MH_STATUS status;
    g_lpHwDLL = GetModuleHandleA("hw");

    if (!g_lpHwDLL)
        return false;

    PrintCalm("[hw_hooked] Got g_lpHwDLL!\n");

    if (MemUtils::GetModuleInfo(L"hw.dll", &handle, &base, &size))
    {
        Utils utils = Utils::Utils(handle, base, size);

        Find(build_number);
        FindbySymbol(Con_Printf);

        CreateHook(build_number);
        CreateHook(Con_Printf);

        MH_EnableHook(MH_ALL_HOOKS);
    }

    return true;
}

/*
================
UnhookEngine
================
*/
bool UnhookEngine() // implemented badly, sometimes it doesn't unhook =_( - ScriptedSnark
{
    MH_STATUS status = MH_ERROR_DISABLED;

    status = MH_DisableHook(ORIG_build_number);
    if (status != MH_OK)
        PrintWarning("Couldn't disable hook for ORIG_build_number: %s\n", MH_StatusToString(status));

    status = MH_DisableHook(ORIG_Con_Printf);
    if (status != MH_OK)
        PrintWarning("Couldn't disable hook for ORIG_Con_Printf: %s\n", MH_StatusToString(status));

    status = MH_RemoveHook(ORIG_build_number);
    if (status != MH_OK)
        PrintWarning("Couldn't remove hook for ORIG_build_number: %s\n", MH_StatusToString(status));

    status = MH_RemoveHook(ORIG_Con_Printf);
    if (status != MH_OK)
        PrintWarning("Couldn't remove hook for ORIG_Con_Printf: %s\n", MH_StatusToString(status));
 
    return true;
}

/*
================
Main
================
*/
void Main()
{
    // for debugging and getting info - ScriptedSnark
    ConUtils::Init();

    ConUtils::Log("hw_hooked | " __TIMESTAMP__ "\n", FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    MH_STATUS status = MH_Initialize();

    char error_string[128];
    sprintf_s(error_string, "Couldn't initialize MinHook: %s\n", MH_StatusToString(status));

    if (status != MH_OK) {
        MessageBox(NULL, error_string, "hw_hooked", MB_OK | MB_ICONERROR);
    }

    if (MH_CreateHook(&LoadLibraryA, &HOOKED_LoadLibraryA, reinterpret_cast<LPVOID*>(&ORIG_LoadLibraryA)) != MH_OK)
        PrintWarning("[WinAPI] Couldn't create LoadLibraryA hook.\n");

    if (MH_CreateHook(&FreeLibrary, &HOOKED_FreeLibrary, reinterpret_cast<LPVOID*>(&ORIG_FreeLibrary)) != MH_OK)
        PrintWarning("[WinAPI] Couldn't create FreeLibrary hook.\n");

    MH_EnableHook(MH_ALL_HOOKS);
}

/*
================
DllMain
================
*/
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        CreateThread(NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(Main), NULL, NULL, NULL);

        return TRUE;
    }
    else if (fdwReason == DLL_PROCESS_DETACH)
    {
        UnhookEngine();
        ConUtils::Free();
        MH_Uninitialize();
    }


    return FALSE;
}