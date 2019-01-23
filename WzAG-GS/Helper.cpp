#include "StdAfx.h"

NpcsStruct NpcStc;

void Helper(OBJECTSTRUCT*lpObj, OBJECTSTRUCT* lpNpc)
{
	int helper = Manager.Helper(lpObj->AccountID);

	int Points = GetPrivateProfileIntA("Helper","Points Bonus",5000,CFG_HELPER);
	int Resets = GetPrivateProfileIntA("Helper","Points Resets",5,CFG_HELPER);

	NpcStc.EnabledNpcNoob = GetPrivateProfileIntA("Helper","Ativar",1,CFG_HELPER);

	NpcStc.SetNumberBK = GetPrivateProfileIntA("Helper","Set Bonus BK",5,CFG_HELPER);
	NpcStc.SetNumberSM = GetPrivateProfileIntA("Helper","Set Bonus SM",2,CFG_HELPER);
	NpcStc.SetNumberDL = GetPrivateProfileIntA("Helper","Set Bonus DL",39,CFG_HELPER);
	NpcStc.SetNumberMG = GetPrivateProfileIntA("Helper","Set Bonus MG",39,CFG_HELPER);
	NpcStc.SetNumberElf = GetPrivateProfileIntA("Helper","Set Bonus Elf",10,CFG_HELPER);

	NpcStc.LevelItems	= GetPrivateProfileIntA("Helper","Set Bonus Level",13,CFG_HELPER);
	NpcStc.ExcItem		= GetPrivateProfileIntA("Helper","Set Bonus ExcItem",63,CFG_HELPER);

	NpcStc.ArmaIndexBK	= GetPrivateProfileIntA("Helper","ArmaIndexBK",0,CFG_HELPER);
	NpcStc.ArmaTypeBK	= GetPrivateProfileIntA("Helper","ArmaTypeBK",20,CFG_HELPER);

	NpcStc.ArmaIndexSM	= GetPrivateProfileIntA("Helper","ArmaIndexSM",5,CFG_HELPER);
	NpcStc.ArmaTypeSM	= GetPrivateProfileIntA("Helper","ArmaTypeSM",11,CFG_HELPER);

	NpcStc.ArmaIndexElf = GetPrivateProfileIntA("Helper","ArmaIndexElf",4,CFG_HELPER);
	NpcStc.ArmaTypeElf	= GetPrivateProfileIntA("Helper","ArmaTypeElf",18,CFG_HELPER);

	NpcStc.ArmaIndexMG	= GetPrivateProfileIntA("Helper","ArmaIndexMG",0,CFG_HELPER);
	NpcStc.ArmaTypeMG	= GetPrivateProfileIntA("Helper","ArmaTypeMG",21,CFG_HELPER);

	NpcStc.ArmaIndexDL	= GetPrivateProfileIntA("Helper","ArmaIndexDL",2,CFG_HELPER);
	NpcStc.ArmaTypeDL	= GetPrivateProfileIntA("Helper","ArmaTypeDL",12,CFG_HELPER);

	DWORD Set,Arma;

	switch(lpObj->Class)
	{
	case CLASS_WIZARD:
		Set			= NpcStc.SetNumberSM;
		Arma		= ItemGetNumberMake(NpcStc.ArmaIndexSM,NpcStc.ArmaTypeSM);
		break;
	case CLASS_KNIGHT:
		Set			= NpcStc.SetNumberBK;
		Arma		= ItemGetNumberMake(NpcStc.ArmaIndexBK,NpcStc.ArmaTypeBK);
		break;
	case CLASS_ELF:
		Set			= NpcStc.SetNumberElf;
		Arma		= ItemGetNumberMake(NpcStc.ArmaIndexElf,NpcStc.ArmaTypeElf);
		break;
	case CLASS_MAGUMSA:
		Set			= NpcStc.SetNumberMG;
		Arma		= ItemGetNumberMake(NpcStc.ArmaIndexMG,NpcStc.ArmaTypeMG);

		break;
	case CLASS_DARKLORD:
		Set			= NpcStc.SetNumberDL;
		Arma		= ItemGetNumberMake(NpcStc.ArmaIndexDL,NpcStc.ArmaTypeDL);
		break;
	}
	if(NpcStc.EnabledNpcNoob == 1)
	{
		if (helper != 0)
		{
			ChatTargetSend(lpNpc,"Você Já recebeu minha Ajuda!", lpObj->m_Index);
			return;
		}

		if(lpObj->Class == CLASS_MAGUMSA)
		{
			int Armor	= ItemGetNumberMake(8,Set);
			int Gloves	= ItemGetNumberMake(9,Set);
			int Pants	= ItemGetNumberMake(10,Set);
			int Boots	= ItemGetNumberMake(11,Set);

			ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,Armor,NpcStc.LevelItems,255,1,1,4,lpObj->m_Index,NpcStc.ExcItem,0);
			ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,Gloves,NpcStc.LevelItems,255,1,1,4,lpObj->m_Index,NpcStc.ExcItem,0);
			ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,Pants,NpcStc.LevelItems,255,1,1,4,lpObj->m_Index,NpcStc.ExcItem,0);
			ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,Boots,NpcStc.LevelItems,255,1,1,4,lpObj->m_Index,NpcStc.ExcItem,0);
			ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,Arma,NpcStc.LevelItems,255,1,1,4,lpObj->m_Index,NpcStc.ExcItem,0);							
		}
		else
		{		
			int Helm	= ItemGetNumberMake(7,Set);
			int Armor	= ItemGetNumberMake(8,Set);
			int Gloves	= ItemGetNumberMake(9,Set);
			int Pants	= ItemGetNumberMake(10,Set);
			int Boots	= ItemGetNumberMake(11,Set);

			ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,Helm,NpcStc.LevelItems,255,1,1,4,lpObj->m_Index,NpcStc.ExcItem,0);
			ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,Armor,NpcStc.LevelItems,255,1,1,4,lpObj->m_Index,NpcStc.ExcItem,0);
			ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,Gloves,NpcStc.LevelItems,255,1,1,4,lpObj->m_Index,NpcStc.ExcItem,0);
			ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,Pants,NpcStc.LevelItems,255,1,1,4,lpObj->m_Index,NpcStc.ExcItem,0);
			ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,Boots,NpcStc.LevelItems,255,1,1,4,lpObj->m_Index,NpcStc.ExcItem,0);
			ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,Arma,NpcStc.LevelItems,255,1,1,4,lpObj->m_Index,NpcStc.ExcItem,0);							
		}

		Manager.ExecFormat("UPDATE [MuOnline].[dbo].[MEMB_INFO] SET helper = 1 Where memb___id = '%s'",lpObj->AccountID);
		Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Resets = Resets + %d Where memb___id = '%s'",Resets,lpObj->Name);


		lpObj->LevelUpPoint += Points;
		func.UpdateCharacter(lpObj->m_Index,false);
		func.LevelUPSend(lpObj->m_Index);

		ChatTargetSend(lpNpc,"Parabéns Você foi Premiado",lpObj->m_Index);
	}
	else
	{
		ChatTargetSend(lpNpc,"Não posso ajudar no momento",lpObj->m_Index);
		return;
	}
}
