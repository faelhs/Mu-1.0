//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 99.60T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "StdAfx.h"

OBJECTSTRUCT* gObj = ( OBJECTSTRUCT* ) ( OBJECT_BASE );
Quest_User QuestUser[7400];
Quest_Boss QuestBoss[7400];
Quest_Loot QuestLoot[7400];
PLAYERSTRUCT Custom[7400];
CDarkSpirit* gDarkSpirit = (CDarkSpirit*)(0x62A03A0);

__declspec(naked) void CItem::Convert(int type, BYTE Option1, BYTE Option2, BYTE Option3,BYTE Attribute2, BYTE SetOption, BYTE DbVersion)
{
    _asm
	{
		MOV EAX, 0x0040283D
		JMP EAX
	}
}
void CItem::Value()
{
	_asm
	{
		MOV ECX, this;
		MOV EDI, 0x004E7B40;
		CALL EDI;
	}
}