#pragma once


#define MAX_ITEM_PRIZE	100

struct EVENT
{
public:	
	void Load();
	void ItemDrop(int aIndex);
	void ResetConfig();
	int  StormItemQuantity;

private:
		struct
		{
			short Index;
			short ItemID;
			short RateItem;
			short MaxLvl;
			short RateSkill;
			short RateLuck;
			short MaxOpt;
			short RateExc;
			short MaxExcOpt;
		} ItemsPrize[MAX_ITEM_PRIZE];

		int MaxRateItem;
		int StormItemsCount;
};

extern EVENT Storm;








