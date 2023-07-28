#include "quakedef.h"
#include "winquake.h"

#ifdef REGS_HOOKED
_build_number ORIG_build_number = NULL;
#endif

#define RELEASE_DAY 34995 // Possibly Thursday, October 24, 1996

const char* date = __DATE__;

char* mon[12] =
{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
char mond[12] =
{ 31,    28,    31,    30,    31,    30,    31,    31,    30,    31,    30,    31 };

int build_number()
{
	int m = 0, d = 0, y = 0;
	static int build = 0;

	if (build)
		return build;

	for (m = 0; m < 11; m++)
	{
		if (strnicmp(&date[0], mon[m], 3) == 0)
			break;

		d += mond[m];
	}

	d += atoi(&date[4]) - 1;
	y = atoi(&date[7]) - 1900;
	build = d + (int)((y - 1) * 365.25);

	if (((y % 4) == 0) && m > 1)
	{
		build += 1;
	}

	build -= RELEASE_DAY; // Oct 24 1996

	return build;
}