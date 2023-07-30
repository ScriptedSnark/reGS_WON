#include "quakedef.h"
#include "winquake.h"
#include "gl_draw.h"

_GL_Upload32 ORIG_GL_Upload32 = NULL;
_GL_Upload16 ORIG_GL_Upload16 = NULL;

int texels;
int giTotalTextures;
int giTotalTexBytes;

void GL_MipMap(byte* in, int width, int height)
{
	byte* out = in;

	width <<= 2;
	height >>= 1;

	for (int i = 0; i < height; i++, in += width)
	{
		for (int j = 0; j < width; j += 8, out += 4, in += 8)
		{
			out[0] = (in[0] + in[4] + in[width + 0] + in[width + 4]) >> 2;
			out[1] = (in[1] + in[5] + in[width + 1] + in[width + 5]) >> 2;
			out[2] = (in[2] + in[6] + in[width + 2] + in[width + 6]) >> 2;
			out[3] = (in[3] + in[7] + in[width + 3] + in[width + 7]) >> 2;
		}
	}
}

// I'm not sure about arguments. TODO: recheck it - ScriptedSnark
void GL_Upload32(unsigned int* data, char* a2, int width, int height, qboolean mipmap, int iType)
{
	ORIG_GL_Upload32(data, a2, width, height, mipmap, iType);
}

void GL_Upload16(unsigned char* data, int width, int height, qboolean mipmap, int iType, unsigned char* pPal)
{
	ORIG_GL_Upload16(data, width, height, mipmap, iType, pPal);
}