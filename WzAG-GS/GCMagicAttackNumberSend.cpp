#include "stdafx.h"


void ReadyGCMagicAttackNumberSend()
{
	func.HookThis((DWORD)&_GCMagicAttackNumberSend,0x004049FD);
}

int CalDistance(int x, int y, int x1, int y1)  
{
	if (x == x1 && y == y1)
	{
		return 0;
	}

	float tx = x - x1;
	float ty = y - y1;

	return sqrt(tx*tx + ty*ty);
}

void _GCMagicAttackNumberSend(LPOBJ lpObj, WORD MagicNumber, int usernumber,  BYTE skillsuccess)
{

	if( MagicNumber == AT_SKILL_KNIGHTADDLIFE )
	{
	   CMagicInf * lpMagic = gObjGetMagicSearch(lpObj,AT_SKILL_FLASH);

		for (int n = 0; n < MAX_VIEWPORT_MONSTER; n++) 
		{
			LPOBJ lpMonster = (LPOBJ)OBJECT_POINTER(lpObj->VpPlayer2[n].number); 

			if( lpMonster >= 0 )
			{
				if ( lpMonster->Type == MONSTER )
				{	
					if(CalDistance(lpObj->X,lpObj->Y,lpMonster->X,lpMonster->Y) < 10) 
					{
						gObjAttack(lpObj,lpMonster,lpMagic,1,0,999,0);
					}
				}
			}
		}
	}

	GCMagicAttackNumberSend(lpObj,MagicNumber,usernumber,skillsuccess);

}


