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

void Customs()
{
	*(unsigned int*)(0x4A4202 + 3) = GetPrivateProfileInt("Server", "Level Máximo", 400, CFG_GAMESERVER);
	*(unsigned int*)(0x4BCEFB + 2) = GetPrivateProfileInt("Server", "Level Máximo", 400, CFG_GAMESERVER);
	*(unsigned int*)(0x5058E0 + 2) = GetPrivateProfileInt("Server", "Level Máximo", 400, CFG_GAMESERVER);
	*(unsigned int*)(0x511990 + 2) = GetPrivateProfileInt("Server", "Level Máximo", 400, CFG_GAMESERVER);
	*(unsigned int*)(0x4F58EF + 3) = GetPrivateProfileInt("Server", "Level Máximo", 400, CFG_GAMESERVER);

	*(unsigned int*)(0x41A486 + 3) = GetPrivateProfileInt("Server", "Level Máximo Mobs", 1000, CFG_GAMESERVER)-1;
	*(unsigned int*)(0x41A0CB + 3) = GetPrivateProfileInt("Server", "Level Máximo Mobs", 1000, CFG_GAMESERVER);
	*(unsigned int*)(0x41A276 + 3) = GetPrivateProfileInt("Server", "Level Máximo Mobs", 1000, CFG_GAMESERVER);
	*(unsigned int*)(0x41A2CC + 3) = GetPrivateProfileInt("Server", "Level Máximo Mobs", 1000, CFG_GAMESERVER);
	*(unsigned int*)(0x41A3FC + 3) = GetPrivateProfileInt("Server", "Level Máximo Mobs", 1000, CFG_GAMESERVER);
	*(unsigned int*)(0x42CBF4 + 2) = GetPrivateProfileInt("Server", "Level Máximo Mobs", 1000, CFG_GAMESERVER);
	*(unsigned int*)(0x42D12F + 2) = GetPrivateProfileInt("Server", "Level Máximo Mobs", 1000, CFG_GAMESERVER);
	*(unsigned int*)(0x42D244 + 2) = GetPrivateProfileInt("Server", "Level Máximo Mobs", 1000, CFG_GAMESERVER);

	*(unsigned char*) (0x4BD011+2) = GetPrivateProfileInt("Server","Pontos Por Level <BK | SM | ELF>",5,CFG_GAMESERVER);
    *(unsigned char*) (0x4BCFFA+2) = GetPrivateProfileInt("Server","Pontos Por Level <MG>",7,CFG_GAMESERVER);
    *(unsigned char*) (0x4BCFD2+2) = GetPrivateProfileInt("Server","Pontos Por Level <DL>",7,CFG_GAMESERVER);

	*(unsigned int*)(0x4F57BF + 1) =GetPrivateProfileInt("GameServerInfo","Porta UDP",60006, CFG_SVINFO);
	//*(unsigned int*)(0x4F57BF + 1) = 60006; //Demo apenas

	*(unsigned long*) (0x434407+3) = GetPrivateProfileInt("Server","Máximo de Zen no Inventory",2000000000,CFG_GAMESERVER);

	*(unsigned long*) (0x43C156+3) = GetPrivateProfileInt("Server","Máximo de Zen no WareHouse",2000000000,CFG_GAMESERVER);
	*(unsigned long*) (0x43C24C+3) = GetPrivateProfileInt("Server","Máximo de Zen no WareHouse",2000000000,CFG_GAMESERVER);
	*(unsigned long*) (0x43C182+2) = GetPrivateProfileInt("Server","Máximo de Zen no WareHouse",2000000000,CFG_GAMESERVER);

	*(unsigned char*) (0x512690+3) = GetPrivateProfileInt("Server","Players para iniciar o chaos castle",1,CFG_GAMESERVER);

	*(unsigned char*) (0x44964B+2) = GetPrivateProfileInt("Server","Players para iniciar uma guild aliança",20,CFG_GAMESERVER);

	*(unsigned int*) (0x47C06E+1) = GetPrivateProfileInt("Server","Tempo dos Itens Dropados no chão",120,CFG_GAMESERVER)*1000;
	*(unsigned int*) (0x47C20F+1) = GetPrivateProfileInt("Server","Tempo dos Itens Dropados no chão",120,CFG_GAMESERVER)*1000;

	*(unsigned int*) (0x46CDD0+7) = GetPrivateProfileInt("Skills do blade knight","Level requerido para uso da twisting slash skill",80,CFG_GAMESERVER);
	*(unsigned int*) (0x46CDE9+7) = GetPrivateProfileInt("Skills do blade knight","Level requerido para uso da rage ful blow skill",170,CFG_GAMESERVER);
	*(unsigned int*) (0x46CE02+7) = GetPrivateProfileInt("Skills do blade knight","Level requerido para uso da death stab skill",160,CFG_GAMESERVER);
	*(unsigned int*) (0x46CE34+7) = GetPrivateProfileInt("Skills do blade knight","Level requerido para uso da great fortitude skill",120,CFG_GAMESERVER);
	*(unsigned int*) (0x46CE4D+7) = GetPrivateProfileInt("Skills do blade knight","Level requerido para uso da penetration skill",1,CFG_GAMESERVER);

	*(unsigned int*) (0x49CD0F+1) = GetPrivateProfileInt("GreatFortitude","GreatFortitudeVitality",100,CFG_GAMESERVER);
	*(unsigned int*) (0x49CD2F+1) = GetPrivateProfileInt("GreatFortitude","GreatFortitudeEnergy",20,CFG_GAMESERVER);
	*(unsigned int*) (0x49CD59+1) = GetPrivateProfileInt("GreatFortitude","GreatFortitudeDuration",760,CFG_GAMESERVER);

	*(unsigned int*) (0x49D0EB+1) = GetPrivateProfileInt("ManaShield","AdditionalAgility",500,CFG_GAMESERVER);
	*(unsigned int*) (0x49D10B+1) = GetPrivateProfileInt("ManaShield","AdditionalEnergy",1600,CFG_GAMESERVER);
	*(unsigned int*) (0x49D136+1) = GetPrivateProfileInt("ManaShield","ManaShieldDuration",760,CFG_GAMESERVER);

	*(unsigned char*) (0x4D9FAB+3) = GetPrivateProfileInt("JóiasRates","Chance de Sucesso da Jewel of Souls em Items Sem Luck",0,CFG_GAMESERVER);
	*(unsigned char*) (0x4D9ECC+3) = GetPrivateProfileInt("JóiasRates","Chance de Sucesso da Jewel of Souls em Items Com Luck",100,CFG_GAMESERVER);
	*(unsigned char*) (0x4DA69A+3) = GetPrivateProfileInt("JóiasRates","Chance de Sucesso da Jewel of Life em Items",0,CFG_GAMESERVER);

	*(unsigned int*) (0x4E7DF0+3) = GetPrivateProfileInt("JóiasPreços","Preço da Jewel of Bless",6000000,CFG_GAMESERVER);
    *(unsigned int*) (0x4E7E11+3) = GetPrivateProfileInt("JóiasPreços","Preço da Jewel of Soul",9000000,CFG_GAMESERVER);
    *(unsigned int*) (0x4E7E33+3) = GetPrivateProfileInt("JóiasPreços","Preço da Jewel of Chaos",810000,CFG_GAMESERVER);
    *(unsigned int*) (0x4E7E55+3) = GetPrivateProfileInt("JóiasPreços","Preço da Jewel of Life",45000000,CFG_GAMESERVER);
    *(unsigned int*) (0x4E7E76+3) = GetPrivateProfileInt("JóiasPreços","Preço da Jewel of Creation",36000000,CFG_GAMESERVER);

	*(unsigned char*) (0x47E6D4+6) = GetPrivateProfileInt("ChaosMachineMixes","Chance de Sucesso ao Upar Item Para +10",100,CFG_GAMESERVER);
	*(unsigned char*) (0x47E6FF+6) = GetPrivateProfileInt("ChaosMachineMixes","Chance de Sucesso ao Upar Item Para +11",100,CFG_GAMESERVER);
	*(unsigned char*) (0x47E72A+6) = GetPrivateProfileInt("ChaosMachineMixes","Chance de Sucesso ao Upar Item Para +12",100,CFG_GAMESERVER);
	*(unsigned char*) (0x47E755+6) = GetPrivateProfileInt("ChaosMachineMixes","Chance de Sucesso ao Upar Item Para +13",100,CFG_GAMESERVER);
	*(unsigned char*) (0x47FADD+6) = GetPrivateProfileInt("ChaosMachineMixes","Chance de Sucesso ao Criar Asa Level 1",100,CFG_GAMESERVER);
	*(unsigned char*) (0x47FAE9+6) = GetPrivateProfileInt("ChaosMachineMixes","Chance de Sucesso ao Criar Asa Level 2",100,CFG_GAMESERVER);
	*(unsigned char*) (0x47EF3C+6) = GetPrivateProfileInt("ChaosMachineMixes","Chance de Sucesso ao Criar Pet Dinorant",100,CFG_GAMESERVER);
	*(unsigned char*) (0x47E793+6) = GetPrivateProfileInt("ChaosMachineMixes","Chaos Machine Rate Máximo",100,CFG_GAMESERVER);
    *(unsigned char*) (0x47E79F+6) = GetPrivateProfileInt("ChaosMachineMixes","Chaos Machine Rate Máximo",100,CFG_GAMESERVER);

	*(unsigned char*) (0x4F76F9+1) = GetPrivateProfileInt("GameServerInfo","NonPK",1,CFG_SVINFO);
	*(unsigned char*) (0x4F7845+1) = GetPrivateProfileInt("GameServerInfo","NonPK",1,CFG_SVINFO);
	*(unsigned char*) (0x4F7991+1) = GetPrivateProfileInt("GameServerInfo","NonPK",1,CFG_SVINFO);
	*(unsigned char*) (0x4F7ADD+1) = GetPrivateProfileInt("GameServerInfo","NonPK",1,CFG_SVINFO);

	//Versão Demo Apenas 

	//memset((char*)0x617148, 0, 17);
	//memcpy((char*)0x617148, "demoversion10ply", sizeof("demoversion10ply"));
	//*(unsigned int*)(0x4F837B + 1) = 20;

	// - Checksum

	int  CheckSum = GetPrivateProfileInt("Server","CheckSum",0,CFG_GAMESERVER);
	if(  CheckSum != 0 )
	{
		func.SetByte(0x428A3A,0x7E);
		func.SetByte(0x428A98,0x74);
	}
	else
	{
		func.SetByte(0x428A3A,0xEB); 
		func.SetByte(0x428A98,0xEB);
	}

	// - Flechas

	int  _Flechas = GetPrivateProfileInt("Server","Flechas Infinitas",0,CFG_GAMESERVER);
	if(  _Flechas != 0)
	{
		for(DWORD i = 0x499BF9; i <= 0x499DFE; i++)
		{
			func.SetByte(i,0x90);
		}
	}

	// - Potions

	int  _Potions = GetPrivateProfileInt("Server","Potions Infinitos",0,CFG_GAMESERVER);
	if(  _Potions != 0)
	{
		func.SetByte(0x441657,0);
		func.SetByte(0x4418B0,0);
		func.SetByte(0x44192F,0);
	}

	// - Pets

	int  _Pets = GetPrivateProfileInt("Server","Pets Imortais",0,CFG_GAMESERVER);
	if(  _Pets != 0)
	{
		func.SetByte(0x4C07A8,0x90);
		func.SetByte(0x4C07A9,0x90);
	}

	// - Zen

	int  _Zen = GetPrivateProfileInt("Server","ZenDrop",0,CFG_GAMESERVER);
	if(  _Zen != 0 )
	{
		*(BYTE*)(0x479540) = 0xC3;
	}

	// Event Bags
	memcpy((char*)0x6179F0, "EventBags\\Bag1.txt", sizeof("EventBags\\Bag1.txt"));
	memcpy((char*)0x6179D8, "EventBags\\Bag2.txt", sizeof("EventBags\\Bag2.txt"));
	memcpy((char*)0x6179C0, "EventBags\\Bag3.txt", sizeof("EventBags\\Bag3.txt"));
	memcpy((char*)0x6179A8, "EventBags\\Bag4.txt", sizeof("EventBags\\Bag4.txt"));
	memcpy((char*)0x617990, "EventBags\\Bag5.txt", sizeof("EventBags\\Bag5.txt"));
	memcpy((char*)0x617978, "EventBags\\Bag6.txt", sizeof("EventBags\\Bag6.txt"));
	memcpy((char*)0x617960, "EventBags\\Bag7.txt", sizeof("EventBags\\Bag7.txt"));
	memcpy((char*)0x617948, "EventBags\\Bag8.txt", sizeof("EventBags\\Bag8.txt"));
	memcpy((char*)0x617930, "EventBags\\Bag9.txt", sizeof("EventBags\\Bag9.txt"));
	memcpy((char*)0x617918, "EventBags\\Bag10.txt", sizeof("EventBags\\Bag10.txt"));
	memcpy((char*)0x617900, "EventBags\\Bag11.txt", sizeof("EventBags\\Bag11.txt"));
	memcpy((char*)0x6178E8, "EventBags\\Bag12.txt", sizeof("EventBags\\Bag12.txt"));
	memcpy((char*)0x6178D0, "EventBags\\Bag13.txt", sizeof("EventBags\\Bag13.txt"));
	memcpy((char*)0x6178B8, "EventBags\\Bag14.txt", sizeof("EventBags\\Bag14.txt"));
	memcpy((char*)0x6178A0, "EventBags\\Bag15.txt", sizeof("EventBags\\Bag15.txt"));
	//memcpy((char*)0x, "EventBags\\Bag16.txt", sizeof("EventBags\\Bag16.txt"));
	memcpy((char*)0x617888, "EventBags\\Bag17.txt", sizeof("EventBags\\Bag17.txt"));
	//memcpy((char*)0x, "EventBags\\Bag18.txt", sizeof("EventBags\\Bag18.txt"));
	//memcpy((char*)0x, "EventBags\\Bag19.txt", sizeof("EventBags\\Bag19.txt"));


	//Mapas
	memcpy((char*)0x616804, "Maps\\Map1.att", sizeof("Maps\\Map1.att"));
	memcpy((char*)0x6167F4, "Maps\\Map2.att", sizeof("Maps\\Map2.att"));
	memcpy((char*)0x6167E4, "Maps\\Map3.att", sizeof("Maps\\Map3.att"));
	memcpy((char*)0x6167D4, "Maps\\Map4.att", sizeof("Maps\\Map4.att"));
	memcpy((char*)0x6167C4, "Maps\\Map5.att", sizeof("Maps\\Map5.att"));
	memcpy((char*)0x6167B4, "Maps\\Map6.att", sizeof("Maps\\Map6.att"));
	memcpy((char*)0x6167A4, "Maps\\Map7.att", sizeof("Maps\\Map7.att"));
	memcpy((char*)0x616794, "Maps\\Map8.att", sizeof("Maps\\Map8.att"));
	memcpy((char*)0x616784, "Maps\\Map9.att", sizeof("Maps\\Map9.att"));
	memcpy((char*)0x616774, "Maps\\Map10.att", sizeof("Maps\\Map10.att"));
	memcpy((char*)0x616764, "Maps\\Map11.att", sizeof("Maps\\Map11.att"));
	memcpy((char*)0x616754, "Maps\\Map12.att", sizeof("Maps\\Map12.att"));
	memcpy((char*)0x616744, "Maps\\Map19.att", sizeof("Maps\\Map19.att"));
	memcpy((char*)0x616734, "Maps\\Map25.att", sizeof("Maps\\Map25.att"));
	memcpy((char*)0x616724, "Maps\\Map31.att", sizeof("Maps\\Map31.att"));
	memcpy((char*)0x616714, "Maps\\Map32.att", sizeof("Maps\\Map32.att"));
	memcpy((char*)0x616704, "Maps\\Map33.att", sizeof("Maps\\Map33.att"));
}
