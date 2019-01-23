#pragma once
class cSorteio
{
public:
	bool Load();
	void premio();
	void Config();
	int randomGen(int x, int y);
	static void Run(void * lpParam);
private:
	int PlayerCount;
	char* _AccountPlayer[1000];
	char* _NamePlayer[1000];
	int _Tempo;
	int _Golds;
	DWORD _Time;
};
extern cSorteio Sorteio;