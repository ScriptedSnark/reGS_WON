typedef void (*_GL_Upload32)(unsigned int* data, char* a2, int width, int height, qboolean mipmap, int iType);
typedef void (*_GL_Upload16)(unsigned char* data, int width, int height, qboolean mipmap, int iType, unsigned char* pPal);

extern _GL_Upload32 ORIG_GL_Upload32;
extern _GL_Upload16 ORIG_GL_Upload16;

#define TEX_TYPE_NONE 0
#define TEX_TYPE_ALPHA 1
#define TEX_TYPE_LUM 2
#define TEX_TYPE_ALPHA_GRADIENT 3
#define TEX_TYPE_RGBA 4
#define TEX_IS_ALPHA(type) ((type) == TEX_TYPE_ALPHA || (type) == TEX_TYPE_ALPHA_GRADIENT || (type) == TEX_TYPE_RGBA)

void GL_Upload32(unsigned int* data, char* a2, int width, int height, qboolean mipmap, int iType);
void GL_Upload16(unsigned char* data, int width, int height, qboolean mipmap, int iType, unsigned char* pPal);