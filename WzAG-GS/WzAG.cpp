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

HANDLE a;
int gType;
HANDLE g_hAllocFile;
unsigned long Bytes;
HANDLE hFile;
HANDLE hGA;

#define MAX_FILE_NAME 40

char szFileName[MAX_FILE_NAME][256];

#define AUTHKEY0	 41
#define AUTHKEY1	 35
#define AUTHKEY2	-66
#define AUTHKEY3	 0x00
#define AUTHKEY4	-31
#define AUTHKEY5	 108
#define AUTHKEY6	-42
#define AUTHKEY7	-82
#define AUTHKEY8	 82
#define AUTHKEY9	-112
#define AUTHKEY10	 73
#define AUTHKEY11	-15
#define AUTHKEY12	-15
#define AUTHKEY13	-69
#define AUTHKEY14	-23
#define AUTHKEY15	-21
#define AUTHKEY16	-77
#define AUTHKEY17	-90
#define AUTHKEY18	-37
#define AUTHKEY19	0x00

unsigned char szGSAuthKey[22]= { AUTHKEY0,
	AUTHKEY1,
	AUTHKEY2,
	AUTHKEY3,
	AUTHKEY4,
	AUTHKEY5,
	AUTHKEY6,
	AUTHKEY7,
	AUTHKEY8,
	AUTHKEY9,
	AUTHKEY10,
	AUTHKEY11,
	AUTHKEY12,
	AUTHKEY13,
	AUTHKEY14,
	AUTHKEY15,
	AUTHKEY16,
	AUTHKEY17,
	AUTHKEY18,
	AUTHKEY19 };

void MsgBox(const char *szLog, ...)
{
	char szBuffer[512]="";
	va_list pArguments;
	va_start(pArguments, szLog);
	vsprintf(szBuffer, szLog, pArguments);
	va_end(pArguments);
	MessageBox(NULL, szBuffer, "Error", MB_OK|MB_APPLMODAL|MB_ICONERROR);
}

BOOL APIENTRY DllMain( HANDLE hModule, 
	DWORD  ul_reason_for_call, 
	LPVOID lpReserved
	)
{
	hModule = a;
	return TRUE;
}

typedef void (*callfunc)(int,int);

extern "C" _declspec(dllexport)HANDLE AGSetInfo(int iCountryCode, unsigned char cPartition, unsigned short iServerCode, char* szServerVersion, char* szServerName, int ServerType, callfunc callbackfunc)
{
	char * szLanguage;

	switch(iCountryCode)
	{
	case 0:
		szLanguage="Kor";
		break;
	case 1:
		szLanguage="Eng";
		break;
	case 2:
		szLanguage="Jpn";
		break;
	case 3:
		szLanguage="Chs";
		break;
	case 4:
		szLanguage="Tai";
		break;
	case 5:
		szLanguage="Tha";
		break;
	case 6:
		szLanguage="Phi";
		break;
	case 7:
		szLanguage="Vtm";
		break;
	default:
		MessageBox(NULL, "Language Selected is not Supported\nChange Language in CommonServer.cfg","Error",MB_OK|MB_ICONERROR);
		break;
	}

	BOOL bUseMDrive = GetPrivateProfileInt("SETUP", "MDrive", 0, ".\\WzAG.ini");
	BOOL bIsGSServer = GetPrivateProfileInt("SETUP", "IsCastleSiegeGS", 0, ".\\WzAG.ini");

	char msb[256] = {0};

	if ( bIsGSServer == TRUE )
	{
		GetPrivateProfileString("SETUP", "MonsterSetBaseForGSCS", "MonsterSetBase_CS.txt", msb, 40, ".\\WzAG.ini");
	}

	char szTemp[MAX_FILE_NAME][256]={0};

	if ( bUseMDrive == TRUE )
	{
		for ( int j=0;j<MAX_FILE_NAME ; j++)
		{
			strcpy(szFileName[j], "M:\\");
		}

	}
	else
	{
		for ( int j=0;j<MAX_FILE_NAME ; j++)
		{
			strcpy(szFileName[j], "..\\data\\");
		}
	}

	strcat(szFileName[0], "lang\\Kor\\Item(Kor).txt");
	strcat(szFileName[2], "lang\\Kor\\Skill(Kor).txt");
	strcat(szFileName[4], "lang\\Kor\\Quest(Kor).txt");
	strcat(szFileName[7], "Monsters\\Monster.txt");
	strcat(szFileName[8], "Gate.txt");

	if ( bIsGSServer == TRUE )
	{
		strcat(szFileName[9], msb);
	}
	else
	{
		strcat(szFileName[9], "Monsters\\MonsterSetBase.txt");
	}

	strcat(szFileName[11], "Shops\\Shop0.txt");
	strcat(szFileName[12], "Shops\\Shop1.txt");
	strcat(szFileName[13], "Shops\\Shop2.txt");
	strcat(szFileName[14], "Shops\\Shop3.txt");
	strcat(szFileName[15], "Shops\\Shop4.txt");
	strcat(szFileName[16], "Shops\\Shop5.txt");
	strcat(szFileName[17], "Shops\\Shop6.txt");
	strcat(szFileName[18], "Shops\\Shop7.txt");
	strcat(szFileName[19], "Shops\\Shop8.txt");
	strcat(szFileName[20], "Shops\\Shop9.txt");
	strcat(szFileName[21], "Shops\\Shop10.txt");
	strcat(szFileName[22], "Shops\\Shop11.txt");
	strcat(szFileName[23], "Shops\\Shop12.txt");

	if ( iCountryCode != 0 )
	{
		wsprintf(szTemp[1], "lang\\%s\\Item(%s).txt", szLanguage, szLanguage);
		wsprintf(szTemp[3], "lang\\%s\\Skill(%s).txt", szLanguage, szLanguage);
		wsprintf(szTemp[5], "lang\\%s\\Quest(%s).txt", szLanguage, szLanguage);
		wsprintf(szTemp[6], "lang\\%s\\CheckSum.dat", szLanguage);
		wsprintf(szTemp[24], "lang\\%s\\Movereq(%s).txt", szLanguage, szLanguage);
		wsprintf(szTemp[26], "lang\\%s\\ItemSetOption(%s).txt", szLanguage, szLanguage);
		wsprintf(szTemp[28], "lang\\%s\\ItemSetType(%s).txt", szLanguage, szLanguage);
		wsprintf(szTemp[MAX_FILE_NAME-1], "lang\\%s\\commonloc.cfg", szLanguage);

		strcat(szFileName[1], szTemp[1]);
		strcat(szFileName[3], szTemp[3]);
		strcat(szFileName[5], szTemp[5]);
		strcat(szFileName[6], szTemp[6]);
		strcat(szFileName[24], szTemp[24]);
		strcat(szFileName[26], szTemp[26]);
		strcat(szFileName[28], szTemp[28]);
		strcat(szFileName[MAX_FILE_NAME-1], szTemp[MAX_FILE_NAME-1]);
	}
	else
	{
		strcat(szFileName[MAX_FILE_NAME-1], "lang\\Kor\\commonloc.cfg");
		strcat(szFileName[6], "lang\\Kor\\CheckSum.dat");
		strcat(szFileName[24],"lang\\Kor\\Movereq(Kor).txt");
		strcat(szFileName[26],"lang\\Kor\\ItemSetOption(Kor).txt");
		strcat(szFileName[28],"lang\\Kor\\ItemSetType(Kor).txt");
	}

	Loaddll();	

	return a;
}

extern "C" _declspec(dllexport)void AGGetClientVersion(HANDLE handle,char* szClientVersion,char* szClientSerial)
{
	GetPrivateProfileString("GameServerInfo","ClientExeVersion","1.02.15",szClientVersion,8,szFileName[MAX_FILE_NAME-1]);
	GetPrivateProfileString("GameServerInfo","ClientExeSerial","Made_By_Deathway",szClientSerial,20,szFileName[MAX_FILE_NAME-1]);
}

extern "C" _declspec(dllexport)void AGSetSubInfo(HANDLE handle,int gServerMaxUser,int gObjTotalUser,int gMonsterHp,int gItemDropPer,int gAddExperience,int GetEventFlag())
{
}

extern "C" _declspec(dllexport)void AGGetKey(HANDLE handle,char* key,int startindex,int len)
{
	for (int counter=0; counter<len; counter++)
	{
		key[startindex+counter]=szGSAuthKey[startindex+counter];
	}
}

extern "C" _declspec(dllexport)void AGRequestData(HANDLE handle,int type)
{
	gType=type;
}

extern "C" _declspec(dllexport)int AGGetDataBufferSize(HANDLE handle)
{
	int iFileSize;

	if (hFile != NULL)
	{
		CloseHandle(hFile);
		GlobalUnlock((HGLOBAL)g_hAllocFile);
		GlobalFree((HGLOBAL)hGA);
	}

	hFile=CreateFile(szFileName[gType],GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_ARCHIVE,NULL);

	if ( hFile == NULL )
	{
		MsgBox("Can't Open File %s [%d]", szFileName[gType], GetLastError());
		return 0;
	}

	iFileSize = GetFileSize(hFile, NULL);
	hGA= GlobalAlloc(GHND, iFileSize+1);
	g_hAllocFile = GlobalLock((HGLOBAL)hGA);
	ReadFile(hFile, g_hAllocFile, iFileSize, &Bytes, NULL);
	CloseHandle(hFile);
	hFile = NULL;

	return iFileSize;

}

extern "C" _declspec(dllexport)char* AGGetDataBuffer(HANDLE handle)
{
	if ( g_hAllocFile == NULL )
	{
		MsgBox("Allocation Failed : Request [%d]", gType);
		return NULL;
	}

	return (char*)g_hAllocFile;
}

extern "C" _declspec(dllexport)void AGConnectSetFS()
{
	MessageBox(NULL,"Function Not Supported","Deathway",MB_OK|MB_ICONERROR);
}

extern "C" _declspec(dllexport)void AGReleaseHandle(HANDLE handle)
{
	if (hFile != NULL)
	{
		CloseHandle(hFile);
		hFile = NULL;
		GlobalUnlock((HGLOBAL)g_hAllocFile);
		GlobalFree((HGLOBAL)hGA);
	}
}