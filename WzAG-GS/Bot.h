#pragma once
class ObjBot
{
public:
	void MakeBot(char* name, int map, int x, int y, int dir);
	bool CallPet(int aIndex, int pet, int x, int y);
};
extern ObjBot Bot;
