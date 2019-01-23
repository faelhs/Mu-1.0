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

    __asm MOV EDI,GetNumber
    __asm CALL EDI
    __asm MOV DWORD PTR SS:[EBP-0xBC],EAX
    __asm LEA ECX,DWORD PTR SS:[EBP-0x9C]
    __asm MOV EDI,GetToken
    __asm CALL EDI
    __asm MOV DWORD PTR SS:[EBP-0xA0],EAX
    __asm LEA ECX,DWORD PTR SS:[EBP-0x9C]
    __asm MOV EDI,GetNumber
    __asm CALL EDI
    __asm MOV Excellent,EAX
    __asm MOV EDI,ShopExcellentMod_Exit1
    __asm JMP EDI
}

void __declspec (naked) cExcellentShop::ExcellentShopAdd()
{
	__asm PUSH Excellent
	__asm MOV AL, BYTE PTR SS:[EBP+0x20]
	__asm MOV EDI, ShopExcellentMod_Exit2
	__asm JMP EDI
}

void cExcellentShop::Load()
{
	*(DWORD*) ((ShopExcellentMod_Hook1+1)) = (DWORD) &cExcellentShop::ExcellentShopLoad - (ShopExcellentMod_Hook1+5); 
	*(BYTE*) (ShopExcellentMod_Hook1) = 0xE9;

	*(DWORD*) ((ShopExcellentMod_Hook2+1)) = (DWORD) &cExcellentShop::ExcellentShopAdd - (ShopExcellentMod_Hook2+5); 
	*(BYTE*) (ShopExcellentMod_Hook2) = 0xE9;
}
