#ifdef REGS_HOOKED
typedef void (*_Con_Printf)(char* fmt, ...);
extern _Con_Printf ORIG_Con_Printf;
#endif

void Con_Init();
void Con_DebugLog(char* file, char* fmt, ...);

#ifndef REGS_HOOKED
void EXPORT Con_Printf(char* fmt, ...);
#else
void Con_Printf(char* fmt, ...);
#endif