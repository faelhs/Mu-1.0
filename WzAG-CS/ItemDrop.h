#ifndef _MAPDROPRATE_H
#define _MAPDROPRATE_H

class MAPDROPRATE
{

public:
	BYTE	Tipo;
	INT		Index;
	BYTE	Mapa;
	INT		Mob;
	BYTE	Level;
	BYTE	Opcao;
	BYTE	Luck;
	BYTE	Skill;
	BYTE	Durabilidade;
	BYTE	Excelente;
	BYTE	Ancient;
	DWORD	Rate;

};
extern MAPDROPRATE MapDropItens[255];

bool ConfigMapDropRate();
static int MapDropRateMonster(OBJECTSTRUCT * lpMonster, OBJECTSTRUCT * lpObject);
void CarregarMapDropRate();





#endif
