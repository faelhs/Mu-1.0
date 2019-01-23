#include "Principal.h"

//=======================================================================================================================
// Model Loader
//=======================================================================================================================
char* CustomzFolder = "Customs\\Jewels\\";
char* WaytoCustomz = "Data\\Customs\\Jewels\\";
//=======================================================================================================================
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
	LoadThisFuckingModelByITEMID(ITEM(12, 15), "Jewel25", CustomzFolder, WaytoCustomz);
	LoadThisFuckingModelByITEMID(ITEM(12, 25), "Jewel25", CustomzFolder, WaytoCustomz);
	LoadThisFuckingModelByITEMID(ITEM(12,26), "Jewel26",	CustomzFolder, WaytoCustomz);
	LoadThisFuckingModelByITEMID(ITEM(12,27), "Jewel27",	CustomzFolder, WaytoCustomz);
	LoadThisFuckingModelByITEMID(ITEM(12,28), "Jewel28",	CustomzFolder, WaytoCustomz);
	LoadThisFuckingModelByITEMID(ITEM(12,29), "Jewel29",	CustomzFolder, WaytoCustomz);
	LoadThisFuckingModelByITEMID(ITEM(14,30), "Jewelluck",	CustomzFolder, WaytoCustomz);
	LoadThisFuckingModelByITEMID(ITEM(7, 30), "HelmMale31", "Player\\", "Data\\Player\\");
	LoadThisFuckingModelByITEMID(ITEM(8, 30), "ArmorMale31", "Player\\", "Data\\Player\\");
	LoadThisFuckingModelByITEMID(ITEM(9, 30), "PantMale31", "Player\\", "Data\\Player\\");
	LoadThisFuckingModelByITEMID(ITEM(10, 30), "GloveMale31", "Player\\", "Data\\Player\\");
	LoadThisFuckingModelByITEMID(ITEM(11, 30), "BootMale31", "Player\\", "Data\\Player\\");

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

