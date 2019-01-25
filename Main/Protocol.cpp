#include "Principal.h"

BOOL ProtocolCoreEx(int unk1, LPBYTE lpRecv, int unk2, int unk3)
{
	BYTE Head = lpRecv[(lpRecv[0] == 0xC2 || lpRecv[0] == 0xC4) ? 3 : 2];
	BYTE SubCode = lpRecv[(lpRecv[0] == 0xC2 || lpRecv[0] == 0xC4) ? 4 : 3];

	switch(Head)
	{
	case 0xF3:
		{
			switch(SubCode)
			{
			case 0x03:
				{
					if (!FireTeam)
					{
						ExitProcess(0);
						__asm MOV EAX, 0;
						__asm JMP EAX;
					}

					Player.InEvent = false;
				}
				break;
			case 0x05:
				Player.IsUpdate = false;
				break;				
			case 0x06:
				{
					Player.IsUpdate = false;
					Player.RealLevelUpPoint--;
				}
				break;
			case 0xE2:
				{
					HPBar.ClearNewHealthBar();

					PMSG_HEALTHBAR* lpMsg = (PMSG_HEALTHBAR*)(lpRecv);

					for (int i = 0; i < lpMsg->Count; i++)
					{
						PMSG_HEALTHBAR_INFO* Info = (PMSG_HEALTHBAR_INFO*)(&lpRecv[sizeof(PMSG_HEALTHBAR) + (sizeof(PMSG_HEALTHBAR_INFO) * i)]);
						HPBar.InsertNewHealthBar(Info->Index, Info->Rate);
					}
				}
				break;
			}
		}
		break;
	case 0xFE:
		{
			switch(SubCode)
			{
			case 0x01: // UpdateCharacter - Com efeito
				{
					PMSG_LEVELUP pResult;
					PMSG_UPDATECHARACTER* pMsg = (PMSG_UPDATECHARACTER*)(lpRecv);

					Player.IsUpdate = true;
					Player.Level = pMsg->Level;
					Player.LevelUpPoint = (WORD)(pMsg->LevelUpPoint);
					Player.RealLevelUpPoint = pMsg->LevelUpPoint;
					Player.Experience = pMsg->Experience;
					Player.NextExperience = pMsg->NextExperience;
					Player.Strength = pMsg->Strength;
					Player.Dexterity = pMsg->Dexterity;
					Player.Vitality = pMsg->Vitality;
					Player.Energy = pMsg->Energy;
					Player.Leadership = pMsg->Leadership;
					Player.Life = pMsg->Life;
					Player.MaxLife = pMsg->MaxLife;
					Player.Mana = pMsg->Mana;
					Player.MaxMana = pMsg->MaxMana;
					Player.BP = pMsg->BP;
					Player.MaxBP = pMsg->MaxBP;

					pResult.h.c = 0xC1;
					pResult.h.size = sizeof(pResult);
					pResult.h.headcode = 0xF3;
					pResult.subcode = 0x05;

					LevelUpRecv(&pResult);
				}
				break;
			case 0x02: // UpdateCharacter - Sem efeito
				{
					PMSG_LVPOINTADDRESULT pResult;
					PMSG_UPDATECHARACTER* pMsg = (PMSG_UPDATECHARACTER*)(lpRecv);

					Player.IsUpdate = true;
					Player.Level = pMsg->Level;
					Player.LevelUpPoint = pMsg->LevelUpPoint + 1;
					Player.RealLevelUpPoint = pMsg->LevelUpPoint; // n precisa de + 1
					Player.Experience = pMsg->Experience;
					Player.NextExperience = pMsg->NextExperience;
					Player.Strength = pMsg->Strength;
					Player.Dexterity = pMsg->Dexterity;
					Player.Vitality = pMsg->Vitality;
					Player.Energy = pMsg->Energy;
					Player.Leadership = pMsg->Leadership;
					Player.Life = pMsg->Life;
					Player.MaxLife = pMsg->MaxLife;
					Player.Mana = pMsg->Mana;
					Player.MaxMana = pMsg->MaxMana;
					Player.BP = pMsg->BP;
					Player.MaxBP = pMsg->MaxBP;

					pResult.h.c = 0xC1;
					pResult.h.size = sizeof(pResult);
					pResult.h.headcode = 0xF3;
					pResult.subcode = 0x06;
					pResult.ResultType = 0x10;
					pResult.MaxLifeAndMana = pMsg->MaxLife;
					pResult.MaxBP = pMsg->MaxBP;

					LevelUpAddPoint(&pResult);
				}
				break;
			case 0x07:
				{
					PMSG_CHARINFOMAIN* Info = (PMSG_CHARINFOMAIN*)(lpRecv);

					Player.Class = Info->Class;
					Player.Dexterity = Info->Dexterity;
					Player.AttackSpeed = Info->AttackSpeed;
					Player.MagicSpeed = Info->MagicSpeed;
					Player.RealLevelUpPoint = Info->LevelUpPoint;

					FireTeam = true;

					ApplyDexterityFix();
				}
				break;
			case 0x08:
				{
					PMSG_UPDATEPOINTS* Info = (PMSG_UPDATEPOINTS*)(lpRecv);

					Player.RealLevelUpPoint = Info->LevelUpPoint;
				}
				break;				
			case 0x09:
				Player.InEvent = true;
				break;
			case 0x0A:
				Player.InEvent = false;
				break;
			}
		}
		break;
	}

	return ProtocolCore(unk1, lpRecv, unk2, unk3);
}

void ApplyDexterityFix()
{
	switch (Player.Class)
	{
	case 0:
		{
			if (Player.MagicSpeed >= 455 && Player.MagicSpeed <= 479)
			{
				*MainSpeedFrame2 = 0.0024700f;
			}
			else if (Player.MagicSpeed >= 605 && Player.MagicSpeed <= 636)
			{
				*MainSpeedFrame2 = 0.0019000f;
			}
			else if (Player.MagicSpeed >= 637 && Player.MagicSpeed <= 668)
			{
				*MainSpeedFrame2 = 0.0018000f;
			}
			else if (Player.MagicSpeed >= 669 && Player.MagicSpeed <= 688)
			{
				*MainSpeedFrame2 = 0.0017000f;
			}
			else if (Player.MagicSpeed >= 855 && Player.MagicSpeed <= 1040)
			{
				*MainSpeedFrame2 = 0.0016300f;
			}
			else if (Player.MagicSpeed >= 1041 && Player.MagicSpeed <= 1104)
			{
				*MainSpeedFrame2 = 0.0015500f;
			}
			else if (Player.MagicSpeed >= 1301 && Player.MagicSpeed <= 1500)
			{
				*MainSpeedFrame2 = 0.0017500f;
			}
			else if (Player.MagicSpeed >= 1501 && Player.MagicSpeed <= 1524)
			{
				*MainSpeedFrame2 = 0.0015000f;
			}
			else if (Player.MagicSpeed >= 1525 && Player.MagicSpeed <= 1800)
			{
				*MainSpeedFrame2 = 0.0014500f;
			}
			else if (Player.MagicSpeed >= 1801 && Player.MagicSpeed <= 1999)
			{
				*MainSpeedFrame2 = 0.0013000f;
			}
			else if (Player.MagicSpeed >= 2000 && Player.MagicSpeed <= 2167)
			{
				*MainSpeedFrame2 = 0.0012500f;
			}
			else if (Player.MagicSpeed >= 2168 && Player.MagicSpeed <= 2354)
			{
				*MainSpeedFrame2 = 0.0011500f;
			}
			else if (Player.MagicSpeed >= 2855 && Player.MagicSpeed <= 3011)
			{
				*MainSpeedFrame2 = 0.0009000f;
			}
			else if (Player.MagicSpeed >= 3011)
			{
				*MainSpeedFrame2 = 0.0008100f;
			}
			else
			{
				*MainSpeedFrame2 = 0.0020000f;
			}
		}
		break;
	case 1:
		{
			*MainSpeedFrame1 = 0.0040000f;
			*MainSpeedFrame2 = 0.0020000f;
		}
		break;
	case 2:
		{
			if (Player.AttackSpeed >= 509 && Player.AttackSpeed <= 549)
			{
				*MainSpeedFrame1 = 0.0026000f;
			} 
			else if (Player.AttackSpeed >= 550 && Player.AttackSpeed <= 750) 
			{
				*MainSpeedFrame1 = 0.0017000f;
			} 
			else 
			{
				*MainSpeedFrame1 = 0.0040000f;
			}
		}
		break;
	case 3:
		{
			if (Player.Dexterity >= 11001 && Player.Dexterity <= 12000)
			{
				*MainSpeedFrame1 = 0.001800000f;
			}
			else if (Player.Dexterity >= 16000 && Player.Dexterity <= 17000)
			{
				*MainSpeedFrame1 = 0.001800000f;
			}
			else if (Player.Dexterity >= 17001 && Player.Dexterity <= 19000)
			{
				*MainSpeedFrame1 = 0.001700000f;
			}
			else if (Player.Dexterity >= 19001 && Player.Dexterity <= 20000)
			{
				*MainSpeedFrame1 = 0.001600000f;
			}
			else if (Player.Dexterity >= 20001 && Player.Dexterity <= 21000)
			{
				*MainSpeedFrame1 = 0.001500000f;
			}
			else if (Player.Dexterity >= 21001 && Player.Dexterity <= 23000)
			{
				*MainSpeedFrame1 = 0.001400000f;
			}
			else if (Player.Dexterity >= 26000 && Player.Dexterity <= 27000)
			{
				*MainSpeedFrame1 = 0.001900000f;
			}
			else if (Player.Dexterity >= 27001 && Player.Dexterity <= 29000)
			{
				*MainSpeedFrame1 = 0.001900000f;
			}
			else if (Player.Dexterity >= 29001 && Player.Dexterity <= 30000)
			{
				*MainSpeedFrame1 = 0.001900000f;
			}
			else if (Player.Dexterity >= 30001 && Player.Dexterity <= 32767)
			{
				*MainSpeedFrame1 = 0.001600000f;
			}
			else
			{
				*MainSpeedFrame1 = 0.002000000f;
			}

			if (Player.MagicSpeed >= 455 && Player.MagicSpeed <= 479)
			{
				*MainSpeedFrame2 = 0.0024700f;
			}
			else if (Player.MagicSpeed >= 605 && Player.MagicSpeed <= 636)
			{
				*MainSpeedFrame2 = 0.0019000f;
			}
			else if (Player.MagicSpeed >= 637 && Player.MagicSpeed <= 668)
			{
				*MainSpeedFrame2 = 0.0018000f;
			}
			else if (Player.MagicSpeed >= 669 && Player.MagicSpeed <= 688)
			{
				*MainSpeedFrame2 = 0.0017000f;
			}
			else if (Player.MagicSpeed >= 855 && Player.MagicSpeed <= 1040)
			{
				*MainSpeedFrame2 = 0.0016300f;
			}
			else if (Player.MagicSpeed >= 1041 && Player.MagicSpeed <= 1104)
			{
				*MainSpeedFrame2 = 0.0015500f;
			}
			else if (Player.MagicSpeed >= 1301 && Player.MagicSpeed <= 1500)
			{
				*MainSpeedFrame2 = 0.0017500f;
			}
			else if (Player.MagicSpeed >= 1501 && Player.MagicSpeed <= 1524)
			{
				*MainSpeedFrame2 = 0.0015000f;
			}
			else if (Player.MagicSpeed >= 1525 && Player.MagicSpeed <= 1800)
			{
				*MainSpeedFrame2 = 0.0014500f;
			}
			else if (Player.MagicSpeed >= 1801 && Player.MagicSpeed <= 1999)
			{
				*MainSpeedFrame2 = 0.0013000f;
			}
			else if (Player.MagicSpeed >= 2000 && Player.MagicSpeed <= 2167)
			{
				*MainSpeedFrame2 = 0.0012500f;
			}
			else if (Player.MagicSpeed >= 2168 && Player.MagicSpeed <= 2354)
			{
				*MainSpeedFrame2 = 0.0011500f;
			}
			else if (Player.MagicSpeed >= 2855 && Player.MagicSpeed <= 3011)
			{
				*MainSpeedFrame2 = 0.0009000f;
			}
			else if (Player.MagicSpeed >= 3011)
			{
				*MainSpeedFrame2 = 0.0008100f;
			}
			else
			{
				*MainSpeedFrame2 = 0.0020000f;
			}
		}
		break;
	case 4:
		{
			if (Player.Dexterity >= 2000 && Player.Dexterity < 4900)
			{
				*MainSpeedFrame1 = 0.0038000f;
			}
			else if (Player.Dexterity >= 4900 && Player.Dexterity < 5050)
			{
				*MainSpeedFrame1 = 0.0037000f;
			}
			else if (Player.Dexterity >= 5050 && Player.Dexterity < 5200)
			{
				*MainSpeedFrame1 = 0.0036000f;
			}
			else if (Player.Dexterity >= 5200 && Player.Dexterity < 5350)
			{
				*MainSpeedFrame1 = 0.0035000f;
			}
			else if (Player.Dexterity >= 5350 && Player.Dexterity < 5550)
			{
				*MainSpeedFrame1 = 0.0034000f;
			}
			else if (Player.Dexterity >= 5550 && Player.Dexterity < 5700)
			{
				*MainSpeedFrame1 = 0.0033000f;
			}
			else if (Player.Dexterity >= 5700 && Player.Dexterity < 5900)
			{
				*MainSpeedFrame1 = 0.0032000f;
			}
			else if (Player.Dexterity >= 5900 && Player.Dexterity < 6100)
			{
				*MainSpeedFrame1 = 0.0031000f;
			}
			else if (Player.Dexterity >= 6100 && Player.Dexterity < 6300)
			{
				*MainSpeedFrame1 = 0.0030000f;
			}
			else if (Player.Dexterity >= 6300 && Player.Dexterity < 6500)
			{
				*MainSpeedFrame1 = 0.0029000f;
			}
			else if (Player.Dexterity >= 6500 && Player.Dexterity < 6750)
			{
				*MainSpeedFrame1 = 0.0028000f;
			}
			else if (Player.Dexterity >= 6750 && Player.Dexterity < 7000)
			{
				*MainSpeedFrame1 = 0.0027000f;
			}
			else if (Player.Dexterity >= 7000 && Player.Dexterity < 7300)
			{
				*MainSpeedFrame1 = 0.0026000f;
			}
			else if (Player.Dexterity >= 7300 && Player.Dexterity < 7600)
			{
				*MainSpeedFrame1 = 0.0025000f;
			}
			else if (Player.Dexterity >= 7600 && Player.Dexterity < 7900)
			{
				*MainSpeedFrame1 = 0.0024000f;
			}
			else if (Player.Dexterity >= 7900 && Player.Dexterity < 8250)
			{
				*MainSpeedFrame1 = 0.0023000f;
			}
			else if (Player.Dexterity >= 8250 && Player.Dexterity < 8650)
			{
				*MainSpeedFrame1 = 0.0022000f;
			}
			else if (Player.Dexterity >= 8650 && Player.Dexterity < 9050)
			{
				*MainSpeedFrame1 = 0.0021000f;
			}
			else if (Player.Dexterity >= 9050 && Player.Dexterity < 9500)
			{
				*MainSpeedFrame1 = 0.0020000f;
			}
			else if (Player.Dexterity >= 9500 && Player.Dexterity < 10000)
			{
				*MainSpeedFrame1 = 0.0019000f;
			}
			else if (Player.Dexterity >= 10000 && Player.Dexterity < 10550)
			{
				*MainSpeedFrame1 = 0.0018000f;
			}
			else if (Player.Dexterity >= 10550 && Player.Dexterity < 11150)
			{
				*MainSpeedFrame1 = 0.0017000f;
			}
			else if (Player.Dexterity >= 11150 && Player.Dexterity < 11850)
			{
				*MainSpeedFrame1 = 0.0016000f;
			}
			else if (Player.Dexterity >= 11850 && Player.Dexterity < 12600)
			{
				*MainSpeedFrame1 = 0.0015000f;
			}
			else if (Player.Dexterity >= 12600 && Player.Dexterity < 13450)
			{
				*MainSpeedFrame1 = 0.0014000f;
			}
			else if (Player.Dexterity >= 13450 && Player.Dexterity < 16600)
			{
				*MainSpeedFrame1 = 0.0010000f;
			}
			else if (Player.Dexterity >= 16600)
			{
				*MainSpeedFrame1 = 0.0008000f;
			}
			else
			{
				*MainSpeedFrame1 = 0.0040000f;
			}
		}
		break;
	}
}

DWORD UpdateCharacterNoEffectBack = 0x4BF8E5;
void __declspec(naked) UpdateCharacterNoEffect()
{
	__asm PUSHAD;

	if (Player.IsUpdate == true)
	{
		__asm
		{
			POPAD;

			MOV EAX, DWORD PTR DS:[0x76103DC];

			MOV CX, Player.Level;
			MOV WORD PTR DS:[EAX+0x0E], CX; 

			MOV ECX, Player.Experience;
			MOV DWORD PTR DS:[EAX+0x10], ECX;

			MOV ECX, Player.NextExperience;
			MOV DWORD PTR DS:[EAX+0x14], ECX;

			MOV CX, Player.Strength;
			MOV WORD PTR DS:[EAX+0x18], CX;

			MOV CX, Player.Dexterity;
			MOV WORD PTR DS:[EAX+0x1A], CX;

			MOV CX, Player.Vitality;
			MOV WORD PTR DS:[EAX+0x1C], CX;

			MOV CX, Player.Energy;
			MOV WORD PTR DS:[EAX+0x1E], CX;

			MOV CX, Player.Leadership;
			MOV WORD PTR DS:[EAX+0x20], CX;

			MOV CX, Player.Life;
			MOV WORD PTR DS:[EAX+0x22], CX;

			MOV CX, Player.MaxLife;
			MOV WORD PTR DS:[EAX+0x26], CX;

			MOV CX, Player.Mana;
			MOV WORD PTR DS:[EAX+0x24], CX;

			MOV CX, Player.MaxMana;
			MOV WORD PTR DS:[EAX+0x28], CX;

			MOV CX, Player.BP;
			MOV WORD PTR DS:[EAX+0x38], CX;

			MOV CX, Player.MaxBP;
			MOV WORD PTR DS:[EAX+0x3A], CX;

			MOV WORD PTR DS:[EAX+0x44], 0;		// StatPoint
			MOV WORD PTR DS:[EAX+0x46], 0;		// MaxStatPoint

			MOV CX, Player.LevelUpPoint;
			MOV WORD PTR DS:[EAX+0x64], CX;

			JMP UpdateCharacterNoEffectBack;
		}
	}

	__asm
	{
		POPAD;
		MOV EAX, DWORD PTR DS:[0x76103DC];
		JMP UpdateCharacterNoEffectBack;
	}
} 

DWORD UpdateCharacterEffectBack[2] = {0x4BF6B6, 0x4BF676};
void __declspec(naked) UpdateCharacterEffect()
{
	__asm PUSHAD;

	if (Player.IsUpdate == true)
	{
		__asm
		{
			POPAD;
			MOV EAX, DWORD PTR DS:[0x76103DC];

			MOV CX, Player.Level;
			MOV WORD PTR DS:[EAX+0x0E], CX; 

			MOV EDX, Player.Experience;
			MOV DWORD PTR DS:[EAX+0x10], EDX;

			MOV EDX, Player.NextExperience;
			MOV DWORD PTR DS:[EAX+0x14], EDX;

			MOV CX, Player.Strength;
			MOV WORD PTR DS:[EAX+0x18], CX;

			MOV CX, Player.Dexterity;
			MOV WORD PTR DS:[EAX+0x1A], CX;

			MOV CX, Player.Vitality;
			MOV WORD PTR DS:[EAX+0x1C], CX;

			MOV CX, Player.Energy;
			MOV WORD PTR DS:[EAX+0x1E], CX;

			MOV CX, Player.Leadership;
			MOV WORD PTR DS:[EAX+0x20], CX;

			MOV CX, Player.Life;
			MOV WORD PTR DS:[EAX+0x22], CX;

			MOV CX, Player.MaxLife;
			MOV WORD PTR DS:[EAX+0x26], CX;

			MOV CX, Player.Mana;
			MOV WORD PTR DS:[EAX+0x24], CX;

			MOV CX, Player.MaxMana;
			MOV WORD PTR DS:[EAX+0x28], CX;

			MOV CX, Player.BP;
			MOV WORD PTR DS:[EAX+0x38], CX;

			MOV CX, Player.MaxBP;
			MOV WORD PTR DS:[EAX+0x3A], CX;

			MOV WORD PTR DS:[EAX+0x44], 0;		// StatPoint
			MOV WORD PTR DS:[EAX+0x46], 0;		// MaxStatPoint

			MOV CX, Player.LevelUpPoint;
			MOV WORD PTR DS:[EAX+0x64], CX;

			JMP UpdateCharacterEffectBack[0];   
		}
	}

	__asm
	{		
		POPAD;
		MOV EAX, DWORD PTR DS:[0x76103DC];
		JMP UpdateCharacterEffectBack[4];
	}
}

__declspec(naked) void FixLevelUpPoints()
{
	static DWORD Local = 0x5C5C1C;

	__asm
	{
		MOV ECX, Player.RealLevelUpPoint;
		PUSH ECX;
		JMP Local;
	}
}

bool CanUseSkill(int Id)
{
	if (Id == 6 || Id == 15)
	{
		if (Player.InEvent)
		{
			return false;
		}
	}

	return ((bool(*)(int))(0x57F120))(Id);
}

void ProtocolHook()
{
	Hook(0xE8,0x4CDA7D,(DWORD)(&ProtocolCoreEx));
	Hook(0xE9,0x4BF8E0,(DWORD)(&UpdateCharacterNoEffect)); 
	Hook(0xE9,0x4BF671,(DWORD)(&UpdateCharacterEffect));
	Hook(0xE9,0x5C5C17,(DWORD)(&FixLevelUpPoints));
	Hook(0xE8,0x55AA01,(DWORD)(&CanUseSkill));
}

ObjPlayer Player;