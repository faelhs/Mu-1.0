#pragma once

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

struct PMSG_LEVELUP 
{
	PBMSG_HEAD h;
	BYTE subcode;
	WORD Level;
	WORD LevelUpPoint;
	WORD MaxLife;
	WORD MaxMana;
	WORD MaxBP;
	WORD AddPoint;
	WORD MaxAddPoint;
};

struct PMSG_LVPOINTADDRESULT
{
	PBMSG_HEAD h;
	BYTE subcode;
	BYTE ResultType;
	WORD MaxLifeAndMana;
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
	short gen;
	short qqnt;
	short qcnt;
	short qtip;

};
struct PMSG_QUESTS
{
	PWMSG_HEAD h;
	BYTE Code;
	BYTE Count;
};
struct PMSG_QUESTS_INFO {
	short Index;
	short qqnt;
	short qcnt;
	short qtip;
};

struct PMSG_UPDATEPOINTS
{
	PBMSG_HEAD h;
	BYTE subcode;
	int LevelUpPoint;
};