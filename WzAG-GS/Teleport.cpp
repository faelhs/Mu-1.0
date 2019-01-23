//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 99.60T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "StdAfx.h"

sTeleport Teleport[255];

bool gObjTeleportEx::LoadMoves()
{
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(CFG_MOVE), group);

	if(group.GetSection(0, section))
	{	

		for(int i = 0; i < section.RowCount; i++)
		{
			TeleportEx.CountMoves++;
			Teleport[i].Active	= section.Rows[i].GetInt(0);
			Teleport[i].Level	= section.Rows[i].GetInt(1);
			Teleport[i].Zen		= section.Rows[i].GetInt(2);
			Teleport[i].Vip		= section.Rows[i].GetInt(3);
			Teleport[i].Pk		= section.Rows[i].GetInt(4);
			Teleport[i].Map		= section.Rows[i].GetInt(5);
			Teleport[i].CorX	= section.Rows[i].GetInt(6);
			Teleport[i].CorY	= section.Rows[i].GetInt(7);
			strcpy_s(&Teleport[i].Syntax[0],sizeof(Teleport[i].Syntax),(section.Rows[i].GetStringPtr(8)));
		}
	}

	return true;
}

void gObjTeleportEx::InitTeleport(DWORD aIndex, short Num)
{
	if (!Teleport[Num].Active)
	{
		func.MsgUser(aIndex,1,"Comando desabilitado.");
		return;
	}

	else if (!Teleport[Num].Pk)
	{
		if (gObj[aIndex].m_PK_Level >= 4)
		{
			func.MsgUser(aIndex,1,"Pk's não podem se mover.");
			return;
		}
	}

	else if (gObj[aIndex].m_IfState.type == 1 && gObj[aIndex].m_IfState.use == 1 || gObj[aIndex].WarehouseSave == 1)
	{
		func.MsgUser(aIndex,1,"Você se encontra ocupado no momento.");
		return;
	}

	else if (Teleport[Num].Level > gObj[aIndex].Level)
	{
		func.MsgUser(aIndex,1,"Você não possui level %d",Teleport[Num].Level);
		return;
	}

	else if (Teleport[Num].Zen > gObj[aIndex].Money)
	{
		func.MsgUser(aIndex,1,"Você não possui zen %d",Teleport[Num].Zen);
		return;
	}

	else if (Teleport[Num].Vip > Custom[aIndex].VipIndex)
	{
		func.MsgUser(aIndex,1,"Move restrito somente para vip's.");
		return;
	}
	else
	{
		gObj[aIndex].Money -= Teleport[Num].Zen;
		GCMoneySend(aIndex,gObj[aIndex].Money);
		gObjTeleport(aIndex,Teleport[Num].Map,Teleport[Num].CorX,Teleport[Num].CorY);
	}
}

gObjTeleportEx TeleportEx;