#include "StdAfx.h"

HappyHour Happy;

void HappyHour::ReadHappyHourEvent()
{   
	HappyHour::LoadSettings();

	if(Happy.ActivoNoActivo != 0 )
	{
		_beginthread(&HappyHour::HappyH,0,NULL);
	}
}

bool HappyHour::LoadSettings()
{
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   Section;

	token.ParseFile(std::string(CFG_HHOUR), group);

	if(group.GetSection(0, Section))
	{	
		Happy.ActivoNoActivo	= Section.Rows[0].GetInt(0);
		Happy.Inicio			= Section.Rows[0].GetInt(1);
		Happy.Duracion			= Section.Rows[0].GetInt(2);
		Happy.Exp				= Section.Rows[0].GetInt(3);
		Happy.Drop				= Section.Rows[0].GetInt(4);
	}
	return true;
}

void HappyHour::HappyH(void * lpParam)
{
	while(true)
	{
		Sleep(Happy.Inicio * 60000);
		func.AllSendServerMsg("[Happy Hour] Inicia en 1 Minuto");
		Sleep(60000); 
		HappyHour::Inicia();
		//Final HappyHours
		Sleep(Happy.Duracion * 60000);
		func.AllSendServerMsg("[Happy Hour] Termina en 1 minuto");
		Sleep(60000); 
		HappyHour::Final();
		func.AllSendServerMsg("[Happy Hour] Finalizado");
	}
}

void SetDrop(DWORD Drop)
{
	__asm
	{
		MOV EAX,Drop
			MOV DWORD PTR DS:[SetORGetDrop_Offset],EAX
	}
}

int GetDrop()
{
	int retr=0;
	_asm
	{
		MOV ECX, DWORD PTR DS: [SetORGetDrop_Offset]
		MOV retr, ECX
	}
	return retr;
}

void HappyHour::Inicia()
{
	char sBuf[255] = {0};
	char sBuf2[255] = {0};

	if(Happy.ActivoNoActivo != 0) 
	{
		func.AllSendServerMsg("[Happy Hour] Iniciado");

		wsprintf(sBuf, "Experiencia + %d, Drop + %d",Happy.Exp,Happy.Drop);

		float * EXPERIENCE = (float *)(getAddExperience); 

		(*EXPERIENCE) += Happy.Exp;

		SetDrop( GetDrop() + Happy.Drop );

		func.AllSendServerMsg(sBuf);
		return;
	}
}

void HappyHour::Final()
{
	float * EXPERIENCE = (float *)(getAddExperience); 
	
	(*EXPERIENCE) -= Happy.Exp;

	SetDrop(GetDrop()-Happy.Drop);
	return;
}