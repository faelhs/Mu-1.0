//**********************************************************************//
// Project:	HaRiBO MU GameServer - Season 6								//
// Company: RealCoderZ MU Development © 2010							//
// Description: Game Shops & NPCs Structures							//
// Coded & Modified By:	WolF & M.E.S									//
//**********************************************************************//

#include "StdAfx.h"

#define MAX_SHOP		    50
#define MAX_ITEM_IN_SHOP	120

struct sShop
{
	int value;
};


class CShop
{
public:
	CShop();
	virtual ~CShop();


	void Init();
	BOOL LoadShopItem(char* Filename);
	BOOL InsertItem(int Type, int Index, int Level, int Dur, BYTE Opt1, BYTE Opt2, BYTE Opt3, BYTE ExcOpt,BYTE Anc);
	int InventoryMapCheck(int X, int Y, int Width, int Height);


	BYTE ShopInventoryMap[MAX_ITEM_IN_SHOP];
	int ItemCount;
	CItem Item[MAX_ITEM_IN_SHOP];
	sShop Cash[MAX_ITEM_IN_SHOP];
	BYTE SendItemData[(MAX_ITEM_IN_SHOP * 5)];
	int SendItemDataLen;
	int ShopCont;

};

extern CShop ShopC[MAX_SHOP];
extern CShop ShopL;

void ReadyCashShop();
BOOL ShopDataLoad();
//void BuyRequest(PMSG_BUYREQUEST* lpMsg, int aIndex);
