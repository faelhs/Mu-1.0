//###############################################################################################
// Project   :: ACTeaM Classic 0.97d
// GameServer:: 0.96.40				
// Company   :: Advanced CoderZ MU DevelopmenT © 2013
// Revised   :: 17/01/2014
// Coded     :: Mr.Haziel Developer								
//###############################################################################################

#include "StdAfx.h"

void ReadyNewMaps()
{  
    MapsFix();
	LoadMaps();
	/*
	memset((DWORD*)0x004F6092, 0x90, 10); 
	memset((DWORD*)0x004F6092, 0xE8, 1); 
	*(DWORD*)(0x004F6092+1) = (DWORD)&LoadMaps-(0x004F6092+5);
	*/
}


pMapItemInit	MapItemInit		= (pMapItemInit)0x004038F0;
pLoadMapAttr	LoadMapAttr		= (pLoadMapAttr)0x0040364D;
pGetNewPath		GetNewPath		= (pGetNewPath)0x0040311B;

void MapsFix() 
{
	func.SetByte(0x4F4893+1,MAPLIMIT);
	func.SetByte(0x4F48FE+1,MAPLIMIT);

	*(DWORD*)(0x4D1C8A + 3) = MAPLIMIT;
	*(DWORD*)(0x4DC9C1 + 3) = MAPLIMIT;
	*(DWORD*)(0x4DC9EB + 3) = MAPLIMIT;
	*(DWORD*)(0x51C044 + 3) = MAPLIMIT;
	*(DWORD*)(0x41D3F8 + 3) = MAPLIMIT;
	*(DWORD*)(0x421B69 + 3) = MAPLIMIT;
	*(DWORD*)(0x42C618 + 3) = MAPLIMIT;

	*(DWORD*)(0x416B53 + 2) = MAPLIMIT-1;
	*(DWORD*)(0x455007 + 2) = MAPLIMIT-1;
	*(DWORD*)(0x4B41F0 + 3) = MAPLIMIT-1;
	*(DWORD*)(0x40865D + 3) = MAPLIMIT-1;
	*(DWORD*)(0x4726B2 + 3) = MAPLIMIT-1;
	*(DWORD*)(0x47871F + 3) = MAPLIMIT-1;

}
/*
void LoadMaps() 
{
		MessageBoxA(NULL,"7","Fire Plugin - Fatal Erro",NULL);
	LoadMapAttribute(34, "Maps\\Map1.att");
	LoadMapAttribute(35, "Maps\\Map1.att");
		MessageBoxA(NULL,"8","Fire Plugin - Fatal Erro",NULL);
	_asm 
	{
		mov ecx, 0953E3A0h;
		mov edi, 00401159h
		call edi;
	}	
		MessageBoxA(NULL,"9","Fire Plugin - Fatal Erro",NULL);
}

void LoadMapAttribute(unsigned int index, const char *name) 
{
		MessageBoxA(NULL,"10","Fire Plugin - Fatal Erro",NULL);
	if(index > MAPLIMIT)
	{
	//	logs.ConsoleHora(1,"Fez merda nos mapas. %s %d",__FILE__,__LINE__);
		return;
	}
		MessageBoxA(NULL,"11","Fire Plugin - Fatal Erro",NULL);
	unsigned int thismap = (index * MAP_SIZE) + MAP_BASE;
	__asm 
	{
		xor ecx, ecx;
		mov ecx, thismap;
		call MapItemInit;

		push index;
		push name;
		xor ecx, ecx;
		mov ecx, DIR_BASE;
		call GetNewPath;

		push eax;
		mov ecx, thismap;
		call LoadMapAttr;
	}
		MessageBoxA(NULL,"12","Fire Plugin - Fatal Erro",NULL);
}
*/


_declspec (naked) void LoadMap (char * mapname, DWORD mapnr)
{
    __asm
    {
        PUSH EBP
        MOV EBP, ESP
        SUB ESP, 4
        MOV ECX, mapnr
        IMUL ECX, ECX, DIR_BASE
        ADD ECX, 0x9561278
        MOV EDX , MapItemInit
        CALL EDX
    
        MOV EAX, mapname
        PUSH EAX
        MOV ECX, mapnr
        IMUL ECX, ECX, DIR_BASE
        ADD ECX, 0x9561278
        MOV EDX, LoadMapAttr
        CALL EDX
    
        MOV ESP, EBP
        POP EBP
        RETN
    }
}
void LoadMaps()
{
//LoadMap("..\\Data\\Maps\\Map1.att", 34);
//LoadMap("..\\Data\\Maps\\Map1.att", 35);
}