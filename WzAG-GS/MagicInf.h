#pragma once

#define MAX_MAGIC_INFO	1
#define MAGIC_SIZE 60

class CMagicInf
{
public:

	CMagicInf();
	virtual ~CMagicInf();
	
	int IsMagic();
	void Clear();
	
	int Set(BYTE aType, BYTE aIndex, BYTE aLevel);

	int GetDamage();

	int Set(int aSkill, BYTE aLevel);
	
	
	CMagicInf & operator = (CMagicInf const & __that)
	{
		this->m_Level = __that.m_Level;
		this->m_Skill = __that.m_Skill;
		this->m_DamageMin = __that.m_DamageMin;
		this->m_DamageMax = __that.m_DamageMax;

		return *this;
	};

public:

	BYTE m_Level;
	int m_Skill;
	int m_DamageMin;
	int m_DamageMax;

};

extern CMagicInf DefMagicInf[];
extern CMagicInf * gObjGetMagicSearch(LPOBJ lpObj, WORD skillnumber);