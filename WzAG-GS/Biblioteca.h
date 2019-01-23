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

struct _PER_IO_CONTEXT
{
	/*<thisrel this+0x0>*/ /*|0x14|*/ struct _OVERLAPPED Overlapped;
	/*<thisrel this+0x14>*/ /*|0x8|*/ struct _WSABUF wsabuf;
	/*<thisrel this+0x1c>*/ /*|0x1770|*/ char Buffer[6000];
	/*<thisrel this+0x178c>*/ /*|0x1770|*/ char BufferSecond[6000];
	/*<thisrel this+0x2efc>*/ /*|0x4|*/ int nSecondOfs;
	/*<thisrel this+0x2f00>*/ /*|0x4|*/ int nTotalBytes;
	/*<thisrel this+0x2f04>*/ /*|0x4|*/ int nSentBytes;
	/*<thisrel this+0x2f08>*/ /*|0x4|*/ int IOOperation;
	/*<thisrel this+0x2f0c>*/ /*|0x4|*/ int nWaitIO;
};

struct _PER_SOCKET_CONTEXT
{
	/*<thisrel this+0x0>*/ /*|0x4|*/ unsigned int m_socket;
	/*<thisrel this+0x4>*/ /*|0x4|*/ int nIndex;
	/*<thisrel this+0x8>*/ /*|0x5e20|*/ _PER_IO_CONTEXT IOContext[2];
	/*<thisrel this+0x5e28>*/ /*|0x4|*/ int dwIOCount;
};

struct ComboSkillData
{
	/*<thisrel this+0x0>*/ /*|0x4|*/ unsigned long dwTime;
	/*<thisrel this+0x4>*/ /*|0x3|*/ unsigned char Skill[3];
	/*<thisrel this+0x8>*/ /*|0x4|*/ int ProgressIndex;
};

struct tagActionState
{
	/*<bitfield this+0x0>*/ /*|0x4|*/ unsigned long Rest:1;
	/*<bitfield this+0x0>*/ /*|0x4|*/ unsigned long Attack:1;
	/*<bitfield this+0x0>*/ /*|0x4|*/ unsigned long Move:1;
	/*<bitfield this+0x0>*/ /*|0x4|*/ unsigned long Escape:1;
	/*<bitfield this+0x0>*/ /*|0x4|*/ unsigned long Emotion:4;
	/*<bitfield this+0x0>*/ /*|0x4|*/ unsigned long EmotionCount:8;
};

struct _GUILD_INFO_STRUCT
{
	/*<thisrel this+0x0>*/ /*|0x4|*/ int Number;
	/*<thisrel this+0x4>*/ /*|0x9|*/ char Name[9];
	/*<thisrel this+0xd>*/ /*|0x20|*/ unsigned char Mark[32];
	/*<thisrel this+0x2d>*/ /*|0x1|*/ unsigned char Count;
	/*<thisrel this+0x2e>*/ /*|0x1|*/ unsigned char TotalCount;
	/*<thisrel this+0x2f>*/ /*|0x370|*/ char Names[80][11];
	/*<thisrel this+0x3a0>*/ /*|0xa0|*/ short Index[80];
	/*<thisrel this+0x440>*/ /*|0x50|*/ unsigned char Use[80];
	/*<thisrel this+0x490>*/ /*|0x50|*/ char pServer[80];
	/*<thisrel this+0x4e0>*/ /*|0x9|*/ char TargetGuildName[9];
	/*<thisrel this+0x4ea>*/ /*|0xa0|*/ short TargetIndex[80];
	/*<thisrel this+0x58c>*/ /*|0x4|*/ _GUILD_INFO_STRUCT* lpTargetGuildNode;
	/*<thisrel this+0x590>*/ /*|0x1|*/ unsigned char WarDeclareState;
	/*<thisrel this+0x591>*/ /*|0x1|*/ unsigned char WarState;
	/*<thisrel this+0x592>*/ /*|0x1|*/ unsigned char WarType;
	/*<thisrel this+0x593>*/ /*|0x1|*/ unsigned char BattleGroundIndex;
	/*<thisrel this+0x594>*/ /*|0x1|*/ unsigned char BattleTeamCode;
	/*<thisrel this+0x595>*/ /*|0x1|*/ unsigned char PlayScore;
	/*<thisrel this+0x598>*/ /*|0x4|*/ int TotalScore;
	/*<thisrel this+0x59c>*/ /*|0x3c|*/ char Notice[60];
	/*<thisrel this+0x5d8>*/ /*|0x140|*/ int GuildStatus[80];
	/*<thisrel this+0x718>*/ /*|0x1|*/ unsigned char btGuildType;
	/*<thisrel this+0x71c>*/ /*|0x4|*/ int iGuildUnion;
	/*<thisrel this+0x720>*/ /*|0x4|*/ int iGuildRival;
	/*<thisrel this+0x724>*/ /*|0x4|*/ int iTimeStamp;
	/*<thisrel this+0x728>*/ /*|0x9|*/ char szGuildRivalName[9];
	/*<thisrel this+0x734>*/ /*|0x4|*/ _GUILD_INFO_STRUCT* back;
	/*<thisrel this+0x738>*/ /*|0x4|*/ _GUILD_INFO_STRUCT* next;
};

struct VIEWPORT_STRUCT
{
	/*<thisrel this+0x0>*/ /*|0x1|*/ char state;
	/*<thisrel this+0x2>*/ /*|0x2|*/ short number;
	/*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char type;
	/*<thisrel this+0x6>*/ /*|0x2|*/ short index;
	/*<thisrel this+0x8>*/ /*|0x4|*/ int dis;
};

struct VIEWPORT_PLAYER_STRUCT
{
	/*<thisrel this+0x0>*/ /*|0x1|*/ char state;
	/*<thisrel this+0x2>*/ /*|0x2|*/ short number;
	/*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char type;
	/*<thisrel this+0x6>*/ /*|0x2|*/ short index;
	/*<thisrel this+0x8>*/ /*|0x4|*/ int dis;
};

struct HITDAMAGE_STRUCT
{
	/*<thisrel this+0x0>*/ /*|0x2|*/ short number;
	/*<thisrel this+0x4>*/ /*|0x4|*/ int HitDamage;
	/*<thisrel this+0x8>*/ /*|0x4|*/ unsigned long LastHitTime;
};

struct tagInterfaceState
{
	/*<bitfield this+0x0>*/ /*|0x4|*/ unsigned long use:2;
	/*<bitfield this+0x0>*/ /*|0x4|*/ unsigned long state:4;
	/*<bitfield this+0x0>*/ /*|0x4|*/ unsigned long type:0x0A;
};

class CItem 
{
public:
	BOOL IsItem()
	{
		if (m_Type < 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	int ItemDefense()
	{
		int Defense;

		if (m_Type < 0)
		{
			return 0;
		}
		else
		{
			if (m_IsValidItem == false)
			{
				return 0;
			}
			else
			{
				Defense = m_Defense;
				PlusSpecial(&Defense, 83);
				return Defense;
			}
		}
	}

	void PlusSpecial(int * Value, int Special)
	{
		if (m_Type < 0)
		{
			return;
		}

		if (m_Durability == 0.0f)
		{
			return;
		}

		if (m_IsValidItem == false)
		{
			return;
		}

		for (int i = 0; i <m_SpecialNum; i++)
		{
			if (m_Special[i] == Special)
			{
				switch ( Special )
				{
				case 82:
					{
						int lc3 = m_Option3*5;
						*Value += lc3 - (int)( lc3 * m_CurrentDurabilityState );
					}
					break;

				case 84:
					* Value += 4;
					break;

				case 81:
				case 80:
				case 83:
					{
						int lc4 = m_Option3*4;
						*Value += lc4 - (int)( lc4 * m_CurrentDurabilityState );
					}
					break;

				case 100:
				case 101:
					*Value =  *Value + m_Level * 5 + 50;
					break;

				case 103:
					*Value += 50;
					break;

				case 105:
					*Value =  *Value + m_Level * 5 + 10;

					break;

				default:
					*Value = *Value + (m_Option3*4);
					break;
				}
			}
		}
	}

	void PlusSpecialPercentEx(int * Value, int SourceValue, int Special)
	{
		if (m_Type < 0)
		{
			return;
		}

		if (m_Durability == 0.0f)
		{
			return;
		}

		if (m_IsValidItem == false)
		{
			return;
		}

		for (int i = 0; i <m_SpecialNum; i++)
		{
			if (m_Special[i] == Special)
			{
				int lc3 = SourceValue * m_Option3/100;
				*Value += lc3 - (int)(lc3 * m_CurrentDurabilityState );
			}
		}
	}

	/*<thisrel this+0x0>*/ /*|0x4|*/ unsigned long m_Number;
	/*<thisrel this+0x4>*/ /*|0x1|*/ char m_serial;
	/*<thisrel this+0x6>*/ /*|0x2|*/ short m_Type;
	/*<thisrel this+0x8>*/ /*|0x2|*/ short m_Level;
	/*<thisrel this+0xa>*/ /*|0x1|*/ unsigned char m_Part;
	/*<thisrel this+0xb>*/ /*|0x1|*/ unsigned char m_Class;
	/*<thisrel this+0xc>*/ /*|0x1|*/ unsigned char m_TwoHand;
	/*<thisrel this+0xd>*/ /*|0x1|*/ unsigned char m_AttackSpeed;
	/*<thisrel this+0xe>*/ /*|0x1|*/ unsigned char m_WalkSpeed;
	/*<thisrel this+0x10>*/ /*|0x2|*/ unsigned short m_DamageMin;
	/*<thisrel this+0x12>*/ /*|0x2|*/ unsigned short m_DamageMax;
	/*<thisrel this+0x14>*/ /*|0x1|*/ unsigned char m_SuccessfulBlocking;
	/*<thisrel this+0x16>*/ /*|0x2|*/ unsigned short m_Defense;
	/*<thisrel this+0x18>*/ /*|0x2|*/ unsigned short m_MagicDefense;
	/*<thisrel this+0x1a>*/ /*|0x1|*/ unsigned char m_Speed;
	/*<thisrel this+0x1c>*/ /*|0x2|*/ unsigned short m_DamageMinOrigin;
	/*<thisrel this+0x1e>*/ /*|0x2|*/ unsigned short m_DefenseOrigin;
	/*<thisrel this+0x20>*/ /*|0x2|*/ unsigned short m_Magic;
	/*<thisrel this+0x24>*/ /*|0x4|*/ float m_Durability;
	/*<thisrel this+0x28>*/ /*|0x2|*/ unsigned short m_DurabilitySmall;
	/*<thisrel this+0x2c>*/ /*|0x4|*/ float m_BaseDurability;
	/*<thisrel this+0x30>*/ /*|0x1|*/ unsigned char m_SpecialNum;
	/*<thisrel this+0x31>*/ /*|0x8|*/ unsigned char m_Special[8];
	/*<thisrel this+0x39>*/ /*|0x8|*/ unsigned char m_SpecialValue[8];
	/*<thisrel this+0x42>*/ /*|0x2|*/ unsigned short m_RequireStrength;
	/*<thisrel this+0x44>*/ /*|0x2|*/ unsigned short m_RequireDexterity;
	/*<thisrel this+0x46>*/ /*|0x2|*/ unsigned short m_RequireEnergy;
	/*<thisrel this+0x48>*/ /*|0x2|*/ unsigned short m_RequireLevel;
	/*<thisrel this+0x4a>*/ /*|0x2|*/ unsigned short m_RequireLeaderShip;
	/*<thisrel this+0x4c>*/ /*|0x2|*/ unsigned short m_Leadership;
	/*<thisrel this+0x4e>*/ /*|0x5|*/ unsigned char m_RequireClass[5];
	/*<thisrel this+0x53>*/ /*|0x7|*/ unsigned char m_Resistance[7];
	/*<thisrel this+0x5c>*/ /*|0x4|*/ int m_Value;
	/*<thisrel this+0x60>*/ /*|0x4|*/ unsigned long m_SellMoney;
	/*<thisrel this+0x64>*/ /*|0x4|*/ unsigned long m_BuyMoney;
	/*<thisrel this+0x68>*/ /*|0x4|*/ int m_iPShopValue;
	/*<thisrel this+0x6c>*/ /*|0x1|*/ unsigned char m_bItemExist;
	/*<thisrel this+0x70>*/ /*|0x4|*/ int m_OldSellMoney;
	/*<thisrel this+0x74>*/ /*|0x4|*/ int m_OldBuyMoney;
	/*<thisrel this+0x78>*/ /*|0x1|*/ unsigned char m_Option1;
	/*<thisrel this+0x79>*/ /*|0x1|*/ unsigned char m_Option2;
	/*<thisrel this+0x7a>*/ /*|0x1|*/ unsigned char m_Option3;
	/*<thisrel this+0x7b>*/ /*|0x1|*/ unsigned char m_NewOption;
	/*<thisrel this+0x7c>*/ /*|0x10|*/ float m_DurabilityState[4];
	/*<thisrel this+0x8c>*/ /*|0x4|*/ float m_CurrentDurabilityState;
	/*<thisrel this+0x90>*/ /*|0x1|*/ unsigned char m_SkillChange;
	/*<thisrel this+0x91>*/ /*|0x1|*/ unsigned char m_QuestItem;
	/*<thisrel this+0x92>*/ /*|0x1|*/ unsigned char m_SetOption;
	/*<thisrel this+0x93>*/ /*|0x1|*/ unsigned char m_SetAddStat;
	/*<thisrel this+0x94>*/ /*|0x1|*/ unsigned char m_IsValidItem;
	/*<thisrel this+0x95>*/ /*|0x7|*/ unsigned char m_SkillResistance[7];
	/*<thisrel this+0x9c>*/ /*|0x4|*/ int m_IsLoadPetItemInfo;
	/*<thisrel this+0xa0>*/ /*|0x4|*/ int m_PetItem_Level;
	/*<thisrel this+0xa4>*/ /*|0x4|*/ int m_PetItem_Exp;

	public:
   
   __declspec() void Convert(int type, BYTE Option1, BYTE Option2, BYTE Option3,BYTE Attribute2, BYTE SetOption, BYTE DbVersion);

};

//class CMagicInf // Refeita Struct em nova cpp
//{
//public:
//	CMagicInf() {}
//	virtual ~CMagicInf() {}
//
//public:
//	BYTE m_Level;
//	BYTE m_Skill;
//	int m_DamageMin;
//	int m_DamageMax;
//};

struct PLAYERSTRUCT
{
   char  OriName[11];
   DWORD VipIndex;
   DWORD Resets;
   DWORD Masters;
   DWORD PostDelay;
   DWORD WareDelay;
   DWORD mCash;
   int m_GensState;
   int m_GensScore_D;
   int m_GensScore_V;
   int jail;
   int jaula;
};

struct OBJECTSTRUCT
{
	/*<thisrel this+0x0>*/ /*|0x4|*/ int m_Index;
	/*<thisrel this+0x4>*/ /*|0x4|*/ int Connected;
	/*<thisrel this+0x8>*/ /*|0x1|*/ char LoginMsgSnd;
	/*<thisrel this+0x9>*/ /*|0x1|*/ char LoginMsgCount;
	/*<thisrel this+0xa>*/ /*|0x1|*/ char CloseCount;
	/*<thisrel this+0xb>*/ /*|0x1|*/ char CloseType;
	/*<thisrel this+0xc>*/ /*|0x4|*/ _PER_SOCKET_CONTEXT* PerSocketContext;
	/*<thisrel this+0x10>*/ /*|0x4|*/ unsigned int m_socket;
	/*<thisrel this+0x14>*/ /*|0x10|*/ char Ip_addr[16];
	/*<thisrel this+0x24>*/ /*|0x4|*/ int UserNumber;
	/*<thisrel this+0x28>*/ /*|0x4|*/ int DBNumber;
	/*<thisrel this+0x2c>*/ /*|0x1|*/ unsigned char Magumsa;
	/*<thisrel this+0x30>*/ /*|0x4|*/ unsigned long AutoSaveTime;
	/*<thisrel this+0x34>*/ /*|0x4|*/ unsigned long ConnectCheckTime;
	/*<thisrel this+0x38>*/ /*|0x4|*/ unsigned long CheckTick;
	/*<thisrel this+0x3c>*/ /*|0x1|*/ unsigned char CheckSpeedHack;
	/*<thisrel this+0x40>*/ /*|0x4|*/ unsigned long CheckTick2;
	/*<thisrel this+0x44>*/ /*|0x1|*/ unsigned char CheckTickCount;
	/*<thisrel this+0x48>*/ /*|0x4|*/ unsigned long SaveTimeForStatics;
	/*<thisrel this+0x4c>*/ /*|0x4|*/ int iPingTime;
	/*<thisrel this+0x50>*/ /*|0x1|*/ unsigned char m_TimeCount;
	/*<thisrel this+0x54>*/ /*|0x4|*/ unsigned long m_dwPKTimer;
	/*<thisrel this+0x58>*/ /*|0x2|*/ short CheckSumTableNum;
	/*<thisrel this+0x5c>*/ /*|0x4|*/ unsigned long CheckSumTime;
	/*<thisrel this+0x60>*/ /*|0x2|*/ unsigned short Type;
	/*<thisrel this+0x62>*/ /*|0x1|*/ unsigned char Live;
	/*<thisrel this+0x63>*/ /*|0x1|*/ char CharacterPos;
	/*<thisrel this+0x64>*/ /*|0xb|*/ char AccountID[11];
	/*<thisrel this+0x6f>*/ /*|0xb|*/ char Name[11];
	/*<thisrel this+0x7a>*/ /*|0xe|*/ char LastJoominNumber[14];
	/*<thisrel this+0x88>*/ /*|0x1|*/ unsigned char PlusStatQuestClear;
	/*<thisrel this+0x89>*/ /*|0x1|*/ unsigned char ComboSkillquestClear;
	/*<thisrel this+0x8c>*/ /*|0xc|*/ ComboSkillData comboSkill;
	/*<thisrel this+0x98>*/ /*|0x2|*/ unsigned short Class;
	/*<thisrel this+0x9a>*/ /*|0x1|*/ unsigned char DbClass;
	/*<thisrel this+0x9b>*/ /*|0x1|*/ unsigned char ChangeUP;
	/*<thisrel this+0x9c>*/ /*|0x2|*/ short Level;
	/*<thisrel this+0xa0>*/ /*|0x4|*/ int LevelUpPoint;
	/*<thisrel this+0xa4>*/ /*|0x4|*/ unsigned long Experience;
	/*<thisrel this+0xa8>*/ /*|0x4|*/ unsigned long NextExp;
	/*<thisrel this+0xac>*/ /*|0x4|*/ int Money;
	/*<thisrel this+0xb0>*/ /*|0x2|*/ short Strength;
	/*<thisrel this+0xb2>*/ /*|0x2|*/ short Dexterity;
	/*<thisrel this+0xb4>*/ /*|0x2|*/ short Vitality;
	/*<thisrel this+0xb6>*/ /*|0x2|*/ short Energy;
	/*<thisrel this+0xb8>*/ /*|0x4|*/ float Life;
	/*<thisrel this+0xbc>*/ /*|0x4|*/ float MaxLife;
	/*<thisrel this+0xc0>*/ /*|0x4|*/ float FillLife;
	/*<thisrel this+0xc4>*/ /*|0x4|*/ float FillLifeMax;
	/*<thisrel this+0xc8>*/ /*|0x4|*/ float Mana;
	/*<thisrel this+0xcc>*/ /*|0x4|*/ float MaxMana;
	/*<thisrel this+0xd0>*/ /*|0x2|*/ unsigned short Leadership;
	/*<thisrel this+0xd2>*/ /*|0x2|*/ unsigned short AddLeadership;
	/*<thisrel this+0xd4>*/ /*|0x2|*/ unsigned short ChatLitmitTime;
	/*<thisrel this+0xd6>*/ /*|0x1|*/ unsigned char ChatLimitTimeSec;
	/*<thisrel this+0xd7>*/ /*|0x1|*/ unsigned char FillLifeCount;
	/*<thisrel this+0xd8>*/ /*|0x2|*/ short AddStrength;
	/*<thisrel this+0xda>*/ /*|0x2|*/ short AddDexterity;
	/*<thisrel this+0xdc>*/ /*|0x2|*/ short AddVitality;
	/*<thisrel this+0xde>*/ /*|0x2|*/ short AddEnergy;
	/*<thisrel this+0xe0>*/ /*|0x4|*/ int BP;
	/*<thisrel this+0xe4>*/ /*|0x4|*/ int MaxBP;
	/*<thisrel this+0xe8>*/ /*|0x4|*/ int AddBP;
	/*<thisrel this+0xec>*/ /*|0x4|*/ float VitalityToLife;
	/*<thisrel this+0xf0>*/ /*|0x4|*/ float EnergyToMana;
	/*<thisrel this+0xf4>*/ /*|0x1|*/ char m_PK_Count;
	/*<thisrel this+0xf5>*/ /*|0x1|*/ char m_PK_Level;
	/*<thisrel this+0xf8>*/ /*|0x4|*/ int m_PK_Time;
	/*<thisrel this+0xfc>*/ /*|0x2|*/ short X;
	/*<thisrel this+0xfe>*/ /*|0x2|*/ short Y;
	/*<thisrel this+0x100>*/ /*|0x1|*/ unsigned char Dir;
	/*<thisrel this+0x101>*/ /*|0x1|*/ unsigned char MapNumber;
	/*<thisrel this+0x104>*/ /*|0x4|*/ int AddLife;
	/*<thisrel this+0x108>*/ /*|0x4|*/ int AddMana;
	/*<thisrel this+0x10c>*/ /*|0x1|*/ unsigned char DamageMinus;
	/*<thisrel this+0x10d>*/ /*|0x1|*/ unsigned char DamageReflect;
	/*<thisrel this+0x10e>*/ /*|0x2|*/ short MonsterDieGetMoney;
	/*<thisrel this+0x110>*/ /*|0x1|*/ unsigned char MonsterDieGetLife;
	/*<thisrel this+0x111>*/ /*|0x1|*/ unsigned char MonsterDieGetMana;
	/*<thisrel this+0x112>*/ /*|0x1|*/ unsigned char StartX;
	/*<thisrel this+0x113>*/ /*|0x1|*/ unsigned char StartY;
	/*<thisrel this+0x114>*/ /*|0x2|*/ short m_OldX;
	/*<thisrel this+0x116>*/ /*|0x2|*/ short m_OldY;
	/*<thisrel this+0x118>*/ /*|0x2|*/ short TX;
	/*<thisrel this+0x11a>*/ /*|0x2|*/ short TY;
	/*<thisrel this+0x11c>*/ /*|0x2|*/ short MTX;
	/*<thisrel this+0x11e>*/ /*|0x2|*/ short MTY;
	/*<thisrel this+0x120>*/ /*|0x4|*/ int PathCount;
	/*<thisrel this+0x124>*/ /*|0x4|*/ int PathCur;
	/*<thisrel this+0x128>*/ /*|0x1|*/ char PathStartEnd;
	/*<thisrel this+0x12a>*/ /*|0x1e|*/ short PathOri[15];
	/*<thisrel this+0x148>*/ /*|0x1e|*/ short PathX[15];
	/*<thisrel this+0x166>*/ /*|0x1e|*/ short PathY[15];
	/*<thisrel this+0x184>*/ /*|0xf|*/ char PathDir[15];
	/*<thisrel this+0x194>*/ /*|0x4|*/ unsigned long PathTime;
	/*<thisrel this+0x198>*/ /*|0x1|*/ char m_MoveGateNumber;
	/*<thisrel this+0x19c>*/ /*|0x4|*/ unsigned long Authority;
	/*<thisrel this+0x1a0>*/ /*|0x4|*/ unsigned long AuthorityCode;
	/*<thisrel this+0x1a4>*/ /*|0x4|*/ unsigned long Penalty;
	/*<thisrel this+0x1a8>*/ /*|0x1|*/ unsigned char m_cAccountItemBlock;
	/*<thisrel this+0x1ac>*/ /*|0x4|*/ tagActionState m_ActState;
	/*<thisrel this+0x1b0>*/ /*|0x1|*/ unsigned char m_ActionNumber;
	/*<thisrel this+0x1b4>*/ /*|0x4|*/ unsigned long m_State;
	/*<thisrel this+0x1b8>*/ /*|0x1|*/ char m_StateSub;
	/*<thisrel this+0x1b9>*/ /*|0x1|*/ unsigned char m_Rest;
	/*<thisrel this+0x1ba>*/ /*|0x1|*/ char m_ViewState;
	/*<thisrel this+0x1bc>*/ /*|0x4|*/ int m_ViewSkillState;
	/*<thisrel this+0x1c0>*/ /*|0x4|*/ unsigned long m_LastMoveTime;
	/*<thisrel this+0x1c4>*/ /*|0x4|*/ unsigned long m_LastAttackTime;
	/*<thisrel this+0x1c8>*/ /*|0x1|*/ unsigned char m_FriendServerOnline;
	/*<thisrel this+0x1cc>*/ /*|0x4|*/ int m_DetectSpeedHackTime;
	/*<thisrel this+0x1d0>*/ /*|0x4|*/ unsigned long m_SumLastAttackTime;
	/*<thisrel this+0x1d4>*/ /*|0x4|*/ unsigned long m_DetectCount;
	/*<thisrel this+0x1d8>*/ /*|0x4|*/ int m_DetectedHackKickCount;
	/*<thisrel this+0x1dc>*/ /*|0x4|*/ int m_SpeedHackPenalty;
	/*<thisrel this+0x1e0>*/ /*|0x1|*/ unsigned char m_AttackSpeedHackDetectedCount;
	/*<thisrel this+0x1e4>*/ /*|0x4|*/ unsigned long m_PacketCheckTime;
	/*<thisrel this+0x1e8>*/ /*|0x1|*/ unsigned char m_ShopTime;
	/*<thisrel this+0x1ec>*/ /*|0x4|*/ unsigned long m_TotalAttackTime;
	/*<thisrel this+0x1f0>*/ /*|0x4|*/ int m_TotalAttackCount;
	/*<thisrel this+0x1f4>*/ /*|0x4|*/ unsigned long TeleportTime;
	/*<thisrel this+0x1f8>*/ /*|0x1|*/ char Teleport;
	/*<thisrel this+0x1f9>*/ /*|0x1|*/ char KillerType;
	/*<thisrel this+0x1fa>*/ /*|0x1|*/ char DieRegen;
	/*<thisrel this+0x1fb>*/ /*|0x1|*/ char RegenOk;
	/*<thisrel this+0x1fc>*/ /*|0x1|*/ unsigned char RegenMapNumber;
	/*<thisrel this+0x1fd>*/ /*|0x1|*/ unsigned char RegenMapX;
	/*<thisrel this+0x1fe>*/ /*|0x1|*/ unsigned char RegenMapY;
	/*<thisrel this+0x200>*/ /*|0x4|*/ unsigned long RegenTime;
	/*<thisrel this+0x204>*/ /*|0x4|*/ unsigned long MaxRegenTime;
	/*<thisrel this+0x208>*/ /*|0x2|*/ short m_PosNum;
	/*<thisrel this+0x20c>*/ /*|0x4|*/ unsigned long LifeRefillTimer;
	/*<thisrel this+0x210>*/ /*|0x4|*/ unsigned long CurActionTime;
	/*<thisrel this+0x214>*/ /*|0x4|*/ unsigned long NextActionTime;
	/*<thisrel this+0x218>*/ /*|0x4|*/ unsigned long DelayActionTime;
	/*<thisrel this+0x21c>*/ /*|0x1|*/ char DelayLevel;
	/*<thisrel this+0x21d>*/ /*|0x1|*/ char m_PoisonType;
	/*<thisrel this+0x21e>*/ /*|0x1|*/ char m_IceType;
	/*<thisrel this+0x21f>*/ /*|0x1|*/ char m_PoisonBeattackCount;
	/*<thisrel this+0x220>*/ /*|0x1|*/ char m_ColdBeattackCount;
	/*<thisrel this+0x221>*/ /*|0x1|*/ char m_ImmuneToMagicCount;
	/*<thisrel this+0x222>*/ /*|0x1|*/ char m_ImmuneToHarmCount;
	/*<thisrel this+0x223>*/ /*|0x1|*/ char m_iMonsterBattleDelay;
	/*<thisrel this+0x224>*/ /*|0x1|*/ char m_cKalimaGateExist;
	/*<thisrel this+0x228>*/ /*|0x4|*/ int m_iKalimaGateIndex;
	/*<thisrel this+0x22c>*/ /*|0x1|*/ char m_cKalimaGateEnterCount;
	/*<thisrel this+0x230>*/ /*|0x4|*/ struct OBJECTSTRUCT * lpAttackObj;
	/*<thisrel this+0x234>*/ /*|0x2|*/ short m_SkillNumber;
	/*<thisrel this+0x238>*/ /*|0x4|*/ unsigned long m_SkillTime;
	/*<thisrel this+0x23c>*/ /*|0x1|*/ unsigned char m_bAttackerKilled;
	/*<thisrel this+0x23d>*/ /*|0x1|*/ char m_ManaFillCount;
	/*<thisrel this+0x23e>*/ /*|0x1|*/ char m_LifeFillCount;
	/*<thisrel this+0x240>*/ /*|0x14|*/ int SelfDefense[5];
	/*<thisrel this+0x254>*/ /*|0x14|*/ unsigned long SelfDefenseTime[5];
	/*<thisrel this+0x268>*/ /*|0x4|*/ unsigned long MySelfDefenseTime;
	/*<thisrel this+0x26c>*/ /*|0x1|*/ char m_Drink;
	/*<thisrel this+0x270>*/ /*|0x4|*/ int m_SkillDefense;
	/*<thisrel this+0x274>*/ /*|0x1|*/ char m_SkillDefenseTime;
	/*<thisrel this+0x278>*/ /*|0x4|*/ int m_SkillAttack;
	/*<thisrel this+0x27c>*/ /*|0x1|*/ char m_SkillAttackTime;
	/*<thisrel this+0x280>*/ /*|0x4|*/ int m_SkillAttack2;
	/*<thisrel this+0x284>*/ /*|0x1|*/ char m_SkillAttackTime2;
	/*<thisrel this+0x288>*/ /*|0x4|*/ int m_SkillAddLife;
	/*<thisrel this+0x28c>*/ /*|0x4|*/ int m_SkillAddLifeTime;
	/*<thisrel this+0x290>*/ /*|0x4|*/ int m_SkillHarden;
	/*<thisrel this+0x294>*/ /*|0x4|*/ int m_SkillHardenTime;
	/*<thisrel this+0x298>*/ /*|0x4|*/ int m_SkillMagumReduceDefense;
	/*<thisrel this+0x29c>*/ /*|0x4|*/ int m_SkillMagumReduceDefenseTime;
	/*<thisrel this+0x2a0>*/ /*|0x4|*/ int PartyNumber;
	/*<thisrel this+0x2a4>*/ /*|0x4|*/ int PartyTargetUser;
	/*<thisrel this+0x2a8>*/ /*|0x4|*/ int GuildNumber;
	/*<thisrel this+0x2ac>*/ /*|0x4|*/ _GUILD_INFO_STRUCT * lpGuild;
	/*<thisrel this+0x2b0>*/ /*|0xb|*/ char GuildName[11];
	/*<thisrel this+0x2bc>*/ /*|0x4|*/ int GuildStatus;
	/*<thisrel this+0x2c0>*/ /*|0x4|*/ int iGuildUnionTimeStamp;
	/*<thisrel this+0x2c4>*/ /*|0x4|*/ int m_RecallMon;
	/*<thisrel this+0x2c8>*/ /*|0x4|*/ int m_Change;
	/*<thisrel this+0x2cc>*/ /*|0x2|*/ short TargetNumber;
	/*<thisrel this+0x2ce>*/ /*|0x2|*/ short TargetShopNumber;
	/*<thisrel this+0x2d0>*/ /*|0x2|*/ short ShopNumber;
	/*<thisrel this+0x2d2>*/ /*|0x2|*/ short LastAttackerID;
	/*<thisrel this+0x2d4>*/ /*|0x4|*/ int m_AttackDamageMin;
	/*<thisrel this+0x2d8>*/ /*|0x4|*/ int m_AttackDamageMax;
	/*<thisrel this+0x2dc>*/ /*|0x4|*/ int m_MagicDamageMin;
	/*<thisrel this+0x2e0>*/ /*|0x4|*/ int m_MagicDamageMax;
	/*<thisrel this+0x2e4>*/ /*|0x4|*/ int m_AttackDamageLeft;
	/*<thisrel this+0x2e8>*/ /*|0x4|*/ int m_AttackDamageRight;
	/*<thisrel this+0x2ec>*/ /*|0x4|*/ int m_AttackDamageMaxLeft;
	/*<thisrel this+0x2f0>*/ /*|0x4|*/ int m_AttackDamageMinLeft;
	/*<thisrel this+0x2f4>*/ /*|0x4|*/ int m_AttackDamageMaxRight;
	/*<thisrel this+0x2f8>*/ /*|0x4|*/ int m_AttackDamageMinRight;
	/*<thisrel this+0x2fc>*/ /*|0x4|*/ int m_AttackRating;
	/*<thisrel this+0x300>*/ /*|0x4|*/ int m_AttackSpeed;
	/*<thisrel this+0x304>*/ /*|0x4|*/ int m_MagicSpeed;
	/*<thisrel this+0x308>*/ /*|0x4|*/ int m_Defense;
	/*<thisrel this+0x30c>*/ /*|0x4|*/ int m_MagicDefense;
	/*<thisrel this+0x310>*/ /*|0x4|*/ int m_SuccessfulBlocking;
	/*<thisrel this+0x314>*/ /*|0x2|*/ short m_MoveSpeed;
	/*<thisrel this+0x316>*/ /*|0x2|*/ short m_MoveRange;
	/*<thisrel this+0x318>*/ /*|0x2|*/ short m_AttackRange;
	/*<thisrel this+0x31a>*/ /*|0x2|*/ short m_AttackType;
	/*<thisrel this+0x31c>*/ /*|0x2|*/ short m_ViewRange;
	/*<thisrel this+0x31e>*/ /*|0x2|*/ short m_Attribute;
	/*<thisrel this+0x320>*/ /*|0x2|*/ short m_ItemRate;
	/*<thisrel this+0x322>*/ /*|0x2|*/ short m_MoneyRate;
	/*<thisrel this+0x324>*/ /*|0x4|*/ int m_CriticalDamage;
	/*<thisrel this+0x328>*/ /*|0x4|*/ int m_ExcelentDamage;
	/*<thisrel this+0x32c>*/ /*|0x4|*/ class CMagicInf* m_lpMagicBack;
	/*<thisrel this+0x330>*/ /*|0x4|*/ class CMagicInf* Magic;
	/*<thisrel this+0x334>*/ /*|0x1|*/ char MagicCount;
	/*<thisrel this+0x335>*/ /*|0x1|*/ unsigned char UseMagicNumber;
	/*<thisrel this+0x338>*/ /*|0x4|*/ unsigned long UseMagicTime;
	/*<thisrel this+0x33c>*/ /*|0x1|*/ char UseMagicCount;
	/*<thisrel this+0x33e>*/ /*|0x2|*/ short OSAttackSerial;
	/*<thisrel this+0x340>*/ /*|0x1|*/ unsigned char SASCount;
	/*<thisrel this+0x344>*/ /*|0x4|*/ unsigned long SkillAttackTime;
	/*<thisrel this+0x348>*/ /*|0xd|*/ unsigned char CharSet[13];
	/*<thisrel this+0x355>*/ /*|0x7|*/ unsigned char m_Resistance[7];
	/*<thisrel this+0x35c>*/ /*|0x7|*/ unsigned char m_AddResistance[7];
	/*<thisrel this+0x364>*/ /*|0x10|*/ int FrustrumX[4];
	/*<thisrel this+0x374>*/ /*|0x10|*/ int FrustrumY[4];
	/*<thisrel this+0x384>*/ /*|0x384|*/ VIEWPORT_STRUCT VpPlayer[75];
	/*<thisrel this+0x708>*/ /*|0x384|*/ VIEWPORT_PLAYER_STRUCT VpPlayer2[75];
	/*<thisrel this+0xa8c>*/ /*|0x4|*/ int VPCount;
	/*<thisrel this+0xa90>*/ /*|0x4|*/ int VPCount2;
	/*<thisrel this+0xa94>*/ /*|0x1e0|*/ HITDAMAGE_STRUCT sHD[40];
	/*<thisrel this+0xc74>*/ /*|0x2|*/ short sHDCount;
	/*<thisrel this+0xc78>*/ /*|0x4|*/ tagInterfaceState m_IfState;
	/*<thisrel this+0xc7c>*/ /*|0x4|*/ unsigned long m_InterfaceTime;
	/*<thisrel this+0xc80>*/ /*|0x4|*/ class CItem* pInventory;
	/*<thisrel this+0xc84>*/ /*|0x4|*/ unsigned char* pInventoryMap;
	/*<thisrel this+0xc88>*/ /*|0x4|*/ char* pInventoryCount;
	/*<thisrel this+0xc8c>*/ /*|0x1|*/ char pTransaction;
	/*<thisrel this+0xc90>*/ /*|0x4|*/ class CItem* Inventory1;
	/*<thisrel this+0xc94>*/ /*|0x4|*/ unsigned char* InventoryMap1;
	/*<thisrel this+0xc98>*/ /*|0x1|*/ char InventoryCount1;
	/*<thisrel this+0xc9c>*/ /*|0x4|*/ class CItem* Inventory2;
	/*<thisrel this+0xca0>*/ /*|0x4|*/ unsigned char* InventoryMap2;
	/*<thisrel this+0xca4>*/ /*|0x1|*/ char InventoryCount2;
	/*<thisrel this+0xca8>*/ /*|0x4|*/ class CItem* Trade;
	/*<thisrel this+0xcac>*/ /*|0x4|*/ unsigned char* TradeMap;
	/*<thisrel this+0xcb0>*/ /*|0x4|*/ int TradeMoney;
	/*<thisrel this+0xcb4>*/ /*|0x1|*/ unsigned char TradeOk;
	/*<thisrel this+0xcb8>*/ /*|0x4|*/ class CItem* pWarehouse;
	/*<thisrel this+0xcbc>*/ /*|0x4|*/ unsigned char* pWarehouseMap;
	/*<thisrel this+0xcc0>*/ /*|0x1|*/ char WarehouseCount;
	/*<thisrel this+0xcc2>*/ /*|0x2|*/ short WarehousePW;
	/*<thisrel this+0xcc4>*/ /*|0x1|*/ unsigned char WarehouseLock;
	/*<thisrel this+0xcc5>*/ /*|0x1|*/ unsigned char WarehouseUnfailLock;
	/*<thisrel this+0xcc8>*/ /*|0x4|*/ int WarehouseMoney;
	/*<thisrel this+0xccc>*/ /*|0x4|*/ int WarehouseSave;
	/*<thisrel this+0xcd0>*/ /*|0x4|*/ class CItem* pChaosBox;
	/*<thisrel this+0xcd4>*/ /*|0x4|*/ unsigned char* pChaosBoxMap;
	/*<thisrel this+0xcd8>*/ /*|0x4|*/ int ChaosMoney;
	/*<thisrel this+0xcdc>*/ /*|0x4|*/ int ChaosSuccessRate;
	/*<thisrel this+0xce0>*/ /*|0x4|*/ int ChaosLock;
	/*<thisrel this+0xce4>*/ /*|0x4|*/ unsigned long m_Option;
	/*<thisrel this+0xce8>*/ /*|0x4|*/ int m_nEventScore;
	/*<thisrel this+0xcec>*/ /*|0x4|*/ int m_nEventExp;
	/*<thisrel this+0xcf0>*/ /*|0x4|*/ int m_nEventMoney;
	/*<thisrel this+0xcf4>*/ /*|0x1|*/ unsigned char m_bDevilSquareIndex;
	/*<thisrel this+0xcf5>*/ /*|0x1|*/ unsigned char m_bDevilSquareAuth;
	/*<thisrel this+0xcf6>*/ /*|0x1|*/ char m_cBloodCastleIndex;
	/*<thisrel this+0xcf7>*/ /*|0x1|*/ char m_cBloodCastleSubIndex;
	/*<thisrel this+0xcf8>*/ /*|0x4|*/ int m_iBloodCastleEXP;
	/*<thisrel this+0xcfc>*/ /*|0x1|*/ char m_cChaosCastleIndex;
	/*<thisrel this+0xcfd>*/ /*|0x1|*/ char m_cChaosCastleSubIndex;
	/*<thisrel this+0xd00>*/ /*|0x4|*/ int m_iChaosCastleBlowTime;
	/*<thisrel this+0xd04>*/ /*|0x1|*/ char m_cKillUserCount;
	/*<thisrel this+0xd05>*/ /*|0x1|*/ char m_cKillMonsterCount;
	/*<thisrel this+0xd08>*/ /*|0x4|*/ int m_iDuelUserReserved;
	/*<thisrel this+0xd0c>*/ /*|0x4|*/ int m_iDuelUserRequested;
	/*<thisrel this+0xd10>*/ /*|0x4|*/ int m_iDuelUser;
	/*<thisrel this+0xd14>*/ /*|0x1|*/ unsigned char m_btDuelScore;
	/*<thisrel this+0xd18>*/ /*|0x4|*/ int m_iDuelTickCount;
	/*<thisrel this+0xd1c>*/ /*|0x1|*/ unsigned char m_bPShopOpen;
	/*<thisrel this+0xd1d>*/ /*|0x1|*/ unsigned char m_bPShopTransaction;
	/*<thisrel this+0xd1e>*/ /*|0x1|*/ unsigned char m_bPShopItemChange;
	/*<thisrel this+0xd1f>*/ /*|0x1|*/ unsigned char m_bPShopRedrawAbs;
	/*<thisrel this+0xd20>*/ /*|0x24|*/ char m_szPShopText[36];
	/*<thisrel this+0xd44>*/ /*|0x1|*/ unsigned char m_bPShopWantDeal;
	/*<thisrel this+0xd48>*/ /*|0x4|*/ int m_iPShopDealerIndex;
	/*<thisrel this+0xd4c>*/ /*|0xa|*/ char m_szPShopDealerName[10];
	/*<thisrel this+0xd58>*/ /*|0x18|*/ struct _RTL_CRITICAL_SECTION m_critPShopTrade;
	/*<thisrel this+0xd70>*/ /*|0x12c|*/ int m_iVpPShopPlayer[75];
	/*<thisrel this+0xe9c>*/ /*|0x2|*/ unsigned short m_wVpPShopPlayerCount;
	/*<thisrel this+0xe9e>*/ /*|0x1|*/ unsigned char IsInBattleGround;
	/*<thisrel this+0xe9f>*/ /*|0x1|*/ unsigned char HaveWeaponInHand;
	/*<thisrel this+0xea0>*/ /*|0x2|*/ short EventChipCount;
	/*<thisrel this+0xea4>*/ /*|0x4|*/ int MutoNumber;
	/*<thisrel this+0xea8>*/ /*|0x4|*/ int UseEventServer;
	/*<thisrel this+0xeac>*/ /*|0x1|*/ unsigned char LoadWareHouseInfo;
	/*<thisrel this+0xeb0>*/ /*|0x4|*/ int iStoneCount;
	/*<thisrel this+0xeb4>*/ /*|0x32|*/ unsigned char m_Quest[50];
	/*<thisrel this+0xee6>*/ /*|0x1|*/ unsigned char m_SendQuestInfo;
	/*<thisrel this+0xee8>*/ /*|0x4|*/ int m_SkyBossMonSheildLinkIndex;
	/*<thisrel this+0xeec>*/ /*|0x4|*/ int m_SkyBossMonSheild;
	/*<thisrel this+0xef0>*/ /*|0x4|*/ int m_SkyBossMonSheildTime;
	/*<thisrel this+0xef4>*/ /*|0x4|*/ int m_MaxLifePower;
	/*<thisrel this+0xef8>*/ /*|0x4|*/ int m_WizardSkillDefense;
	/*<thisrel this+0xefc>*/ /*|0x4|*/ int m_WizardSkillDefenseTime;
	/*<thisrel this+0xf00>*/ /*|0x4|*/ int m_PacketChecksumTime;
	/*<thisrel this+0xf04>*/ /*|0x4|*/ int m_CheckLifeTime;
	/*<thisrel this+0xf08>*/ /*|0x1|*/ unsigned char m_MoveOtherServer;
	/*<thisrel this+0xf09>*/ /*|0x1|*/ char m_BossGoldDerconMapNumber;
	/*<thisrel this+0xf0a>*/ /*|0x1|*/ unsigned char m_InWebzen;
	/*<thisrel this+0xf0b>*/ /*|0x1|*/ char m_LastTeleportTime;
	/*<thisrel this+0xf0c>*/ /*|0x1|*/ unsigned char m_ClientHackLogCount;
	/*<thisrel this+0xf0d>*/ /*|0x1|*/ unsigned char m_bIsInMonsterHerd;
	/*<thisrel this+0xf0e>*/ /*|0x1|*/ unsigned char m_bIsMonsterAttackFirst;
	/*<thisrel this+0xf10>*/ /*|0x4|*/ class MonsterHerd* m_lpMonsterHerd;
	/*<thisrel this+0xf14>*/ /*|0x74|*/ unsigned char NPggCSAuth[0x74];
	/*<thisrel this+0xf88>*/ /*|0x4|*/ unsigned long m_NPggCheckSum;
	/*<thisrel this+0xf8c>*/ /*|0x4|*/ unsigned long m_NPggCheckSumSendTime;
	/*<thisrel this+0xf90>*/ /*|0x10|*/ int fSkillFrustrumX[4];
	/*<thisrel this+0xfa0>*/ /*|0x10|*/ int fSkillFrustrumY[4];
	/*<thisrel this+0xfb0>*/ /*|0x1|*/ unsigned char SkillHellFire2State;
	/*<thisrel this+0xfb1>*/ /*|0x1|*/ unsigned char SkillHellFire2Count;
	/*<thisrel this+0xfb4>*/ /*|0x4|*/ unsigned long SkillHellFire2Time;
	/*<thisrel this+0xfb8>*/ /*|0x1|*/ unsigned char m_ReqWarehouseOpen;
	/*<thisrel this+0xfbc>*/ /*|0x4|*/ int m_NotAttackAreaCount;
	/*<thisrel this+0xfc0>*/ /*|0x2|*/ short SetOpAddSkillAttack;
	/*<thisrel this+0xfc2>*/ /*|0x2|*/ short SetOpAddExDamage;
	/*<thisrel this+0xfc4>*/ /*|0x2|*/ short SetOpAddExDamageSuccessRate;
	/*<thisrel this+0xfc6>*/ /*|0x2|*/ short SetOpAddCriticalDamage;
	/*<thisrel this+0xfc8>*/ /*|0x2|*/ short SetOpAddCriticalDamageSuccessRate;
	/*<thisrel this+0xfca>*/ /*|0x2|*/ short SetOpIncAGValue;
	/*<thisrel this+0xfcc>*/ /*|0x2|*/ short SetOpAddDamage;
	/*<thisrel this+0xfce>*/ /*|0x2|*/ short SetOpAddMinAttackDamage;
	/*<thisrel this+0xfd0>*/ /*|0x2|*/ short SetOpAddMaxAttackDamage;
	/*<thisrel this+0xfd2>*/ /*|0x2|*/ short SetOpAddAttackDamage;
	/*<thisrel this+0xfd4>*/ /*|0x2|*/ short SetOpAddDefence;
	/*<thisrel this+0xfd6>*/ /*|0x2|*/ short SetOpAddDefenceRate;
	/*<thisrel this+0xfd8>*/ /*|0x2|*/ short SetOpAddMagicPower;
	/*<thisrel this+0xfda>*/ /*|0x1|*/ unsigned char SetOpIgnoreDefense;
	/*<thisrel this+0xfdb>*/ /*|0x1|*/ unsigned char SetOpDoubleDamage;
	/*<thisrel this+0xfdc>*/ /*|0x1|*/ unsigned char SetOpTwoHandSwordImproveDamage;
	/*<thisrel this+0xfdd>*/ /*|0x1|*/ unsigned char SetOpImproveSuccessAttackRate;
	/*<thisrel this+0xfde>*/ /*|0x1|*/ unsigned char SetOpReflectionDamage;
	/*<thisrel this+0xfdf>*/ /*|0x1|*/ unsigned char SetOpImproveSheldDefence;
	/*<thisrel this+0xfe0>*/ /*|0x1|*/ unsigned char SetOpDecreaseAG;
	/*<thisrel this+0xfe1>*/ /*|0x1|*/ unsigned char SetOpImproveItemDropRate;
	/*<thisrel this+0xfe2>*/ /*|0x1|*/ unsigned char IsFullSetItem;
	/*<thisrel this+0xfe4>*/ /*|0x12c|*/ unsigned char DurMagicKeyChecker[0x012c];
	/*<thisrel this+0x1110>*/ /*|0x2|*/ unsigned short SkillRecallParty_Time;
	/*<thisrel this+0x1112>*/ /*|0x1|*/ unsigned char SkillRecallParty_MapNumber;
	/*<thisrel this+0x1113>*/ /*|0x1|*/ unsigned char SkillRecallParty_X;
	/*<thisrel this+0x1114>*/ /*|0x1|*/ unsigned char SkillRecallParty_Y;
	/*<thisrel this+0x1116>*/ /*|0x2|*/ unsigned short SkillAddCriticalDamageTime;
	/*<thisrel this+0x1118>*/ /*|0x2|*/ unsigned short SkillAddCriticalDamage;
	/*<thisrel this+0x111a>*/ /*|0x1|*/ unsigned char bIsChaosMixCompleted;
	/*<thisrel this+0x111b>*/ /*|0x1|*/ unsigned char SkillLongSpearChange;
	/*<thisrel this+0x111c>*/ /*|0x404|*/ unsigned char CSkillDelay[0x404];
	/*<thisrel this+0x1520>*/ /*|0x4|*/ int iObjectSecTimer;
	/*<thisrel this+0x1524>*/ /*|0x1|*/ unsigned char m_bMapSvrMoveQuit;
	/*<thisrel this+0x1525>*/ /*|0x1|*/ unsigned char m_bMapSvrMoveReq;
	/*<thisrel this+0x1528>*/ /*|0x4|*/ unsigned long m_dwMapSvrQuitTick;
	/*<thisrel this+0x152c>*/ /*|0x2|*/ short m_sPrevMapSvrCode;
	/*<thisrel this+0x152e>*/ /*|0x2|*/ short m_sDestMapNumber;
	/*<thisrel this+0x1530>*/ /*|0x1|*/ unsigned char m_btDestX;
	/*<thisrel this+0x1531>*/ /*|0x1|*/ unsigned char m_btDestY;
	/*<thisrel this+0x1532>*/ /*|0x1|*/ unsigned char m_btWeaponState;
	/*<thisrel this+0x1534>*/ /*|0x4|*/ int m_iWeaponUser;
	/*<thisrel this+0x1538>*/ /*|0x1|*/ unsigned char m_btKillCount;
	/*<thisrel this+0x153c>*/ /*|0x4|*/ int m_iSkillStunTime;
	/*<thisrel this+0x1540>*/ /*|0x4|*/ int m_iSkillBrandOfSkillTime;
	/*<thisrel this+0x1544>*/ /*|0x4|*/ int m_iSkillInvisibleTime;
	/*<thisrel this+0x1548>*/ /*|0x4|*/ int m_iSkillManaSwellTime;
	/*<thisrel this+0x154c>*/ /*|0x4|*/ int m_iSkillManaSwell;
	/*<thisrel this+0x1550>*/ /*|0x4|*/ int m_iAccumulatedDamage;
	/*<thisrel this+0x1554>*/ /*|0x4|*/ int m_iPotionBlessTime;
	/*<thisrel this+0x1558>*/ /*|0x4|*/ int m_iPotionSoulTime;
	/*<thisrel this+0x155c>*/ /*|0x4|*/ unsigned long m_dwLastCheckTick;
	/*<thisrel this+0x1560>*/ /*|0x4|*/ int m_iAutoRecuperationTime;
	/*<thisrel this+0x1564>*/ /*|0x4|*/ int m_iSkillNPCHelpTime;
	/*<thisrel this+0x1568>*/ /*|0x4|*/ int m_iSkillNPCDefense;
	/*<thisrel this+0x156c>*/ /*|0x4|*/ int m_iSkillNPCAttack;
};

class CObjBaseAttack
{
public:
	CObjBaseAttack()
	{
	}

	virtual ~CObjBaseAttack()
	{
	}
};

class CDarkSpirit : public CObjBaseAttack
{
public:
  CDarkSpirit()
  {
  }

  virtual ~CDarkSpirit()
  {
  }

  void Set(int aIndex, CItem* pPetItem)
  {
	  __asm
	  {
		  PUSH pPetItem;
		  PUSH aIndex;
		  MOV EDI, 0x4AB300;
		  MOV ECX, this;
		  CALL EDI;
	  }
  }

public:
	int m_AttackDamageMin;
	int m_AttackDamageMax;
	int m_AttackSpeed;
	int m_SuccessAttackRate;
	int m_iMasterIndex;
	int m_iTargetIndex;
	DWORD m_dwLastAttackTime;
	enum ePetItem_Mode
	{
		PetItem_Mode_Normal = 0x0,
		PetItem_Mode_Attack_Random = 0x1,
		PetItem_Mode_Attack_WithMaster = 0x2,
		PetItem_Mode_Attack_Target = 0x3,

	} m_ActionMode;
	CItem * m_pPetItem;
};

typedef OBJECTSTRUCT*		LPOBJ;
extern	OBJECTSTRUCT*		gObj;



extern PLAYERSTRUCT Custom[7400];
extern CDarkSpirit* gDarkSpirit;

struct Quest_User
{
	int Quest_Num;
	int Quest_kill;
	int Quest_Start;
	int FreePoints;
	int ClickNPC;
};
struct Quest_Elf
{
	int Quest_Num;
	int Quest_kill;
	int Quest_Start;
	int FreePoints;
	int ClickNPC;
};
struct Quest_Boss
{
	int Quest_Num;
	int Quest_kill;
	int Quest_Start;
	int FreePoints;
	int ClickNPC;
};
struct Quest_Loot
{
	int Quest_Num;
	int Quest_kill;
	int Quest_Start;
	int FreePoints;
	int ClickNPC;
};
extern Quest_User QuestUser[7400];
extern Quest_Boss QuestBoss[7400];
extern Quest_Loot QuestLoot[7400];