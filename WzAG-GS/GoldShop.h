#pragma once
#ifndef _GOLDSHOP_H
#define _GOLDSHOP_H

void ReadGoldShop();

typedef struct GoldShop
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

}GOLDSHOP;

extern GoldShop GoldShopInfo[255];

extern int GoldShopCount;

#endif
