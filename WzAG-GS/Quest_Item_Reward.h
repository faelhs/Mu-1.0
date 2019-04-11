#pragma once
#ifndef _Quest_Item_Reward_H
#define _Quest_Item_Reward_H
#endif

void ReadQuest_Item_Reward();
typedef struct Quest_Item_Reward
{
	char itemnome[20];
	char itemexib[20];
	int itemindex;
	int itemid;
	int itemlvl;
	int itemdur;
	int itemopt;
	int itemexc;
	int itemluck;
	int itemskill;
	int itempreco;

}Quest_Item_Reward;

extern Quest_Item_Reward Quest_Item_RewardInfo[255];
extern int Quest_Item_RewardCount;

