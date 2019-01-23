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
	int					    _NeedFor[4];
	int					    _NeedAgi[4];
	int					    _NeedVit[4];
	int					    _NeedEne[4];
	int					    _NeedCmd[4];
	int					    _Level[4];
	int					    _Zen[4];
	int					    _NextLevel[4];
	int					    _Zerar[4];
	char					_Syntax[25];
	char					_Query[5][255];
};

extern cMReset MReset;