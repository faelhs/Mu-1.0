#include "Principal.h"
#include "MiniMap.h"


BYTE *Main_MiniMapShow = (BYTE*)0x00410426;

int *Map		= (int*)0x67198C;
char CurrentDir1[_MAX_PATH];
char configname[_MAX_PATH];
int  LastMap;
bool IsMiniMap;
bool ShowMiniMap;
bool FileExists2(char * name);
typedef int(*TLoadImage)(char[64], int, int, int, int, int);
typedef int(*TUnBlend2) ();

TUnBlend2 UnBlend2 = (TUnBlend2)0x005F1330;
TLoadImage LoadImg = (TLoadImage)0x0060F900;

bool FileExists2(char * name)
{
	if (CreateFile(name, 0, 0, 0, OPEN_EXISTING, 0, 0) == INVALID_HANDLE_VALUE)
		return false;
	return true;
}

void MiniMap()
{
	char path[64];
	char mypath[MAX_PATH];
	LastMap = 100;
	if (LastMap != *Map)
	{
		sprintf_s(path, "Maps\\map%d.jpg", *Map + 1);
		sprintf_s(mypath, "%sData\\Maps\\map%d.OZJ", CurrentDir1, *Map + 1);

		if (FileExists2(mypath))
		{
			LoadImg(path, 0x690, 0x2601, 0x2900, 0, 1);
			IsMiniMap = true;
		}
		else
		IsMiniMap = false;
		LastMap = *Map;
	}

	if (IsMiniMap == true)
		*Main_MiniMapShow = 0xEB;
	else
		*Main_MiniMapShow = 0x74;
	UnBlend2();


}

void HookMiniMap()
{
	HookOffset((DWORD)&MiniMap, 0x005829B9, 0xE8);
}



