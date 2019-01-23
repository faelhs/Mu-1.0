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
	GetPrivateProfileString("MSSQL", "Senha do SQL Server","fireteam",this->Senha,sizeof(this->Senha),CFG_GAMESERVER);
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