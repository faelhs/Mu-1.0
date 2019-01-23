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

bool Commands::Load()
{
	this->_Active[0] = GetPrivateProfileInt("Comando Post","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Level[0] = GetPrivateProfileInt("Comando Post","NeedLevel",1,CFG_COMMAND);
	this->_Zen[0] = GetPrivateProfileInt("Comando Post","NeedZen",1000,CFG_COMMAND);
	this->_Vip = GetPrivateProfileInt("Comando Post","NeedVip",1,CFG_COMMAND);
	this->_Delay = GetPrivateProfileInt("Comando Post","TimeDelay",10,CFG_COMMAND);	
	this->_Color = GetPrivateProfileInt("Comando Post","TypeColor",1,CFG_COMMAND);
	GetPrivateProfileString("Comando Post","Formato","[POST]:%s",this->_Formato,50,CFG_COMMAND);
	GetPrivateProfileString("Comando Post","Sintax","/post",this->_Syntax[0],25,CFG_COMMAND);

	this->_Active[1] = GetPrivateProfileInt("Comando Adicionar","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Level[1] = GetPrivateProfileInt("Comando Adicionar","NeedLevel",1,CFG_COMMAND);
	this->_Zen[1] = GetPrivateProfileInt("Comando Adicionar","NeedZen",1000,CFG_COMMAND);
	GetPrivateProfileString("Comando Adicionar","Sintax 1","/for",this->_Syntax[1],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Adicionar","Sintax 2","/agi",this->_Syntax[2],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Adicionar","Sintax 3","/vit",this->_Syntax[3],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Adicionar","Sintax 4","/ene",this->_Syntax[4],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Adicionar","Sintax 5","/cmd",this->_Syntax[5],25,CFG_COMMAND);

	this->_Active[2] = GetPrivateProfileInt("Comando Readicionar","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Level[2] = GetPrivateProfileInt("Comando Readicionar","NeedLevel",350,CFG_COMMAND);
	this->_Zen[2] = GetPrivateProfileInt("Comando Readicionar","NeedZen",10000,CFG_COMMAND);
	GetPrivateProfileString("Comando Readicionar","Sintax","/readd",this->_Syntax[6],25,CFG_COMMAND);

	this->_Active[3] = GetPrivateProfileInt("Comando Clear","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Level[3] = GetPrivateProfileInt("Comando Clear","NeedLevel",1,CFG_COMMAND);
	this->_Zen[3] = GetPrivateProfileInt("Comando Clear","NeedZen",1000,CFG_COMMAND);
	GetPrivateProfileString("Comando Clear","Sintax","/limparpk",this->_Syntax[7],25,CFG_COMMAND);

	this->_Active[4] = GetPrivateProfileInt("Comando Baú","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Level[4] = GetPrivateProfileInt("Comando Baú","NeedLevel",1,CFG_COMMAND);
	this->_Zen[4] = GetPrivateProfileInt("Comando Baú","NeedZen",10000,CFG_COMMAND);
	this->_Ware[0] = GetPrivateProfileInt("Comando Baú","LimitFree",3,CFG_COMMAND);
	this->_Ware[1] = GetPrivateProfileInt("Comando Baú","LimitVip1",5,CFG_COMMAND);
	this->_Ware[2] = GetPrivateProfileInt("Comando Baú","LimitVip2",7,CFG_COMMAND);
	this->_Ware[3] = GetPrivateProfileInt("Comando Baú","LimitVip3",9,CFG_COMMAND);
	GetPrivateProfileString("Comando Baú","Sintax","/bau",this->_Syntax[8],25,CFG_COMMAND);

	this->_Active[5] = GetPrivateProfileInt("Comando Zen","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Zen[5] = GetPrivateProfileInt("Comando Zen","Quantity",2000000000,CFG_COMMAND);
	GetPrivateProfileString("Comando Zen","Sintax","/zen",this->_Syntax[9],25,CFG_COMMAND);

	this->_Active[6] = GetPrivateProfileInt("Comando Online","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Zen[6] = GetPrivateProfileInt("Comando Online","NeedZen",10000,CFG_COMMAND);
	GetPrivateProfileString("Comando Online","Sintax","/online",this->_Syntax[10],25,CFG_COMMAND);

	this->_Active[7] = GetPrivateProfileInt("Comando Premiar","Active",1,CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Premiar","Sintax","/premiar",this->_Syntax[11],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Premiar","Mensagem","",this->_Notice,60,CFG_COMMAND);
	GetPrivateProfileString("Querys","UPDATE PREMIAR","",this->_Query,255,CFG_QUERY);

	this->_Active[8] = GetPrivateProfileInt("Comando Moveall","Active",1,CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Moveall","Sintax","/moveall",this->_Syntax[12],25,CFG_COMMAND);

	this->_Active[9] = GetPrivateProfileInt("Comando Skin","Active",1,CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Skin","Sintax","/skin",this->_Syntax[13],25,CFG_COMMAND);

	this->_Active[10] = GetPrivateProfileInt("Comando Gmove","Active",1,CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Gmove","Sintax","/gmove",this->_Syntax[14],25,CFG_COMMAND);

	return true;
}

bool Commands::ChatRecv(PMSG_CHATDATA * lpMsg, int aIndex)
{
	if (!_stricmp((const char*)(lpMsg->message),"/info"))
	{
		func.MsgUser(aIndex,0,"Conta: %s :: ViP: %d :: Level %d",gObj[aIndex].AccountID,Custom[aIndex].VipIndex,gObj[aIndex].Level);
		func.MsgUser(aIndex,0,"Nome: %s :: Level Points: %d",gObj[aIndex].Name,gObj[aIndex].LevelUpPoint);
		func.MsgUser(aIndex,0,"Resets: %d :: Master Resets: %d",Custom[aIndex].Resets,Custom[aIndex].Masters);

		return true;
	}

	if (!_stricmp((const char*)(lpMsg->message),"/move Valley"))
	{
		if (gObj[aIndex].Level >= 200) 
        { 
           gObjTeleport(aIndex,30,31,40); 
        } 
		
		return true;
	}

	if (!_stricmp((const char*)(lpMsg->message),this->_Syntax[6]))
	{
		ReAdicionar(aIndex);
		return true;
	}

	if (!_stricmp((const char*)(lpMsg->message),this->_Syntax[7]))
	{
		Clear(aIndex);
		return true;
	}

	if (!_stricmp((const char*)(lpMsg->message),this->_Syntax[9]))
	{
		Money(aIndex);
		return true;
	}

	if(!_stricmp((const char*)(lpMsg->message),this->_Syntax[10]))
	{
		Online(aIndex);
		return true;
	}

	if (!_stricmp((const char*)(lpMsg->message),Reset._Syntax))
	{
		Reset.InitExec(aIndex);
		return true;
	}

	if (!_stricmp((const char*)(lpMsg->message),MReset._Syntax))
	{
		MReset.InitExec(aIndex);
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[0],strlen(this->_Syntax[0])))
	{
		Post(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[0])));
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[1],strlen(this->_Syntax[1])))
	{
		Adicionar(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[1])),1);
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[2],strlen(this->_Syntax[2])))
	{
		Adicionar(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[2])),2);
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[3],strlen(this->_Syntax[3])))
	{
		Adicionar(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[3])),3);
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[4],strlen(this->_Syntax[4])))
	{
		Adicionar(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[4])),4);
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[5],strlen(this->_Syntax[5])))
	{
		Adicionar(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[5])),5);
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[8],strlen(this->_Syntax[8])))
	{
		Ware(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[8])));
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[11],strlen(this->_Syntax[11])))
	{
		Premiar(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[11])));
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[12],strlen(this->_Syntax[12])))
	{
		MoveAll(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[12])));
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[13],strlen(this->_Syntax[13])))
	{
		Skin(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[13])));
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[14],strlen(this->_Syntax[14])))
	{
		Move(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[14])));
		return true;
	}

	return false;
}

void Commands::Post(int aIndex, char* msg)
{
	DWORD Time = (GetTickCount() - Custom[aIndex].PostDelay) / 1000;

	if (!this->_Active[0])
	{
		func.MsgUser(aIndex,1,"Comando desabilitado.");
		return;  
	}
	else if (gObj[aIndex].Level < this->_Level[0])
	{
		func.MsgUser(aIndex,1,"Você não possui level %d", this->_Level[0]);
		return;
	}
	else if (gObj[aIndex].Money < this->_Zen[0])
	{
		func.MsgUser(aIndex,1,"Você não possui zen %d", this->_Zen[0]);
		return;
	}
	else if (this->_Vip == 1)
	{
		if(Custom[aIndex].VipIndex < 1)
		{
			func.MsgUser(aIndex,1,"Exclusivo apenas para vip's.");
			return;
		}
	}
	if (this->_Delay > Time)
	{
		func.MsgUser(aIndex,1,"Tente usar em [%d] segundos.",(this->_Delay - Time));
		return;
	}

	char Buffer[60];

	sprintf(Buffer, this->_Formato, msg);

	if (this->_Color == Azul)
	{
		func.BlueChatSend(gObj[aIndex].Name,Buffer,aIndex);
	}
	if(this->_Color == Verde)
	{
		func.GreenChatSend(gObj[aIndex].Name,Buffer,aIndex);
	}
	if(this->_Color == Amarelo)
	{
		func.YellowChatSend(gObj[aIndex].Name,Buffer,aIndex);
	}

	Custom[aIndex].PostDelay = GetTickCount();

	GCMoneySend(aIndex,gObj[aIndex].Money -= this->_Zen[0]);
}

void Commands::Adicionar(int aIndex, LPCSTR Buffer, int Status)
{
	int Pontos = atoi(Buffer);

	if (!this->_Active[1])
	{
		func.MsgUser(aIndex,1,"Comando desabilitado.");
		return;  
	}
	else if (Pontos <= 0)
	{
		return;
	}
	else if (gObj[aIndex].Level < this->_Level[1])
	{
		func.MsgUser(aIndex,1,"Você não possui level %d", this->_Level[1]);
		return;
	}
	else if(gObj[aIndex].Money < this->_Zen[1])
	{
		func.MsgUser(aIndex,1,"Você não possui zen %d", this->_Zen[1]);
		return;
	}
	else if (Pontos > gObj[aIndex].LevelUpPoint)
	{
		func.MsgUser(aIndex,1,"Faltam %d pontos.", (Pontos - gObj[aIndex].LevelUpPoint));
		return;
	}
	else if (32700 <= Pontos)
	{
		func.MsgUser(aIndex,1,"Maximo de pontos a adicionar 32700");
		return;
	}
	else
	{
		if (Status == 1)
		{
			if ((gObj[aIndex].Strength + Pontos) >= 32767)
			{
				func.MsgUser(aIndex,1,"Limite de pontos permitidos 32767");
				return;
			}
			else
			{
				gObj[aIndex].Strength += Pontos;

				func.MsgUser(aIndex,1,"Adicionado %d pontos em Força",Pontos);
			}
		}
		else if (Status == 2)
		{
			if ((gObj[aIndex].Dexterity + Pontos) >= 32767)
			{
				func.MsgUser(aIndex,1,"Limite de pontos permitidos 32767");
				return;
			}
			else
			{
				gObj[aIndex].Dexterity += Pontos;

				func.MsgUser(aIndex,1,"Adicionado %d pontos em Agilidade",Pontos);
			}
		}
		else if (Status == 3)
		{
			if ((gObj[aIndex].Vitality + Pontos) >= 32767)
			{
				func.MsgUser(aIndex,1,"Limite de pontos permitidos 32767");
				return;
			}
			else
			{
				gObj[aIndex].Vitality += Pontos;

				func.MsgUser(aIndex,1,"Adicionado %d pontos em Vitalidade",Pontos);
			}
		}
		else if (Status == 4)
		{
			if ((gObj[aIndex].Energy + Pontos) >= 32767)
			{
				func.MsgUser(aIndex,1,"Limite de pontos permitidos 32767");
				return;
			}
			else
			{
				gObj[aIndex].Energy += Pontos;

				func.MsgUser(aIndex,1,"Adicionado %d pontos em Energia",Pontos);
			}
		}
		else if (Status == 5)
		{
			if (gObj[aIndex].Class != 4)
			{
				func.MsgUser(aIndex,1,"Comando disponível para Dark Lord!");
			    return;
			}
			else if ((gObj[aIndex].Leadership + Pontos) >= 32767)
			{
				func.MsgUser(aIndex,1,"Limite de pontos permitidos 32767");
				return;
			}
			else
			{
				gObj[aIndex].Leadership += Pontos;

				func.MsgUser(aIndex,1,"Adicionado %d pontos em Comando",Pontos);
			}
		}

		GCMoneySend(aIndex,gObj[aIndex].Money -= this->_Zen[1]);
		gObj[aIndex].LevelUpPoint -= Pontos;
		gObj[aIndex].MaxLife = gObj[aIndex].VitalityToLife * gObj[aIndex].Vitality;
		gObj[aIndex].Life = gObj[aIndex].MaxLife;
		gObj[aIndex].AddLife = 0;
		gObj[aIndex].MaxMana = gObj[aIndex].EnergyToMana * gObj[aIndex].Energy;
		gObj[aIndex].Mana = gObj[aIndex].MaxMana;
		gObj[aIndex].AddMana = 0;
		gObjSetBP(gObj[aIndex].m_Index);
		gObj[aIndex].BP = gObj[aIndex].MaxBP;
		gObj[aIndex].AddBP = 0;
		func.UpdateCharacter(aIndex, false);
	}
}

void Commands::ReAdicionar(int aIndex)
{
	if (!this->_Active[2])
	{
		func.MsgUser(aIndex,1,"Comando desabilitado.");
		return;  
	}
	else if (gObj[aIndex].Level < this->_Level[2])
	{
		func.MsgUser(aIndex,1,"Você não possui level %d", this->_Level[2]);
		return; 	
	}
	else if(gObj[aIndex].Money < this->_Zen[2])
	{
		func.MsgUser(aIndex,1,"Você não possui zen %d", this->_Zen[2]);
		return;
	}

	UINT uiPoints;

	uiPoints = ((gObj[aIndex].Strength + gObj[aIndex].Dexterity) + (gObj[aIndex].Vitality + gObj[aIndex].Energy)) - 100;
	uiPoints += gObj[aIndex].LevelUpPoint;

	if(gObj[aIndex].Class == 4)
	{
		uiPoints += (gObj[aIndex].Leadership) - 100;
	}

	GCMoneySend(aIndex,gObj[aIndex].Money -= this->_Zen[2]);
	gObj[aIndex].LevelUpPoint		= uiPoints >= 4294967290 ? 4294967290 : uiPoints;
	gObj[aIndex].Experience         = 0;
	gObj[aIndex].Strength			= 25;
	gObj[aIndex].Dexterity			= 25;
	gObj[aIndex].Vitality			= 25;
	gObj[aIndex].Energy			    = 25;
	gObj[aIndex].Leadership         = 25;
	gObj[aIndex].MaxLife = gObj[aIndex].VitalityToLife * gObj[aIndex].Vitality;
	gObj[aIndex].Life = gObj[aIndex].MaxLife;
	gObj[aIndex].AddLife = 0;
	gObj[aIndex].MaxMana = gObj[aIndex].EnergyToMana * gObj[aIndex].Energy;
	gObj[aIndex].Mana = gObj[aIndex].MaxMana;
	gObj[aIndex].AddMana = 0;
	gObjSetBP(gObj[aIndex].m_Index);
	gObj[aIndex].BP = gObj[aIndex].MaxBP;
	gObj[aIndex].AddBP = 0;
	func.UpdateCharacter(aIndex, false);
	func.MsgUser(aIndex,1,"%d disponiveis para distribuição.",gObj[aIndex].LevelUpPoint);
}

void Commands::Clear(int aIndex)
{ 
	if (!this->_Active[3])
	{
		func.MsgUser(aIndex,1,"Comando desabilitado.");
		return;  
	}
	else if (gObj[aIndex].Level < this->_Level[3])
	{
		func.MsgUser(aIndex,1,"Você não possui level %d",this->_Level[3]);
		return;
	}
	else if (gObj[aIndex].Money < this->_Zen[3])
	{
		func.MsgUser(aIndex,1,"Você não possui zen %d",this->_Zen[3]);
		return;
	}
	else if (gObj[aIndex].m_PK_Level < 5)
	{		
		func.MsgUser(aIndex,1,"Você não está PK");
		return;
	}

	gObj[aIndex].m_PK_Level = 3;
	gObj[aIndex].m_PK_Count = 0;
	gObj[aIndex].m_PK_Time  = 0;
	GCMoneySend(aIndex,gObj[aIndex].Money -= this->_Zen[3]);
	GCPkLevelSend(aIndex,gObj[aIndex].m_PK_Level);

	func.MsgUser(aIndex,1,"Você foi Perdoado com sucesso.");
}

void Commands::Ware(int aIndex, LPCSTR Buffer)
{  
	this->_Number = atoi(Buffer);

	DWORD Time = (GetTickCount() - Custom[aIndex].WareDelay) / 1000;

	if (!this->_Active[4])
	{
		func.MsgUser(aIndex,1,"Comando desabilitado.");
		return;  
	}
	else if (gObj[aIndex].Level < this->_Level[4])
	{
		func.MsgUser(aIndex,1,"Você não possui level %d",this->_Level[4]);
		return;
	}
	else if (gObj[aIndex].Money < this->_Zen[4])
	{
		func.MsgUser(aIndex,1,"Você não possui zen %d",this->_Zen[4]);
		return;
	}
	else if (Time < 10)
	{
		func.MsgUser(aIndex,1,"Tente trocar em [%d] segundos.",(10 - Time));
		return;
	}
	else if (gObj[aIndex].m_IfState.use == 1 || gObj[aIndex].pTransaction == 1 || gObj[aIndex].WarehouseSave == 1)
	{
		func.MsgUser(aIndex,1,"Você não pode trocar de baú agora.");
		return;
	}

	switch (Custom[aIndex].VipIndex)
	{
	case 0:
		{
			if (this->_Number > this->_Ware[0])
			{
				func.MsgUser(aIndex,1,"O seu limite de baús é %d",this->_Ware[0]);
				return;
			}
		}
		break; 
	case 1:
		{
			if (this->_Number > this->_Ware[1])
			{
				func.MsgUser(aIndex,1,"O seu limite de baús é %d",this->_Ware[1]);
				return;
			}
		}
		break; 
	case 2:
		{
			if (this->_Number > this->_Ware[2])
			{
				func.MsgUser(aIndex,1,"O seu limite de baús é %d",this->_Ware[2]);
				return;
			}
		}
		break; 
	case 3:
		{
			if (this->_Number > this->_Ware[3])
			{
				func.MsgUser(aIndex,1,"O seu limite de baús é %d",this->_Ware[3]);
				return;
			}
		}
		break; 
	}

	Manager.ExecFormat("EXEC MuOnline.dbo.MUDAR_BAU '%s', %d",gObj[aIndex].AccountID,this->_Number);

	func.MsgUser(aIndex,1,"Troca efetuada com sucesso, baú %d",this->_Number);

	GCMoneySend(aIndex,gObj[aIndex].Money -= this->_Zen[4]);
}

void Commands::Money(int aIndex)
{
	if (!this->_Active[5])
	{
		func.MsgUser(aIndex,1,"Comando desabilitado.");
		return;  
	}

	func.MsgUser(aIndex,1,"Zen adicionado com sucesso.");

	gObj[aIndex].Money = this->_Zen[5];
	GCMoneySend(aIndex,gObj[aIndex].Money);
}

void Commands::Online(int aIndex)
{
	if (!this->_Active[6])
	{
		func.MsgUser(aIndex,1,"Comando desabilitado.");
		return;  
	}
	else if (gObj[aIndex].Money < this->_Zen[6])
	{
		func.MsgUser(aIndex,1,"Você não possui zen %d",this->_Zen[6]);
		return;
	}

	DWORD PlayerCount = 0;
	DWORD GM = 0;

	for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if (gObj[i].Authority == 1 && gObj[i].Connected == 3)
		{
			PlayerCount++;
		}
		else if (gObj[i].Authority > 1 && gObj[i].Connected == 3)
		{
			GM++;
		}
	}

	func.MsgUser(aIndex,1,"Players onlines: %d :: GM'S onlines: %d :: Total: %d",PlayerCount,GM,(PlayerCount+GM));

	GCMoneySend(aIndex,gObj[aIndex].Money -= this->_Zen[6]);
}

void Commands::Premiar(int aIndex, char* msg)
{
	if (!this->_Active[7])
	{
		func.MsgUser(aIndex,1,"Comando desabilitado.");
		return;  
	}
	else if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex,1,"Exclusivo apenas para gamemaster.");
		return;
	}
	else if (strlen(msg) < 1)
	{
		return;
	}

	int num = {-1};
	char tName[11];
	sscanf(msg,"%s %d",tName,&num);
	int tIndex = func.Get_PlayerIndex(tName);

	if (gObj[tIndex].Connected < 3)
	{
		func.MsgUser(aIndex,1,"O Personagem não se encontra.");
		return;
	}

	Manager.ExecFormat(this->_Query,num,gObj[tIndex].AccountID);

	func.MsgAllUser(0,this->_Notice,tName,num);
}

void Commands::MoveAll(int aIndex, char* msg)
{
	if (!this->_Active[8])
	{
		func.MsgUser(aIndex,1,"Comando desabilitado.");
		return;  
	}
	else if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex,1,"Exclusivo apenas para gamemaster.");
		return;
	}
	else if (strlen(msg) < 1)
	{
		return;
	}

	int Mapa,X,Y;
	sscanf(msg,"%d %d %d",&Mapa, &X, &Y);

	for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if(gObj[i].AuthorityCode == 0)
		{
			gObjTeleport(i,Mapa,X,Y);
		}
	}

	func.MsgUser(aIndex,1,"Movidos com sucesso.");
}

void Commands::Skin(int aIndex, char* msg)
{
	if (!this->_Active[9])
	{
		func.MsgUser(aIndex,1,"Comando desabilitado.");
		return;  
	}
	else if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex,1,"Exclusivo apenas para gamemaster.");
		return;
	}
	else if (strlen(msg) < 1)
	{
		return;
	}

	int skinnum = {-1};
	char tName[11];
	sscanf(msg,"%s %d",tName,&skinnum);
	int tIndex = func.Get_PlayerIndex(tName);

	if (gObj[tIndex].Connected < 3)
	{
		func.MsgUser(aIndex,1,"Personagem não se encontra.");
		return;
	}

	gObj[tIndex].m_Change = skinnum;
	gObjViewportListProtocolCreate(&gObj[tIndex]);

	if (tIndex == aIndex)
	{
		func.MsgUser(aIndex,1,"%s Mudou de skin.",gObj[aIndex].Name);
	}
	else
	{
		func.MsgUser(aIndex,1,"Skin adicionada.");
		func.MsgUser(tIndex,1,"Skin adicionada por %s",gObj[aIndex].Name);
	}
}

void Commands::Move(int aIndex, char* msg)
{
	if (!this->_Active[10])
	{
		func.MsgUser(aIndex,1,"Comando desabilitado.");
		return;  
	}
	else if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex,1,"Exclusivo apenas para gamemaster.");
		return;
	}
	else if (strlen(msg) < 1)
	{
		return;
	}

	int Mapa,X,Y;
	char tName[11];
	sscanf(msg,"%s %d %d %d",&tName,&Mapa,&X,&Y);
	int tIndex = func.Get_PlayerIndex(tName);

	if (gObj[tIndex].Connected < 3)
	{
		func.MsgUser(aIndex,1,"Personagem não se encontra.");
		return;
	}
	else
	{
		gObjTeleport(gObj[tIndex].m_Index,Mapa,X,Y);
	}
}

Commands Command;