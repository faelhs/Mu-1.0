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
	short gen;
	short qqtd;
	short qcnt;
	short qtip;

};
struct QUESTS {
	short Index;
	short qqtd;
	short qcnt;
	short qtip;
};
class cHealthBar
{
public:
	GLuint loadBMP_custom(const char * imagepath);
	void ClearNewHealthBar();
	void ClearNewQuests();
	void InsertNewHealthBar(short Index, BYTE Rate, short gen, short qqnt, short qcnt, short qtip);
	void GetQuests(short Index, short qqnt, short qcnt, short qtip);
	HEALTH_BAR* GetNewHealthBar(short Index);
	QUESTS* GetNewQuests(short Index);
	static void DrawHealthBar();
	static void DrawHealthBarOri();
};

extern cHealthBar HPBar;