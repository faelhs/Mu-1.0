#include "stdafx.h"
#include "WinSock2.h"
#include "ws2def.h"

class OffTrade
{
public:
	OffTrade(void);
	~OffTrade(void);
	void CreateOfflineStore(int aIndex);
	void InitOfflineTrade();

	struct sConfigs
	{
		int Enabled;
		int LevelReq;  
		DWORD PriceZen;  
	}Configs;
};extern OffTrade OfflineTrade;

#define HIDE_ERRORL10
#define MAX_EXSENDBUF_SIZE 7024
#define MAX_IO_BUFFER_SIZE		6000
#define MAX_IO_THREAD_HANDLES	16

struct _PER_IO_CONTEXT_2
{ 
	WSAOVERLAPPED Overlapped; 
	WSABUF wsabuf; 
	unsigned char Buffer[MAX_IO_BUFFER_SIZE]; 
	unsigned char BufferSecond[MAX_IO_BUFFER_SIZE]; 
	int nSecondOfs; 
	int nTotalBytes;
	int nSentBytes; 
	int IOOperation; 
	int nWaitIO; 
}; 

struct _PER_SOCKET_CONTEXT_2
{
	SOCKET m_socket;	
	int nIndex;	
	_PER_IO_CONTEXT_2 IOContext[2];	
	int dwIOCount;	
}; 

struct PSBMSG_HEAD_TT
{
    BYTE type;
	BYTE size;
	BYTE head;
	BYTE subh;
};

struct PMSG_ANS_PERIODITEM_INSERT
{
	PBMSG_HEAD2 head;
	int iUserIndex;
	int iItemCode;
	int iItemPeriodDate;
	BYTE btItemEffectType1;
	BYTE btItemEffectType2;
	BYTE btResult;
};

struct PMSG_IDPASS {
	struct PSBMSG_HEAD_TT h;
	unsigned char subcode;
	char Id[10];
	char Pass[10];
	unsigned long TickCount;
	unsigned char CliVersion[5];
	unsigned char CliSerial[16];
};

#define CGPShopAnsClose_Hook 0x004041C4
#define CGPShopAnsClose ((void(*)(int,BYTE))0x0044B2C0)
#define ResponErrorCloseClient ((void(*)(int))0x004B4130)
#define ResponErrorCloseClient_Hook 0x00403E95
#define CloseClient2_Ex ((void(*)(_PER_SOCKET_CONTEXT*,int))0x004B3F70)
#define CloseClient2_Hook 0x004057D6
#define CSPJoinIdPassRequest_Hook 0x0040291E
#define CSPJoinIdPassRequest ((void(*)(PMSG_IDPASS *lpMsg, int aIndex)) 0x0043A670)
#define gObjDelHook 0x00403AE4
#define gObjCloseSetHook 0x00401B5E

void CGPShopAnsClose_Ex(int aIndex, BYTE btResult);
void CloseClient2Ex(_PER_SOCKET_CONTEXT_2 * lpPerSocketContext, int result);
void __cdecl CSPJoinIdPassRequestEx(PMSG_IDPASS *lpMsg, int aIndex);
int CheckItems(DWORD PlayerID,DWORD itemId,int ItemLevel,int ItemOpt,int ItemLuck,int ItemSkill);
int  retResistance(LPOBJ lpObj, int Resistance_Type);
short gObjDel_Ex(int aIndex);
void ResponErrorCloseClientEx(int Index);


