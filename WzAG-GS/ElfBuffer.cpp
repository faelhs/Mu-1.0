#include "StdAfx.h"

int NpcShadowPhantomEx(OBJECTSTRUCT *lpNpc, OBJECTSTRUCT *lpObj)
{

	int Time = GetPrivateProfileInt("ShadowPhantom ", "Tempo do Buff", 60,  CFG_SHADOWF);
	int MaxReset = GetPrivateProfileInt("ShadowPhantom", "Max Reset", 100, CFG_SHADOWF);
	int MaxLevel = GetPrivateProfileInt("ShadowPhantom", "Max Level", 400, CFG_SHADOWF);
	int Attack = GetPrivateProfileInt("ShadowPhantom", "Add Attack", 1000, CFG_SHADOWF);
	int Defense = GetPrivateProfileInt("ShadowPhantom", "Add Defense", 1000, CFG_SHADOWF);
	int Life = GetPrivateProfileInt("ShadowPhantom", "Add Life", 1000, CFG_SHADOWF);
	int ManaDef = GetPrivateProfileInt("ShadowPhantom", "Mana Shield Def", 100, CFG_SHADOWF);
	int MaxDef = GetPrivateProfileInt("ShadowPhantom", "Mana Shield MaxDef", 500, CFG_SHADOWF);
	int CritDmg = GetPrivateProfileInt("ShadowPhantom", "Critical Damage", 1000, CFG_SHADOWF);
	bool ifLife = GetPrivateProfileInt("ShadowPhantom", "Life Active", 1, CFG_COMMAND) > 0 ? true : false;
	bool ifMana = GetPrivateProfileInt("ShadowPhantom", "ManaShield Active", 1, CFG_COMMAND) > 0 ? true : false;
	bool ifCrit = GetPrivateProfileInt("ShadowPhantom", "CriticalDamage Active", 1, CFG_COMMAND) > 0 ? true : false;
	int result;
	int Resets = Manager.CountResets(&lpObj->Name[0]);

	if (gObjIsConnected2(lpObj->m_Index))

		if (Resets <= MaxReset)
			if (lpObj->Level <= MaxLevel)
			{
				int result; 	

				lpObj->m_SkillAttackTime	= Time * 60000;
				lpObj->m_SkillDefense		= Attack;
				lpObj->m_SkillAttack		= Attack;
				lpObj->m_ViewSkillState		|= 0x2000000;
				lpObj->m_SkillDefense		= (float)(10 + 1) * 2 + (lpObj->Energy / 2);

				lpObj->m_SkillDefense		= Defense;
				lpObj->m_ViewSkillState		|= 0x8u;
				lpObj->m_SkillDefenseTime	= Time * 60000;
				
				GCStateInfoSend((DWORD)&lpObj->m_Index, 1, lpObj->m_ViewSkillState);
				//test.
				if (ifLife) {
					lpObj->AddLife -= lpObj->m_SkillAddLife;
					if (lpObj->AddLife < 0)
						lpObj->AddLife = 0;
					lpObj->m_SkillAddLife = Life;
					lpObj->AddLife += lpObj->m_SkillAddLife;
					lpObj->m_SkillAddLifeTime = Time * 60000;
					GCMagicAttackNumberSend(&gObj[lpObj->m_Index], AT_SKILL_KNIGHTADDLIFE, lpObj->m_Index, 1);
					gObj[lpObj->m_Index].m_ViewSkillState |= 16;
					GCReFillSend(lpObj->m_Index, lpObj->MaxLife + lpObj->AddLife, 0xFE, 0);
				}
				if (ifMana) {
					lpObj->m_WizardSkillDefense = ManaDef;
					if (lpObj->m_WizardSkillDefense > MaxDef)
						lpObj->m_WizardSkillDefense = MaxDef;
					lpObj->m_WizardSkillDefenseTime = Time * 60000;
					lpObj->m_ViewSkillState |= 256;
					GCMagicAttackNumberSend(&gObj[lpObj->m_Index], AT_SKILL_MAGICDEFENSE, lpObj->m_Index, 1);
				}
				if (ifCrit) {
					if (lpObj->SkillAddCriticalDamageTime <= 0)
					{
						int addcriticaldamagevalue = CritDmg;
						lpObj->SkillAddCriticalDamage = addcriticaldamagevalue;
						lpObj->SkillAddCriticalDamageTime = Time * 60000;
						lpObj->m_ViewSkillState |= 2048;
						GCMagicAttackNumberSend(&gObj[lpObj->m_Index], AT_SKILL_ADD_CRITICALDAMAGE, lpObj->m_Index, 1);
					}
				}
				result = 1;
			}
			else
			{

				GCServerCmd(lpObj->m_Index, 13, 0, 0);

				result = 1;
			}
		else
		{
			result = 1;
		}
		return result;
}

