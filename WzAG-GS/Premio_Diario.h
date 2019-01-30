#pragma once

class Premio_Diario {
public:
	bool	load();
	void	LoadPremios();
	void	premiar(int aIndex);
	void	darpremio(int aIndex, int dia, char * date);
	int		valor[7];
	int		_Count[7];
	bool	_ativo;
	struct Data
	{
		int dia;
		int mes;
		int ano;
	};
	struct Premio_Dia {
		int dia;
		char * ultimo_recebido;
	};
	void ParseData(char str[11], Data *Alvo);
	struct DayPrize
	{
		int ItemType;
		int ItemIndex;
		int ItemLevel;
		int ItemLuck;
		int ItemSkill;
		int ItemDur;
		int ItemOpt;
		int ItemExc;
	};
	DayPrize Day[7][10];
};

extern Premio_Diario::Premio_Dia PremioDiario[7400];
extern Premio_Diario Pdiario;