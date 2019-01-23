#include "StdAfx.h"


//----------------------------------------------------------------------------------------//
// [] --- Novas Joias
//----------------------------------------------------------------------------------------//

void UseItemRecv(PMSG_USEITEM* lpMsg,int aIndex)
{
	OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);

	CItem* DTitem = &lpObj->pInventory[lpMsg->inventoryPos];
	CItem* DTadd  = &lpObj->pInventory[lpMsg->invenrotyTarget];

	int option = func.MyRand(1,63);

	if(DTitem->m_Type == ITEMGET(12 ,25)) //Jewel Level + 13
	{	
		int Jewel25 = GetPrivateProfileInt("CustomJewels","JewelOfDragon",100,CFG_JEWELS);

		if ((rand() % 100) < Jewel25)
		{
			if(DTadd->m_Level >= 13)
			{
				MsgOutput(aIndex,"[%s] O Item Já e +13",lpObj->Name);
				return;
			}
			else
			{
			DTadd->m_Level = 13;
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			}
		}
		else
		{
			MsgOutput(aIndex,"[%s] Sua Joia Falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}
	}

	if(DTitem->m_Type == ITEMGET(12,26)) //Jewel JewelOfEternal
	{	
		int Jewel26 = GetPrivateProfileInt("CustomJewels","JewelOfEternal",100,CFG_JEWELS);

		if ((rand() % 100) < Jewel26)
		{
			if(DTadd->m_Option3 >= 4)
			{
				MsgOutput(aIndex,"[%s] O Item Já e possui Life",lpObj->Name);
				return;
			}
			else
			{
				DTadd->m_Option3 = 4;
				deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			}
		}
		else
		{
			MsgOutput(aIndex,"[%s] Sua Joia Falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}
	}

	if(DTitem->m_Type == ITEMGET(12,27)) //Jewel Skill
	{	
		int Jewel27 = GetPrivateProfileInt("CustomJewels","JewelOfSkill",100,CFG_JEWELS);

		if ((rand() % 100) < Jewel27)
		{
			if(DTadd->m_Option1 == 1)
			{
				MsgOutput(aIndex,"[%s] O Item Já e possui skill",lpObj->Name);
				return;
			}
			else
			{
				DTadd->m_Option1 = 1;
				deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			}
		}
		else
		{
			MsgOutput(aIndex,"[%s] Sua Joia Falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}
	}

	if(DTitem->m_Type == ITEMGET(12,28)) //Jewel + 15
	{	
		int Jewel28 = GetPrivateProfileInt("CustomJewels","JewelOfRainbow",100,CFG_JEWELS);

		if ((rand() % 100) < Jewel28)
		{
			if(DTadd->m_Level == 15)
			{
				MsgOutput(aIndex,"[%s] O Item está no level Maximo",lpObj->Name);
				return;
			}
		
			if(DTadd->m_Level < 13)
			{
				MsgOutput(aIndex,"[%s] O Item precisa estar no level 13",lpObj->Name);
				return;
			}
			else
			{
				DTadd->m_Level = DTadd->m_Level += 1;
				deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			}
		}
		else
		{
			MsgOutput(aIndex,"[%s] Sua Joia Falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}
	}

	if(DTitem->m_Type == ITEMGET(12,29)) //Jewel Excellente
	{	
		int Jewel29 = GetPrivateProfileInt("CustomJewels","JewelOfMystic",100,CFG_JEWELS);

		if ((rand() % 100) < Jewel29)
		{
			if(DTadd->m_NewOption >= 1)
			{
				MsgOutput(aIndex,"[%s] Deixa o Item Excellente",lpObj->Name);
				return;
			}
			else
			{
				DTadd->m_NewOption = option;
				deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			}
		}
		else
		{
			MsgOutput(aIndex,"[%s] Sua Joia Falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}
	}

	if(DTitem->m_Type == ITEMGET(14,27)) //Jewel Anciet of Metal
	{	
		int Ancient = GetPrivateProfileInt("CustomJewels","AncientMetal",100,CFG_JEWELS);

		if ((rand() % 100) < Ancient)
		{

			if(DTadd->m_SetOption >= 3)
			{
				MsgOutput(aIndex,"[%s] O Item Já e Ancient",lpObj->Name);
				return;
			}
			for(int x = 1; x < 6; x++)
			{
				DTadd->m_SetOption = x;
				deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			}
		}
		else
		{
			MsgOutput(aIndex,"[%s] Sua Joia Falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}
       
	}

	if(DTitem->m_Type == ITEMGET(14,30)) //Jewel Luck
	{	
		int Ancient = GetPrivateProfileInt("CustomJewels","JewelOfLuck",100,CFG_JEWELS);

		if ((rand() % 100) < Ancient)
		{

			if(DTadd->m_Option2 == 1)
			{
				MsgOutput(aIndex,"[%s] O Item Ja Possui Luck",lpObj->Name);
				return;
			}
			else
			{
				DTadd->m_Option2 = 1;
				deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			}
		}
		else
		{
			MsgOutput(aIndex,"[%s] Sua Joia Falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}
       
	}

}

//----------------------------------------------------------------------------------------//
// [] --- Deletar as novas joias
//----------------------------------------------------------------------------------------//
void deleteRecv(int aIndex, char slot, char target)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);

	gObjInventoryDeleteItem(aIndex,slot);
	GCInventoryItemDeleteSend(aIndex,slot,1);
	GCInventoryItemOneSend(aIndex,target);	
	lpObj->pInventory[target].Convert(lpObj->pInventory[target].m_Type,lpObj->pInventory[target].m_Option1, lpObj->pInventory[target].m_Option2, lpObj->pInventory[target].m_Option3, lpObj->pInventory[target].m_NewOption,lpObj->pInventory[target].m_SetOption,1);
}
