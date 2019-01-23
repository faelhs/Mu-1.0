#include "StdAfx.h"

_blood_castle _blood;


void _blood_castle::_reload()
{
   memset(_blood.drop, 0, sizeof(_blood.drop));
}

void _blood_castle::_iniciar_blood_castle(char * filename)
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
			_blood.drop[_blood.blood[0]].index[0]         = section.Rows[i].GetInt(0);
			_blood.drop[_blood.blood[0]].id[0]            = section.Rows[i].GetInt(1);
			_blood.drop[_blood.blood[0]].level[0]         = section.Rows[i].GetInt(2);
			_blood.drop[_blood.blood[0]].skill[0]         = section.Rows[i].GetInt(3);
			_blood.drop[_blood.blood[0]].luck[0]          = section.Rows[i].GetInt(4);
			_blood.drop[_blood.blood[0]].addopt[0]        = section.Rows[i].GetInt(5);
			_blood.drop[_blood.blood[0]].addoptex[0]      = section.Rows[i].GetInt(6);
			_blood.blood[0]++;
		}
	}

	if(group.GetSection(1, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_blood.drop[_blood.blood[1]].index[1]         = section.Rows[i].GetInt(0);
			_blood.drop[_blood.blood[1]].id[1]            = section.Rows[i].GetInt(1);
			_blood.drop[_blood.blood[1]].level[1]         = section.Rows[i].GetInt(2);
			_blood.drop[_blood.blood[1]].skill[1]         = section.Rows[i].GetInt(3);
			_blood.drop[_blood.blood[1]].luck[1]          = section.Rows[i].GetInt(4);
			_blood.drop[_blood.blood[1]].addopt[1]        = section.Rows[i].GetInt(5);
			_blood.drop[_blood.blood[1]].addoptex[1]      = section.Rows[i].GetInt(6);
			_blood.blood[1]++;
		}
	}

	if(group.GetSection(2, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_blood.drop[_blood.blood[2]].index[2]         = section.Rows[i].GetInt(0);
			_blood.drop[_blood.blood[2]].id[2]            = section.Rows[i].GetInt(1);
			_blood.drop[_blood.blood[2]].level[2]         = section.Rows[i].GetInt(2);
			_blood.drop[_blood.blood[2]].skill[2]         = section.Rows[i].GetInt(3);
			_blood.drop[_blood.blood[2]].luck[2]          = section.Rows[i].GetInt(4);
			_blood.drop[_blood.blood[2]].addopt[2]        = section.Rows[i].GetInt(5);
			_blood.drop[_blood.blood[2]].addoptex[2]      = section.Rows[i].GetInt(6);
			_blood.blood[2]++;
		}
	}

	if(group.GetSection(3, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_blood.drop[_blood.blood[3]].index[3]         = section.Rows[i].GetInt(0);
			_blood.drop[_blood.blood[3]].id[3]            = section.Rows[i].GetInt(1);
			_blood.drop[_blood.blood[3]].level[3]         = section.Rows[i].GetInt(2);
			_blood.drop[_blood.blood[3]].skill[3]         = section.Rows[i].GetInt(3);
			_blood.drop[_blood.blood[3]].luck[3]          = section.Rows[i].GetInt(4);
			_blood.drop[_blood.blood[3]].addopt[3]        = section.Rows[i].GetInt(5);
			_blood.drop[_blood.blood[3]].addoptex[3]      = section.Rows[i].GetInt(6);
			_blood.blood[3]++;
		}
	}

	if(group.GetSection(4, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_blood.drop[_blood.blood[4]].index[4]         = section.Rows[i].GetInt(0);
			_blood.drop[_blood.blood[4]].id[4]            = section.Rows[i].GetInt(1);
			_blood.drop[_blood.blood[4]].level[4]         = section.Rows[i].GetInt(2);
			_blood.drop[_blood.blood[4]].skill[4]         = section.Rows[i].GetInt(3);
			_blood.drop[_blood.blood[4]].luck[4]          = section.Rows[i].GetInt(4);
			_blood.drop[_blood.blood[4]].addopt[4]        = section.Rows[i].GetInt(5);
			_blood.drop[_blood.blood[4]].addoptex[4]      = section.Rows[i].GetInt(6);
			_blood.blood[4]++;
		}
	}

	if(group.GetSection(5, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_blood.drop[_blood.blood[5]].index[5]         = section.Rows[i].GetInt(0);
			_blood.drop[_blood.blood[5]].id[5]            = section.Rows[i].GetInt(1);
			_blood.drop[_blood.blood[5]].level[5]         = section.Rows[i].GetInt(2);
			_blood.drop[_blood.blood[5]].skill[5]         = section.Rows[i].GetInt(3);
			_blood.drop[_blood.blood[5]].luck[5]          = section.Rows[i].GetInt(4);
			_blood.drop[_blood.blood[5]].addopt[5]        = section.Rows[i].GetInt(5);
			_blood.drop[_blood.blood[5]].addoptex[5]      = section.Rows[i].GetInt(6);
			_blood.blood[5]++;
		}
	}

	if(group.GetSection(6, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_blood.drop[_blood.blood[6]].index[6]         = section.Rows[i].GetInt(0);
			_blood.drop[_blood.blood[6]].id[6]            = section.Rows[i].GetInt(1);
			_blood.drop[_blood.blood[6]].level[6]         = section.Rows[i].GetInt(2);
			_blood.drop[_blood.blood[6]].skill[6]         = section.Rows[i].GetInt(3);
			_blood.drop[_blood.blood[6]].luck[6]          = section.Rows[i].GetInt(4);
			_blood.drop[_blood.blood[6]].addopt[6]        = section.Rows[i].GetInt(5);
			_blood.drop[_blood.blood[6]].addoptex[6]      = section.Rows[i].GetInt(6);
			
			_blood.blood[6]++;
		}
	}
}

void _blood_castle::_blood_drop(LPOBJ lpObj, char vector)
{
	for(int i = 0; i < _blood.blood[vector]; i++)
	{
		int item = ItemGetNumberMake(_blood.drop[i].index[vector],_blood.drop[i].id[vector]);
		ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber + 227,lpObj->X,lpObj->Y,item,_blood.drop[i].level[vector],0,_blood.drop[i].skill[vector],_blood.drop[i].luck[vector],_blood.drop[i].addopt[vector],lpObj->m_Index,_blood.drop[i].addoptex[vector],0);
	}
}

void _blood_castle_hook(int aIndex)
{
    OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	switch(lpObj->MapNumber)
	{
	case 11:
		_blood._blood_drop(lpObj,0);
		break;
	case 12:
		_blood._blood_drop(lpObj,1);
		break;
	case 13:
		_blood._blood_drop(lpObj,2);
		break;
	case 14:
		_blood._blood_drop(lpObj,3);
		break;
	case 15:
		_blood._blood_drop(lpObj,4);
		break;
	case 16:
		_blood._blood_drop(lpObj,5);
		break;
	case 17:
		_blood._blood_drop(lpObj,6);
		break;
	default:

		break;
	}
}