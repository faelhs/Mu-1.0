#include "StdAfx.h"
#include "GoldShop.h" 

GOLDSHOP	GoldShopInfo[255];

int GoldShopCount;

void ReadGoldShop()
{
	FILE *fp;
	BOOL bRead = FALSE;
	DWORD dwArgv = 0;
	char sLineTxt[255] = { 0 };
	GoldShopCount = 1;

	fp = fopen(CFG_GOLDSHOP, "r");

	if (!fp)
	{
		MessageBoxA(NULL, "./DKData/GoldShop.ini not found!!", "Error!", MB_OK);
		::ExitProcess(0);
	}

	rewind(fp);

	while (fgets(sLineTxt, 255, fp) != NULL)
	{
		if (sLineTxt[0] == '/')continue;
		if (sLineTxt[0] == ';')continue;

		int n[20];
		char GetItemName[20];
		char GetExibName[20];

		sscanf(sLineTxt, "%s %d %d %d %d %d %d %d %d %d %s", &GetItemName, &n[1], &n[2], &n[3], &n[4], &n[5], &n[6], &n[7], &n[8], &n[9], &GetExibName);
		sprintf(GoldShopInfo[GoldShopCount].itemnome, "%s", GetItemName);
		sprintf(GoldShopInfo[GoldShopCount].itemexib, "%s", GetExibName);
		GoldShopInfo[GoldShopCount].itemindex = n[1];
		GoldShopInfo[GoldShopCount].itemid = n[2];
		GoldShopInfo[GoldShopCount].itemlvl = n[3];
		GoldShopInfo[GoldShopCount].itemdur = n[4];
		GoldShopInfo[GoldShopCount].itemskill = n[5];
		GoldShopInfo[GoldShopCount].itemluck = n[6];
		GoldShopInfo[GoldShopCount].itemopt = n[7];
		GoldShopInfo[GoldShopCount].itemexc = n[8];
		GoldShopInfo[GoldShopCount].itempreco = n[9];
		GoldShopCount++;
	}

	rewind(fp);
	fclose(fp);
}