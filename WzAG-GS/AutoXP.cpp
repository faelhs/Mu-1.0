#include "StdAfx.h"

int AutoExp__Enabled;
int AutoExp__Time;
int AutoExp__BaseExp;
int AutoExp__Secs;
int AutoExp__LevelUpPoints;
int AutoExp__MaxLevel;
int AutoExp__MaxReset;
int AutoExp__Free;

void AutoExp()
{
	AutoExp__Enabled       = GetPrivateProfileIntA("AutoExp", "Ativar",				1,		CFG_AUTOXP);
	AutoExp__Free		   = GetPrivateProfileIntA("AutoExp", "Tipo de Conta",		0,		CFG_AUTOXP);
	AutoExp__BaseExp       = GetPrivateProfileIntA("AutoExp", "ExpAdicional",		8000,	CFG_AUTOXP);
	AutoExp__Secs          = GetPrivateProfileIntA("AutoExp", "TempoCheck",			10,		CFG_AUTOXP);
	AutoExp__MaxLevel      = GetPrivateProfileIntA("AutoExp", "MaxLevel",			50,		CFG_AUTOXP);
	AutoExp__MaxReset      = GetPrivateProfileIntA("AutoExp", "MaxReset",			10,		CFG_AUTOXP);
	AutoExp__LevelUpPoints = GetPrivateProfileIntA("AutoExp", "LevelUpPoint",		5,		CFG_AUTOXP);

	if(AutoExp__Enabled == 1)
	{
		AutoExp__Time	= (1000 * AutoExp__Secs);
		_beginthread( AutoExp__Trigger, 0, NULL  );
	}
}

int NextLevelUpPoints( DWORD PlayerID)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(PlayerID);

	int LevelUpPoint = 0;

	if (lpObj->Level < AutoExp__MaxLevel)         
	{
		switch(lpObj->Class)
		{
		case 3:
			{
				LevelUpPoint = 7;	
			}break;
		case 4:
			{
				LevelUpPoint = 7;  

			}break;

		}

	}
	return LevelUpPoint;
}

void AutoExp__Trigger(void * lpParam)
{
	BYTE Packet[10] = {0xC3,0x09,0x16,0xFF,0xFF,0x00,0x00,0x00,0x00,0xFF};

	while(true)
	{		
		Sleep(AutoExp__Time);

		for(int PlayerID=OBJECT_MIN;PlayerID<OBJECT_MAX;PlayerID++)
		{
			int AddExp = 0;

			if(func.IsOnGame(PlayerID))
			{

				OBJECTSTRUCT *pObj = (OBJECTSTRUCT*)OBJECT_POINTER(PlayerID);

				int pLevel = pObj->Level;
				int VipIndex = Manager.VipCount(pObj->AccountID);
				int Resets = Manager.CountResets(pObj->Name);

				if(VipIndex >= AutoExp__Free)
				{
					if(Resets < AutoExp__MaxReset)
					{
						if (pLevel < AutoExp__MaxLevel) 
						{

							AddExp = (int)(AutoExp__BaseExp * pLevel) ;

							if(AddExp > 0x0FFFF)
								AddExp = 65534;

							if(AddExp > 0)
							{
								pObj->Experience += AddExp;
								Packet[5]=HIBYTE(AddExp);
								Packet[6]=LOBYTE(AddExp);
								DataSend(PlayerID,(PBYTE)Packet,Packet[1]);
								if(pObj->Experience >= pObj->NextExp )
								{
									if(AutoExp__LevelUpPoints < 0)
									{
										pObj->LevelUpPoint += NextLevelUpPoints(PlayerID);
									}
									else
									{
										pObj->LevelUpPoint += AutoExp__LevelUpPoints;
									}
									pObj->Level +=1;
									GCLevelUpMsgSend(PlayerID,pObj->Level,pObj->LevelUpPoint,(WORD)(pObj->MaxLife+pObj->AddLife),(WORD)(pObj->MaxMana+pObj->AddMana),(WORD)(pObj->MaxBP+pObj->AddBP));
								}
							}
						}
					}
				}
			}
		}
	}
}