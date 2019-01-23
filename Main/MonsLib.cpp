/*
Code: Add new monsters to MuOnline client
Credits: DoS.Ninja
Web: ninja-researcher.blogspot.com
*/
#include "Principal.h"

#define ADD_MOBS_COUNT 3
MonsterAdd_Struct s_AddMob[ADD_MOBS_COUNT] = {
	{ 555, MONSTER_DIR, "Monster555" },
	{ 556, MONSTER_DIR, "Monster13" },
	{ 557, MONSTER_DIR, "Monster13" },
};
DWORD dwNewMobResInx[ADD_MOBS_COUNT];

#define MOBS_PARAMS_COUNT 4
MobParam_Struct s_ParamMob[MOBS_PARAMS_COUNT] = {
	{ 555, "New mob1", NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 0 },
	{ 556, "New mob2", 4, 5, 0, 0x057c, 1, 44, 0x0F81, 1, 22, 1 },
	{ 557, "New mob3", 4, 1, 0, NONE, NULL, NULL, -1, NULL, NULL, 1.5 },
	{ 24, "Worm Killer", 1, 7, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 2 }
};

DWORD dwModelResInx, dwModelMobsID, dwModelResSizeof, dwModelResCount;
int iTempMobID = NONE;
/*
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Init_Monsters();
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
*/

void Init_Monsters() {
	DWORD dwResSize, dwResCount, dwTotalSize;

	// Get resource ID
	dwModelResSizeof = *(DWORD*)(OFFST_MODELRES_SIZEOF + 1);
	dwModelResCount = *(DWORD*)(OFFST_MODELRES_COUNT + 1);
	dwModelMobsID = *(DWORD*)(OFFST_MODELRES_MOBS_ID + 2);

	// Hook some proc for calc resource id 
	HookAddress(HPROC_LOADPLAYERBMD, (DWORD)Hook_LoadPlayerBMD, NULL);

	// Hook zero-bull load
	HookAddress(HPROC_OPENMONSTERMODEL_BULL, (DWORD)Hook_OpenMonsterModel, NULL);
	memset((void*)(HARGS_BULL_PUSH), _asm_nop, 2);
	MEMORY1(HARGS_BULL_PUSH) = _asm_push_eax; // Change PUSH 0 to PUSH EAX

											  // Hook construct zero-bull model
	HookAddress(HPROC_CONSTMONSTERMODEL_BULL, (DWORD)Hook_ConstructMonsterModel, NULL);

	// Fix load resurce id in OpenMonsterModel() HPROC_LOADBMDMODEL
	HookAddress(HPROC_LOADBMDMODEL, (DWORD)Hook_FixLoadBMDModel, NULL);

	//Hook set mob name style, for change mob params
	HookAddress(HPROC_SETMOBNAMESTYLE, (DWORD)Hook_SetMonsterNameStyle, NULL);

}

void __cdecl Hook_LoadPlayerBMD(DWORD dwResInx, LPSTR lpDir, LPSTR lpBaseName, DWORD Arg4) {
	// Hook procedure only for calc model resource indexes after heapalloc memory block
	DWORD dwEnd, dwDiff, dwSize;

	// calc model resource index
	dwSize = dwModelResSizeof * dwModelResCount;
	dwDiff = *lpModelResArray - *lpModelResBase;
	dwModelResInx = (dwSize - dwDiff) / dwModelResSizeof;

	// set resource index for new monsters
	for (int i = 0; i<ADD_MOBS_COUNT; i++) {
		dwNewMobResInx[i] = dwModelResInx - i - 1;
		s_AddMob[i].dwMobID -= 1;//fix, LoadModel(mob_id) where mob_id = server_mob_id - 1
	}

	//back to load player.bmd
	HLoadBMDModel(dwResInx, lpDir, lpBaseName, Arg4);//original
}

void __cdecl Hook_OpenMonsterModel(DWORD dwMobNumber) {
	// Change zero-bull to new mob (if need)
	if (dwMobNumber != -1)// if not zero-bull
	{
		for (int i = 0; i<ADD_MOBS_COUNT; i++) {
			if (dwMobNumber == s_AddMob[i].dwMobID) {
				dwMobNumber = dwNewMobResInx[i] - dwModelMobsID;
				iTempMobID = i;
				break;
			}
		}
	}
	else
		dwMobNumber = 0;

	HOpenMonsterModel(dwMobNumber);//original
}

void __cdecl Hook_FixLoadBMDModel(DWORD dwResInx, LPSTR lpDir, LPSTR lpBaseName, DWORD Arg4) {
	// Change load bmd model params (if need)
	if (iTempMobID != NONE) {
		lpDir = s_AddMob[iTempMobID].lpDir;
		lpBaseName = s_AddMob[iTempMobID].lpFile;
		Arg4 = -1;
	}

	HLoadBMDModel(dwResInx, lpDir, lpBaseName, Arg4);//original
}

DWORD __cdecl Hook_ConstructMonsterModel(DWORD Arg1, DWORD dwResInx, DWORD dwResOffst, DWORD Arg4, DWORD Arg5) {
	// Change new resource ID (if need)
	if (iTempMobID != NONE) {
		dwResInx = dwNewMobResInx[iTempMobID];
		iTempMobID = NONE;
	}

	return HConstructMonsterModel(Arg1, dwResInx, dwResOffst, Arg4, Arg5);//original
}

void __cdecl Hook_SetMonsterNameStyle(DWORD dwMemAddr, DWORD dwMobID, DWORD Arg3, DWORD Arg4) {
	// Hook for change monster parametres
	HSetMonsterNameStyle(dwMemAddr, dwMobID, Arg3, Arg4);//original
	ModifMonsParams(dwMemAddr, dwMobID);
}

void ModifMonsParams(DWORD lpUnit, DWORD dwMobID) {

	for (int i = 0; i<MOBS_PARAMS_COUNT; i++)
	{
		if (s_ParamMob[i].dwMobID == dwMobID)
		{
			Unit_Struct *pUnit;
			pUnit = (Unit_Struct*)lpUnit;

			if (s_ParamMob[i].lpName != NULL)
				sprintf(pUnit->cName, "%s", s_ParamMob[i].lpName);

			if (s_ParamMob[i].bMoveOut != NONE)
				pUnit->bMoveOut = s_ParamMob[i].bMoveOut;

			if (s_ParamMob[i].bMobType != NONE)
				pUnit->bMobType = s_ParamMob[i].bMobType;

			if (s_ParamMob[i].fSize != NULL)
				pUnit->fSize = s_ParamMob[i].fSize;

			if (s_ParamMob[i].bPKStatus != NONE)
				pUnit->bPKStatus = s_ParamMob[i].bPKStatus;

			//Hand first
			if (s_ParamMob[i].sItem1ResID != NONE)
				pUnit->sItem1ResID = s_ParamMob[i].sItem1ResID;

			if (s_ParamMob[i].bItem1IsExcl != NONE)
				pUnit->bItem1IsExc = s_ParamMob[i].bItem1IsExcl;

			if (s_ParamMob[i].bItem1JoinID != NONE)
				pUnit->bItem1JoinID = s_ParamMob[i].bItem1JoinID;

			//Hand second
			if (s_ParamMob[i].sItem2ResID != NONE)
				pUnit->sItem2ResID = s_ParamMob[i].sItem2ResID;

			if (s_ParamMob[i].bItem2IsExcl != NONE)
				pUnit->bItem2IsExc = s_ParamMob[i].bItem2IsExcl;

			if (s_ParamMob[i].bItem2JoinID != NONE)
				pUnit->bItem2JoinID = s_ParamMob[i].bItem2JoinID;

		}
	}
}