#pragma once

class HappyHour
{
public:
	static void ReadHappyHourEvent();
	static bool LoadSettings();
	static void HappyH(void * lpParam);
	static void Inicia();
	static void Final();

	int ActivoNoActivo;
	int Inicio;
	int Duracion;
	int Exp;
	int Drop;

};
void SetDrop(DWORD Drop);	
int GetDrop();
extern HappyHour Happy;