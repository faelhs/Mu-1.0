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

CManager Manager = CManager( );

CManager::CManager( void )
{

}

CManager::~CManager( void )
{

}

bool CManager::Initialize( )
{
	if( !this->InitDatabase ( ) )
	{
		return false;
	}

	return true;
}

bool CManager::InitDatabase()
{
	bool bReturn = false;

	Manager.load();

	if(this->Connect(this->Host , this->Database , this->Usuario , this->Senha) == true )
	{	
		bReturn = true;
	}
	else
	{
		MessageBox(NULL,"Conexão com SQL Server Falhou!\nFavor Verificar o arquivo 'Config.ini","Erro na conexão com SQL Server!",MB_OK | MB_ICONSTOP);
		ExitProcess(0);
		
		this->DiagnosticConn();
	}

	return bReturn;
}

bool CManager::load()
{
	GetPrivateProfileString("MSSQL", "Usuario do SQL Server","sa",this->Usuario,sizeof(this->Usuario),CFG_GAMESERVER);
	GetPrivateProfileString("MSSQL", "Senha do SQL Server","1234",this->Senha,sizeof(this->Senha),CFG_GAMESERVER);
	GetPrivateProfileString("MSSQL", "DataBase do Servidor","MuOnline",this->Database,sizeof(this->Database),CFG_GAMESERVER);
	GetPrivateProfileString("MSSQL", "Host do SQL Server","127.0.0.1",this->Host,sizeof(this->Host),CFG_GAMESERVER);

	return true;
}

void CManager::OnError(const char * szMessage, ...)
{
	LogSystem::CustomLog((char*)szMessage);
}

void CManager::OnMessage(const char * szMessage, ...)
{
	LogSystem::CustomLog((char*)szMessage);
}

void CManager::OnQuery(const char * szMessage, ...)
{
	LogSystem::CustomLog((char*)szMessage);
}

int CManager::VipCount( char* Account )
{
	int Vip;

	this->ExecFormat("SELECT vip FROM MEMB_INFO WHERE memb___id = '%s'" , Account );

	this->Fetch( );

	Vip = this->GetInt("vip");

	this->Clear( );

	return Vip;
}

int CManager::Helper( char* Account )
{
	int helper;

	this->ExecFormat("SELECT helper FROM MEMB_INFO WHERE memb___id = '%s'" , Account );

	this->Fetch( );

	helper = this->GetInt("helper");

	this->Clear( );

	return helper;
}

int CManager::CountResets(char * Character)
{
	int Resets;

	this->ExecFormat("SELECT Resets from Character WHERE Name = '%s'",Character);

	this->Fetch( );

	Resets = this->GetInt("Resets");

	this->Clear( );

	return Resets;
}

int CManager::CountMasters(char * Character)
{
	int MResets;

	this->ExecFormat("SELECT MResets from Character WHERE Name = '%s'",Character);

	this->Fetch( );

	MResets = this->GetInt("MResets");

	this->Clear( );

	return MResets;
}

void CManager::setpremiodia(char* Account, int dia) {
	this->ExecFormat("UPDATE[MuOnline].[dbo].[MEMB_INFO] SET premiodia = %d WHERE memb___id = '%s'", dia, Account);
}

int CManager::getpremiodia(char* Account) {

				int dia;

				this->ExecFormat("SELECT premiodia from [MuOnline].[dbo].[MEMB_INFO] WHERE  memb___id = '%s'", Account);

				this->Fetch();

				dia = this->GetInt("premiodia");

				this->Clear();

				return dia;
	
}

void CManager::setpremiodata(char* Account, char* data) {
	this->ExecFormat("UPDATE[MuOnline].[dbo].[MEMB_INFO] SET ultimopremio = '%s' WHERE memb___id = '%s'", data, Account);
}

char* CManager::getpremiodata(char* Account) {
		char * buff;
		this->ExecFormat("SELECT ultimopremio from [MuOnline].[dbo].[MEMB_INFO] WHERE  memb___id = '%s'", Account);
		this->Fetch();
		this->GetStr("ultimopremio",buff);
		this->Clear();
		return buff;
}

int CManager::Quest_Num(char * Character)
{
	int Quest_Num;

	this->ExecFormat("SELECT Quest_Num from Character WHERE Name = '%s'",Character);

	this->Fetch( );

	Quest_Num = this->GetInt("Quest_Num");

	this->Clear( );

	return Quest_Num;
}
int CManager::Quest_Kill(char * Character)
{
	int Quest_Kill;

	this->ExecFormat("SELECT Quest_Kill from Character WHERE Name = '%s'", Character);

	this->Fetch();

	Quest_Kill = this->GetInt("Quest_Kill");
	if(Quest_Kill < 0){return 0;}
	this->Clear();

	return Quest_Kill;
}

int CManager::Quest_Start(char * Character)
{
	int Quest_Start;

	this->ExecFormat("SELECT Quest_Start from Character WHERE Name = '%s'",Character);

	this->Fetch( );

	Quest_Start = this->GetInt("Quest_Start");

	this->Clear( );

	return Quest_Start; 
}

int CManager::QuestBoss_Start(char * Character)
{
	int Quest_Start;

	this->ExecFormat("SELECT Quest_Boss_Start from Character WHERE Name = '%s'", Character);

	this->Fetch();

	Quest_Start = this->GetInt("Quest_Boss_Start");

	this->Clear();

	return Quest_Start;
}

int CManager::QuestBoss_Num(char * Character)
{
	int Quest_Num;

	this->ExecFormat("SELECT Quest_Boss_Num from Character WHERE Name = '%s'", Character);

	this->Fetch();

	Quest_Num = this->GetInt("Quest_Boss_Num");

	this->Clear();

	return Quest_Num;
}
int CManager::QuestBoss_Kill(char * Character)
{
	int Quest_Kill;

	this->ExecFormat("SELECT Quest_Boss_Kill from Character WHERE Name = '%s'", Character);

	this->Fetch();

	Quest_Kill = this->GetInt("Quest_Boss_Kill");
	if(Quest_Kill < 0){return 0;}
	this->Clear();

	return Quest_Kill;
}

int CManager::QuestLoot_Start(char * Character)
{
	int Quest_Start;

	this->ExecFormat("SELECT Quest_Loot_Start from Character WHERE Name = '%s'", Character);

	this->Fetch();

	Quest_Start = this->GetInt("Quest_Loot_Start");

	this->Clear();

	return Quest_Start;
}
int CManager::QuestLoot_Num(char * Character)
{
	int Quest_Num;

	this->ExecFormat("SELECT Quest_Loot_Num from Character WHERE Name = '%s'", Character);

	this->Fetch();

	Quest_Num = this->GetInt("Quest_Loot_Num");

	this->Clear();

	return Quest_Num;
}
int CManager::QuestLoot_Kill(char * Character)
{
	int Quest_Kill;

	this->ExecFormat("SELECT Quest_Loot_Kill from Character WHERE Name = '%s'", Character);

	this->Fetch();

	Quest_Kill = this->GetInt("Quest_Loot_Kill");
	if(Quest_Kill < 0){return 0;}
	this->Clear();

	return Quest_Kill;
}

int CManager::LevelUpPoint(char * Character)
{
	int LevelUpPoint;

	this->ExecFormat("SELECT LevelUpPoint from Character WHERE Name = '%s'",Character);

	this->Fetch( );

	LevelUpPoint = this->GetInt("LevelUpPoint");

	this->Clear( );

	return LevelUpPoint;
}
/*
bool CManager::ChangeName(char* Account, char* Character, char* NewName){
	char* query = ("SELECT Name from Character WHERE Name = '%s'", Character);
	bool exist = GetStrExec(query,"Name");
	char* name;



}
*/
int CManager::GetJail(char* Char) {
	int jail;
	this->ExecFormat("SELECT jail FROM character WHERE Name = '%s'", Char);
	this->Fetch();
	jail = this->GetInt("jail");
	return jail;
}
int CManager::GetJaula(char* Char) {
	int jail;
	this->ExecFormat("SELECT jaula FROM character WHERE Name = '%s'", Char);
	this->Fetch();
	jail = this->GetInt("jaula");
	return jail;
}
int CManager::GoldCount(char* Account)
{
	int Gold;

	this->ExecFormat("SELECT gold FROM MEMB_INFO WHERE memb___id = '%s'", Account);

	this->Fetch();

	Gold = this->GetInt("gold");

	this->Clear();

	return Gold;
}