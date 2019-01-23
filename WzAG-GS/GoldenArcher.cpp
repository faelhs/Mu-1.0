#include "StdAfx.h"

bool cNpc::Load()
{
	this->_Active = GetPrivateProfileInt("Gowther","Active",1,CFG_GOWTHER) > 0 ? true : false;
	this->_Type = GetPrivateProfileInt("Gowther","Type",14,CFG_GOWTHER);
	this->_Index = GetPrivateProfileInt("Gowther","Index",21,CFG_GOWTHER);
	this->_Level = GetPrivateProfileInt("Gowther","Level",1,CFG_GOWTHER);
	this->_Quantity = GetPrivateProfileInt("Gowther","Quantity",30,CFG_GOWTHER);
	GetPrivateProfileString("Gowther","Fala do NPC Gowther 1","Você precisa ter %d Stones!",this->_Notice[0],160,CFG_GOWTHER);
	GetPrivateProfileString("Gowther","Fala do NPC Gowther 2","%s Trocou suas Stones!",this->_Notice[1],160,CFG_GOWTHER);
	GetPrivateProfileString("Gowther","Fala do NPC Gowther 3","%s Foi premiado(a) com 10 Golds!",this->_Notice[2],160,CFG_GOWTHER);
	GetPrivateProfileString("Querys","UPDATE GOWTHER","",this->_Query,100,CFG_QUERY);

	return true;
}

void cNpc::Gowther(OBJECTSTRUCT* Npc, OBJECTSTRUCT* lpObj)
{	
	char Buffer[60];

	INT Stone_ID = ITEMGET(this->_Type,this->_Index);

	if (!this->_Active)
	{
		ChatTargetSend(Npc,"Estou de férias.",lpObj->m_Index);
		return;  
	}
	else if (func.GetInventoryItemCount(lpObj->m_Index,Stone_ID,this->_Level) < this->_Quantity)
	{
		sprintf_s(Buffer,this->_Notice[0],this->_Quantity);
		ChatTargetSend(Npc,Buffer,lpObj->m_Index);
		return;
	}
	else
	{
		Manager.ExecFormat(this->_Query,lpObj->AccountID);

		func.MsgAllUser(0,this->_Notice[1],lpObj->Name);
		func.MsgAllUser(0,this->_Notice[2],lpObj->Name);

		func.gObjDeleteItemsCount(lpObj->m_Index,Stone_ID, this->_Level, this->_Quantity);

		sprintf_s(Buffer,"Parabéns %s",lpObj->Name);
		ChatTargetSend(Npc,Buffer,lpObj->m_Index);
	}
}