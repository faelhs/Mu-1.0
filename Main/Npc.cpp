//=======================================
//-- NOMBRES NPC
//=======================================
#include "Principal.h"
#include "ReadScript.h"


int *MapMu = (int*)0x67198C;
CObjectPreview _obj_preview;

CMonsters Monsters;  


#define MonsterInfo(OriginalMonsterBMD)(OriginalMonsterBMD - 1)
#define MonsterTextureInfo(MonsterInfo)(MonsterInfo + MonsterArray)

bool CObjectPreview::Loading()
{
	SetOp((LPVOID)0x004B655C, this->Render, ASM::CALL);
	SetOp((LPVOID)0x004B6B9C, this->Render, ASM::CALL);
	SetOp((LPVOID)0x004B6FA9, this->Render, ASM::CALL);
	SetOp((LPVOID)0x004CC15A, this->Render, ASM::CALL);
	SetOp((LPVOID)0x004FDAA9, this->Render, ASM::CALL);
	SetOp((LPVOID)0x0052F3D0, this->Render, ASM::CALL);
	SetOp((LPVOID)0x00585E53, this->Render, ASM::CALL);

	return true;
}

DWORD SetWord(const LPVOID dwOffset, const WORD wValue)
{
	return WriteMemory(dwOffset, (LPVOID)& wValue, sizeof(WORD));
}

DWORD SetByte(const LPVOID dwOffset, const BYTE btValue)
{
	return WriteMemory(dwOffset, (LPVOID)& btValue, sizeof(BYTE));
}


DWORD SetDword1(const LPVOID dwOffset, const DWORD dwValue)
{
	return WriteMemory(dwOffset, (LPVOID)& dwValue, sizeof(DWORD));
}


void CMonsters::Init()
{
	//Hook New Monster
	SetHook1(NewMonster_Switch, (LPVOID)0x004FAF86, 0xE8);//004FAF86 

	//Fix Monsters Die Animation
	SetWord((LPVOID)(0x004E5BD7 + 2), 386 + 100); //004E5BD7

	//Set NPC Atributte
	//Con esto, a partir mobs > Crazy DL sera considerados NPC
	//SetByte((LPVOID)(0x004FD63A + 1), 0xE1); //004FD63A

}

//=======================================
//-- CARGA NPC NUEVOS
//=======================================
LPVOID CObjectPreview::Render(DWORD m_iMonsterID, DWORD Arg1, DWORD Arg3, DWORD Arg4, DWORD Arg5)
{
	LPVOID lpRender = __object_render(m_iMonsterID, Arg1, Arg3, Arg4, Arg5);

	SObjectPreview * lpView = (SObjectPreview *)lpRender;
	
	// ----
	switch (m_iMonsterID)
	{
		case 201:
	{
			
			lstrcpy(lpView->Name, "[NPC] QuestBoss");
			lpView->WingsSlot = ITEM(12, 5);

	}	case 202:
	{
			
			lstrcpy(lpView->Name, "[NPC] QuestLoot");
			lpView->WingsSlot = ITEM(12, 5);

	}
		case 254: //passi the wizard
		{
			lpView->WingsSlot = ITEM(12, 4);
			lpView->WeaponFirstSlot = ITEM(5, 10);
			lpView->WeaponFirstLevel = 13;
			lpView->WeaponFirstExcellent = 1;
			lpView->WeaponSecondSlot = -1;
		}
		break;
		// --
	case 59:
		{
			lpView->WeaponFirstSlot = ITEM(5, 7);
			lpView->WeaponFirstLevel = 13;
			lpView->WeaponFirstExcellent = 1;
		}
		break;

			case 229: //marlon
		{
			lpView->WeaponFirstSlot = ITEM(0, 31);
			lpView->WeaponFirstLevel = 13;
			lpView->WeaponFirstExcellent = 1;
			// ----
			lpView->HelmSlot = ITEM(7, 21);
			lpView->_HelmLevel = 13;
			lpView->HelmExcellent = 1;
			// ----
			lpView->ArmorSlot = ITEM(8, 21);
			lpView->_ArmorLevel = 13;
			lpView->ArmorExcellent = 1;
			// ----
			lpView->PantsSlot = ITEM(9, 21);
			lpView->_PantsLevel = 13;
			lpView->PantsExcellent = 1;
			// ----
			lpView->GlovesSlot = ITEM(10, 21);
			lpView->_GlovesLevel = 13;
			lpView->GlovesExcellent = 1;
			// ----
			lpView->BootsSlot = ITEM(11, 21);
			lpView->_BootsLevel = 13;
			lpView->BootsExcellent = 1;
			// ----
			lpView->WingsSlot = ITEM(12, 5);
		}
		break;
		// --
	case 247:
		{
			lstrcpy(lpView->Name, "[NPC] Quests");
			lpView->WeaponFirstSlot = ITEM(4, 18);
			lpView->WeaponFirstLevel = 13;
			lpView->WeaponFirstExcellent = 1;
			// ----
			lpView->WeaponSecondSlot = ITEM(4, 7);
			lpView->WeaponSecondLevel = 13;
			lpView->WeaponSecondExcellent = 1;
			// ----
			lpView->HelmSlot = ITEM(7, 30);
			lpView->_HelmLevel = 13;
			lpView->HelmExcellent = 1;
			// ----
			lpView->ArmorSlot = ITEM(8, 30);
			lpView->_ArmorLevel = 13;
			lpView->ArmorExcellent = 1;
			// ----
			lpView->PantsSlot = ITEM(9, 30);
			lpView->_PantsLevel = 13;
			lpView->PantsExcellent = 1;
			// ----
			lpView->GlovesSlot = ITEM(10, 30);
			lpView->_GlovesLevel = 13;
			lpView->GlovesExcellent = 1;
			// ----
			lpView->BootsSlot = ITEM(11, 30);
			lpView->_BootsLevel = 13;
			lpView->BootsExcellent = 1;
			// ----
			lpView->WingsSlot = ITEM(12, 3);
		}
		break;
		// --

	case 239:
	{
		
		lstrcpy(lpView->Name, "[NPC] Quests Boss");

		lpView->WeaponFirstSlot = ITEM(5, 10);
		lpView->WeaponFirstLevel = 13;
		lpView->WeaponFirstExcellent = 1;
		// ----
		// ----
		lpView->HelmSlot = ITEM(7, 31);
		lpView->_HelmLevel = 13;
		lpView->HelmExcellent = 1;
		// ----
		lpView->ArmorSlot = ITEM(8, 31);
		lpView->_ArmorLevel = 13;
		lpView->ArmorExcellent = 1;
		// ----
		lpView->PantsSlot = ITEM(9, 31);
		lpView->_PantsLevel = 13;
		lpView->PantsExcellent = 1;
		// ----
		lpView->GlovesSlot = ITEM(10, 31);
		lpView->_GlovesLevel = 13;
		lpView->GlovesExcellent = 1;
		// ----
		lpView->BootsSlot = ITEM(11, 31);
		lpView->_BootsLevel = 13;
		lpView->BootsExcellent = 1;
		// ----
		lpView->WingsSlot = ITEM(12, 6);
	}
	break;

	case 253:
	{

		lstrcpy(lpView->Name, "[NPC] Quests Loot");

		lpView->WeaponFirstSlot = ITEM(5, 10);
		lpView->WeaponFirstLevel = 13;
		lpView->WeaponFirstExcellent = 1;
		// ----
		// ----
		lpView->HelmSlot = ITEM(7, 29);
		lpView->_HelmLevel = 13;
		lpView->HelmExcellent = 1;
		// ----
		lpView->ArmorSlot = ITEM(8, 29);
		lpView->_ArmorLevel = 13;
		lpView->ArmorExcellent = 1;
		// ----
		lpView->PantsSlot = ITEM(9, 29);
		lpView->_PantsLevel = 13;
		lpView->PantsExcellent = 1;
		// ----
		lpView->GlovesSlot = ITEM(10, 29);
		lpView->_GlovesLevel = 13;
		lpView->GlovesExcellent = 1;
		// ----
		lpView->BootsSlot = ITEM(11, 29);
		lpView->_BootsLevel = 13;
		lpView->BootsExcellent = 1;
		// ----
		lpView->WingsSlot = ITEM(12, 6);
	}
	break;

		case 249: //npc quest lorencia
		{
			lpView->WeaponFirstSlot = ITEM(0, 19);
			lpView->WeaponFirstLevel = 13;
			lpView->WeaponFirstExcellent = 1;
			// ----
			// ----
			lpView->HelmSlot = ITEM(7, 29);
			lpView->_HelmLevel = 13;
			lpView->HelmExcellent = 1;
			// ----
			lpView->ArmorSlot = ITEM(8, 29);
			lpView->_ArmorLevel = 13;
			lpView->ArmorExcellent = 1;
			// ----
			lpView->PantsSlot = ITEM(9, 29);
			lpView->_PantsLevel = 13;
			lpView->PantsExcellent = 1;
			// ----
			lpView->GlovesSlot = ITEM(10, 29);
			lpView->_GlovesLevel = 13;
			lpView->GlovesExcellent = 1;
			// ----
			lpView->BootsSlot = ITEM(11, 29);
			lpView->_BootsLevel = 13;
			lpView->BootsExcellent = 1;
			// ----
			lpView->WingsSlot = ITEM(12, 5);
		}
		break;
	case 257: // diane a guardia
		{
			// ----
			lpView->HelmSlot = ITEM(7, 19);
			lpView->_HelmLevel = 13;
			lpView->HelmExcellent = 1;
			// ----
			lpView->ArmorSlot = ITEM(8, 19);
			lpView->_ArmorLevel = 13;
			lpView->ArmorExcellent = 1;
			// ----
			lpView->PantsSlot = ITEM(9, 19);
			lpView->_PantsLevel = 13;
			lpView->PantsExcellent = 1;
			// ----
			lpView->GlovesSlot = ITEM(10, 19);
			lpView->_GlovesLevel = 13;
			lpView->GlovesExcellent = 1;
			// ----
			lpView->BootsSlot = ITEM(11, 19);
			lpView->_BootsLevel = 13;
			lpView->BootsExcellent = 1;
			// ----
			lpView->WingsSlot = ITEM(12, 3);
		}
		break;
	case 25: //ice queen
		{
			lpView->fScalarMode = 1.0f;
			// ----
			if(Arg1 == 25)
			{
				lpView->WeaponFirstSlot = ITEM(5, 9);
				lpView->WeaponFirstLevel = 13;
				lpView->WeaponFirstExcellent = 1;
				// ----
				lpView->WeaponSecondSlot = ITEM(6, 3);
				lpView->WeaponSecondLevel = 13;
				lpView->WeaponSecondExcellent = 1;
			}
		}
		break;
	}
	
	return lpRender;
}

//=======================================
//-- CARGA MOBS NUEVOS
//=======================================

int NewMonster_Switch(int MonsterIndex, int a2, int a3, int a4)
{
	int MonsterStructure = Kundum_MonsterShow(MonsterIndex, a2, a3, a4);;

	
	int MonsterTexture = GetBMDTexture(20); 

	if (!MonsterStructure)
	{
		switch (MonsterIndex)
		{

			//=======================================
			//-- CARGA NPC NUEVOS
			//=======================================
			case 201: // "QuestBoss" 
			LoadMonsterBMD(100);// ejemplo monster97.bmd - 1 = 96
			return LoadTextureMonster(a4, 419, a2, a3, 0); // 319 + 97 -1 = 415
			break;
			//=======================================
			//-- CARGA NPC NUEVOS
			//=======================================
			case 202: // "QuestLoot" 
			LoadMonsterBMD(100);// ejemplo monster97.bmd - 1 = 96
			return LoadTextureMonster(a4, 419, a2, a3, 0); // 319 + 97 -1 = 415
			break;
			//=======================================
			//-- CARGA Monster NUEVOS
			//=======================================
		case 304: // "New Mob 1" 
			LoadMonsterBMD(93);// ejemplo monster97.bmd - 1 = 96
			return LoadTextureMonster(a4, 412, a2, a3, 0); // 319 + 97 -1 = 415
			break;
		case 305:// "New Mob 2"
			LoadMonsterBMD(94);// ejemplo monster97.bmd - 1 = 96
			return LoadTextureMonster(a4, 413, a2, a3, 0); // 319 + 97 -1 = 415
			break;
		case 306:// "New Mob 3"
			LoadMonsterBMD(95);// ejemplo monster97.bmd - 1 = 96
			return LoadTextureMonster(a4, 414, a2, a3, 0); // 319 + 97 -1 = 415
			break;
		case 307:// "New Mob 4"
			LoadMonsterBMD(96);// ejemplo monster97.bmd - 1 = 96
			return LoadTextureMonster(a4, 415, a2, a3, 0); // 319 + 97 -1 = 415
			break;
		case 308:// "New Mob 5"
			LoadMonsterBMD(97);// ejemplo monster97.bmd - 1 = 96
			return LoadTextureMonster(a4, 416, a2, a3, 0); // 319 + 97 -1 = 415
			break;
		case 309:// "New Mob 1"
			LoadMonsterBMD(98);// ejemplo monster97.bmd - 1 = 96
			return LoadTextureMonster(a4, 417, a2, a3, 0); // 319 + 97 -1 = 415
			break;
		case 349:// "New Mob 1"
			LoadMonsterBMD(98);// ejemplo monster97.bmd - 1 = 96
			return LoadTextureMonster(a4, 417, a2, a3, 0); // 319 + 97 -1 = 415
			break;
		
case 417: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(92);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 411, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 416: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(91);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 410, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 415: //  Mob 2 Evento
		//Mobs nuevo
	LoadMonsterBMD(90);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 409, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 414: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(89);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 408, a2, a3, 0); // 319 + 97 -1 = 415
		// case 275:
			//sub_5E5BF0(64);
//break;
		
	break;
case 408: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(153);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 472, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 407: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(152);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 471, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 406: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(151);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 470, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 405: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(150);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 469, a2, a3, 0); // 319 + 97 -1 = 415
	break;

case 404: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(149);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 468, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 403: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(148);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 467, a2, a3, 0); // 319 + 97 -1 = 415
	break;	
case 402: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(147);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 466, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 401: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(146);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 465, a2, a3, 0); // 319 + 97 -1 = 415
	break;	
case 400: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(145);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 464, a2, a3, 0); // 319 + 97 -1 = 415
	break;	
case 399: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(144);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 463, a2, a3, 0); // 319 + 97 -1 = 415
	break;		
case 398: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(143);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 462, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 397: //  Mob 2 Evento
	//Mobs nuevo
	LoadMonsterBMD(142);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 461, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 396: //  Mob 1 Evento
	//Mobs nuevo
	LoadMonsterBMD(141);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 460, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 395: //  Otros mobs 5 
	//Mobs nuevo
	LoadMonsterBMD(140);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 459, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 394: //  Otros mobs 4
	//Mobs nuevo
	LoadMonsterBMD(139);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 458, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 393: //  Otros mobs 3
	//Mobs nuevo
	LoadMonsterBMD(138);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 457, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 392: //  Otros mobs 2
	//Mobs nuevo
	LoadMonsterBMD(137);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 456, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 391: //  "Otros mobs 1" 
	//Mobs nuevo
	LoadMonsterBMD(136);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 455, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 390: //  "Sin nombre 8" 
	//Mobs nuevo
	LoadMonsterBMD(135);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 454, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 389: //  "Orcus" 	 
	//Mobs nuevo
	LoadMonsterBMD(134);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 453, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 388: // "Sin nombre 7"    
	//Mobs nuevo
	LoadMonsterBMD(133);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 452, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 387: //  "Sin nombre 6"  
	//Mobs nuevo
	LoadMonsterBMD(133);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 452, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 386: //  "Sin nombre 5" 
	//Mobs nuevo
	LoadMonsterBMD(131);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 450, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 385: //  "Gollock"  
	//Mobs nuevo
	LoadMonsterBMD(130);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 449, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 384: //  "Sin nombre 4"  
	//Mobs nuevo
	LoadMonsterBMD(129);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 448, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 383: // "Sin nombre 3"  
	//Mobs nuevo
	LoadMonsterBMD(128);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 447, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 382: //  "Sin nombre 2" 
	//Mobs nuevo
	LoadMonsterBMD(127);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 446, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 381: //  "Sin nombre" 
	//Mobs nuevo
	LoadMonsterBMD(126);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 445, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 380: //  "Burning Lava Giant"   
	//Mobs nuevo
	LoadMonsterBMD(125);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 444, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 379: //  "Captain Grizzly" 
	//Mobs nuevo
	LoadMonsterBMD(124);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 443, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 378: //  "Sin nombre"  
	//Mobs nuevo
	LoadMonsterBMD(123);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 442, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 377: //  "Splinter Wolf" 
	//Mobs nuevo
	LoadMonsterBMD(122);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 441, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 376: // "Iron Rider" 
	//Mobs nuevo
	LoadMonsterBMD(121);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 440, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 375: // "Berserker"
	//Mobs nuevo
	LoadMonsterBMD(120);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 439, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 374: // "Kentarus"
	//Mobs nuevo
	LoadMonsterBMD(119);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 438, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 373: // "Iron Knight" 
	//Mobs nuevo
	LoadMonsterBMD(118);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 437, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 372: // "Coolutin"
	//Mobs nuevo
	LoadMonsterBMD(117);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 436, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 371: // "Ice Walker"
	//Mobs nuevo
	LoadMonsterBMD(116);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 435, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 370: // "Giant Mammoth"
	//Mobs nuevo
	LoadMonsterBMD(115);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 434, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 369: // "Selupan"  
	//Mobs nuevo
	LoadMonsterBMD(114);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 433, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 368: // "Ice Giant" 
	//Mobs nuevo
	LoadMonsterBMD(113);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 432, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 367: // "Bow Scout" 
	//Mobs nuevo
	LoadMonsterBMD(112);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 431, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 366: // "Balram"  
	//Mobs nuevo
	LoadMonsterBMD(111);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 430, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 365: // "Valam" 
	//Mobs nuevo
	LoadMonsterBMD(110);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 429, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 364: // "Werewolf"
	//Mobs nuevo
	LoadMonsterBMD(109);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 428, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 363: // "Sin nombre con alas"
	//Mobs nuevo
	LoadMonsterBMD(108);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 427, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 362: // "Sin Nombre"
	//Mobs nuevo
	LoadMonsterBMD(107);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 426, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 361: // "Solam"
	//Mobs nuevo
	LoadMonsterBMD(106);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 425, a2, a3, 0); // 319 + 97 -1 = 415
	break;

case 360: // Forest Orc
	//Mobs nuevo
	LoadMonsterBMD(103);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 422, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 359: // Death Ride
	//Mobs nuevo
	LoadMonsterBMD(102);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 421, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 358: //Blue Golem
	//Mobs nuevo
	LoadMonsterBMD(101);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 420, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 357: //Hell Maine
	//Mobs nuevo
	LoadMonsterBMD(105);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 424, a2, a3, 0); // 319 + 97 -1 = 415
	break;
case 356: //Death Tree
	//Mobs nuevo
	LoadMonsterBMD(104);// ejemplo monster97.bmd - 1 = 96
	return LoadTextureMonster(a4, 423, a2, a3, 0); // 319 + 97 -1 = 415
	break;
		case 252:
			//Npc nuevo
			LoadMonsterBMD(76);// ejemplo monster97.bmd - 1 = 96
			return LoadTextureMonster(a4, 395, a2, a3, 0); // 319 + 97 -1 = 415
			break;
		/*case 256:
			//Npc nuevo
			LoadMonsterBMD(104);// ejemplo monster97.bmd - 1 = 96
			return LoadTextureMonster(a4, 423, a2, a3, 0); // 319 + 97 -1 = 415
			break;*/
		/*case 231:
			//Npc nuevo
			LoadMonsterBMD(154);// ejemplo monster97.bmd - 1 = 96
			return LoadTextureMonster(a4, 473, a2, a3, 0); // 319 + 97 -1 = 415
			break;*/
		default:
			return MonsterStructure;
			break;
		}
	}

	return MonsterStructure;
}

/*
319+20-1

LoadMonsterBMD(19);
return LoadTextureMonster(a4, 338, a2, a3, 0); 

*/