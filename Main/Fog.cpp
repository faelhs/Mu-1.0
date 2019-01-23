#include "Principal.h"

int *MAP_CHECK      = (int*)0x0067198C; 
int *MAIN_STATE     = (int*)0x0067AC98;

ptr_glEnable glEnable_Real = (ptr_glEnable)&glEnable;
ptr_glClearColor glClearColor_Real = (ptr_glClearColor)&glClearColor;

unsigned int Textures[5];

RGBAStruct FogMapColor(int Map)
{
	RGBAStruct rgb;

	switch (Map)
	{
	case 0x0: // Lorencia
		{
			rgb.r = 0.85f; rgb.g = 0.8025f; rgb.b = 0.2805f; rgb.a = 1.0f; return rgb;
		} 
		break;

	case 0x1: // Dungeon
		{
			rgb.r = 0.83f; rgb.g = 0.7581f; rgb.b = 0.6142f; rgb.a = 1.0f; return rgb;
		} 
		break;

	case 0x2: // Devias
		{
			rgb.r = 0.6643f; rgb.g = 0.8158f; rgb.b = 0.91f; rgb.a = 1.0f; return rgb;
		} 
		break;

	case 0x3: // Noria
		{
			rgb.r = 0.3689f; rgb.g = 0.58f; rgb.b = 0.2552f; rgb.a = 1.0f; return rgb;
		} 
		break;

	case 0x4: // Losttower
		{
			rgb.r = 0.0f; rgb.g = 0.0f; rgb.b = 0.0f; rgb.a = 1.0f; return rgb;
		} 
		break;

	case 0x6: // Stadium
		{
			rgb.r = 0.56f; rgb.g = 0.4424f; rgb.b = 0.308f; rgb.a = 1.0f; return rgb;
		}

	case 0x7: // Atlans
		{
			rgb.r = 0.451f; rgb.g = 0.6478f; rgb.b = 0.82f; rgb.a = 1.0f; return rgb;
		} 
		break;

	case 0x8: // Tarkan
		{
			rgb.r = 0.83f; rgb.g = 0.667f; rgb.b = 0.3154f; rgb.a = 1.0f; return rgb;
		} 
		break;

	case 0xA: // Icarus
		{
			rgb.r = 0.2744f; rgb.g = 0.3839f; rgb.b = 0.56f; rgb.a = 1.0f; return rgb;
		} 
		break; 

	case 0x19: // Kalima
		{
			rgb.r = 0.1736f; rgb.g = 0.3475f; rgb.b = 0.56f; rgb.a = 1.0f; return rgb;
		} 
		break; 

	case 0x1A: // Kalima
		{
			rgb.r = 0.1736f; rgb.g = 0.3475f; rgb.b = 0.56f; rgb.a = 1.0f; return rgb;
		} 
		break; 

	case 0x1B: // Kalima
		{
			rgb.r = 0.1736f; rgb.g = 0.3475f; rgb.b = 0.56f; rgb.a = 1.0f; return rgb;
		} 
		break;

	case 0x1C: // Kalima
		{
			rgb.r = 0.1736f; rgb.g = 0.3475f; rgb.b = 0.56f; rgb.a = 1.0f; return rgb;
		} 
		break;

	case 0x1D: // Kalima
		{
			rgb.r = 0.1736f; rgb.g = 0.3475f; rgb.b = 0.56f; rgb.a = 1.0f; return rgb;
		} 
		break;

	case 0x1E: // Kalima
		{
			rgb.r = 0.1736f; rgb.g = 0.3475f; rgb.b = 0.56f; rgb.a = 1.0f; return rgb;
		} 
		break;

	case 0x1F: // Valley of Loren
		{
			rgb.r = 0.39f; rgb.g = 0.3156f; rgb.b = 0.1872f; rgb.a = 1.0f; return rgb;
		} 
		break;

	case 0x20: // Land of Trial
		{
			rgb.r = 0.0f; rgb.g = 0.0f; rgb.b = 0.0f; rgb.a = 1.0f; return rgb;
		} 
		break; 

	default:
		{
			rgb.r = 0.0f; rgb.g = 0.0f; rgb.b = 0.0f; rgb.a = 1.0f; return rgb;
		} 
		break;
	}
}

void APIENTRY glEnable_Hooked(GLenum cap)
{  
	RGBAStruct rgb = FogMapColor(*MAP_CHECK); 

	GLfloat rgba[4] = { rgb.r, rgb.g, rgb.b, rgb.a };

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (*MAIN_STATE == 0x4)
	{
		glDisable(GL_FOG);
	}

	if (*MAIN_STATE == 5)
	{
		if (cap == GL_BLEND || cap == GL_TEXTURE_2D || cap == GL_DEPTH_TEST)
		{
			glDisable(GL_FOG);
		}

		glEnable_Real(GL_FOG);

		glFogi(GL_FOG_MODE, GL_LINEAR);
		glFogf(GL_FOG_DENSITY, 0.85f);
		glFogfv(GL_FOG_COLOR, rgba);
		glFogf(GL_FOG_START, 1200.0f);
		glFogf(GL_FOG_END, 1800.0f);
		glHint(GL_FOG_HINT, GL_NICEST);

		if (cap == GL_BLEND || cap == GL_TEXTURE_2D || cap == GL_DEPTH_TEST)   
		{
			glDisable(GL_FOG);  
		}
	}


	glEnable_Real(cap);

} 

void APIENTRY glClearColor_Hooked(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	RGBAStruct rgb = FogMapColor(*MAP_CHECK); 

	if (*MAIN_STATE == 2)
	{ 
		glBindTexture(GL_TEXTURE_2D, *Textures); 
		glClearColor_Real(0.76f, 0.76f, 0.76f, 0.0f);
	}

	if (*MAIN_STATE == 4)
	{ 
		glBindTexture(GL_TEXTURE_2D, *Textures);
		glClearColor_Real(0.0f, 0.0f, 0.0f, 0.0f);
		return;
	}

	if (*MAIN_STATE == 5)
	{ 
		glBindTexture(GL_TEXTURE_2D, *Textures); 
		glClearColor_Real(rgb.r, rgb.g, rgb.b, 0.0f);  
		return;
	}

	glClearColor_Real(red,green,blue,alpha);
}


void FogOn()
{
	RunningFG = !RunningFG;
	HINSTANCE hInst;
	hInst = 0;
	HINSTANCE hInstance;
	hInstance = 0;
	hInstance = hInst;

	DisableThreadLibraryCalls(hInst);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)glEnable_Real, glEnable_Hooked);
	DetourAttach(&(PVOID&)glClearColor_Real, glClearColor_Hooked);
	DetourTransactionCommit();
}

void FogOff()
{
	RunningFG = !RunningFG;
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)glEnable_Real, glEnable_Hooked); 
	DetourDetach(&(PVOID&)glClearColor_Real, glClearColor_Hooked);
	DetourTransactionCommit();
}