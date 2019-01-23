#pragma once

struct _DROP_BLOOD
{
	BYTE index[7];
	BYTE id[7];
	BYTE level[7];
	BYTE skill[7];
	BYTE luck[7];
	BYTE addopt[7];
	BYTE addoptex[7];
};

class _blood_castle
{
public:
	int blood[7];
	_DROP_BLOOD drop[255];
	void _iniciar_blood_castle(char * filename);
	void _blood_drop(LPOBJ lpObj, char vector);

private:
	void _reload();
};

extern _blood_castle _blood;
void _blood_castle_hook(int aIndex);