#include "Principal.h"

//=======================================================================================================================
// Model Loader folder Jewels
//=======================================================================================================================
char* CustomzFolderJewels = "Custom\\Jewels\\";
char* WaytoCustomzJewels = "Data\\Custom\\Jewels\\";
//=======================================================================================================================
// Model Loader folder Boxs
//=======================================================================================================================
char* CustomzFolderBox = "Custom\\Boxs\\";
char* WaytoCustomzBox = "Data\\Custom\\Boxs\\";
//=======================================================================================================================
char* CustomzFolderAlas = "Data\\Custom\\alas\\";
char* WaytoCustomzAlas = "Custom\\alas\\";

int Flag = 2;


struct DataJMP
{
	BYTE Command;
	DWORD PointerToFunc;
};

#define API_CALL(F,...) (API_TYPE_##F API_ADDR_##F)(__VA_ARGS__)

#define API_ADDR_LoadBmdFile 0x005E10E0

#define API_TYPE_LoadBmdFile (int (__cdecl *)(int, char *, char *, int))

#define API_ADDR_LoadTxtFile 0x005E0CA0 

#define API_TYPE_LoadTxtFile (int (__cdecl *)(int, char *, int, int, int))

void LoadThisFuckingModelByITEMID(int ItemID,char* ModelName,char* FolderFrom,char* WayFrom)
{
	API_CALL(LoadBmdFile, ItemID, WayFrom, ModelName, -1);
	API_CALL(LoadTxtFile, ItemID, FolderFrom, 0x2901, 0x2600, 1); 
}

void LoadThisFuckingModelByITEMID(int ItemID,char* ModelName,char* FolderFrom,char* WayFrom, int ItemIndex)
{
	API_CALL(LoadBmdFile, ItemID, WayFrom, ModelName, ItemIndex);
	API_CALL(LoadTxtFile, ItemID, FolderFrom, 0x2901, 0x2600, 1); 
}

__declspec(naked) void PatchMainForLoadModels()
{
//============================================================================
// Custom Conditional BMD de Box
//============================================================================
	LoadThisFuckingModelByITEMID(ITEM(12,25), "BoxGreen", CustomzFolderBox, WaytoCustomzBox);
	LoadThisFuckingModelByITEMID(ITEM(12,26), "BoxPurple", CustomzFolderBox, WaytoCustomzBox);
	LoadThisFuckingModelByITEMID(ITEM(12,27), "BoxRed", CustomzFolderBox, WaytoCustomzBox);
//============================================================================
// Custom Conditional BMD de Jewels
//============================================================================
	LoadThisFuckingModelByITEMID(ITEM(12,28), "JewelOfDragon",	CustomzFolderJewels, WaytoCustomzJewels);
	LoadThisFuckingModelByITEMID(ITEM(14,27), "Jewel29",	CustomzFolderJewels, WaytoCustomzJewels);
	LoadThisFuckingModelByITEMID(ITEM(14,30), "JewelGreen", CustomzFolderJewels, WaytoCustomzJewels);
//============================================================================
// Custom Conditional BMD de Jewels
//============================================================================
	LoadThisFuckingModelByITEMID(ITEM(15,134), "Wing04",	CustomzFolderAlas, WaytoCustomzAlas);
	LoadThisFuckingModelByITEMID(ITEM(15,135), "Wing05",	CustomzFolderAlas, WaytoCustomzAlas);
	LoadThisFuckingModelByITEMID(ITEM(15,136), "Wing06", CustomzFolderAlas, WaytoCustomzAlas);
	LoadThisFuckingModelByITEMID(ITEM(15,137), "Wing07", CustomzFolderAlas, WaytoCustomzAlas);
	_asm
	{
		PUSH -1								; /Arg4 = FFFFFFFF
		PUSH 0x00673430						; |Arg3 = 00673430 ASCII "suho"
		PUSH 0x0067365C						; |Arg2 = 0067365C ASCII "Data\Item\"
		PUSH 0x3D8							; |Arg1 = 000003D8
		mov eax,BMDModelLoad 
		CALL eax                   			; \Main.005F1D33
		mov eax,ReturnOffset
		JMP eax
	}
}

void ModelsLoad()
{
	DataJMP ModelJMP;
	SetNop(LoadModel_Offset, 22);
	ModelJMP.Command = 0xE9;
	ModelJMP.PointerToFunc = (DWORD)&PatchMainForLoadModels;

	memcpy((int*)LoadModel_Offset, &ModelJMP, sizeof(ModelJMP));
	HookThis((DWORD)&PatchMainForLoadModels, LoadModel_Offset);
}


