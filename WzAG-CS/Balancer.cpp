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

CBalancer::CBalancer() : Character()
{
}

CBalancer::~CBalancer()
{
}

void CBalancer::LoadSettings()
{
	Character.WizardAttack[0] = GetPrivateProfileIntA("Character","SM.RightDamageMin",6,CFG_CHARACTER);
	Character.WizardAttack[1] = GetPrivateProfileIntA("Character","SM.RightDamageMax",4,CFG_CHARACTER);
	Character.WizardAttack[2] = GetPrivateProfileIntA("Character","SM.LeftDamageMin",6,CFG_CHARACTER);
	Character.WizardAttack[3] = GetPrivateProfileIntA("Character","SM.LeftDamageMax",4,CFG_CHARACTER);
	Character.AttackSpeed[0] = GetPrivateProfileIntA("Character","SM.AttackSpeed",15,CFG_CHARACTER);
	Character.MagicSpeed[0] = GetPrivateProfileIntA("Character","SM.MagicSpeed",20,CFG_CHARACTER);
	Character.Defense[0] = GetPrivateProfileIntA("Character","SM.Defense",4,CFG_CHARACTER);
	Character.SuccessfulBlocking[0] = GetPrivateProfileIntA("Character","SM.SuccessfulBlocking",3,CFG_CHARACTER);
	Character.MagicDamageMin[0] = GetPrivateProfileIntA("Character","SM.MagicDamageMin",9,CFG_CHARACTER);
	Character.MagicDamageMax[0] = GetPrivateProfileIntA("Character","SM.MagicDamageMax",4,CFG_CHARACTER);

	Character.KnightAttack[0] = GetPrivateProfileIntA("Character","BK.RightDamageMin",6,CFG_CHARACTER);
	Character.KnightAttack[1] = GetPrivateProfileIntA("Character","BK.RightDamageMax",4,CFG_CHARACTER);
	Character.KnightAttack[2] = GetPrivateProfileIntA("Character","BK.LeftDamageMin",6,CFG_CHARACTER);
	Character.KnightAttack[3] = GetPrivateProfileIntA("Character","BK.LeftDamageMax",4,CFG_CHARACTER);
	Character.AttackSpeed[1] = GetPrivateProfileIntA("Character","BK.AttackSpeed",15,CFG_CHARACTER);
	Character.MagicSpeed[1] = GetPrivateProfileIntA("Character","BK.MagicSpeed",20,CFG_CHARACTER);
	Character.Defense[1] = GetPrivateProfileIntA("Character","BK.Defense",3,CFG_CHARACTER);
	Character.SuccessfulBlocking[1] = GetPrivateProfileIntA("Character","BK.SuccessfulBlocking",3,CFG_CHARACTER);
	Character.MagicDamageMin[1] = GetPrivateProfileIntA("Character","BK.MagicDamageMin",9,CFG_CHARACTER);
	Character.MagicDamageMax[1] = GetPrivateProfileIntA("Character","BK.MagicDamageMax",4,CFG_CHARACTER);

	Character.ElfAttack[0] = GetPrivateProfileIntA("Character","ME.RightDamageMin",7,CFG_CHARACTER);
	Character.ElfAttack[1] = GetPrivateProfileIntA("Character","ME.RightDamageMax",4,CFG_CHARACTER);
	Character.ElfAttack[2] = GetPrivateProfileIntA("Character","ME.LeftDamageMin",7,CFG_CHARACTER);
	Character.ElfAttack[3] = GetPrivateProfileIntA("Character","ME.LeftDamageMax",4,CFG_CHARACTER);
	Character.ElfAttack[4] = GetPrivateProfileIntA("Character","ME.RightDamageMin2",7,CFG_CHARACTER);
	Character.ElfAttack[5] = GetPrivateProfileIntA("Character","ME.RightDamageMax2",4,CFG_CHARACTER);
	Character.ElfAttack[6] = GetPrivateProfileIntA("Character","ME.LeftDamageMin2",7,CFG_CHARACTER);
	Character.ElfAttack[7] = GetPrivateProfileIntA("Character","ME.LeftDamageMax2",4,CFG_CHARACTER);
	Character.ElfAttack[8] = GetPrivateProfileIntA("Character","ME.RightDamageMin3",14,CFG_CHARACTER);
	Character.ElfAttack[9] = GetPrivateProfileIntA("Character","ME.RightDamageMax3",8,CFG_CHARACTER);
	Character.ElfAttack[10] = GetPrivateProfileIntA("Character","ME.LeftDamageMin3",14,CFG_CHARACTER);
	Character.ElfAttack[11] = GetPrivateProfileIntA("Character","ME.LeftDamageMax3",8,CFG_CHARACTER);
	Character.ElfAttack[12] = GetPrivateProfileIntA("Character","ME.RightDamageMin4",7,CFG_CHARACTER);
	Character.ElfAttack[13] = GetPrivateProfileIntA("Character","ME.RightDamageMax4",4,CFG_CHARACTER);
	Character.ElfAttack[14] = GetPrivateProfileIntA("Character","ME.LeftDamageMin4",7,CFG_CHARACTER);
	Character.ElfAttack[15] = GetPrivateProfileIntA("Character","ME.LeftDamageMax4",4,CFG_CHARACTER);
	Character.AttackSpeed[2] = GetPrivateProfileIntA("Character","ME.AttackSpeed",50,CFG_CHARACTER);
	Character.MagicSpeed[2] = GetPrivateProfileIntA("Character","ME.MagicSpeed",50,CFG_CHARACTER);
	Character.Defense[2] = GetPrivateProfileIntA("Character","ME.Defense",10,CFG_CHARACTER);
	Character.SuccessfulBlocking[2] = GetPrivateProfileIntA("Character","ME.SuccessfulBlocking",4,CFG_CHARACTER);
	Character.MagicDamageMin[2] = GetPrivateProfileIntA("Character","ME.MagicDamageMin",9,CFG_CHARACTER);
	Character.MagicDamageMax[2] = GetPrivateProfileIntA("Character","ME.MagicDamageMax",4,CFG_CHARACTER);

	Character.GladiatorAttack[0] = GetPrivateProfileIntA("Character","MG.RightDamageMin",6,CFG_CHARACTER);
	Character.GladiatorAttack[1] = GetPrivateProfileIntA("Character","MG.RightDamageMax",4,CFG_CHARACTER);
	Character.GladiatorAttack[2] = GetPrivateProfileIntA("Character","MG.LeftDamageMin",6,CFG_CHARACTER);
	Character.GladiatorAttack[3] = GetPrivateProfileIntA("Character","MG.LeftDamageMax",4,CFG_CHARACTER);
	Character.GladiatorAttack[4] = GetPrivateProfileIntA("Character","MG.RightDamageMin2",12,CFG_CHARACTER);
	Character.GladiatorAttack[5] = GetPrivateProfileIntA("Character","MG.RightDamageMax2",8,CFG_CHARACTER);
	Character.GladiatorAttack[6] = GetPrivateProfileIntA("Character","MG.LeftDamageMin2",12,CFG_CHARACTER);
	Character.GladiatorAttack[7] = GetPrivateProfileIntA("Character","MG.LeftDamageMax2",8,CFG_CHARACTER);
	Character.AttackSpeed[3] = GetPrivateProfileIntA("Character","MG.AttackSpeed",15,CFG_CHARACTER);
	Character.MagicSpeed[3] = GetPrivateProfileIntA("Character","MG.MagicSpeed",20,CFG_CHARACTER);
	Character.Defense[3] = GetPrivateProfileIntA("Character","MG.Defense",4,CFG_CHARACTER);
	Character.SuccessfulBlocking[3] = GetPrivateProfileIntA("Character","MG.SuccessfulBlocking",3,CFG_CHARACTER);
	Character.MagicDamageMin[3] = GetPrivateProfileIntA("Character","MG.MagicDamageMin",9,CFG_CHARACTER);
	Character.MagicDamageMax[3] = GetPrivateProfileIntA("Character","MG.MagicDamageMax",4,CFG_CHARACTER);

	Character.LordAttack[0] = GetPrivateProfileIntA("Character","DL.RightDamageMin",7,CFG_CHARACTER);
	Character.LordAttack[1] = GetPrivateProfileIntA("Character","DL.RightDamageMax",5,CFG_CHARACTER);
	Character.LordAttack[2] = GetPrivateProfileIntA("Character","DL.LeftDamageMin",7,CFG_CHARACTER);
	Character.LordAttack[3] = GetPrivateProfileIntA("Character","DL.LeftDamageMax",5,CFG_CHARACTER);
	Character.LordAttack[4] = GetPrivateProfileIntA("Character","DL.RightDamageMin2",14,CFG_CHARACTER);
	Character.LordAttack[5] = GetPrivateProfileIntA("Character","DL.RightDamageMax2",10,CFG_CHARACTER);
	Character.LordAttack[6] = GetPrivateProfileIntA("Character","DL.LeftDamageMin2",14,CFG_CHARACTER);
	Character.LordAttack[7] = GetPrivateProfileIntA("Character","DL.LeftDamageMax2",10,CFG_CHARACTER);
	Character.AttackSpeed[4] = GetPrivateProfileIntA("Character","DL.AttackSpeed",10,CFG_CHARACTER);
	Character.MagicSpeed[4] = GetPrivateProfileIntA("Character","DL.MagicSpeed",10,CFG_CHARACTER);
	Character.Defense[4] = GetPrivateProfileIntA("Character","DL.Defense",7,CFG_CHARACTER);
	Character.SuccessfulBlocking[4] = GetPrivateProfileIntA("Character","DL.SuccessfulBlocking",7,CFG_CHARACTER);
	Character.MagicDamageMin[4] = GetPrivateProfileIntA("Character","DL.MagicDamageMin",9,CFG_CHARACTER);
	Character.MagicDamageMax[4] = GetPrivateProfileIntA("Character","DL.MagicDamageMax",4,CFG_CHARACTER);
}

CBalancer Balancer;

void CBalancer::gObjCalCharacter(int aIndex)
{
	int Strength = 0;
	int Dexterity = 0;
	int Vitality = 0;
	int Energy = 0;

	CItem * Right = &gObj[aIndex].pInventory[0];
	CItem * Left = &gObj[aIndex].pInventory[1];
	CItem * Gloves = &gObj[aIndex].pInventory[5];
	CItem * Amulet = &gObj[aIndex].pInventory[9];
	CItem * Helper = &gObj[aIndex].pInventory[8];
	gObj[aIndex].HaveWeaponInHand = true;

	if (Right->IsItem() == FALSE && Left->IsItem() == FALSE)
	{
		gObj[aIndex].HaveWeaponInHand = false;
	}
	else if (Left->IsItem() == FALSE && Right->m_Type == ITEMGET(4, 15))
	{
		gObj[aIndex].HaveWeaponInHand = false;
	}
	else if (Right->IsItem() == FALSE)
	{
		int iType = Left->m_Type / 32;

		if (Left->m_Type == ITEMGET(4, 7))
		{
			gObj[aIndex].HaveWeaponInHand = false;
		}
		else if (iType == 6)
		{
			gObj[aIndex].HaveWeaponInHand = false;
		}
	}

	gObj[aIndex].AddLife = 0;
	gObj[aIndex].AddMana = 0;
	gObj[aIndex].MonsterDieGetMoney = 0;
	gObj[aIndex].MonsterDieGetLife = 0;
	gObj[aIndex].MonsterDieGetMana = 0;
	gObj[aIndex].DamageReflect = 0;
	gObj[aIndex].DamageMinus = 0;
	gObj[aIndex].SkillLongSpearChange = false;

	int iItemIndex;
	BOOL bIsChangeItem;

	for (iItemIndex = 0; iItemIndex < 12; iItemIndex++)
	{
		if (gObj[aIndex].pInventory[iItemIndex].IsItem() != FALSE)
		{
			gObj[aIndex].pInventory[iItemIndex].m_IsValidItem = true;
		}
	}

	do
	{
		gObj[aIndex].SetOpAddMaxAttackDamage = 0;
		gObj[aIndex].SetOpAddMinAttackDamage = 0;
		gObj[aIndex].SetOpAddDamage = 0;
		gObj[aIndex].SetOpIncAGValue = 0;
		gObj[aIndex].SetOpAddCriticalDamageSuccessRate = 0;
		gObj[aIndex].SetOpAddCriticalDamage = 0;
		gObj[aIndex].SetOpAddExDamageSuccessRate = 0;
		gObj[aIndex].SetOpAddExDamage = 0;
		gObj[aIndex].SetOpAddSkillAttack = 0;
		gObj[aIndex].AddStrength = 0;
		gObj[aIndex].AddDexterity = 0;
		gObj[aIndex].AddVitality = 0;
		gObj[aIndex].AddEnergy = 0;
		gObj[aIndex].AddBP = 0;
		gObj[aIndex].SetOpAddAttackDamage = 0;
		gObj[aIndex].SetOpAddDefence = 0;
		gObj[aIndex].SetOpAddMagicPower = 0;
		gObj[aIndex].SetOpAddDefenceRate = 0;
		gObj[aIndex].SetOpIgnoreDefense = 0;
		gObj[aIndex].SetOpDoubleDamage = 0;
		gObj[aIndex].SetOpTwoHandSwordImproveDamage = 0;
		gObj[aIndex].SetOpImproveSuccessAttackRate = 0;
		gObj[aIndex].SetOpReflectionDamage = 0;
		gObj[aIndex].SetOpImproveSheldDefence = 0;
		gObj[aIndex].SetOpDecreaseAG = 0;
		gObj[aIndex].SetOpImproveItemDropRate = 0;
		gObj[aIndex].IsFullSetItem = false;
		memset(gObj[aIndex].m_AddResistance, 0, sizeof(gObj[aIndex].m_AddResistance));
		bIsChangeItem = 0;
		gObjCalcSetItemStat(&gObj[aIndex]);
		gObjCalcSetItemOption(&gObj[aIndex]);

		for (iItemIndex = 0; iItemIndex < 12; iItemIndex++)
		{
			if (gObj[aIndex].pInventory[iItemIndex].IsItem() != FALSE && gObj[aIndex].pInventory[iItemIndex].m_IsValidItem != false)
			{
				if (gObjValidItem(&gObj[aIndex], &gObj[aIndex].pInventory[iItemIndex], iItemIndex) != FALSE)
				{
					gObj[aIndex].pInventory[iItemIndex].m_IsValidItem = true;
				}
				else
				{
					gObj[aIndex].pInventory[iItemIndex].m_IsValidItem = false;
					bIsChangeItem = TRUE;
				}
			}
		}
	} 

    while (bIsChangeItem != FALSE);

	Strength = gObj[aIndex].Strength + gObj[aIndex].AddStrength;
	Dexterity = gObj[aIndex].Dexterity + gObj[aIndex].AddDexterity;
	Vitality = gObj[aIndex].Vitality + gObj[aIndex].AddVitality;
	Energy = gObj[aIndex].Energy + gObj[aIndex].AddEnergy;

	switch (gObj[aIndex].Class)
	{
	case WIZARD:
		{
			gObj[aIndex].m_AttackDamageMinRight = Strength / Balancer.Character.WizardAttack[0];
			gObj[aIndex].m_AttackDamageMaxRight = Strength / Balancer.Character.WizardAttack[1];
			gObj[aIndex].m_AttackDamageMinLeft = Strength / Balancer.Character.WizardAttack[2];
			gObj[aIndex].m_AttackDamageMaxLeft = Strength / Balancer.Character.WizardAttack[3];
		}
		break;
	case KNIGHT:
		{
			gObj[aIndex].m_AttackDamageMinRight = Strength / Balancer.Character.KnightAttack[0];
			gObj[aIndex].m_AttackDamageMaxRight = Strength / Balancer.Character.KnightAttack[1];
			gObj[aIndex].m_AttackDamageMinLeft = Strength / Balancer.Character.KnightAttack[2];
			gObj[aIndex].m_AttackDamageMaxLeft = Strength / Balancer.Character.KnightAttack[3];
		}
		break;
	case ELF:
		{
			if ((Right->m_Type >= ITEMGET(4, 8) && Right->m_Type < ITEMGET(4, 15)) || (Left->m_Type >= ITEMGET(4, 0) && Left->m_Type < ITEMGET(4, 7)) || Right->m_Type == ITEMGET(4, 16) || Left->m_Type == ITEMGET(4, 20) || Left->m_Type == ITEMGET(4, 21) || Right->m_Type == ITEMGET(4, 18) || Right->m_Type == ITEMGET(4, 19) || Left->m_Type == ITEMGET(4, 17))
			{
				if ((Right->IsItem() != FALSE && Right->m_IsValidItem == false) || (Left->IsItem() != FALSE && Left->m_IsValidItem == false))
				{
					gObj[aIndex].m_AttackDamageMinRight = (Dexterity + Strength) / Balancer.Character.ElfAttack[0];
					gObj[aIndex].m_AttackDamageMaxRight = (Dexterity + Strength) / Balancer.Character.ElfAttack[1];
					gObj[aIndex].m_AttackDamageMinLeft = (Dexterity + Strength) / Balancer.Character.ElfAttack[2];
					gObj[aIndex].m_AttackDamageMaxLeft = (Dexterity + Strength) / Balancer.Character.ElfAttack[3];
				}
				else
				{
					gObj[aIndex].m_AttackDamageMinRight = (Dexterity / Balancer.Character.ElfAttack[4]) + (Strength / Balancer.Character.ElfAttack[8]);
					gObj[aIndex].m_AttackDamageMaxRight = (Dexterity / Balancer.Character.ElfAttack[5]) + (Strength / Balancer.Character.ElfAttack[9]);
					gObj[aIndex].m_AttackDamageMinLeft = (Dexterity / Balancer.Character.ElfAttack[6]) + (Strength / Balancer.Character.ElfAttack[10]);
					gObj[aIndex].m_AttackDamageMaxLeft = (Dexterity / Balancer.Character.ElfAttack[7]) + (Strength / Balancer.Character.ElfAttack[11]);
				}
			}
			else
			{
				gObj[aIndex].m_AttackDamageMinRight = (Dexterity + Strength) / Balancer.Character.ElfAttack[12];
				gObj[aIndex].m_AttackDamageMaxRight = (Dexterity + Strength) / Balancer.Character.ElfAttack[13];
				gObj[aIndex].m_AttackDamageMinLeft = (Dexterity + Strength) / Balancer.Character.ElfAttack[14];
				gObj[aIndex].m_AttackDamageMaxLeft = (Dexterity + Strength) / Balancer.Character.ElfAttack[15];
			}
		}
		break;
	case MAGUMSA:
		{
			gObj[aIndex].m_AttackDamageMinRight = (Strength / Balancer.Character.GladiatorAttack[0]) + (Energy / Balancer.Character.GladiatorAttack[4]);
			gObj[aIndex].m_AttackDamageMaxRight = (Strength / Balancer.Character.GladiatorAttack[1]) + (Energy / Balancer.Character.GladiatorAttack[5]);
			gObj[aIndex].m_AttackDamageMinLeft = (Strength / Balancer.Character.GladiatorAttack[2]) + (Energy / Balancer.Character.GladiatorAttack[6]);
			gObj[aIndex].m_AttackDamageMaxLeft = (Strength / Balancer.Character.GladiatorAttack[3]) + (Energy / Balancer.Character.GladiatorAttack[7]);
		}
		break;
	case DARKLORD:
		{
			gObj[aIndex].m_AttackDamageMinRight = (Strength / Balancer.Character.LordAttack[0]) + (Energy / Balancer.Character.LordAttack[4]);
			gObj[aIndex].m_AttackDamageMaxRight = (Strength / Balancer.Character.LordAttack[1]) + (Energy / Balancer.Character.LordAttack[5]);
			gObj[aIndex].m_AttackDamageMinLeft = (Strength / Balancer.Character.LordAttack[2]) + (Energy / Balancer.Character.LordAttack[6]);
			gObj[aIndex].m_AttackDamageMaxLeft = (Strength / Balancer.Character.LordAttack[3]) + (Energy / Balancer.Character.LordAttack[7]);
		}
		break;
	}

	gObj[aIndex].pInventory[7].PlusSpecial(&gObj[aIndex].m_AttackDamageMinRight, 80);
	gObj[aIndex].pInventory[7].PlusSpecial(&gObj[aIndex].m_AttackDamageMaxRight, 80);
	gObj[aIndex].pInventory[7].PlusSpecial(&gObj[aIndex].m_AttackDamageMinLeft, 80);
	gObj[aIndex].pInventory[7].PlusSpecial(&gObj[aIndex].m_AttackDamageMaxLeft, 80);

	int AddLeadership = 0;

	if (gObj[aIndex].pInventory[7].IsItem() != FALSE && gObj[aIndex].pInventory[7].m_IsValidItem != false)
	{
		AddLeadership += gObj[aIndex].pInventory[7].m_Leadership;
	}

	if (Right->m_Type != -1)
	{
		if (Right->m_IsValidItem != false)
		{
			if (Right->m_Type >= ITEMGET(5, 0) && Right->m_Type <= ITEMGET(6, 0))
			{
				gObj[aIndex].m_AttackDamageMinRight += Right->m_DamageMin / 2;
				gObj[aIndex].m_AttackDamageMaxRight += Right->m_DamageMax / 2;
			}
			else
			{
				gObj[aIndex].m_AttackDamageMinRight += Right->m_DamageMin;
				gObj[aIndex].m_AttackDamageMaxRight += Right->m_DamageMax;
			}
		}

		if (gObj[aIndex].pInventory[0].m_SkillChange != FALSE)
		{
			gObj[aIndex].SkillLongSpearChange = true;
		}

		gObj[aIndex].pInventory[0].PlusSpecial(&gObj[aIndex].m_AttackDamageMinRight, 80);
		gObj[aIndex].pInventory[0].PlusSpecial(&gObj[aIndex].m_AttackDamageMaxRight, 80);
	}

	if (Left->m_Type != -1)
	{
		if (Left->m_IsValidItem != false)
		{
			gObj[aIndex].m_AttackDamageMinLeft += Left->m_DamageMin;
			gObj[aIndex].m_AttackDamageMaxLeft += Left->m_DamageMax;
		}

		gObj[aIndex].pInventory[1].PlusSpecial(&gObj[aIndex].m_AttackDamageMinLeft, 80);
		gObj[aIndex].pInventory[1].PlusSpecial(&gObj[aIndex].m_AttackDamageMaxLeft, 80);
	}

	gObj[aIndex].m_CriticalDamage = 0;
	gObj[aIndex].m_ExcelentDamage = 0;

	gObj[aIndex].pInventory[0].PlusSpecial(&gObj[aIndex].m_CriticalDamage, 84);
	gObj[aIndex].pInventory[1].PlusSpecial(&gObj[aIndex].m_CriticalDamage, 84);
	gObj[aIndex].pInventory[2].PlusSpecial(&gObj[aIndex].m_CriticalDamage, 84);
	gObj[aIndex].pInventory[3].PlusSpecial(&gObj[aIndex].m_CriticalDamage, 84);
	gObj[aIndex].pInventory[4].PlusSpecial(&gObj[aIndex].m_CriticalDamage, 84);
	gObj[aIndex].pInventory[5].PlusSpecial(&gObj[aIndex].m_CriticalDamage, 84);
	gObj[aIndex].pInventory[6].PlusSpecial(&gObj[aIndex].m_CriticalDamage, 84);
	gObj[aIndex].pInventory[7].PlusSpecial(&gObj[aIndex].m_CriticalDamage, 84);
	
	gObj[aIndex].m_MagicDamageMin = Energy / Balancer.Character.MagicDamageMin[gObj[aIndex].Class];
	gObj[aIndex].m_MagicDamageMax = Energy / Balancer.Character.MagicDamageMax[gObj[aIndex].Class];
	
	gObj[aIndex].pInventory[7].PlusSpecial(&gObj[aIndex].m_MagicDamageMin, 81);
	gObj[aIndex].pInventory[7].PlusSpecial(&gObj[aIndex].m_MagicDamageMax, 81);

	if (Right->m_Type != -1)
	{
		if (gObj[aIndex].pInventory[0].m_Type == ITEMGET(0, 31) || gObj[aIndex].pInventory[0].m_Type == ITEMGET(0, 21) || gObj[aIndex].pInventory[0].m_Type == ITEMGET(0, 23) || gObj[aIndex].pInventory[0].m_Type == ITEMGET(0, 25))
		{
			gObj[aIndex].pInventory[0].PlusSpecial(&gObj[aIndex].m_MagicDamageMin, 80);
			gObj[aIndex].pInventory[0].PlusSpecial(&gObj[aIndex].m_MagicDamageMax, 80);
		}
		else
		{
			gObj[aIndex].pInventory[0].PlusSpecial(&gObj[aIndex].m_MagicDamageMin, 81);
			gObj[aIndex].pInventory[0].PlusSpecial(&gObj[aIndex].m_MagicDamageMax, 81);
		}
	}

	gObj[aIndex].m_AttackRating = (Strength + Dexterity) / 2;
	gObj[aIndex].m_AttackRating += gObj[aIndex].pInventory[5].ItemDefense();

	gObj[aIndex].m_AttackSpeed = Dexterity / Balancer.Character.AttackSpeed[gObj[aIndex].Class];
	gObj[aIndex].m_MagicSpeed = Dexterity / Balancer.Character.MagicSpeed[gObj[aIndex].Class];

	bool bRight = false;
	bool bLeft = false;

	if (Right->m_Type != ITEMGET(4, 7) && Right->m_Type != ITEMGET(4, 15) && Right->m_Type >= ITEMGET(0, 0) && Right->m_Type < ITEMGET(6, 0))
	{
		if (Right->m_IsValidItem != false)
		{
			bRight = true;
		}
	}

	if (Left->m_Type != ITEMGET(4, 7) && Left->m_Type != ITEMGET(4, 15) && Left->m_Type >= ITEMGET(0, 0) && Left->m_Type < ITEMGET(6, 0))
	{
		if (Left->m_IsValidItem != false)
		{
			bLeft = true;
		}
	}

	if (bRight != false && bLeft != false)
	{
		gObj[aIndex].m_AttackSpeed += (Right->m_AttackSpeed + Left->m_AttackSpeed) / 2;
		gObj[aIndex].m_MagicSpeed += (Right->m_AttackSpeed + Left->m_AttackSpeed) / 2;
	}
	else if (bRight != false)
	{
		gObj[aIndex].m_AttackSpeed += Right->m_AttackSpeed;
		gObj[aIndex].m_MagicSpeed += Right->m_AttackSpeed;
	}
	else if (bLeft != false)
	{
		gObj[aIndex].m_AttackSpeed += Left->m_AttackSpeed;
		gObj[aIndex].m_MagicSpeed += Left->m_AttackSpeed;
	}

	if (Gloves->m_Type != -1)
	{
		if (Gloves->m_IsValidItem != false)
		{
			gObj[aIndex].m_AttackSpeed += Gloves->m_AttackSpeed;
			gObj[aIndex].m_MagicSpeed += Gloves->m_AttackSpeed;
		}
	}

	if (Helper->m_Type != -1)
	{
		if (Helper->m_IsValidItem != false)
		{
			gObj[aIndex].m_AttackSpeed += Helper->m_AttackSpeed;
			gObj[aIndex].m_MagicSpeed += Helper->m_AttackSpeed;
		}
	}

	if (Amulet->m_Type != -1)
	{
		if (Amulet->m_IsValidItem != false)
		{
			gObj[aIndex].m_AttackSpeed += Amulet->m_AttackSpeed;
			gObj[aIndex].m_MagicSpeed += Amulet->m_AttackSpeed;
		}
	}

	if ((gObj[aIndex].pInventory[10].IsItem() == TRUE && gObj[aIndex].pInventory[10].m_Type == ITEMGET(13, 20) && gObj[aIndex].pInventory[10].m_Level == 0 && gObj[aIndex].pInventory[10].m_Durability > 0.0f) || (gObj[aIndex].pInventory[11].IsItem() == TRUE && gObj[aIndex].pInventory[11].m_Type == ITEMGET(13, 20) && gObj[aIndex].pInventory[11].m_Level == 0 && gObj[aIndex].pInventory[11].m_Durability > 0.0f))
	{
		gObj[aIndex].m_AttackDamageMinRight += gObj[aIndex].m_AttackDamageMinRight * 10 / 100;
		gObj[aIndex].m_AttackDamageMaxRight += gObj[aIndex].m_AttackDamageMaxRight * 10 / 100;
		gObj[aIndex].m_AttackDamageMinLeft += gObj[aIndex].m_AttackDamageMinLeft * 10 / 100;
		gObj[aIndex].m_AttackDamageMaxLeft += gObj[aIndex].m_AttackDamageMaxLeft * 10 / 100;
		gObj[aIndex].m_MagicDamageMin += gObj[aIndex].m_MagicDamageMin * 10 / 100;
		gObj[aIndex].m_MagicDamageMax += gObj[aIndex].m_MagicDamageMax * 10 / 100;
		gObj[aIndex].m_AttackSpeed += 10;
		gObj[aIndex].m_MagicSpeed += 10;
	}

	if (gObj[aIndex].Class == WIZARD)
	{
		gObj[aIndex].m_DetectSpeedHackTime = (int)(*(DWORD*)(0x686F6C) - (gObj[aIndex].m_MagicSpeed * 2 * *(float*)(0x686F74)));
	}
	else
	{
		gObj[aIndex].m_DetectSpeedHackTime = (int)(*(DWORD*)(0x686F6C) - (gObj[aIndex].m_AttackSpeed *  *(float*)(0x686F74)));
	}

	if (gObj[aIndex].m_DetectSpeedHackTime < *(int*)(0x686F78))
	{
		gObj[aIndex].m_DetectSpeedHackTime = *(int*)(0x686F78);
	}

	gObj[aIndex].m_SuccessfulBlocking = Dexterity / Balancer.Character.SuccessfulBlocking[gObj[aIndex].Class];

	if (Left->m_Type != -1)
	{
		if (Left->m_IsValidItem != false)
		{
			gObj[aIndex].m_SuccessfulBlocking += Left->m_SuccessfulBlocking;
			gObj[aIndex].pInventory[1].PlusSpecial(&gObj[aIndex].m_SuccessfulBlocking, 82);
		}
	}

	bool Success = true;

	if (gObj[aIndex].Class == MAGUMSA)
	{
		for (int j = 3; j <= 6; j++)
		{
			if (gObj[aIndex].pInventory[j].m_Type == -1)
			{
				Success = false;
				break;
			}

			if (gObj[aIndex].pInventory[j].m_IsValidItem == false)
			{
				Success = false;
				break;
			}
		}
	}
	else
	{
		for (int k = 2; k <= 6; k++)
		{
			if (gObj[aIndex].pInventory[k].m_Type == -1)
			{
				Success = false;
				break;
			}

			if (gObj[aIndex].pInventory[k].m_IsValidItem == false)
			{
				Success = false;
				break;
			}
		}
	}

	int Level11Count = 0;
	int Level10Count = 0;
	int Level12Count = 0;
	int Level13Count = 0;

	if (Success != false)
	{
		int in;

		if (gObj[aIndex].Class == MAGUMSA)
		{
			in = gObj[aIndex].pInventory[3].m_Type % 32;

			if (in != ITEMGET(0, 15) &&
				in != ITEMGET(0, 20) &&
				in != ITEMGET(0, 23) &&
				in != ITEMGET(0, 33) &&
				in != ITEMGET(0, 32) &&
				in != ITEMGET(0, 37))
			{
				Success = false;
			}
			else
			{
				Level13Count++;

				for (int m = 3; m <= 6; m++)
				{
					if (in != (gObj[aIndex].pInventory[m].m_Type % 32))
					{
						Success = false;
					}

					if (gObj[aIndex].pInventory[m].m_Level > 12)
					{
						Level13Count++;
					}
					else if (gObj[aIndex].pInventory[m].m_Level > 11)
					{
						Level12Count++;
					}
					else if (gObj[aIndex].pInventory[m].m_Level > 10)
					{
						Level11Count++;
					}
					else if (gObj[aIndex].pInventory[m].m_Level > 9)
					{
						Level10Count++;
					}
				}
			}
		}
		else
		{
			in = gObj[aIndex].pInventory[2].m_Type % 32;

			for (int m = 2; m <= 6; m++)
			{
				if (in != (gObj[aIndex].pInventory[m].m_Type % 32))
				{
					Success = false;
				}

				if (gObj[aIndex].pInventory[m].m_Level > 12)
				{
					Level13Count++;
				}
				else if (gObj[aIndex].pInventory[m].m_Level > 11)
				{
					Level12Count++;
				}
				else if (gObj[aIndex].pInventory[m].m_Level > 10)
				{
					Level11Count++;
				}
				else if (gObj[aIndex].pInventory[m].m_Level > 9)
				{
					Level10Count++;
				}
			}
		}

		if (Success != false)
		{
			gObj[aIndex].m_SuccessfulBlocking += gObj[aIndex].m_SuccessfulBlocking / 10;
		}
	}
	
	gObj[aIndex].m_Defense = Dexterity / Balancer.Character.Defense[gObj[aIndex].Class];
	
	gObj[aIndex].m_Defense += gObj[aIndex].pInventory[2].ItemDefense();
	gObj[aIndex].m_Defense += gObj[aIndex].pInventory[3].ItemDefense();
	gObj[aIndex].m_Defense += gObj[aIndex].pInventory[4].ItemDefense();
	gObj[aIndex].m_Defense += gObj[aIndex].pInventory[5].ItemDefense();
	gObj[aIndex].m_Defense += gObj[aIndex].pInventory[6].ItemDefense();
	gObj[aIndex].m_Defense += gObj[aIndex].pInventory[1].ItemDefense();
	gObj[aIndex].m_Defense += gObj[aIndex].pInventory[7].ItemDefense();

	if (gObj[aIndex].pInventory[8].IsItem() != FALSE)
	{
		if (gObj[aIndex].pInventory[8].m_Type == ITEMGET(13, 4) && gObj[aIndex].pInventory[8].m_Durability > 0.0f)	// Dark Horse
		{
			gObj[aIndex].m_Defense += INT(Dexterity / 20 + 5 + Helper->m_PetItem_Level * 2);
		}
	}

	if ((Level13Count + Level12Count + Level11Count + Level10Count) >= 5)
	{
		if (Success != false)
		{
			if (Level13Count == 5)
			{
				gObj[aIndex].m_Defense += gObj[aIndex].m_Defense * 20 / 100;
			}
			else if (Level12Count == 5 || (Level12Count + Level13Count) == 5)
			{
				gObj[aIndex].m_Defense += gObj[aIndex].m_Defense * 15 / 100;
			}
			else if (Level11Count == 5 || (Level11Count + Level12Count + Level13Count) == 5)
			{
				gObj[aIndex].m_Defense += gObj[aIndex].m_Defense * 10 / 100;
			}
			else if (Level10Count == 5 || (Level10Count + Level11Count + Level12Count + Level13Count) == 5)
			{
				gObj[aIndex].m_Defense += gObj[aIndex].m_Defense * 5 / 100;
			}
		}
	}

	gObj[aIndex].m_Defense = gObj[aIndex].m_Defense * 10 / 20;

	if (gObj[aIndex].m_Change == 9)
	{

	}
	else if (gObj[aIndex].m_Change == 41)
	{
		gObj[aIndex].AddLife = ((int)(gObj[aIndex].MaxLife * 20.0f)) / 100;
	}
	else if (gObj[aIndex].m_Change == 372)
	{
		gObj[aIndex].m_Defense += gObj[aIndex].m_Defense / 10;
		gObj[aIndex].AddLife += gObj[aIndex].Level;
	}

	if (gObj[aIndex].pInventory[8].m_Type == ITEMGET(13, 0))
	{
		gObj[aIndex].AddLife += 50;
	}

	int addlife = 0;
	int addmana = 0;

	gObj[aIndex].pInventory[7].PlusSpecial(&addlife, 100);
	gObj[aIndex].pInventory[7].PlusSpecial(&addmana, 101);
	gObj[aIndex].pInventory[7].PlusSpecial(&AddLeadership, 105);
	gObj[aIndex].AddLeadership = AddLeadership;
	gObj[aIndex].AddLife += addlife;
	gObj[aIndex].AddMana += addmana;

	if (gObj[aIndex].pInventory[8].m_Type == ITEMGET(13, 3))
	{
		gObj[aIndex].pInventory[8].PlusSpecial(&gObj[aIndex].AddBP, 103);
	}

	if (gObj[aIndex].Type == PLAYER)
	{
		gDarkSpirit[aIndex].Set(aIndex, &gObj[aIndex].pInventory[1]);
	}

	gObj[aIndex].pInventory[9].PlusSpecialPercentEx(&gObj[aIndex].AddBP, gObj[aIndex].MaxBP, 173);
	gObj[aIndex].pInventory[10].PlusSpecialPercentEx(&gObj[aIndex].AddMana, (int)gObj[aIndex].MaxMana, 172);
	gObj[aIndex].pInventory[11].PlusSpecialPercentEx(&gObj[aIndex].AddMana, (int)gObj[aIndex].MaxMana, 172);

	CItem * rItem[3];
	int comparecount = 0;

	rItem[0] = &gObj[aIndex].pInventory[10];
	rItem[1] = &gObj[aIndex].pInventory[11];
	rItem[2] = &gObj[aIndex].pInventory[9];

    #define GET_MAX_RESISTANCE(x,y,z) ( ( ( ( (x) > (y) ) ? (x) : (y) ) > (z) ) ? ( ( (x) > (y) ) ? (x) : (y) ) : (z) )	

	gObj[aIndex].m_Resistance[1] = GET_MAX_RESISTANCE(rItem[0]->m_Resistance[1], rItem[1]->m_Resistance[1], rItem[2]->m_Resistance[1]);
	gObj[aIndex].m_Resistance[0] = GET_MAX_RESISTANCE(rItem[0]->m_Resistance[0], rItem[1]->m_Resistance[0], rItem[2]->m_Resistance[0]);
	gObj[aIndex].m_Resistance[2] = GET_MAX_RESISTANCE(rItem[0]->m_Resistance[2], rItem[1]->m_Resistance[2], rItem[2]->m_Resistance[2]);
	gObj[aIndex].m_Resistance[3] = GET_MAX_RESISTANCE(rItem[0]->m_Resistance[3], rItem[1]->m_Resistance[3], rItem[2]->m_Resistance[3]);
	gObj[aIndex].m_Resistance[4] = GET_MAX_RESISTANCE(rItem[0]->m_Resistance[4], rItem[1]->m_Resistance[4], rItem[2]->m_Resistance[4]);
	gObj[aIndex].m_Resistance[5] = GET_MAX_RESISTANCE(rItem[0]->m_Resistance[5], rItem[1]->m_Resistance[5], rItem[2]->m_Resistance[5]);
	gObj[aIndex].m_Resistance[6] = GET_MAX_RESISTANCE(rItem[0]->m_Resistance[6], rItem[1]->m_Resistance[6], rItem[2]->m_Resistance[6]);

	GObjExtItemApply(&gObj[aIndex]);
	gObjSetItemApply(&gObj[aIndex]);
	gObjNextExpCal(&gObj[aIndex]);

	if ((Left->m_Type >= ITEMGET(4, 0) && Left->m_Type < ITEMGET(4, 7)) ||
		Left->m_Type == ITEMGET(4, 17) ||
		Left->m_Type == ITEMGET(4, 20) ||
		Left->m_Type == ITEMGET(4, 21) ||
		Left->m_Type == ITEMGET(4, 22))
	{
		if (Right->m_Type == ITEMGET(4, 15) && Right->m_Level == 1)
		{
			gObj[aIndex].m_AttackDamageMinLeft += (WORD)(gObj[aIndex].m_AttackDamageMinLeft * 0.03f + 1.0f);
			gObj[aIndex].m_AttackDamageMaxLeft += (WORD)(gObj[aIndex].m_AttackDamageMaxLeft * 0.03f + 1.0f);
		}
		else if (Right->m_Type == ITEMGET(4, 15) && Right->m_Level == 2)
		{
			gObj[aIndex].m_AttackDamageMinLeft += (WORD)(gObj[aIndex].m_AttackDamageMinLeft * 0.05f + 1.0f);
			gObj[aIndex].m_AttackDamageMaxLeft += (WORD)(gObj[aIndex].m_AttackDamageMaxLeft * 0.05f + 1.0f);
		}
	}
	else if ((Right->m_Type >= ITEMGET(4, 8) && Right->m_Type < ITEMGET(4, 15)) ||
		(Right->m_Type >= ITEMGET(4, 16) && Right->m_Type < ITEMGET(5, 0)))
	{
		if (Left->m_Type == ITEMGET(4, 7) && Left->m_Level == 1)
		{
			gObj[aIndex].m_AttackDamageMinRight += (WORD)(gObj[aIndex].m_AttackDamageMinRight * 0.03f + 1.0f);
			gObj[aIndex].m_AttackDamageMaxRight += (WORD)(gObj[aIndex].m_AttackDamageMaxRight * 0.03f + 1.0f);
		}
		else if (Left->m_Type == ITEMGET(4, 7) && Left->m_Level == 2)
		{
			gObj[aIndex].m_AttackDamageMinRight += (WORD)(gObj[aIndex].m_AttackDamageMinRight * 0.05f + 1.0f);
			gObj[aIndex].m_AttackDamageMaxRight += (WORD)(gObj[aIndex].m_AttackDamageMaxRight * 0.05f + 1.0f);
		}
	}

	if (gObj[aIndex].Class == KNIGHT || gObj[aIndex].Class == MAGUMSA || gObj[aIndex].Class == DARKLORD)
	{
		if (Right->m_Type != -1 && Left->m_Type != -1)
		{
			if (Right->m_Type >= ITEMGET(0, 0) && Right->m_Type < ITEMGET(4, 0) && Left->m_Type >= ITEMGET(0, 0) && Left->m_Type < ITEMGET(4, 0))
			{
				gObj[aIndex].m_AttackDamageMinRight = gObj[aIndex].m_AttackDamageMinRight * 55 / 100;
				gObj[aIndex].m_AttackDamageMaxRight = gObj[aIndex].m_AttackDamageMaxRight * 55 / 100;
				gObj[aIndex].m_AttackDamageMinLeft = gObj[aIndex].m_AttackDamageMinLeft * 55 / 100;
				gObj[aIndex].m_AttackDamageMaxLeft = gObj[aIndex].m_AttackDamageMaxLeft * 55 / 100;
			}
		}
	}

	if(gObj[aIndex].Mana > 32000) gObj[aIndex].Mana = 32000;
	if(gObj[aIndex].MaxMana > 32000) gObj[aIndex].MaxMana = 32000;

	GCReFillSend(aIndex,(WORD)(gObj[aIndex].MaxLife + gObj[aIndex].AddLife), 0xFE,0);
	GCManaSend(aIndex,(short)(gObj[aIndex].MaxMana + gObj[aIndex].AddMana), 0xFE,0,gObj[aIndex].MaxBP + gObj[aIndex].AddBP);

	PMSG_CHARINFOMAIN Result;

	Result.h.c = 0xC1;
	Result.h.size = sizeof(Result);
	Result.h.headcode = 0xFE;
	Result.Code = 0x07;
	Result.Class = gObj[aIndex].Class;
	Result.Dexterity = (WORD)(gObj[aIndex].Dexterity);
	Result.AttackSpeed = (WORD)(gObj[aIndex].m_AttackSpeed); 
	Result.MagicSpeed = (WORD)(gObj[aIndex].m_MagicSpeed);

	DataSend(aIndex, (LPBYTE)(&Result), Result.h.size);
}