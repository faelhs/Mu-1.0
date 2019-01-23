/*
Code: Add new monsters to MuOnline client
Credits: DoS.Ninja
Web: ninja-researcher.blogspot.com
*/
#include "Principal.h"
#include "Hook.h"

void Access(DWORD dwOffset, int t_size)
{
	DWORD OldProtect;
	VirtualProtect((LPVOID)dwOffset, t_size, PAGE_EXECUTE_READWRITE, &OldProtect);
}

void HookAddress(DWORD dwAddrOffst, DWORD dwNewOffst, BYTE new_Cmd)
{//Хук процедуры
	Access(dwAddrOffst, 5);

	if (new_Cmd)
		memset((void*)dwAddrOffst, new_Cmd, 1);

	*(DWORD*)(dwAddrOffst + 1) = dwNewOffst - (dwAddrOffst + 5);
}