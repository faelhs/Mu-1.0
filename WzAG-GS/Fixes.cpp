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

void __declspec(naked) Durability()
{
	__asm 
	{
		CMP DWORD PTR SS:[EBP+0xC],0x0E;
		JNZ ITEM_15;
		MOV ECX,DWORD PTR SS:[EBP+8];
		IMUL ECX,ECX,0x6C;
		XOR EDX,EDX;
		MOV DL,BYTE PTR DS:[ECX+0x9439398];
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
		MOV DL,BYTE PTR DS:[ECX+0x9439398];
		MOV EAX,DWORD PTR SS:[EBP+0xC];
		LEA ECX,DWORD PTR DS:[EDX+EAX*2+8];
		MOV DWORD PTR SS:[EBP-4],ECX;
		JMP LOCAL;
LOCAL:
		MOV EDI, 0x004EC7E7;
		JMP EDI;
RETURN:
		MOV EAX,DWORD PTR SS:[EBP+8];
		IMUL EAX,EAX,0x6C;
		XOR ECX,ECX;
		MOV CL,BYTE PTR DS:[EAX+0x9439398];
		MOV EDX,DWORD PTR SS:[EBP+0xC];
		LEA EAX,DWORD PTR DS:[ECX+EDX*2-4];
		MOV DWORD PTR SS:[EBP-4],EAX;
		MOV EDI, 0x004EC7E7;
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
		MOV EDI, 0x52A488;
		MOV DWORD PTR SS:[EBP-0x8], EDX;
		FILD DWORD PTR SS:[EBP-0x8];
		FMUL DWORD PTR DS:[0x628DC4];
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

	func.SetRetn(0x401EF1);
	func.SetNop(0x401EF1+1,4);

	// - GCDamageSend

	func.SetByte(0x43E71B+1,0xD9);

	// - PMoveProc

	func.SetByte(0x43D8CF+1,0xD7);

	// - RecvPositionSetProc

	func.SetByte(0x43DFC6+1,0xD0);

    // - gObjBackSpring

	func.SetByte(0x4BC90A+3,0xD0);

	// - gObjBackSpring2

	func.SetByte(0x4BCD63+3,0xD0);

	// - PathFindMoveMsgSend
	
	func.SetByte(0x413516+6,0xD7);

	// - gObjSetPosition

	func.SetByte(0x4DD13E+3,0xD0);

	// - CGClientMsg (Client HackCheck)

	func.SetRRetn(0x404372);

	// -  Memory Error 0x00000000

	func.SetRetn(0x402F9F);

	// - Useskill SpeedhackCheck

	func.SetRetn(0x403B8E);
	func.SetNop(0x403B8E+1,4);
	func.SetNop(0x43E51C,6);

	// - Speedhack Warning

	func.SetByte(0x42869C,0xE9);
	func.SetByte(0x42869C+1,0x2F);
	func.SetByte(0x42869C+2,0x01);
	func.Set00(0x42869C+3,2);
	func.SetNop(0x42869C+5,1);

	// - Dark Horse & Dark Heaven

	func.Set00(0x4232A6+2,2);
	func.Set00(0x4232C8+1,2);

	// - HP Potion 255

	func.SetNop(0x420E7E,8);
	func.SetNop(0x4B4656,8);

	// - Protocol Error

	func.SetNop(0x43EE30,27);
	func.SetNop(0x43E360,27);

	// - Delete Guild Without Pid

	func.SetNop(0x4399EA,6);

	// - Leave Guild Without Pid

	func.SetNop(0x439B40,2);

	// - Character Delete Without Pid

	func.SetByte(0x42B401,0xEB);

	// -  Socket Serial

	func.SetByte(0x426DFD,0xEB);

	// -  Destroy Giocp

	func.SetRetn(0x402C57);
	func.SetNop(0x402C57+1,3);

	// -  AntiHack

	func.SetByte(0x4E962D,0x7E);

	// -  NoStandBy DataServer

	func.SetNop(0x4BD11E,18);

	// - Pk Bug

	func.SetByte(0x49A051,0xEB);
	func.SetByte(0x49A2E2,0xEB);
	func.SetByte(0x49A30D,0xEB);

	// - INVALID_SOCKET

	func.SetByte(0x475C18,0x90);
	func.SetByte(0x475C19,0x90);
	func.SetByte(0x475D31,0xEB);

	// - GetQueueCompletionStatus() : Error 183

	func.SetByte(0x473B15,0xEB);

	// - Authority nick webzen

	func.SetByte(0x4B640B+6,0x01);
	func.SetByte(0x4B644C+6,0x01);
	func.SetByte(0x4B6504+6,0x01);

	// - Deffense Setting

	func.SetByte(0x4B29F2,0xEB);

	// - Option +28

	func.SetNop(0x420D3E,2);
	func.SetNop(0x4EBB17,2);
	func.SetByte(0x4DA697,0x07);
	func.SetByte(0x4B457A,0x07);

	// - GCWarehouseRecivePassword

	func.SetByte(0x43C8DB,0xEB);
	func.SetByte(0x43C96E,0xEB);

	// - Ancient + Options full

	func.SetByte(0x4E5B36,0xEB);

	// - Itens+15

	func.SetByte(0x420CDA+2,0x0F);
	func.SetByte(0x4B44D3+2,0x0F);
	func.HookProc(0x4EC7CF,(DWORD)(&Durability));
    func.SetNop(0x4EC7CF+5,19);

	// - Party Zen Bug

	for(DWORD i = 0x4C3345; i <= 0x4C334B; i++)
	func.SetByte(i,0xCC);
	func.SetByte(0x4C3345,0xE9);
	func.HookThis((DWORD)(&CheckZenMonster),0x4C3345);

	// - Marlon Quest Save

	func.SetByte(0x4B5C15,0xEB);
	func.SetByte(0x4B5C76,0xEB);

    // - GameMaster Move "M"
	
	func.SetByte(0x4F158D+2,0x64);

	// - Chaos Castle ObjSetPosition
	
	func.SetByte(0x512CD6+3,0xD0);
	func.SetByte(0x512D8A+1,0xD0);

	// - Chaos Castle GiveUserDamage
	
	func.SetByte(0x511724+1,0xD9);

	// - Warning Dark Horse & Dark Heaven

	func.SetNop(0x4DF844,29);
	func.SetNop(0x4DF929,29);
	func.SetNop(0x4DFA40,29);
	func.SetNop(0x4DFB56,29);

	// - Wings Lvl 1 - CItem::Convert - Reinterpret like Wings Lvl 2

	func.SetByte(0x4E5A70+4,0x80);
	func.SetByte(0x4E6B4A,0xE9);
	func.SetByte(0x4E6B4A+1,0xAA);
	func.SetByte(0x4E6B4A+2,0x00);
	func.SetByte(0x4E6B4A+3,0x00);
	func.SetByte(0x4E6B4A+4,0x00);
	func.SetByte(0x4E6B71,0xE9);
	func.SetByte(0x4E6B71+1,0xF8);
	func.SetByte(0x4E6B71+2,0x00);
	func.SetByte(0x4E6B71+3,0x00);
	func.SetByte(0x4E6B71+4,0x00);
	func.SetByte(0x4E6BB5,0xE9);
	func.SetByte(0x4E6BB5+1,0x19);
	func.SetByte(0x4E6BB5+2,0x01);
	func.SetByte(0x4E6BB5+3,0x00);
	func.SetByte(0x4E6BB5+4,0x00);

	// - [%s][%s] Try Attack In Not Attack Area (%s,%d,%d) errortype = %d
	
	func.SetByte(0x499F20,0xEB);

	// - [%s][%s] Try Attack In Not Attack Area [Protocol] (%s:%d,%d) errortype = %d
	
	func.SetByte(0x43EED2,0xEB);

	// - Close Time

	func.SetByte(0x4B2B55+3, 0x01);

	// - Skills do Siege

	func.SetByte(0x4A1E84,0xEB);
	func.SetByte(0x4A1E94,0xEB);
	func.SetByte(0x4A1F77,0xEB);
	func.SetByte(0x4A1F87,0xEB);
	func.SetByte(0x4A2094,0xEB);
	func.SetByte(0x4A20A4,0xEB);
	func.SetByte(0x4A2177,0xEB);
	func.SetByte(0x4A2187,0xEB);
	func.SetByte(0x4A2294,0xEB);
	func.SetByte(0x4A22A4,0xEB);
	func.SetByte(0x4A2384,0xEB);
	func.SetByte(0x4A2394,0xEB);
	func.SetByte(0x4A2467,0xEB);
	func.SetByte(0x4A2477,0xEB);

	// - gObjGetMagicSearch

	func.SetByte(0x4D8744,0xEB);

	// - CGDurationMagicRecv

	func.SetByte(0x440D44,0xEB);

	// - gObjGuildWarCheck

	*(DWORD*)(0x4DB923+1) = 50000;

	//--------------------------------------------------------------------
	// # Juntar Potions
	//--------------------------------------------------------------------

	*(DWORD*)(0x4C9C58 + 2) = 0x612A52;//509408 0x00612A52
	*(DWORD*)(0x4C9C65 + 6) = 0xFF;

	// - Mensagem de dragões

	const char DRAGON[]  = {""};
    memcpy((int*)0x6105C0,DRAGON,sizeof(DRAGON));
    memcpy((int*)0x6105BC,DRAGON,sizeof(DRAGON));

	// - GetStockObject

	func.SetByte(0x4FE82F+1,0x04);

	// - Decrease Logs Server

	func.SetNop(0x42197E,6); // - Monster Item Drop Request [%s] [%d][%d][%d] : [%s][%d][%d][%d][%d] Ex:[%d,%d,%d,%d,%d,%d,%d] Set:[%d]
	func.SetNop(0x422312,6); // - Monster Item Drop [%d][%d][%d] : serial:%d [%s][%d][%d][%d][%d] Ex:[%d,%d,%d,%d,%d,%d,%d] Set:[%d]
	func.SetNop(0x479EA5,6); // - Item has Disappeared
	func.SetNop(0x479105,6); // - Can't throw away the item
	func.SetNop(0x4BCEE8,6); // - Experience : [%s][%s](%d) %u %d
	func.SetNop(0x4BD115,6); // - Level Up
	func.SetNop(0x473C88,6); // - error-L1 : Socket Header error %d, %d
	func.SetNop(0x473C97,5); // - CloseClient
	func.SetNop(0x475C4A,6); // - error-L1 : CloseClient INVALID_SOCKET
	func.SetNop(0x475D38,6); // - error-L1 : CloseClient INVALID_SOCKET
	func.SetNop(0x471E44,6); // - [Quest] QuestSave [%s][%s] index(%d) name(%s) state(%s)
	func.SetNop(0x49CAAE,6); // - ¸¶°Ë»ç ¸ó½ºÅÍ¹æ¾î·Â°¨¼Ò : 10
	func.SetNop(0x474FAE,6); // - error-L2 : Index(%d) %x %x %x
	func.SetNop(0x42874B,6); // - [%s][%s][%s] ClientHack Detected : Editing AttackSpeed [%d][%d] [%d][%d]


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