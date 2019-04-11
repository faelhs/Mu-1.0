#include  "StdAfx.h"

MAPDROPRATE DropItens[255];
DWORD MapContadorDrops;

void CarregarMapDropRate()
{
	ConfigMapDropRate();
	func.HookThis((DWORD)&MapDropRateMonster, 0x004046CE);
	func.HookThis((DWORD)&DropManager,0x0040107D);
}

bool ConfigMapDropRate()
{
	Tokenizer			token;
	TokenizerGroup		Class;
	TokenizerSection	Section;

	token.ParseFile(std::string(CFG_DROP), Class);
	if (Class.GetSection(0, Section))
	{
		MapContadorDrops = Section.RowCount;
		for (int i = 0; i < Section.RowCount; i++)
		{
			DropItens[i].Tipo = Section.Rows[i].GetInt(0);
			DropItens[i].Index = Section.Rows[i].GetInt(1);
			DropItens[i].Mapa = Section.Rows[i].GetInt(2);
			DropItens[i].Mob = Section.Rows[i].GetInt(3);
			DropItens[i].Level = Section.Rows[i].GetInt(4);
			DropItens[i].Luck = Section.Rows[i].GetInt(5);
			DropItens[i].Skill = Section.Rows[i].GetInt(6);
			DropItens[i].Opcao = Section.Rows[i].GetInt(7);
			DropItens[i].Durabilidade = Section.Rows[i].GetInt(8);
			DropItens[i].Excelente = Section.Rows[i].GetInt(9);
			DropItens[i].Ancient = Section.Rows[i].GetInt(10);
			DropItens[i].Rate = Section.Rows[i].GetInt(11);
		}
	}
	return true;
}

int MapDropRateMonster(OBJECTSTRUCT * lpMonster, OBJECTSTRUCT * lpObject)
{												
	for (int i = 0; i < MapContadorDrops; i++)
	{
		if(DropItens[i].Level > 99){if(rand() % 100 < 3){DropItens[i].Level = rand() % 4;}}
		if(DropItens[i].Luck > 99){if(rand() % 100 < 3){DropItens[i].Level = 1;}}
		if(DropItens[i].Skill > 99){if(rand() % 100 < 3){DropItens[i].Level = 1;}}
		if(DropItens[i].Opcao > 99){if(rand() % 100 < 3){DropItens[i].Level = rand() % 8;}}
		if(DropItens[i].Excelente > 99){if(rand() % 100 < 2){DropItens[i].Level = rand() % 32;}}
		if(DropItens[i].Ancient > 99){if(rand() % 100 < 2){DropItens[i].Level = rand() % 6;}}
		
		if(lpMonster->MapNumber == DropItens[i].Mapa && lpMonster->Class == DropItens[i].Mob) //ok
		{
			if ( DropItens[i].Rate == 10000)
			{
				DWORD Item		= ITEMGET(DropItens[i].Tipo, DropItens[i].Index);
				DWORD Damage	= gObjMonsterTopHitDamageUser(lpMonster);
				ItemSerialCreateSend(lpMonster->m_Index,(DWORD)lpMonster->MapNumber,(DWORD)lpMonster->X, (DWORD)lpObject->Y, Item, DropItens[i].Level, (DWORD)DropItens[i].Luck, (DWORD)DropItens[i].Skill, (DWORD)DropItens[i].Durabilidade, (DWORD)DropItens[i].Opcao,Damage, (DWORD)DropItens[i].Excelente, (DWORD)DropItens[i].Ancient);	
			}
			if (rand() % 10000 < DropItens[i].Rate)
			{
				DWORD Item		= ITEMGET(DropItens[i].Tipo, DropItens[i].Index);
				DWORD Damage	= gObjMonsterTopHitDamageUser(lpMonster);
				ItemSerialCreateSend(lpMonster->m_Index,(DWORD)lpMonster->MapNumber,(DWORD)lpMonster->X, (DWORD)lpObject->Y, Item, DropItens[i].Level, (DWORD)DropItens[i].Luck, (DWORD)DropItens[i].Skill, (DWORD)DropItens[i].Durabilidade, (DWORD)DropItens[i].Opcao,Damage, (DWORD)DropItens[i].Excelente, (DWORD)DropItens[i].Ancient);	
			}
		}
		if(lpMonster->MapNumber == DropItens[i].Mapa && DropItens[i].Mob < 0 ) // ok
		{
			if (DropItens[i].Rate == 10000)
			{
				DWORD Item		= ITEMGET(DropItens[i].Tipo, DropItens[i].Index);
				DWORD Damage	= gObjMonsterTopHitDamageUser(lpMonster);
				ItemSerialCreateSend(lpMonster->m_Index,(DWORD)lpMonster->MapNumber,(DWORD)lpMonster->X, (DWORD)lpObject->Y, Item, DropItens[i].Level, (DWORD)DropItens[i].Luck, (DWORD)DropItens[i].Skill, (DWORD)DropItens[i].Durabilidade, (DWORD)DropItens[i].Opcao,Damage, (DWORD)DropItens[i].Excelente, (DWORD)DropItens[i].Ancient);	
			}
			if (rand() % 10000 < DropItens[i].Rate)
			{
				DWORD Item		= ITEMGET(DropItens[i].Tipo, DropItens[i].Index);
				DWORD Damage	= gObjMonsterTopHitDamageUser(lpMonster);
				ItemSerialCreateSend(lpMonster->m_Index,(DWORD)lpMonster->MapNumber,(DWORD)lpMonster->X, (DWORD)lpObject->Y, Item, DropItens[i].Level, (DWORD)DropItens[i].Luck, (DWORD)DropItens[i].Skill, (DWORD)DropItens[i].Durabilidade, (DWORD)DropItens[i].Opcao,Damage, (DWORD)DropItens[i].Excelente, (DWORD)DropItens[i].Ancient);	
			}
		}
		if(lpMonster->Class == DropItens[i].Mob && DropItens[i].Mapa == 255 ) //ok
		{
			if (DropItens[i].Rate == 10000)
			{
				DWORD Item		= ITEMGET(DropItens[i].Tipo, DropItens[i].Index);
				DWORD Damage	= gObjMonsterTopHitDamageUser(lpMonster);
				ItemSerialCreateSend(lpMonster->m_Index,(DWORD)lpMonster->MapNumber,(DWORD)lpMonster->X, (DWORD)lpObject->Y, Item, DropItens[i].Level, (DWORD)DropItens[i].Luck, (DWORD)DropItens[i].Skill, (DWORD)DropItens[i].Durabilidade, (DWORD)DropItens[i].Opcao,Damage, (DWORD)DropItens[i].Excelente, (DWORD)DropItens[i].Ancient);	
			}
			if (rand() % 10000 < DropItens[i].Rate)
			{
				DWORD Item		= ITEMGET(DropItens[i].Tipo, DropItens[i].Index);
				DWORD Damage	= gObjMonsterTopHitDamageUser(lpMonster);
			    ItemSerialCreateSend(lpMonster->m_Index,(DWORD)lpMonster->MapNumber,(DWORD)lpMonster->X, (DWORD)lpObject->Y, Item, DropItens[i].Level, (DWORD)DropItens[i].Luck, (DWORD)DropItens[i].Skill, (DWORD)DropItens[i].Durabilidade, (DWORD)DropItens[i].Opcao,Damage, (DWORD)DropItens[i].Excelente, (DWORD)DropItens[i].Ancient);	
			}
		}
		if(DropItens[i].Mapa == 255  && DropItens[i].Mob < 0 )
		{
			if (DropItens[i].Rate == 10000)
			{
				DWORD Item		= ITEMGET(DropItens[i].Tipo, DropItens[i].Index);
				DWORD Damage	= gObjMonsterTopHitDamageUser(lpMonster);
				func.ItemSerialCreateSendEx(lpMonster->m_Index,(DWORD)lpMonster->MapNumber,(DWORD)lpMonster->X, (DWORD)lpObject->Y, Item, DropItens[i].Level, (DWORD)DropItens[i].Luck, (DWORD)DropItens[i].Skill, (DWORD)DropItens[i].Durabilidade, (DWORD)DropItens[i].Opcao,Damage, (DWORD)DropItens[i].Excelente, (DWORD)DropItens[i].Ancient);	
			}
			if (rand() % 10000 < DropItens[i].Rate)
			{
				DWORD Item		= ITEMGET(DropItens[i].Tipo, DropItens[i].Index);
				DWORD Damage	= gObjMonsterTopHitDamageUser(lpMonster);
				func.ItemSerialCreateSendEx(lpMonster->m_Index,(DWORD)lpMonster->MapNumber,(DWORD)lpMonster->X, (DWORD)lpObject->Y, Item, DropItens[i].Level, (DWORD)DropItens[i].Luck, (DWORD)DropItens[i].Skill, (DWORD)DropItens[i].Durabilidade, (DWORD)DropItens[i].Opcao,Damage, (DWORD)DropItens[i].Excelente, (DWORD)DropItens[i].Ancient);	
			}
		}
		
	}
	return gEventMonsterItemDropOri(lpMonster, lpObject);
}

void __cdecl DropManager(OBJECTSTRUCT *lpObj, OBJECTSTRUCT *lpTargetObj)
{
	// Zen Drop
	if(lpObj->Money > 0)
    {
		DWORD SubMoney = 0;

		if(lpObj->Level > 10 && lpObj->Level <= 99)
		{
			SubMoney = (DWORD)(lpObj->Money) / 100;
		}
		else if(lpObj->Level >= 100 && lpObj->Level <= 199)
		{
			SubMoney = (DWORD)(lpObj->Money * 2) / 100;
		}
		else if(lpObj->Level > 200)
		{
			SubMoney = (DWORD)(lpObj->Money * 3) / 100;
		}

		lpObj->Money = (lpObj->Money - SubMoney) * 0.3;
	}

	// Original function
	gObjMonsterDieGiveItem(lpObj, lpTargetObj);
}