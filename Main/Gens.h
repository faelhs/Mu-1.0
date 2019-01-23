#pragma once


struct GENS
{
	short Index;
	BYTE Rate;
	short gen;
};

class cGens
{
public:
	void ClearNewGensHealthBar();
	void InsertNewGensHealthBar(short Index, BYTE Rate, short gen);
	GENS* GetNewGensHealthBar(short Index);
	static void DrawGensHealthBar();
	static void DrawGensHealthBarOri();
};

extern cGens GensHPBar;