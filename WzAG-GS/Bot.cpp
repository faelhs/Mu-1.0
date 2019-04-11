#include "StdAfx.h"
#include "Bot.h"
ObjBot Bot;

void ObjBot::MakeBot(char* name, int map, int x, int y, int dir) {
	int result = gObjAddCallMon();
	if (result >= 0)
	{
		int index = result;
		gObj[result].m_PosNum = (WORD)-1;
		gObj[result].X = x+1;
		gObj[result].Y = y+1;
		gObj[result].m_OldX = x+1;
		gObj[result].m_OldY = y+1;
		gObj[result].TX = x+1;
		gObj[result].TY = y+1;
		gObj[result].MTX = x+1;
		gObj[result].MTY = y+1;
		gObj[result].Dir = dir;
		gObj[result].MapNumber = map;
		gObj[result].Live = TRUE;
		gObj[result].PathCount = 0;

		gObjSetMonster(result, 17);
		gObj[result].ChangeUP = 17 & 0x07;	// Set Second Type of Character
		gObj[result].Class = 17;
		gObj[result].Level = 400;
		gObj[result].Life = 1;
		gObj[result].MaxLife = 2;
		gObj[result].Mana = 1;
		gObj[result].MaxMana = 2;
		gObj[result].Experience = 0;
		gObj[result].DbClass = 17;
		strncpy(gObj[result].Name, name, sizeof(gObj[result].Name));

		gObjMakePreviewCharSet(result);
		gObj[result].m_AttackType = 0;
		gObj[result].m_Attribute = 100;
		gObj[result].TargetNumber = (WORD)-1;
		gObj[result].m_ActState.Emotion = 0;
		gObj[result].m_ActState.Attack = 0;
		gObj[result].m_ActState.EmotionCount = 0;
		gObj[result].PathCount = 0;
		gObj[result].m_MoveRange = 1;
		gObj[result].m_RecallMon = result;
		gObj[result].MaxLife = 1000;
		gObj[result].Life = gObj[result].MaxLife;
		gObj[result].m_Defense = 1000;
		GCRecallMonLife(gObj[result].m_RecallMon, gObj[result].MaxLife, gObj[result].Life);
		ChatSend(&gObj[result], "Olá Mestre");
//		GCActionSend(&gObj[result], 120, result, result);
		func.MsgUser(gObj->m_Index, 1, "Bot criado com sucesso.");
	}
	else {
		func.MsgUser(gObj->m_Index, 1, "Falha ao criar o bot.");
	}

}

bool ObjBot::CallPet(int aIndex, int pet, int x, int y) {
	if (gObj[aIndex].MapNumber == 10)
	{
		return false;
	}

	if (CC_MAP_RANGE(gObj[aIndex].MapNumber))
	{
		return false;
	}

	if (gObj[aIndex].m_RecallMon >= 0)
	{
		GCRecallMonLife(aIndex, 60, 0);
		gObjMonsterCallKill(aIndex);
		return false;
	}

	int result = gObjAddCallMon();

	if (result >= 0)
	{
		gObj[result].X = x;
		gObj[result].Y = y;
		gObj[result].MTX = x;
		gObj[result].MTY = y;
		gObj[result].Dir = 2;
		gObj[result].MapNumber = gObj[aIndex].MapNumber;
		gObjSetMonster(result, pet);
		gObj[result].m_RecallMon = aIndex;
		gObj[result].m_Attribute = 100;
		gObj[result].TargetNumber = (WORD)-1;
		gObj[result].m_ActState.Emotion = 0;
		gObj[result].m_ActState.Attack = 0;
		gObj[result].m_ActState.EmotionCount = 0;
		gObj[result].PathCount = 0;
		gObj[aIndex].m_RecallMon = result;
		gObj[result].m_MoveRange = 5;

		gObj[result].MaxLife += (gObj[result].MaxLife * gObj[aIndex].MaxLife) / 100.0f;
		gObj[result].Life = gObj[result].MaxLife;
		gObj[result].m_Defense += (gObj[result].m_Defense * gObj[aIndex].m_Defense) / 100.0f;

		GCRecallMonLife(gObj[result].m_RecallMon, gObj[result].MaxLife, gObj[result].Life);
		ChatSend(&gObj[result], "Olá Mestre");
		return true;
	}
	return false;
}