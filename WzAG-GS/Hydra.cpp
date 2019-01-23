//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 0.97.40T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "StdAfx.h"

bool cHydra::Load()
{
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   Section;

	token.ParseFile(std::string(CFG_HYDRA),group);

	if (group.GetSection(0, Section))
	{	
		this->_Active = Section.Rows[0].GetInt(0);
		this->_Time = Section.Rows[0].GetInt(1) * 60 * 60 * 1000 - (60*  1000*  5);
		this->_Duration = Section.Rows[0].GetInt(2) * 60 * 1000;
	}

	if (group.GetSection(1, Section))
	{
		this->_Count = Section.RowCount;

		for (int i = 0; i < Section.RowCount; i++)
		{
			HydraDrop[i].ItemType = Section.Rows[i].GetInt(0);
			HydraDrop[i].ItemIndex = Section.Rows[i].GetInt(1);
			HydraDrop[i].ItemLevel = Section.Rows[i].GetInt(2);
			HydraDrop[i].ItemLuck = Section.Rows[i].GetInt(3);
			HydraDrop[i].ItemSkill = Section.Rows[i].GetInt(4);
			HydraDrop[i].ItemDur = Section.Rows[i].GetInt(5);
			HydraDrop[i].ItemOpt = Section.Rows[i].GetInt(6);
			HydraDrop[i].ItemExc = Section.Rows[i].GetInt(7);
		}
	}

	if (this->_Active != 0)
	{
		_beginthread(&cHydra::Run,0,NULL);
	}

	return true;
}

void cHydra::Run(void * lpParam)
{
	while(true)
	{
		Sleep(Hydra._Time);

		func.MsgAllUser(0,"A Hydra aparecerá em 5 Minuto(s)");
		Sleep(60000);  
		func.MsgAllUser(0,"A Hydra aparecerá em 4 Minuto(s)");
		Sleep(60000); 
		func.MsgAllUser(0,"A Hydra aparecerá em 3 Minuto(s)");
		Sleep(60000); 
		func.MsgAllUser(0,"A Hydra aparecerá em 2 Minuto(s)");
		Sleep(60000); 
		func.MsgAllUser(0,"A Hydra aparecerá em 1 Minuto(s)");
		Sleep(60000);

		short X, Y;

		while (func.GetBoxPosition(7,10,10,240,240,X,Y) == 0) {}

		func.MosterAdd(49,7,X,Y);

		Hydra._Alive = true;

		PMSG_NOTICE pNotice[2];

		func.MakeNoticeMsg(&pNotice[0], 0, "A Hydra invadiu Atlans");
		func.MakeNoticeMsg(&pNotice[1], 0, "Procure-a e ganhe recompensas!");


		for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
		{
			if (gObj[i].Connected == 3)
			{
				DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
				DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
			}
		}

		Sleep(Hydra._Duration);

		Hydra.DisappearMonster();

		if (Hydra._Alive == true)
		{
			func.MakeNoticeMsg(&pNotice[0], 0, "A Hydra desapareceu! Para onde será que ela foi?");
			func.MakeNoticeMsg(&pNotice[1], 0, "Tente novamente na próxima vez.");

			for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
			{
				if (gObj[i].Connected == 3)
				{
					DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
					DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
				}
			}

		}
	}
}

void cHydra::DisappearMonster()
{
	for (int Index = 0; Index < OBJ_MAXMONSTER; Index++)
	{
		if (gObj[Index].Class == 49)
		{
			gObjDel(Index); 
		}
	}

	int MobCount = *(DWORD*)(MonsterCount);
	MobCount--;
}

void cHydra::Dropitem(int aIndex)
{
	char Buffer[60];
	PMSG_NOTICE pNotice[2];

	sprintf_s(Buffer, "%s matou a Hydra!", gObj[aIndex].Name);
	func.MakeNoticeMsg(&pNotice[0], 0, Buffer);	

	sprintf_s(Buffer, "Localização: Atlans %02d/%02d", gObj[aIndex].X,gObj[aIndex].Y);									
	func.MakeNoticeMsg(&pNotice[1], 0, Buffer);

	for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if (gObj[i].Connected == 3)
		{
			DataSend(i, (LPBYTE)&pNotice[0], pNotice[0].h.size);
			DataSend(i, (LPBYTE)&pNotice[1], pNotice[1].h.size);
		}
	}

	int itemSorteado = rand() % this->_Count;

	DWORD Item = ITEMGET(HydraDrop[itemSorteado].ItemType,HydraDrop[itemSorteado].ItemIndex);
	ItemSerialCreateSend(aIndex,gObj[aIndex].MapNumber,gObj[aIndex].X, gObj[aIndex].Y,Item,HydraDrop[itemSorteado].ItemLevel,HydraDrop[itemSorteado].ItemDur,HydraDrop[itemSorteado].ItemSkill,HydraDrop[itemSorteado].ItemLuck,HydraDrop[itemSorteado].ItemOpt,aIndex,HydraDrop[itemSorteado].ItemExc,0);
}

cHydra Hydra;