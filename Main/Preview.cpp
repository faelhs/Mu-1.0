#include "Principal.h"

CObjectPreview _obj_preview;

bool CObjectPreview::Loading()
{
	SetOp((LPVOID)0x004B655C, this->Render, ASM::CALL);
	SetOp((LPVOID)0x004B6B9C, this->Render, ASM::CALL);
	SetOp((LPVOID)0x004B6FA9, this->Render, ASM::CALL);
	SetOp((LPVOID)0x004CC15A, this->Render, ASM::CALL);
	SetOp((LPVOID)0x004FDAA9, this->Render, ASM::CALL);
	SetOp((LPVOID)0x0052F410, this->Render, ASM::CALL);
	SetOp((LPVOID)0x00585E93, this->Render, ASM::CALL);
	return true;
}

bool CObjectPreview::_render_handler(DWORD m_iMonsterID, DWORD Arg2, DWORD Arg3, DWORD Arg4, LPVOID lpObjectView)
{
	SObjectPreview * lpPreview = (SObjectPreview *)lpObjectView;
	// ----
	switch(m_iMonsterID)
	{
	case 257:
		{
			lstrcpy(lpPreview->Name, "admin");
		}
		break;
	}
	// ----
	return true;
}

LPVOID CObjectPreview::Render3(DWORD m_iMonsterID, DWORD Arg2, DWORD Arg3, DWORD Arg4)
{
	LPVOID lpRender = _find_object_3(m_iMonsterID, Arg2, Arg3, Arg4);
	// ----
	_obj_preview._render_handler(m_iMonsterID, Arg2, Arg3, Arg4, lpRender);
	// ----
	return lpRender;
}

LPVOID CObjectPreview::Render2(DWORD m_iMonsterID, DWORD Arg2, DWORD Arg3, DWORD Arg4)
{
	LPVOID lpRender = _find_object_2(m_iMonsterID, Arg2, Arg3, Arg4);
	// ----
	_obj_preview._render_handler(m_iMonsterID, Arg2, Arg3, Arg4, lpRender);
	// ----
	return lpRender;
}

LPVOID CObjectPreview::Render1(DWORD m_iMonsterID, DWORD Arg2, DWORD Arg3, DWORD Arg4)
{
	LPVOID lpRender = _find_object_1(m_iMonsterID, Arg2, Arg3, Arg4);
	// ----
	_obj_preview._render_handler(m_iMonsterID, Arg2, Arg3, Arg4, lpRender);
	// ----
	return lpRender;
}

LPVOID CObjectPreview::Render(DWORD Arg1, DWORD m_iMonsterID, DWORD Arg3, DWORD Arg4, DWORD Arg5)
{
	LPVOID lpRender = __object_render(Arg1, m_iMonsterID, Arg3, Arg4, Arg5);
	// ----
	SObjectPreview * lpView = (SObjectPreview *)lpRender;
	// ----
	switch(Arg1)
	{
	case 254:
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

			case 229:
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

		case 249:
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
	case 257:
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
	case 25:
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
	// ----
	return lpRender;
}