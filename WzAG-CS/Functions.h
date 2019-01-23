//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 99.60T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#pragma once

class Functions
{
public:
	void HookThis(DWORD dwMyFuncOffset,DWORD dwJmpOffset);
	void HookProc(DWORD Offset, DWORD Func);
	void SetNop(DWORD Offset,int Size);
	void Set00(DWORD Offset,int Size);
	void SetRetn(DWORD Offset);
	void SetRRetn(DWORD Offset);
	void SetByte(DWORD Offset,BYTE btValue);
	void SetString(DWORD Offset, char* btString, int Size);
	int Get_PlayerIndex(char *Name);
	void FireWork(int aIndex);
	static BOOL HookgObjAttack(OBJECTSTRUCT* lpObj, OBJECTSTRUCT* lpTargetObj, class CMagicInf* lpMagic, int magicsend, unsigned char MSBFlag, int AttackDamage, BOOL bCombo);
	static void gObjInterfaceTimeCheckEx(LPOBJ lpObj);
	static void gObjSecondProcEx();
	static void gObjPlayerKillerEx(LPOBJ lpObj, LPOBJ lpTargetObj);
	static bool gObjLevelUpEx(LPOBJ lpObj, int addexp, int iMonsterType, int iEventType);
	void MakeNoticeMsg(void * lpNotice, BYTE btType, char * szNoticeMsg);
	void MsgUser(int aIndex, int Type, char * Msg, ...);
	void MsgAllUser(int Type, char * Msg, ...);
	static void AllSendServerMsg(char* chatmsg);
	void BlueChatSend(LPCSTR Nome, LPSTR Mensagem, DWORD aIndex);
	void GreenChatSend(LPCSTR Nome, LPSTR Mensagem, DWORD aIndex);
	void YellowChatSend(LPCSTR Nome, LPSTR Mensagem, DWORD aIndex);
	void UpdateCharacter(int aIndex, bool Effect);
	void Check(LPOBJ lpObj);
	void HealthBarSend(LPOBJ lpObj);
	void CheckPet(LPOBJ lpObj);
	bool IniciaIni();
	bool SystemIPS( char * ini );
};

extern Functions func;

void StartAddress(LPVOID lpThreadParameter);