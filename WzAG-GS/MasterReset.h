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

class cMReset
{
public:
	bool Load();
	void Increase(int aIndex, int Num);
	void InitExec(int aIndex);
	
public:
	bool					_Active;
	int					    _NeedFor[6];
	int					    _NeedAgi[6];
	int					    _NeedVit[6];
	int					    _NeedEne[6];
	int					    _NeedCmd[6];
	int					    _Level[6];
	int						_Resets[6];
	int					    _Zen[6];
	int					    _NextLevel[6];
	int					    _Zerar[6];
	char					_Syntax[25];
	char					_Query[8][255];
};

extern cMReset MReset;