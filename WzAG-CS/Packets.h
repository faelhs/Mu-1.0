//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 99.60T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#pragma once

#include "StdAfx.h"

struct PBMSG_HEAD
{
public:
	void set ( LPBYTE lpBuf, BYTE head, BYTE size)
	{
		lpBuf[0] = 0xC1;
		lpBuf[1] = size;
		lpBuf[2] = head;
	};

	void setE ( LPBYTE lpBuf, BYTE head, BYTE size)
	{
		lpBuf[0] = 0xC3;
		lpBuf[1] = size;
		lpBuf[2] = head;
	};

	BYTE c;
	BYTE size;
	BYTE headcode;
};

struct PWMSG_HEAD
{
	BYTE c;
	BYTE sizeH;
	BYTE sizeL;
	BYTE headcode;
};

struct PMSG_CHATDATA
{
	PBMSG_HEAD h;	
	char chatid[10];
	char message[60];
};

struct PMSG_NOTICE
{
	PBMSG_HEAD h;
	BYTE type;
	BYTE btCount;
	WORD wDelay;	
	int dwColor;
	BYTE btSpeed;
	char Notice[256];
}; 

struct PMSG_CHATDATA_NUMBER
{
	PBMSG_HEAD h;
	BYTE NumberH;
	BYTE NumberL;
	char chatmsg[60];
};

struct PMSG_DEFAULT2
{
	PBMSG_HEAD h;
	BYTE subcode;
};

struct PMSG_CHARCREATE
{
	PBMSG_HEAD h;
	BYTE subcode;
	char Name[10];
	BYTE ClassSkin;
};

struct PMSG_PARTYREQUEST
{
	PBMSG_HEAD h;
	BYTE NumberH;
	BYTE NumberL;
};

struct PMSG_CHARINFOMAIN
{
	PBMSG_HEAD h;
	BYTE Code;
	BYTE Class;
	WORD Dexterity;
	WORD AttackSpeed;
	WORD MagicSpeed;
	int LevelUpPoint;
}; 

struct PMSG_UPDATECHARACTER
{
	PBMSG_HEAD h;
	BYTE Code;
	DWORD Experience;
	DWORD NextExperience;
	WORD Level;
	int LevelUpPoint;
	WORD Strength;
	WORD Dexterity;
	WORD Vitality;
	WORD Energy;
	WORD Leadership;
	WORD Life;
	WORD MaxLife;
	WORD Mana;
	WORD MaxMana;
	WORD BP;
	WORD MaxBP;
};

struct PMSG_HEALTHBAR
{
	PWMSG_HEAD h; 
	BYTE Code;
	BYTE Count;
};

struct PMSG_HEALTHBAR_INFO
{
	short Index;
	BYTE Rate;
};

struct PMSG_UPDATEPOINTS
{
	PBMSG_HEAD h;
	BYTE subcode;
	int LevelUpPoint;
};