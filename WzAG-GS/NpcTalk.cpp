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



BOOL cNpc::NPCTalk(OBJECTSTRUCT* lpNpc, OBJECTSTRUCT* lpObj)
{
	switch (lpNpc->Class) 
	{
	case NPC_Gowter:
		{
			Npc.Gowther(lpNpc,lpObj);
			return TRUE;
		}
		break;
	case NPC_Helper:
		{
			Helper(lpObj,lpNpc);
			return true;
		}
		break;
	}

	return NpcTalkEx(lpNpc, lpObj);
}

bool ClickOnNPC(int aIndex,int aNPC)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);
	OBJECTSTRUCT *gObjNPC = (OBJECTSTRUCT*) OBJECT_POINTER (aNPC);

	if(gObjNPC->Class == NPC_Quest )
	{
		Qest_PGW.Q_NPC(aIndex,aNPC);
	}

	if (gObjNPC->Class == NPC_Quest_Elf)
	{
		Qest_PGW_ELF.Q_NPC(aIndex, aNPC);
	}

	if (gObjNPC->Class == NPC_Quest_Boss)
	{
		Qest_PGW_Boss.Q_NPC(aIndex, aNPC);
	}

	if (gObjNPC->Class == NPC_Quest_Loot)
	{
		Qest_PGW_Loot.Q_NPC(aIndex, aNPC);
	}
	return false;
}

cNpc Npc;