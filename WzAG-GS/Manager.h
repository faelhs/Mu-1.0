//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 99.60T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#pragma once

#include "Database.h"

class CManager : public CDataBase
{
public:
	CManager( void );
	~CManager( void );
	bool Initialize();
	bool InitDatabase( );
	bool load();
	void OnMessage(const char * szMessage, ...);
	void OnError(const char * szMessage, ...);
	void OnQuery(const char * szMessage, ...);

	int VipCount(char* Account);
	bool ChangeName(char* Account, char* Character, char* NewName);
	int GoldCount(char* Account);
	int Helper( char* Account );
	int CountResets(char * Character);
	int CountMasters(char * Character);
	int Quest_Start(char * Character);
	int Quest_Num(char * Character);
	int Quest_Kill(char * Character);
	int LevelUpPoint(char * Character);

	int QuestBoss_Start(char * Character);
	int QuestBoss_Num(char * Character);
	int QuestBoss_Kill(char * Character);

	int QuestLoot_Start(char * Character);
	int QuestLoot_Num(char * Character);
	int QuestLoot_Kill(char * Character);

	int getpremiodia(char* Account);
	void setpremiodia(char* Account, int dia);
	char * getpremiodata(char* Account);
	void setpremiodata(char* Account, char* data);

	int GetJail(char* Char);
	int GetJaula(char* Char);
private:
	char Host[50];
	char Database[50];
	char Usuario[50];
	char Senha[50];
};

extern CManager Manager;