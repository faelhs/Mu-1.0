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

PegaEvent::PegaEvent() : _State(Empty)
{
}

PegaEvent::~PegaEvent()
{
}

bool PegaEvent::Load()
{
	this->_Players = std::vector<LPOBJ>();

	this->_Active = GetPrivateProfileInt("PegaPega","Active",1,CFG_PEGAPEGA) > 0 ? true : false;
	this->_MapNumber = GetPrivateProfileInt("PegaPega","MapNumber",9,CFG_PEGAPEGA);
	this->_X = GetPrivateProfileInt("PegaPega","X",80,CFG_PEGAPEGA);
	this->_Y = GetPrivateProfileInt("PegaPega","Y",80,CFG_PEGAPEGA);
	GetPrivateProfileString("PegaPega","3° Lugar","Prêmio: 10 Golds",this->_Notice[0],60,CFG_PEGAPEGA);
	GetPrivateProfileString("PegaPega","2° Lugar","Prêmio: 15 Golds",this->_Notice[1],60,CFG_PEGAPEGA);
	GetPrivateProfileString("PegaPega","1° Lugar","Prêmio: 20 Golds",this->_Notice[2],60,CFG_PEGAPEGA);
	GetPrivateProfileString("Querys","UPDATE PEGAPEGA 3°","",this->_Query[0],255,CFG_QUERY);
	GetPrivateProfileString("Querys","UPDATE PEGAPEGA 2°","",this->_Query[1],255,CFG_QUERY);
	GetPrivateProfileString("Querys","UPDATE PEGAPEGA 1°","",this->_Query[2],255,CFG_QUERY);
	GetPrivateProfileString("PegaPega","PlayerSintax","/irpegapega",this->_Syntax[0],sizeof(this->_Syntax[0]),CFG_PEGAPEGA);
	GetPrivateProfileString("PegaPega","GMSintax","/pegapega",this->_Syntax[1],sizeof(this->_Syntax[1]),CFG_PEGAPEGA);

	return true;
}

bool PegaEvent::Check(LPOBJ lpObj, const char* Text)
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
				if (!this->CheckItem(lpObj))
	            {
		            func.MsgUser(lpObj->m_Index, 1, "Você não pode participar do evento usando pets ou asas.");
					return true;
	            }

				auto it = std::find(this->_Players.cbegin(), this->_Players.cend(), lpObj);

				if (it != this->_Players.cend())
				{
					func.MsgUser(lpObj->m_Index, 1, "Você já está registrado no evento. Aguarde.");
				}
				else
				{
					this->_Players.push_back(lpObj);					

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

void PegaEvent::Start(int Time)
{
	if (Time == 0)
	{
		Time++;
	}

	if (this->_Players.size() > 0)
	{
		this->_Players.clear();
	}

	this->_State = Register;
	this->_Count = (Time * 60) + 1;
}

void PegaEvent::Run()
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
	PMSG_NOTICE pNotice[4];

	switch (this->_State)
	{
	case Register:
		{
			if (this->_Count == 0)
			{
				if (this->_Players.size() < 3)
				{
					for (auto it = this->_Players.cbegin(); it != this->_Players.cend(); ++it)
					{
						if ((*it)->Connected == 3)
						{
							gObjTeleport((*it)->m_Index, 0, 125, 125);

							BYTE SendEvent[4] = { 0xC1, 0x04, 0xFE, 0x0A };
							DataSend((*it)->m_Index, SendEvent, 4);
						}
					}

					func.MakeNoticeMsg(&pNotice[0], 0, "Sem quantidade necessária de jogadores para o evento");
					func.MakeNoticeMsg(&pNotice[1], 0, "Pega-Pega foi cancelado!");

					for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
					{
						if(gObj[i].Connected == 3)
						{
							DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
							DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
						}
					}

					this->_State = Empty;
					this->_Count = 0;
				}
				else
				{
					func.MsgAllUser(0, "Inscrições para o Pega-Pega encerradas!");

					this->_State = Capture;
					this->_Count = 6;
				}
			}
			else
			{
				if ((this->_Count % 60) == 0)
				{
					sprintf_s(Buffer, "Pega-Pega começará em %d Minuto(s)", (this->_Count / 60));
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
	case Capture:
		{
			switch (this->_Count)
			{
			case 5:
			case 4:
			case 3:
			case 2:
			case 1:
				{
					for(auto it = this->_Players.cbegin(); it != this->_Players.cend(); ++it)
					{
						if ((*it)->Connected == 3)
						{
							func.MsgUser((*it)->m_Index, 0, "O GM começará a pegar em %d Segundo(s)", this->_Count);
						}
					}
				}
				break;
			case 0:
				{
					func.MsgAllUser(0,"Corra! O GM começou a capturar!");

					this->_State = Progress;
				}
				break;
			}
		}
		break;
	case Progress:
		break;
	case Final:
		{
			if (this->_Players.size() > 0)
			{
				this->_State = Progress;
			}
			else
			{
				Manager.ExecFormat(this->_Query[0], this->_Account[0]);
				Manager.ExecFormat(this->_Query[1], this->_Account[1]);
				Manager.ExecFormat(this->_Query[2], this->_Account[2]);

				func.MakeNoticeMsg(&pNotice[0], 0, "[   PEGA-PEGA   ]");
					
				sprintf_s(Buffer, "1º Lugar: %s / %s", this->_Name[2], this->_Notice[2]);
				func.MakeNoticeMsg(&pNotice[1], 0, Buffer);

				sprintf_s(Buffer, "2º Lugar: %s / %s", this->_Name[1], this->_Notice[1]);
				func.MakeNoticeMsg(&pNotice[2], 0, Buffer);
				
				sprintf_s(Buffer, "3º Lugar: %s / %s", this->_Name[0], this->_Notice[0]);
				func.MakeNoticeMsg(&pNotice[3], 0, Buffer);

				for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
				{
					if(gObj[i].Connected == 3)
					{
						DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
						DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
						DataSend(i, (LPBYTE)&pNotice[2], pNotice[2].h.size);
						DataSend(i, (LPBYTE)&pNotice[3], pNotice[3].h.size);
					}
				}

				Manager.ExecFormat("UPDATE MuOnline.dbo.Character set Pegapega = Pegapega + 1 Where Name = '%s'", this->_Name[2]);

				this->_State = Empty;
				this->_Count = 0;
			}
		}
		break;
	}
}

bool PegaEvent::CheckItem(LPOBJ lpObj)
{
	if (lpObj->pInventory[7].IsItem())
	{
		return false;
	}

	if (lpObj->pInventory[8].IsItem())
	{
		return false;
	}

	return true;
}

bool PegaEvent::Attack(LPOBJ lpObj, LPOBJ lpTargetObj)
{
	if (this->_State == Progress)
	{
		if (lpObj->Authority > 1)
		{
			if (this->_Players.size() > 0)
			{
				auto it = std::find(this->_Players.cbegin(), this->_Players.cend(), lpTargetObj);

				if (it != this->_Players.cend())
				{
					func.MsgAllUser(0, "%s - capturado!", lpTargetObj->Name);

					switch (this->_Players.size())
					{
					case 3:
						{
							strcpy_s(this->_Name[0], lpTargetObj->Name);
							strcpy_s(this->_Account[0], lpTargetObj->AccountID);
						}
						break;
					case 2:
						{
							strcpy_s(this->_Name[1], lpTargetObj->Name);
							strcpy_s(this->_Account[1], lpTargetObj->AccountID);							
							
							gObjTeleport((*it)->m_Index, 0, 125, 125);

							BYTE SendEvent[4] = { 0xC1, 0x04, 0xFE, 0x0A };
							DataSend((*it)->m_Index, SendEvent, 4);

							this->_Players.erase(it);
							
							it = this->_Players.cbegin();

							strcpy_s(this->_Name[2], (*it)->Name);
							strcpy_s(this->_Account[2], (*it)->AccountID);
						}
						break;
					case 1:
						{
							strcpy_s(this->_Name[2], lpTargetObj->Name);
							strcpy_s(this->_Account[2], lpTargetObj->AccountID);
						}
						break;
					}
					
					gObjTeleport(lpTargetObj->m_Index, 0, 125, 125);

					BYTE SendEvent[4] = { 0xC1, 0x04, 0xFE, 0x0A };
					DataSend(lpTargetObj->m_Index, SendEvent, 4);

					this->_Players.erase(it);

					this->_State = Final;
				}
			}
		}
		else
		{
			if (this->_Players.size() > 0)
			{
				auto it = std::find(this->_Players.cbegin(), this->_Players.cend(), lpObj);

				if (it != this->_Players.cend())
				{
					return false;
				}

				it = std::find(this->_Players.cbegin(), this->_Players.cend(), lpTargetObj);

				if (it != this->_Players.cend())
				{
					return false;
				}
			}
		}
	}

	return true;
}

void PegaEvent::Quit(LPOBJ lpObj)
{
	if (this->_State != Empty)
	{
		if (this->_Players.size() > 0)
		{	
			auto it = std::find(this->_Players.cbegin(), this->_Players.cend(), lpObj);

			if (it != this->_Players.cend())
			{
				if (this->_State == Progress)
				{
					switch (this->_Players.size())
					{
					case 3:
						{
							func.MsgAllUser(0, "%s - perda de conexão!", lpObj->Name);
							strcpy_s(this->_Name[0], lpObj->Name);
							strcpy_s(this->_Account[0], lpObj->AccountID);
						}
						break;
					case 2:
						{
							func.MsgAllUser(0, "%s - perda de conexão!", lpObj->Name);
							strcpy_s(this->_Name[1], lpObj->Name);
							strcpy_s(this->_Account[1], lpObj->AccountID);
							
							(*it)->MapNumber = 0;
							(*it)->X = 125;
							(*it)->Y = 125;

							this->_Players.erase(it);
							
							it = this->_Players.cbegin();

							strcpy_s(this->_Name[2], (*it)->Name);
							strcpy_s(this->_Account[2], (*it)->AccountID);
						}
						break;
					case 1:
						{
							func.MsgAllUser(0, "%s - perda de conexão!", lpObj->Name);
							strcpy_s(this->_Name[2], lpObj->Name);
							strcpy_s(this->_Account[2], lpObj->AccountID);
						}
						break;
					}
					
					(*it)->MapNumber = 0;
					(*it)->X = 125;
					(*it)->Y = 125;

					this->_Players.erase(it);
				
					this->_State = Final;
				}
				else
				{
					this->_Players.erase(it);
				}
			}
		}
	}
}

bool PegaEvent::Equip(LPOBJ lpObj, BYTE SourcePos, BYTE TargetPos)
{
	if (this->_State != Empty)
	{
		if (this->_Players.size() > 0)
		{	
			auto it = std::find(this->_Players.cbegin(), this->_Players.cend(), lpObj);

			if (it != this->_Players.cend())
			{
				if (TargetPos == 7)
				{
					func.MsgUser(lpObj->m_Index, 1, "Você não pode equipar asas participando do evento.");
					return false;
				}

				if (TargetPos == 8)
				{
					func.MsgUser(lpObj->m_Index, 1, "Você não pode equipar pets participando do evento.");
					return false;
				}
			}
		}
	}

	return true;
}

PegaEvent Pega;