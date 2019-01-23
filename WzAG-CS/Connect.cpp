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

void ConnectServer::PlayerConnect(int aIndex)
{
	Custom[aIndex].VipIndex = Manager.VipCount(gObj[aIndex].AccountID);
	Custom[aIndex].Resets = Manager.CountResets(gObj[aIndex].Name);
	Custom[aIndex].Masters = Manager.CountMasters(gObj[aIndex].Name);

	GetPrivateProfileString("Server","Noticia de conexão","Bem vindo(a) %s",this->Notice[0],160,CFG_GAMESERVER);
	func.MsgUser(aIndex,0,this->Notice[0],gObj[aIndex].Name);
}

void ConnectServer::GameMasterConnect(int aIndex)
{
	GetPrivateProfileString("Server","Noticia de conexão de GM/ADM","%s Online",this->Notice[1],160,CFG_GAMESERVER);

	if(gObj[aIndex].AuthorityCode > 1)
	{
		func.MsgAllUser(0,this->Notice[1],gObj[aIndex].Name);
	}
}

void ConnectServer::InGame(int aIndex)
{
	PlayerConnect(aIndex);
	GameMasterConnect(aIndex);
}

ConnectServer Connect;