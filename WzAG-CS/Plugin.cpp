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

void Load()
{
	DWORD OldProtect;
	if(VirtualProtect(LPVOID(0x401000),3543191,PAGE_EXECUTE_READWRITE,&OldProtect))
	{
		//ReadyLicense();
		Fixes();
		Manager.Initialize();
		Customs();
		func.HookThis((DWORD)&ProtocolCoreEx,0x004036D4);
		func.HookThis((DWORD)&DataSendEx,0x004052F9);
		Command.Load();
		Reset.Load();
		MReset.Load();
		func.HookThis((DWORD)&Flood::Connection,0x0040141F);
		func.HookThis((DWORD)&Functions::HookgObjAttack,0x004028E2);
		func.HookThis((DWORD)&gObjSetCharacterEx,0x0040573B);
		func.HookThis((DWORD)&ChatTargetSend,0x00402A68);
		ExcellentShop.Load();
		func.HookThis((DWORD)&Functions::gObjInterfaceTimeCheckEx,0x00402518);
        func.HookThis((DWORD)&Functions::gObjSecondProcEx,0x004051C3);
		func.HookThis((DWORD)&Functions::gObjPlayerKillerEx,0x004027FC);
		func.HookThis((DWORD)&Functions::gObjLevelUpEx,0x004044C1);
		func.HookThis((DWORD)&CloseWarehouse,0x00403828);
		Balancer.LoadSettings();
		func.HookThis((DWORD)&CBalancer::gObjCalCharacter,0x00402C3E);
		Tips.Load();
		News.Load();
		func.HookThis((DWORD)&Functions::AllSendServerMsg,0x00404368);
		func.HookThis((DWORD)&cDisplay::ViewPaint,0x004043EA);
		func.HookThis((DWORD)&cDisplay::LogTextPaintProcEx,0x00404016);
		func.HookThis((DWORD)&cDisplay::LogTextAddEx,0x0040234C);

		/*if (sizeof(OBJECTSTRUCT) != OBJECT_SIZE)
        {
             MessageBox(NULL, "Struct size errada", "Erro", MB_OK);
        }*/
		// New Customs
		func.IniciaIni();
		CarregarMapDropRate();


		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, 0, 0, 0);

	}
	else
	{
		MessageBoxA(NULL,"Injeção de códigos da DLL falhou!","Fire Plugin - Fatal Erro",NULL);
	}
}