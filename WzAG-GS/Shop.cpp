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

DWORD Excellent;

cExcellentShop ExcellentShop;

void __declspec (naked) cExcellentShop::ExcellentShopLoad()
{
	Excellent = 0;

	__asm
	{
		MOV EDI,GetNumber
		CALL EDI
		MOV DWORD PTR SS:[EBP-0xBC],EAX
		LEA ECX,DWORD PTR SS:[EBP-0x9C]
		MOV EDI,GetToken
		CALL EDI
		MOV DWORD PTR SS:[EBP-0xA0],EAX
		LEA ECX,DWORD PTR SS:[EBP-0x9C]
		MOV EDI,GetNumber
		CALL EDI
		MOV Excellent,EAX
		MOV EDI,ShopExcellentMod_Exit1
		JMP EDI
	}
}

void __declspec (naked) cExcellentShop::ExcellentShopAdd()
{
	__asm 
	{
		PUSH Excellent
	    MOV AL, BYTE PTR SS:[EBP+0x20]
	    MOV EDI, ShopExcellentMod_Exit2
	    JMP EDI
	}
}

void cExcellentShop::Load()
{
	*(DWORD*) ((ShopExcellentMod_Hook1+1)) = (DWORD) &cExcellentShop::ExcellentShopLoad - (ShopExcellentMod_Hook1+5); 
	*(BYTE*) (ShopExcellentMod_Hook1) = 0xE9;

	*(DWORD*) ((ShopExcellentMod_Hook2+1)) = (DWORD) &cExcellentShop::ExcellentShopAdd - (ShopExcellentMod_Hook2+5); 
	*(BYTE*) (ShopExcellentMod_Hook2) = 0xE9;
}
