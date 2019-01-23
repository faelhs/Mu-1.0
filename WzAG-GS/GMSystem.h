#ifndef _GMSYSTEM_H
#define _GMSYSTEM_H

void ReadGMSystem();
 
typedef struct GMSystem
{
	char Name[11];

	int GMPremiar;
	int GMMoveAll;
	int GMSkin;
	int GMMove;	
	int GMVisible;
	int GMDrop;
	int GMChuva;
	int GMReload;
	int GMSetLevel;
	int GMSetPts;
	int GMMakeSet;
	int GMMake;
	int GMFakeName;
	int GMSetQuest;
	int GMSpawn;
	int GMJail;

}GMSYSTEM;

extern GMSYSTEM GMSystemInfo[255];

extern int GMSystemCount;

#endif
