#pragma once

//----------------------------------------------------------------------------------------//
//struct
struct _DROP_CHAOS
{
	BYTE index[6];
	BYTE id[6];
	BYTE level[6];
	BYTE skill[6];
	BYTE luck[6];
	BYTE addopt[6];
	BYTE addoptex[6];
	BYTE addoptanc[6];
};

//----------------------------------------------------------------------------------------//
class _chaos_castle
{
public:
	//----------- variavel
	int chaos[6];
	//----------- struct
	_DROP_CHAOS drop[255];
	//----------- configurações
	void _iniciar_chaos_castle(char * filename);
	//----------- funções
	void _chaos_drop(LPOBJ lpObj, char vector);

private:
	void _reload();
};

//----------------------------------------------------------------------------------------//
//extern
extern _chaos_castle _chaos;

//----------------------------------------------------------------------------------------//
//hook original função
void _chaos_castle_hook(int iChaosCastleIndex, int iWinnerIndex);