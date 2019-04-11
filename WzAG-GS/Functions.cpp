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

void Functions::HookThis(DWORD dwMyFuncOffset,DWORD dwJmpOffset)
{
	*(DWORD*)(dwJmpOffset+1) = dwMyFuncOffset-(dwJmpOffset+5);
}


void Functions::HookProc(DWORD Offset, DWORD Func)
{
	*(BYTE*)(Offset) = 0xE9;
	*(DWORD*)(Offset+1) = (DWORD)(Func)-(Offset+5);
}

void Functions::SetNop(DWORD Offset,int Size)
{
	for (int n = 0; n < Size; n++)
	{
		*(BYTE*)(Offset + n) = 0x90;
	}
}

void Functions::Set00(DWORD Offset,int Size)
{
	for (int n = 0; n < Size; n++)
	{
		*(BYTE*)(Offset + n) = 0x00;
	}
}

void Functions::SetRetn(DWORD Offset)
{
	*(BYTE*)(Offset) = 0xC3;
}

void Functions::SetRRetn(DWORD Offset)
{
	*(BYTE*)(Offset) = 0xC3;
	*(BYTE*)(Offset+1) = 0x90;
	*(BYTE*)(Offset+2) = 0x90;
	*(BYTE*)(Offset+3) = 0x90;
	*(BYTE*)(Offset+4) = 0x90;
}

void Functions::SetByte(DWORD Offset,BYTE btValue)
{
	*(BYTE*)(Offset) = btValue;
}

void Functions::SetString(DWORD Offset, char* btString, int Size)
{
	memset((char*) Offset, 0x00, Size);
	memcpy((char*) Offset, btString, Size);
}

int Functions::Get_PlayerIndex(char *Name)
{    
	for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{     
		if (gObj[i].Connected > 2)
		{
			if (!strcmp(gObj[i].Name, Name))
			{
				return i;
			}
		}
	}

	return -1;
}

void Functions::MosterAdd(int MobID, int MapID, int CoordX, int CoordY)
{
	int mIndex = gObjAddMonster(MapID);

	if (mIndex >= 0)
	{
		gObjSetMonster(mIndex, MobID);
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(mIndex);
		gObj->Class = MobID;
		gObj->MapNumber = MapID;
		gObj->X = CoordX;
		gObj->Y = CoordY;
	}

	//return mIndex;
}

void Functions::GCWarePassSend(int aIndex, PMSG_WAREHOUSEPASSSEND * lpMsg)
{
	switch (lpMsg->Type)
	{
	case 0:
	{
		if (lpMsg->Pass != gObj[aIndex].WarehousePW)
		{
			GCWarehouseStateSend(aIndex, 10);
			return;
		}
		else
		{
			gObj[aIndex].WarehouseLock = 0;
			gObj[aIndex].WarehousePW = 0;
			GCWarehouseStateSend(aIndex, gObj[aIndex].WarehouseLock);
			GCWarehouseRecivePassword(aIndex, lpMsg);
		}
	}
	break;
	case 1:
	{
		gObj[aIndex].WarehouseLock = 1;
		gObj[aIndex].WarehousePW = lpMsg->Pass;
		GCWarehouseStateSend(aIndex, gObj[aIndex].WarehouseLock);
	}
	break;
	case 2:
	{
		if (lpMsg->Pass != gObj[aIndex].WarehousePW)
		{
			GCWarehouseStateSend(aIndex, 10);
			return;
		}
		else
		{
			GCWarehouseStateSend(aIndex, 0);
			GCWarehouseRecivePassword(aIndex, lpMsg);
		}
	}
	break;
	}

	GCWarehouseRecivePassword(aIndex, lpMsg);
}

void Functions::gObjLifeCheckHook(LPOBJ lpTargetObj, LPOBJ lpObj, int AttackDamage, int DamageSendType, int MSBFlag, int MSBDamage, BYTE Skill,int iShieldDamage)
{	
	PBYTE a_aIndex = 0;
	PBYTE b_mIndex = 0;

	a_aIndex = (PBYTE)lpObj;
	b_mIndex = (PBYTE)lpTargetObj;

	WORD mIndex = 0;
	WORD aIndex = 0;

	memcpy(&mIndex, b_mIndex+0x00,sizeof(WORD));
	memcpy(&aIndex, a_aIndex+0x00,sizeof(WORD));

	OBJECTSTRUCT *mObj = (OBJECTSTRUCT*) OBJECT_POINTER (mIndex);
	OBJECTSTRUCT *pObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);

	// --------------------------------------------------
	// - [] Quest System
	// --------------------------------------------------
	bool classe = (gObj[aIndex].DbClass == DB_FAIRY_ELF || gObj[aIndex].DbClass == DB_MUSE_ELF) && (QuestUser[aIndex].Quest_Num < Qest_PGW_ELF.Count);

	if(QuestUser[aIndex].Quest_Start == 1 && mObj->Class == Qest_PGW.Number[QuestUser[aIndex].Quest_Num].Mob && mObj->Life <= 0 && !classe)
	{
		Qest_PGW.KilledMob(aIndex);
		if(QuestUser[aIndex].Quest_kill < Qest_PGW.Number[QuestUser[aIndex].Quest_Num].Coun){
			func.MsgUser(aIndex, 0, "[Quest] %s [%d/%d]", Qest_PGW.Number[QuestUser[aIndex].Quest_Num].msg2, QuestUser[aIndex].Quest_kill, Qest_PGW.Number[QuestUser[aIndex].Quest_Num].Coun);
		}else{
			func.MsgUser(aIndex, 0, "[Quest] Concluida Retorne ao NPC");
		}
	}
	if (QuestUser[aIndex].Quest_Start == 1 && mObj->Class == Qest_PGW_ELF.Number[QuestUser[aIndex].Quest_Num].Mob && mObj->Life <= 0 && classe)
	{
		Qest_PGW_ELF.KilledMob(aIndex);
		if(QuestUser[aIndex].Quest_kill < Qest_PGW_ELF.Number[QuestUser[aIndex].Quest_Num].Coun){
			func.MsgUser(aIndex, 0, "[Quest] %s [%d/%d]", Qest_PGW_ELF.Number[QuestUser[aIndex].Quest_Num].msg2, QuestUser[aIndex].Quest_kill, Qest_PGW_ELF.Number[QuestUser[aIndex].Quest_Num].Coun);
		}else{
			func.MsgUser(aIndex, 0, "[Quest] Concluida Retorne ao NPC");
		}
	}
	if (QuestBoss[aIndex].Quest_Start == 1 && mObj->Class == Qest_PGW_Boss.Number[QuestBoss[aIndex].Quest_Num].Mob && mObj->Life <= 0)
	{
		Qest_PGW_Boss.KilledMob(aIndex);
		if(QuestBoss[aIndex].Quest_kill < Qest_PGW_Boss.Number[QuestBoss[aIndex].Quest_Num].Coun){
			func.MsgUser(aIndex, 0, "[QuestBoss] %s [%d/%d]", Qest_PGW_Boss.Number[QuestBoss[aIndex].Quest_Num].msg2, QuestBoss[aIndex].Quest_kill, Qest_PGW_Boss.Number[QuestBoss[aIndex].Quest_Num].Coun);
		}else{
			func.MsgUser(aIndex, 0, "[QuestBoss] Concluida Retorne ao NPC");
		}
	}
	if (QuestLoot[aIndex].Quest_Start == 1 && mObj->Class == Qest_PGW_Loot.Number[QuestLoot[aIndex].Quest_Num].Mob && mObj->Life <= 0)
	{
		Qest_PGW_Loot.KilledMob(aIndex);
		if(QuestLoot[aIndex].Quest_kill < Qest_PGW_Loot.Number[QuestLoot[aIndex].Quest_Num].Coun){
			func.MsgUser(aIndex, 0, "[QuestLoot] %s [%d/%d]", Qest_PGW_Loot.Number[QuestLoot[aIndex].Quest_Num].msg2, QuestLoot[aIndex].Quest_kill, Qest_PGW_Loot.Number[QuestLoot[aIndex].Quest_Num].Coun);
		}else{
			func.MsgUser(aIndex, 0, "[QuestLoot] Concluida Retorne ao NPC");
		}
	}
	if (Hydra._Active != 0)
	{
		if (mObj->Life <= 0 && mObj->Live != 0 )
		{	
			if (mObj->Type == MONSTER && mObj->Class == 49)
			{	
				func.FireWork(pObj->m_Index);
				Hydra.Dropitem(pObj->m_Index);
				Hydra._Alive = false;
			}
		}
	}

	gObjLifeCheck(mObj,pObj,AttackDamage,DamageSendType,MSBFlag,MSBDamage,Skill,iShieldDamage); 
}

void Functions::FireWork(int aIndex)
{
	if (gObj[aIndex].X <= 5 || gObj[aIndex].X >= 250 || gObj[aIndex].Y <= 5 || gObj[aIndex].Y >= 250)
	{
		return;
	}

	char PacketRand[5] = {-2, -1, 0, 1, 2};

	BYTE Packet[20][7];

	for (int i = 0; i < 20; i++)
	{
		BYTE RandX = (rand() % 5)*2 - 4;
		BYTE RandY = (rand() % 5)*2 - 4;

		Packet[i][0] = 0xC1;
		Packet[i][1] = 0x07;
		Packet[i][2] = 0xF3;
		Packet[i][3] = 0x40;
		Packet[i][4] = 0x00;
		Packet[i][5] = (BYTE)(gObj[aIndex].X + PacketRand[RandX]);
		Packet[i][6] = (BYTE)(gObj[aIndex].Y + PacketRand[RandY]);
	}

	for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if (gObj[i].Connected == 3 /*&& gObj[i].MapNumber == 7*/)
		{
			for (int n = 0; n < 3; n++)
			{
				DataSend(i,Packet[n],(DWORD)Packet[n][1]);
			}
		}
	}
}

BOOL Functions::HookgObjAttack(OBJECTSTRUCT* lpObj, OBJECTSTRUCT* lpTargetObj, class CMagicInf* lpMagic, int magicsend, unsigned char MSBFlag, int AttackDamage, BOOL bCombo)
{
	if (lpTargetObj->Authority > 1)
	{
		return FALSE;
	}

	if (!Duel.Attack(lpObj, lpTargetObj))
	{
		return FALSE;
	}

	if (!Pega.Attack(lpObj, lpTargetObj))
	{
		return FALSE;
	}

	if (!Sobre.Attack(lpObj, lpTargetObj))
	{
		return FALSE;
	}

	if (lpObj->Type == PLAYER)	
	{
		func.CheckPet(lpObj);
	}

	if (lpTargetObj->Type == PLAYER)
	{
		func.CheckPet(lpTargetObj);
	}
	
	return gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
}

void Functions::gObjPlayerKillerEx(LPOBJ lpObj, LPOBJ lpTargetObj)
{  
	gObjPlayerKiller(lpObj,lpTargetObj); 

}

void Functions::gObjInterfaceTimeCheckEx(LPOBJ lpObj)
{
	Sobre.PlayerOut(lpObj);
	//func.Check(lpObj);

	gObjInterfaceTimeCheck(lpObj);
}

void Functions::gObjSecondProcEx()
{
	Duel.Run();
	Pega.Run();
	Sobre.Run();
	Tips.Send();
	News.Send();

	for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if (gObj[i].Type == PLAYER)
		{
			func.HealthBarSend(&gObj[i]);
			func.ChkJail(&gObj[i]);
			//func.QuestsSend(&gObj[i]);
		}
	}

	gObjSecondProc();
}

void Functions::gObjCloseSetEx(int aIndex, int flag)
{
	if(gObj[aIndex].Type == PLAYER){
	func.SaveQuest(aIndex);
	Duel.Quit(&gObj[aIndex]);
	Pega.Quit(&gObj[aIndex]);
	Sobre.Quit(&gObj[aIndex]);
	}
	return gObjCloseSet(aIndex,flag);  
}
void Functions::SaveQuest(int aIndex)
{
	Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Boss_Kill = %d WHERE Name='%s'", QuestBoss[aIndex].Quest_kill, &gObj[aIndex].Name);
	Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Loot_Kill = %d WHERE Name='%s'", QuestLoot[aIndex].Quest_kill, &gObj[aIndex].Name);
	Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Kill = %d WHERE Name='%s'", QuestUser[aIndex].Quest_kill, &gObj[aIndex].Name);
	Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Boss_Num = %d WHERE Name='%s'", QuestBoss[aIndex].Quest_Num, &gObj[aIndex].Name);
	Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Loot_Numl = %d WHERE Name='%s'", QuestLoot[aIndex].Quest_Num, &gObj[aIndex].Name);
	Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Num = %d WHERE Name='%s'", QuestUser[aIndex].Quest_Num, &gObj[aIndex].Name);
	Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Boss_Start = %d WHERE Name='%s'", QuestBoss[aIndex].Quest_Start, &gObj[aIndex].Name);
	Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Loot_Start = %d WHERE Name='%s'", QuestLoot[aIndex].Quest_Start, &gObj[aIndex].Name);
	Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Start = %d WHERE Name='%s'", QuestUser[aIndex].Quest_Start, &gObj[aIndex].Name);
}
short Functions::gObjDelEx(int aIndex)
{
	Duel.Quit(&gObj[aIndex]);
	Pega.Quit(&gObj[aIndex]);
	Sobre.Quit(&gObj[aIndex]);
	func.SaveQuest(aIndex);
	return gObjDel(aIndex);
}

void Functions::gObjUserDieEx(LPOBJ lpObj, LPOBJ lpTargetObj)
{
	Duel.Die(lpObj);
	Sobre.Die(lpObj,lpTargetObj);

	gObjUserDie(lpObj, lpTargetObj);
}

BYTE Functions::gObjInventoryMoveItemEx(int aIndex, unsigned char source, unsigned char target, int& durSsend, int& durTsend, unsigned char sFlag, unsigned char tFlag, unsigned char* siteminfo)
{
	if (!Pega.Equip(&gObj[aIndex], source, target))
	{
		return (BYTE)(-1);
	}

	return gObjInventoryMoveItem(aIndex, source, target, durSsend, durTsend, sFlag, tFlag, siteminfo);
}

bool Functions::gObjLevelUpEx(LPOBJ lpObj, int addexp, int iMonsterType, int iEventType)
{
	bool Result = gObjLevelUp(lpObj, addexp, iMonsterType, iEventType);

	PMSG_UPDATEPOINTS pMsg;

	pMsg.h.c = 0xC1;
	pMsg.h.size = sizeof(pMsg);
	pMsg.h.headcode = 0xFE;
	pMsg.subcode = 0x08;
	pMsg.LevelUpPoint = lpObj->LevelUpPoint;

	DataSend(lpObj->m_Index, (LPBYTE)&pMsg, pMsg.h.size);

	return Result;
}

BOOL Functions::GetBoxPosition(int MapNumber, int X, int Y, int W, int H, short& rX, short& rY)
{
	BOOL Result = FALSE;

	__asm
	{
		PUSH rY;
		PUSH rX;
		PUSH H;
		PUSH W;
		PUSH Y;
		PUSH X;
		PUSH MapNumber;
		MOV ECX, 0x9541288;
		MOV EDI, 0x403DF5;
		CALL EDI;
		MOV Result, EAX;
	}

	return Result;
}

void Functions::MakeNoticeMsg(void * lpNotice, BYTE btType, char * szNoticeMsg)
{
	PMSG_NOTICE * pNotice = (PMSG_NOTICE *)lpNotice;
	pNotice->type  = btType;

	wsprintf(pNotice->Notice,szNoticeMsg);
	PHeadSetB((LPBYTE)pNotice,0x0D,strlen(pNotice->Notice) + sizeof(PMSG_NOTICE) - sizeof(pNotice->Notice) + 1);
}

void Functions::MsgUser(int aIndex, int Type, char * Msg, ...)
{
	char szBuffer[1024];
	va_list pArguments;
	va_start(pArguments,Msg);
	vsprintf(szBuffer,Msg,pArguments);
	va_end(pArguments);
	PMSG_NOTICE pNotice;
	MakeNoticeMsg(&pNotice,Type,szBuffer);
	DataSend(aIndex,(LPBYTE)&pNotice,pNotice.h.size);
}

void Functions::MsgAllUser(int Type, char * Msg, ...)
{
	char szBuffer[1024];
	va_list pArguments;
	va_start(pArguments,Msg);
	vsprintf(szBuffer,Msg,pArguments);
	va_end(pArguments);
	PMSG_NOTICE pNotice;
	MakeNoticeMsg(&pNotice,Type,szBuffer);
	DataSendAll((LPBYTE)&pNotice,pNotice.h.size);
}

void Functions::AllSendServerMsg(char* chatmsg)
{
	char szBuffer[1024];
	va_list pArguments;
	va_start(pArguments,chatmsg);
	vsprintf(szBuffer,chatmsg,pArguments);
	va_end(pArguments);

	PMSG_NOTICE pNotice;

	func.MakeNoticeMsg(&pNotice,0,szBuffer);

	for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if (gObj[i].Connected == 3)
		{
			if (gObj[i].Type == PLAYER)
			{
				DataSend(i,(unsigned char*)&pNotice, pNotice.h.size);
			}
		}
	}
}

void Functions::BlueChatSend(LPCSTR Nome, LPSTR Mensagem, DWORD aIndex)
{
	BYTE Buffer[0xFF] = {0};
	BYTE Len=strlen(Mensagem);
	Buffer[0] = 0xC1;
	Buffer[1] = Len + 15;
	Buffer[2] = 0x00;
	strncpy((char*)&Buffer[3],Nome,10);
	Buffer[13] = 0x7E;
	strncpy((char*)&Buffer[14],Mensagem,Len);

	for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if (gObj[i].Connected == 3)
		{
			DataSend(i,(unsigned char*)Buffer,Buffer[1]);
		}
	}
}

void Functions::GreenChatSend(LPCSTR Nome, LPSTR Mensagem, DWORD aIndex)
{
	BYTE Buffer[0xFF] = {0};
	BYTE Len=strlen(Mensagem);
	Buffer[0] = 0xC1;
	Buffer[1] = Len + 15;
	Buffer[2] = 0x00;
	Buffer[13] = 0x40;
	strncpy((char*)&Buffer[3],Nome,10);
	strncpy((char*)&Buffer[14],Mensagem,Len);

	for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if (gObj[i].Connected == 3)
		{
			DataSend(i, (unsigned char*)Buffer, Buffer[1]);
		}
	} 
}

void Functions::YellowChatSend(LPCSTR Nome, LPSTR Mensagem, DWORD aIndex)
{
	BYTE Buffer[0xFF] = {0};
	BYTE Len = strlen(Mensagem);
	Buffer[0] = 0xC1;
	Buffer[1] = Len + 14;
	Buffer[2] = 0x02;
	strncpy((char*)&Buffer[3],Nome,10);
	strncpy((char*)&Buffer[13],Mensagem,Len);

	for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
        if (gObj[i].Connected == 3)
		{
			DataSend(i,(unsigned char*)Buffer,Buffer[1]);
		}
	}
}

void Functions::UpdateCharacter(int aIndex, bool Effect)
{
	PMSG_UPDATECHARACTER pMsg;

	pMsg.h.c = 0xC1;
	pMsg.h.size = sizeof(PMSG_UPDATECHARACTER);
	pMsg.h.headcode = 0xFE;
	pMsg.Code = (Effect == true) ? 1 : 2;
	pMsg.Experience = gObj[aIndex].Experience;
	pMsg.NextExperience = gObj[aIndex].NextExp;
	pMsg.Level = (WORD)(gObj[aIndex].Level);
	pMsg.LevelUpPoint = gObj[aIndex].LevelUpPoint;
	pMsg.Strength = (WORD)(gObj[aIndex].Strength);
	pMsg.Dexterity = (WORD)(gObj[aIndex].Dexterity);
	pMsg.Vitality = (WORD)(gObj[aIndex].Vitality);
	pMsg.Energy = (WORD)(gObj[aIndex].Energy);
	pMsg.Leadership = (WORD)(gObj[aIndex].Leadership);
	pMsg.Life = (WORD)(gObj[aIndex].Life);
	pMsg.MaxLife = (WORD)(gObj[aIndex].MaxLife);
	pMsg.Mana = (WORD)(gObj[aIndex].Mana);
	pMsg.MaxMana = (WORD)(gObj[aIndex].MaxMana);
	pMsg.BP = (WORD)(gObj[aIndex].BP);
	pMsg.MaxBP = (WORD)(gObj[aIndex].MaxBP);

	DataSend(aIndex, (LPBYTE)(&pMsg), pMsg.h.size);

	CBalancer::gObjCalCharacter(aIndex);
	gObjCalcMaxLifePower(aIndex);
}

int Functions::GetInventoryItemCount(int aIndex, int Type, int Level)
{
	int count = 0;

	for(unsigned i = 12; i < 76; i++)
	{
		if(gObj[aIndex].pInventory[i].m_Type == Type)
		{
			if(Level != -1)
			{
				if(!gObj[aIndex].pInventory[i].m_Level == Level)
				{
					continue;
				}
			}

			count++;
		}
	}

	return count;
}

int Functions::gObjDeleteItemsCount(int gObjId, short Type, short Level, int Count)
{
	int count = 0;

	for(int i = 12; i < 76; i++)
	{
		if(gObj[gObjId].pInventory[i].m_Type == Type && gObj[gObjId].pInventory[i].m_Level == Level)
		{
			gObjInventoryDeleteItem(gObjId, i);
			GCInventoryItemDeleteSend(gObjId, i, 1);

			count++;

			if(Count == count)
				break;
		}
	}

	return count;
}

void Functions::Check(LPOBJ lpObj)
{
	Custom[lpObj->m_Index].VipIndex = Manager.VipCount(lpObj->AccountID);
	Custom[lpObj->m_Index].Resets = Manager.CountResets(lpObj->Name);
	Custom[lpObj->m_Index].Masters = Manager.CountMasters(lpObj->Name);
	Custom[lpObj->m_Index].mCash = Manager.GoldCount(lpObj->AccountID);
	Custom[lpObj->m_Index].jail = Manager.GetJail(lpObj->Name);
}

void Functions::HealthBarSend(LPOBJ lpObj)
{
	BYTE Buffer[1500];
	PMSG_HEALTHBAR Result;
	PMSG_HEALTHBAR_INFO Info;

	Result.h.c = 0xC2;
	Result.h.headcode = 0xF3;
	Result.Code = 0xE2;
	Result.Count = 0;
	
	int Size = sizeof(Result);

	for (int i = 0; i < 75; i++)
	{
		if (lpObj->VpPlayer[i].state != 1 && lpObj->VpPlayer[i].state != 2)
		{
			continue;
		}

		if (lpObj->VpPlayer[i].type != MONSTER)
		{
			continue;
		}

		if (OBJECT_RANGE(lpObj->VpPlayer[i].number) == 0)
		{
			continue;
		}

		LPOBJ lpTargetObj = &gObj[lpObj->VpPlayer[i].number];

		if (lpTargetObj->Class == 200 || lpTargetObj->Live == 0 || lpTargetObj->m_State != 2 || CC_MAP_RANGE(lpTargetObj->MapNumber) != 0)
		{
			continue;
		}

		Info.Index = lpObj->VpPlayer[i].number;
		Info.Rate = (BYTE)((lpTargetObj->Life * 100) / (lpTargetObj->MaxLife + lpTargetObj->AddLife));

		memcpy(&Buffer[Size], &Info, sizeof(Info));
		Size += sizeof(Info);
		Result.Count++;
	}

	Result.h.sizeH = HIBYTE(Size);
	Result.h.sizeL = LOBYTE(Size);

	memcpy(Buffer, &Result, sizeof(Result));

	DataSend(lpObj->m_Index, Buffer, Size);
}
void Functions::CheckPet(LPOBJ lpObj)
{
	if (!(lpObj->pInventory[8].m_Type >= ITEMGET(13,0) && lpObj->pInventory[8].m_Type <= ITEMGET(13, 5))) 
	{
		GCInventoryItemDeleteSend(lpObj->m_Index,8,0);
	}
}
bool Functions::SystemIPS( char * ini )
{
	memset((DWORD*)0x004FDACE, 0xEB, 1);
	memset((DWORD*)0x004FDACF, 0x73, 1);

	char Connect_Load[50], IP[16];
	int JS = 0, DS = 0, GS = 0;

	GetPrivateProfileString("GameServerInfo", "Connect_Load", "127.0.0.1 55970 55960 55901", Connect_Load, 50, ini);
	sscanf(Connect_Load, "%s %d %d %d" , IP, &JS, &DS, &GS);


	memcpy((DWORD*)0x0AB550B0, IP, strlen(IP));
	memcpy((DWORD*)0x0AB551B0, IP, strlen(IP));


	*(unsigned int*)0x0A78EF1C = (unsigned int)JS;
	*(unsigned int*)0x0A78EF18 = (unsigned int)DS;
	*(unsigned int*)0x0A78EF20 = (unsigned int)GS;


	return 1;
}

bool Functions::IniciaIni()
{
	char aini[] = "Data\\ServerInfo.dat";
	bool rResultado;
	rResultado = func.SystemIPS(aini);
	return 1;
}

void Functions::LevelUPSend(DWORD aIndex)
{
	// ---
	OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	// ---
	GCLevelUpMsgSend(aIndex,gObj[aIndex].Level,gObj[aIndex].LevelUpPoint,(WORD)(gObj[aIndex].MaxLife+gObj[aIndex].AddLife),(WORD)(gObj[aIndex].MaxMana+gObj[aIndex].AddMana),(WORD)(gObj[aIndex].MaxBP+gObj[aIndex].AddBP));
	// ---

}

bool Functions::IsOnGame(int iIndex)
{
	if ((iIndex >= 0)&&(iIndex<OBJECT_MAX))
	{

		if (gObj[iIndex].Connected==3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}

bool Functions::IsBadFileLine(char *FileLine, int &Flag)
{
	if(Flag == 0)
	{
		if(isdigit(FileLine[0]))
		{
			Flag = FileLine[0] - 48;
			return true;
		}
	}
	else if(Flag < 0 || Flag > 9)
	{
		Flag = 0;
	}

	if(!strncmp(FileLine, "end", 3))
	{
		Flag = 0;
		return true;
	}

	if(FileLine[0] == '/' || FileLine[0] == '\n')
		return true;

	for(UINT i = 0; i < strlen(FileLine); i++)
	{
		if(isalnum(FileLine[i]))
			return false;
	}
	return true;
}

int Functions::GenExcOpt(int amount)
{
	// User input errors
	if (amount > 6) amount = 6;
	if (amount < 1) amount = 1;

	int opt_db[6]  = {1, 2, 4, 8, 16, 32};
	int exc = 0;

	std::random_shuffle(opt_db, opt_db + 6);

	for(int n=0; n < amount; n++)
		exc += opt_db[n];

	return exc;
}

void Functions::MsgOutputAll(char *message, ...)
{
	char szBuffer[512] = "";
	va_list pArguments;

	va_start(pArguments, message);
	vsprintf(&szBuffer[0], message, pArguments);
	va_end(pArguments);

	for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if(gObj[i].Connected == 3)
		{
			GCServerMsgStringSend(&szBuffer[0], i, 1);
		}
	}
}

bool Functions::WarehouseHacker(int aIndex)
{
	if(gObj[aIndex].WarehouseSave >= 1 )
	{
		CGWarehouseUseEnd(aIndex);
		return TRUE;
	}
	return FALSE;
}

int	Functions::MyRand(int min, int max)
{
	if(min == max) 
		return min;

	int rnd = rand();
	int r = min + rnd / (RAND_MAX / (max - min) + 1);

	return r;
}
void Functions::ChkJail(LPOBJ lpObj) {
	int aIndex = lpObj->m_Index;
	if (Custom[aIndex].jail == 1 && gObj[aIndex].Connected == 3) {
		if (gObj[aIndex].MapNumber > 0 || gObj[aIndex].X >= 129 || gObj[aIndex].X <= 126 || gObj[aIndex].Y >= 120 || gObj[aIndex].Y <= 116) {
			gObj[aIndex].m_PK_Level = 6;
			gObj[aIndex].m_PK_Count = 20;
			gObj[aIndex].m_PK_Time = 100;
			GCPkLevelSend(aIndex, gObj[aIndex].m_PK_Level);
			gObjTeleport(aIndex, 0, 128, 118);
		}
	}
}

void StartAddress(LPVOID lpThreadParameter)
{
	HANDLE v1;
	HANDLE v2;

	while ( TRUE )
	{
		Sleep(5000);
		v1 = GetCurrentProcess();
		SetProcessWorkingSetSize(v1, 0xFFFFFFFF, 0xFFFFFFFF);
		v2 = GetCurrentProcess();
		SetThreadPriority(v2, -2);
	}
}/*
void Functions::CGTalkRequestRecv(PMSG_TALKREQUEST* lpMsg, int aIndex)
{
	if (PacketCheckTime(&gObj[aIndex]) == FALSE)
	{
		return;
	}
	if (gObj[aIndex].CloseType != -1)
	{
		return;
	}

	if (!Func.gObjIsConnectedGP(aIndex))
	{
		return;
	}

	if (gObj[aIndex].m_IfState.use > 0)
	{
		return;
	}

	int DealerNumber = MAKE_NUMBER(lpMsg->NumberH, lpMsg->NumberL);

	if (DealerNumber < 0 || DealerNumber > OBJECT_MAX - 1)
	{
		return;
	}

	if (gObj[aIndex].MapNumber != gObj[DealerNumber].MapNumber ||
		(gObj[aIndex].X < (gObj[DealerNumber].X - 5) || gObj[aIndex].X > (gObj[DealerNumber].X + 5)) || 
		(gObj[aIndex].Y < (gObj[DealerNumber].Y - 5) || gObj[aIndex].Y > (gObj[DealerNumber].Y + 5)))
	{
		return;
	}

	int ShopNum = gObj[DealerNumber].ShopNumber;

	if (gObj[DealerNumber].Type == 3)
	{
		if (cNpc::NPCTalkEx(&gObj[DealerNumber], &gObj[aIndex]) == TRUE)
		{
			return;
		}
	}

	Func.gObjFixInventoryPointer(&gObj[aIndex]);

	PMSG_TALKRESULT pMsg;
	BYTE bRand;

	pMsg.h.c        = 0xC3;
	pMsg.h.head		= 0x30;
	pMsg.h.size     = sizeof(PMSG_TALKRESULT);
	pMsg.Treasure   = 0;

	if (gObj[DealerNumber].Class == 234)    // Npc Server Division
	{
		pMsg.result = 5;
		DataSend(aIndex, (LPBYTE)&pMsg, pMsg.h.size);
		return;
	}

	if (gObj[DealerNumber].Type == 3 && ShopNum < 0)
	{
		return; 
	}

	if (ShopNum >= 0 && ShopNum < MAX_SHOP)
	{
		if (ShopNum == Treasure.ShopNumber())  // Treasure
		{
			if (!_stricmp(Treasure.Winner(), gObj[aIndex].Name))
			{
				CShop* Shop				   = &ShopC[ShopNum];

				gObj[aIndex].TargetShopNumber    = ShopNum;
				gObj[aIndex].m_IfState.use       = 1;
				gObj[aIndex].m_IfState.type      = 3;
				gObj[aIndex].m_ShopTime          = 0;

				pMsg.result				   = 0;
				pMsg.Treasure			   = 1;

				DataSend(aIndex, (LPBYTE)(&pMsg), pMsg.h.size);

				BYTE SendByte[1024];
				PMSG_SHOPITEMCOUNT pShopItemCount;
				int lOfs = sizeof(pShopItemCount);
				int Size = lOfs + Shop->SendItemDataLen;

				pShopItemCount.h.c          = 0xC2;
				pShopItemCount.h.sizeH      = HIBYTE(Size);
				pShopItemCount.h.sizeL      = LOBYTE(Size);
				pShopItemCount.h.head	    = 0x31;
				pShopItemCount.Type         = 0;
				pShopItemCount.count        = Shop->ItemCount;

				memcpy_s(SendByte, 1024, &pShopItemCount, sizeof(pShopItemCount));
				memcpy_s(&SendByte[lOfs], (1024 - lOfs), Shop->SendItemData, Shop->SendItemDataLen);

				DataSend(aIndex, SendByte, Size);
			}
		}
		else
		{
			CShop* Shop = &ShopC[ShopNum];
			bRand		= (BYTE)(rand() % 2);

			if (Shop->ItemCount < 1)
			{
				if (bRand != 0)
				{
					ChatTargetSend(&gObj[DealerNumber], Func.lMsgGet(MSGGET(4, 119)), aIndex);
				}
				else
				{
					ChatTargetSend(&gObj[DealerNumber], Func.lMsgGet(MSGGET(4, 120)), aIndex);
				}

				return;
			}

			if (gObj[aIndex].m_PK_Level > 4)
			{
				if (bRand != 0)
				{
					ChatTargetSend(&gObj[DealerNumber], Func.lMsgGet(MSGGET(4, 121)), aIndex);
				}
				else
				{
					ChatTargetSend(&gObj[DealerNumber], Func.lMsgGet(MSGGET(4, 122)), aIndex);
				}

				return;
			}

			bRand = (BYTE)(rand() % 6);

			switch (bRand)
			{
			case 0:
				{
					if (*(gMerryXMasNpcEvent) == 1)
					{
						ChatTargetSend(&gObj[DealerNumber], Func.lMsgGet(MSGGET(4, 123)), aIndex);
					}
				} break;
			case 1:
				{
					if (*(gHappyNewYearNpcEvent) == 1)
					{
						ChatTargetSend(&gObj[DealerNumber], Func.lMsgGet(MSGGET(4, 124)), aIndex);
					}
				} break;
			}

			gObj[aIndex].TargetShopNumber    = ShopNum;
			gObj[aIndex].m_IfState.use       = 1;
			gObj[aIndex].m_IfState.type      = 3;
			gObj[aIndex].m_ShopTime          = 0;

			pMsg.result				   = 0;
			pMsg.Treasure              = 0;

			DataSend(aIndex, (LPBYTE)(&pMsg), pMsg.h.size);

			BYTE SendByte[1024];
			PMSG_SHOPITEMCOUNT pShopItemCount;
			int lOfs = sizeof(pShopItemCount);
			int Size = lOfs + Shop->SendItemDataLen;

			pShopItemCount.h.c          = 0xC2;
			pShopItemCount.h.sizeH      = HIBYTE(Size);
			pShopItemCount.h.sizeL      = LOBYTE(Size);
			pShopItemCount.h.head	    = 0x31;
			pShopItemCount.Type         = 0;
			pShopItemCount.count        = Shop->ItemCount;

			memcpy_s(SendByte, 1024, &pShopItemCount, sizeof(pShopItemCount));
			memcpy_s(&SendByte[lOfs], (1024 - lOfs), Shop->SendItemData, Shop->SendItemDataLen);

			DataSend(aIndex, SendByte, Size);
		}
	}
	else
	{
		bRand = (BYTE)(rand() % 6);

		switch (bRand)
		{
		case 0:
			{
				if (*(gMerryXMasNpcEvent) == 1)
				{
					ChatTargetSend(&gObj[DealerNumber], Func.lMsgGet(MSGGET(4, 123)), aIndex);
				}
			} break;
		case 1:
			{
				if (*(gHappyNewYearNpcEvent) == 1)
				{
					ChatTargetSend(&gObj[DealerNumber], Func.lMsgGet(MSGGET(4, 124)), aIndex);
				}
			} break;
		}

		gObj[aIndex].TargetShopNumber    = ShopNum;
		gObj[aIndex].m_IfState.use       = 1;
		gObj[aIndex].m_IfState.type      = 3;
		gObj[aIndex].m_ShopTime          = 0;

		pMsg.result = 0;

		switch (ShopNum)
		{
		case 100:
			{
				if (gObj[aIndex].m_ReqWarehouseOpen != 0)
				{
				}
				else
				{
					gObj[aIndex].m_ReqWarehouseOpen  = 1;
					gObj[aIndex].m_IfState.type      = 6;
					gObj[aIndex].m_IfState.state     = 0;
					gObj[aIndex].WarehouseCount      = 0;

					GDGetWarehouseList(aIndex, gObj[aIndex].AccountID);
				}
			} break;
		case 101:
			{
				if (*(bCanChaosBox) == TRUE)
				{               
					gObj[aIndex].m_IfState.type = 7;
					gObj[aIndex].m_IfState.state = 0;

					pMsg.result = 3;
					pMsg.level1 = (BYTE)(*(gDQChaosSuccessRateLevel1));
					pMsg.level2 = (BYTE)(*(gDQChaosSuccessRateLevel2));
					pMsg.level3 = (BYTE)(*(gDQChaosSuccessRateLevel3));
					pMsg.level4 = (BYTE)(*(gDQChaosSuccessRateLevel4));

					DataSend(aIndex, (LPBYTE)&pMsg, pMsg.h.size);
					gObjInventoryTrans(aIndex);

					LogAddTD("[%s][%s] Open Chaos Box", gObj[aIndex].AccountID, gObj[aIndex].Name);

					gObjItemTextSave(&gObj[aIndex]);
					gObjWarehouseTextSave(&gObj[aIndex]);
				}
			} break;
		}
	}
}

void Functions::CGBuyRequestRecv(PMSG_BUYREQUEST* lpMsg, int aIndex)
{
	PMSG_BUYRESULT pMsg;

	pMsg.h.c        = 0xC1;
	pMsg.h.size     = sizeof(PMSG_BUYRESULT);
	pMsg.h.head     = 0x32;
	pMsg.Result     = -1;

	if (PacketCheckTime(&gObj[aIndex]) == FALSE)
	{
		DataSend(aIndex, (LPBYTE)&pMsg, pMsg.h.size);
		return;
	}
	
	if (gObj[aIndex].CloseType != -1)
	{
		DataSend(aIndex, (LPBYTE)&pMsg, pMsg.h.size);
		return;
	}
	
	Func.gObjFixInventoryPointer(&gObj[aIndex]);

	if (gObj[aIndex].m_ShopTime == 0)
	{
		gObj[aIndex].m_ShopTime = 1;
	}
	
	if (gObj[aIndex].m_ShopTime > 60)
	{
		if (gObj[aIndex].m_IfState.use != 0 && gObj[aIndex].m_IfState.type == 3)
		{
			gObj[aIndex].TargetShopNumber    = -1;
			gObj[aIndex].m_IfState.use       = 0;
			gObj[aIndex].m_IfState.type      = 0;
		}

		DataSend(aIndex, (LPBYTE)&pMsg, pMsg.h.size);
		return;
	}
	else if (gObj[aIndex].m_IfState.use > 0 && gObj[aIndex].m_IfState.type != 3)
	{
		DataSend(aIndex, (LPBYTE)&pMsg, pMsg.h.size);
		return;
	}
	else
	{
		int ShopNum = gObj[aIndex].TargetShopNumber;

		if (ShopNum < 0 || ShopNum > MAX_SHOP -1)
		{
			DataSend(aIndex, (LPBYTE)&pMsg, pMsg.h.size);
			return;
		}
		else if (lpMsg->Pos > 120 - 1)
		{
			DataSend(aIndex, (LPBYTE)&pMsg, pMsg.h.size);
			return;
		}
		else
		{
			if (ShopNum == Treasure.ShopNumber()) // Treasure
			{
				if (!_stricmp(gObj[aIndex].Name, Treasure.Winner()))
				{
					CShop* Shop = &ShopC[ShopNum];

					if (Shop->Item[lpMsg->Pos].IsItem())
					{
						BOOL NoItem = TRUE;

						if (Shop->Item[lpMsg->Pos].m_Type >= ITEMGET(14,0) && Shop->Item[lpMsg->Pos].m_Type <= ITEMGET(14,8))
						{
							int Durability = (int)(Shop->Item[lpMsg->Pos].m_Durability);

							if(Durability == 0)
							{
								Durability = 1;
							}

							if (gObjSearchItem(&gObj[aIndex], Shop->Item[lpMsg->Pos].m_Type, Durability) == TRUE)
							{
								NoItem = FALSE;                             
							}
						}

						if (NoItem != FALSE)
						{
							pMsg.Result = gObjShopBuyInventoryInsertItem(aIndex, Shop->Item[lpMsg->Pos]);

							if (pMsg.Result != 0xFF)
							{
								ItemByteConvert((LPBYTE)(&pMsg.ItemInfo), Shop->Item[lpMsg->Pos]);
							}
						}
					}
				}
			}
			else
			{
				CShop* Shop = &ShopC[ShopNum];

				if (Shop->Item[lpMsg->Pos].IsItem() == TRUE)
				{
					if ((UINT)(gObj[aIndex].Money) < Shop->Item[lpMsg->Pos].m_BuyMoney)
					{
						pMsg.Result = -1;
					}
					else
					{
						BOOL NoItem = TRUE;

						if (Shop->Item[lpMsg->Pos].m_Type >= ITEMGET(14,0) && Shop->Item[lpMsg->Pos].m_Type <= ITEMGET(14,8))
						{
							int Durability = (int)(Shop->Item[lpMsg->Pos].m_Durability);

							if(Durability == 0)
							{
								Durability = 1;
							}

							if (gObjSearchItem(&gObj[aIndex], Shop->Item[lpMsg->Pos].m_Type, Durability) == TRUE)
							{
								NoItem = FALSE;

								gObj[aIndex].Money -= (int)Shop->Item[lpMsg->Pos].m_BuyMoney;

								if (gObj[aIndex].Money < 0)
								{
									gObj[aIndex].Money = 0;
								}

								GCMoneySend(aIndex, gObj[aIndex].Money);
							}
						}

						if (NoItem != FALSE)
						{
							pMsg.Result = gObjShopBuyInventoryInsertItem(aIndex, Shop->Item[lpMsg->Pos]);
							
							if (pMsg.Result != 0xFF)
							{
								ItemByteConvert((LPBYTE)(&pMsg.ItemInfo), Shop->Item[lpMsg->Pos]);

								gObj[aIndex].Money -= (int)Shop->Item[lpMsg->Pos].m_BuyMoney;

								if (gObj[aIndex].Money < 0)
								{
									gObj[aIndex].Money = 0;
								}

								GCMoneySend(aIndex, gObj[aIndex].Money);                              
							}
						}
					}
				}
			}
		}
	}

	DataSend(aIndex, (LPBYTE)&pMsg, pMsg.h.size);
}*/
//===========================================================================================
//--  Function ItemSerialCreateSend Extra   
//===========================================================================================

int Functions::InventoryMapCheck(int aIndex,int X, int Y, int Width, int Height)
{
	 OBJECTSTRUCT *ItObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

		  
	if (((X + Width) > 8) || ((Y + Height) > 12))
	{
		return (-1);
	}

	int y, x, Blank = 0;
	
	for (y = 4; y < Height; y++)
	{
		for (x = 0; x < Width; x++)
		{
			if (this->InventoryMap[(((Y + y) * 8) + (X + x))])
			{
				if(ItObj->pInventory[(((Y + y) * 8) + (X + x))].m_Type == SLOT_EMPTY ){
					Blank++;
					break;
				}
			}
		}
	}

	if (Blank == 0)
	{
		for (y = 4; y < Height; y++)
		{
			for (x = 0; x < Width; x++)
			{
				this->InventoryMap[(((Y + y) * 8) + (X + x))] = 1;
			}
		}

		return (X + (Y * 8));
	}

	return (-1);
}


void Functions::ItemSerialCreateSendEx(int aIndex, int MapNumber, int x, int y, int Type, int Level, int Dur, int Skill, int Luck, int Option,int LootIndex,int Excellent,int Ancient)
{
	if(MapNumber == 235 )
	{
		
		int Width = 0, Height = 0,Blank = (-1);
		OBJECTSTRUCT *ItObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
		if ( ItObj->Connected > CONNECTED )
		{
		ItemGetSize(Type, Width, Height);
		if ((Width < 0) || (Height < 0))
			{
				return;
			}
		for (y = 4; y < 12; y++)
			{
				for (x = 0; x < 8; x++)
					{
						if (this->InventoryMap[(x + (y * 8))] == 0)
							{
								Blank = this->InventoryMapCheck(aIndex,x, y, Width, Height);
								if (Blank >= 0)
									{

										if(Dur == 0){Dur = ItemGetDurability(Type, Level, (Excellent != 0) ? 1 : 0);}
										CItem pCreateItem;

										// ----
										
										pCreateItem.m_Number = func.MyRand(1000000, 30000000);
										pCreateItem.m_Level = Level;
										
										pCreateItem.m_Durability = Dur;
		

										pCreateItem.Convert(Type, Skill, Luck, Option, Excellent, Ancient, 1);
										BYTE btItemPos = gObjOnlyInventoryInsertItem(aIndex, pCreateItem);
										//BYTE btItemPos = gObjInventoryInsertItem(aIndex, pCreateItem);

										// ----

										if ( btItemPos == (BYTE)-1 )

											{

												//LogAddTD("[CashShop] Error : Failed To Insert Item Type:%d, TypeIndex:%d to [%s][%s]", iItemType, iItemIndex, gObj[lpMsg->aIndex].AccountID, gObj[lpMsg->aIndex].Name);

											}
										else

											{
												//GCInventoryItemOneSend(aIndex, btItemPos);
												GCItemListSend(aIndex);

											}
										
										return;
								}else{
									func.MsgUser(aIndex,1,"Inventario lotado, item não inserido");
								}
							}
						}
					}
		}
	}
	else
	{
	    ItemSerialCreateSend(aIndex,MapNumber,x,y,Type,Level,Dur,Skill,Luck,Option,aIndex,Excellent,0);  //Original Function 
	}

}

Functions func;