//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 99.60T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#pragma once

struct Reset_Acumulativo
{
	int					_Level[4];
	int					_Zen;
	int					_RemoveItems[4];
	int					_NextLevel;
};

struct Reset_Pontuativo
{
	int					_Level[4];
	int					_Zen;
	int					_NextLevel;
	int					_RemoveItems[4];
	int					_PointsAdd[4];
};

class cReset
{
public:
	bool Load();
	void InitExec(int aIndex);
	bool CheckItem(LPOBJ lpObj);

	Reset_Acumulativo Acumulativo;
	Reset_Pontuativo Pontuativo;

public:
	bool					_Active;
	BYTE					_Type;
	char					_Syntax[25];
	char					_Query[4][255];
};

extern cReset Reset;