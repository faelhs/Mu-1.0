/*
Code: Add new monsters to MuOnline client
Credits: DoS.Ninja
Web: ninja-researcher.blogspot.com
*/
#ifndef MONSTA_H
#define MONSTA_H

// Offsets and structures for Main 1.03.25(1.03y) JPN
#define OFFST_MODELRES_SIZEOF 0x005F365C
#define OFFST_MODELRES_COUNT 0x005F3657
#define OFFST_MODELRES_MOBS_ID 0x005FBB47

#define HPROC_OPENMONSTERMODEL_BULL 0x00518DAD
#define HARGS_BULL_PUSH HPROC_OPENMONSTERMODEL_BULL - 2
#define HPROC_CONSTMONSTERMODEL_BULL 0x00518DC8
#define HPROC_LOADBMDMODEL 0x005FBB93
#define HPROC_LOADPLAYERBMD 0x005F36E2
#define HPROC_SETMOBNAMESTYLE 0x0051B908

#define HOpenMonsterModel ((void (__cdecl *)(DWORD dwMobNumber)) 0x005FBB28)
#define HConstructMonsterModel ((DWORD (__cdecl *)(DWORD Arg1, DWORD dwResInx, DWORD dwResOffst, DWORD Arg4, DWORD Arg5)) 0x005148C8)
#define HLoadBMDModel ((DWORD (__cdecl *)(DWORD Arg1, LPSTR Arg2, LPSTR Arg3, DWORD Arg4)) 0x005F34C3)
#define HSetMonsterNameStyle ((DWORD (__cdecl *)(DWORD dwMemAddr, DWORD dwMobID, DWORD Arg3, DWORD Arg4)) 0x00516489)

/*
005F36AE  |. 8B15 10A0B306  MOV EDX,DWORD PTR DS:[6B3A010]
005F36B4  |. 03D0           ADD EDX,EAX
005F36B6  |. 8915 90F09D05  MOV DWORD PTR DS:[59DF090],EDX */
static DWORD *lpModelResBase = (DWORD *)0x6B3A010;
static DWORD *lpModelResArray = (DWORD *)0x59DF090;

struct Unit_Struct {
	BYTE Unknown1[32];
	BYTE bPKStatus;
	BYTE Unknown2[23];
	char cName[32];
	BYTE bMoveOut;
	BYTE Unknown5[303];
	signed short sItem1ResID;
	BYTE Unknown7;
	signed char bItem1IsExc;
	BYTE Unknown8;
	signed char bItem1JoinID;//6
	BYTE Unknown9[26];//26
	signed short sItem2ResID;
	BYTE Unknown10;
	signed char bItem2IsExc;
	BYTE Unknown11;
	signed char bItem2JoinID;//6
	BYTE Unknown12[292];
	BYTE bMobType;
	BYTE Unknown13[73];
	float fSize;
};

/*// Offsets and structures for Main 1.05.50(1.05x+) KOR
#define OFFST_MODELRES_SIZEOF 0x005C9AFF
#define OFFST_MODELRES_COUNT 0x005C9B04
#define OFFST_MODELRES_MOBS_ID 0x005D075D

#define HPROC_OPENMONSTERMODEL_BULL 0x004FCA33
#define HARGS_BULL_PUSH HPROC_OPENMONSTERMODEL_BULL - 2
#define HPROC_CONSTMONSTERMODEL_BULL 0x004FCA4E
#define HPROC_LOADBMDMODEL 0x005D07A9
#define HPROC_LOADPLAYERBMD 0x005C9B8A
#define HPROC_SETMOBNAMESTYLE 0x004FECBC

#define HOpenMonsterModel ((void (__cdecl *)(DWORD dwMobNumber)) 0x005D0754)
#define HConstructMonsterModel ((DWORD (__cdecl *)(DWORD Arg1, DWORD dwResInx, DWORD dwResOffst, DWORD Arg4, DWORD Arg5)) 0x004F88F6)
#define HLoadBMDModel ((DWORD (__cdecl *)(DWORD Arg1, LPSTR Arg2, LPSTR Arg3, DWORD Arg4)) 0x005C9983)
#define HSetMonsterNameStyle ((DWORD (__cdecl *)(DWORD dwMemAddr, DWORD dwMobID, DWORD Arg3, DWORD Arg4)) 0x004FA1DE)

//005C9B56  |.  8B15 9C29A506 MOV EDX,DWORD PTR DS:[6A5299C]
//005C9B5C  |.  03D0          ADD EDX,EAX
//005C9B5E  |.  8915 1C7A8F05 MOV DWORD PTR DS:[58F7A1C],EDX
static DWORD *lpModelResBase = (DWORD *)0x06A5299C;
static DWORD *lpModelResArray = (DWORD *)0x058F7A1C;

struct Unit_Struct{
BYTE Unknown4[31];
BYTE bPKStatus;
BYTE Unknown1[19];
BYTE bAnimationDie;
BYTE Unknown5[4];
char cName[25];
BYTE bMoveOut;
BYTE Unknown3[3];
BYTE bClanTag;
BYTE Unknown6[5];
BYTE bColor;
BYTE Unknown2[292];
signed short sItem1ResID;
BYTE Unknown7;
signed char bItem1IsExc;
BYTE Unknown8;
signed char bItem1JoinID;
BYTE Unknown9[26];
signed short sItem2ResID;
BYTE Unknown10;
signed char bItem2IsExc;
BYTE Unknown11;
signed char bItem2JoinID;
BYTE Unknown12[236];
BYTE bMobType;
BYTE Unknown13[73];
float fSize;
};
*/

struct MobParam_Struct {
	DWORD dwMobID;
	LPSTR lpName;
	signed char bMobType;
	signed char bPKStatus;
	signed char bMoveOut;
	signed short sItem1ResID;
	signed char bItem1IsExcl;
	signed char bItem1JoinID;
	signed short sItem2ResID;
	signed char bItem2IsExcl;
	signed char bItem2JoinID;
	float fSize;
};

struct MonsterAdd_Struct {
	DWORD dwMobID;
	char *lpDir;
	char *lpFile;
};

#define NONE -1
#define MONSTER_DIR "Data\\Monster\\"

void Init_Monsters();
void __cdecl Hook_OpenMonsterModel(DWORD dwMobNumber);
DWORD __cdecl Hook_ConstructMonsterModel(DWORD Arg1, DWORD dwResInx, DWORD dwResOffst, DWORD Arg4, DWORD Arg5);
void __cdecl Hook_FixLoadBMDModel(DWORD dwResInx, LPSTR lpDir, LPSTR lpBaseName, DWORD Arg4);
void __cdecl Hook_LoadPlayerBMD(DWORD dwResInx, LPSTR lpDir, LPSTR lpBaseName, DWORD Arg4);
void __cdecl Hook_SetMonsterNameStyle(DWORD dwMemAddr, DWORD dwMobID, DWORD Arg3, DWORD Arg4);
void ModifMonsParams(DWORD lpUnit, DWORD dwMobID);

#endif