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

struct DuelPlayer
{
	bool Die;
	bool Quit;
	BYTE Score;
	LPOBJ lpObj;
};

class DuelEvent
{
public:
	DuelEvent();
	~DuelEvent();
	
public:
	bool Load();
	bool Check(LPOBJ lpObj, const char* Text);
	void Start(int Time, int Class);
	void Run();
	bool Attack(LPOBJ lpObj, LPOBJ lpTargetObj);
	void Die(LPOBJ lpObj);
	void Quit(LPOBJ lpObj);

private:
	bool					_Active;
	char					_Syntax[2][25];
	char                    _Query[255];
	char                    _Notice[60];
	BYTE					_MapNumber[2];
	BYTE					_X[2];
	BYTE					_Y[2];
	BYTE					_State;
	BYTE					_Type;
	int						_Count;
	std::vector<DuelPlayer> _Players[2];
	DuelPlayer				_Selected[2];

private:
	enum State
	{
		Empty, Register, Select, Progress, Died, NextStage, WO, Final
	};
};

extern DuelEvent Duel;