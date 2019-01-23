#pragma once

struct ObjPlayer
{
	bool IsUpdate;
	WORD Level;
	WORD LevelUpPoint;
	BYTE Class;
	DWORD Experience;
	DWORD NextExperience;
	WORD Strength;
	WORD Dexterity;
	WORD Vitality;
	WORD Energy;
	WORD Leadership;
	WORD AttackSpeed;
	WORD MagicSpeed;
	WORD Life;
	WORD MaxLife;
	WORD Mana;
	WORD MaxMana;
	WORD BP;
	WORD MaxBP;
	int RealLevelUpPoint;
	bool InEvent;
};

extern ObjPlayer Player;

BOOL ProtocolCoreEx(int, LPBYTE lpRecv, int, int);
void ApplyDexterityFix();
bool CanUseSkill(int Id);
void ProtocolHook();
