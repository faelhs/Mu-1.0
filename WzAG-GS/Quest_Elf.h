#pragma once
#pragma once

class Q_PGW_ELF
{
public:
	void Config();
	void Q_Load();
	void Q_Num();
	void Q_CreateStruct(int aIndex);
	void Q_NPC(int aIndex, int aNPC);
	void KilledMob(int aIndex);
	bool Presents(int aIndex, int Present, int Gifts);
	bool IsBadFileLine(char *FileLine, int &Flag);
	struct
	{
		int Mob;
		int Coun;
		int proc;
		int rew;
		int gift;
		int exp;
		int Zen;
		int lvl;
		int resets;
		int reqmap;
		int map;
		int x;
		int y;
		int teleport;
		char msg[100];
		char msg2[100];
		char msg3[100];
	}
	Number[1000];

	int Count;
};

extern Q_PGW_ELF Qest_PGW_ELF;
void ClickNPCElf(int aIndex, int aNPC);
