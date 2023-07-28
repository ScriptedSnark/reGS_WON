#include "quakedef.h"
#include "winquake.h"
#include "conutils.hpp"

// From https://github.com/YaLTeR/BunnymodXT with minor changes.

namespace ConUtils
{
	HANDLE hConsoleOutput = INVALID_HANDLE_VALUE;
	WORD wStandartAttributes;

	void Init()
	{
		AllocConsole();

		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hConsoleOutput == INVALID_HANDLE_VALUE)
			return;

		CONSOLE_SCREEN_BUFFER_INFO coninfo;
		GetConsoleScreenBufferInfo(hConsoleOutput, &coninfo);
		wStandartAttributes = coninfo.wAttributes;
		coninfo.dwSize.X = 150;
		coninfo.dwSize.Y = 500;
		SetConsoleScreenBufferSize(hConsoleOutput, coninfo.dwSize);

		SetConsoleTitleA("reGS Debug Console");

		ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	}

	void Free()
	{
		FreeConsole();
	}

	void Log(const char* szText)
	{
		if (hConsoleOutput != INVALID_HANDLE_VALUE)
			WriteConsoleA(hConsoleOutput, szText, strlen(szText), NULL, NULL);
	}

	void Log(const char* szText, WORD wAttributes)
	{
		if (hConsoleOutput != INVALID_HANDLE_VALUE) {
			SetConsoleTextAttribute(hConsoleOutput, wAttributes);
			WriteConsoleA(hConsoleOutput, szText, strlen(szText), NULL, NULL);
			SetConsoleTextAttribute(hConsoleOutput, wStandartAttributes);
		}
	}

	void Log(const WCHAR* szText)
	{
		if (hConsoleOutput != INVALID_HANDLE_VALUE)
			WriteConsoleW(hConsoleOutput, szText, wcslen(szText), NULL, NULL);
	}

	void Log(const WCHAR* szText, WORD wAttributes)
	{
		if (hConsoleOutput != INVALID_HANDLE_VALUE) {
			SetConsoleTextAttribute(hConsoleOutput, wAttributes);
			WriteConsoleW(hConsoleOutput, szText, wcslen(szText), NULL, NULL);
			SetConsoleTextAttribute(hConsoleOutput, wStandartAttributes);
		}
	}
}

void PrintMessage(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	char temp[1024];
	vsprintf_s(temp, format, args);

	va_end(args);

	ConUtils::Log(temp, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void PrintWarning(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	char temp[1024];
	vsprintf_s(temp, format, args);

	va_end(args);

	ConUtils::Log(temp, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void PrintCalm(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	char temp[1024];
	vsprintf_s(temp, format, args);

	va_end(args);

	ConUtils::Log(temp, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}