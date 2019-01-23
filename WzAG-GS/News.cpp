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

CNews::CNews()
{
}

CNews::~CNews()
{
}

bool CNews::Load()
{
	{
		char Buffer[10];
		SNews News;
		int i = 1;

		this->_Active = GetPrivateProfileInt("News","Active",1,CFG_NEWS) > 0 ? true : false;
		this->_Interval = GetPrivateProfileInt("News","Interval",30,CFG_NEWS);

		while (true)
		{
			sprintf_s(Buffer, "News%02d", i);
			GetPrivateProfileString(Buffer, "Line_1","",News.Line[0],sizeof(News.Line[0]),CFG_NEWS);

			if (News.Line[0][0] == 0)
			{
				break;
			}

			GetPrivateProfileString(Buffer, "Line_2","",News.Line[1],sizeof(News.Line[1]),CFG_NEWS);
			GetPrivateProfileString(Buffer, "Line_3","",News.Line[2],sizeof(News.Line[2]),CFG_NEWS);

			this->_News.push_back(News);
			++i;
		}
	}

	{
		if (this->_News.empty())
		{
			this->_Active = false;
			return true;
		}
		
		if (this->_Interval <= 0)
		{
			this->_Interval = 1;
		}
		
		this->_Interval *= 60;

		this->_Timer  = this->_Interval;
		this->_Last	  = this->_News.begin();
	}

	return true;
}

void CNews::Send()
{
	if (!this->_Active)
	{
		return;
	}

	if (this->_Timer > 0)
	{
		this->_Timer--;
		return;
	}
	
	this->_Timer = this->_Interval;

	if (this->_Last == this->_News.end())
	{
		this->_Last = this->_News.begin();
	}

	PMSG_NOTICE pNotice[3];

	func.MakeNoticeMsg(&pNotice[0], 0, this->_Last->Line[0]);
	func.MakeNoticeMsg(&pNotice[1], 0, this->_Last->Line[1]);
	func.MakeNoticeMsg(&pNotice[2], 0, this->_Last->Line[2]);

	for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if(gObj[i].Connected == 3)
		{
			DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
			DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
			DataSend(i, (LPBYTE)&pNotice[2], pNotice[2].h.size);
		}
	}

	++this->_Last;
}

CNews News;