#pragma once
#define Naked(Function) void __declspec(naked) Function()

#define ITEM(x,y)               ((x) * 32 + (y) + 505)
#define ITEMGET(x,y)            ((x) * 32 + (y))

#define COLOR_ADR_ALLOW			0x0058B87B
#define COLOR_ADR_RETURN		0x0058B789

#define iItemTitleColor			0x0058B789
#define iItemTitleColor_Next	0x0058B794
#define iItemTitleColor_Stack	0x0058B87B

#define pDrawGUI2 ((bool (__cdecl*)(DWORD dwElementID, float m_fPositionX, float m_fPositionY, float m_fWidth, float m_fHeight, float m_fArg6)) 0x005F23A0)

#define ProtocolCore	        ((BOOL(*)(int, LPBYTE, int, int))(0x4CDB60))
#define LevelUpAddPoint	        ((void(*)(struct PMSG_LVPOINTADDRESULT*))(0x4BF810))
#define LevelUpRecv		        ((void(*)(struct PMSG_LEVELUP*))(0x4BF4F0))
#define MsgStringSend           ((void(*)(char* message,int color)) 0x5346B0)
#define GetViewPortId			((int(__cdecl*)(int aIndex)) 0x4F8650)
#define DrawBarForm			    ((void(__cdecl*)(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)) 0x5F2340)
#define GetPosFromAngle		    ((void(__cdecl*)(VAngle * Angle, int * PosX, int * PosY)) 0x5F0E50)
#define SetBlend				((void(__cdecl*)(BYTE Mode)) 0x5F12A0)
#define GLSwitchBlend			((void(__cdecl*)()) 0x5F1330)
#define GLSwitch				((void(__cdecl*)()) 0x5F1220)
#define	CursorX				    *(int*)0x7CC0D44
#define	CursorY				    *(int*)0x7CC0D40
#define FixText					((void(*)(int, int, char*))(0x5343E0))		
#define Text					((void(*)(int,int, char* Text, int, int, int)) 0x5342E0)
#define MainSpeedFrame1	        (float*)(0x661910)
#define MainSpeedFrame2	        (float*)(0x6618E4)
#define WndProc                 (WNDPROC)(0x49DA50)
#define pInitModelData			((void(__cdecl*)()) 0x005E3250)
#define pLoadModel				((void(__cdecl*)(int ResourceID, char * Path, char * File, int Arg4)) 0x5E10E0)
#define pLoadTexture			((void(__cdecl*)(int TextureID, char * Folder, int GLREPEAT, int GLNEAREST, int GLTRUE)) 0x5E0CA0)
#define pInitTextureData		((void(__cdecl*)()) 0x005E4A20)

enum ASM
{
	JMP	 = 0xE9,
	JE	 = 0x74,
	JNE  = 0x75,
	JGE  = 0x7D,
	NOP	 = 0x90,
	CALL = 0xE8,
};

namespace ItemColor
{
	enum T
	{
		White		= 0x00,
		Blue		= 0x01,
		Red			= 0x02, //funciona rojo
		Gold		= 0x03,
		Green		= 0x04,
		WhiteRed	= 0x05, // chat verde 
		Violet		= 0x06,
		WhiteBlue	= 0x07,
		WhiteBeige	= 0x08,
		GreenBlue	= 0x09,
		Gray		= 0x0A,
		DarkViolet	= 0x0B,
	};
};