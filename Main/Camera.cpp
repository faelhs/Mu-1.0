#include "Principal.h"
#pragma comment(lib,"OpenGL32.lib")
#pragma comment(lib,"GLu32.lib")
#pragma comment(lib,"GLaux.lib")
#define KeyDir "Software\\WebZen\\Mu\\Config"
struct FRGB
{
	float r, g, b;

};

HKEY hKey;
DWORD dwKeyType, RegLPSize;
LONG RegOpen;
char CurrentDir[_MAX_PATH1];

bool CameraState = false;
bool MoveCamera = false;
int MouseX, MouseY;
int TimerID;
int CameraMode, CameraSensivity, CameraControl;
int CameraLBtn, CameraRBtn;
int Sky, SkyDayNight;
int DisplayInitialized;
char buff[65536];
char CurrentPath[_MAX_PATH1];
FRGB skycolor;
int skycolordirection;
int LastMaps;
int sky = 0;

AUX_RGBImageRec* blankimage;
AUX_RGBImageRec* images[80][6];
unsigned int textures[80][6];

#pragma data_seg(".shared")
static HHOOK HookKeyboard = NULL;
HHOOK HookCamera = NULL;
static HINSTANCE hInstance;
#pragma data_seg()
#pragma comment(linker,"/SECTION:.shared,RWS")

char GetOptions(LPCSTR lpValueName);
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK CameraProc(int nCode, WPARAM wParam, LPARAM lParam);
VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
VOID CALLBACK SkyTimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);


int *Mapx = (int*)0x0067198C;//ok 
int *Main_StateS = (int*)0x0067AC98;//chequear
float *Camera_Zoom = (float*)0x00609921;//ok
float *Camera_RotY = (float*)0x0066365C;//ok
float *Camera_RotZ = (float*)0x07CC0D88;//ok
float *Camera_PosY = (float*) 0x006117E0;//ok
float *Camera_PosZ = (float*)0x006616B0;//ok
float *Camera_ClipX = (float*)0x00663540;//ok
float *Camera_ClipY = (float*)0x005D09EE;//ok
float *Camera_GlClip = (float*)0x00609C0E;//ok
float *Camera_ClipR = (float*)0x663544;//ok
float *Camera_ClipX_Map30 = (float*)0x663550;//ok
float *Camera_ClipR_Map30 = (float*)0x663554;//ok
float *Camera_ClipY_Map30 = (float*)0x005D099E;//ok
long *Main_MouseX = (long*)0x7CBAF14;//ok
long *Main_MouseY = (long*)0x7CBAF10;//ok

typedef int(*TSkyHook)();
TSkyHook SkyHook = (TSkyHook)0x00512A80;//ok

typedef int(*TBlend) (int);
TBlend Blend = (TBlend)0x5F1130;//ok

typedef int(*TUnBlend) ();
TUnBlend UnBlend = (TUnBlend)0x005F1330; //ok

typedef int(*TLoadImage)(char[64], int, int, int, int, int);
TLoadImage LoadImgx = (TLoadImage)0x0060F900; //ok
TLoadImage LoadImgAlphax = (TLoadImage)0x60FC20;

typedef int(*TPrintImage) (DWORD, float, float, float, float, int, int, float, float, int, int, int);
TPrintImage PrintImage = (TPrintImage)0x5F2290;
BOOL KeyboardSetHook(BOOL set_or_remove);

void TrilinearFiltering()
{
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}


void LoadAddons()
{
	char confignametemp[MAX_PATH];
	::GetModuleFileName(NULL, confignametemp, sizeof(confignametemp));
	strncpy_s(CurrentDir, confignametemp, strlen(confignametemp) - strlen(strrchr(confignametemp, '\\')) + 1);

	CameraMode = 1;
	CameraSensivity = 8;
	CameraControl = 1;

	if(sky =  1)
	{
	Sky = 1;
	SkyDayNight =1;
	}
	KeyboardSetHook(true);

	LastMaps = -1;

	TrilinearFiltering();

	if (CameraMode)
	{
		HookOffset((DWORD)&Display, 0x0060B1C5, 0xE8);//ok

		*Camera_ClipX = 12000;
		*Camera_ClipR = 6600;
		*Camera_ClipY = 12000;
		*Camera_GlClip = 6000;

		*Camera_ClipX_Map30 = 7000;
		*Camera_ClipR_Map30 = 8000;
		*Camera_ClipY_Map30 = 10000;
		HookCamera = SetWindowsHookEx(WH_MOUSE, CameraProc, NULL, GetCurrentThreadId());
		*Camera_Zoom = 35;
	}
	//Fix_RotateDmg();
}
int WritePrivateProfileFloat(const char* pcSektion, const char* pcKey, float* dValue, const char* pcIni) {
	char acValue[30];
	sprintf(acValue, "%f", dValue);
	return WritePrivateProfileString(pcSektion, pcKey, acValue, pcIni);
}

char GetOptions(LPCSTR lpValueName)
{
	char* uData = new char[1];
	RegLPSize = sizeof(uData);
	RegOpen = RegOpenKeyEx(HKEY_CURRENT_USER, KeyDir, 0, KEY_ALL_ACCESS, &hKey);
	if (RegOpen == ERROR_SUCCESS)
	{
		RegQueryValueEx(hKey, lpValueName, NULL, &dwKeyType, (LPBYTE)uData, &RegLPSize);
	}
	return *uData;
	delete[] uData;
}

BOOL KeyboardSetHook(BOOL set_or_remove){
    if(set_or_remove == TRUE){
		if(HookKeyboard == NULL){
			HookKeyboard = SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)KeyboardProc, hInstance, GetCurrentThreadId());
			if(!HookKeyboard){ return FALSE; }
		}
	} else {
		return UnhookWindowsHookEx(HookKeyboard);
		HookKeyboard = NULL;
	}
    return TRUE;
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam){	
		if(((lParam>>31)&1) && (nCode == HC_ACTION)){
		if(wParam == VK_HOME){
			*Camera_RotY	= 48.50000;
			*Camera_RotZ	= -45;
			*Camera_PosZ	= 150.0000;
			*Camera_Zoom	= 35.00000;
			*Camera_ClipX = 12000;
			*Camera_ClipR = 6600;
			*Camera_ClipY = 12000;
			*Camera_GlClip = 6000;
		}

		if(wParam == VK_F7){
			 if(CameraControl == 1)
            { 
				CameraControl = 2;
            } else {
				CameraControl = 1;
            }
		}

	}	

	return CallNextHookEx(HookKeyboard, nCode, wParam, lParam);
}

LRESULT CALLBACK CameraProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	MOUSEHOOKSTRUCTEX* mhs = (MOUSEHOOKSTRUCTEX*)lParam;
	HWND MuWindow = FindWindow("MU", NULL);
	if (GetForegroundWindow() == MuWindow)
	{		
		
		
		if (wParam == WM_MOUSEWHEEL)
		{
	
			int direction = mhs->mouseData;
			if (direction<0)
			{
				if (*Camera_Zoom < 60)
				{
					for (int i = 1; i <= CameraSensivity; i++)
					{
						*Camera_Zoom += 0.2f;
					}
				}
				if (*Camera_Zoom > 60)
					*Camera_Zoom = 60;
			}



			else if (direction>0)
			{
				if (*Camera_Zoom > 1)
				{
					for (int i = 1; i <= CameraSensivity; i++)
					{
						*Camera_Zoom -= 0.2f;
					}
				}
				if (*Camera_Zoom < 1)
					*Camera_Zoom = 1;
			}
		}
		else if (wParam == WM_LBUTTONDOWN)
		{
			if (CameraControl == 2)
			{
				CameraLBtn = 1;
				if (CameraRBtn)
				{
					mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
					MouseX = mhs->pt.x;
					MouseY = mhs->pt.y;
					MoveCamera = true;
					*Main_MouseX = 640;
					*Main_MouseY = 480;
					SetTimer(MuWindow, 1, 1, (TIMERPROC)TimerProc);
					CallNextHookEx(0, nCode, wParam, lParam);
					return 1;
				}
			}
		}
		else if (wParam == WM_LBUTTONUP)
		{
			if (CameraControl == 2)
			{
				CameraLBtn = 0;
				if (!CameraRBtn)
				{
					if (MoveCamera)
					{
						KillTimer(MuWindow, 1);
						MoveCamera = false;
						SetCursorPos(MouseX, MouseY);
					}
				}
			}
		}
		else if (wParam == WM_RBUTTONDOWN)
		{
			if (CameraControl == 2)
			{
				CameraRBtn = 1;
				if (CameraLBtn)
				{
					mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
					MouseX = mhs->pt.x;
					MouseY = mhs->pt.y;
					MoveCamera = true;
					*Main_MouseX = 640;
					*Main_MouseY = 480;
					SetTimer(MuWindow, 1, 1, (TIMERPROC)TimerProc);
					CallNextHookEx(0, nCode, wParam, lParam);
					return 1;
				}
			}
		}
		else if (wParam == WM_RBUTTONUP)//no
		{
			if (CameraControl == 2)
			{
				CameraRBtn = 0;
				if (!CameraLBtn)
				{
					if (MoveCamera)
					{
						KillTimer(MuWindow, 1);
						MoveCamera = false;
						SetCursorPos(MouseX, MouseY);
					}
				}
			}
		}
		else if (wParam == WM_MBUTTONDOWN)//no
		{
			if (CameraControl == 1)
			{
				MouseX = mhs->pt.x;
				MouseY = mhs->pt.y;
				MoveCamera = true;
				*Main_MouseX = 640;
				*Main_MouseY = 480;
				SetTimer(MuWindow, 1, 1, (TIMERPROC)TimerProc);
			}
		}
		else if (wParam == WM_MBUTTONUP)//no
		{
			if (CameraControl == 1)
			{
				if (MoveCamera)
				{
					KillTimer(MuWindow, 1);
					MoveCamera = false;
					SetCursorPos(MouseX, MouseY);
				}
			}
		}
		else if (wParam == WM_MOUSEMOVE)
		{
			if (MoveCamera)
			{
				if (MouseX < mhs->pt.x)
				{
					for (int i = 1; i <= CameraSensivity; i++)
						*Camera_RotZ += 0.7;
				}
				else if (MouseX > mhs->pt.x)
				{
					for (int i = 1; i <= CameraSensivity; i++)
						*Camera_RotZ -= 0.7;
				}

				if (*Camera_RotZ > 315 || *Camera_RotZ < -405) *Camera_RotZ = -45;

				if (MouseY < mhs->pt.y)
				{
					if (*Camera_RotY > 45)
					{
						for (int i = 1; i <= CameraSensivity; i++)
						{
							*Camera_PosZ -= 5.0f;
							*Camera_RotY -= 0.3f;
						}
					}
					else
						*Camera_RotY = 45;
				}
				else if (MouseY > mhs->pt.y)
				{
					if (*Camera_RotY < 90)
					{
						for (int i = 1; i <= CameraSensivity; i++)
						{
							*Camera_PosZ += 5.0f;
							*Camera_RotY += 0.3f;
						}
					}
					else
						*Camera_RotY = 90;
				}
				CallNextHookEx(0, nCode, wParam, lParam);
				return 1;
			}
		}
		
	}

	return CallNextHookEx(0, nCode, wParam, lParam);
}

VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	SetCursorPos(MouseX, MouseY);
}


void GetCamCoords(double* x_cam, double* y_cam, double* z_cam)
{
	double m[16];
	glGetDoublev(GL_MODELVIEW_MATRIX, m);
	*x_cam = -m[12] * m[0] - m[13] * m[1] - m[14] * m[2];
	*y_cam = -m[12] * m[4] - m[13] * m[5] - m[14] * m[6];
	*z_cam = -m[12] * m[8] - m[13] * m[9] - m[14] * m[10];
}

void InitDisplay()
{
	if (Sky)
	{
		char texturepath[256];
		sprintf(texturepath, "%s", ".\\Data\\Sky\\Null.bmp");
		if (!FileExists(texturepath))
		{
			MessageBox(0, "Cannot find blank texture\n.\\Data\\Sky\\Null.bmp", "3D Sky", 0);
			ExitProcess(0);
		}
		blankimage = auxDIBImageLoad(texturepath);

		try
		{
			for (int i = 0; i<90; i++)
			{
				for (int j = 0; j<6; j++)
				{
					images[i][j] = blankimage;
				}

				sprintf(texturepath, ".\\Data\\Sky\\World%d\\Back.bmp", i + 1);
				if (FileExists(texturepath))
					images[i][0] = auxDIBImageLoad(texturepath);
				sprintf(texturepath, ".\\Data\\Sky\\World%d\\Bottom.bmp", i + 1);
				if (FileExists(texturepath))
					images[i][1] = auxDIBImageLoad(texturepath);
				sprintf(texturepath, ".\\Data\\Sky\\World%d\\Front.bmp", i + 1);
				if (FileExists(texturepath))
					images[i][2] = auxDIBImageLoad(texturepath);
				sprintf(texturepath, ".\\Data\\Sky\\World%d\\Left.bmp", i + 1);
				if (FileExists(texturepath))
					images[i][3] = auxDIBImageLoad(texturepath);
				sprintf(texturepath, ".\\Data\\Sky\\World%d\\Right.bmp", i + 1);
				if (FileExists(texturepath))
					images[i][4] = auxDIBImageLoad(texturepath);
				sprintf(texturepath, ".\\Data\\Sky\\World%d\\Top.bmp", i + 1);
				if (FileExists(texturepath))
					images[i][5] = auxDIBImageLoad(texturepath);
			}
		}
		catch (...){}

		for (int i = 0; i<90; i++)
		{
			for (int j = 0; j<6; j++)
			{
				glGenTextures(1, &textures[i][j]);
				glBindTexture(GL_TEXTURE_2D, textures[i][j]);
				glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
				glTexImage2D(GL_TEXTURE_2D, 0, 3, images[i][j]->sizeX, images[i][j]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, images[i][j]->data);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			}
		}

		skycolor.r = 1.0f;
		skycolor.g = 1.0f;
		skycolor.b = 1.0f;
		if (SkyDayNight)
		{
			skycolordirection = 1;
			SetTimer(FindWindow("Mu DraconicK", NULL), 2, 5000, (TIMERPROC)SkyTimerProc);
			ChangeSky();
		}
	}

	DisplayInitialized = 1;
}
VOID CALLBACK SkyTimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	ChangeSky();
}
void ChangeSky()
{
	
		skycolor.r = 1.0f;
		skycolor.g = 1.0f;
		skycolor.b = 1.0f;

}
bool CanDrawSky()
{
	char texturepath[256];
	sprintf(texturepath, ".\\Data\\Sky\\World%d\\Top.bmp", *Mapx + 1);
	if (FileExists(texturepath))
		return true;
	return false;
}


void Display()
{
	SkyHook();
	if (*Main_StateS == 5)
	{
		if (!DisplayInitialized)
			InitDisplay();

		if (Sky && CanDrawSky())
		{
			double x_cam, y_cam, z_cam;
			GetCamCoords(&x_cam, &y_cam, &z_cam);

			Blend(1);
			glColor3d(skycolor.r, skycolor.g, skycolor.b);
			glBindTexture(GL_TEXTURE_2D, textures[*Mapx][5]);
			glBegin(GL_QUADS);
			//TOP
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x_cam - 5500, y_cam + 5500, 1250);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x_cam + 5500, y_cam + 5500, 1250);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x_cam + 5500, y_cam - 5500, 1250);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x_cam - 5500, y_cam - 5500, 1250);
			glEnd();

			glBindTexture(GL_TEXTURE_2D, textures[*Mapx][1]);
			glBegin(GL_QUADS);
			//BOTTOM
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x_cam - 5500, y_cam + 5500, 0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x_cam + 5500, y_cam + 5500, 0);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x_cam + 5500, y_cam - 5500, 0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x_cam - 5500, y_cam - 5500, 0);
			glEnd();

			glBindTexture(GL_TEXTURE_2D, textures[*Mapx][2]);
			glBegin(GL_QUADS);
			//FRONT
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x_cam - 5500, y_cam + 5500, 1250);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x_cam + 5500, y_cam + 5500, 1250);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x_cam + 5500, y_cam + 5500, 0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x_cam - 5500, y_cam + 5500, 0);
			glEnd();

			glBindTexture(GL_TEXTURE_2D, textures[*Mapx][0]);
			glBegin(GL_QUADS);
			//BACK
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x_cam - 5500, y_cam - 5500, 1250);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x_cam + 5500, y_cam - 5500, 1250);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x_cam + 5500, y_cam - 5500, 0);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x_cam - 5500, y_cam - 5500, 0);
			glEnd();

			glBindTexture(GL_TEXTURE_2D, textures[*Mapx][3]);
			glBegin(GL_QUADS);
			//LEFT
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x_cam - 5500, y_cam - 5500, 1250);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x_cam - 5500, y_cam + 5500, 1250);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x_cam - 5500, y_cam + 5500, 0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x_cam - 5500, y_cam - 5500, 0);
			glEnd();

			glBindTexture(GL_TEXTURE_2D, textures[*Mapx][4]);
			glBegin(GL_QUADS);
			//RIGHT
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x_cam + 5500, y_cam - 5500, 1250);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x_cam + 5500, y_cam + 5500, 1250);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x_cam + 5500, y_cam + 5500, 0);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x_cam + 5500, y_cam - 5500, 0);
			glEnd();
			UnBlend();
		}
	}
}