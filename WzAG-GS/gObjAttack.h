#ifndef _GOBJATTACK_H
#define _GOBJATTACK_H

struct GOBJATTACK
{
	int A_NonPK;
	int A_NonGM;
	int A_AltoReset;
	int A_Attack;

	int A_Lorencia;
	int A_Dungeon;
	int A_Davias;
	int A_Noria;
	int A_LostTower;
	int A_Stadium;
	int A_Atlans;
	int A_Tarkan;
	int A_Icarus;

	int A_New17;
	int A_New18;
	int A_New19;
	int A_New20;
	int A_New21;
	int A_New22;
	int A_New23;
	int A_New24;

};
extern GOBJATTACK  pObjAttack;

void ReadygObjAttack();
void AttackConfigs();
bool gObjAttackEX(OBJECTSTRUCT* lpObj, OBJECTSTRUCT* lpTargetObj, void * lpMagic, BOOL magicsend, BYTE MSBFlag, int AttackDamage);


#endif#pragma once
