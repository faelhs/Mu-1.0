#include "StdAfx.h"

GMSYSTEM GMSystemInfo[255];

int GMSystemCount;

void ReadGMSystem()
{
	FILE *fp;
	BOOL bRead = FALSE;
	DWORD dwArgv = 0;
	char sLineTxt[255] = {0};
	GMSystemCount = 1;

	fp = fopen(CFG_GMSYSTEM,"r");

	if(!fp)
	{
		MessageBoxA(NULL, CFG_GMSYSTEM, "Error!", MB_OK);
		::ExitProcess(0);
	}

	rewind(fp);
	
	while(fgets(sLineTxt, 255, fp) != NULL)
	{
		if(sLineTxt[0] == '/')continue;
		if(sLineTxt[0] == ';')continue;

		int n[20];
		char GetGMName[11];

		sscanf(sLineTxt, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &GetGMName,&n[1],&n[2],&n[3],&n[4],&n[5],&n[6],&n[7],&n[8],&n[9],&n[10],&n[11],&n[12], &n[13], &n[14], &n[15],&n[16]);
		sprintf(GMSystemInfo[GMSystemCount].Name,"%s",GetGMName);
		
		GMSystemInfo[GMSystemCount].GMPremiar		= n[1];
		GMSystemInfo[GMSystemCount].GMMoveAll		= n[2];
		GMSystemInfo[GMSystemCount].GMSkin			= n[3];
		GMSystemInfo[GMSystemCount].GMMove  		= n[4];
		GMSystemInfo[GMSystemCount].GMVisible		= n[5];		
		GMSystemInfo[GMSystemCount].GMDrop			= n[6];
		GMSystemInfo[GMSystemCount].GMChuva			= n[7];
		GMSystemInfo[GMSystemCount].GMReload		= n[8];
		GMSystemInfo[GMSystemCount].GMSetLevel		= n[9];
		GMSystemInfo[GMSystemCount].GMSetPts		= n[10];
		GMSystemInfo[GMSystemCount].GMMakeSet		= n[11];
		GMSystemInfo[GMSystemCount].GMMake			= n[12];
		GMSystemInfo[GMSystemCount].GMFakeName		= n[13];
		GMSystemInfo[GMSystemCount].GMSetQuest		= n[14];
		GMSystemInfo[GMSystemCount].GMSpawn		    = n[15];
		GMSystemInfo[GMSystemCount].GMJail		    = n[16];
			
		GMSystemCount++;
	}

	rewind(fp);
	fclose(fp);
}