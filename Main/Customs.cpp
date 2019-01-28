#include "Principal.h"

char SystemTitle[16];
char SystemVersion[6];
char SystemSerial[17];
int	 hpbar;


void Customs()
{
	GetPrivateProfileStringA("B&W","SystemTitle","Private Games Brasil - Mu Online",SystemTitle,sizeof(SystemTitle),WentMu);
	GetPrivateProfileStringA("B&W","SystemVersion","22459",SystemVersion,sizeof(SystemVersion),WentMu);
	GetPrivateProfileStringA("B&W","SystemSerial","PGBrasilMuOnline",SystemSerial,sizeof(SystemSerial),WentMu);
	hpbar	= GetPrivateProfileIntA("B&W","HPBar",   1,WentMu);


	// - Serial do Main
	memset((int*)(0x0066FEF0), 0x00, 17);
	memcpy((int*)(0x0066FEF0), SystemSerial, 17);

	memset((int*)(0x0067DF28), 0x00, 17);
	memcpy((int*)(0x0067DF28), SystemSerial, 17);

	// - Versão do main Exp: 1.00.00
	memset((int*)(0x0066FEE8), 0x00, 6);
	memcpy((int*)(0x0066FEE8), SystemVersion, 6);


	// - Nome da Janela
	memcpy((int*)(0x00660FE0), SystemTitle, sizeof(SystemTitle));
	BYTE NovoJanelaNome[] = {0x68, 0xE0, 0x0F, 0x66, 0x00};
	memcpy((int*)0x004A6FF2, NovoJanelaNome, sizeof(NovoJanelaNome));
	memcpy((int*)0x004A7022, NovoJanelaNome, sizeof(NovoJanelaNome));

	// - Screenshots

	char SSNovo[] = "../ScreenShots/Screen_(%02d_%02d-%02d_%02d)-%04d.jpg";
	_mkdir("../ScreenShots");

	memcpy((int*)(0x00660F9B), SSNovo, sizeof(SSNovo));
	BYTE NovoSSPath[] = {0x68, 0x9B, 0x0F, 0x66, 0x00};
	memcpy((int*)0x0060BE08, NovoSSPath, sizeof(NovoSSPath));

	// - Liberar Itens

	*(BYTE*)(0x005E3C27+2) = 0x50;
	*(BYTE*)(0x005E3D48+2) = 0x50;
	*(BYTE*)(0x005E3D73+2) = 0x50;
	*(BYTE*)(0x005E3DB7+2) = 0x50;
	*(BYTE*)(0x005E3DE2+2) = 0x50;
	*(BYTE*)(0x005E3E26+2) = 0x50;
	*(BYTE*)(0x005E3E80+2) = 0x50;
	*(BYTE*)(0x005E3F43+2) = 0x50;
	*(BYTE*)(0x005E3F6E+2) = 0x50;
	*(BYTE*)(0x005E4827+2) = 0x20;
	*(BYTE*)(0x005E48E8+2) = 0x20; 
	*(BYTE*)(0x005E21A8+2) = 0x50; 
	*(BYTE*)(0x005E26A5+2) = 0x50; 
	*(BYTE*)(0x005E2732+2) = 0x50;
	*(BYTE*)(0x005E27B4+2) = 0x50;
	*(BYTE*)(0x005E2226+2) = 0x50;
	*(BYTE*)(0x005E260E+2) = 0x50;

	// - Acentuação

	memset((int*)(0x66F318),0xA0,1);

	// - Remover Recuo

	*(BYTE*)(0x4DEE00) = 0xC3;

	// - Brilho dos itens

	*(BYTE*)(0x4F7A0E+1) = 0x8C;
	*(BYTE*)(0x5E005B+2) = 0x10;

	// - Excellent Wings Level 1

	*(BYTE*)(0x52CDBA + 3) = 0x80;
	*(BYTE*)(0x52D1F8 + 3) = 0x80;
	*(BYTE*)(0x52D40E + 3) = 0x80;
	*(BYTE*)(0x52D46E + 3) = 0x80;
	*(BYTE*)(0x58A889 + 3) = 0x80;
	*(BYTE*)(0x58AE18 + 1) = 0x80;
	*(BYTE*)(0x58B881 + 3) = 0x80;
	*(BYTE*)(0x58CF46 + 3) = 0x80;
	*(BYTE*)(0x590C0D + 3) = 0x80;
	*(BYTE*)(0x59127D + 3) = 0x80;
	*(BYTE*)(0x5943B3 + 2) = 0x80;
	*(BYTE*)(0x5D2A7E + 2) = 0x80;
	*(BYTE*)(0x52D8E4 + 1) = 0x12;
	*(BYTE*)(0x52D8EA + 1) = 0x1A;
	*(BYTE*)(0x52D8F0 + 1) = 0x22;

	// - Fix Mover Cursor (Quando abre o NPC)

	*(BYTE*)(0x4BEEF7) = 0x90;

	for (DWORD i = 0x4BEF15; i <= 0x4BEF1B; i++)
	{
		*(BYTE*)(i) = 0x90;
	}

	// - Fix Uso do CPU

	*(BYTE*)(0x60C269) = 0x6A;
	*(BYTE*)(0x60C269 + 1) = 0x01;
	*(BYTE*)(0x60C269 + 2) = 0xFF;
	*(BYTE*)(0x60C269 + 3) = 0x15;
	*(BYTE*)(0x60C269 + 4) = 0x38;
	*(BYTE*)(0x60C269 + 5) = 0x11;
	*(BYTE*)(0x60C269 + 6) = 0x66;
	*(BYTE*)(0x60C269 + 7) = 0x00;

	for (DWORD i = 0x60C271; i <= 0x60C27A; i++)
	{
		*(BYTE*)(i) = 0x90;
	}

	*(BYTE*)(0x60C27B) = 0xEB;
	*(BYTE*)(0x60C27B + 1) = 0xD1;

	// - Skills do Siege

	*(BYTE*)(0x57F129+1) = 0x2B;
	*(BYTE*)(0x57F12E+1) = 0x26;
	*(BYTE*)(0x57F133+1) = 0x21;
	*(BYTE*)(0x57F138+1) = 0x1C;
	*(BYTE*)(0x57F13D+1) = 0x17;
	*(BYTE*)(0x57F142)	 = 0xEB;
	*(BYTE*)(0x57F600+2) = 0x00;
	*(BYTE*)(0x57F605+2) = 0x00;
	*(BYTE*)(0x57F60A+2) = 0x00;
	*(BYTE*)(0x57F60F+2) = 0x00;
	*(BYTE*)(0x57F614+2) = 0x00;
	*(BYTE*)(0x57F619+2) = 0x00;

	// - Fonte

	BYTE FixFonte[4] = {0x6A, 0x05, 0x90, 0x90};
	FixFonte[1] = 12;

	// - Fonte Normal
	memcpy((BYTE*)0x004A85E2, FixFonte, 4);

	// - Fonte Bold 1
	memcpy((BYTE*)0x004A8623, FixFonte, 4);

	// - Fonte Bold 2
	memset((BYTE*)0x004A8664, 0x90, 6);
	memcpy((BYTE*)0x004A8664, FixFonte, 4);

	// - Protocol

	ProtocolHook();

	// - Preview

	_obj_preview.Loading();

	// - HP Bar Ex700
	//Hook(0xE8,0x580846,(DWORD)(&HPBar.DrawHealthBar));

	// - HP Bar Original
	Hook(0xE8,0x580846,(DWORD)(&HPBar.DrawHealthBar));


	// - WndProc

	*(DWORD*)(0x4A6F3D) = (DWORD)&WndProcEx;


	// - Zen
	*(BYTE*)(0x5FFBF1+1) = 9;
	*(BYTE*)(0x5F6EEB) = 0xEB;

	// - Change Folder
	_mkdir(ErrorDir);
	char cTempLog[40] = ErrorLog;
	DWORD *offsetLog = (DWORD*)(0x0066E980);
	memset(&offsetLog[0],0,40);
	memcpy(&offsetLog[0],cTempLog,strlen(cTempLog));

	char cTempDump[40] = DumpLog;
	DWORD *offsetDump = (DWORD*)(0x0066FD7C); 
	memset(&offsetDump[0],0,40);
	memcpy(&offsetDump[0],cTempDump,strlen(cTempDump));


	BYTE DecriptLog[5] = {0x90, 0x90, 0x90, 0x90, 0x90};
	memcpy((int*)0x0041CD3A, DecriptLog, sizeof(DecriptLog));
	memcpy((int*)0x0041CE87, DecriptLog, sizeof(DecriptLog));

	//------------------------------------------------------------------------
	// - Mu.exe (Abrir main sem Launcher - ON EB OFF 00)
	//------------------------------------------------------------------------
	*(BYTE*)(0x004A7D68) = 0xEB;

	//------------------------------------------------------------------------
	// FIX Open 2 MU (Abrir Dois main - ON EB OFF 00)
	//------------------------------------------------------------------------
	*(BYTE*)(0x004A7CF7) = 0xEB;
	*(BYTE*)(0x004A7CDB) = 0xEB;

	//------------------------------------------------------------------------
	// Other(Chat Color)
	//------------------------------------------------------------------------
	BYTE ChatObtainedColor[] = { 0x6A, 0x02 };
	WriteMemory( (PVOID) 0x004BD661, & ChatObtainedColor, sizeof( ChatObtainedColor ) );

	BYTE ChatObtainedZenColor[] = { 0x6A, 0x01 };
	WriteMemory( (PVOID) 0x004BD5C7, & ChatObtainedZenColor, sizeof( ChatObtainedZenColor ) );
}

void Initialize()
{
	Customs();
	Joias();
	//  Init_Monsters(); // Pegar Offsets da 1.0L
	HookMiniMap();
	ExperienceBar();
	m_Glow	= LoadLibrary("./Data/Customs/Plugin/Glow.dll");
	m_Cam	= LoadLibrary("./Data/Customs/Plugin/Camera.dll");
	m_Min	= LoadLibrary("./Data/Customs/Plugin/Min.dll");
	m_Keyboard = SetWindowsHookEx(WH_KEYBOARD,KeyboardHookProc,NULL,GetCurrentThreadId());
}

void Finalize()
{
	UnhookWindowsHookEx(m_Keyboard);

	if (m_Glow)
	{
		FreeLibrary(m_Glow);
	}
	if (m_Cam)
	{
		FreeLibrary(m_Cam);
	}
	if (m_Min)
	{
		FreeLibrary(m_Min);
	}
}

HWND            Window			= NULL;
HHOOK           m_Keyboard      = NULL;
HMODULE			m_Glow			= NULL;
HMODULE			m_Cam			= NULL;
HMODULE			m_Min			= NULL;
BYTE            MouseState      = NULL;
bool            FireTeam        = false;
bool            RunningFG       = false;
bool            AutoClick[3]    = { false, false, false };


LRESULT CALLBACK KeyboardHookProc(int Code, WPARAM wParam, LPARAM lParam)
{	
	if (((lParam >> 31) & 1) && (Code == HC_ACTION))
	{
		if (wParam == VK_F8)
		{
			if (!RunningFG)
			{
				FogOn();
			}
			else
			{
				FogOff();
			}
		}
		/*
		if (wParam == VK_F10)
		{
			if (AutoClick[1] == false) // Right
			{
				AutoClick[0] = !AutoClick[0];
				AutoClick[2] = false;

				if (AutoClick[0] == false)  // Left
				{
					KillTimer(Window, AUTOCLICK_LEFT);
					SendMessage(Window, WM_LBUTTONUP, NULL, NULL);
				}
				else
				{
					SetTimer(Window, AUTOCLICK_LEFT, 100, NULL);
				}
			}
		}
		if (wParam == VK_F11)
		{
			if (AutoClick[0] == false) // Left
			{
				AutoClick[1] = !AutoClick[1];
				AutoClick[2] = false;

				if (AutoClick[1] == false)  // Right
				{
					KillTimer(Window, AUTOCLICK_RIGHT);
					SendMessage(Window, WM_RBUTTONUP, NULL, NULL);
				}
				else
				{
					SetTimer(Window, AUTOCLICK_RIGHT, 100, NULL);
				}
			}
		}*/
	}

	return CallNextHookEx(m_Keyboard, Code, wParam, lParam);
}

LRESULT CALLBACK WndProcEx(HWND Window, UINT Message, WPARAM W, LPARAM L)
{
	if (::Window == NULL)
	{
		::Window = Window;
	}

	switch (Message)
	{
	case WM_NCACTIVATE:
		{
			return 0;
		}
		break;
	case WM_RBUTTONDOWN:
		{
			if (MouseState == 2)
			{
				return 0;
			}

			MouseState = 1;
		}
		break;
	case WM_RBUTTONUP:
		{
			if (MouseState == 1)
			{
				MouseState = 0;
			}
		}
		break;
	case WM_LBUTTONDOWN:
		{
			if (MouseState == 1)
			{
				return 0;
			}

			MouseState = 2;
		}
		break;
	case WM_LBUTTONUP:
		{
			if (MouseState == 2)
			{
				MouseState = 0;
			}
		}
		break;
	case WM_TIMER:
		{
			switch (W)
			{
			case AUTOCLICK_LEFT:
				{
					if (AutoClick[0] == true)
					{
						SendMessage(Window, (AutoClick[2] == true) ? WM_LBUTTONUP : WM_LBUTTONDOWN, NULL, NULL);
						AutoClick[2] = !AutoClick[2];
					}
				}
				break;
			case AUTOCLICK_RIGHT:
				{
					if (AutoClick[1] == true)
					{
						SendMessage(Window, (AutoClick[2] == true) ? WM_RBUTTONUP : WM_RBUTTONDOWN, NULL, NULL);
						AutoClick[2] = !AutoClick[2];
					}
				}
				break;
			}
		} 
		break;
	}

	return CallWindowProc(WndProc,Window,Message,W,L);
}