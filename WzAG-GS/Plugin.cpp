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

DWORD WINAPI EventTimer(LPVOID lpParam)
{
	Sleep(5000);
	EventTimeTick();
	return 1;
}

void Loaddll()
{
	DWORD OldProtect;
	if(VirtualProtect(LPVOID(0x401000),3543191,PAGE_EXECUTE_READWRITE,&OldProtect))
	{  
		ReadyLicense(); 
		Fixes();
		Manager.Initialize();
		Customs();
		func.HookThis((DWORD)&ProtocolCoreEx,0x004033E6);
		func.HookThis((DWORD)&DataSendEx,0x00401A7D);
		func.HookThis((DWORD)&Functions::gObjLifeCheckHook,0x00401C71);
		Reset.Load();
		MReset.Load();
		Command.Load();
		func.HookThis((DWORD)&Flood::Connection,0x00401352);
		func.HookThis((DWORD)&Functions::HookgObjAttack,0x00402919);
		func.HookThis((DWORD)&gObjSetCharacterEx,0x004020F9);
		func.HookThis((DWORD)&ChatTargetSend,0x00402A45);
		ExcellentShop.Load();
		Npc.Load();
		func.HookThis((DWORD)&cNpc::NPCTalk,0x004031B1);
		func.HookThis((DWORD)&Functions::gObjInterfaceTimeCheckEx,0x0040261C);
		func.HookThis((DWORD)&Functions::gObjSecondProcEx,0x00404985);
		func.HookThis((DWORD)&Functions::gObjPlayerKillerEx,0x0040285B);
		func.HookThis((DWORD)&Functions::gObjCloseSetEx,0x00401681);
		func.HookThis((DWORD)&CloseWarehouse,0x00403503);
		Duel.Load();
        Pega.Load();
		Sobre.Load();
		func.HookThis((DWORD)&Functions::gObjDelEx,0x00403689);
		gObjTeleportEx::LoadMoves();
		func.HookThis((DWORD)&Functions::gObjUserDieEx,0x00403071);
		Balancer.LoadSettings();
		func.HookThis((DWORD)&CBalancer::gObjCalCharacter,0x00402B99);

		func.HookThis((DWORD)&_blood_castle_hook,0x00403481);
		func.HookThis((DWORD)&_chaos_castle_hook,0x004018E3);
		_blood._iniciar_blood_castle(CFG_DROPBC);
	    _chaos._iniciar_chaos_castle(CFG_DROPCC);	

		func.HookThis((DWORD)&Functions::gObjInventoryMoveItemEx,0x00401A00);
		func.HookThis((DWORD)&Functions::gObjLevelUpEx, 0x00403F17);
		func.HookThis((DWORD)&Functions::GCWarePassSend, 0x0043C7D0);
		Tips.Load();
		News.Load();
		Hydra.Load();
		func.HookThis((DWORD)&Functions::AllSendServerMsg,0x00403DEB);
		func.HookThis((DWORD)&cDisplay::ViewPaint,0x00403E63);
		func.HookThis((DWORD)&cDisplay::LogTextPaintProcEx,0x00403B5C);
		func.HookThis((DWORD)&cDisplay::LogTextAddEx,0x00402478);

		//New Customs
		func.IniciaIni();
		AutoExp();
		EventLoad();
		CarregarMapDropRate();
		ReadGMSystem();
		ReadGoldShop();
		ReadQuest_Item_Reward();
		ReadyGCMagicAttackNumberSend();
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, 0, 0, 0);
		CloseHandle(CreateThread(NULL,0,EventTimer,NULL,0,NULL));
		func.HookThis((DWORD)&NpcShadowPhantomEx, 0x0040237E);
		gLottery.Load();				//-- Cerrega sorteio.
		Pdiario.load();					//-- Carrega premios do premio diario.
	}
	else
	{
		MessageBoxA(NULL,"Injeção de códigos da DLL falhou!","Fire Plugin - Fatal Erro",NULL);
	}
}
