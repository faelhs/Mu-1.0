//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 0.97.40T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#pragma once

struct sHydra
{
	DWORD ItemType;       
	DWORD ItemIndex;       
	DWORD ItemLevel;
	DWORD ItemLuck;
	DWORD ItemSkill;
	DWORD ItemDur;       
	DWORD ItemOpt;       
	DWORD ItemExc;   
};

class cHydra
{
public:
	bool Load();
	static void Run(void * lpParam);
	void DisappearMonster();
	void Dropitem(int aIndex);

public:
	int					    _Active;
	bool                    _Alive;
	DWORD					_Time;
	DWORD					_Duration;
	DWORD					_Count;

	sHydra HydraDrop[1000];
};

extern cHydra Hydra;