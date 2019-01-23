#include "stdafx.h"
#include "OffTrade.h"
#include "WinError.h"
#include "WinSock2.h"
#include "WinBase.h"

//------------------------------------------------------------------------------------------------------
CRITICAL_SECTION criti;
OffTrade OfflineTrade; 
//------------------------------------------------------------------------------------------------------
OffTrade::OffTrade(void)
{
	//-- CONSTRUCTOR --
}

//------------------------------------------------------------------------------------------------------
void OffTrade::InitOfflineTrade()
{
	func.HookThis((DWORD)&CGPShopAnsClose_Ex,CGPShopAnsClose_Hook);
	func.HookThis((DWORD)&CloseClient2Ex,CloseClient2_Hook);
	func.HookThis((DWORD)&CloseClient2Ex,CloseClient2_Hook);
	func.HookThis((DWORD)&ResponErrorCloseClientEx,ResponErrorCloseClient_Hook);
	
}
//------------------------------------------------------------------------------------------------------
OffTrade::~OffTrade(void)
{
	//-- DESTRUCTOR ----
}

void ResponErrorCloseClientEx(int Index)
{
	if ( Index < 0 || Index > 8999 )
	{ 
		return;
	}

	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index);
	if ( gObj->Connected == PLAYER_EMPTY )
	{ 
		return;
	}

	if(AddTab[Index].OfflineTrade == true)
		return;

	ResponErrorCloseClient(Index);
}

//------------------------------------------------------------------------------------------------------
void OffTrade::CreateOfflineStore(int aIndex)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	AddTab[aIndex].OfflineTrade=true;
	 
	CloseClient(aIndex);
}
//------------------------------------------------------------------------------------------------------
void CGPShopAnsClose_Ex(int aIndex, BYTE btResult)
{
	// Function calling when Personal store is closing. 
	// Also it is calling when Personal store become empty.
	CGPShopAnsClose(aIndex,btResult);
	
	if(AddTab[aIndex].OfflineTrade == true)
	{
		AddTab[aIndex].OfflineTrade = false;
		gObjDel_Ex(aIndex);
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex); 
	}
}
//------------------------------------------------------------------------------------------------------
void CloseClient2Ex(_PER_SOCKET_CONTEXT_2 * lpPerSocketContext, int result)
{
	// Very easy function hooking. Just disable auto log-off of Disconnected Characters ;)
	int index = -1;
	index = lpPerSocketContext->nIndex ;	
	//---
	if ( index >= 8000 && index < 9000 )
	{		
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(index); 
		if ( gObj->m_socket  != INVALID_SOCKET )
		{
			if ( closesocket(gObj->m_socket) == -1 )
				if ( WSAGetLastError() != WSAENOTSOCK )
					return;
			gObj->m_socket = INVALID_SOCKET; 
		}
		gObjDel_Ex(index); 
	}
}
//------------------------------------------------------------------------------------------------------
short gObjDel_Ex(int aIndex)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	 
	if(AddTab[aIndex].OfflineTrade == true)
		return 1;
	 
	if(aIndex < 8000 || AddTab[aIndex].CloseSetCheck == true)
		return gObjDel(aIndex); 

	return gObjDel(aIndex);
}
//------------------------------------------------------------------------------------------------------
