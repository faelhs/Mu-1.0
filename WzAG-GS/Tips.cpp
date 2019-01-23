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

CTips::CTips()
{
}

CTips::~CTips()
{
}

bool CTips::Load()
{
	{
		char Buffer[10];
		STips Tips;
		int i = 1;

		this->_Active = GetPrivateProfileInt("Tips","Active",1,CFG_DICAS) > 0 ? true : false;
		this->_Interval = GetPrivateProfileInt("Tips","Interval",20,CFG_DICAS);

		while (true)
		{
			sprintf_s(Buffer, "Tips%02d", i);
			GetPrivateProfileString(Buffer, "Line","",Tips.Line,sizeof(Tips.Line),CFG_DICAS);

			if (Tips.Line[0] == 0)
			{
				break;
			}

			this->_Tips.push_back(Tips);
			++i;
		}
	}

	{
		if (this->_Tips.empty())
		{
			this->_Active = false;
			return true;
		}

		if (this->_Interval <= 0)
		{
			this->_Interval = 1;
		}

		this->_Interval *= 60;

		this->_Timer = this->_Interval;
		this->_Last	 = this->_Tips.begin();
	}

	return true;
}

void CTips::Send()
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

	if (this->_Last == this->_Tips.end())
	{
		this->_Last = this->_Tips.begin();
	}

	BYTE Buffer[75];
	memset(Buffer, 0, sizeof(Buffer));

	Buffer[0]  = 0xC1;
	Buffer[1]  = 0x0E + (BYTE)(strlen(this->_Last->Line));
	Buffer[2]  = 0x0D;
	Buffer[3]  = 0x0A;
	Buffer[4]  = 0x01;
	Buffer[5]  = 0x01;
	Buffer[6]  = 0x00;
	Buffer[7]  = 0x00;
	Buffer[8]  = 0x00;
	Buffer[9]  = 0xFF;
	Buffer[10] = 0x64;
	Buffer[11] = 0xFF;
	Buffer[12] = 0x14;
	strcpy_s((char*)(&Buffer[13]), 60, this->_Last->Line);

	for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if (gObj[i].Connected == 3)
		{
			DataSend(i, Buffer, Buffer[1]);
		}
	}

	++this->_Last;
}

CTips Tips;