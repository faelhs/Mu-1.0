#include "StdAfx.h"
// ---
CLottery gLottery;
// ---
void CLottery::Load()
{
	memset(&this->m_Data, 0, sizeof(this->m_Data));
	// ---
	Tokenizer          token;
	TokenizerGroup     Class;
	TokenizerSection   Section;
	// ---
	token.ParseFile(std::string(CFG_SORTEIO), Class);
	// ---	
	if(Class.GetSection(0, Section))
	{	
		this->m_Data.Enabled		=	Section.Rows[0].GetInt(0);
		this->m_Data.Time			=	Section.Rows[0].GetInt(1);
		this->m_Data.iType			=	Section.Rows[0].GetInt(2);
	}
	// ---
	if(Class.GetSection(1, Section))
	{	
		this->m_Data.Gold			=	Section.Rows[0].GetInt(0);
		this->m_Data.Cash			=	Section.Rows[0].GetInt(1);
		this->m_Data.LevelUpPoints	=	Section.Rows[0].GetInt(2);
		this->m_Data.Level			=	Section.Rows[0].GetInt(3);
		this->m_Data.Zen			=	Section.Rows[0].GetInt(4);
	}
	// ---
	_beginthread(&this->TimeTick, 0, 0);
}
// ---
void CLottery::TimeTick(LPVOID lpTime)
{
	while(gLottery.m_Data.Enabled)
	{
		
		Sleep(gLottery.m_Data.Time *  60 * 60 * 1000 - (60*  1000*  5));
		func.MsgAllUser(0,"O sorteio acontecerá em 5 Minuto(s)");
		Sleep(60000);  
		func.MsgAllUser(0,"O sorteio acontecerá em 4 Minuto(s)");
		Sleep(60000); 
		func.MsgAllUser(0,"O sorteio acontecerá em 3 Minuto(s)");
		Sleep(60000); 
		func.MsgAllUser(0,"O sorteio acontecerá em 2 Minuto(s)");
		Sleep(60000); 
		func.MsgAllUser(0,"O sorteio acontecerá em 1 Minuto(s)");
		Sleep(60000);
		// ---
		gLottery.Init();
	}
	// ---
	_endthread();
}
// ---
void CLottery::Init()
{
	int iTarget = 0;
	// ---
	for(int i = OBJ_STARTUSERINDEX; i < OBJECT_MAX; i++)
	{
		if(gObj[i].Connected >= 3)
		{
			this->m_Data.pRecv[iTarget++] = i;
		}
	}
	// ---
	if(iTarget > 0)
	{
		int Index = rand() % iTarget;
		// ---
		int Target = this->m_Data.pRecv[Index];
		// ---
		switch(this->m_Data.iType)
		{
		case 1:
			{
				Manager.ExecFormat("UPDATE MuOnline.dbo.MEMB_INFO SET Cash = Cash + %d WHERE memb___id = '%s'", this->m_Data.Cash, gObj[Target].AccountID);
				// ---
				func.MsgAllUser(0, "%s Foi Sorteado Com %d Cash(s).", gObj[Target].Name, this->m_Data.Cash);
				// ---
				func.MsgUser(gObj[Target].m_Index, 1, "Você Foi Sorteado Com %d Cash(s).", this->m_Data.Cash);
			}
			break;
		case 2:
			{
				Manager.ExecFormat("UPDATE MuOnline.dbo.MEMB_INFO SET Gold = Gold + %d WHERE memb___id = '%s'", this->m_Data.Gold, gObj[Target].AccountID);
				// ---
				func.MsgAllUser(0, "%s Foi Sorteado Com %d Gold(s).", gObj[Target].Name, this->m_Data.Gold);
				// ---
				func.MsgUser(gObj[Target].m_Index, 1, "Você Foi Sorteado Com %d Gold(s).", this->m_Data.Gold);
			}
			break;
		case 3:
			{
				gObj[Target].LevelUpPoint += this->m_Data.LevelUpPoints;
				func.UpdateCharacter(Target, false);
				func.LevelUPSend(Target);
				// ---
				func.MsgAllUser(0, "%s Foi Sorteado Com %d UpPoint(s).", gObj[Target].Name, this->m_Data.LevelUpPoints);
				// ---
				func.MsgUser(gObj[Target].m_Index, 1, "Você Foi Sorteado Com %d UpPoint(s).", this->m_Data.LevelUpPoints);
			}
			break;
		case 4:
			{
				gObj[Target].Level += this->m_Data.Level;
				func.UpdateCharacter(Target, false);
				func.LevelUPSend(Target);
				// ---
				func.MsgAllUser(0, "%s Foi Sorteado Com %d Level(s).", gObj[Target].Name, this->m_Data.LevelUpPoints);
				// ---
				func.MsgUser(gObj[Target].m_Index, 1, "Você Foi Sorteado Com %d Level(s).", this->m_Data.LevelUpPoints);
			}
			break;
		case 5:
			{
				gObj[Target].Money += this->m_Data.Zen;
				// ---
				func.MsgAllUser(0, "%s Foi Sorteado Com %d Zen.", gObj[Target].Name, this->m_Data.LevelUpPoints);
				// ---
				func.MsgUser(gObj[Target].m_Index, 1, "Você Foi Sorteado Com %d Zen.", this->m_Data.LevelUpPoints);
			}
			break;
		}
	}
}