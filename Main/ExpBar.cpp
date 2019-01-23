#include "Principal.h"


int Exp_s;
Naked (ExpBugBurs)
{
	_asm
	{
			PUSH ECX
			MOV ECX,DWORD PTR DS:[EAX+0x14]
			MOV DWORD PTR DS:[EAX+0x10],ECX
			MOV BYTE PTR DS:[Exp_s],0x1
			POP ECX
			MOV EDI, 0x005318B0
			CALL EDI
			RETN
	}
}
DWORD dwPointerToAll;
// ----
// ----
DWORD dwAddress;
// ----
DWORD dwAddress2;
// ----
#define LDWORD(x) *(DWORD*)(x)
//---------------------------------------------------------------------------
Naked (ExpBarBugs)
{
	_asm
	{
		TEST BYTE PTR DS:[Exp_s],0x1
			JNZ qwerty
			ADD ESI,ECX
qwerty:
		MOV ECX,0x056F3C20
			MOV BYTE PTR DS:[Exp_s],0x0
			RETN
	}
}

void ExperienceBar()
{
	HookOffset((DWORD)&ExpBugBurs, 0x004BF6BC, 0xE8);
	SetNop(0x004BC110, 7);
	HookOffset((DWORD)&ExpBarBugs, 0x004BC110, 0xE8);
}