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
	int					_Level[6];
	int					_Zen;
	int					_RemoveItems[6];
	int					_NextLevel;
	int					_MaxResets;
};

struct Reset_Pontuativo
{
	int					_Level[6];
	int					_Zen;
	int					_NextLevel;
	int					_RemoveItems[6];
	int					_PointsAdd[6];
	int					_MaxResets;
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
	char					_Query[5][255];
	bool					_ResetMove;
	bool					_ResetAuto;
};

extern cReset Reset;