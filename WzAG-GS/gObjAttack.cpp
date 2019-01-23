//###############################################################################################
// Project   :: ACTeaM Classic 0.97d
// GameServer:: 0.96.40				
// Company   :: Advanced CoderZ MU DevelopmenT © 2013
// Revised   :: 17/01/2014
// Coded     :: Mr.Haziel Developer								
//###############################################################################################

#include "StdAfx.h"

GOBJATTACK  pObjAttack;

void ReadygObjAttack()
{
	AttackConfigs();
	func.HookThis((DWORD)&gObjAttackEX, 0x00405E7A);
}

void AttackConfigs()
{
	pObjAttack.A_NonPK = GetPrivateProfileIntA("PVPSystem", "NonPVP", 0, CFG_PVPSystem);
	pObjAttack.A_NonGM = GetPrivateProfileIntA("Fixes", "GMDamage", 0, CFG_PVPSystem);

	pObjAttack.A_AltoReset = GetPrivateProfileIntA("ResetSystem", "Automatic", 0, CFG_PVPSystem);

	pObjAttack.A_Attack = GetPrivateProfileIntA("PVPSystem", "Switch", 0, CFG_PVPSystem);
	pObjAttack.A_Lorencia = GetPrivateProfileIntA("PVPSystem", "Lorencia", 1, CFG_PVPSystem);
	pObjAttack.A_Dungeon = GetPrivateProfileIntA("PVPSystem", "Dungeon", 1, CFG_PVPSystem);
	pObjAttack.A_Davias = GetPrivateProfileIntA("PVPSystem", "Devias", 1, CFG_PVPSystem);
	pObjAttack.A_Noria = GetPrivateProfileIntA("PVPSystem", "Noria", 1, CFG_PVPSystem);
	pObjAttack.A_LostTower = GetPrivateProfileIntA("PVPSystem", "Losttower", 1, CFG_PVPSystem);
	pObjAttack.A_Stadium = GetPrivateProfileIntA("PVPSystem", "Stadium", 1, CFG_PVPSystem);
	pObjAttack.A_Atlans = GetPrivateProfileIntA("PVPSystem", "Atlans", 1, CFG_PVPSystem);
	pObjAttack.A_Tarkan = GetPrivateProfileIntA("PVPSystem", "Tarkan", 1, CFG_PVPSystem);
	pObjAttack.A_Icarus = GetPrivateProfileIntA("PVPSystem", "Icarus", 1, CFG_PVPSystem);
	/*
	pObjAttack.A_New17 = GetPrivateProfileIntA("PVPSystem", "NewMap17", 1, CFG_PVPSystem);
	pObjAttack.A_New18 = GetPrivateProfileIntA("PVPSystem", "NewMap18", 1, CFG_PVPSystem);
	pObjAttack.A_New19 = GetPrivateProfileIntA("PVPSystem", "NewMap19", 1, CFG_PVPSystem);
	pObjAttack.A_New20 = GetPrivateProfileIntA("PVPSystem", "NewMap20", 1, CFG_PVPSystem);
	pObjAttack.A_New21 = GetPrivateProfileIntA("PVPSystem", "NewMap21", 1, CFG_PVPSystem);
	pObjAttack.A_New22 = GetPrivateProfileIntA("PVPSystem", "NewMap22", 1, CFG_PVPSystem);
	pObjAttack.A_New23 = GetPrivateProfileIntA("PVPSystem", "NewMap23", 1, CFG_PVPSystem);
	pObjAttack.A_New24 = GetPrivateProfileIntA("PVPSystem", "NewMap24", 1, CFG_PVPSystem);
	*/
}





bool gObjAttackEX(OBJECTSTRUCT* lpObj, OBJECTSTRUCT* lpTargetObj, void * lpMagic, BOOL magicsend, BYTE MSBFlag, int AttackDamage)
{

	if (lpTargetObj->Type == OBJECT_MONSTER)
	{

		////////////////////////////////////////
		//-- BOSS MEDUSA DROP JEWEL           //
		////////////////////////////////////////
		srand(static_cast<int>(time(NULL)));
		int MedusaRand = (rand() % 100);

		if (eMedusa.IsMedusa != 0)
		{
			if (lpTargetObj->Class == 49)
			{
				if (MedusaRand > 96)
				{
					ChatTargetSend(lpTargetObj, "Oh Não! Perdi uma bless", lpObj->m_Index);
					ItemSerialCreateSend(lpObj->m_Index, lpObj->MapNumber, lpObj->X, lpObj->Y, ITEMGET(14, 13), 0, 0, 0, 0, 0, -1, 0);
				}
				if (MedusaRand > 97)
				{
					ChatTargetSend(lpTargetObj, "Oh Não! ,Perdi uma Soul", lpObj->m_Index);
					ItemSerialCreateSend(lpObj->m_Index, lpObj->MapNumber, lpObj->X, lpObj->Y, ITEMGET(14, 14), 0, 0, 0, 0, 0, -1, 0);
				}
				if (MedusaRand > 95)
				{
					ChatTargetSend(lpTargetObj, "Oh Não! ,Perdi uma chaos", lpObj->m_Index);
					ItemSerialCreateSend(lpObj->m_Index, lpObj->MapNumber, lpObj->X, lpObj->Y, ITEMGET(12, 15), 0, 0, 0, 0, 0, -1, 0);
				}
			}
		}

		if (pObjAttack.A_AltoReset != 0)
		{
			if (epObj[lpObj->m_Index].m_Vip == 0 && lpObj->Level >= pReset.LevelRequiredtoResetNrl)
			{
				ResetSystemExecult(lpObj->m_Index); //-- ReseteSystem.CPP
				return true;
			}

			if (epObj[lpObj->m_Index].m_Vip == 1 && lpObj->Level >= pReset.LevelRequiredtoResetVIP_1)
			{
				ResetSystemExecult(lpObj->m_Index); //-- ReseteSystem.CPP
				return true;
			}

			if (epObj[lpObj->m_Index].m_Vip == 2 && lpObj->Level >= pReset.LevelRequiredtoResetVIP_2)
			{
				ResetSystemExecult(lpObj->m_Index); //-- ReseteSystem.CPP
				return true;
			}

			if (epObj[lpObj->m_Index].m_Vip == 3 && lpObj->Level >= pReset.LevelRequiredtoResetVIP_3)
			{
				ResetSystemExecult(lpObj->m_Index); //-- ReseteSystem.CPP
				return true;
			}
		}

	}

	//===================================================
	//-- Gens System  
	//===================================================
	if (pGens.ISGENS != FALSE)
	{
		if (GensDisplay(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage) != true)
		{
			return true;
		}
	}

	if (lpObj->Type == OBJECT_USER && lpTargetObj->Type == OBJECT_USER)
	{

		//=========================================================
		//-- Fix Room Non PK
		//=========================================================
		if (pObjAttack.A_NonPK != 0)
		{
			return true;
		}
		//=========================================================
		//--Duel System NO PVP
		//=========================================================
		if (DuelSystem.ISDUEL != 0)
		{
			if (lpObj->MapNumber == DuelSystem.Duel_Map && epObj[lpObj->m_Index].m_Duel_PVP == FALSE)
			{
				return true;
			}
			if (lpTargetObj->MapNumber == DuelSystem.Duel_Map && epObj[lpTargetObj->m_Index].m_Duel_PVP == FALSE)
			{
				return true;
			}
		}
		//=========================================================
		//-- Fix Bug Dino 
		//=========================================================
		short Type = lpObj->pInventory[8].m_Type;
		if (!((Type >= ITEMGET(13, 0) && Type <= ITEMGET(13, 5)) || Type == ITEMGET(13, 37)))
		{
			GCInventoryItemDeleteSend(lpObj->m_Index, 8, 0);
		}

		//=========================================================
		//-- Fix Kinighth Bug Far Attack
		//=========================================================
		/*	    if(lpObj->Class == CLASS_KNIGHT && pAntiHacker.IsTsHacker != FALSE )
		{
		int X = lpObj->X - lpTargetObj->X;
		int Y = lpObj->Y - lpTargetObj->Y;
		int Distance = X + Y / 2;

		if( Distance > 2 || Distance < - 1)
		{
		//GCDamageSend(lpObj->m_Index,lpTargetObj->m_Index, 0, 0, 0, 0);
		return true;
		}
		}

		//=========================================================
		//-- Zumbi Hack Bug
		//=========================================================
		if(lpObj->DieRegen != 0 || lpTargetObj->DieRegen != 0 )
		{
		//GCDamageSend(lpObj->m_Index,lpTargetObj->m_Index, 0, 0, 0, 0); // MISS
		//AntiHackerLog(lpObj->m_Index,"Was using Zumbi Hack Bug!");
		return true;
		}

		//=========================================================
		//-- Game Master no PVP
		//=========================================================
		if(lpObj->Authority > 1 && pObjAttack.A_NonGM != 0 )
		{
		GCDamageSend(lpObj->m_Index,lpTargetObj->m_Index, 0, 0, 0, 0);
		return true;
		}

		//=========================================================
		//-- Speed Hacker
		//=========================================================
		if(epObj[lpObj->m_Index].BlockAttack != 0 )
		{
		GCDamageSend(lpObj->m_Index,lpTargetObj->m_Index, 0, 0, 0, 0);
		return true;
		} */

		//=========================================================
		//-- Map PVP System 
		//=========================================================
		if (pObjAttack.A_Attack != 0)
		{
			if (lpObj->MapNumber == 0 && pObjAttack.A_Lorencia == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			if (lpObj->MapNumber == 1 && pObjAttack.A_Dungeon == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			if (lpObj->MapNumber == 2 && pObjAttack.A_Davias == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			if (lpObj->MapNumber == 3 && pObjAttack.A_Noria == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			if (lpObj->MapNumber == 4 && pObjAttack.A_LostTower == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			if (lpObj->MapNumber == 6 && pObjAttack.A_Stadium == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			if (lpObj->MapNumber == 7 && pObjAttack.A_Atlans == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			if (lpObj->MapNumber == 8 && pObjAttack.A_Tarkan == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			if (lpObj->MapNumber == 9 && pObjAttack.A_Icarus == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			//=========================================================
			// New maps 
			//=========================================================
			if (lpObj->MapNumber == 17 && pObjAttack.A_New17 == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			if (lpObj->MapNumber == 18 && pObjAttack.A_New18 == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			if (lpObj->MapNumber == 19 && pObjAttack.A_New19 == 0)
			{
				GCServerMsgStringSend("PVP está desativado neste mapa!", lpObj->m_Index, 1);
				return true;
			}
			if (lpObj->MapNumber == 20 && pObjAttack.A_New20 == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			if (lpObj->MapNumber == 21 && pObjAttack.A_New21 == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			if (lpObj->MapNumber == 22 && pObjAttack.A_New22 == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			if (lpObj->MapNumber == 23 && pObjAttack.A_New23 == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
			if (lpObj->MapNumber == 24 && pObjAttack.A_New24 == 0)
			{
				MsgOutput(lpObj->m_Index, "%s PVP está desativado neste mapa ", lpObj->Name);
				return true;
			}
		}

	}

	gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage);

	return false;

}