//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 99.60T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "StdAfx.h"

bool cReset::Load()
{
	this->_Active = GetPrivateProfileInt("Reset","Active",1,CFG_RESET) > 0 ? true : false;
	this->_Type = GetPrivateProfileInt("Reset","Type",2,CFG_RESET);
	GetPrivateProfileString("Reset","Sintax","/reset",this->_Syntax,50,CFG_RESET);

	Reset.Acumulativo._Level[0] = GetPrivateProfileInt("Acumulativo","NeedLevelFree",1,CFG_RESET);
	Reset.Acumulativo._Level[1] = GetPrivateProfileInt("Acumulativo","NeedLevelVip1",1,CFG_RESET);
	Reset.Acumulativo._Level[2] = GetPrivateProfileInt("Acumulativo","NeedLevelVip2",1,CFG_RESET);
	Reset.Acumulativo._Level[3] = GetPrivateProfileInt("Acumulativo","NeedLevelVip3",1,CFG_RESET);
	Reset.Acumulativo._Level[4] = GetPrivateProfileInt("Acumulativo","NeedLevelVip4",1,CFG_RESET);
	Reset.Acumulativo._Level[5] = GetPrivateProfileInt("Acumulativo","NeedLevelVip5",1,CFG_RESET);
	Reset.Acumulativo._RemoveItems[0] = GetPrivateProfileInt("Acumulativo","RemoveFree",1,CFG_RESET);
	Reset.Acumulativo._RemoveItems[1] = GetPrivateProfileInt("Acumulativo","RemoveVip1",1,CFG_RESET);
	Reset.Acumulativo._RemoveItems[2] = GetPrivateProfileInt("Acumulativo","RemoveVip2",1,CFG_RESET);
	Reset.Acumulativo._RemoveItems[3] = GetPrivateProfileInt("Acumulativo","RemoveVip3",1,CFG_RESET);
	Reset.Acumulativo._RemoveItems[4] = GetPrivateProfileInt("Acumulativo","RemoveVip4",1, CFG_RESET);
	Reset.Acumulativo._RemoveItems[5] = GetPrivateProfileInt("Acumulativo","RemoveVip5",1, CFG_RESET);
	Reset.Acumulativo._Zen = GetPrivateProfileInt("Acumulativo","NeedZen",1,CFG_RESET);
	Reset.Acumulativo._NextLevel = GetPrivateProfileInt("Acumulativo","ReturnLevel",1,CFG_RESET);
	Reset.Acumulativo._MaxResets = GetPrivateProfileInt("Acumulativo", "MaxResets", 100, CFG_RESET);

	Reset.Pontuativo._Level[0] = GetPrivateProfileInt("Pontuativo","NeedLevelFree",400,CFG_RESET);
	Reset.Pontuativo._Level[1] = GetPrivateProfileInt("Pontuativo","NeedLevelVip1",380,CFG_RESET);
	Reset.Pontuativo._Level[2] = GetPrivateProfileInt("Pontuativo","NeedLevelVip2",350,CFG_RESET);
	Reset.Pontuativo._Level[3] = GetPrivateProfileInt("Pontuativo","NeedLevelVip3",330,CFG_RESET);
	Reset.Pontuativo._Level[4] = GetPrivateProfileInt("Pontuativo","NeedLevelVip4",330,CFG_RESET);
	Reset.Pontuativo._Level[5] = GetPrivateProfileInt("Pontuativo","NeedLevelVip5",330,CFG_RESET);
	Reset.Pontuativo._RemoveItems[0] = GetPrivateProfileInt("Pontuativo","RemoveFree",1,CFG_RESET);
	Reset.Pontuativo._RemoveItems[1] = GetPrivateProfileInt("Pontuativo","RemoveVip1",1,CFG_RESET);
	Reset.Pontuativo._RemoveItems[2] = GetPrivateProfileInt("Pontuativo","RemoveVip2",1,CFG_RESET);
	Reset.Pontuativo._RemoveItems[3] = GetPrivateProfileInt("Pontuativo","RemoveVip3",1,CFG_RESET);
	Reset.Pontuativo._RemoveItems[4] = GetPrivateProfileInt("Pontuativo","RemoveVip4",1,CFG_RESET);
	Reset.Pontuativo._RemoveItems[5] = GetPrivateProfileInt("Pontuativo","RemoveVip5",1,CFG_RESET);
	Reset.Pontuativo._Zen = GetPrivateProfileInt("Pontuativo","NeedZen",1,CFG_RESET);
	Reset.Pontuativo._NextLevel = GetPrivateProfileInt("Pontuativo","ReturnLevel",1,CFG_RESET); 
	Reset.Pontuativo._PointsAdd[0] = GetPrivateProfileInt("Pontuativo","PointsFree",300,CFG_RESET); 
	Reset.Pontuativo._PointsAdd[1] = GetPrivateProfileInt("Pontuativo","PointsVip1",600,CFG_RESET);
	Reset.Pontuativo._PointsAdd[2] = GetPrivateProfileInt("Pontuativo","PointsVip2",700,CFG_RESET);
	Reset.Pontuativo._PointsAdd[3] = GetPrivateProfileInt("Pontuativo","PointsVip3",900,CFG_RESET);
	Reset.Pontuativo._PointsAdd[4] = GetPrivateProfileInt("Pontuativo","PointsVip4",1100,CFG_RESET);
	Reset.Pontuativo._PointsAdd[5] = GetPrivateProfileInt("Pontuativo","PointsVip5",1400,CFG_RESET);
	Reset.Pontuativo._MaxResets = GetPrivateProfileInt("Pontuativo", "MaxResets", 100, CFG_RESET);

	GetPrivateProfileString("Querys","UPDATE RESET","",this->_Query[0],255,CFG_QUERY);
	GetPrivateProfileString("Querys","UPDATE RESET DAY","",this->_Query[1],255,CFG_QUERY);
	GetPrivateProfileString("Querys","UPDATE RESET WEEk","",this->_Query[2],255,CFG_QUERY);
	GetPrivateProfileString("Querys","UPDATE RESET MONTH","",this->_Query[3],255,CFG_QUERY);
	GetPrivateProfileString("Querys", "GET RESETS", "", this->_Query[4], 255, CFG_QUERY);

	return true;
}

bool cReset::CheckItem(LPOBJ lpObj)
{
	for (int i = 0; i < 11; i++)
	{
		if (lpObj->pInventory[i].IsItem())
	    {
		    return false;
	    }
	}

	return true;
}

void cReset::InitExec(int aIndex)
{
	if (!this->_Active)
	{
		func.MsgUser(aIndex,1,"Comando desabilitado.");
		return;
	}
	else
	{
		switch (this->_Type)
		{
		case 1: // Acumulativo
			{
			if (Custom[aIndex].Resets >= Reset.Acumulativo._MaxResets) {
				func.MsgUser(aIndex, 1, "Voce atingiu o maximo de resets %d", Reset.Acumulativo._MaxResets);
				return;
				}
				else if (Reset.Acumulativo._Level[Custom[aIndex].VipIndex] > gObj[aIndex].Level)
				{
					func.MsgUser(aIndex,1,"Você não possui level %d",Reset.Acumulativo._Level[Custom[aIndex].VipIndex]);
					return;
				}
				else if (Reset.Acumulativo._Zen > gObj[aIndex].Money)
				{
					func.MsgUser(aIndex,1,"Você não possui Zen %d",Reset.Acumulativo._Zen);
					return;
				}
				else if (Reset.Acumulativo._RemoveItems[Custom[aIndex].VipIndex] != 0 && !this->CheckItem(&gObj[aIndex]))
				{
					func.MsgUser(aIndex,1,"Remova todos os items para resetar.");
					return;
				}
				else
				{
					Custom[aIndex].Resets		   += 1;
					gObj[aIndex].Money			   -= Reset.Acumulativo._Zen;
					gObj[aIndex].Experience        = 0;
					gObj[aIndex].Level			   = Reset.Acumulativo._NextLevel;
					GCMoneySend(aIndex,gObj[aIndex].Money);

					Manager.ExecFormat(this->_Query[0],gObj[aIndex].Name);
					Manager.ExecFormat(this->_Query[1],gObj[aIndex].Name);
					Manager.ExecFormat(this->_Query[2],gObj[aIndex].Name);
					Manager.ExecFormat(this->_Query[3],gObj[aIndex].Name);

					if (gObj[aIndex].Class == ELF)
					{
						gObjTeleport(aIndex,3,174,114);
					}

					gObj[aIndex].MaxLife = gObj[aIndex].VitalityToLife * gObj[aIndex].Vitality;
					gObj[aIndex].Life = gObj[aIndex].MaxLife;
					gObj[aIndex].AddLife = 0;
					gObj[aIndex].MaxMana = gObj[aIndex].EnergyToMana * gObj[aIndex].Energy;
					gObj[aIndex].Mana = gObj[aIndex].MaxMana;
					gObj[aIndex].AddMana = 0;
					gObjSetBP(aIndex);
					gObj[aIndex].BP = gObj[aIndex].MaxBP;
					gObj[aIndex].AddBP = 0;

					QuestUser[aIndex].Quest_Num = 0;
					QuestUser[aIndex].Quest_kill = 0;
					QuestUser[aIndex].Quest_Start = 0;
					Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Num = %d WHERE Name='%s'", 0, &gObj[aIndex].Name);
					Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Start = 0 WHERE Name='%s'", gObj[aIndex].Name);
					Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Kill = 0 WHERE Name='%s'", gObj[aIndex].Name);

					func.UpdateCharacter(aIndex, true);
					func.MsgUser(aIndex,1,"Resetado com sucesso.");
					func.MsgUser(aIndex, 1, "Resets: %d", Custom[aIndex].Resets);
				}
			}
			break;
		case 2: // Pontuativo
			{
				if (Custom[aIndex].Resets >= Reset.Pontuativo._MaxResets) {
				func.MsgUser(aIndex, 1, "Voce atingiu o maximo de resets %d", Reset.Pontuativo._MaxResets);
				return;
			}
			else if (Reset.Pontuativo._Level[Custom[aIndex].VipIndex] > gObj[aIndex].Level)
				{
					func.MsgUser(aIndex,1,"Você não possui level %d",Reset.Pontuativo._Level[Custom[aIndex].VipIndex]);
					return;
				}
				else if (Reset.Pontuativo._Zen > gObj[aIndex].Money)
				{
					func.MsgUser(aIndex,1,"Você não possui Zen %d",Reset.Pontuativo._Zen);
					return;
				}
				else if (Reset.Acumulativo._RemoveItems[Custom[aIndex].VipIndex] != 0 && !this->CheckItem(&gObj[aIndex]))
				{
					func.MsgUser(aIndex,1,"Remova todos os items para resetar.");
					return;
				}
				else
				{
					gObj[aIndex].LevelUpPoint      = 0;

					Custom[aIndex].Resets		   += 1;
					gObj[aIndex].Money			   -= Reset.Pontuativo._Zen;
					gObj[aIndex].LevelUpPoint	   += Custom[aIndex].Resets * Reset.Pontuativo._PointsAdd[Custom[aIndex].VipIndex];
					gObj[aIndex].Experience        = 0;
					gObj[aIndex].Level			   = Reset.Pontuativo._NextLevel;
					gObj[aIndex].Strength		   = 25;
					gObj[aIndex].Dexterity		   = 25;
					gObj[aIndex].Vitality		   = 25;
					gObj[aIndex].Energy			   = 25;
					gObj[aIndex].Leadership        = 25;
					GCMoneySend(aIndex,gObj[aIndex].Money);

					Manager.ExecFormat(this->_Query[0],gObj[aIndex].Name);
					Manager.ExecFormat(this->_Query[1],gObj[aIndex].Name);
					Manager.ExecFormat(this->_Query[2],gObj[aIndex].Name);
					Manager.ExecFormat(this->_Query[3], gObj[aIndex].Name);

					if (gObj[aIndex].Class == WIZARD || gObj[aIndex].Class == KNIGHT || gObj[aIndex].Class == MAGUMSA || gObj[aIndex].Class == DARKLORD)
					{
						gObjTeleport(aIndex,0,134,128);
					}
					else if (gObj[aIndex].Class == ELF)
					{
						gObjTeleport(aIndex,3,174,114);
					}

					gObj[aIndex].MaxLife = gObj[aIndex].VitalityToLife * gObj[aIndex].Vitality;
					gObj[aIndex].Life = gObj[aIndex].MaxLife;
					gObj[aIndex].AddLife = 0;
					gObj[aIndex].MaxMana = gObj[aIndex].EnergyToMana * gObj[aIndex].Energy;
					gObj[aIndex].Mana = gObj[aIndex].MaxMana;
					gObj[aIndex].AddMana = 0;
					gObjSetBP(aIndex);
					gObj[aIndex].BP = gObj[aIndex].MaxBP;
					gObj[aIndex].AddBP = 0;
					func.ResetQuest(aIndex);
					func.UpdateCharacter(aIndex, true);
					func.MsgUser(aIndex,1,"Resetado com sucesso.");
					func.MsgUser(aIndex, 1, "Resets: %d", Custom[aIndex].Resets);
				}
			}
			break;
		}
	}
}

cReset Reset;