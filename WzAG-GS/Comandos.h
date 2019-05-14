//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 99.60T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#pragma once
class Commands
{
public:
	bool Load();
	bool ChatRecv(PMSG_CHATDATA * lpMsg, int aIndex);
	void Post(int aIndex, char* msg);
	void Adicionar(int aIndex, LPCSTR Buffer, int Status);
	void ReAdicionar(int aIndex);
	void Clear(int aIndex);
	void Ware(int aIndex, LPCSTR Buffer);
	void Money(int aIndex, char * msg);
	void Online (int aIndex);
	void Evo(int aIndex,char * msg);
	void Premiar(int aIndex, char* msg);
	void MoveAll(int aIndex, char* msg);
	void Skin(int aIndex, char* msg);
	void Move(int aIndex, char* msg);
	void Visible(int aIndex, LPCSTR IpBuffer, BYTE BuffCode);
	void OpenWare(int aIndex);
	void Drop(int aIndex,char * msg);
	void Classe(unsigned short aIndex, char * String, BYTE Tipo);
	void StormCommand(int aIndex);
	void Reload(int aIndex, char * msg);
	void SetLevel(int aIndex, char * msg);
	void SetPts(int aIndex, char * msg, int Status);
	void MakeSet(int aIndex, char* msg);
	void Comprar(int aIndex, char* msg);
	void Listar(int aIndex, char* msg);
	int calcset(char* setname);
	void Make(int aIndex, char * msg);
	void Spawn(int aIndex, char * msg);
	void Pet(int aIndex, char * msg);
	void mBot(int aIndex, char * msg);
	void SetQuest(int aIndex, char * msg);
	void makecomprar(int aIndex, char * msg, char * itemname);
	void FakeName(int aIndex, char name[11]);
	void ChangeName(int aIndex, char name[11]);
	void ClearInvCommand(int aIndex, char* IpBuffer);
	void OpenCashShopCommand(int aIndex, char* msg);
	void QuestInfo(int aIndex);
	void Ping(int aIndex);
	void GoQuest(int aIndex);
	void Goto(int aIndex, char * msg);
	void Recall(int aIndex, char * msg);
	void Jail(int aIndex, char * msg,int type);
	void Dice(int aIndex);
	void ComandoSortear(int aIndex);
	void EventStart(int aIndex, char * msg); 
		
private:
	bool					_Active[50];
	int					    _Level[25];
	int					    _Zen[25];
	int						_Gold[25];
	int					    _Color;
	int					    _Delay;
	int					    _Vip[10];
	int					    _Ware[6];
	int                     _Number;
	char					_Syntax[100][50];
	char					_Formato[50];
	char                    _Notice[60];
	char					_QueryComprar[255];
	char					_QueryVerificar[255];
	char					_vipname[6][25];
	char					_Query[255];
	bool					_OnlyGM[25];
	enum sets {
		dragon = 1,
		pad = 2,
		legendary = 3,
		bone = 4,
		leather = 5,
		scale = 6,
		sphinx = 7,
		brass = 8,
		plate = 9,
		vine = 10,
		silk = 11,
		wind = 12,
		spirit = 13,
		guardian = 14,
		stormcrow = 15,
		blackdragon = 16,
		darkphoenix = 17,
		grandsoul = 18,
		divine = 19,
		thunderkawk = 20,
		greatdragon = 21,
		darksoul = 22,
		huricane = 23,
		redspirit = 24,
		lightplate = 25,
		adamantine = 26,
		darksteel = 27,
		darkmaster = 28,
		dragonknight = 29,
		venonmist = 30,
		phoenixlord = 31

	};

};

extern Commands Command;