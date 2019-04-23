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

#include "Fixes.h"         
#include "Offsets.h"
#include "Biblioteca.h"
#include "Packets.h"
#include "Functions.h"
#include "Comandos.h"
#include "Connect.h"
#include "Customs.h"
#include "Protocol.h"
#include "Tips.h"
#include "News.h"
#include "Hydra.h"
#include "Reset.h"
#include "License.h"
#include "MasterReset.h"
#include "Tokenizer.h"
#include "Flood.h"
#include "UnicodeChar.h"
#include "Ware.h"
#include "Manager.h"
#include "Database.h"
#include "Shop.h"
#include "NpcTalk.h"
#include "Log.h"
#include "Balancer.h"
#include "DuelEvent.h"
#include "PegaEvent.h"
#include "SobreEvent.h"
#include "Teleport.h"
#include "Castle.h"
#include "Blood.h"
#include "Display.h"
#include "AutoXP.h"
#include "DropEvent.h"
#include "HHour.h"
#include "VipSystem.h"
#include "Helper.h"
#include "ItemDrop.h"
#include "Quest.h"
#include "Quest_Elf.h"
#include "Quest_Boss.h"
#include "Quest_Loot.h"
#include "Storm.h"
#include "GoldenArcher.h"
#include "GMSystem.h"
#include "ElfBuffer.h"
#include "GCMagicAttackNumberSend.h"
#include "MagicInf.h"
#include "Jewels.h"
#include "GoldShop.h"
#include "Sorteio.h"
#include "Quest_Item_Reward.h" 
#include "gObjAttack.h"
#include "Bot.h"
#include "Premio_Diario.h"
#include "CashShop.h"
#include "CShopNPC.h"
#include "ReadScript.h"

#define CFG_SVINFO					"./Data/ServerInfo.dat"
#define CFG_GAMESERVER				"../DKData/Config.ini"
#define CFG_NEWS					"../DKData/Noticias.ini"
#define CFG_DICAS					"../DKData/Dicas.ini"
#define CFG_COMMAND					"../DKData/Comandos.ini"
#define CFG_RESET					"../DKData/Reset.ini"
#define CFG_MRESET					"../DKData/MReset.ini"
#define CFG_QUERY					"../DKData/Querys.ini"
#define CFG_CHARACTER				"../DKData/Character.ini"
#define CFG_MATAMATA				"../DKData/MataMata.ini"
#define CFG_PEGAPEGA				"../DKData/PegaPega.ini"
#define CFG_SURVIVOR				"../DKData/Survivor.ini"
#define CFG_GOWTHER					"../DKData/Gowther.ini"
#define CFG_GMSYSTEM				"../DKData/GMSystem.ini"
#define CFG_DROPBC					"../DKData/Blood.txt"
#define CFG_DROPCC					"../DKData/Castle.txt"
#define CFG_DROP					"../DKData/ItemDrop.txt"
#define CFG_HELPER					"../DKData/Helper.ini"
#define CFG_VIP						"../DKData/VipSystem.ini"
#define CFG_JEWELS      			"../DKData/Jewels.ini"  
#define CFG_AUTOXP					"../DKData/AutoXP.ini"
#define CFG_DROPEVT					"../DKData/DropEvent.ini"
#define CFG_HHOUR					"../DKData/HHour.ini"
#define CFG_HYDRA					"../DKData/Hydra.txt"
#define CFG_MOVE					"../DKData/Moves.txt"
#define CFG_STORM					"../DKData/Storm.ini"
#define CFG_SHADOWF					"../DKData/ShadowPhantom.ini"
#define CFG_SORTEIO					"../DKData/Sorteio.ini"
#define CFG_GOLDSHOP				"../DKData/GoldShop.ini"
#define CFG_QUEST					"../DKData/Quests/Quest_Main.ini"
#define CFG_QUEST_ELF				"../DKData/Quests/Quest_ELF.ini"
#define CFG_QUEST_BOSS				"../DKData/Quests/Quest_Boss.ini"
#define CFG_QUEST_LOOT				"../DKData/Quests/Quest_Loot.ini"
#define CFG_Quest_Item_Reward		"../DKData/Quests/Quest_Item_Reward.ini"
#define CFG_PVPSystem				"../DKData/PVPSystem.ini"
#define CFG_PremioDiario			"../DKData/Premio_Diario.ini"
#define CFG_Faccao					"../DKData/facção.ini"



//NPCS
#define NPC_Quest						249
#define NPC_Quest_Elf					247
#define NPC_Quest_Boss					201
#define NPC_Quest_Loot					202
#define NPC_Helper						234	
#define NPC_Gowter						236
void Loaddll();