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

struct SurvivorPlayer
{
	BYTE EventStatus;
	bool SurvivorBlock;
	bool RequestMove;
};

class SobreEvent
{
public:
	SobreEvent();
	~SobreEvent();

public:
	bool Load();
	bool Check(LPOBJ lpObj, const char* Text);
	void Start(int Time);
	void Run();
	bool Attack(LPOBJ lpObj, LPOBJ lpTargetObj);
	void Die(LPOBJ lpObj, LPOBJ lpTargetObj);
	void PlayerOut(LPOBJ lpObj);
	void Quit(LPOBJ lpObj);

private:
	bool				_Active;
	char				_Syntax[2][25];
	char                _Query[255];
	char                _Notice[60];
	BYTE				_MapNumber;
	BYTE				_X;
	BYTE				_Y;
	BYTE				_State;
	int			        _Count;
	int                 _PlayerCount;
	SurvivorPlayer Player[1000];

private:
	enum State
	{
		Empty, Register, Progress, Fight, Final
	};
};

extern SobreEvent Sobre;