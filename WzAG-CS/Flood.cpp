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

sIpInfo IpInfo[2000];

int LastIPList = 0;

int Flood::GetIPIndex(char* ip)
{
	int Ret = -1;

	for (int x = 0; x < LastIPList; x++)
	{
		if (IpInfo[x].ip[0] == ip[0])
		{
			if (strcmp(IpInfo[x].ip,ip) == 0)
			{
				return x;
				break;
			}
		}
	}

	Ret = LastIPList;
	sprintf(IpInfo[LastIPList].ip,"%s",ip);

	LastIPList++;

	if(LastIPList >= 2000)
	{
		LastIPList = 0;
	}

	return Ret;
}

short Flood::Connection(SOCKET szSocket, char* szAddress,DWORD aIndex)
{
	int IPIndex = GetIPIndex(szAddress);

	DWORD CurTick = (GetTickCount() - IpInfo[IPIndex].LastConnect) / 1000;

	if (CurTick < 3)
	{
		IpInfo[IPIndex].LastConnect = GetTickCount();
		return -1;
	}

	IpInfo[IPIndex].LastConnect = GetTickCount();
	return j_gObjAdd(szSocket, szAddress,aIndex);
}