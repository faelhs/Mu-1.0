#pragma once

#define DROP_EVENT_MAX	256


class cDropEvent
{
public:
	int Enable;
	int ItemCount;

	void LoadConfigs();
	void LoadFile();
	void StartEvent();
	void TickTime();

	struct
	{
		int Index;
		int Type;
		int Level;
		int Durabilidade;
		int Skill;
		int Luck;
		int Opt;
		int Exl;
	}Item[DROP_EVENT_MAX];

	struct 
	{
		int Hour;
		int Min;
	}Time[DROP_EVENT_MAX];

	struct  
	{
		int Map;
		int X;
		int Y;
	}Cord[100];

	int Count[5];
};
extern cDropEvent DropEvent;

void EventLoad();
void EventTimeTick(void);
