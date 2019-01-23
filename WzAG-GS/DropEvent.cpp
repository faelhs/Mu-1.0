#include "StdAfx.h"

cDropEvent DropEvent;

void cDropEvent::LoadConfigs()
{
	Enable = GetPrivateProfileInt("DropEvent","Ativar",1,CFG_DROPEVT);
	ItemCount = GetPrivateProfileInt("DropEvent","ItemCount",15,CFG_DROPEVT);

	for(int i = 0;i < DROP_EVENT_MAX; i++)
	{
		Item[i].Index			= 0;
		Item[i].Type			= 0;
		Item[i].Level			= 0;
		Item[i].Durabilidade	= 0;
		Item[i].Skill			= 0;
		Item[i].Luck			= 0;
		Item[i].Opt				= 0;
		Item[i].Exl				= 0;
	}

	for(int j=0;j < DROP_EVENT_MAX; j++)
	{
		Time[j].Hour	= 0;
		Time[j].Min		= 0;
	}

	for(int f=0;f<100;f++)
	{
		Cord[f].Map		= 0;
		Cord[f].X		= 0;
		Cord[f].Y		= 0;
	}
}

void cDropEvent::LoadFile()
{
	DropEvent.LoadConfigs();

	FILE *file = fopen(CFG_DROPEVT,"r");

	if(file == NULL)
	{
		MessageBoxA(0,"./Data/DropEvent.ini Load Error","CRITICAL ERROR",0);
		ExitProcess(1);
		return;
	}

	char Buff[256];
	int Flag = 0;

	Count[1] = 0;
	Count[2] = 0;
	Count[3] = 0;

	while(!feof(file))
	{
		fgets(Buff,256,file);
		if(func.IsBadFileLine(Buff, Flag))
			continue;
		if(Flag == 1)
		{
			int n[10];
			sscanf(Buff, "%d %d %d %d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4], &n[5], &n[6],&n[7]);

			Item[Count[1]].Type			= n[0];
			Item[Count[1]].Index		= n[1];
			Item[Count[1]].Level		= n[2];
			Item[Count[1]].Durabilidade = n[3];
			Item[Count[1]].Skill		= n[4];
			Item[Count[1]].Luck			= n[5];
			Item[Count[1]].Opt			= n[6];
			Item[Count[1]].Exl			= n[7];
			Count[1]++;
		}

		if(Flag == 2)
		{
			int n[3];
			sscanf(Buff, "%d %d", &n[0], &n[1]);
			Time[Count[2]].Hour  = n[0];
			Time[Count[2]].Min   = n[1];
			Count[2]++;
		}

		if(Flag == 3)
		{
			int n[4];
			sscanf(Buff, "%d %d %d", &n[0], &n[1], &n[2]);
			Cord[Count[3]].Map  = n[0];
			Cord[Count[3]].X	= n[1];
			Cord[Count[3]].Y	= n[2];
			Count[3]++;
		}
	}
	fclose(file);
}

void cDropEvent::StartEvent()
{
	func.AllSendServerMsg("[Drop Event] Iniciado!");
	for(int i=0;i<Count[3];i++)
	{
		int Ran = rand()%Count[1];

		int NewExl = 0;

		int DropItem = ITEMGET(Item[Ran].Type,Item[Ran].Index);

		if(Item[Ran].Exl > 0)
			NewExl = func.GenExcOpt(Item[Ran].Exl);

		int CordMap = Cord[i].Map;
		int CordX	= Cord[i].X;
		int CordY	= Cord[i].Y;

		ItemSerialCreateSend(NULL,CordMap,CordX,CordY,DropItem,Item[Ran].Level,Item[Ran].Durabilidade,Item[Ran].Skill,Item[Ran].Luck,Item[Ran].Opt,NULL,NewExl,0);
		
	}	
}

void cDropEvent::TickTime()
{
	if(!Enable)
	return;

	SYSTEMTIME t;
	GetLocalTime(&t);
	if(t.wSecond == 00)
	{
		for(int i = 0; i < Count[2]; i++)
		{
			if(Time[i].Hour == t.wHour && Time[i].Min == t.wMinute)
			{
				DropEvent.StartEvent();
				break;
			}
		}
	}
}


void EventTimeTick(void)
{
	while(true)
	{
		DropEvent.TickTime();
		Sleep(1000);
	}
}

void EventLoad()
{	
	VipSettings();
	DropEvent.LoadFile();
	Happy.ReadHappyHourEvent();
	Qest_PGW.Q_Load();
	Qest_PGW_ELF.Q_Load();
	Qest_PGW_Boss.Q_Load();
	Qest_PGW_Loot.Q_Load();
	Storm.Load();
}