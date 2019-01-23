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

class Commands
{
public:
	bool Load();
	bool ChatRecv(PMSG_CHATDATA * lpMsg, int aIndex);
	void Post(int aIndex, char* msg);
	void Adicionar(int aIndex, LPCSTR Buffer, int Status);
	void ReAdicionar(int aIndex);
	void Clear(int aIndex);
	void Ware(int aIndex, LPCSTR Buffer);
	void Money(int aIndex);
	void Online (int aIndex);
	void Premiar(int aIndex, char* msg);
	void MoveAll(int aIndex, char* msg);
	void Skin(int aIndex, char* msg);
	void Move(int aIndex, char* msg);

private:
	bool					_Active[11];
	int					    _Level[6];
	int					    _Zen[8];
	int					    _Color;
	int					    _Delay;
	int					    _Vip;
	int					    _Ware[4];
	int                     _Number;
	char					_Syntax[15][25];
	char					_Formato[50];
	char                    _Notice[60];
	char					_Query[255];
};

extern Commands Command;