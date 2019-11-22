#include "StdAfx.h"

CReconnectSystem * gReconnectSystem;

static unsigned char bBuxCode[3] = { 0xFC, 0xCF, 0xAB };	// Xox Key for some interesting things :)

void BuxConvertDev(char* buf, int size)
{
	for (int n = 0; n < size; n++)
	{
		buf[n] ^= bBuxCode[n % 3];		// Nice trick from WebZen
	}
}

bool CReconnectSystem::PacketCheckTime2(LPOBJ lpObj) 
{
	if((GetTickCount() - lpObj->m_PacketCheckTime) < 300)
	{
		return false;
	}
	// ----
	lpObj->m_PacketCheckTime = GetTickCount();
	// ----
	return true;
}

bool CReconnectSystem::_send_login(int UserIndex, CONNECTEX_LOGIN * Data)
{
	BuxConvertDev(Data->AccountID, MAX_ACCOUNT_LEN);
	BuxConvertDev(Data->Password, MAX_ACCOUNT_LEN);
	// ----
	char id[11] = {NULL};
	id[10] = 0;
	memcpy(id, Data->AccountID, sizeof(Data->AccountID));
	// ----
	BuxConvertDev(id, MAX_ACCOUNT_LEN);
	// ----
	_GJPUserClose(id);
	// ----
	LPOBJ lpObj = CUser::getObject(UserIndex);
	// ----
	if(lpObj->Connected != PLAYER_CONNECTED)
	{
		_CloseClient(UserIndex);
		// ----
		return false;
	}
	// ----
	if(lpObj->LoginMsgSnd != FALSE)
	{
		return false;
	}
	// ----
	if(lpObj->Connected >= PLAYER_LOGGED)
	{
		return false;
	}
	// ----
	SDHP_IDPASS spMsg = {NULL};
	// ----
	spMsg.h.Set((LPBYTE)&spMsg, 0x01, sizeof(spMsg));
	spMsg.Number = UserIndex;
	memcpy(spMsg.Id, Data->AccountID, sizeof(spMsg.Id));
	memcpy(spMsg.Pass, Data->Password, sizeof(spMsg.Pass));
	strcpy(spMsg.IpAddress, lpObj->Ip_addr);
	lpObj->CheckTick = Data->TickCount;
	lpObj->CheckTick2 = GetTickCount();
	lpObj->ConnectCheckTime = GetTickCount();
	lpObj->CheckSpeedHack = true;
	lpObj->LoginMsgSnd = 1;
	lpObj->LoginMsgCount = 1;
	lpObj->AccountID[MAX_ACCOUNT_LEN] = 0;
	lpObj->Name[MAX_ACCOUNT_LEN] = 0;
	memcpy(lpObj->AccountID, id, MAX_ACCOUNT_LEN);
	memcpy(lpObj->Name, Data->Name, MAX_ACCOUNT_LEN);
	lpObj->m_cAccountItemBlock = 0;
	sObj[lpObj->m_Index].bIsReconnect = true;
	// ----
	//_join_send(_JoinServerThis(), (LPBYTE)&spMsg, spMsg.h.size);
	// ----
	_asm
	{
		MOV ECX, DWORD PTR[spMsg.h.size];
		AND ECX, 0xFF;
		PUSH ECX;
		// ----
		LEA EDX, [spMsg];
		PUSH EDX;
		MOV ECX, 0x0A5FEEC0;
		MOV ESI, 0x004027BB;
		CALL ESI;
	}
	// ----
	_LogAddTD("[Reconnect]Join Send : (%d)%s", UserIndex, lpObj->AccountID);
	// ----
	//lpObj->DieRegen = 1;
	lpObj->m_bMapSvrMoveReq = false;
	lpObj->m_sPrevMapSvrCode = -1; 
	lpObj->m_sDestMapNumber = -1;
	lpObj->m_btDestX = 0;
	lpObj->m_btDestY = 0;
	// ----
	return true;
}

bool CReconnectSystem::_send_game(int UserIndex)
{
	LPOBJ lpObj = CUser::getObject(UserIndex);
	// ----
	sObj[lpObj->m_Index].bIsReconnect = false;
	// ----
	_DataServerGetCharListRequest(UserIndex);
	// ----
	if(!PacketCheckTime2(&gObj[UserIndex]))
	{
		return false;
	}
	// ----
	if(!_gObjIsAccountConnect(UserIndex, lpObj->AccountID))
	{
		return false;
	}
	// ----
	if(lpObj->Connected == PLAYER_PLAYING)
	{
		return false;
	}
	// ----
	char _name[MAX_ACCOUNT_LEN + 1];
	// ----
	SDHP_DBCHARINFOREQUEST pCRequest = {NULL};
	// ----
	pCRequest.h.Set((LPBYTE)&pCRequest, 0x06, sizeof(pCRequest));
	memset(_name, 0, MAX_ACCOUNT_LEN);
	memcpy(_name, lpObj->Name, MAX_ACCOUNT_LEN);
	BuxConvertDev(_name, MAX_ACCOUNT_LEN);
	memcpy(pCRequest.Name, _name, MAX_ACCOUNT_LEN);
	strcpy(pCRequest.AccountID, lpObj->AccountID);
	pCRequest.Number = UserIndex;
	// ----
	_asm
	{
		MOV EAX, DWORD PTR[pCRequest.h.size];
		AND EAX, 0x0FF;
		PUSH EAX;
		LEA ECX, [pCRequest];
		PUSH ECX;
		MOV ECX, 0x6421D0;
		MOV ESI, 0x004015FA;
		CALL ESI;
	}
	// ----
	//gObjPlayerKiller(lpObj,lpObj);
	func.Refresh(UserIndex);
	return true;
}

bool CReconnectSystem::_send_close(int UserIndex)
{
	CONNECTEX_CLOSE pRequest = {NULL};
	// ----
	pRequest.h.Set((LPBYTE)&pRequest, 0xFB, 0xC, sizeof(CONNECTEX_CLOSE));
	// ----
	return _CoreSend(UserIndex, (LPBYTE)&pRequest, pRequest.h.size);
}

bool CReconnectSystem::JoinResult(BYTE btResult, int aIndex)
{
	PMSG_RESULT pResult = {NULL};
	// ----
	pResult.h.Set((LPBYTE)&pResult, 0xF1, 0x01, sizeof(pResult));
	// ----
	pResult.result = btResult;
	// ----
	return _CoreSend(aIndex, (LPBYTE)&pResult, pResult.h.size);
}