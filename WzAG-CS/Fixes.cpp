//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 0.97.40T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "StdAfx.h"

void __declspec(naked) Durability()
{
	__asm 
	{
		CMP DWORD PTR SS:[EBP+0xC],0x0E;
		JNZ ITEM_15;
		MOV ECX,DWORD PTR SS:[EBP+8];
		IMUL ECX,ECX,0x6C;
		XOR EDX,EDX;
		MOV DL,BYTE PTR DS:[ECX+0x568A890];
		MOV EAX,DWORD PTR SS:[EBP+0xC];
		LEA ECX,DWORD PTR DS:[EDX+EAX*2+7];
		MOV DWORD PTR SS:[EBP-4],ECX;
		JMP LOCAL;
ITEM_15:
		CMP DWORD PTR SS:[EBP+0xC],0x0F;
		JNZ RETURN;
		MOV ECX,DWORD PTR SS:[EBP+8];
		IMUL ECX,ECX,0x6C;
		XOR EDX,EDX;
		MOV DL,BYTE PTR DS:[ECX+0x568A890];
		MOV EAX,DWORD PTR SS:[EBP+0xC];
		LEA ECX,DWORD PTR DS:[EDX+EAX*2+8];
		MOV DWORD PTR SS:[EBP-4],ECX;
		JMP LOCAL;
LOCAL:
		MOV EDI, 0x005011E7;
		JMP EDI;
RETURN:
		MOV EAX,DWORD PTR SS:[EBP+8];
		IMUL EAX,EAX,0x6C;
		XOR ECX,ECX;
		MOV CL,BYTE PTR DS:[EAX+0x568A890];
		MOV EDX,DWORD PTR SS:[EBP+0xC];
		LEA EAX,DWORD PTR DS:[ECX+EDX*2-4];
		MOV DWORD PTR SS:[EBP-4],EAX;
		MOV EDI, 0x005011E7;
		JMP EDI;
	}
}

void __declspec(naked) CheckZenMonster()
{
	__asm 
	{
		MOV ECX, DWORD PTR SS:[EBP+0xC];
		CMP WORD PTR DS:[ECX+0x60], 2;
		JNZ IsNotZero;
		MOV EDX, DWORD PTR DS:[ECX+0xAC];
		MOV EDI, 0x561E48;
		MOV DWORD PTR SS:[EBP-0x8], EDX;
		FILD DWORD PTR SS:[EBP-0x8];
		FMUL DWORD PTR DS:[0x686EFC];
		CALL EDI;
		MOV ECX,DWORD PTR SS:[EBP+0xC];
		MOV DWORD PTR DS:[ECX+0xAC], EAX;
IsNotZero:
		POP EDI;
		POP ESI;
		POP EBX;
		MOV ESP, EBP;
		POP EBP;
		RETN;
	}
}

void Fixes()
{
	// -  Nprotect GameGuard

	func.SetRetn(0x401FA5);
	func.SetNop(0x401FA5+1,4);

	// - GCDamageSend

	func.SetByte(0x44179B+1,0xD9);

	// - PMoveProc

	func.SetByte(0x4408B3+1,0xD7);

	// - RecvPositionSetProc

	func.SetByte(0x441046+1,0xD0);

    // - gObjBackSpring

	func.SetByte(0x4CFD1B+3,0xD0);

	// - gObjBackSpring2

	func.SetByte(0x4D029D+3,0xD0);

	// - PathFindMoveMsgSend
	
	func.SetByte(0x4155F6+6,0xD7);

	// - gObjSetPosition

	func.SetByte(0x4F19EE+3,0xD0);

	// - CGClientMsg (Client HackCheck)

	func.SetRRetn(0x404A07);

	// -  Memory Error 0x00000000

	func.SetRetn(0x403170);

	// - Useskill SpeedhackCheck

	func.SetRetn(0x40404D);
	func.SetNop(0x40404D+1,4);
	func.SetNop(0x4AE86B,6);

	// - Speedhack Warning

	func.SetByte(0x42BFDC,0xE9);
	func.SetByte(0x42BFDC+1,0x2F);
	func.SetByte(0x42BFDC+2,0x01);
	func.Set00(0x42BFDC+3,2);
	func.SetNop(0x42BFDC+5,1);

	// - Dark Horse & Dark Heaven

	func.Set00(0x425646+2,2);
	func.Set00(0x425668+1,2);

	// - HP Potion 255

	func.SetNop(0x42321E,8);
	func.SetNop(0x4C7776,8);

	// -  Protocol Error

	func.SetNop(0x441EB0,27);
	func.SetNop(0x4413E0,27);

	// - Delete Guild Without Pid

	func.SetNop(0x43D3EC,6);

	// - Leave Guild Without Pid

	func.SetNop(0x43D544,2);

	// - Character Delete Without Pid

	func.SetByte(0x42ED41,0xEB);

	// -  Socket Serial

	func.SetByte(0x42A71D,0xEB);

	// -  Destroy Giocp

	func.SetRetn(0x402D3D);
	func.SetNop(0x402D3D+1,3);

	// -  AntiHack

	func.SetByte(0x4FE02D,0x7E);

	// -  NoStandBy DataServer

	func.SetNop(0x4D068E,18);

	// - Pk Bug

	func.SetByte(0x4AD391,0xEB);
	func.SetByte(0x4AD622,0xEB);
	func.SetByte(0x4AD64D,0xEB);

	// - INVALID_SOCKET

	func.SetByte(0x4885A8,0x90);
	func.SetByte(0x4885A9,0x90);
	func.SetByte(0x4886C1,0xEB);

	// - GetQueueCompletionStatus() : Error 183

	func.SetByte(0x4864A5,0xEB);

	// - Authority nick webzen

	func.SetByte(0x4C9686+6,0x01);
	func.SetByte(0x4C96C7+6,0x01);
	func.SetByte(0x4C977F+6,0x01);

	// - Deffense Setting

	func.SetByte(0x4C5A92,0xEB);

	// - Option +28

	func.SetNop(0x4230DE,2);
	func.SetNop(0x500517,2);
	func.SetByte(0x4EEFC7,0x07);
	func.SetByte(0x4C769A,0x07);

	// - GCWarehouseRecivePassword

	func.SetByte(0x43F67B,0xEB);
	func.SetByte(0x43F70E,0xEB);

	// - Ancient + Options full

	func.SetByte(0x4FA536,0xEB);

	// - Itens+15

	func.SetByte(0x42307A+2,0x0F);
	func.SetByte(0x4C75F3+2,0x0F);
	func.HookProc(0x5011CF,(DWORD)(&Durability));
    func.SetNop(0x5011CF+5,19);

	// - Party Zen Bug

	for(DWORD i = 0x4D6A35; i <= 0x4D6A3B; i++)
	func.SetByte(i,0xCC);
	func.SetByte(0x4D6A35,0xE9);
	func.HookThis((DWORD)(&CheckZenMonster),0x4D6A35);

	// - Marlon Quest Save

	func.SetByte(0x4C8E0F,0xEB);
	func.SetByte(0x4C8E70,0xEB);

	// - GameMaster Move "M"
	
	func.SetByte(0x50607D+2,0x64);

	// - Chaos Castle ObjSetPosition
	
	func.SetByte(0x528096+3,0xD0);
	func.SetByte(0x52814A+1,0xD0);

	// - Chaos Castle GiveUserDamage
	
	func.SetByte(0x526AE4+1,0xD9);

	// - Warning Dark Horse & Dark Heaven

	func.SetNop(0x4F40F4,29);
	func.SetNop(0x4F41D9,29);
	func.SetNop(0x4F42F0,29);
	func.SetNop(0x4F4406,29);

	// - Wings Lvl 1 - CItem::Convert - Reinterpret like Wings Lvl 2

	func.SetByte(0x4FA470+4,0x80);
	func.SetByte(0x4FB54A,0xE9);
	func.SetByte(0x4FB54A+1,0xAA);
	func.SetByte(0x4FB54A+2,0x00);
	func.SetByte(0x4FB54A+3,0x00);
	func.SetByte(0x4FB54A+4,0x00);
	func.SetByte(0x4FB571,0xE9);
	func.SetByte(0x4FB571+1,0xF8);
	func.SetByte(0x4FB571+2,0x00);
	func.SetByte(0x4FB571+3,0x00);
	func.SetByte(0x4FB571+4,0x00);
	func.SetByte(0x4FB5B5,0xE9);
	func.SetByte(0x4FB5B5+1,0x19);
	func.SetByte(0x4FB5B5+2,0x01);
	func.SetByte(0x4FB5B5+3,0x00);
	func.SetByte(0x4FB5B5+4,0x00);

	// - [Fix] [%s][%s] Try Attack In Not Attack Area (%s,%d,%d) errortype = %d
	
	func.SetByte(0x4AD260,0xEB);

	// - [Fix] [%s][%s] Try Attack In Not Attack Area [Protocol] (%s:%d,%d) errortype = %d
	
	func.SetByte(0x441F52,0xEB);

	// - Close Time

	func.SetByte(0x4C5BF5+3, 0x01);

	// - Skills do Siege

	func.SetByte(0x4B55B4,0xEB);
	func.SetByte(0x4B55C4,0xEB);
	func.SetByte(0x4B56A7,0xEB);
	func.SetByte(0x4B56B7,0xEB);
	func.SetByte(0x4B57C4,0xEB);
	func.SetByte(0x4B57D4,0xEB);
	func.SetByte(0x4B58A7,0xEB);
	func.SetByte(0x4B58B7,0xEB);
	func.SetByte(0x4B59C4,0xEB);
	func.SetByte(0x4B59D4,0xEB);
	func.SetByte(0x4B5AB4,0xEB);
	func.SetByte(0x4B5AC4,0xEB);
	func.SetByte(0x4B5B97,0xEB);
	func.SetByte(0x4B5BA7,0xEB);

	// - gObjGetMagicSearch

	func.SetByte(0x4ED074,0xEB);

	// - CGDurationMagicRecv

	func.SetByte(0x443EA4,0xEB);

	// - gObjGuildWarCheck

	*(DWORD*)(0x4F0253+1) = 50000;

	// - Mensagem de dragões

	const char DRAGON[]  = {""};
    memcpy((int*)0x667998,DRAGON,sizeof(DRAGON));
    memcpy((int*)0x667994,DRAGON,sizeof(DRAGON));

	// - GetStockObject

	func.SetByte(0x513A51+1,0x04);

	// - Decrease Logs Server

	func.SetNop(0x423D1E,6); // - Monster Item Drop Request [%s] [%d][%d][%d] : [%s][%d][%d][%d][%d] Ex:[%d,%d,%d,%d,%d,%d,%d] Set:[%d]
	func.SetNop(0x4246B2,6); // - Monster Item Drop [%d][%d][%d] : serial:%d [%s][%d][%d][%d][%d] Ex:[%d,%d,%d,%d,%d,%d,%d] Set:[%d]
	func.SetNop(0x48C835,6); // - Item has Disappeared
	func.SetNop(0x48BA95,6); // - Can't throw away the item
	func.SetNop(0x4D0458,6); // - Experience : [%s][%s](%d) %u %d
	func.SetNop(0x4D0685,6); // - Level Up
	func.SetNop(0x486618,6); // - error-L1 : Socket Header error %d, %d
	func.SetNop(0x486627,5); // - CloseClient
	func.SetNop(0x4886C8,6); // - error-L1 : CloseClient INVALID_SOCKET
	func.SetNop(0x4847D4,6); // - [Quest] QuestSave [%s][%s] index(%d) name(%s) state(%s)
	func.SetNop(0x4AFEFE,6); // - ¸¶°Ë»ç ¸ó½ºÅÍ¹æ¾î·Â°¨¼Ò : 10
	func.SetNop(0x48793E,6); // - error-L2 : Index(%d) %x %x %x
	func.SetNop(0x42C08B,6); // - [%s][%s][%s] ClientHack Detected : Editing AttackSpeed [%d][%d] [%d][%d]
}

BOOL gObjSetCharacterEx(LPBYTE lpdata, int aIndex)
{
	BOOL retornar = gObjSetCharacter(lpdata,aIndex);

	if(gObj[aIndex].Authority > 1)
	{
	   gObj[aIndex].m_ViewSkillState |= 0x1000000;
	   GCStateInfoSend((DWORD)&gObj[aIndex], 1, gObj[aIndex].m_ViewSkillState);
	}

	if(retornar == TRUE)
	{
		PMSG_CHARINFOMAIN Result;

		Result.h.c = 0xC1;
		Result.h.size = sizeof(Result);
		Result.h.headcode = 0xFE;
		Result.Code = 0x07;
		Result.Class = gObj[aIndex].Class;
		Result.Dexterity = (WORD)(gObj[aIndex].Dexterity);
		Result.AttackSpeed = (WORD)(gObj[aIndex].m_AttackSpeed);
		Result.MagicSpeed = (WORD)(gObj[aIndex].m_MagicSpeed);
		Result.LevelUpPoint = gObj[aIndex].LevelUpPoint;

		DataSend(aIndex, (LPBYTE)(&Result), Result.h.size);
	}

	return retornar;
}