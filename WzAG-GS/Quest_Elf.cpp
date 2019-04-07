#include "StdAfx.h"


Q_PGW_ELF Qest_PGW_ELF;

void Q_PGW_ELF::Config()
{
	int EnableExQuest = GetPrivateProfileInt("Quest", "Ativar", 1, CFG_QUEST_ELF);

	if (EnableExQuest < 1) {
		return;
	}
}

bool Q_PGW_ELF::IsBadFileLine(char *FileLine, int &Flag)
{
	Qest_PGW.Config();

	if (Flag == 0)
	{
		if (isdigit(FileLine[0]))
		{
			Flag = FileLine[0] - 48;
			return true;
		}
	}
	else if (Flag < 0 || Flag > 9)
	{
		Flag = 0;
	}

	if (!strncmp(FileLine, "end", 3))
	{
		Flag = 0;
		return true;
	}

	if (FileLine[0] == '/' || FileLine[0] == '\n')
		return true;

	for (UINT i = 0; i < strlen(FileLine); i++)
	{
		if (isalnum(FileLine[i]))
			return false;
	}
	return true;
}

void Q_PGW_ELF::Q_Num()
{
	for (int i(0); i<1000; i++)
	{
		Number[i].Mob = 0;
		Number[i].Coun = 0;
		Number[i].proc = 0;
		Number[i].rew = 0;
		Number[i].gift = 0;
		Number[i].msg[0] = NULL;
		Number[i].msg2[0] = NULL;
		Number[i].msg3[0] = NULL;
	}
}

void Q_PGW_ELF::Q_Load()
{
	Qest_PGW.Config();

	Q_Num();
	FILE *file;
	file = fopen(CFG_QUEST_ELF, "r");
	if (file == NULL)
	{
		MessageBoxA(0, CFG_QUEST_ELF, "CRITICAL ERROR", 0);
		ExitProcess(1);
		return;
	}
	char Buff[256];
	int Flag = 0;
	Count = 0;

	while (!feof(file))
	{
		fgets(Buff, 256, file);

		if (IsBadFileLine(Buff, Flag)) continue;

		if (Flag == 1)
		{
			int n[10];
			char mes[100];
			char mes2[100];
			char mes3[100];
			//gets(mes);
			sscanf(Buff, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d \"%[^\"]\" \"%[^\"]\" \"%[^\"]\"", &n[0], &n[1], &n[2], &n[3], &n[4], &n[5], &n[6], &n[7], &n[8], &n[9], &n[10], &n[11], &n[12], &n[13], &mes, &mes2, &mes3);
			Number[Count].Mob = n[0];
			Number[Count].Coun = n[1];
			Number[Count].proc = n[2];
			Number[Count].rew = n[3];
			Number[Count].gift = n[4];
			Number[Count].Zen = n[5];
			Number[Count].exp = n[6];
			Number[Count].lvl = n[7];
			Number[Count].resets = n[8];
			Number[Count].teleport = n[9];
			Number[Count].map = n[10];
			Number[Count].x = n[11];
			Number[Count].y = n[12];
			Number[Count].reqmap = n[13];
			sprintf(Number[Count].msg, "%s", mes);
			sprintf(Number[Count].msg2, "%s", mes2);
			sprintf(Number[Count].msg3, "%s", mes3);
			Count++;
		}
	}
	fclose(file);
}


void Q_PGW_ELF::Q_NPC(int aIndex, int aNPC)
{
	Qest_PGW.Config();

	OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	OBJECTSTRUCT *gObjNPC = (OBJECTSTRUCT*)OBJECT_POINTER(aNPC);

	if ((gObjNPC->Class == NPC_Quest_Elf))
	{
		bool classe = gObj[aIndex].DbClass == DB_FAIRY_ELF || gObj[aIndex].DbClass == DB_MUSE_ELF;
		if (!classe) {
			ChatTargetSend(gObjNPC, "Começe por lorencia!", aIndex);
			MsgOutput(aIndex, "Sua classe incia em lorencia.");
			return;
		}
		if (QuestUser[aIndex].Quest_Num < Count)
		{

			if (QuestUser[aIndex].Quest_Start == 0)
			{
				if (QuestUser[aIndex].Quest_Num == 0 && lpObj->Level >= Number[QuestUser[aIndex].Quest_Num].lvl && Custom[aIndex].Resets >= Number[QuestUser[aIndex].Quest_Num].resets &&  lpObj->MapNumber == Number[QuestUser[aIndex].Quest_Num].reqmap)
				{
					ChatTargetSend(gObjNPC, "[Quest] Aceita!", aIndex);
					QuestUser[aIndex].Quest_Start = 1;
					Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Start = 1 WHERE Name='%s'", lpObj->Name);
					MsgOutput(aIndex, "[Quest] Quest N: %d", QuestUser[aIndex].Quest_Num + 1);
					MsgOutput(aIndex, "[Quest] %s", Number[QuestUser[aIndex].Quest_Num].msg);
					MsgOutput(aIndex, "[Quest] Mate %s [%d/%d]", Number[QuestUser[aIndex].Quest_Num].msg2, QuestUser[aIndex].Quest_kill, Number[QuestUser[aIndex].Quest_Num].Coun);
					if (Number[QuestUser[aIndex].Quest_Num].teleport > 0) {
						gObjTeleport(gObj[aIndex].m_Index, Number[QuestUser[aIndex].Quest_Num].map, Number[QuestUser[aIndex].Quest_Num].x, Number[QuestUser[aIndex].Quest_Num].y);
					}
					return;
				}
				else if (QuestUser[aIndex].Quest_Num > 0 && lpObj->Level >= Number[QuestUser[aIndex].Quest_Num].lvl && Custom[aIndex].Resets >= Number[QuestUser[aIndex].Quest_Num].resets &&  lpObj->MapNumber == Number[QuestUser[aIndex].Quest_Num].reqmap)
				{
					QuestUser[aIndex].Quest_Start = 1;
					Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Start = 1 WHERE Name='%s'", lpObj->Name);
					MsgOutput(aIndex, "[Quest] Quest N: %d", QuestUser[aIndex].Quest_Num + 1);
					MsgOutput(aIndex, "[Quest] %s", Number[QuestUser[aIndex].Quest_Num].msg);
					MsgOutput(aIndex, "[Quest] Mate %s [%d/%d]", Number[QuestUser[aIndex].Quest_Num].msg2, QuestUser[aIndex].Quest_kill, Number[QuestUser[aIndex].Quest_Num].Coun);
					ChatTargetSend(gObjNPC, "Complete essa nova Quest!", aIndex);
					if (Number[QuestUser[aIndex].Quest_Num].teleport > 0) {
						gObjTeleport(gObj[aIndex].m_Index, Number[QuestUser[aIndex].Quest_Num].map, Number[QuestUser[aIndex].Quest_Num].x, Number[QuestUser[aIndex].Quest_Num].y);
					}
					return;
				}
				else if (lpObj->Level < Number[QuestUser[aIndex].Quest_Num].lvl && Custom[aIndex].Resets < Number[QuestUser[aIndex].Quest_Num].resets) {
					MsgOutput(aIndex, "[Quest]Volte no level: %d", Number[QuestUser[aIndex].Quest_Num].lvl);
					MsgOutput(aIndex, "[Quest]Volte com %d resets", Number[QuestUser[aIndex].Quest_Num].resets);
				}
				else if (lpObj->Level < Number[QuestUser[aIndex].Quest_Num].lvl) {
					MsgOutput(aIndex, "[Quest]Volte no level: %d", Number[QuestUser[aIndex].Quest_Num].lvl);
				}
				else if (Custom[aIndex].Resets < Number[QuestUser[aIndex].Quest_Num].resets) {
					MsgOutput(aIndex, "[Quest]Volte com %d resets", Number[QuestUser[aIndex].Quest_Num].resets);
				}
				else if (lpObj->MapNumber != Number[QuestUser[aIndex].Quest_Num].reqmap) {
					MsgOutput(aIndex, "[Quest] %s", Number[QuestUser[aIndex].Quest_Num].msg3);
				}
				else {
					MsgOutput(aIndex, "Verifica esse erro...");
				}
			}
			else if (QuestUser[aIndex].Quest_Start == 1)
			{

				if (QuestUser[aIndex].Quest_kill == Number[QuestUser[aIndex].Quest_Num].Coun)
				{
					int ExQuest_gift = Presents(aIndex, Number[QuestUser[aIndex].Quest_Num].rew, Number[QuestUser[aIndex].Quest_Num].gift);
					if (ExQuest_gift == false)
					{
						ChatTargetSend(gObjNPC, "Premiação desativada!", aIndex);
						return;
					}

					if (QuestUser[aIndex].Quest_Num == Count)
					{
						MsgOutput(aIndex, "[Quest] Finalzada");
						return;
					}

					QuestUser[aIndex].Quest_Start = 0;
					QuestUser[aIndex].Quest_Num++;
					QuestUser[aIndex].Quest_kill = 0;
					ChatTargetSend(gObjNPC, "Parabéns!", aIndex);
					Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Start = 0 WHERE Name='%s'", lpObj->Name);
					Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Kill = 0 WHERE Name='%s'", lpObj->Name);
					Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Num = Quest_Num + 1 WHERE Name='%s'", lpObj->Name);
					return;
				}
				else
				{
					ChatTargetSend(gObjNPC, "Volte quando tiver terminado!", aIndex);
					MsgOutput(aIndex, "[Quest] %s", Number[QuestUser[aIndex].Quest_Num].msg);
					MsgOutput(aIndex, "[Quest] %s [%d/%d]", Number[QuestUser[aIndex].Quest_Num].msg2, QuestUser[aIndex].Quest_kill, Number[QuestUser[aIndex].Quest_Num].Coun);
					return;
				}
			}
		}
		else
		{
			ChatTargetSend(gObjNPC, "Você completou todas as Quest!", aIndex);
			MsgOutput(aIndex, "Você completou todas as Quest");
			return;
		}
	}

}

void Q_PGW_ELF::KilledMob(int aIndex)
{
	Qest_PGW.Config();
	OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	int iRate = rand() % 100 + 1;
	if (iRate >= 0)
	{

		if (QuestUser[aIndex].Quest_kill < Number[QuestUser[aIndex].Quest_Num].Coun)
		{
			QuestUser[aIndex].Quest_kill++;
			
			
			if (QuestUser[aIndex].Quest_kill == Number[QuestUser[aIndex].Quest_Num].Coun)
			{
				MsgOutput(aIndex, "[Quest] Retorne ao NPC!");
				func.MsgUser(aIndex, 0, "[Quest] Retorne ao NPC!");
			}
		}
	}
}

bool Q_PGW_ELF::Presents(int aIndex, int Present, int Gifts)
{
	OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	switch (Present)
	{

	case 1:
	{
		lpObj->LevelUpPoint += Gifts;
		lpObj->Level += Number[QuestUser[aIndex].Quest_Num].exp;
		if (lpObj->DbClass == DB_MAGIC_GLADIATOR || lpObj->DbClass == DB_DARK_LORD) {
			lpObj->LevelUpPoint += Number[QuestUser[aIndex].Quest_Num].exp * 7;
		}
		else {
			lpObj->LevelUpPoint += Number[QuestUser[aIndex].Quest_Num].exp * 5;
		}
		GCMoneySend(aIndex, lpObj->Money += Number[QuestUser[aIndex].Quest_Num].Zen);
		func.UpdateCharacter(aIndex, false);
		MsgOutput(aIndex, "[Quest] %s  Premiado com %d Points", lpObj->Name, Gifts);
		if (Number[QuestUser[aIndex].Quest_Num].Zen > 0) { MsgOutput(aIndex, "[Quest] %s  Premiado com %d Zen", lpObj->Name, Number[QuestUser[aIndex].Quest_Num].Zen); }
		if (Number[QuestUser[aIndex].Quest_Num].exp > 0) { MsgOutput(aIndex, "[Quest] %s  Premiado com %d Level", lpObj->Name, Number[QuestUser[aIndex].Quest_Num].exp); }
		func.LevelUPSend(aIndex);
	}
	break;
	case 2:
	{
		Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Resets = Resets + %d WHERE Name='%s'", lpObj->Name);
		lpObj->Level += Number[QuestUser[aIndex].Quest_Num].exp;
		if (lpObj->DbClass == DB_MAGIC_GLADIATOR || lpObj->DbClass == DB_DARK_LORD) {
			lpObj->LevelUpPoint += Number[QuestUser[aIndex].Quest_Num].exp * 7;
		}
		else {
			lpObj->LevelUpPoint += Number[QuestUser[aIndex].Quest_Num].exp * 5;
		}
		MsgOutput(aIndex, "[Quest] %s  Premiado com %d Resets", lpObj->Name, Gifts);
		if (Number[QuestUser[aIndex].Quest_Num].Zen > 0) { MsgOutput(aIndex, "[Quest] %s  Premiado com %d Zen", lpObj->Name, Number[QuestUser[aIndex].Quest_Num].Zen); }
		if (Number[QuestUser[aIndex].Quest_Num].exp > 0) { MsgOutput(aIndex, "[Quest] %s  Premiado com %d Level", lpObj->Name, Number[QuestUser[aIndex].Quest_Num].exp); }
		GCMoneySend(aIndex, lpObj->Money += Number[QuestUser[aIndex].Quest_Num].Zen);
		func.LevelUPSend(aIndex);

	}
	break;
	case 3:
	{
		Manager.ExecFormat("UPDATE [MuOnline].[dbo].[MEMB_INFO] SET Gold = Gold + %d WHERE memb___id='%s'", lpObj->AccountID);
		lpObj->Level += Number[QuestUser[aIndex].Quest_Num].exp;
		if (lpObj->DbClass == DB_MAGIC_GLADIATOR || lpObj->DbClass == DB_DARK_LORD) {
			lpObj->LevelUpPoint += Number[QuestUser[aIndex].Quest_Num].exp * 7;
		}
		else {
			lpObj->LevelUpPoint += Number[QuestUser[aIndex].Quest_Num].exp * 5;
		}
		MsgOutput(aIndex, "[Quest] %s  Premiado com %d Golds", lpObj->Name, Gifts);
		if (Number[QuestUser[aIndex].Quest_Num].Zen > 0) { MsgOutput(aIndex, "[Quest] %s  Premiado com %d Zen", lpObj->Name, Number[QuestUser[aIndex].Quest_Num].Zen); }
		if (Number[QuestUser[aIndex].Quest_Num].exp > 0) { MsgOutput(aIndex, "[Quest] %s  Premiado com %d Level", lpObj->Name, Number[QuestUser[aIndex].Quest_Num].exp); }
		GCMoneySend(aIndex, lpObj->Money += Number[QuestUser[aIndex].Quest_Num].Zen);
		func.LevelUPSend(aIndex);
	}
	break;
	case 4: {
		char  str[20];
		_itoa(Gifts, str, 10);
		int qtd = 1;
		char cmd[255] = "";
		int index = 0;
		int id = 0;
		int lvl = 0;
		int dur = 0;
		int opt = 0;
		int exc = 0;
		int luck = 0;
		int skill = 0;
		int preco = 0;
		bool existe = 0;
		int saldo = 0;
		int exib;
		for (int x = 0; x < Quest_Item_RewardCount; x++)
		{
			if (!strcmp(Quest_Item_RewardInfo[x].itemnome, str) || !strcmp(Quest_Item_RewardInfo[x].itemexib, str))
			{
				exib = x;
				index = Quest_Item_RewardInfo[x].itemindex;
				id = Quest_Item_RewardInfo[x].itemid;
				lvl = Quest_Item_RewardInfo[x].itemlvl;
				dur = Quest_Item_RewardInfo[x].itemdur;
				opt = Quest_Item_RewardInfo[x].itemopt;
				exc = Quest_Item_RewardInfo[x].itemexc;
				luck = Quest_Item_RewardInfo[x].itemluck;
				skill = Quest_Item_RewardInfo[x].itemskill;
				preco = Quest_Item_RewardInfo[x].itempreco;
				existe = 1;
			}
		}
		if (existe) {
			sprintf(cmd, "%d %d %d %d %d %d %d %d", index, id, lvl, dur, skill, luck, opt, exc);
			Command.makecomprar(aIndex, cmd, ("Quest Reward %s", Quest_Item_RewardInfo[exib].itemexib));
			lpObj->Level += Number[QuestUser[aIndex].Quest_Num].exp;
			if (lpObj->DbClass == DB_MAGIC_GLADIATOR || lpObj->DbClass == DB_DARK_LORD) {
				lpObj->LevelUpPoint += Number[QuestUser[aIndex].Quest_Num].exp * 7;
			}
			else {
				lpObj->LevelUpPoint += Number[QuestUser[aIndex].Quest_Num].exp * 5;
			}
			GCMoneySend(aIndex, lpObj->Money += Number[QuestUser[aIndex].Quest_Num].Zen);
			MsgOutput(aIndex, "[Quest] %s  Premiado com %s ", lpObj->Name, Quest_Item_RewardInfo[exib].itemexib);
			if (Number[QuestUser[aIndex].Quest_Num].Zen > 0) { MsgOutput(aIndex, "[Quest] %s  Premiado com %d Zen", lpObj->Name, Number[QuestUser[aIndex].Quest_Num].Zen); }
			if (Number[QuestUser[aIndex].Quest_Num].exp > 0) { MsgOutput(aIndex, "[Quest] %s  Premiado com %d Level", lpObj->Name, Number[QuestUser[aIndex].Quest_Num].exp); }
			func.LevelUPSend(aIndex);
		}
	}
			break;
	}

	return true;
}

void ClickNPCElf(int aIndex, int aNPC)
{
	ClickOnNPC(aIndex, aNPC);
}