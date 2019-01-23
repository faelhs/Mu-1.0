#pragma once


struct NpcsStruct
{
	int EnabledNpcNoob;

	int SetNumberBK;
	int SetNumberSM;
	int SetNumberDL;
	int SetNumberMG;
	int SetNumberElf;

	int LevelItems;
	int ExcItem;

	int ArmaIndexBK;
	int ArmaTypeBK;

	int ArmaIndexSM;
	int ArmaTypeSM;

	int ArmaIndexElf;
	int ArmaTypeElf;

	int ArmaIndexDL;
	int ArmaTypeDL;

	int ArmaIndexMG;
	int ArmaTypeMG;
};
extern NpcsStruct NpcStc;

void Helper(OBJECTSTRUCT*pObj, OBJECTSTRUCT* gObjNPC);