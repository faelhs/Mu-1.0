
#define FuckAdder 505
#define ITEM_IN_MAIN(x,y) ((x)*32+(y)+FuckAdder)
#define ITEM(x, y) ((x)*32+(y)+FuckAdder)
#define LoadModel_Offset	 0x005E43D5
#define BMDModelLoad	     0x005E10E0
#define ReturnOffset	     0x005E43EB
#define OpenTexture		     0x005E0CA0
#define mLoadImage ((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x0060F900)
#define pDrawGUI ((bool(__cdecl*)(DWORD dwElementID, float m_fPositionX, float m_fPositionY, float m_fWidth, float m_fHeight, int Arg6, int Arg7, float m_fWidth2, float m_fHeight2, char Arg10, float m_fArg11)) 0x005F2400)
#define UnknownFunc ((bool(__cdecl*)()) 0x005F1330)
#define UnknownFunc2 ((bool(__cdecl*)()) 0x005F1220)
#define UnknownFunc3 ((bool(__cdecl*)(char Arg1)) 0x005F12A0)
#define pHDC *(HDC *)0x056F4048
#define pTextTransparent *(DWORD *)0x00670A90
#define pWinWidth *(GLsizei*)0x0067AC30
#define pWinHeight *(GLsizei*)0x0067AC34
#define pCreateConnect ((bool(__cdecl*)(LPCSTR lpszIp, WORD wPort)) 0x004AF160)
#define pActiveSocket *(SOCKET*)(*(DWORD*)0x66FF04 + 0x0C)
#define pPlayerState *(int*)0x0067AC98
#define pOnLine *(DWORD *)0x56F8498
#define pPartyMemberCount *(DWORD*)0x7830520
#define oUserPreviewStruct		*(int*)0x73C81EC
#define oUserPreviewStruct2		*(int*)0x56F3FF4
#define pShopClose ((bool (__cdecl*)(LPBYTE lpData)) 0x004C7560)
#define pRefreshGame ((bool (__cdecl*)(int m_iPreview)) 0x004DCBB0)
#define pPShopThis1 ((LPVOID(__cdecl*)()) 0x440C60)
#define pPShopThis2	((LPVOID(__thiscall*)(LPVOID This)) 0x8612B0)
#define pPShopSet ((void(__thiscall*)(LPVOID This, int Mode)) 0x440370)
#define pSetMainEvent ((bool (__cdecl*)(DWORD dwEvent)) 0x005F4200)

#define pClearGame_1 *(int *)0x7782360 //-> 0
#define pClearGame_2 *(int *)0x6709F8 // -> 6
#define pClearGame_3 *(int *)0x6B47A0 // -> 0
#define pClearGame_4 *(int *)0x7836414 //-> 0
#define pClearGame_5 *(int *)0x7836418 //-> 0
#define pClearGame_6 *(int *)0x670A54  //-> -1
#define pClearGame_7 *(int *)0x670A58  //-> -1
#define pClearGame_8 *(int *)0x670A5C  //-> -1
#define pClearGame_9 *(int *)0x670A60  //-> -1
#define pClearGame_10 *(int *)0x670A64  //-> -1
#define pClearGame_11 *(BYTE *)0x670A79  //-> -1

#define COLOR_ADR_ALLOW			0x0058B87B
#define COLOR_ADR_RETURN		0x0058B789

void ModelsLoad();
void PatchMainForLoadModels();