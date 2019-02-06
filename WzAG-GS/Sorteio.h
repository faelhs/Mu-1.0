#ifndef _LOTTERY_H
#define _LOTTERY_H
// ---
struct CLottery_Data
{
	int Enabled;
	int Time;
	int iType;
	int pRecv[1000];
	// ---
	int Gold;
	int Cash;
	int LevelUpPoints;
	int Level;
	int Zen;
	//--
	std::string TableGold;
	std::string TableCash;
};
// ---
class CLottery
{
public:
	void Load();
	static void TimeTick(LPVOID lpTime);
	void Init();
	// ---
	CLottery_Data m_Data;
};
// ---
extern CLottery gLottery;
// ---
#endif