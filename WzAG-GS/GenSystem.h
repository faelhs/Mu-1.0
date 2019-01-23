#pragma once
#ifndef _GENS_H
#define _GENS_H

struct GENS
{
	int  ISGENS;
	int  Gens_Level;
	int  Gens_Resets;
	int  Gens_Zen;
	int  Gens_Vip;
	char CMDDuprian[20];
	char CMDVanert[20];
	char CMDExitGens[20];
	char CMDRankGens[20];
	char nameblack[20];
	char namewhite[20];
};
extern GENS pGens;

void ReadyGenSystem();
void ReadyGenConfigs();
void DuprianCommand(int aIndex);
void VanertCommand(int aIndex);
bool CheckGensSystem(int aIndex);
void GensRankingSave(int aIndex);
void ExitGensCommand(int aIndex);
void RankGensCommand(int aIndex);
void GensRanking(LPOBJ pObj, LPOBJ lpTargetObj);
void GensProtocol(PMSG_CHATDATA * lpMsg, int aIndex);
bool GensDisplay(OBJECTSTRUCT* lpObj, OBJECTSTRUCT* lpTargetObj, void * lpMagic, BOOL magicsend, BYTE MSBFlag, int AttackDamage);

#endif