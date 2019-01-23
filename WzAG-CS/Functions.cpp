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
	*(BYTE*)  (Offset)   = 0xE9;
	*(DWORD*) (Offset+1) = (DWORD)(Func)-(Offset+5);
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
	memset ((char*) Offset, 0x00, Size);
	memcpy ((char*) Offset, btString, Size);
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
		if (gObj[i].Connected == 3 && gObj[i].MapNumber == 7)
		{
			for(int n = 0; n < 20; n++)
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

	if (lpObj->Type == PLAYER)	
	{
		func.CheckPet(lpObj);
	}

	if (lpTargetObj->Type == PLAYER)
	{
		func.CheckPet(lpTargetObj);
	}

	if (*(BYTE*)GS_CASTLESIEGESTAT == 7)
	{
		if (lpObj->GuildNumber != 0 && lpTargetObj->GuildNumber != 0)
		{
			if (lpObj->GuildNumber == lpTargetObj->GuildNumber)
			{
				return false;
			}

			if (lpObj->lpGuild->iGuildUnion != 0)
			{
				if (lpObj->lpGuild->iGuildUnion == lpTargetObj->lpGuild->iGuildUnion)
				{
					return false;
				}
			}
		}
	}

	return gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
}

void Functions::gObjInterfaceTimeCheckEx(LPOBJ lpObj)
{
	func.Check(lpObj);

	gObjInterfaceTimeCheck(lpObj);
}

void Functions::gObjSecondProcEx()
{
	Tips.Send();
	News.Send();

	for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if (gObj[i].Type == PLAYER)
		{
			func.HealthBarSend(&gObj[i]);
		}
	}

	gObjSecondProc();
}

void Functions::gObjPlayerKillerEx(LPOBJ lpObj, LPOBJ lpTargetObj)
{  
	return gObjPlayerKiller(lpObj,lpTargetObj); 
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

void Functions::MakeNoticeMsg(void * lpNotice, BYTE btType, char * szNoticeMsg)
{
	PMSG_NOTICE * pNotice = (PMSG_NOTICE*)lpNotice;
	pNotice->type = btType;
	wsprintf(pNotice->Notice, szNoticeMsg);
	PHeadSetB((LPBYTE)pNotice, 0x0D, strlen(pNotice->Notice) + sizeof(PMSG_NOTICE) - sizeof(pNotice->Notice) + 1);
}

void Functions::MsgUser(int aIndex, int Type, char * Msg, ...)
{
	char szBuffer[1024];
	va_list pArguments;
	va_start(pArguments, Msg);
	vsprintf(szBuffer, Msg, pArguments);
	va_end(pArguments);
	PMSG_NOTICE pNotice;
	MakeNoticeMsg(&pNotice, Type, szBuffer);
	DataSend(aIndex, (LPBYTE)&pNotice, pNotice.h.size);
}

void Functions::MsgAllUser(int Type, char * Msg, ...)
{
	char szBuffer[1024];
	va_list pArguments;
	va_start(pArguments, Msg);
	vsprintf(szBuffer, Msg, pArguments);
	va_end(pArguments);
	PMSG_NOTICE pNotice;
	MakeNoticeMsg(&pNotice, Type, szBuffer);
	DataSendAll((LPBYTE)&pNotice, pNotice.h.size);
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
	strncpy((char*)&Buffer[3], Nome, 10);
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

void Functions::Check(LPOBJ lpObj)
{
	Custom[lpObj->m_Index].VipIndex = Manager.VipCount(lpObj->AccountID);
	Custom[lpObj->m_Index].Resets = Manager.CountResets(lpObj->Name);
	Custom[lpObj->m_Index].Masters = Manager.CountMasters(lpObj->Name);
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

	LPOBJ lpTargetObj;

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

		lpTargetObj = &gObj[lpObj->VpPlayer[i].number];

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
	memset((DWORD*)0x00512BFE, 0xEB, 1);
	memset((DWORD*)0x00512BFF, 0x73, 1);
	
	char Connect_Load[50], IP[16];
	int JS = 0, DS = 0, GS = 0;
	
	GetPrivateProfileString("GameServerInfo", "Connect_Load", "127.0.0.1 55970 55960 55901", Connect_Load, 50, ini);
	sscanf(Connect_Load, "%s %d %d %d" , IP, &JS, &DS, &GS);


	memcpy((DWORD*)0x06D5F768, IP, strlen(IP)); 
	memcpy((DWORD*)0x06D5F868, IP, strlen(IP));

	
	*(unsigned int*)0x069A52CC = (unsigned int)JS;
	*(unsigned int*)0x069A52C8 = (unsigned int)DS;
	*(unsigned int*)0x069A52D0 = (unsigned int)GS;

	
	return 1;
}

bool Functions::IniciaIni()
{
	char aini[] = "Data\\ServerInfo.dat";
	bool rResultado;
	rResultado = func.SystemIPS(aini);
	return 1;
}
// Fix Consumo CPU
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
}

Functions func;