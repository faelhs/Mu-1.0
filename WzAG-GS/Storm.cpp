#include "StdAfx.h"

EVENT Storm;

void EVENT::ResetConfig()
{
	StormItemsCount = 0;
	memset(&ItemsPrize,0,sizeof(ItemsPrize));
}

void EVENT::Load()
{
	Storm.ResetConfig();
	// ---
	FILE *file;
	file = fopen(CFG_STORM,"r");
	// ---
	char Buff[256];
	int Flag = 0;
	StormItemsCount = 0;
	// ---
	while (!feof(file))
	{
		fgets(Buff,256,file);
		// ---
		if(func.IsBadFileLine(Buff, Flag))
		{
			continue;
		}
		// ---
		if(Flag == 1)
		{
			int n[9];
			sscanf(Buff,"%d %d %d %d %d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4], &n[5], &n[6], &n[7], &n[8]);
			// ---
			ItemsPrize[StormItemsCount].Index		= n[0];
			ItemsPrize[StormItemsCount].ItemID	= n[1];
			ItemsPrize[StormItemsCount].RateItem	= n[2];
			ItemsPrize[StormItemsCount].MaxLvl	= n[3];
			ItemsPrize[StormItemsCount].RateSkill	= n[4];
			ItemsPrize[StormItemsCount].RateLuck	= n[5];
			ItemsPrize[StormItemsCount].MaxOpt	= n[6];
			ItemsPrize[StormItemsCount].RateExc	= n[7];
			ItemsPrize[StormItemsCount].MaxExcOpt	= n[8];
			// ---
			StormItemsCount++;
			
		}
	}

	fclose(file);
}

void EVENT::ItemDrop(int aIndex)
{
		Storm.MaxRateItem = 0;
		
		Storm.StormItemQuantity	= GetPrivateProfileIntA("Storm","ItemQuantity" ,3  ,CFG_STORM);  
		// ---
		for(char x = 0; x < Storm.StormItemQuantity; x++)
		{
				if(StormItemsCount > 0)
				{
					int ArrayItemsIndex[MAX_ITEM_PRIZE];
					int g = -1;
					short RandValue = rand()%100 + 1;
					if (RandValue > Storm.MaxRateItem) RandValue = Storm.MaxRateItem;
					// ---
					for (int i = 0; i < StormItemsCount; i++)
					{
						if (RandValue <= ItemsPrize[i].RateItem)
						{
							ArrayItemsIndex[++g] = i;
						}
					}
					// ---
					RandValue = rand()% (g + 1);
					int PrizeIndex = ArrayItemsIndex[RandValue];
					int Level,Skill,Luck,Opt,Exc;
					// ---
					Level = ItemsPrize[PrizeIndex].MaxLvl;
					Opt   = rand()%(ItemsPrize[PrizeIndex].MaxOpt + 1);
					// ---
					Skill = rand() % 100 + 1 < ItemsPrize[PrizeIndex].RateSkill ? Skill = 1 : Skill = 0;
					Luck  = rand() % 100 + 1 < ItemsPrize[PrizeIndex].RateLuck  ? Luck = 1  : Luck = 0;
					Exc   = rand() % 100 + 1 < ItemsPrize[PrizeIndex].RateExc   ? Exc = func.GenExcOpt(rand()%(ItemsPrize[PrizeIndex].MaxExcOpt + 1)) : Exc = 0;
					// ---
					int Item = ItemGetNumberMake(ItemsPrize[PrizeIndex].Index,ItemsPrize[PrizeIndex].ItemID);
					// ---

					int rndX = (BYTE)gObj[aIndex].X;
					int rndY = (BYTE)gObj[aIndex].Y;
					int DropRand = 1;
					// ---
					if(DropRand == 1)
					{
						rndX = (rndX - 3) + rand()%15;
						rndY = (rndY - 3) + rand()%15;
					}

					ItemSerialCreateSend(aIndex, gObj[aIndex].MapNumber,rndX,rndY,Item,Level,0,Skill,Luck,Opt,gObj[aIndex].m_Index,Exc,0);
				}			
		}
}