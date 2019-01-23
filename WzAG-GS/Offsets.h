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

#define OBJECT_POINTER(aIndex)              ((aIndex * OBJECT_SIZE) + OBJECT_BASE)
#define OBJECT_BASE					        0x653DBF8
#define OBJECT_SIZE					        0x1570
#define OBJECT_MIN					        6400
#define OBJECT_MAX					        7400
#define OBJMAXUSER                          1000
#define MonsterCount	                    0x0AB5BCC8
#define OBJ_MAXMONSTER                      10600
#define OBJECT_RANGE(x)                     (((x) < 0) ? 0: ((x) >= 10000) ? 0 :1)
#define CC_MAP_RANGE(x)                     (((x) < 18) ? 0: ((x) > 23) ? (((x) == 53 ) ? 1:0 ) :1)
#define ShopExcellentMod_Hook1	            0x004EFE84
#define ShopExcellentMod_Exit1	            0x004EFE8F
#define ShopExcellentMod_Hook2	            0x004EF3FC
#define ShopExcellentMod_Exit2	            0x004EF401
#define GetNumber                           0x0048C4B0
#define GetToken                            0x0048C500
#define ITEMGET(X,Y)                        ((X * 32) + Y)
#define MAX_VIEWPORT						75 
#define MAX_VIEWPORT_MONSTER				20


#define gObjLifeCheck					    ((void(*)(OBJECTSTRUCT* lpTargetObj, OBJECTSTRUCT* lpObj, int AttackDamage, int DamageSendType, int MSBFlag, int MSBDamage, BYTE Skill, int iShieldDamage)) 0x004C36E0)
#define LogTextAdd							((void(*)(BYTE type, char* msg, int len))	0x00488B00)
#define GetPartyCount						((int(*)(int party_number)) 0x0048F020)
#define PHeadSetB							((void(*)(LPBYTE lpBuf, BYTE head, int size)) 0x0048A2A0)
#define NpcJewelMixDealer					((bool(*)(OBJECTSTRUCT*, OBJECTSTRUCT*)) 0x005229F0)
#define LogAddFunc							((void(*)(char* szLog, ...)) 0x00488C30)
#define GCMagicAttackNumberSend				((void(*)(OBJECTSTRUCT* lpObj, BYTE MagicNumber, int usernumber,  unsigned char skillsuccess))	0x0043F100)
#define GCServerCmd							((void(*)(int aIndex, BYTE type, BYTE Cmd1, BYTE Cmd2)) 0x004016B3)
#define NpcShadowPhantom					((bool(*)(OBJECTSTRUCT*, OBJECTSTRUCT*)) 0x00523020)
#define CGTradeRequestSend					((void(*)(PMSG_TRADE_REQUEST* lpMsg, int aIndex)) 0x00432DB0)
#define CGCheckMainRecv						((void(*)(LPBYTE* lpMsg, int aIndex)) 0x004289C0)
#define gObjMagicAdd						((int(*)(OBJECTSTRUCT lpObj, unsigned char aSkill, unsigned char Level)) 0x004D8CF0)
#define gObjMagicDel						((int(*)(OBJECTSTRUCT lpObj, unsigned char aSkill, unsigned char Level)) 0x004D9130)
#define MsgSendV2							((void(*)(OBJECTSTRUCT*, unsigned char* Msg, int size)) 0x004284C0)
#define gObjPlayerKiller					((void(*)(OBJECTSTRUCT*, OBJECTSTRUCT*)) 0x004BE870)
#define gObjSetInventory1Pointer			((void(*)(OBJECTSTRUCT* lpObj)) 0x004BBB20)
#define gObjSetInventory2Pointer			((void(*)(OBJECTSTRUCT* lpObj)) 0x004BBB80)
#define CGItemDropRequest					((bool(*)(PMSG_ITEMTHROW*, int aIndex, BOOL dType)) 0x0042DA40)
#define NpcTalkEx                           ((BOOL(*) (OBJECTSTRUCT* lpNpc, OBJECTSTRUCT* lpObj)) 0x005211D0)
#define gObjShopBuyInventoryInsertItem		((int(*)(int, CItem)) 0x004C6610)
#define ItemSerialCreateSend				((int(*)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD)) 0x00421750)
#define CGLevelUpPointAdd					((int(*)(PBYTE Arg1, DWORD PlayerID))	0x0042B7E0)
#define gObjGetIndex						((int(*)(const char*))	0x004BB6A0)
#define gObjGetItemCountInIventory			((int(*)(int, WORD)) 0x004DD310)
#define GCSendQuestPrize					((int(*)(int, int, int)) 0x004448F0)
#define gObjCalcMaxLifePower				((int(*)(int aIndex)) 0x004DE3D0)
#define ItemGetNumberMake					((DWORD(*)(DWORD,DWORD))	0x004EC600)
#define GCStateInfoSend						((int(*) (int, int, int)) 0x0043F350)
#define gObjAddMonster						((short(*)(int)) 0x004040A2)
#define gObjSetMonster				        ((bool(*)(int,int)) 0x004026FD)
#define ProtocolCore						((void(*)(BYTE protoNum, unsigned char* pData, int pSize, int uIndex, BOOL Encrypt, int Serial)) 0x00426D40)
#define DataSend							((void(*)(DWORD PlayerID, PBYTE Packet, DWORD Size)) 0x00474F40)
#define DataRecv							((void(*)(BYTE, PBYTE, DWORD, ...)) 0x00476930)
#define GCMoneySend							((void(*)(DWORD aIndex, DWORD Money))	0x0042C270)
#define GCServerMsgStringSend				((void(*)(char* Text, DWORD aIndex, int Type))	0x00429D60)
#define GCPkLevelSend						((void(*)(DWORD aIndex, BYTE PkLevel))	0x0042BA30)
#define gObjMoveGate						((void(*)(int aIndex, int Gate)) 0x004D6C60)
#define CloseClient							((void(*)(int)) 0x00475B00)
#define GCLevelUpMsgSend					((void(*)(int aIndex, WORD Level, WORD LevelUpPoint, WORD MaxLife, WORD MaxMana, WORD MaxBP)) 0x0042B730)
#define gObjInventoryDeleteItem				((void(*)(int,int)) 0x004C57B0)
#define GCInventoryItemDeleteSend			((void(*)(int,int,unsigned char))	0x00442CB0)
#define GCEquipmentSend						((void(*)(int)) 0x0042BEC0)
#define GCItemListSend						((void(*)(int)) 0x00420380)
#define gObjCloseSet						((void(*)(DWORD aIndex, DWORD flag)) 0x004B2950)
#define gObjTeleport					    ((void(*)(int aIndex, int MapNumber, int X, int Y))	0x004D8200)
#define gObjDel								((short(*)(int)) 0x004BA570)
#define gObjMakePreviewCharSet				((void(*)(int)) 0x004CD890)
#define gObjViewportListProtocolCreate		((void(*)(OBJECTSTRUCT* lpObj)) 0x004D37E0)
#define gObjMonsterDieGiveItem				((void(*)(OBJECTSTRUCT*, OBJECTSTRUCT*)) 0x00415880)
#define gObjUserDie							((void(*)(OBJECTSTRUCT*, OBJECTSTRUCT*)) 0x004BEE90)
#define PChatProc                           ((void(*)(PMSG_CHATDATA* lpChat, short aIndex)) 0x00429190)
#define FriendListRequest				    ((void(*)(int aIndex)) 0x0040429B)
#define DGGuildMemberInfoRequest		    ((void(*)(int aIndex)) 0x00403148)
#define CGRequestQuestInfo				    ((void(*)(int aIndex)) 0x00404A57)
#define GCMagicListMultiSend			    ((void(*)(OBJECTSTRUCT* lpObj, unsigned char btListType)) 0x00403D2D)
#define gObjClearViewport				    ((void(*)(OBJECTSTRUCT* lpObj)) 0x004029F5)
#define KundunEventItemBoxOpen			    ((void(*)(OBJECTSTRUCT* lpObj, unsigned char btMapNumber, unsigned char cX, unsigned char cY)) 0x00401B04)
#define gObjSetBP				            ((void(*)(int aIndex)) 0x004B4AC0)
#define GCReFillSend			      	    ((void(*)(WORD, WORD, BYTE, BYTE)) 0x00442B40)
#define GCManaSend					        ((void(*)(DWORD, WORD, BYTE, BYTE, WORD)) 0x00442BC0)
#define GCWarehouseStateSend                ((void(*)(int aIndex, char state)) 0x0043C770)
#define GCWarehouseRecivePassword           ((void(*)(int aIndex, PMSG_WAREHOUSEPASSSEND *lpMsg)) 0x0043C7D0)
#define ChaosBoxInit					    ((int(*)(OBJECTSTRUCT* lpObj)) 0x0040402F)
#define GCUserChaosBoxSend				    ((void(*)(OBJECTSTRUCT* lpObj, int iChaosBoxType)) 0x0040489A)
#define CGWarehouseUseEnd                   ((void(*)(int aIndex)) 0x0043C620)
#define gObjSetCharacter                    ((bool(*)(LPBYTE lpdata, int aIndex)) 0x004B4DC0)
#define j_gObjAdd                           ((short(*)(SOCKET, char*, int)) 0x004B8EC0)
#define gObjInterfaceTimeCheck              ((void(*)(LPOBJ lpObj)) 0x004BFF30)
#define gObjSecondProc                      ((void(*)()) 0x004D2070)
#define gObjAttack                          ((int(*)(LPOBJ lpObj, LPOBJ lpTargetObj, class CMagicInf* lpMagic, int magicsend, unsigned char MSBFlag, int AttackDamage, BOOL bCombo))(0x004C2960))
#define ItemDurRepaire                      ((void(*)(LPOBJ lpObj, CItem * DurItem, int pos, int RequestPos)) 0x004326F0)
#define gObjTradeCancel				        ((void(*)(int index)) 0x004CC4A0)
#define JGCharacterCreateFailSend	        ((void(*)(DWORD, char*)) 0x0041FB40)
#define CGPartyRequestRecv                  ((void(*)(PMSG_PARTYREQUEST* lpMsg, int aIndex)) 0x00437440)
#define gObjNextExpCal						((void(*)(LPOBJ))(0x004BE4A0))
#define gObjIsConnected                     ((int(*)(LPOBJ)) 0x004BAAB0)
#define gObjIsConnected2					((bool(*)(int aIndex))0x004BAB10)
#define gObjCalcSetItemStat					((void(*)(LPOBJ)) 0x004A80D0)
#define gObjCalcSetItemOption				((void(*)(LPOBJ)) 0x004A85B0)
#define gObjValidItem						((BOOL(*)(LPOBJ, CItem*, int)) 0x004A9F70)
#define GObjExtItemApply					((void(*)(LPOBJ)) 0x004A75F0)
#define gObjSetItemApply					((void(*)(LPOBJ)) 0x004A9890)
#define gObjInventoryMoveItem				((BYTE(*)(int, BYTE, BYTE, int&, int&, BYTE, BYTE, LPBYTE)) 0x004C8D80)
#define gObjViewportPaint				    ((void(*)(HWND hWnd, short aIndex)) 0x004CE3F0)
#define gObjLevelUp							((bool(*)(LPOBJ lpObj, int addexp, int iMonsterType, int iEventType))(0x004BCEB0))
#define ServerMaxUser                       *(int*)0x627E68
#define TotalUser						    *(int*)0x8BF8B18
#define GDGetWarehouseList					((void(*)(int aIndex, char* AccountID)) 0x00420960)
#define	getAddExperience					0x00628DC4
#define SetORGetDrop_Offset					0x00628D8C
#define gObjMonsterTopHitDamageUser			((int(*)(OBJECTSTRUCT* lpObj)) 0x0040F9B0)
#define gEventMonsterItemDropOri			((int(*)(OBJECTSTRUCT*,OBJECTSTRUCT*)) 0x00417220)
#define MsgOutput							((void(*)(DWORD aIndex,char *szMsg, ...))	0x004E1620) // OK
#define gObjInventoryItemSet				((void(*)(int,int,BYTE)) 0x004C51F0) // Ok
#define GCInventoryItemOneSend				((void(*)(int,int)) 0x0042B960) // Ok

//Draconick Exclusive.
#define GameMonsterAllCloseAndReLoad		(( void(*)()) 0x004F6AE0)
#define ShopDataLoad						(( void(*)()) 0x004EFFA0)
#define ReadCommonServerInfo				(( void(*)()) 0x004F7440)
#define ReadEventInfo						(( void(*)(int)) 0x004FB110)
#define ReadGameEtcInfo						(( void(*)(int)) 0x004FCCD0)
#define CObjUseSkill_SkillSummon			((void(*)(int,int))0x004A12A0)
#define	SkillMonsterCall					((bool (*) (int aIndex ,int MonsterType ,int x,int y)) 0x00404129)
#define	KnightSkillAddLife					((void(*) (int aIndex, int skill_level, int MagicNumber)) 0x00403AD0)
#define	WizardMagicDefense					((void(*) (int aIndex, int aTargetIndex, int skill_level, WORD SkillNr)) 0x0040472D)
#define gObjAddCallMon				        ((short(*)()) 0x0040112C)
#define GCRecallMonLife				        ((void(*)(int aIndex, int maxlife, int life)) 0x00403F30)
#define gObjMonsterCallKill					((void(*)(int aIndex))0x004014CE)
#define ChatSend							((void(*)(LPOBJ lpObj,char* text))0x00402FE5)
#define GCActionSend						((void(*)(LPOBJ lpObj, BYTE ActionNumber, int aIndex, int aTargetIndex))0x00404390)
enum OBJECT_TYPE 
{
	EMPTY		= -1,
	MONSTER		= 2,
	PLAYER		= 1,
	NPC		    = 3
};

enum OBJECT_STATE
{
	OFFLINE		= 0,
	CONNECTED	= 1,
	LOGGED		= 2,
	PLAYING		= 3
};

enum CLASS_NUMBER 
{
	WIZARD		= 0,
	KNIGHT		= 1,
	ELF			= 2,
	MAGUMSA		= 3,
	DARKLORD	= 4
};

typedef enum
{
	Azul		= 0,
	Verde		= 1,
	Amarelo		= 2
};

typedef enum
{
	Free = 0,
	Bronze = 1,
	Prata = 2,
	Ouro = 3,
	Platina = 4,
	Infinity = 5
};

enum PLAYER_QUEST
{
    QUEST_COMPENSATION_CHANGEUP    = 201,
    QUEST_COMPENSATION_STATUP      = 200,
    QUEST_COMPENSATION_PLUSSSTAT   = 202,
    QUEST_COMPENSATION_COMBOSKILL  = 203,
    QUEST_COMPENSATION_CHANGEUP3RD = 204,
    QUEST_MINLEVEL_PLUSSTAT        = 220,
    QUEST_STATE_SIZE                = 50
};

enum ClassNumber 
{
	CLASS_WIZARD	= 0x0,
	CLASS_KNIGHT	= 0x1,
	CLASS_ELF		= 0x2,
	CLASS_MAGUMSA	= 0x3,
	CLASS_DARKLORD	= 0x4,
};


enum DB_CLASS_CODES 
{
	DB_DARK_WIZARD		        = 0,
	DB_SOUL_MASTER		        = 1,
	
	DB_DARK_KNIGHT		        = 16,
	DB_BLADE_KNIGHT		        = 17,
	
	DB_FAIRY_ELF		        = 32,
	DB_MUSE_ELF			        = 33,
	
	DB_MAGIC_GLADIATOR	        = 48,
	DB_DARK_LORD		        = 64,

};

enum SkillType
{
	AT_SKILL_POISON = 0x1,
	AT_SKILL_METEO = 0x2,
	AT_SKILL_THUNDER = 0x3,
	AT_SKILL_FIREBALL = 0x4,
	AT_SKILL_FLAME = 0x5,
	AT_SKILL_TELEPORT = 0x6,
	AT_SKILL_SLOW = 0x7,
	AT_SKILL_STORM = 0x8,
	AT_SKILL_EVIL = 0x9,
	AT_SKILL_HELL = 0xa,
	AT_SKILL_POWERWAVE = 0xb,
	AT_SKILL_FLASH = 0xc,
	AT_SKILL_BLAST = 0xd,
	AT_SKILL_INFERNO = 0xe,
	AT_SKILL_TARGET_TELEPORT = 0xf,
	AT_SKILL_MAGICDEFENSE = 0x10,
	AT_SKILL_ENERGYBALL = 0x11,
	AT_SKILL_BLOCKING = 0x12,
	AT_SKILL_SWORD1 = 0x13,
	AT_SKILL_SWORD2 = 0x14,
	AT_SKILL_SWORD3 = 0x15,
	AT_SKILL_SWORD4 = 0x16,
	AT_SKILL_SWORD5 = 0x17,
	AT_SKILL_CROSSBOW = 0x18,
	AT_SKILL_BOW = 0x19,
	AT_SKILL_HEALING = 0x1a,
	AT_SKILL_DEFENSE = 0x1b,
	AT_SKILL_ATTACK = 0x1c,
	AT_SKILL_CALLMON1 = 0x1e,
	AT_SKILL_CALLMON2 = 0x1f,
	AT_SKILL_CALLMON3 = 0x20,
	AT_SKILL_CALLMON4 = 0x21,
	AT_SKILL_CALLMON5 = 0x22,
	AT_SKILL_CALLMON6 = 0x23,
	AT_SKILL_CALLMON7 = 0x24,
	AT_SKILL_WHEEL = 0x29,
	AT_SKILL_BLOWOFFURY = 0x2a,
	AT_SKILL_STRIKE = 0x2b,
	AT_SKILL_KNIGHTSPEAR = 0x2f,
	AT_SKILL_KNIGHTADDLIFE = 0x30,
	AT_SKILL_KNIGHTDINORANT = 0x31,
	AT_SKILL_ELFHARDEN = 0x33,
	AT_SKILL_PENETRATION = 0x34,
	AT_SKILL_DEFENSEDOWN = 0x37,
	AT_SKILL_SWORD6 = 0x38,
	AT_SKILL_5CROSSBOW = 0x36,
	AT_SKILL_EXPPOISON = 0x26,
	AT_SKILL_EXPICE = 0x27,
	AT_SKILL_EXPHELL = 0x28,
	AT_SKILL_EXPHELL_START = 0x3a,
	AT_SKILL_IMPROVE_AG_REFILL = 0x35,
	AT_SKILL_DEVILFIRE = 0x32,
	AT_SKILL_COMBO = 0x3b,
	AT_SKILL_SPEAR = 0x3c,
	AT_SKILL_FIREBURST = 0x3d,
	AT_SKILL_DARKHORSE_ATTACK = 0x3e,
	AT_SKILL_RECALL_PARTY = 0x3f,
	AT_SKILL_ADD_CRITICALDAMAGE = 0x40,
	AT_SKILL_ELECTRICSPARK = 0x41,
	AT_SKILL_LONGSPEAR = 0x42,
	AT_SKILL_RUSH = 0x2c,
	AT_SKILL_JAVALIN = 0x2d,
	AT_SKILL_DEEPIMPACT = 0x2e,
	AT_SKILL_ONE_FLASH = 0x39,
	AT_SKILL_DEATH_CANNON = 0x49,
	AT_SKILL_SPACE_SPLIT = 0x4a,
	AT_SKILL_BRAND_OF_SKILL = 0x4b,
	AT_SKILL_STUN = 0x43,
	AT_SKILL_REMOVAL_STUN = 0x44,
	AT_SKILL_ADD_MANA = 0x45,
	AT_SKILL_INVISIBLE = 0x46,
	AT_SKILL_REMOVAL_INVISIBLE = 0x47,
	AT_SKILL_REMOVAL_MAGIC = 0x48,
	AT_SKILL_FENRIR_ATTACK = 0x4c,
	AT_SKILL_INFINITY_ARROW = 0x4d,
	AT_SKILL_FIRESCREAM = 0x4e,
	AT_SKILL_EXPLOSION = 0x4f,
	AT_SKILL_SUMMON = 0xc8,
	AT_SKILL_IMMUNE_TO_MAGIC = 0xc9,
	AT_SKILL_IMMUNE_TO_HARM = 0xca,
};

enum MU_ETC_TYPE {
	MU_ETC_ALL = 0x0,
	MU_ETC_CREATECHARACTER = 0x1,
	MU_ETC_GUILD = 0x2,
	MU_ETC_TRADE = 0x3,
	MU_ETC_USECHAOSBOX = 0x4,
	MU_ETC_PERSONALSHOP = 0x5,
	MU_ETC_PKITEMDROP = 0x6,
	MU_ETC_ITEMDROPRATE = 0x7,
	MU_ETC_SPEEDHACK = 0x8,
	MU_ETC_GAMEGUARD = 0x9,
};

enum MU_EVENT_TYPE {
	MU_EVENT_ALL = 0x0,
	MU_EVENT_DEVILSQUARE = 0x1,
	MU_EVENT_BLOODCASTLE = 0x2,
	MU_EVENT_ATTACKEVENTTROOP = 0x3,
	MU_EVENT_GOLDENTROOP = 0x4,
	MU_EVENT_WHITEMAGETROOP = 0x5,
	MU_EVENT_LOVEPANGPANG = 0x6,
	MU_EVENT_FIRECRACKER = 0x7,
	MU_EVENT_MEDALION = 0x8,
	MU_EVENT_XMASSTAR = 0x9,
	MU_EVENT_HEARTOFLOVE = 0xa,
	MU_EVENT_SAY_HAPPYNEWYEAR = 0xb,
	MU_EVENT_SAY_MERRYXMAS = 0xc,
	MU_EVENT_CHAOSCASTLE = 0xd,
	MU_EVENT_CHRISTMAS_RIBBONBOX = 0xe,
	MU_EVENT_VALENTINESDAY_CHOCOLATEBOX = 0xf,
	MU_EVENT_WHITEDAY_CANDYBOX = 0x10,
};