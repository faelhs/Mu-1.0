#include "StdAfx.h"
#include "Sorteio.h"
#include <ctime>


void cSorteio::Config()
{
	int EnableSorteio = GetPrivateProfileInt("Sorteio", "Ativar", 1, CFG_SORTEIO);
	this->_Tempo = GetPrivateProfileInt("Sorteio", "Tempo", 6, CFG_SORTEIO);
	this->_Golds = GetPrivateProfileInt("Sorteio", "Quantia", 10, CFG_SORTEIO);
	
	if (EnableSorteio < 1) {
		return;
	}
}
bool cSorteio::Load() {
	 Sorteio.Config();	
	 Sorteio._Time = this->_Tempo * 60 * 1000 - (60 * 1000 * 5);
	_beginthread(&Sorteio.Run, 0, NULL);
	
	return true;
}

void cSorteio::Run(void * lpParam){
	while (true)
	{
		Sleep(Sorteio._Time);
		func.MsgAllUser(0, "O sorteio começará em 5 minuto(s)");
		Sleep(60000);
		func.MsgAllUser(0, "O sorteio começará em 4 minuto(s)");
		Sleep(60000);
		func.MsgAllUser(0, "O sorteio começará em 3 minuto(s)");
		Sleep(60000);
		func.MsgAllUser(0, "O sorteio começará em 2 minuto(s)");
		Sleep(60000);
		func.MsgAllUser(0, "O sorteio começará em 1 minuto(s)");
		Sleep(60000);
		
		Sorteio.premio();
	}
}



void cSorteio::premio(){

	char					_Query[255];
	char * premio = NULL;
	GetPrivateProfileString("Querys", "UPDATE PREMIAR", "", _Query, 255, CFG_QUERY);
	this->PlayerCount = 0;
	for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if (gObj[i].Authority == 1 && gObj[i].Connected == 3)
		{
			this->_AccountPlayer[PlayerCount] = gObj[i].AccountID;
			this->_NamePlayer[PlayerCount] = gObj[i].Name;
			this->PlayerCount++;
		}
	}
	if (this->PlayerCount <= 10) {
			int n = Sorteio.randomGen(this->PlayerCount, 0);
			if (this->_NamePlayer[n] == NULL) {
				func.MsgAllUser(0, " Sinto muito ninguém foi sorteador.");
				LogSystem::DKLog("Nimguém", "Foi premiado no sorteio de golds.");
			}
			else if (this->_NamePlayer[n] == "") {
				func.MsgAllUser(0, " Sinto muito ninguém foi sorteador.");
				LogSystem::DKLog("Nimguém", "Foi premiado no sorteio de golds.");
			}
			else {
				Manager.ExecFormat(_Query, this->_Golds, this->_AccountPlayer[n]);
				_itoa(this->_Golds, premio, 10);
				func.MsgAllUser(0, " %s foi sorteado e ganhou %s golds.", this->_NamePlayer[n],&premio);
				LogSystem::DKLog(this->_NamePlayer[n], "Foi premiado no sorteio de golds.");
			}
			return;
	}
	if (this->PlayerCount <= 50) {
		for (int i = 0; i <= 5; i++)
		{
			int n = Sorteio.randomGen(this->PlayerCount, 0);
			if (this->_NamePlayer[n] == NULL) {
				func.MsgAllUser(0, " Sinto muito ninguém foi sorteador.");
				LogSystem::DKLog("Nimguém", "Foi premiado no sorteio de golds.");
			}
			else if (this->_NamePlayer[n] == "") {
				func.MsgAllUser(0, " Sinto muito ninguém foi sorteador.");
				LogSystem::DKLog("Nimguém", "Foi premiado no sorteio de golds.");
			}
			else {
				Manager.ExecFormat(_Query, this->_Golds, this->_AccountPlayer[n]);
				_itoa(this->_Golds, premio, 10);
				func.MsgAllUser(0, " %s foi sorteado e ganhou %s golds.", this->_NamePlayer[n], &premio);
				LogSystem::DKLog(this->_NamePlayer[n], "Foi premiado no sorteio de golds.");
			}
		}
		return;
	}
	else if (this->PlayerCount <= 100) {
		for (int i = 0; i <= 20; i++)
		{
			int n = Sorteio.randomGen(this->PlayerCount, 0);
			if (this->_NamePlayer[n] == NULL) {
				func.MsgAllUser(0, " Sinto muito ninguém foi sorteador.");
				LogSystem::DKLog("Nimguém", "Foi premiado no sorteio de golds.");
			}
			else if (this->_NamePlayer[n] == "") {
				func.MsgAllUser(0, " Sinto muito ninguém foi sorteador.");
				LogSystem::DKLog("Nimguém", "Foi premiado no sorteio de golds.");
			}
			else {
				Manager.ExecFormat(_Query, this->_Golds, this->_AccountPlayer[n]);
				_itoa(this->_Golds, premio, 10);
				func.MsgAllUser(0, " %s foi sorteado e ganhou %s golds.", this->_NamePlayer[n], &premio);
				LogSystem::DKLog(this->_NamePlayer[n], "Foi premiado no sorteio de golds.");
			}
		}
		return;
	}
	else {
		for (int i = 0; i <= 30; i++)
		{
			int n = Sorteio.randomGen(this->PlayerCount, 0);
			if (this->_NamePlayer[n] == NULL) {
				func.MsgAllUser(0, " Sinto muito ninguém foi sorteador.");
				LogSystem::DKLog("Nimguém", "Foi premiado no sorteio de golds.");
			}
			else if (this->_NamePlayer[n] == "") {
				func.MsgAllUser(0, " Sinto muito ninguém foi sorteador.");
				LogSystem::DKLog("Nimguém", "Foi premiado no sorteio de golds.");
			}
			else {
				Manager.ExecFormat(_Query, this->_Golds, this->_AccountPlayer[n]);
				_itoa(this->_Golds, premio, 10);
				func.MsgAllUser(0, " %s foi sorteado e ganhou %s golds.", this->_NamePlayer[n], &premio);
				LogSystem::DKLog(this->_NamePlayer[n], "Foi premiado no sorteio de golds.");
			}
		}
		return;
	}
	}

int cSorteio::randomGen(int x, int y)
{
	int max = x, min = y, range;
	range = max - min + 1;
	return rand() % range + min;
}
cSorteio Sorteio;