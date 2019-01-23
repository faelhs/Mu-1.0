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

SobreEvent::SobreEvent() : _State(Empty)
{
}

SobreEvent::~SobreEvent()
{
}

bool SobreEvent::Load()
{
	this->_PlayerCount = 0;

	this->_Active = GetPrivateProfileInt("Survivor","Active",1,CFG_SURVIVOR) > 0 ? true : false;
	this->_MapNumber = GetPrivateProfileInt("Survivor","MapNumber",1,CFG_SURVIVOR);
	this->_X = GetPrivateProfileInt("Survivor","X",152,CFG_SURVIVOR);
	this->_Y = GetPrivateProfileInt("Survivor","Y",190,CFG_SURVIVOR);
	GetPrivateProfileString("Survivor","Mensagem","Prêmio: 50 Golds",this->_Notice,60,CFG_SURVIVOR);
	GetPrivateProfileString("Querys","UPDATE SURVIVOR","",this->_Query,255,CFG_QUERY);
	GetPrivateProfileString("Survivor","PlayerSintax","/irsurvivor",this->_Syntax[0],sizeof(this->_Syntax[0]),CFG_SURVIVOR);
	GetPrivateProfileString("Survivor","GMSintax","/survivor",this->_Syntax[1],sizeof(this->_Syntax[1]),CFG_SURVIVOR);

	return true;
}

bool SobreEvent::Check(LPOBJ lpObj, const char* Text)
{
	if (lpObj->Authority > 1)
	{
		char Buffer[60], * Token = nullptr, * Context = nullptr;

		strcpy_s(Buffer, Text);
		Token = strtok_s(Buffer, " ", &Context);

		if (this->_State == Empty && !_stricmp(Token, this->_Syntax[1]))
		{
			char* Time = strtok_s(nullptr, " ", &Context);
			
			if (!Time)
			{
				func.MsgUser(lpObj->m_Index, 1, "Erro de sintaxe! Digite: %s <tempo>",this->_Syntax[1]);
				func.MsgUser(lpObj->m_Index, 1, "Exemplo -> %s 3",this->_Syntax[1]);
				return true;
			}			
			
			gObjTeleport(lpObj->m_Index, this->_MapNumber, this->_X, this->_Y);
			this->Start(atoi(Time));
			return true;
		}
	}
	else
	{
		if (!_stricmp(Text, this->_Syntax[0]))
		{
			if (this->_State == Register)
			{
				if (Player[lpObj->m_Index].EventStatus == 1)
				{
					func.MsgUser(lpObj->m_Index, 1, "Você já está registrado no evento. Aguarde.");
					return true;
				}
				else
				{	
					Player[lpObj->m_Index].EventStatus = 1;
		            Player[lpObj->m_Index].SurvivorBlock = true;
		            this->_PlayerCount++;
					lpObj->m_PK_Level = 6;
                    GCPkLevelSend(lpObj->m_Index,lpObj->m_PK_Level);
					gObjTeleport(lpObj->m_Index, this->_MapNumber, this->_X, this->_Y);
					func.MsgUser(lpObj->m_Index, 1, "Você foi registrado no evento. Aguarde...");

					BYTE SendEvent[4] = { 0xC1, 0x04, 0xFE, 0x09 };
					DataSend(lpObj->m_Index, SendEvent, 4);
				}
			}

			return true;
		}
	}

	return false;
}

void SobreEvent::Start(int Time)
{
	if (Time == 0)
	{
		Time++;
	}

	this->_PlayerCount = 0;

	this->_State = Register;
	this->_Count = (Time * 60) + 1;
}

void SobreEvent::Run()
{
	if (this->_State == Empty)
	{
		return;
	}

	if (this->_Count > 0)
	{
		this->_Count--;
	}
	
	char Buffer[60];
	PMSG_NOTICE pNotice[2];

	switch (this->_State)
	{
	case Register:
		{
			if (this->_Count == 0)
			{
				if (this->_PlayerCount < 2) // 3
				{
					func.MakeNoticeMsg(&pNotice[0], 0, "Sem quantidade necessária de jogadores para o evento");
					func.MakeNoticeMsg(&pNotice[1], 0, "Survivor foi cancelado!");

					for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
					{
						if(gObj[i].Connected == 3)
						{
							DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
							DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
						}
					}

					for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
			        {
				         Player[i].SurvivorBlock = false;

						 BYTE SendEvent[4] = { 0xC1, 0x04, 0xFE, 0x0A };
						 DataSend(i, SendEvent, 4);
			        }

					this->_State = Empty;
					this->_Count = 0;
					this->_PlayerCount = 0;
				}
				else
				{
					func.MsgAllUser(0, "Inscrições para o Survivor encerradas!");

					this->_State = Progress;
					this->_Count = 6;
				}
			}
			else
			{
				if ((this->_Count % 60) == 0)
				{
					sprintf_s(Buffer, "Survivor começará em %d Minuto(s)", (this->_Count / 60));
					func.MakeNoticeMsg(&pNotice[0], 0, Buffer);
					
					sprintf_s(Buffer, "Para participar, utilize o comando: %s", this->_Syntax[0]);
					func.MakeNoticeMsg(&pNotice[1], 0, Buffer);

					for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
					{
						if(gObj[i].Connected == 3)
						{
							DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
							DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
						}
					}
				}
			}
		}
		break;
		case Progress:
		{
			switch (this->_Count)
			{
			case 5:
			case 4:
			case 3:
			case 2:
			case 1:
				{
					func.MsgAllUser(0,"O Survivor começará em %d Segundo(s)", this->_Count);
				}
				break;
			case 0:
				{
					func.MsgAllUser(0,"O Survivor começou!");
					this->_State = Fight;
					this->_Count = 0;
				}
				break;
			}
		}
		break;
	case Fight:
		{
			for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
			{
				if (Player[i].EventStatus == 1)
				{
				    Player[i].SurvivorBlock = false;
				}
			}
		}
		break;
	case Final:
		{
			this->_State = Empty;
			this->_Count = 0;
			this->_PlayerCount = 0;
		}
		break;
	}
}

bool SobreEvent::Attack(LPOBJ lpObj, LPOBJ lpTargetObj)
{
	if (lpObj->Type == PLAYER && lpTargetObj->Type == PLAYER)
	{
		if (Player[lpObj->m_Index].SurvivorBlock == true)
		{
			return false;
		}
	}

	return true;
}

void SobreEvent::Die(LPOBJ lpObj, LPOBJ lpTargetObj)
{
	if(lpObj->Type == PLAYER && this->_MapNumber && Player[lpObj->m_Index].EventStatus == 1)
	{
		this->_PlayerCount--;
		func.MsgAllUser(0, "%s Eliminado(a) do Survivor!", lpObj->Name);
		Player[lpObj->m_Index].EventStatus = 0;
		lpObj->m_PK_Level = 3;
		GCPkLevelSend(lpObj->m_Index,lpObj->m_PK_Level);

		BYTE SendEvent[4] = { 0xC1, 0x04, 0xFE, 0x0A };
		DataSend(lpObj->m_Index, SendEvent, 4);

		if(this->_PlayerCount == 1)
		{
			char Buffer[60];
			PMSG_NOTICE pNotice[2];

			sprintf_s(Buffer, "%s Venceu o Survivor!", lpTargetObj->Name);
			func.MakeNoticeMsg(&pNotice[0], 0, Buffer);

			sprintf_s(Buffer, this->_Notice, lpTargetObj->Name);
			func.MakeNoticeMsg(&pNotice[1], 0, Buffer);

			for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
			{
				if(gObj[i].Connected == 3)
				{
					DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
					DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
				}
			}

			Manager.ExecFormat("UPDATE MuOnline.dbo.Character set Survivor = Survivor + 1 Where Name = '%s'", lpTargetObj->Name);
			Manager.ExecFormat(this->_Query,lpTargetObj->AccountID);
			Player[lpTargetObj->m_Index].EventStatus = 0;
			lpTargetObj->m_PK_Level = 3;
			GCPkLevelSend(lpTargetObj->m_Index,lpTargetObj->m_PK_Level);
			Player[lpTargetObj->m_Index].RequestMove = true;

			BYTE SendEvent[4] = { 0xC1, 0x04, 0xFE, 0x0A };
		    DataSend(lpTargetObj->m_Index, SendEvent, 4);

			this->_State = Final;
			this->_Count = 0;
		}
	}
}

void SobreEvent::PlayerOut(LPOBJ lpObj)
{
	if(Player[lpObj->m_Index].RequestMove == true)
	{
		if(lpObj->Live == TRUE)
		{
			gObjTeleport(lpObj->m_Index,0,125,125);
			Player[lpObj->m_Index].RequestMove = false;
		}
	}
}

void SobreEvent::Quit(LPOBJ lpObj)
{
	if(Player[lpObj->m_Index].EventStatus == 1)
	{
		Player[lpObj->m_Index].EventStatus = 0;
		Player[lpObj->m_Index].SurvivorBlock = false;
		this->_PlayerCount--;
		lpObj->m_PK_Level = 3;
		GCPkLevelSend(lpObj->m_Index,lpObj->m_PK_Level);
	}
}

SobreEvent Sobre;