#include "StdAfx.h"

//----------------------------------------------------------------------------------------//
_chaos_castle _chaos;

//----------------------------------------------------------------------------------------//
//reload
void _chaos_castle::_reload()
{
   for(int i = 0; i < 6; i++)
   {
       _chaos.chaos[i] = 0;
   }
   memset(_chaos.drop, 0, sizeof(_chaos.drop));
}

//----------------------------------------------------------------------------------------//
//configuração
void _chaos_castle::_iniciar_chaos_castle(char * filename)
{

	this->_reload();

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(filename), group);

	if(group.GetSection(0, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_chaos.drop[_chaos.chaos[0]].index[0]         = section.Rows[i].GetInt(0);
			_chaos.drop[_chaos.chaos[0]].id[0]            = section.Rows[i].GetInt(1);
			_chaos.drop[_chaos.chaos[0]].level[0]         = section.Rows[i].GetInt(2);
			_chaos.drop[_chaos.chaos[0]].skill[0]         = section.Rows[i].GetInt(3);
			_chaos.drop[_chaos.chaos[0]].luck[0]          = section.Rows[i].GetInt(4);
			_chaos.drop[_chaos.chaos[0]].addopt[0]        = section.Rows[i].GetInt(5);
			_chaos.drop[_chaos.chaos[0]].addoptex[0]      = section.Rows[i].GetInt(6);
			_chaos.drop[_chaos.chaos[0]].addoptanc[0]     = section.Rows[i].GetInt(7);
			_chaos.chaos[0]++;
		}
	}

	if(group.GetSection(1, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_chaos.drop[_chaos.chaos[1]].index[1]         = section.Rows[i].GetInt(0);
			_chaos.drop[_chaos.chaos[1]].id[1]            = section.Rows[i].GetInt(1);
			_chaos.drop[_chaos.chaos[1]].level[1]         = section.Rows[i].GetInt(2);
			_chaos.drop[_chaos.chaos[1]].skill[1]         = section.Rows[i].GetInt(3);
			_chaos.drop[_chaos.chaos[1]].luck[1]          = section.Rows[i].GetInt(4);
			_chaos.drop[_chaos.chaos[1]].addopt[1]        = section.Rows[i].GetInt(5);
			_chaos.drop[_chaos.chaos[1]].addoptex[1]      = section.Rows[i].GetInt(6);
			_chaos.drop[_chaos.chaos[1]].addoptanc[1]     = section.Rows[i].GetInt(7);
			_chaos.chaos[1]++;
		}
	}

	if(group.GetSection(2, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_chaos.drop[_chaos.chaos[2]].index[2]         = section.Rows[i].GetInt(0);
			_chaos.drop[_chaos.chaos[2]].id[2]            = section.Rows[i].GetInt(1);
			_chaos.drop[_chaos.chaos[2]].level[2]         = section.Rows[i].GetInt(2);
			_chaos.drop[_chaos.chaos[2]].skill[2]         = section.Rows[i].GetInt(3);
			_chaos.drop[_chaos.chaos[2]].luck[2]          = section.Rows[i].GetInt(4);
			_chaos.drop[_chaos.chaos[2]].addopt[2]        = section.Rows[i].GetInt(5);
			_chaos.drop[_chaos.chaos[2]].addoptex[2]      = section.Rows[i].GetInt(6);
			_chaos.drop[_chaos.chaos[2]].addoptanc[2]     = section.Rows[i].GetInt(7);
			_chaos.chaos[2]++;
		}
	}

	if(group.GetSection(3, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_chaos.drop[_chaos.chaos[3]].index[3]         = section.Rows[i].GetInt(0);
			_chaos.drop[_chaos.chaos[3]].id[3]            = section.Rows[i].GetInt(1);
			_chaos.drop[_chaos.chaos[3]].level[3]         = section.Rows[i].GetInt(2);
			_chaos.drop[_chaos.chaos[3]].skill[3]         = section.Rows[i].GetInt(3);
			_chaos.drop[_chaos.chaos[3]].luck[3]          = section.Rows[i].GetInt(4);
			_chaos.drop[_chaos.chaos[3]].addopt[3]        = section.Rows[i].GetInt(5);
			_chaos.drop[_chaos.chaos[3]].addoptex[3]      = section.Rows[i].GetInt(6);
			_chaos.drop[_chaos.chaos[3]].addoptanc[3]     = section.Rows[i].GetInt(7);
			_chaos.chaos[3]++;
		}
	}

	if(group.GetSection(4, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_chaos.drop[_chaos.chaos[4]].index[4]         = section.Rows[i].GetInt(0);
			_chaos.drop[_chaos.chaos[4]].id[4]            = section.Rows[i].GetInt(1);
			_chaos.drop[_chaos.chaos[4]].level[4]         = section.Rows[i].GetInt(2);
			_chaos.drop[_chaos.chaos[4]].skill[4]         = section.Rows[i].GetInt(3);
			_chaos.drop[_chaos.chaos[4]].luck[4]          = section.Rows[i].GetInt(4);
			_chaos.drop[_chaos.chaos[4]].addopt[4]        = section.Rows[i].GetInt(5);
			_chaos.drop[_chaos.chaos[4]].addoptex[4]      = section.Rows[i].GetInt(6);
			_chaos.drop[_chaos.chaos[4]].addoptanc[4]     = section.Rows[i].GetInt(7);
			_chaos.chaos[4]++;
		}
	}

	if(group.GetSection(5, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_chaos.drop[_chaos.chaos[5]].index[5]         = section.Rows[i].GetInt(0);
			_chaos.drop[_chaos.chaos[5]].id[5]            = section.Rows[i].GetInt(1);
			_chaos.drop[_chaos.chaos[5]].level[5]         = section.Rows[i].GetInt(2);
			_chaos.drop[_chaos.chaos[5]].skill[5]         = section.Rows[i].GetInt(3);
			_chaos.drop[_chaos.chaos[5]].luck[5]          = section.Rows[i].GetInt(4);
			_chaos.drop[_chaos.chaos[5]].addopt[5]        = section.Rows[i].GetInt(5);
			_chaos.drop[_chaos.chaos[5]].addoptex[5]      = section.Rows[i].GetInt(6);
			_chaos.drop[_chaos.chaos[5]].addoptanc[5]     = section.Rows[i].GetInt(7);
			_chaos.chaos[5]++;
		}
	}
	//----------- gera um log final
	//console.gerar_cole(".dll-> %s iniciado.",filename);
}

//----------------------------------------------------------------------------------------//
//função de drops
void _chaos_castle::_chaos_drop(LPOBJ lpObj, char vector)
{
	for(int i = 0; i < _chaos.chaos[vector]; i++)
	{
		int item = ItemGetNumberMake(_chaos.drop[i].index[vector],_chaos.drop[i].id[vector]);
		ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,item,_chaos.drop[i].level[vector],0,_chaos.drop[i].skill[vector],_chaos.drop[i].luck[vector],_chaos.drop[i].addopt[vector],lpObj->m_Index,_chaos.drop[i].addoptex[vector],_chaos.drop[i].addoptanc[vector]);
	}
}

//----------------------------------------------------------------------------------------//
//função original modificada
void _chaos_castle_hook(int iChaosCastleIndex, int iWinnerIndex)
{
    OBJECTSTRUCT* lpObj01 = (OBJECTSTRUCT*)OBJECT_POINTER(iChaosCastleIndex);
	OBJECTSTRUCT* lpObj02 = (OBJECTSTRUCT*)OBJECT_POINTER(iWinnerIndex);

	/*if(gObj[aIndex].Connected == 0)
	{
	  return;
	}*/

	switch(lpObj02->MapNumber)
	{
	case 18:
		_chaos._chaos_drop(lpObj02,0);
		//console.gerar_cole(".dll-> chaos castle [1] drops sucesso");
		break;
	case 19:
		_chaos._chaos_drop(lpObj02,1);
		//console.gerar_cole(".dll-> chaos castle [2] drops sucesso");
		break;
	case 20:
		_chaos._chaos_drop(lpObj02,2);
		//console.gerar_cole(".dll-> chaos castle [3] drops sucesso");
		break;
	case 21:
		_chaos._chaos_drop(lpObj02,3);
		//console.gerar_cole(".dll-> chaos castle [4] drops sucesso");
		break;
	case 22:
		_chaos._chaos_drop(lpObj02,4);
		//console.gerar_cole(".dll-> chaos castle [5] drops sucesso");
		break;
	case 23:
		_chaos._chaos_drop(lpObj02,5);
		break;
	default:
		break;
	}
}