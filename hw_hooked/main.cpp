#include "includes.hpp"

typedef int (*_Eng_Load)(LPCSTR lpLibFileName, int load);
_Eng_Load ORIG_Eng_Load = NULL;

// long pointer to hw.dll/hl.exe
void* g_lpHwDLL;
void* g_lpLauncher;

bool HookEngine();
bool UnhookEngine();

funchook_t* g_lpFuncHook_engine;
funchook_t* g_lpFuncHook_launcher;

/*
================
Eng_Load
================
*/
int Eng_Load(LPCSTR lpLibFileName, int load)
{
    int result = ORIG_Eng_Load(lpLibFileName, load);

    if (load)
        HookEngine();

    PrintMessage("[launcher] Eng_Load(\"%s\", %i) returned %i.\n", lpLibFileName, load, result);

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
HookLauncher
================
*/
bool HookLauncher()
{
    void* handle;
    void* base;
    size_t size;

    g_lpLauncher = GetModuleHandleA("hl.exe");

    if (!g_lpLauncher)
        return false;

    PrintCalm("[hw_hooked] Got g_lpLauncher!\n");

    if (MemUtils::GetModuleInfo(L"hl.exe", &handle, &base, &size))
    {
        int status;
        Utils utils = Utils::Utils(handle, base, size);

        g_lpFuncHook_launcher = funchook_create();

        Find(launcher, Eng_Load);
        CreateHook(launcher, Eng_Load);

        funchook_install(g_lpFuncHook_launcher, 0);
    }

    return true;
}

/*
================
UnhookLauncher
================
*/
bool UnhookLauncher()
{
    PrintMessage("[hw_hooked] Unhooking launcher...\n");

    funchook_uninstall(g_lpFuncHook_launcher, 0);
    funchook_destroy(g_lpFuncHook_launcher);

    return true;
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

    g_lpHwDLL = GetModuleHandleA("hw");

    if (!g_lpHwDLL)
        return false;

    PrintCalm("[hw_hooked] Got g_lpHwDLL!\n");

    if (g_lpFuncHook_engine)
        UnhookEngine();

    if (MemUtils::GetModuleInfo(L"hw.dll", &handle, &base, &size))
    {
        int status;
        Utils utils = Utils::Utils(handle, base, size);

        g_lpFuncHook_engine = funchook_create();

        Find(engine, build_number);
        Find(engine, GL_Upload32);
        Find(engine, GL_Upload16);
        FindbySymbol(engine, Con_Printf);

        CreateHook(engine, build_number);
        CreateHook(engine, GL_Upload32);
        CreateHook(engine, GL_Upload16);
        CreateHook(engine, Con_Printf);

        funchook_install(g_lpFuncHook_engine, 0);
    }

    return true;
}

/*
================
UnhookEngine
================
*/
bool UnhookEngine()
{
    PrintMessage("[hw_hooked] Unhooking engine...\n");

    funchook_uninstall(g_lpFuncHook_engine, 0);
    funchook_destroy(g_lpFuncHook_engine);

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

    HookLauncher();
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
        UnhookLauncher();
        ConUtils::Free();
    }


    return FALSE;
}