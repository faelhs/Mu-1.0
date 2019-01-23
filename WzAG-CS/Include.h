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

#include "Fixes.h"         
#include "Offsets.h"
#include "Biblioteca.h"
#include "Functions.h"
#include "Packets.h"
#include "Protocol.h"
#include "Tips.h"
#include "News.h"
#include "License.h"
#include "Customs.h"
#include "Comandos.h"
#include "MasterReset.h"
#include "Reset.h"
#include "Flood.h"
#include "Tokenizer.h"
#include "Connect.h"
#include "Manager.h"
#include "Database.h"
#include "Shop.h"
#include "UnicodeChar.h"
#include "Log.h"
#include "Ware.h"
#include "Balancer.h"
#include "Display.h"
#include "ItemDrop.h"

#define CFG_SVINFO		"./Data/ServerInfo.dat"
#define CFG_GAMESERVER	"../DKData/Config.ini"
#define CFG_NEWS		"../DKData/Noticias.ini"
#define CFG_DICAS		"../DKData/Dicas.ini"
#define CFG_COMMAND		"../DKData/Comandos.ini"
#define CFG_RESET		"../DKData/Reset.ini"
#define CFG_MRESET		"../DKData/MReset.ini"
#define CFG_QUERY		"../DKData/Querys.ini"
#define CFG_CHARACTER	"../DKData/Character.ini"
#define ITEM_DROP		"../DKData/ItemDrop.txt"

void Load();
