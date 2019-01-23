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

struct sTeleport
{
	int Active;
	int Map;
	int CorX;
	int CorY;
	int Level;
	int Zen;
	int Vip;
	int Pk;
	char Syntax[25];
};

class gObjTeleportEx
{
public:
	static bool LoadMoves();
	static void InitTeleport(DWORD aIndex,short Num);

public:
	int CountMoves;
};

extern gObjTeleportEx TeleportEx;
extern sTeleport Teleport[255];