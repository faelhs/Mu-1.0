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

class PegaEvent
{
public:
	PegaEvent();
	~PegaEvent();

public:
	bool Load();
	bool Check(LPOBJ lpObj, const char* Text);
	void Start(int Time);
	void Run();
	bool CheckItem(LPOBJ lpObj);
	bool Attack(LPOBJ lpObj, LPOBJ lpTargetObj);
	void Quit(LPOBJ lpObj);
	bool Equip(LPOBJ lpObj, BYTE SourcePos, BYTE TargetPos);

private:
	bool				_Active;
	bool                _Capturar;
	char				_Syntax[2][25];
	char                _Query[3][255];
	char                _Notice[3][60];
	BYTE				_MapNumber;
	BYTE				_X;
	BYTE				_Y;
	BYTE				_State;
	int			        _Count;
	std::vector<LPOBJ>	_Players;
	char				_Account[3][11];
	char				_Name[3][11];

private:
	enum State
	{
		Empty, Register, Capture, Progress, Final
	};
};

extern PegaEvent Pega;