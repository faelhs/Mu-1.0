//###############################################################################################
// Project   :: ACTeaM Classic 0.97d
// GameServer:: 0.96.40				
// Company   :: Advanced CoderZ MU DevelopmenT © 2013
// Revised   :: 17/01/2014
// Coded     :: Mr.Haziel Developer								
//###############################################################################################

#include "StdAfx.h"


CShop ShopC[MAX_SHOP];
CShop ShopL;

void ReadyCashShop()
{
	ShopL.ShopCont = 3;
//	HookThis((DWORD)&BuyRequest,0x4026B2);
//	hook_proc(0x401B5E, (DWORD)(&ShopDataLoad),							0xE9);
	func.HookThis((DWORD)&ShopDataLoad,0x004031DE);
}

CShop::CShop()
{
}

CShop::~CShop()
{
}

void CShop::Init()
{
	this->SendItemDataLen = 0;
	this->ItemCount = 0;
	memset(this->ShopInventoryMap, 0, sizeof(this->ShopInventoryMap));
	
}

BOOL CShop::LoadShopItem(char* Filename)
{
	FILE *file;
	file = fopen(Filename, "r");

	char Message[255];
	if (file == NULL)
	{
		sprintf(Message,"Falha ao carregar %s",Filename);
		MessageBox(0,Message,"Mu Cosmos",MB_OK);
		::ExitProcess(0);
	}
	char Buff[256];

	int  Type, Index,Level, Dur,Money, LoopCount = 0;
	BYTE Opt1, Opt2, Opt3, Opt4, Anc;

	while (!feof(file))
	{
		fgets(Buff,256,file);
		
		if(Buff[0] ==';' || Buff[0] =='/' || strlen(Buff) < 1 || Buff[0] == ' ')
		{
			continue;
		}
		sscanf(Buff,"%d %d %d %d %d %d %d %d %d",&Type,&Index,&Level,&Dur,&Opt1,&Opt2,&Opt3,&Opt4,&Anc);

		if (this->InsertItem(Type, Index, Level, Dur, Opt1, Opt2, Opt3, Opt4, Anc) == FALSE)
		{
			MessageBox(0,"Erro0 no Shop","Mu Cosmos",MB_OK);
			::ExitProcess(0);
		}
		LoopCount++;
	}
	fclose(file);
	return TRUE;
}

BOOL CShop::InsertItem(int Type, int Index, int Level, int Dur, BYTE Opt1, BYTE Opt2, BYTE Opt3, BYTE ExcOpt,BYTE Anc)
{
	int Temp = ITEMGET(Type, Index);
	if (Temp < 0)
	{
		MessageBox(0,"Erro1 no Shop","Mu Cosmos",MB_OK);
		return FALSE;
	}
	
	int Width = 0, Height = 0;

	ItemGetSize(Temp, Width, Height);

	if ((Width < 0) || (Height < 0))
	{
		MessageBox(0,"Erro2 no Shop","Mu Cosmos",MB_OK);
		return FALSE;
	}

	int x, y, Blank = (-1);

	for (y = 0; y < 15; y++)
	{
		for (x = 0; x < 8; x++)
		{
			if (this->ShopInventoryMap[(x + (y * 8))] == 0)
			{
				Blank = this->InventoryMapCheck(x, y, Width, Height);

				if (Blank >= 0)
				{
					this->Item[Blank].m_Level = Level;

					if (Dur == 0)
					{
						Dur = ItemGetDurability(ITEMGET(Type, Index), Level, (ExcOpt != 0) ? 1 : 0);
					}

					this->Item[Blank].m_Durability = (float)(Dur);
					this->Item[Blank].Convert(Temp, Opt1, Opt2, Opt3,0,ExcOpt,0);  
					this->Item[Blank].Value();

					//this->Cash[Blank].value = BuyMoney;

					this->SendItemData[this->SendItemDataLen] = Blank;
					this->SendItemDataLen++;

					ItemByteConvert((LPBYTE)(&this->SendItemData[this->SendItemDataLen]), this->Item[Blank]);

					this->SendItemDataLen += 4;
					this->ItemCount++;

					return TRUE;
				}
			}
		}
	}
	
}

int CShop::InventoryMapCheck(int X, int Y, int Width, int Height)
{
	if (((X + Width) > 8) || ((Y + Height) > 15))
	{
		return (-1);
	}

	int y, x, Blank = 0;
	
	for (y = 0; y < Height; y++)
	{
		for (x = 0; x < Width; x++)
		{
			if (this->ShopInventoryMap[(((Y + y) * 8) + (X + x))])
			{
				Blank++;
				break;
			}
		}
	}

	if (Blank == 0)
	{
		for (y = 0; y < Height; y++)
		{
			for (x = 0; x < Width; x++)
			{
				this->ShopInventoryMap[(((Y + y) * 8) + (X + x))] = 1;
			}
		}

		return (X + (Y * 8));
	}

	return (-1);
}



BOOL ShopDataLoad()
{

	LoadShopData();

	

	char msg[100];
	for(int i = 1;i < ShopL.ShopCont;i++)
	{
		int x = (i+12);
		sprintf(msg,"..\\Data\\CashShop\\CashShop%d.txt",i);
		ShopC[x].LoadShopItem(msg);
		
	}
	/*
	ShopC[0].LoadShopItem("..\\Data\\Shops\\shop0.txt");
	ShopC[1].LoadShopItem("..\\Data\\Shops\\shop1.txt");
	ShopC[2].LoadShopItem("..\\Data\\Shops\\shop2.txt");
	ShopC[3].LoadShopItem("..\\Data\\Shops\\shop3.txt");
	ShopC[4].LoadShopItem("..\\Data\\Shops\\shop4.txt");	
	ShopC[5].LoadShopItem("..\\Data\\Shops\\shop5.txt");
	ShopC[6].LoadShopItem("..\\Data\\Shops\\shop6.txt");
	ShopC[7].LoadShopItem("..\\Data\\Shops\\shop7.txt");
	ShopC[8].LoadShopItem("..\\Data\\Shops\\shop8.txt");
	ShopC[9].LoadShopItem("..\\Data\\Shops\\shop9.txt");
	ShopC[10].LoadShopItem("..\\Data\\Shops\\shop10.txt");
	ShopC[11].LoadShopItem("..\\Data\\Shops\\shop12.txt");
	ShopC[12].LoadShopItem("..\\Data\\Shops\\shop13.txt");

	ShopC[13].LoadShopItem("..\\Data\\CashShop\\CashShop1.txt");
	ShopC[14].LoadShopItem("..\\Data\\CashShop\\CashShop2.txt");
	ShopC[15].LoadShopItem("..\\Data\\CashShop\\CashShop3.txt");
	ShopC[16].LoadShopItem("..\\Data\\CashShop\\CashShop4.txt");
	ShopC[17].LoadShopItem("..\\Data\\CashShop\\CashShop5.txt");
	*/
	LogAddFunc("ShopExtras Carregado");
	return TRUE;
}



/*
void BuyRequest(PMSG_BUYREQUEST* lpMsg, int aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if(lpObj->TargetShopNumber < 11 && lpObj->TargetShopNumber >= 0)
	{
		CGBuyRequestRecv(lpMsg,aIndex);
		return;
	}

	PMSG_BUYRESULT pResult;

	PHeadSetB((LPBYTE)(&pResult), 0x32, sizeof(pResult));
	pResult.Result = (-1);

	if ((PacketCheckTime(lpObj) == FALSE) || (lpObj->CloseType != -1))
	{
		
		DataSend(aIndex, (LPBYTE)(&pResult), (DWORD)(pResult.h.size));
		return;
	}
	
	if (lpObj->m_ShopTime == 0)
	{
		lpObj->m_ShopTime = 1;
	}

	if (lpObj->m_ShopTime > 60)
	{
		if ((lpObj->m_IfState.use != 0) && (lpObj->m_IfState.type == 3))
		{
			lpObj->TargetShopNumber = (-1);
			lpObj->m_IfState.use = 0;
			lpObj->m_IfState.type = 0;
		}
		DataSend(aIndex, (LPBYTE)(&pResult), (DWORD)(pResult.h.size));
		return;
	}

	if (lpObj->m_IfState.use != 0)
	{
		if (lpObj->m_IfState.type != 3)
		{
			DataSend(aIndex, (LPBYTE)(&pResult), (DWORD)(pResult.h.size));
			return;
		}
	}

	int tShop = lpObj->TargetShopNumber; 

	if ((tShop < 0) || (tShop > (MAX_SHOP - 1)))
	{
		DataSend(aIndex, (LPBYTE)(&pResult), (DWORD)(pResult.h.size));
		return;
	}

	if (lpMsg->Pos > (MAX_ITEM_IN_SHOP - 1))
	{
		DataSend(aIndex, (LPBYTE)(&pResult), (DWORD)(pResult.h.size));
		return;
	}

	if (ShopC[tShop].Item[lpMsg->Pos].IsItem() == TRUE)
	{
		if (pObj[aIndex].mCash < (int)(ShopC[tShop].Cash[lpMsg->Pos].value))
		{
			MsgOutput(aIndex,"Este item custa %d moedas",ShopC[tShop].Cash[lpMsg->Pos].value);
			pResult.Result = (-1);
		}
		else 
		{
			BOOL InsertItem = TRUE;
			if ((ShopC[tShop].Item[lpMsg->Pos].m_Type >= ITEMGET(14,0)) && (ShopC[tShop].Item[lpMsg->Pos].m_Type <= ITEMGET(14,8)))
			{
				int ShopItemDur = (int)(ShopC[tShop].Item[lpMsg->Pos].m_Durability);

				if (ShopItemDur == 0)
				{
					ShopItemDur = 1;
				}

				if (gObjSearchItem(lpObj, ShopC[tShop].Item[lpMsg->Pos].m_Type, ShopItemDur) == TRUE)
				{
					InsertItem = FALSE;
					lpObj->Money -= 10;// ShopC[tShop].Item[lpMsg->Pos].m_BuyMoney;
					
					if (lpObj->Money < 0)
					{
						lpObj->Money = 0;
					}

					GCMoneySend(aIndex, lpObj->Money);
				}
			}

			if (InsertItem == TRUE)
			{
				//MsgOutput(aIndex,"true");
				pResult.Result = gObjShopBuyInventoryInsertItem(lpObj, ShopC[tShop].Item[lpMsg->Pos]);
				
				if (pResult.Result != (-1))
				{
					ItemByteConvert(pResult.ItemInfo, ShopC[tShop].Item[lpMsg->Pos]);
					pObj[aIndex].mCash -= ShopC[tShop].Cash[lpMsg->Pos].value;
					
					if (pObj[aIndex].mCash < 0)
					{
						pObj[aIndex].mCash = 0;
					}
					MySQL.ExecQuery("UPDATE MEMB_INFO set Cash = '%d' where AccountID = '%s'",pObj[aIndex].mCash,lpObj->AccountID);
					MySQL.Fetch();
					MySQL.Close();
					MsgOutput(aIndex,"Item comprado, valor: %d moedas",ShopC[tShop].Cash[lpMsg->Pos].value);
					MsgOutput(aIndex,"Você ainda possui: %d moedas",pObj[aIndex].mCash);
					LogAddTD("PShop compra"); 
					
				}
			} 
		} 
	}
	DataSend(aIndex, (LPBYTE)(&pResult), (DWORD)(pResult.h.size));
}

*/