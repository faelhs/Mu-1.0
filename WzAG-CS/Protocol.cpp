//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 0.97.40T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "StdAfx.h"

BYTE ProtocolServer(BYTE HeadCode)
{
	switch (HeadCode)
	{
	case 0xD7:
		return 0xD9;
	case 0xD0:
		return 0xDC;
	case 0xD9:
		return 0x15;
	default:
		return HeadCode;
	}

	return HeadCode;
}

void ProtocolCoreEx(BYTE protoNum,LPBYTE aRecv,DWORD aLen,DWORD aIndex,DWORD Encrypt,int Serial)		
{
	if (aRecv[0] == 0xC1 || aRecv[0] == 0xC3)
	{
		aRecv[2] = ProtocolServer(aRecv[2]);
		protoNum = aRecv[2];
	}
	else
	{
		aRecv[3] = ProtocolServer(aRecv[3]);
		protoNum = aRecv[3];
	}

	switch (protoNum)
	{
	case 0x00:
		PChatProcEx((PMSG_CHATDATA*)aRecv, aIndex);
		return;
		break;
	case 0x03:
		{
			Connect.InGame(aIndex);
		}
		break;
	case 0x30:
		{
			if (gObj[aIndex].WarehouseSave == 1)
			{
				CGWarehouseUseEnd(aIndex);
			}
		}
		break;
	case 0x37:
		{
			if (aRecv[0] == 0xC1)
			{
				if (aRecv[1] == 0x04 || aRecv[2] == 0x37)
				{
					if ((gObj[aIndex].TargetNumber != -1) && ( gObj[aIndex].pTransaction == 1 ))
					{
						gObj[aIndex].pTransaction = 0;
						gObjTradeCancel(aIndex);
						return;
					}
				}
			}
		}
		break;
	case 0x55:  
		{
			if ((gObj[aIndex].m_IfState.use == 0 ) || (gObj[aIndex].m_IfState.use == 1 && gObj[aIndex].m_IfState.type == 3 ) || (gObj[aIndex].m_IfState.use == 0 && gObj[aIndex].m_IfState.type == 15))  
			{
				return;
			}
		}
		break;
	case 0xF3:
		{
			PMSG_DEFAULT2 * lpDef = (PMSG_DEFAULT2 *)aRecv;

			switch (lpDef->subcode)
			{
			case 0x01:
				{
					if (InitCreateChar((PMSG_CHARCREATE*)aRecv, aIndex) == true)
					{
						JGCharacterCreateFailSend(aIndex, gObj[aIndex].Name);
						return;
					}
				}
				break;

			}

			switch (aRecv[3])
			{
			case 0x06:
				switch (aRecv[4])
				{
				case 0:
					if ((unsigned short)(gObj[aIndex].Strength + 1) > 32767)
					{
						return;
					}
					break;
				case 1:
					if ((unsigned short)(gObj[aIndex].Dexterity + 1) > 32767)
					{
						return;
					}
					break;
				case 2:
					if ((unsigned short)(gObj[aIndex].Vitality + 1) > 32767)
					{
						return;
					}
					break;
				case 3:
					if ((unsigned short)(gObj[aIndex].Energy + 1) > 32767)
					{
						return;
					}
					break;
				case 4:
					if ((unsigned short)(gObj[aIndex].Leadership + 1) > 32767)
					{
						return;
					}
				}
			}
		}
		break;
	case 0xBC:
		{
			if (gObj[aIndex].m_IfState.use == 1 && gObj[aIndex].m_IfState.type == 1)
			{
				return;
			}
		}
		break;
	}

	ProtocolCore(protoNum,aRecv,aLen,aIndex,Encrypt,Serial);
}

void PChatProcEx(PMSG_CHATDATA * lpChat, short aIndex)
{
	int len = strlen(lpChat->message);

	if (len < 1 || len > 60 - 1)
	{
		return;
	}

	switch (lpChat->message[0])
	{
	case '/':
		{
			Command.ChatRecv(lpChat,aIndex);
		}
		break;
	case '!':
		{
			if (gObj[aIndex].Authority > 1)
			{
				func.MsgAllUser(0,"%s",lpChat->message+1);
				return;
			}
		} 
		break;
	case '#':
		{
			if (gObj[aIndex].Authority > 1)
			{
				func.MsgAllUser(0,"%s: %s",gObj[aIndex].Name,lpChat->message+1);
				return;
			}
		} 
		break;

	}

	BYTE btSend[256];

	memcpy(&btSend[0], lpChat, 13);

	btSend[1] = MultiByteToWideChar(0, 0, (char*)&lpChat->message, lpChat->h.size - 13, (LPWSTR)&btSend[13], sizeof(btSend) - 13) + 13;

	ProtocolCore(btSend[2], btSend, btSend[1], aIndex, 0, -1);
}

void GCChatConvert(int aIndex, BYTE * lpMsg, int size, int x)
{
	BYTE btSend[256];

	memcpy(&btSend[0], &lpMsg[0], x);

	btSend[1] = WideCharToMultiByte(0, 0, (LPCWSTR)&lpMsg[x], size - x, (char*)&btSend[x], sizeof(btSend) - x, 0, 0) + x;

	DataSend(aIndex, btSend, btSend[1]);
}

void DataSendEx(int aIndex, LPBYTE lpMsg, DWORD dwSize)
{
	BYTE HeadCode;

	if (lpMsg[0] == 0xC1 || lpMsg[0] == 0xC3)
	{
		HeadCode = lpMsg[2];
	}
	else
	{
		HeadCode = lpMsg[3];
	}

	switch (HeadCode)
	{
	case 0x00:
		GCChatConvert(aIndex, lpMsg, dwSize, 13);
		return;
	case 0x01:
		GCChatConvert(aIndex, lpMsg, dwSize, 5);
		return;
	case 0x0D:
		GCChatConvert(aIndex, lpMsg, dwSize, 13);
		return;
	}

	DataSend(aIndex, lpMsg, dwSize);
}

void DataSendAll(LPBYTE lpMsg, DWORD dwSize)
{		
	for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if (gObj[i].Connected == 3)
		{
			if (gObj[i].Type == 1)
			{
				DataSend(i,lpMsg,dwSize);
			}
		}
	}
}

void ChatTargetSend(LPOBJ lpObj, char * szChat, int senduser)
{
	int len = strlen(szChat);

	if (len < 1 || len > 60 - 1)
	{
		return;
	}

	PMSG_CHATDATA_NUMBER Result;

	PHeadSetB((LPBYTE)&Result, 0x01, len + 6);

	strcpy(Result.chatmsg, szChat);

	Result.NumberH = HIBYTE(lpObj->m_Index);
	Result.NumberL = LOBYTE(lpObj->m_Index);

	Result.chatmsg[len + 1] = 0;

	DataSend(senduser, (LPBYTE)&Result, Result.h.size);
}