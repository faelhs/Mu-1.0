#include "StdAfx.h"


CMagicInf DefMagicInf[256];

CMagicInf::CMagicInf()
{
	this->Clear();
}

CMagicInf::~CMagicInf()
{
	this->m_DamageMin  = 0;
	this->m_DamageMax  = 0;
}

void CMagicInf::Clear()
{
	this->m_Skill  = 0xFF;
	this->m_Level  = 0;
}

BOOL CMagicInf::IsMagic()
{
	if ( this->m_Skill == 0xFF )
	{
		return false;
	}
	return true;
}

int GetSkillNumberInex(int type, int Index, int level) 
{
	int skillnumber = -1;

	if ( type == 15 )
	{
		if ( Index >= 0 && Index < 16 )
		{
			skillnumber = Index + 1;
		}
		else if ( Index == 16 )
		{
			skillnumber = 38;
		}
		else if ( Index == 17 )
		{
			skillnumber = 39;
		}
		else if ( Index == 18 )
		{
			skillnumber = 40;
		}
		else if ( Index == 19 )
		{
			skillnumber = 215;
		}
		else if ( Index == 20 )
		{
			skillnumber = 214;
		}
		else if ( Index == 21 )
		{
			skillnumber = 230; //lightning shock
		}
		else if ( Index == 22 )
		{
			skillnumber = 217;
		}
		else if ( Index == 23 )
		{
			skillnumber = 218; //berserker
		}
		else if ( Index == 24 )
		{
			skillnumber = 219;
		}
		else if ( Index == 25 )
		{
			skillnumber = 220;
		}
		else if ( Index == 26 )
		{
			skillnumber = 221;
		}
		else if ( Index == 27 )
		{
			skillnumber = 222;
		}
		//s4
		else if ( Index == 28 )
		{
			skillnumber = 233;
		}
		else if ( Index == 29 )
		{
			skillnumber = 237;
		}
	}
	else if ( type == 12 )
	{
		switch ( Index )
		{
			case 7:		skillnumber = 41;	break;
			case 8:		skillnumber = 26;	break;
			case 9:		skillnumber = 27;	break;
			case 10:	skillnumber = 28;	break;
			case 12:	skillnumber = 42;	break;
			case 13:	skillnumber = 47;	break;
			case 14:	skillnumber = 48;	break;
			case 19:	skillnumber = 43;	break;
			case 17:	skillnumber = 52;	break;
			case 18:	skillnumber = 51;	break;
			case 16:	skillnumber = 55;	break;
			case 21:	skillnumber = 61;	break;
			case 22:	skillnumber = 63;	break;
			case 23:	skillnumber = 64;	break;
			case 24:	skillnumber = 65;	break;
			case 11:	skillnumber = level + 30;	break;
			case 35:	skillnumber = 78;	break;
			//
			case 44: skillnumber = 232; break;
			case 45: skillnumber = 235; break;
			case 46: skillnumber = 234; break;
			case 47: skillnumber = 236; break;
			case 48: skillnumber = 238; break;
		}
	}
	return skillnumber;
}

int CMagicInf::Set(BYTE aType, BYTE aIndex, BYTE aLevel)
{
	if ( this->m_Skill != 0xFF )
	{
		return -1;
	}

	this->m_Level = aLevel;
	this->m_Skill = GetSkillNumberInex(aType, aIndex, aLevel);
	
	if ( this->m_Skill < 0 )
	{
		this->m_Skill = 1;
	}

	int damage = 1;
	this->m_DamageMin = damage;
	this->m_DamageMax = damage + damage/2;

	return this->m_Skill;
}

int CMagicInf::GetDamage()
{
	int damage = 0;

	if ( this->m_Skill == 0xFF )
	{
		return 0;
	}

	int subd = this->m_DamageMax - this->m_DamageMin;

	__try
	{
		damage = this->m_DamageMin + (rand() % 1);
	}
	__except(subd=1,1)
	{

	}

	return damage;
}

int CMagicInf::Set(int aSkill, BYTE aLevel)
{
	if ( this->m_Skill != 0xFF )
	{
		return -1;
	}

	this->m_Skill = aSkill;
	this->m_Level = aLevel;
    int damage = 1;
	this->m_DamageMin = damage;
	this->m_DamageMax = damage + damage/2;

	return this->m_Skill;
}

CMagicInf * gObjGetMagicSearch(LPOBJ lpObj, WORD skillnumber)
{
	for(int n=0; n < MAGIC_SIZE;n++)
	{
		if(lpObj->Magic[n].IsMagic() == 1)
		{
			if(lpObj->Magic[n].m_Skill == skillnumber || lpObj->Magic[n].m_Skill == lpObj->m_Index )
			{
				return &lpObj->Magic[n];
			}
		}
	}
	return 0;
}

void MagicByteConvert(LPBYTE buf, CMagicInf* const Magici, int maxmagic) //00490F10
{
	int n=0; 

	int loc2;
	int loc3;
	int loc4;

	for (int index = 0;index < maxmagic;index++)
	{
		loc3 = Magici[index].m_Skill;
		loc2 = 0;
		loc4 = 0;

		if((int)Magici[index].m_Skill > 765)
		{
			loc3 = 0xFF;
			loc2 = 3;
			loc4 = Magici[index].m_Skill - (loc3 * 3);
		}
		else if((int)Magici[index].m_Skill > 510)
		{
			loc3 = 0xFF;
			loc2 = 2;
			loc4 = Magici[index].m_Skill - (loc3 << 1);
		}
		else if((int)Magici[index].m_Skill > 255)
		{
			loc3 = 0xFF;
			loc2 = 1;
			loc4 = Magici[index].m_Skill - loc3;
		}

		buf[n] = loc3; //Skill
		n++;

		buf[n] = Magici[index].m_Level << 3;
		buf[n] |= loc2 & 0x07; //Season3 add-on
		n++;

		buf[n] = loc4; //Skill :|
		n++;
	}
}


