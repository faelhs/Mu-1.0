#pragma once

struct VAngle
{
	float X;
	float Y;
	float Z;
};

struct HEALTH_BAR
{
	short Index;
	BYTE Rate;
};

class cHealthBar
{
public:
	void ClearNewHealthBar();
	void InsertNewHealthBar(short Index, BYTE Rate);
	HEALTH_BAR* GetNewHealthBar(short Index);
	static void DrawHealthBar();
	static void DrawHealthBarOri();
};

extern cHealthBar HPBar;