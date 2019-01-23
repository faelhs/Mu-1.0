#include "StdAfx.h"
//=======================================
//-- New Wings Gameserver Visual Bug In Game
//=======================================

void ReadygObjMakePreviewCharSet()
{
	_asm
	{
		pushad
		mov eax, 0x00402068 + 1
		mov ecx, offset gObjMakePreviewCharSetEx
		sub ecx, 0x00402068 + 5
		mov[eax], ecx
		popad
	}
}

void gObjMakePreviewCharSetEx(int aIndex)
{
	gObjMakePreviewCharSet(aIndex);

	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	switch (lpObj->pInventory[7].m_Type)
	{
	case 0x194: /* Wing of Illusion */
		break;
	case 0x195: /* Wing of Space-Time */
		break;
	case 0x196: /* Wing of Storm */
		break;
	case 0x197: /* Wings of Downcast */
		break;
	case 0x198: /* Wing of Life[Ex702] */
		break;
	case 0x199: /* Wing of Chaos[Ex702] */
		break;
	case 0x19A: /* Wing of Power[Ex702] */
		break;
	}
}​