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

DuelEvent::DuelEvent() : _State(Empty)
{
}

DuelEvent::~DuelEvent()
{
}

bool DuelEvent::Load()
{
	this->_Players[0] = std::vector<DuelPlayer>();
	this->_Players[1] = std::vector<DuelPlayer>();

	this->_Active = GetPrivateProfileInt("MataMata","Active",1,CFG_MATAMATA) > 0 ? true : false;
	this->_MapNumber[0] = GetPrivateProfileInt("MataMata","WaitMap",6,CFG_MATAMATA);
	this->_X[0] = GetPrivateProfileInt("MataMata","WaitX",6,CFG_MATAMATA);
	this->_Y[0] = GetPrivateProfileInt("MataMata","WaitY",6,CFG_MATAMATA);
	this->_MapNumber[1] = GetPrivateProfileInt("MataMata","FightMap",6,CFG_MATAMATA);
	this->_X[1] = GetPrivateProfileInt("MataMata","FightX",6,CFG_MATAMATA);
	this->_Y[1] = GetPrivateProfileInt("MataMata","FightY",6,CFG_MATAMATA);
	GetPrivateProfileString("MataMata","Mensagem","Prêmio: 50 Golds",this->_Notice,60,CFG_MATAMATA);
	GetPrivateProfileString("Querys","UPDATE MATAMATA","",this->_Query,255,CFG_QUERY);
	GetPrivateProfileString("MataMata","PlayerSintax","/irmatamata",this->_Syntax[0],sizeof(this->_Syntax[0]),CFG_MATAMATA);
	GetPrivateProfileString("MataMata","GMSintax","/matamata",this->_Syntax[1],sizeof(this->_Syntax[1]),CFG_MATAMATA);

	return true;
}

bool DuelEvent::Check(LPOBJ lpObj, const char* Text)
{
	if (lpObj->Authority > 1)
	{
		char Buffer[60], * Token = nullptr, * Context = nullptr;

		strcpy_s(Buffer, Text);
		Token = strtok_s(Buffer, " ", &Context);

		if (this->_State == Empty && !_stricmp(Token, this->_Syntax[1]))
		{
			char* Time = strtok_s(nullptr, " ", &Context);
			char* Class = strtok_s(nullptr, " ", &Context);
			
			if (!Time || !Class)
			{
				func.MsgUser(lpObj->m_Index, 1, "Erro de sintaxe! Digite: %s <tempo> <class>", this->_Syntax[1]);
				func.MsgUser(lpObj->m_Index, 1, "Exemplo -> Evento para BKs: %s 3 1", this->_Syntax[1]);
				func.MsgUser(lpObj->m_Index, 1, "ID de classes: ");
				func.MsgUser(lpObj->m_Index, 1, "0: Wizard    | 1: Knight    | 2: Elf");
				func.MsgUser(lpObj->m_Index, 1, "3: Gladiator | 4: Dark Lord | 5: Todos");
				return true;
			}			

			gObjTeleport(lpObj->m_Index, this->_MapNumber[0], this->_X[0], this->_Y[0]);
			this->Start(atoi(Time), atoi(Class));
			return true;
		}
	}
	else
	{
		if (!_stricmp(Text, this->_Syntax[0]))
		{
			if (this->_State == Register)
			{
				if (this->_Type != 5 && lpObj->Class != this->_Type)
				{
					switch (this->_Type)
					{
					case 0:
						func.MsgUser(lpObj->m_Index, 1, "Mata-Mata exclusivo para Dark Wizards e Soul Masters");
						break;
					case 1:
						func.MsgUser(lpObj->m_Index, 1, "Mata-Mata exclusivo para Dark Knights e Blade Knights");
						break;
					case 2:
						func.MsgUser(lpObj->m_Index, 1, "Mata-Mata exclusivo para Elfs e Muse Elfs");
						break;
					case 3:
						func.MsgUser(lpObj->m_Index, 1, "Mata-Mata exclusivo para Magic Gladiators");
						break;
					case 4:
						func.MsgUser(lpObj->m_Index, 1, "Mata-Mata exclusivo para Dark Lords");
						break;
					}

					return true;
				}

				if (this->_Players[0].size() > 0)
				{
					for (auto it = this->_Players[0].cbegin(); it != this->_Players[0].cend(); ++it)
					{
						if (it->lpObj == lpObj)
						{
							func.MsgUser(lpObj->m_Index, 1, "Você já está registrado no evento. Aguarde.");
							return true;
						}
					}
				}

				DuelPlayer Player;

				Player.Die = false;
				Player.lpObj = lpObj;

				this->_Players[0].push_back(Player);

				gObjTeleport(lpObj->m_Index, this->_MapNumber[0], this->_X[0], this->_Y[0]);
				func.MsgUser(lpObj->m_Index, 1, "Você foi registrado no evento. Aguarde...");
			}

			return true;
		}
	}

	return false;
}

void DuelEvent::Start(int Time, int Class)
{
	if (Time == 0)
	{
		Time++;
	}

	if (this->_Players[0].size() > 0)
	{
		this->_Players[0].clear();
	}

	if (this->_Players[1].size() > 0)
	{
		this->_Players[1].clear();
	}

	this->_State = Register;
	this->_Count = (Time * 60) + 1;
	this->_Type = (BYTE)(Class);
}

void DuelEvent::Run()
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
				if (this->_Players[0].size() < 4)
				{					
					func.MakeNoticeMsg(&pNotice[0], 0, "Sem quantidade necessária de jogadores para o evento");
					func.MakeNoticeMsg(&pNotice[1], 0, "Mata-Mata foi cancelado!");

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
					func.MakeNoticeMsg(&pNotice[0], 0, "Inscrições para o Mata-Mata encerradas!");
					func.MakeNoticeMsg(&pNotice[1], 0, "PRIMEIRA RODADA!");

					for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
					{
						if(gObj[i].Connected == 3)
						{
							DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
							DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
						}
					}

					this->_State = Select;
					this->_Count = 3;
				}
			}
			else
			{
				if ((this->_Count % 60) == 0)
				{
					sprintf_s(Buffer, "Mata-Mata começará em %d Minuto(s)", (this->_Count / 60));
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
	case Select:
		{
			if (this->_Count == 0)
			{
				switch (this->_Players[0].size())
				{
				case 0:
					{
						this->_State = NextStage;
						this->_Count = 0;
					}
					break;
				case 1:
					{
                        SelectWO:
						this->_Selected[0] = this->_Players[0].front();

						func.MakeNoticeMsg(&pNotice[0], 0, "[    DUELO    ]");

						sprintf_s(Buffer, "%s venceu de W.O.", this->_Selected[0].lpObj->Name);
						func.MakeNoticeMsg(&pNotice[1], 0, Buffer);

						for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
						{
							if(gObj[i].Connected == 3)
							{
								DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
								DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
							}
						}

						this->_Players[1].push_back(this->_Selected[0]);

						this->_State = NextStage;
						this->_Count = 0;
					}
					break;
				default:
					{
						auto Player1 = this->_Players[0].begin();
						auto Player2 = (--this->_Players[0].end());

						while (true)
						{
							if (Player1->lpObj->m_socket == INVALID_SOCKET || Player1->lpObj->Connected != 3)
							{
								this->_Players[0].erase(Player1);
								Player1 = this->_Players[0].begin();
							}
							else if (Player2->lpObj->m_socket == INVALID_SOCKET || Player2->lpObj->Connected != 3)
							{
								this->_Players[0].erase(Player2);
								Player2 = (--this->_Players[0].end());
							}
							else
							{
								break;
							}
						}

						if (Player1 == Player2)
						{
							goto SelectWO;
						}
						else
						{
							this->_Selected[0] = *Player1;
							this->_Selected[1] = *Player2;

							this->_Selected[0].Die = false;
							this->_Selected[0].Quit = false;
							this->_Selected[0].Score = 0;
							this->_Selected[1].Die = false;
							this->_Selected[1].Quit = false;
							this->_Selected[1].Score = 0;

							func.MakeNoticeMsg(&pNotice[0], 0, "[    DUELO    ]");

							sprintf_s(Buffer, "%s  vs  %s", this->_Selected[0].lpObj->Name, this->_Selected[1].lpObj->Name);
							func.MakeNoticeMsg(&pNotice[1], 0, Buffer);

							for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
							{
								if(gObj[i].Connected == 3)
								{
									DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
									DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
								}
							}

							this->_State = Progress;
							this->_Count = 8;

							gObjTeleport(this->_Selected[0].lpObj->m_Index, this->_MapNumber[1], this->_X[1], this->_Y[1] - 1);
							gObjTeleport(this->_Selected[1].lpObj->m_Index, this->_MapNumber[1], this->_X[1], this->_Y[1] + 1);
							
							this->_Selected[0].lpObj->m_PK_Level = 6;
							this->_Selected[1].lpObj->m_PK_Level = 6;
							GCPkLevelSend(this->_Selected[0].lpObj->m_Index, 6);
							GCPkLevelSend(this->_Selected[1].lpObj->m_Index, 6);

							this->_Players[0].erase(Player2);
							this->_Players[0].erase(Player1);
						}
					}
					break;
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
					func.MsgUser(this->_Selected[0].lpObj->m_Index, 1, "Você poderá atacar em %d segundo(s)", this->_Count);
					func.MsgUser(this->_Selected[1].lpObj->m_Index, 1, "Você poderá atacar em %d segundo(s)", this->_Count);
				}
				break;
			default:
				break;
			}
		}
		break;
	case Died:
		{
			if (this->_Count == 0)
			{
				if (this->_Selected[0].Die && this->_Selected[1].Die)
				{
					func.MsgAllUser(0, "Draw!");

					this->_State = Progress;
					this->_Count = 8;
				}
				else
				{
					BYTE Winner = (this->_Selected[0].Die) ? 1 : 0;
					BYTE Loser = (Winner == 1) ? 0 : 1;

					this->_Selected[Winner].Score++;

					PMSG_NOTICE pNotice2;

					func.MakeNoticeMsg(&pNotice[0], 0, "[    PLACAR    ]");

					sprintf_s(Buffer, "%s  vs  %s", this->_Selected[0].lpObj->Name, this->_Selected[1].lpObj->Name);
					func.MakeNoticeMsg(&pNotice[1], 0, Buffer);
										
					sprintf_s(Buffer, "%d   x   %d", this->_Selected[0].Score, this->_Selected[1].Score);
					func.MakeNoticeMsg(&pNotice2, 0, Buffer);

					for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
					{
						if(gObj[i].Connected == 3)
						{
							DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
							DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
							DataSend(i, (LPBYTE)&pNotice2, pNotice2.h.size);
						}
					}
											
					if (this->_Selected[Winner].Score >= 3)
					{
						func.MsgAllUser(0, "%s venceu!", this->_Selected[Winner].lpObj->Name);

						this->_Players[1].push_back(this->_Selected[Winner]);
						
						this->_Selected[0].lpObj->m_PK_Level = 3;
						this->_Selected[1].lpObj->m_PK_Level = 3;
						GCPkLevelSend(this->_Selected[0].lpObj->m_Index, 3);
						GCPkLevelSend(this->_Selected[1].lpObj->m_Index, 3);

						gObjTeleport(this->_Selected[Winner].lpObj->m_Index, this->_MapNumber[0], this->_X[0], this->_Y[0]);
						gObjTeleport(this->_Selected[Loser].lpObj->m_Index, 0, 125, 125);

						this->_State = Select;
						this->_Count = 0;
					}
					else
					{
						this->_State = Progress;
						this->_Count = 8;
					}
				}

				this->_Selected[0].Die = false;
				this->_Selected[1].Die = false;
			}
		}
		break;
	case NextStage:
		{
			if (this->_Players[0].size() > 0)
			{
				this->_Players[0].clear();
			}

			this->_Players[0] = this->_Players[1];
			
			if (this->_Players[1].size() > 0)
			{
				this->_Players[1].clear();
			}

			switch (this->_Players[0].size())
			{
			case 0:
				{
					this->_State = Empty;
					this->_Count = 0;
				}
				break;
			case 1:
				{
					this->_State = Final;
					this->_Count = 0;
				}
				break;
			default:
				{
					if ((this->_Players[0].size() % 2) == 0)
					{
						func.MsgAllUser(0, "RODADA FINAL!");
					}
					else
					{
						func.MsgAllUser(0, "PRÓXIMA RODADA!");
					}

					this->_State = Select;
					this->_Count = 0;
				}
				break;
			}
		}
		break;
	case WO:
		{
			BYTE Winner = (this->_Selected[0].Quit) ? 1 : 0;
			BYTE Loser = (Winner == 1) ? 0 : 1;
			
			PMSG_NOTICE pNotice2;
			
			func.MakeNoticeMsg(&pNotice[0], 0, "[    PLACAR    ]");

			sprintf_s(Buffer, "%s  vs  %s", this->_Selected[0].lpObj->Name, this->_Selected[1].lpObj->Name);
			func.MakeNoticeMsg(&pNotice[1], 0, Buffer);
										
			sprintf_s(Buffer, "%s venceu por W.O.", this->_Selected[Winner].lpObj->Name);
			func.MakeNoticeMsg(&pNotice2, 0, Buffer);

			for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
			{
				if(gObj[i].Connected == 3)
				{
					DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
					DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
					DataSend(i, (LPBYTE)&pNotice2, pNotice2.h.size);
				}
			}

			this->_Players[1].push_back(this->_Selected[Winner]);

			gObjTeleport(this->_Selected[Winner].lpObj->m_Index, this->_MapNumber[0], this->_X[0], this->_Y[0]);
			gObjTeleport(this->_Selected[Loser].lpObj->m_Index, 0, 125, 125);

			this->_State = Select;
			this->_Count = 0;
		}
		break;
	case Final:
		{
			LPOBJ lpObj = this->_Players[0].front().lpObj;

			Manager.ExecFormat("UPDATE MuOnline.dbo.Character set Matamata = Matamata + 1 Where Name = '%s'", lpObj->Name);
			Manager.ExecFormat(this->_Query, lpObj->AccountID);
			
			sprintf_s(Buffer, "%s é o campeão do Mata-Mata!", lpObj->Name);
			func.MakeNoticeMsg(&pNotice[0], 0, Buffer);										
			func.MakeNoticeMsg(&pNotice[1], 0, this->_Notice);

			for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
			{
				if(gObj[i].Connected == 3)
				{
					DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
					DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
				}
			}

			gObjTeleport(lpObj->m_Index, 0, 125, 125);

			this->_State = Empty;
			this->_Count = 0;
		}
		break;
	}
}

bool DuelEvent::Attack(LPOBJ lpObj, LPOBJ lpTargetObj)
{
	if (this->_State == Progress)
	{
		if (this->_Selected[0].lpObj != lpObj && this->_Selected[1].lpObj != lpObj &&
			this->_Selected[0].lpObj != lpTargetObj && this->_Selected[1].lpObj != lpTargetObj)
		{
			return true;
		}

		if (this->_Selected[0].lpObj == lpObj && this->_Selected[1].lpObj == lpTargetObj ||
			this->_Selected[1].lpObj == lpObj && this->_Selected[0].lpObj == lpTargetObj)
		{
			if (this->_Count == 0)
			{
				return true;
			}

			return false;
		}

		if (this->_Selected[0].lpObj == lpObj && this->_Selected[1].lpObj->Type == MONSTER ||
			this->_Selected[1].lpObj == lpObj && this->_Selected[0].lpObj->Type == MONSTER)
		{
			return true;
		}
		
		return false;
	}

	return true;
}

void DuelEvent::Die(LPOBJ lpObj)
{
	if (this->_State == Progress || this->_State == Died)
	{
		if (this->_Selected[0].lpObj == lpObj)
		{
			this->_Selected[0].Die = true;
		}

		if (this->_Selected[1].lpObj == lpObj)
		{
			this->_Selected[1].Die = true;
		}

		if (this->_State == Progress && (this->_Selected[0].Die || this->_Selected[1].Die))
		{
			this->_State = Died;
			this->_Count = 4;
		}
	}
}

void DuelEvent::Quit(LPOBJ lpObj)
{
	if (this->_State != Empty)
	{
		if (this->_Selected[0].lpObj == lpObj)
		{
			this->_Selected[0].Quit = true;
			this->_State = WO;
		}
		else if (this->_Selected[1].lpObj == lpObj)
		{
			this->_Selected[1].Quit = true;
			this->_State = WO;
		}
		else
		{
			if (this->_Players[0].size() > 0)
			{
				for (auto it = this->_Players[0].cbegin(); it != this->_Players[0].cend(); ++it)
				{
					if (it->lpObj == lpObj)
					{
						this->_Players[0].erase(it);
						break;
					}
				}
			}

			if (this->_Players[1].size() > 0)
			{
				for (auto it = this->_Players[1].cbegin(); it != this->_Players[1].cend(); ++it)
				{
					if (it->lpObj == lpObj)
					{
						this->_Players[1].erase(it);
						break;
					}
				}
			}
		}
	}
}

DuelEvent Duel;