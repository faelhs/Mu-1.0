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
	BYTE InventoryMap[64];
	void HookThis(DWORD dwMyFuncOffset,DWORD dwJmpOffset);
	void HookProc(DWORD Offset, DWORD Func);
	void SetNop(DWORD Offset,int Size);
	void Set00(DWORD Offset,int Size);
	void SetRetn(DWORD Offset);
	void SetRRetn(DWORD Offset);
	void SetByte(DWORD Offset,BYTE btValue);
	void SetString(DWORD Offset, char* btString, int Size);
	int Get_PlayerIndex(char *Name);
	void MosterAdd(int MobID, int MapID, int CoordX, int CoordY);
	static void gObjLifeCheckHook(LPOBJ lpTargetObj, LPOBJ lpObj, int AttackDamage, int DamageSendType, int MSBFlag, int MSBDamage, BYTE Skill,int iShieldDamage);								 
	void FireWork(int aIndex);
	static BOOL HookgObjAttack(OBJECTSTRUCT* lpObj, OBJECTSTRUCT* lpTargetObj, class CMagicInf* lpMagic, int magicsend, unsigned char MSBFlag, int AttackDamage, BOOL bCombo);
	static void gObjPlayerKillerEx(LPOBJ lpObj, LPOBJ lpTargetObj);
	static void gObjInterfaceTimeCheckEx(LPOBJ lpObj);
	static void gObjSecondProcEx();
	static void gObjCloseSetEx(int aIndex, int flag);
	static short gObjDelEx(int aIndex);
	static void gObjUserDieEx(LPOBJ lpObj, LPOBJ lpTargetObj);
	static BYTE gObjInventoryMoveItemEx(int aIndex, unsigned char source, unsigned char target, int& durSsend, int& durTsend, unsigned char sFlag, unsigned char tFlag, unsigned char* siteminfo);
	static bool gObjLevelUpEx(LPOBJ lpObj, int addexp, int iMonsterType, int iEventType);
	BOOL GetBoxPosition(int MapNumber, int X, int Y, int W, int H, short& rX, short& rY);
	void MakeNoticeMsg(void * lpNotice, BYTE btType, char * szNoticeMsg);
	void MsgUser(int aIndex, int Type, char * Msg, ...);
	void MsgAllUser(int Type, char * Msg, ...);
	static void AllSendServerMsg(char* chatmsg);
	void BlueChatSend(LPCSTR Nome, LPSTR Mensagem, DWORD aIndex);
	void GreenChatSend(LPCSTR Nome, LPSTR Mensagem, DWORD aIndex);
	void YellowChatSend(LPCSTR Nome, LPSTR Mensagem, DWORD aIndex);
	void UpdateCharacter(int aIndex, bool Effect);
	int GetInventoryItemCount(int aIndex, int Type, int Level);
	int gObjDeleteItemsCount(int gObjId, short Type, short Level, int Count);
	void Check(LPOBJ lpObj);
	void HealthBarSend(LPOBJ lpObj);
	static void GCWarePassSend(int aIndex, PMSG_WAREHOUSEPASSSEND * lpMsg);
	void QuestsSend(LPOBJ lpObj);
	void CheckPet(LPOBJ lpObj);
	bool IniciaIni();
	bool SystemIPS( char * ini );
	void LevelUPSend(DWORD aIndex);
	bool IsOnGame(int iIndex);
	bool IsBadFileLine(char *FileLine, int &Flag);
	int GenExcOpt(int amount);
	void MsgOutputAll(char *message, ...);
	bool WarehouseHacker(int aIndex);	
	int MyRand(int min, int max);
	void ChkJail(LPOBJ lpObj);
	void SaveQuest(int aIndex);
	void ResetQuest(int aIndex);
	void CGTalkRequestRecv(PMSG_TALKREQUEST* lpMsg, int aIndex);
	void CGBuyRequestRecv(PMSG_BUYREQUEST* lpMsg, int aIndex);
	void ItemSerialCreateSendEx(int aIndex, int MapNumber, int x, int y, int Type, int Level, int Dur, int Skill, int Luck, int Option,int LootIndex,int Excellent,int Ancient);
	int InventoryMapCheck(int aIndex,int X, int Y, int Width, int Height);
	int GetPartyMemberIndex(int party_number);
};

extern Functions func;


void StartAddress(LPVOID lpThreadParameter);
