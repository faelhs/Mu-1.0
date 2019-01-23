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

void Customs()
{
	*(unsigned int*) (0x4B7932+3) = GetPrivateProfileInt("Server","Level Máximo",400,CFG_GAMESERVER);
	*(unsigned int*) (0x4D046B+2) = GetPrivateProfileInt("Server","Level Máximo",400,CFG_GAMESERVER);
	*(unsigned int*) (0x51ACA0+2) = GetPrivateProfileInt("Server","Level Máximo",400,CFG_GAMESERVER);
	*(unsigned int*) (0x526D50+2) = GetPrivateProfileInt("Server","Level Máximo",400,CFG_GAMESERVER);
	*(unsigned int*) (0x50A5BD+3) = GetPrivateProfileInt("Server","Level Máximo",400,CFG_GAMESERVER);

	*(unsigned char*) (0x4D0581+2) = GetPrivateProfileInt("Server","Pontos Por Level <BK | SM | ELF>",5,CFG_GAMESERVER);
    *(unsigned char*) (0x4D056A+2) = GetPrivateProfileInt("Server","Pontos Por Level <MG>",7,CFG_GAMESERVER);
    *(unsigned char*) (0x4D0542+2) = GetPrivateProfileInt("Server","Pontos Por Level <DL>",7,CFG_GAMESERVER);

	*(unsigned int*) (0x50A48D+1) = GetPrivateProfileInt("GameServerInfo", "Porta UDP", 60006, CFG_SVINFO);

	*(unsigned char*) (0x44B49B+2) = GetPrivateProfileInt("Server","Players para iniciar uma guild aliança",20,CFG_GAMESERVER);

	*(unsigned long*) (0x437D77+3) = GetPrivateProfileInt("Server","Máximo de Zen no Inventory",2000000000,CFG_GAMESERVER);

	*(unsigned long*) (0x43EEF6+3) = GetPrivateProfileInt("Server","Máximo de Zen no WareHouse",2000000000,CFG_GAMESERVER);
	*(unsigned long*) (0x43EFEC+3) = GetPrivateProfileInt("Server","Máximo de Zen no WareHouse",2000000000,CFG_GAMESERVER);
	*(unsigned long*) (0x43EF22+2) = GetPrivateProfileInt("Server","Máximo de Zen no WareHouse",2000000000,CFG_GAMESERVER);

	*(unsigned char*) (0x4EE8DB+3) = GetPrivateProfileInt("JóiasRates","Chance de Sucesso da Jewel of Souls em Items Sem Luck",0,CFG_GAMESERVER);
	*(unsigned char*) (0x4EE7FC+3) = GetPrivateProfileInt("JóiasRates","Chance de Sucesso da Jewel of Souls em Items Com Luck",100,CFG_GAMESERVER);
	*(unsigned char*) (0x4EEFCA+3) = GetPrivateProfileInt("JóiasRates","Chance de Sucesso da Jewel of Life em Items",0,CFG_GAMESERVER);

	*(unsigned int*) (0x4FC7F0+3) = GetPrivateProfileInt("JóiasPreços","Preço da Jewel of Bless",6000000,CFG_GAMESERVER);
    *(unsigned int*) (0x4FC811+3) = GetPrivateProfileInt("JóiasPreços","Preço da Jewel of Soul",9000000,CFG_GAMESERVER);
    *(unsigned int*) (0x4FC833+3) = GetPrivateProfileInt("JóiasPreços","Preço da Jewel of Chaos",810000,CFG_GAMESERVER);
    *(unsigned int*) (0x4FC855+3) = GetPrivateProfileInt("JóiasPreços","Preço da Jewel of Life",45000000,CFG_GAMESERVER);
    *(unsigned int*) (0x4FC876+3) = GetPrivateProfileInt("JóiasPreços","Preço da Jewel of Creation",36000000,CFG_GAMESERVER);

	*(unsigned int*) (0x48E9FE+1) = GetPrivateProfileInt("Server","Tempo dos Itens Dropados no chão",120,CFG_GAMESERVER)*1000;
	*(unsigned int*) (0x48EB9F+1) = GetPrivateProfileInt("Server","Tempo dos Itens Dropados no chão",120,CFG_GAMESERVER)*1000;

	*(unsigned int*) (0x47F760+7) = GetPrivateProfileInt("Skills do blade knight","Level requerido para uso da twisting slash skill",80,CFG_GAMESERVER);
	*(unsigned int*) (0x47F779+7) = GetPrivateProfileInt("Skills do blade knight","Level requerido para uso da rage ful blow skill",170,CFG_GAMESERVER);
	*(unsigned int*) (0x47F792+7) = GetPrivateProfileInt("Skills do blade knight","Level requerido para uso da death stab skill",160,CFG_GAMESERVER);
	*(unsigned int*) (0x47F7C4+7) = GetPrivateProfileInt("Skills do blade knight","Level requerido para uso da great fortitude skill",120,CFG_GAMESERVER);
	*(unsigned int*) (0x47F7DD+7) = GetPrivateProfileInt("Skills do blade knight","Level requerido para uso da penetration skill",1,CFG_GAMESERVER);

	*(unsigned int*) (0x4B015F+1) = GetPrivateProfileInt("GreatFortitude","GreatFortitudeVitality",100,CFG_GAMESERVER);
	*(unsigned int*) (0x4B017F+1) = GetPrivateProfileInt("GreatFortitude","GreatFortitudeEnergy",20,CFG_GAMESERVER);
	*(unsigned int*) (0x4B01A9+1) = GetPrivateProfileInt("GreatFortitude","GreatFortitudeDuration",760,CFG_GAMESERVER);

	*(unsigned int*) (0x4B053B+1) = GetPrivateProfileInt("ManaShield","AdditionalAgility",500,CFG_GAMESERVER);
	*(unsigned int*) (0x4B055B+1) = GetPrivateProfileInt("ManaShield","AdditionalEnergy",1600,CFG_GAMESERVER);
	*(unsigned int*) (0x4B0586+1) = GetPrivateProfileInt("ManaShield","ManaShieldDuration",760,CFG_GAMESERVER);

	*(unsigned char*) (0x491064+6) = GetPrivateProfileInt("ChaosMachineMixes","Chance de Sucesso ao Upar Item Para +10",100,CFG_GAMESERVER);
    *(unsigned char*) (0x49108F+6) = GetPrivateProfileInt("ChaosMachineMixes","Chance de Sucesso ao Upar Item Para +11",100,CFG_GAMESERVER);
	*(unsigned char*) (0x4910BA+6) = GetPrivateProfileInt("ChaosMachineMixes","Chance de Sucesso ao Upar Item Para +12",100,CFG_GAMESERVER);
	*(unsigned char*) (0x4910E5+6) = GetPrivateProfileInt("ChaosMachineMixes","Chance de Sucesso ao Upar Item Para +13",100,CFG_GAMESERVER);
	*(unsigned char*) (0x49246D+6) = GetPrivateProfileInt("ChaosMachineMixes","Chance de Sucesso ao Criar Asa Level 1",100,CFG_GAMESERVER);
	*(unsigned char*) (0x492479+6) = GetPrivateProfileInt("ChaosMachineMixes","Chance de Sucesso ao Criar Asa Level 2",100,CFG_GAMESERVER);
	*(unsigned char*) (0x4918CC+6) = GetPrivateProfileInt("ChaosMachineMixes","Chance de Sucesso ao Criar Pet Dinorant",100,CFG_GAMESERVER);
	*(unsigned char*) (0x491123+6) = GetPrivateProfileInt("ChaosMachineMixes","Chaos Machine Rate Máximo",100,CFG_GAMESERVER);
    *(unsigned char*) (0x49112F+6) = GetPrivateProfileInt("ChaosMachineMixes","Chaos Machine Rate Máximo",100,CFG_GAMESERVER);

	// -  CheckSum

	int  CheckSum = GetPrivateProfileInt("Server","CheckSum",0,CFG_GAMESERVER);
	if(  CheckSum != 0 )
	{
		func.SetByte(0x42C37A,0x7E);
		func.SetByte(0x42C3D8,0x74);
	}
	else
	{
		func.SetByte(0x42C37A,0xEB); 
		func.SetByte(0x42C3D8,0xEB);
	}

	// -  Flechas

	int  _Flechas = GetPrivateProfileInt("Server","Flechas Infinitas",0,CFG_GAMESERVER);
	if(  _Flechas != 0)
	{
		for(DWORD i = 0x4ACF39; i <= 0x4AD13E; i++)
		{
			func.SetByte(i,0x90);
		}
	}

	// -  Potions

	int  _Potions = GetPrivateProfileInt("Server","Potions Infinitos",0,CFG_GAMESERVER);
	if(  _Potions != 0)
	{
		func.SetByte(0x4447B7,0);
		func.SetByte(0x444A10,0);
		func.SetByte(0x444A8F,0);
	}

	// -  Pets

	int  _Pets = GetPrivateProfileInt("Server","Pets Imortais",0,CFG_GAMESERVER);
	if(  _Pets != 0)
	{
		func.SetByte(0x4D3E98,0x90);
		func.SetByte(0x4D3E99,0x90);
	}

	// -  Zen

	int  _Zen = GetPrivateProfileInt("Server","ZenDrop",0,CFG_GAMESERVER);
	if(  _Zen != 0 )
	{
		*(BYTE*)(0x48BED0) = 0xC3;
	}
	// Event Bags
	memcpy((char*)0x66F674, "EventBags\\Bag1.txt", sizeof("EventBags\\Bag1.txt"));
	memcpy((char*)0x66F65C, "EventBags\\Bag2.txt", sizeof("EventBags\\Bag2.txt"));
	memcpy((char*)0x66F644, "EventBags\\Bag3.txt", sizeof("EventBags\\Bag3.txt"));
	memcpy((char*)0x66F62C, "EventBags\\Bag4.txt", sizeof("EventBags\\Bag4.txt"));
	memcpy((char*)0x66F614, "EventBags\\Bag5.txt", sizeof("EventBags\\Bag5.txt"));
	memcpy((char*)0x66F5FC, "EventBags\\Bag6.txt", sizeof("EventBags\\Bag6.txt"));
	memcpy((char*)0x66F5E4, "EventBags\\Bag7.txt", sizeof("EventBags\\Bag7.txt"));
	memcpy((char*)0x66F5CC, "EventBags\\Bag8.txt", sizeof("EventBags\\Bag8.txt"));
	memcpy((char*)0x66F5B4, "EventBags\\Bag9.txt", sizeof("EventBags\\Bag9.txt"));
	memcpy((char*)0x66F59C, "EventBags\\Bag10.txt", sizeof("EventBags\\Bag10.txt"));
	memcpy((char*)0x66F584, "EventBags\\Bag11.txt", sizeof("EventBags\\Bag11.txt"));
	memcpy((char*)0x66F56C, "EventBags\\Bag12.txt", sizeof("EventBags\\Bag12.txt"));
	memcpy((char*)0x66F554, "EventBags\\Bag13.txt", sizeof("EventBags\\Bag13.txt"));
	memcpy((char*)0x66F53C, "EventBags\\Bag14.txt", sizeof("EventBags\\Bag14.txt"));
	memcpy((char*)0x66F524, "EventBags\\Bag15.txt", sizeof("EventBags\\Bag15.txt"));
	//memcpy((char*)0x, "EventBags\\Bag16.txt", sizeof("EventBags\\Bag16.txt"));
	memcpy((char*)0x66F50C, "EventBags\\Bag17.txt", sizeof("EventBags\\Bag17.txt"));
	memcpy((char*)0x66F4F4, "EventBags\\Bag18.txt", sizeof("EventBags\\Bag18.txt"));
	memcpy((char*)0x66F4DC, "EventBags\\Bag19.txt", sizeof("EventBags\\Bag19.txt"));


	//Mapas
	memcpy((char*)0x66E428, "Maps\\Map1.att", sizeof("Maps\\Map1.att"));
	memcpy((char*)0x66E418, "Maps\\Map2.att", sizeof("Maps\\Map2.att"));
	memcpy((char*)0x66E408, "Maps\\Map3.att", sizeof("Maps\\Map3.att"));
	memcpy((char*)0x66E3F8, "Maps\\Map4.att", sizeof("Maps\\Map4.att"));
	memcpy((char*)0x66E3E8, "Maps\\Map5.att", sizeof("Maps\\Map5.att"));
	memcpy((char*)0x66E3D8, "Maps\\Map6.att", sizeof("Maps\\Map6.att"));
	memcpy((char*)0x66E3C8, "Maps\\Map7.att", sizeof("Maps\\Map7.att"));
	memcpy((char*)0x66E3B8, "Maps\\Map8.att", sizeof("Maps\\Map8.att"));
	memcpy((char*)0x66E3A8, "Maps\\Map9.att", sizeof("Maps\\Map9.att"));
	memcpy((char*)0x66E398, "Maps\\Map10.att", sizeof("Maps\\Map10.att"));
	memcpy((char*)0x66E388, "Maps\\Map11.att", sizeof("Maps\\Map11.att"));
	memcpy((char*)0x66E378, "Maps\\Map12.att", sizeof("Maps\\Map12.att"));
	memcpy((char*)0x66E368, "Maps\\Map19.att", sizeof("Maps\\Map19.att"));
	memcpy((char*)0x66E358, "Maps\\Map25.att", sizeof("Maps\\Map25.att"));
	memcpy((char*)0x66E348, "Maps\\Map31.att", sizeof("Maps\\Map31.att"));
	memcpy((char*)0x66E338, "Maps\\Map32.att", sizeof("Maps\\Map32.att"));
	memcpy((char*)0x66E328, "Maps\\Map33.att", sizeof("Maps\\Map33.att"));
}