#include "stdafx.h"
#include "OffTradeProtocol.h"
#include "tchar.h"
#include "OffTrade.h"


cOffProtocol OffProtocol; 

//----------------------------------------------------------------------------------------------------------------------------------
cOffProtocol::cOffProtocol(void)
{
	//----------------------------------------
}
//----------------------------------------------------------------------------------------------------------------------------------
cOffProtocol::~cOffProtocol(void)
{
	//----------------------------------------
}
//----------------------------------------------------------------------------------------------------------------------------------
void cOffProtocol::Init(void)
{
	//-----------------------------------------
} 
//----------------------------------------------------------------------------------------------------------------------------------
void cOffProtocol::ICSPJoinIdPassRequest(LPBYTE aRecv,int aIndex)
{
    char id[11];
    int isOff = 0;
 
    PMSG_IDPASS *lpMsg = (PMSG_IDPASS *)aRecv;
	OBJECTSTRUCT *gObjt = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	
	id[10]=0;
	memcpy(id, lpMsg->Id, sizeof(lpMsg->Id));
	BuxConvert(id, MAX_ACCOUNT_LEN);

	 for(int i=8000;i<9000;i++)
    {   

        OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);
        if(gObj->Connected == 3 && AddTab[i].OfflineTrade == true)
        {
			//gObj_GetLogin(aIndex,Login);
			if(!strcmp(gObj->AccountID, gObjt->AccountID))
            {
				AddTab[i].OfflineTrade = false;
				CloseClient(i);
				gObjDel(i);
                isOff = 1;
				//this not tested
				AddTab[aIndex].aRecv = aRecv;
				AddTab[aIndex].OfflineTrade = false;
				break;
            }
        }
    } 
    if(isOff)
        _beginthread( cOffProtocol::Login_Timer, 0, (void*)aIndex  );
	else
        CSPJoinIdPassRequest(lpMsg,aIndex);
}
//----------------------------------------------------------------------------------------------------------------------------------
void cOffProtocol::Login_Timer(void * lpParam)
{
	int aIndex = (int)lpParam;
    Sleep(3000);
    PMSG_IDPASS *lpMsg = (PMSG_IDPASS *)AddTab[aIndex].aRecv;
    CSPJoinIdPassRequest(lpMsg,aIndex);
    _endthread();

}
