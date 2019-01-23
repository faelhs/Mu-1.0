//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 0.97.40T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#pragma once

#define OBJECT_BASE                         0x3CCEF10
#define OBJECT_SIZE                         0x158C
#define OBJECT_MIN                          2500
#define OBJECT_MAX                          4000
#define OBJMAXUSER                          1500
#define OBJECT_RANGE(x)                     (((x) < 0) ? 0: ((x) >= 10000) ? 0 :1)
#define CC_MAP_RANGE(x)                     (((x) < 18) ? 0: ((x) > 23) ? (((x) == 53 ) ? 1:0 ) :1)
#define ShopExcellentMod_Hook1	            0x00504884
#define ShopExcellentMod_Exit1	            0x0050488F
#define ShopExcellentMod_Hook2	            0x00503DFC
#define ShopExcellentMod_Exit2	            0x00503E01
#define GetNumber	                        0x0049F660
#define GetToken	                        0x0049F6B0
#define GS_CASTLESIEGESTAT                  0x0053ABD0
#define ITEMGET(X,Y)                        ((X * 32) + Y)

#define DataSend							((void(*) (DWORD PlayerID, PBYTE Packet, DWORD Size)) 0x004878D0)
#define ProtocolCore						((void(*) (BYTE protoNum, unsigned char* pData, int pSize, int uIndex, BOOL Encrypt, int Serial)) 0x0042A660)
#define PHeadSetB							((void(*) (LPBYTE lpBuf, BYTE head, int size))	0x0049D450)
#define GCServerMsgStringSend				((void(*) (char* Text, DWORD aIndex, int Type))	0x0042D6A0)
#define GCMagicAttackNumberSend				((void(*) (OBJECTSTRUCT* lpObj, BYTE MagicNumber, int usernumber,  unsigned char skillsuccess))	0x00442180)
#define GCMoneySend							((void(*)(DWORD aIndex, DWORD Money))	0x0042FBB0)
#define GCLevelUpMsgSend					((void(*)(int aIndex, WORD Level, WORD LevelUpPoint, WORD MaxLife, WORD MaxMana, WORD MaxBP)) 0x0042F070)
#define GCInventoryItemDeleteSend			((void(*)(int,int,unsigned char))	0x00445EF0)
#define gObjSetBP				    		((void(*)(int aIndex)) 0x004C7BE0)
#define GCReFillSend			   		    ((void(*)(WORD, WORD, BYTE, BYTE)) 0x00445D80)
#define GCManaSend							((void(*)(DWORD, WORD, BYTE, BYTE, WORD)) 0x00445E00)
#define GCPkLevelSend						((void(*)(DWORD aIndex, BYTE PkLevel))	0x0042F370)
#define CGWarehouseUseEnd           		((void(*)(int aIndex)) 0x0043F3C0)
#define gObjTeleport			    		((void(*)(int aIndex, int MapNumber, int X, int Y))	0x004ECB30)
#define ItemSerialCreateSend				((int(*)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD)) 0x00423AF0)
#define gObjViewportListProtocolCreate		((void(*)(OBJECTSTRUCT* lpObj)) 0x004E7870)
#define GCItemListSend						((void(*)(int)) 0x00422720)
#define GCMagicListMultiSend			    ((void(*)(OBJECTSTRUCT* lpObj, unsigned char btListType)) 0x0042F630)
#define CGRequestQuestInfo				    ((void(*)(int aIndex)) 0x00447870)
#define DGGuildMemberInfoRequest		    ((void(*)(int aIndex)) 0x00452EC0)
#define FriendListRequest				    ((void(*)(int aIndex)) 0x00455F20)
#define GCDiePlayerSend					    ((void(*)(OBJECTSTRUCT* lpObj, int TargetIndex, BYTE skill, int KillerIndex)) 0x00441A80)
#define gObjPlayerKiller					((void(*)(OBJECTSTRUCT*, OBJECTSTRUCT*)) 0x004D1EA0)
#define ItemGetNumberMake					((DWORD(*)(DWORD,DWORD))	0x00501000)
#define gObjViewportPaint                   ((void(*)(HWND hWnd, short aIndex)) 0x004E1EC0)
#define gObjClearViewport				    ((void(*)(OBJECTSTRUCT* lpObj)) 0x004C5940)
#define gObjAttack                          ((int(*)(LPOBJ lpObj, LPOBJ lpTargetObj, class CMagicInf* lpMagic, int magicsend, unsigned char MSBFlag, int AttackDamage, BOOL bCombo))(0x004D6050))
#define gObjSetCharacter                    ((bool(*)(LPBYTE lpdata, int aIndex)) 0x004C7EE0)
#define GCStateInfoSend						((int(*) (int, int, int))	0x004423D0)
#define ItemDurRepaire                      ((void(*)(LPOBJ lpObj, CItem * DurItem, int pos, int RequestPos)) 0x00436060)
#define j_gObjAdd                           ((short(*)(SOCKET, char*, int)) 0x004CC220)
#define gObjInterfaceTimeCheck              ((void(*)(LPOBJ lpObj)) 0x004D3620)
#define gObjSecondProc                      ((void(*)()) 0x004E5FB0)
#define PChatProc                           ((void(*)(PMSG_CHATDATA* lpChat, short aIndex)) 0x0042CAD0)
#define gObjTradeCancel				        ((void(*)(int index)) 0x004DFF70)
#define CloseClient							((void(*)(DWORD)) 0x00488490)
#define JGCharacterCreateFailSend	        ((void(*)(DWORD, char*)) 0x00421EE0)
#define gObjNextExpCal						((void(*)(LPOBJ))(0x004D1A10))
#define gObjCalcMaxLifePower				((int(*)(int aIndex)) 0x004F2C80)
#define gObjCalcSetItemStat					((void(*)(LPOBJ)) 0x004BB800)
#define gObjCalcSetItemOption				((void(*)(LPOBJ)) 0x004BBCE0)
#define gObjValidItem						((BOOL(*)(LPOBJ, CItem*, int)) 0x004BD6A0)
#define GObjExtItemApply					((void(*)(LPOBJ)) 0x004BAD20)
#define gObjSetItemApply					((void(*)(LPOBJ)) 0x004BCFC0)
#define gObjViewportPaint				    ((void(*)(HWND hWnd, short aIndex)) 0x004E1EC0)
#define gObjLevelUp							((bool(*)(LPOBJ lpObj, int addexp, int iMonsterType, int iEventType))(0x004D0420))
#define ServerMaxUser                       *(int*)0x685BF0
#define TotalUser						    *(int*)0x51D9C30
#define gObjMonsterTopHitDamageUser			((int(*)(OBJECTSTRUCT* lpObj)) 0x004118D0) // OK
#define gEventMonsterItemDrop				((int(*)(OBJECTSTRUCT *,OBJECTSTRUCT *)) 0x00419490) // OK
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
	Free		= 0,
	Bronze		= 1,
	Prata		= 2,
	Ouro		= 3
};

enum eSkillType
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