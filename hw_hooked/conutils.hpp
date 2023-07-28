#pragma once

namespace ConUtils
{
    void Init();
    void Free();

    void Log(const char* szText);
    void Log(const char* szText, WORD wAttributes);
    void Log(const WCHAR* szText);
    void Log(const WCHAR* szText, WORD wAttributes);
}

void PrintMessage(const char* format, ...);
void PrintWarning(const char* format, ...);
void PrintCalm(const char* format, ...);