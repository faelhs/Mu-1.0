//===================================================================================
// [#] - WentMu TeaM - 0.99.60T - PREMIUM
//===================================================================================

#include "StdAfx.h"

//===================================================================================
// [#] - Comandos Settings
//===================================================================================

bool Commands::Load()
{



	GetPrivateProfileString("Vip", "NameFree", "Free", this->_vipname[0],25, CFG_COMMAND);
	GetPrivateProfileString("Vip", "NameVip1", "Bronze", this->_vipname[1], 25, CFG_COMMAND);
	GetPrivateProfileString("Vip", "NameVip2", "Prata", this->_vipname[2], 25, CFG_COMMAND);
	GetPrivateProfileString("Vip", "NameVip3", "Ouro", this->_vipname[3], 25, CFG_COMMAND);
	GetPrivateProfileString("Vip", "NameVip4", "Platina", this->_vipname[4], 25, CFG_COMMAND);
	GetPrivateProfileString("Vip", "NameVip5", "Infinity", this->_vipname[5], 25, CFG_COMMAND);

	this->_Active[0] = GetPrivateProfileInt("Comando Post","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Level[0] = GetPrivateProfileInt("Comando Post","NeedLevel",1,CFG_COMMAND);
	this->_Zen[0] = GetPrivateProfileInt("Comando Post","NeedZen",1000,CFG_COMMAND);
	this->_Vip[0] = GetPrivateProfileInt("Comando Post","NeedVip",0,CFG_COMMAND);
	this->_Delay = GetPrivateProfileInt("Comando Post","TimeDelay",10,CFG_COMMAND);	
	this->_Color = GetPrivateProfileInt("Comando Post","TypeColor",1,CFG_COMMAND);
	GetPrivateProfileString("Comando Post","Formato","[POST]:%s",this->_Formato,50,CFG_COMMAND);
	GetPrivateProfileString("Comando Post","Sintax","/post",this->_Syntax[0],25,CFG_COMMAND);

	this->_Active[1] = GetPrivateProfileInt("Comando Adicionar","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Level[1] = GetPrivateProfileInt("Comando Adicionar","NeedLevel",1,CFG_COMMAND);
	this->_Zen[1] = GetPrivateProfileInt("Comando Adicionar","NeedZen",1000,CFG_COMMAND);
	this->_Vip[1] = GetPrivateProfileInt("Comando Adicionar","NeedVip",1,CFG_COMMAND);
	GetPrivateProfileString("Comando Adicionar","Sintax 1","/for",this->_Syntax[1],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Adicionar","Sintax 2","/agi",this->_Syntax[2],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Adicionar","Sintax 3","/vit",this->_Syntax[3],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Adicionar","Sintax 4","/ene",this->_Syntax[4],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Adicionar","Sintax 5","/cmd",this->_Syntax[5],25,CFG_COMMAND);

	this->_Active[2] = GetPrivateProfileInt("Comando Readicionar","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Level[2] = GetPrivateProfileInt("Comando Readicionar","NeedLevel",350,CFG_COMMAND);
	this->_Zen[2] = GetPrivateProfileInt("Comando Readicionar","NeedZen",10000,CFG_COMMAND);
	this->_Vip[2] = GetPrivateProfileInt("Comando Readicionar","NeedVip",1,CFG_COMMAND);
	GetPrivateProfileString("Comando Readicionar","Sintax","/readd",this->_Syntax[6],25,CFG_COMMAND);

	this->_Active[3] = GetPrivateProfileInt("Comando Clear","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Level[3] = GetPrivateProfileInt("Comando Clear","NeedLevel",1,CFG_COMMAND);
	this->_Zen[3] = GetPrivateProfileInt("Comando Clear","NeedZen",1000,CFG_COMMAND);
	this->_Vip[3] = GetPrivateProfileInt("Comando Clear", "NeedVip", 1, CFG_COMMAND);
	this->_Gold[3] = GetPrivateProfileInt("Comando Clear", "NeedGold", 5, CFG_COMMAND);
	GetPrivateProfileString("Comando Clear","Sintax","/limparpk",this->_Syntax[7],25,CFG_COMMAND);

	this->_Active[4] = GetPrivateProfileInt("Comando Baú","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Level[4] = GetPrivateProfileInt("Comando Baú","NeedLevel",1,CFG_COMMAND);
	this->_Zen[4] = GetPrivateProfileInt("Comando Baú","NeedZen",10000,CFG_COMMAND);
	this->_Vip[4] = GetPrivateProfileInt("Comando Baú","NeedVip",1,CFG_COMMAND);
	this->_Ware[0] = GetPrivateProfileInt("Comando Baú","LimitFree",3,CFG_COMMAND);
	this->_Ware[1] = GetPrivateProfileInt("Comando Baú","LimitVip1",5,CFG_COMMAND);
	this->_Ware[2] = GetPrivateProfileInt("Comando Baú","LimitVip2",7,CFG_COMMAND);
	this->_Ware[3] = GetPrivateProfileInt("Comando Baú", "LimitVip3", 9, CFG_COMMAND);
	this->_Ware[4] = GetPrivateProfileInt("Comando Baú", "LimitVip4", 11, CFG_COMMAND);
	this->_Ware[5] = GetPrivateProfileInt("Comando Baú", "LimitVip5", 13, CFG_COMMAND);
	GetPrivateProfileString("Comando Baú","Sintax","/bau",this->_Syntax[8],25,CFG_COMMAND);

	this->_Active[5] = GetPrivateProfileInt("Comando Zen","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Vip[5] = GetPrivateProfileInt("Comando Zen","NeedVip",1,CFG_COMMAND);
	this->_OnlyGM[5] = GetPrivateProfileInt("Comando Zen", "OnlyGM", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Zen","Sintax","/zen",this->_Syntax[9],25,CFG_COMMAND);
	
	this->_Active[6] = GetPrivateProfileInt("Comando Online", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	this->_Zen[6] = GetPrivateProfileInt("Comando Online","NeedZen",10000,CFG_COMMAND);
	this->_Vip[6] = GetPrivateProfileInt("Comando Online", "NeedVip", 1, CFG_COMMAND);
	this->_OnlyGM[6] = GetPrivateProfileInt("Comando Online", "OnlyGM", 1, CFG_COMMAND)> 0 ? true : false;
	GetPrivateProfileString("Comando Online","Sintax","/online",this->_Syntax[10],25,CFG_COMMAND);

	GetPrivateProfileString("Comando Siege","Sintax","/siege",this->_Syntax[11],25,CFG_COMMAND);

	this->_Active[7] = GetPrivateProfileInt("Comando Evo","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Vip[7] = GetPrivateProfileInt("Comando Evo","NeedVip",1,CFG_COMMAND);
	this->_Level[7] = GetPrivateProfileInt("Comando Evo","NeedLevel",1,CFG_COMMAND);
	this->_Zen[7] = GetPrivateProfileInt("Comando Evo","NeedZen",1000000,CFG_COMMAND);
	GetPrivateProfileString("Comando Evo","Sintax","/evo",this->_Syntax[12],25,CFG_COMMAND);

	this->_Active[8] = GetPrivateProfileInt("Comando OpenWare","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Vip[8] = GetPrivateProfileInt("Comando OpenWare","NeedVip",1,CFG_COMMAND);
	this->_Level[8] = GetPrivateProfileInt("Comando OpenWare","NeedLevel",1,CFG_COMMAND);
	this->_Zen[8] = GetPrivateProfileInt("Comando OpenWare","NeedZen",1000000,CFG_COMMAND);
	GetPrivateProfileString("Comando OpenWare","Sintax","/open",this->_Syntax[13],25,CFG_COMMAND);

	this->_Active[9] = GetPrivateProfileInt("Comando ChangeClasse","Active",1,CFG_COMMAND) > 0 ? true : false;
	this->_Vip[9] = GetPrivateProfileInt("Comando ChangeClasse","NeedVip",1,CFG_COMMAND);
	this->_Level[9] = GetPrivateProfileInt("Comando ChangeClasse","NeedLevel",1,CFG_COMMAND);
	this->_Zen[9] = GetPrivateProfileInt("Comando ChangeClasse","NeedZen",1000000,CFG_COMMAND);
	this->_OnlyGM[9] = GetPrivateProfileInt("Comando ChangeClasse", "OnlyGm", 0, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando ChangeClasse","Sintax DW","/classe dw",this->_Syntax[14],25,CFG_COMMAND);
	GetPrivateProfileString("Comando ChangeClasse","Sintax SM","/classe sm",this->_Syntax[15],25,CFG_COMMAND);
	GetPrivateProfileString("Comando ChangeClasse","Sintax DK","/classe dw",this->_Syntax[16],25,CFG_COMMAND);
	GetPrivateProfileString("Comando ChangeClasse","Sintax BK","/classe sm",this->_Syntax[17],25,CFG_COMMAND);
	GetPrivateProfileString("Comando ChangeClasse","Sintax ELF","/classe elf",this->_Syntax[18],25,CFG_COMMAND);
	GetPrivateProfileString("Comando ChangeClasse","Sintax ME","/classe me",this->_Syntax[19],25,CFG_COMMAND);
	GetPrivateProfileString("Comando ChangeClasse","Sintax MG","/classe mg",this->_Syntax[20],25,CFG_COMMAND);
	GetPrivateProfileString("Comando ChangeClasse","Sintax DL","/classe dl",this->_Syntax[21],25,CFG_COMMAND);

	GetPrivateProfileString("Comando Premiar","Sintax","/premiar",this->_Syntax[22],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Premiar","Mensagem","",this->_Notice,60,CFG_COMMAND);
	GetPrivateProfileString("Querys","UPDATE PREMIAR","",this->_Query,255,CFG_QUERY);
	GetPrivateProfileString("Comando Moveall","Sintax","/moveall",this->_Syntax[23],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Skin","Sintax","/skin",this->_Syntax[24],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Gmove","Sintax","/gmove",this->_Syntax[25],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Drop","Sintax","/drop",this->_Syntax[26],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Visible","Sintax","/visible",this->_Syntax[27],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Invisible","Sintax","/invisible",this->_Syntax[28],25,CFG_COMMAND);
	GetPrivateProfileString("Comando Storm","Sintax","/storm",this->_Syntax[29],25,CFG_COMMAND);

	this->_Active[10] = GetPrivateProfileInt("Comando Reload", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Reload", "Sintax", "/reload", this->_Syntax[30], 25, CFG_COMMAND);

	this->_Active[11] = GetPrivateProfileInt("Comando SetLevel", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando SetLevel", "Sintax", "/setlevel", this->_Syntax[31], 25, CFG_COMMAND);

	this->_Active[12] = GetPrivateProfileInt("Comando SetPts", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando SetPts", "Sintax", "/setpts", this->_Syntax[32], 25, CFG_COMMAND);
	GetPrivateProfileString("Comando SetPts", "SintaxF", "/setfor", this->_Syntax[33], 25, CFG_COMMAND);
	GetPrivateProfileString("Comando SetPts", "SintaxA", "/setagi", this->_Syntax[34], 25, CFG_COMMAND);
	GetPrivateProfileString("Comando SetPts", "SintaxV", "/setvit", this->_Syntax[35], 25, CFG_COMMAND);
	GetPrivateProfileString("Comando SetPts", "SintaxE", "/setene", this->_Syntax[36], 25, CFG_COMMAND);
	GetPrivateProfileString("Comando SetPts", "SintaxC", "/setcmd", this->_Syntax[37], 25, CFG_COMMAND);
	GetPrivateProfileString("Comando SetPts", "SintaxR", "/setres", this->_Syntax[47], 25, CFG_COMMAND);

	this->_Active[13] = GetPrivateProfileInt("Comando MakeSet", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando MakeSet", "Sintax", "/makeset", this->_Syntax[38], 25, CFG_COMMAND);

	this->_Active[14] = GetPrivateProfileInt("Comando Comprar", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Comprar", "Sintax", "/comprar", this->_Syntax[39], 25, CFG_COMMAND);
	GetPrivateProfileString("Querys", "UPDATE COMPRAR", "", this->_QueryComprar, 255, CFG_QUERY);

	this->_Active[15] = GetPrivateProfileInt("Comando Listar", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Listar", "Sintax", "/listar", this->_Syntax[40], 25, CFG_COMMAND);
	
	this->_Active[16] = GetPrivateProfileInt("Comando Make", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Make", "Sintax", "/make", this->_Syntax[41], 25, CFG_COMMAND);

	this->_Active[17] = GetPrivateProfileInt("Comando FakeName", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando FakeName", "Sintax", "/fakename", this->_Syntax[42], 25, CFG_COMMAND);

	this->_Active[18] = GetPrivateProfileInt("Comando SetQuest", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando SetQuest", "Sintax", "/setquest", this->_Syntax[43], 25, CFG_COMMAND);

	this->_Active[19] = GetPrivateProfileInt("Comando Spawn", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Spawn", "Sintax", "/spawn", this->_Syntax[44], 25, CFG_COMMAND);

	this->_Active[20] = GetPrivateProfileInt("Comando ClearInv", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	this->_Vip[10] = GetPrivateProfileInt("Comando ClearInv", "NeedVip", 1, CFG_COMMAND);
	this->_Level[10] = GetPrivateProfileInt("Comando ClearInv", "NeedLevel", 1, CFG_COMMAND);
	this->_Zen[10] = GetPrivateProfileInt("Comando ClearInv", "NeedZen", 1000000, CFG_COMMAND);
	GetPrivateProfileString("Comando ClearInv", "Sintax", "/limparinv", this->_Syntax[45], 25, CFG_COMMAND);

	this->_Active[21] = GetPrivateProfileInt("Comando OpenCashShop", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando OpenCashShop", "Sintax", "/cashshop", this->_Syntax[46], 25, CFG_COMMAND);

	this->_Active[22] = GetPrivateProfileInt("Comando QuestInfo", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando QuestInfo", "Sintax", "/questinfo", this->_Syntax[48], 25, CFG_COMMAND);

	this->_Active[23] = GetPrivateProfileInt("Comando Ping", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Ping", "Sintax", "/ping", this->_Syntax[49], 25, CFG_COMMAND);

	this->_Active[24] = GetPrivateProfileInt("Comando Goto", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Goto", "Sintax", "/goto", this->_Syntax[50], 25, CFG_COMMAND);

	this->_Active[25] = GetPrivateProfileInt("Comando Recall", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Recall", "Sintax", "/recall", this->_Syntax[51], 25, CFG_COMMAND);
	
	this->_Active[26] = GetPrivateProfileInt("Comando Pet", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	this->_Vip[26] = GetPrivateProfileInt("Comando Pet", "NeedVip", 1, CFG_COMMAND);
	this->_Level[26] = GetPrivateProfileInt("Comando Pet", "NeedLevel", 1, CFG_COMMAND);
	this->_Zen[26] = GetPrivateProfileInt("Comando Pet", "NeedZen", 1000000, CFG_COMMAND);
	GetPrivateProfileString("Comando Pet", "Sintax", "/pet", this->_Syntax[52], 25, CFG_COMMAND);
	
	this->_Active[27] = GetPrivateProfileInt("Comando Bot", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Bot", "Sintax", "/bot", this->_Syntax[53], 25, CFG_COMMAND);

	this->_Active[28] = GetPrivateProfileInt("Comando GoQuest", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	this->_Vip[28] = GetPrivateProfileInt("Comando GoQuest", "NeedVip", 1, CFG_COMMAND);
	this->_Level[28] = GetPrivateProfileInt("Comando GoQuest", "NeedLevel", 1, CFG_COMMAND);
	this->_Zen[28] = GetPrivateProfileInt("Comando GoQuest", "NeedZen", 1000000, CFG_COMMAND);
	GetPrivateProfileString("Comando GoQuest", "Sintax", "/goquest", this->_Syntax[54], 25, CFG_COMMAND);

	this->_Active[29] = GetPrivateProfileInt("Comando Jain", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Jail", "Sintax Jail", "/jail", this->_Syntax[55], 25, CFG_COMMAND);
	GetPrivateProfileString("Comando Jail", "Sintax UnJail", "/unjail", this->_Syntax[56], 25, CFG_COMMAND);

	this->_Active[30] = GetPrivateProfileInt("Comando Dice", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Dice", "Sintax", "/dice", this->_Syntax[57], 25, CFG_COMMAND);
	this->_Vip[30] = GetPrivateProfileInt("Comando Dice", "NeedVip", 1, CFG_COMMAND);
	this->_Level[30] = GetPrivateProfileInt("Comando Dice", "NeedLevel", 1, CFG_COMMAND);
	this->_Zen[30] = GetPrivateProfileInt("Comando Dice", "NeedZen", 0, CFG_COMMAND);
	
	this->_Active[31] = GetPrivateProfileInt("Comando Sortear", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando Sortear", "Sintax", "/sortear", this->_Syntax[58], 25, CFG_COMMAND);

	this->_Active[32] = GetPrivateProfileInt("Comando EventStart", "Active", 1, CFG_COMMAND) > 0 ? true : false;
	GetPrivateProfileString("Comando EventStart", "Sintax", "/event", this->_Syntax[59], 25, CFG_COMMAND);

	return true;
}

//===================================================================================
// [#] - Chat Protocol
//===================================================================================

bool Commands::ChatRecv(PMSG_CHATDATA * lpMsg, int aIndex)
{
	if (Duel.Check(&gObj[aIndex], lpMsg->message))
	{
		return true;
	}

	if (Pega.Check(&gObj[aIndex], lpMsg->message))
	{
		return true;
	}

	if (Sobre.Check(&gObj[aIndex], lpMsg->message))
	{
		return true;
	}

	if (!_stricmp((const char*)(lpMsg->message),"/info"))
	{
		func.MsgUser(aIndex,0,"Conta: %s :: ViP: %s :: Level %d",gObj[aIndex].AccountID, this->_vipname[Custom[aIndex].VipIndex],gObj[aIndex].Level);
		func.MsgUser(aIndex,0,"Nome: %s :: Level Points: %d",gObj[aIndex].Name,gObj[aIndex].LevelUpPoint);
		func.MsgUser(aIndex, 0, "Resets: %d :: Master Resets: %d", Custom[aIndex].Resets, Custom[aIndex].Masters);
		func.MsgUser(aIndex, 0, "Golds: %d ", Manager.GoldCount(gObj[aIndex].AccountID));

		return true;
	}

	if (!_stricmp((const char*)(lpMsg->message),this->_Syntax[11]))
	{
		Duel.Quit(&gObj[aIndex]);
		Pega.Quit(&gObj[aIndex]);
		Sobre.Quit(&gObj[aIndex]);

		if (gObj[aIndex].Level >= 200) 
        { 
           gObjTeleport(aIndex,30,31,40); 
        } 
		
		return true;
	}

	if (!_memicmp(lpMsg->message, "/move ", 6))
	{
	    Duel.Quit(&gObj[aIndex]);
		Pega.Quit(&gObj[aIndex]);
		Sobre.Quit(&gObj[aIndex]);

		return false;
	}

	if (!_stricmp((const char*)(lpMsg->message),this->_Syntax[6]))
	{
		ReAdicionar(aIndex);
		return true;
	}

	if (!_stricmp((const char*)(lpMsg->message),this->_Syntax[7]))
	{
		Clear(aIndex);
		return true;
	}

	if (!_memicmp(lpMsg->message, this->_Syntax[9], strlen(this->_Syntax[9])))
	{
		Money(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[9])));
		return true;
	}

	if(!_stricmp((const char*)(lpMsg->message),this->_Syntax[10]))
	{
		Online(aIndex);
		return true;
	}

	if (!_stricmp((const char*)(lpMsg->message),Reset._Syntax))
	{
		Reset.InitExec(aIndex);
		return true;
	}

	if (!_stricmp((const char*)(lpMsg->message),MReset._Syntax))
	{
		MReset.InitExec(aIndex);
		return true;
	}
	if(!_stricmp((const char*)(lpMsg->message),this->_Syntax[13]))
	{
		OpenWare(aIndex);
		return true;
	}
	
	if(!_stricmp((const char*)(lpMsg->message),this->_Syntax[29]))
	{
		StormCommand(aIndex);
		return true;
	}


	for (int i = 0; i < TeleportEx.CountMoves; i++)
	{
		if (!_stricmp((const char*)(lpMsg->message),Teleport[i].Syntax))
		{
			Duel.Quit(&gObj[aIndex]);
			Pega.Quit(&gObj[aIndex]);
			Sobre.Quit(&gObj[aIndex]);
			gObjTeleportEx::InitTeleport(aIndex,i);
			return true;
		}
	}

	
	if (!_memicmp(lpMsg->message,this->_Syntax[0],strlen(this->_Syntax[0])))
	{
		Post(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[0])));
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[1],strlen(this->_Syntax[1])))
	{
		Adicionar(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[1])),1);
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[2],strlen(this->_Syntax[2])))
	{
		Adicionar(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[2])),2);
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[3],strlen(this->_Syntax[3])))
	{
		Adicionar(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[3])),3);
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[4],strlen(this->_Syntax[4])))
	{
		Adicionar(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[4])),4);
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[5],strlen(this->_Syntax[5])))
	{
		Adicionar(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[5])),5);
		return true;
	}
	
	if (!_memicmp(lpMsg->message,this->_Syntax[8],strlen(this->_Syntax[8])))
	{
		Ware(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[8])));
		return true;
	}


	if(!_memicmp(lpMsg->message,this->_Syntax[12],strlen(this->_Syntax[12])))
	{
		Evo(aIndex,(char*)lpMsg->message+strlen(this->_Syntax[12]));
		return true;
	}
	
	if (!_memicmp(lpMsg->message,this->_Syntax[22],strlen(this->_Syntax[22])))
	{
		Premiar(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[23])));
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[23],strlen(this->_Syntax[23])))
	{
		MoveAll(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[23])));
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[24],strlen(this->_Syntax[24])))
	{
		Skin(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[24])));
		return true;
	}

	if (!_memicmp(lpMsg->message,this->_Syntax[25],strlen(this->_Syntax[25])))
	{
		Move(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[25])));
		return true;
	}
	
	if(!_memicmp(lpMsg->message,this->_Syntax[26],strlen(this->_Syntax[26])))
	{
		Drop(aIndex,(char*)(lpMsg->message+strlen(this->_Syntax[26])));
		return true;
	}

	if(!_memicmp(lpMsg->message,this->_Syntax[28],strlen(this->_Syntax[28])))
	{
		Visible(aIndex,(char*)lpMsg->message+strlen(this->_Syntax[28]),1);
		return true;
	}
	
	if(!_memicmp(lpMsg->message,this->_Syntax[27],strlen(this->_Syntax[27])))
	{
		Visible(aIndex,(char*)lpMsg->message+strlen(this->_Syntax[27]),2);
		return true;
	}
	
	if(!_memicmp(lpMsg->message,this->_Syntax[14],strlen(this->_Syntax[14])))
	{
		Classe(aIndex,(char*)lpMsg->message+strlen(this->_Syntax[14]),0);
		return true;
	}

	if(!_memicmp(lpMsg->message,this->_Syntax[15],strlen(this->_Syntax[15])))
	{
		Classe(aIndex,(char*)lpMsg->message+strlen(this->_Syntax[15]),1);
		return true;
	}

	if(!_memicmp(lpMsg->message,this->_Syntax[16],strlen(this->_Syntax[16])))
	{
		Classe(aIndex,(char*)lpMsg->message+strlen(this->_Syntax[16]),2);
		return true;
	}

	if(!_memicmp(lpMsg->message,this->_Syntax[17],strlen(this->_Syntax[17])))
	{
		Classe(aIndex,(char*)lpMsg->message+strlen(this->_Syntax[17]),3);
		return true;
	}

	if(!_memicmp(lpMsg->message,this->_Syntax[18],strlen(this->_Syntax[18])))
	{
		Classe(aIndex,(char*)lpMsg->message+strlen(this->_Syntax[18]),4);
		return true;
	}		

	if(!_memicmp(lpMsg->message,this->_Syntax[19],strlen(this->_Syntax[19])))
	{
		Classe(aIndex,(char*)lpMsg->message+strlen(this->_Syntax[19]),5);
		return true;
	}

	if(!_memicmp(lpMsg->message,this->_Syntax[20],strlen(this->_Syntax[20])))
	{
		Classe(aIndex,(char*)lpMsg->message+strlen(this->_Syntax[20]),6);
		return true;
	}

	if(!_memicmp(lpMsg->message,this->_Syntax[21],strlen(this->_Syntax[21])))
	{
		Classe(aIndex,(char*)lpMsg->message+strlen(this->_Syntax[21]),7);
		return true;
	}

	if (!_memicmp(lpMsg->message, this->_Syntax[30], strlen(this->_Syntax[30])))
	{
		Reload(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[30])));
		return true;
	}

	if (!_memicmp(lpMsg->message, this->_Syntax[31], strlen(this->_Syntax[31])))
	{
		SetLevel(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[31])));
		return true;
	}

	if (!_memicmp(lpMsg->message, this->_Syntax[32], strlen(this->_Syntax[32])))
	{
		SetPts(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[32])),0);
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[33], strlen(this->_Syntax[33])))
	{
		SetPts(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[33])), 1);
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[34], strlen(this->_Syntax[34])))
	{
		SetPts(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[34])), 2);
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[35], strlen(this->_Syntax[35])))
	{
		SetPts(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[35])), 3);
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[36], strlen(this->_Syntax[36])))
	{
		SetPts(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[36])), 4);
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[37], strlen(this->_Syntax[37])))
	{
		SetPts(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[37])), 5);
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[47], strlen(this->_Syntax[47])))
	{
		SetPts(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[47])), 6);
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[38], strlen(this->_Syntax[38])))
	{
		MakeSet(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[38])));
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[39], strlen(this->_Syntax[39])))
	{
		Comprar(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[39])));
		return true;
	}

	if (!_memicmp(lpMsg->message, this->_Syntax[40], strlen(this->_Syntax[40])))
	{
		Listar(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[40])));
		return true;
	}

	if (!_memicmp(lpMsg->message, this->_Syntax[41], strlen(this->_Syntax[41])))
	{
		Make(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[41])));
		return true;
	}

	if (!_memicmp(lpMsg->message, this->_Syntax[42], strlen(this->_Syntax[42])))
	{
		FakeName(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[42])));
		return true;
	}

	if (!_memicmp(lpMsg->message, this->_Syntax[43], strlen(this->_Syntax[43])))
	{
		SetQuest(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[43])));
		return true;
	}
	
	if (!_memicmp(lpMsg->message, this->_Syntax[44], strlen(this->_Syntax[44])))
	{
		Spawn(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[44])));
		return true;
	}
	

	if (!_memicmp(lpMsg->message, this->_Syntax[45], strlen(this->_Syntax[45])))
	{
		ClearInvCommand(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[45])));
		return true;
	}
	
	if (!_memicmp(lpMsg->message, this->_Syntax[46], strlen(this->_Syntax[46])))
	{
		OpenCashShopCommand(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[46])));
		return true;
	}
	
	//Syntas 47 no setrests.

	if (!_stricmp((const char*)(lpMsg->message), this->_Syntax[48]))
	{
		QuestInfo(aIndex);
		return true;
	}
	if (!_stricmp((const char*)(lpMsg->message), this->_Syntax[49]))
	{
		Ping(aIndex);
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[50], strlen(this->_Syntax[50])))
	{
		Goto(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[50])));
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[51], strlen(this->_Syntax[51])))
	{
		Recall(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[51])));
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[52], strlen(this->_Syntax[52])))
	{
		Pet(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[52])));
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[53], strlen(this->_Syntax[53])))
	{
		mBot(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[53])));
		return true;
	}
	if (!_stricmp((const char*)(lpMsg->message), this->_Syntax[54]))
	{
		GoQuest(aIndex);
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[55], strlen(this->_Syntax[55])))
	{
		Jail(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[55])), 1);
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[56], strlen(this->_Syntax[56])))
	{
		Jail(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[56])), 2);
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[57], strlen(this->_Syntax[57])))
	{
		Dice(aIndex);
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[58], strlen(this->_Syntax[58])))
	{
		ComandoSortear(aIndex);
		return true;
	}
	if (!_memicmp(lpMsg->message, this->_Syntax[59], strlen(this->_Syntax[59])))
	{
		EventStart(aIndex, (char*)(lpMsg->message + strlen(this->_Syntax[59])));
		return true;
	}
	return false;
}

//===================================================================================
// [#] - Comandos Players
//===================================================================================

void Commands::Post(int aIndex, char* msg)
{
	DWORD Time = (GetTickCount() - Custom[aIndex].PostDelay) / 1000;

	if (!this->_Active[0])
	{
		func.MsgUser(aIndex,1,"Comando Desligado..");
		return;  
	}
	else if (gObj[aIndex].Level < this->_Level[0])
	{
		func.MsgUser(aIndex,1,"Você não possui level %d", this->_Level[0]);
		return;
	}
	else if (gObj[aIndex].Money < this->_Zen[0])
	{
		func.MsgUser(aIndex,1,"Você não possui Zen %d", this->_Zen[0]);
		return;
	}
	else if (this->_Vip[0] == 1)
	{
		if(Custom[aIndex].VipIndex < 1)
		{
			func.MsgUser(aIndex,1,"Somente Vips");
			return;
		}
	}
	if (this->_Delay > Time)
	{
		func.MsgUser(aIndex,1,"Poderá usar em [%d] segundos.",(this->_Delay - Time));
		return;
	}

	char Buffer[60];

	sprintf(Buffer, this->_Formato, msg);

	if (this->_Color == Azul)
	{
		func.BlueChatSend(gObj[aIndex].Name,Buffer,aIndex);
	}
	if(this->_Color == Verde)
	{
		func.GreenChatSend(gObj[aIndex].Name,Buffer,aIndex);
	}
	if(this->_Color == Amarelo)
	{
		func.YellowChatSend(gObj[aIndex].Name,Buffer,aIndex);
	}

	Custom[aIndex].PostDelay = GetTickCount();

	GCMoneySend(aIndex,gObj[aIndex].Money -= this->_Zen[0]);
}

void Commands::Adicionar(int aIndex, LPCSTR Buffer, int Status)
{
	int Pontos = atoi(Buffer);

	if (!this->_Active[1])
	{
		func.MsgUser(aIndex,1,"Comando Desligado..");
		return;  
	}
	else if (Pontos <= 0)
	{
		return;
	}
	else if (gObj[aIndex].Level < this->_Level[1])
	{
		func.MsgUser(aIndex,1,"Você não possui level %d", this->_Level[1]);
		return;
	}
	else if(gObj[aIndex].Money < this->_Zen[1])
	{
		func.MsgUser(aIndex,1,"Você não possui Zen %d", this->_Zen[1]);
		return;
	}
	else if (this->_Vip[1] == 1)
	{
		if(Custom[aIndex].VipIndex < 1)
		{
			func.MsgUser(aIndex,1,"Somente Vips");
			return;
		}
	}
	else if (Pontos > gObj[aIndex].LevelUpPoint)
	{
		func.MsgUser(aIndex,1,"Faltam %d pontos.", (Pontos - gObj[aIndex].LevelUpPoint));
		return;
	}
	else if (32700 <= Pontos)
	{
		func.MsgUser(aIndex,1,"Maximo de pontos a adicionar 32700");
		return;
	}
	else
	{
		if (Status == 1)
		{
			if ((gObj[aIndex].Strength + Pontos) >= 32767)
			{
				func.MsgUser(aIndex,1,"Limite de pontos permitidos 32767");
				return;
			}
			else
			{
				gObj[aIndex].Strength += Pontos;

				func.MsgUser(aIndex,1,"Adicionado %d pontos em Força",Pontos);
			}
		}
		else if (Status == 2)
		{
			if ((gObj[aIndex].Dexterity + Pontos) >= 32767)
			{
				func.MsgUser(aIndex,1,"Limite de pontos permitidos 32767");
				return;
			}
			else
			{
				gObj[aIndex].Dexterity += Pontos;

				func.MsgUser(aIndex,1,"Adicionado %d pontos em Agilidade ",Pontos);
			}
		}
		else if (Status == 3)
		{
			if ((gObj[aIndex].Vitality + Pontos) >= 32767)
			{
				func.MsgUser(aIndex,1,"Limite de pontos permitidos 32767");
				return;
			}
			else
			{
				gObj[aIndex].Vitality += Pontos;

				func.MsgUser(aIndex,1,"Adicionado %d pontos em Vitalidade",Pontos);
			}
		}
		else if (Status == 4)
		{
			if ((gObj[aIndex].Energy + Pontos) >= 32767)
			{
				func.MsgUser(aIndex,1,"Limite de pontos permitidos 32767");
				return;
			}
			else
			{
				gObj[aIndex].Energy += Pontos;

				func.MsgUser(aIndex,1,"Adicionado %d pontos em Energia",Pontos);
			}
		}
		else if (Status == 5)
		{
			if (gObj[aIndex].Class != 4)
			{
				func.MsgUser(aIndex,1,"Comando disponível para Dark Lord!");
			    return;
			}
			else if ((gObj[aIndex].Leadership + Pontos) >= 32767)
			{
				func.MsgUser(aIndex,1,"Limite de pontos permitidos 32767");
				return;
			}
			else
			{
				gObj[aIndex].Leadership += Pontos;

				func.MsgUser(aIndex,1,"Adicionado %d pontos em Comando",Pontos);
			}
		}

		GCMoneySend(aIndex,gObj[aIndex].Money -= this->_Zen[1]);
		gObj[aIndex].LevelUpPoint -= Pontos;
		gObj[aIndex].MaxLife = gObj[aIndex].VitalityToLife * gObj[aIndex].Vitality;
		gObj[aIndex].Life = gObj[aIndex].MaxLife;
		gObj[aIndex].AddLife = 0;
		gObj[aIndex].MaxMana = gObj[aIndex].EnergyToMana * gObj[aIndex].Energy;
		gObj[aIndex].Mana = gObj[aIndex].MaxMana;
		gObj[aIndex].AddMana = 0;
		gObjSetBP(gObj[aIndex].m_Index);
		gObj[aIndex].BP = gObj[aIndex].MaxBP;
		gObj[aIndex].AddBP = 0;

		func.UpdateCharacter(aIndex, false);

		func.LevelUPSend(aIndex);
	}
}

void Commands::ReAdicionar(int aIndex)
{
	if (!this->_Active[2])
	{
		func.MsgUser(aIndex,1,"Comando Desligado.");
		return;  
	}
	else if (gObj[aIndex].Level < this->_Level[2])
	{
		func.MsgUser(aIndex,1,"Você não possui level %d", this->_Level[2]);
		return; 	
	}
	else if(gObj[aIndex].Money < this->_Zen[2])
	{
		func.MsgUser(aIndex,1,"Você não possui Zen %d", this->_Zen[2]);
		return;
	}
	else if (this->_Vip[2] == 1)
	{
		if(Custom[aIndex].VipIndex < 1)
		{
			func.MsgUser(aIndex,1,"Somente Vips");
			return;
		}
	}

	UINT uiPoints;

	uiPoints = ((gObj[aIndex].Strength + gObj[aIndex].Dexterity) + (gObj[aIndex].Vitality + gObj[aIndex].Energy)) - 100;
	uiPoints += gObj[aIndex].LevelUpPoint;

	if(gObj[aIndex].Class == 4)
	{
		uiPoints += (gObj[aIndex].Leadership) - 25;
	}

	GCMoneySend(aIndex,gObj[aIndex].Money -= this->_Zen[2]);
	gObj[aIndex].LevelUpPoint		= uiPoints >= 4294967290 ? 4294967290 : uiPoints;
	gObj[aIndex].Experience         = 0;
	gObj[aIndex].Strength			= 25;
	gObj[aIndex].Dexterity			= 25;
	gObj[aIndex].Vitality			= 25;
	gObj[aIndex].Energy			    = 25;
	gObj[aIndex].Leadership         = 25;
	gObj[aIndex].MaxLife = gObj[aIndex].VitalityToLife * gObj[aIndex].Vitality;
	gObj[aIndex].Life = gObj[aIndex].MaxLife;
	gObj[aIndex].AddLife = 0;
	gObj[aIndex].MaxMana = gObj[aIndex].EnergyToMana * gObj[aIndex].Energy;
	gObj[aIndex].Mana = gObj[aIndex].MaxMana;
	gObj[aIndex].AddMana = 0;
	gObjSetBP(gObj[aIndex].m_Index);
	gObj[aIndex].BP = gObj[aIndex].MaxBP;
	gObj[aIndex].AddBP = 0;

	func.UpdateCharacter(aIndex, false);
	func.MsgUser(aIndex,1,"%d disponiveis para distribuição.",gObj[aIndex].LevelUpPoint);
	func.LevelUPSend(aIndex);
}

void Commands::Clear(int aIndex)
{ 
	if (!this->_Active[3])
	{
		func.MsgUser(aIndex,1,"Comando Desligado.");
		return;  
	}
	else if (gObj[aIndex].Level < this->_Level[3])
	{
		func.MsgUser(aIndex,1,"Você não possui level %d",this->_Level[3]);
		return;
	}
	else if (gObj[aIndex].Money < this->_Zen[3])
	{
		func.MsgUser(aIndex,1,"Você não possui Zen %d",this->_Zen[3]);
		return;
	}
	else if (this->_Vip[3] == 1)
	{
		if (Custom[aIndex].VipIndex < 1)
		{
			func.MsgUser(aIndex, 1, "Somente Vips");
			return;
		}
	}
	else if (this->_Gold[3] > Custom[aIndex].mCash)
	{
			func.MsgUser(aIndex, 1, "Você não tem Golds para isso. ");
			return;
	}
	else if (gObj[aIndex].m_PK_Level < 5)
	{		
		func.MsgUser(aIndex,1,"Você não está PK");
		return;
	}
	if (this->_Gold[3] > 0) {
		Custom[aIndex].mCash -= this->_Gold[3];
		Manager.ExecFormat(this->_QueryComprar, this->_Gold[3], gObj[aIndex].AccountID);
		func.MsgUser(aIndex, 1, "Golds pagos: %d",this->_Gold[3]);
	}

	gObj[aIndex].m_PK_Level = 3;
	gObj[aIndex].m_PK_Count = 0;
	gObj[aIndex].m_PK_Time  = 0;
	GCMoneySend(aIndex,gObj[aIndex].Money -= this->_Zen[3]);
	GCPkLevelSend(aIndex,gObj[aIndex].m_PK_Level);

	func.MsgUser(aIndex,1,"Pk limpo com sucesso.");
}

void Commands::Ware(int aIndex, LPCSTR Buffer)
{  
	this->_Number = atoi(Buffer);

	DWORD Time = (GetTickCount() - Custom[aIndex].WareDelay) / 1000;

	if (!this->_Active[4])
	{
		func.MsgUser(aIndex,1,"Comando Desligado.");
		return;  
	}
	else if (gObj[aIndex].Level < this->_Level[4])
	{
		func.MsgUser(aIndex,1,"Você não possui level %d",this->_Level[4]);
		return;
	}
	else if (gObj[aIndex].Money < this->_Zen[4])
	{
		func.MsgUser(aIndex,1,"Você não possui Zen %d",this->_Zen[4]);
		return;
	}
	else if (this->_Vip[4] == 1)
	{
		if(Custom[aIndex].VipIndex < 1)
		{
			func.MsgUser(aIndex,1,"Somente Vips");
			return;
		}
	}
	else if (Time < 10)
	{
		func.MsgUser(aIndex,1,"Tente trocar em [%d] segundos.",(10 - Time));
		return;
	}
	else if (gObj[aIndex].m_IfState.use == 1 || gObj[aIndex].pTransaction == 1 || gObj[aIndex].WarehouseSave == 1)
	{
		func.MsgUser(aIndex,1,"Você não pode trocar de baú agora.");
		return;
	}

	switch (Custom[aIndex].VipIndex)
	{
	case 0:
		{
			if (this->_Number > this->_Ware[0])
			{
				func.MsgUser(aIndex,1,"O seu limite de baús é %d",this->_Ware[0]);
				return;
			}
		}
		break; 
	case 1:
		{
			if (this->_Number > this->_Ware[1])
			{
				func.MsgUser(aIndex,1,"O seu limite de baús é %d",this->_Ware[1]);
				return;
			}
		}
		break; 
	case 2:
		{
			if (this->_Number > this->_Ware[2])
			{
				func.MsgUser(aIndex,1,"O seu limite de baús é %d",this->_Ware[2]);
				return;
			}
		}
		break; 
	case 3:
		{
			if (this->_Number > this->_Ware[3])
			{
				func.MsgUser(aIndex,1,"O seu limite de baús é %d",this->_Ware[3]);
				return;
			}
		}
		break; 
	case 4:
	{
		if (this->_Number > this->_Ware[4])
		{
			func.MsgUser(aIndex, 1, "O seu limite de baús é %d", this->_Ware[4]);
			return;
		}
	}
	break;
	case 5:
	{
		if (this->_Number > this->_Ware[5])
		{
			func.MsgUser(aIndex, 1, "O seu limite de baús é %d", this->_Ware[5]);
			return;
		}
	}
	break;
	}

	Manager.ExecFormat("EXEC MuOnline.dbo.MUDAR_BAU '%s', %d", gObj[aIndex].AccountID, this->_Number);

	func.MsgUser(aIndex,1,"Troca efetuada com sucesso, baú %d",this->_Number);

	GCMoneySend(aIndex,gObj[aIndex].Money -= this->_Zen[4]);
}

void Commands::Money(int aIndex, char * msg)
{
	if (!this->_Active[5])
	{
		func.MsgUser(aIndex,1,"Comando Desligado.");
		return;  
	}
	if(this->_OnlyGM[5]){
		if (gObj[aIndex].AuthorityCode < 1)
		{
			func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
			return;
		}
	}
	else if (this->_Vip[5] == 1)
	{
		if(Custom[aIndex].VipIndex < 1)
		{
			func.MsgUser(aIndex,1,"Somente Vips");
			return;
		}
	}
	int Zen = atoi(msg);
	func.MsgUser(aIndex,1,"Zen adicionado com sucesso.");

	gObj[aIndex].Money = Zen;
	GCMoneySend(aIndex,gObj[aIndex].Money);
}

void Commands::Online(int aIndex)
{
	if (!this->_Active[6])
	{
		func.MsgUser(aIndex,1,"Comando Desligado.");
		return;  
	}
	if (this->_OnlyGM[6]) {
		if (gObj[aIndex].AuthorityCode < 1)
		{
			func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
			return;
		}
	}
	else if (gObj[aIndex].Money < this->_Zen[6])
	{
		func.MsgUser(aIndex,1,"Você não possui Zen %d",this->_Zen[6]);
		return;
	}
	else if (this->_Vip[6] == 1)
	{
		if(Custom[aIndex].VipIndex < 1)
		{
			func.MsgUser(aIndex,1,"Somente Vips");
			return;
		}
	}

	DWORD PlayerCount = 0;
	DWORD GM = 0;

	for (int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if (gObj[i].Authority == 1 && gObj[i].Connected == 3)
		{
			PlayerCount++;
		}
		else if (gObj[i].Authority > 1 && gObj[i].Connected == 3)
		{
			GM++;
		}
	}

	func.MsgUser(aIndex,1,"Players onlines: %d :: GM'S onlines: %d :: Total: %d",PlayerCount,GM,(PlayerCount+GM));

	GCMoneySend(aIndex,gObj[aIndex].Money -= this->_Zen[6]);
}

void Commands::Evo(int aIndex,char * msg)
{
	if (!this->_Active[7])
	{
		func.MsgUser(aIndex,1,"Comando Desligado.");
		return;  
	}
	else if (gObj[aIndex].Level < this->_Level[7])
	{
		func.MsgUser(aIndex,1,"Você não possui level %d", this->_Level[7]);
		return;
	}
	else if(gObj[aIndex].Money < this->_Zen[7])
	{
		func.MsgUser(aIndex,1,"Você não possui Zen %d", this->_Zen[7]);
		return;
	}
	else if (this->_Vip[7] == 1)
	{
		if(Custom[aIndex].VipIndex < 1)
		{
			func.MsgUser(aIndex,1,"Somente Vips");
			return;
		}
	}

	switch(gObj[aIndex].DbClass)
	{
		case DB_DARK_WIZARD:
		case DB_DARK_KNIGHT:
		case DB_FAIRY_ELF:
		{    
			gObj[aIndex].ChangeUP             = true;
			gObj[aIndex].DbClass             |= true;
			gObj[aIndex].PlusStatQuestClear   = true;
			gObj[aIndex].ComboSkillquestClear = true;

			gObj[aIndex].LevelUpPoint       += 220;
			gObjMakePreviewCharSet(aIndex);

			BYTE btClass = (gObj[aIndex].Class << 5) & 0xE0;
			btClass |= (gObj[aIndex].ChangeUP << 4) & 0x10;
			GCSendQuestPrize(aIndex,QUEST_COMPENSATION_CHANGEUP, btClass);
			gObj[aIndex].m_Quest[0] = 0xAA;  //---> Quest Fix The Darck Stone 
			func.LevelUPSend(aIndex);
			func.MsgUser(aIndex,1,"%s Evoluiu para a segunda classe",gObj[aIndex].Name);
			gObj[aIndex].Money -= _Zen[7];
			return;
		}
		case DB_MAGIC_GLADIATOR:
		case DB_DARK_LORD:
		{
			func.MsgUser(aIndex,1,"%s Você está em sua classe final",gObj[aIndex].Name);
			return;
		}
		break;
	}
}

void Commands::OpenWare(int aIndex)
{
	
	if (!this->_Active[8])
	{
		func.MsgUser(aIndex,1,"Comando Desligado.");
		return;  
	}
	else if (gObj[aIndex].Level < this->_Level[8])
	{
		func.MsgUser(aIndex,1,"Você não possui level %d", this->_Level[8]);
		return;
	}
	else if(gObj[aIndex].Money < this->_Zen[8])
	{
		func.MsgUser(aIndex,1,"Você não possui Zen %d", this->_Zen[8]);
		return;
	}

	else if (this->_Vip[8] == 1)
	{
		if(Custom[aIndex].VipIndex < 1)
		{
			func.MsgUser(aIndex,1,"Somente Vips");
			return;
		}
	}

	if(gObj[aIndex].pTransaction == 1)
	{
		func.MsgUser(aIndex,1,"%s Feche o Trade Para Usar o Comando!",gObj[aIndex].Name);		
		return;
	}

	if(gObj[aIndex].m_IfState.use == 1 && gObj[aIndex].m_IfState.type == 7 )
	{
		func.MsgUser(aIndex,1,"%s Feche o ChaosBox Para Usar o Comando!",gObj[aIndex].Name);	
		return;
	}

	if(gObj[aIndex].m_ReqWarehouseOpen != 0  || gObj[aIndex].WarehouseSave != 0 )
	{
		func.MsgUser(aIndex,1,"%s Feche o Baú Para Usar o Comando!",gObj[aIndex].Name);	
		return;
	}


	gObj[aIndex].m_ReqWarehouseOpen = 1;
	gObj[aIndex].m_IfState.type = 6;
	gObj[aIndex].m_IfState.use = 1;
	gObj[aIndex].m_IfState.state = 0;
	gObj[aIndex].WarehouseSave = TRUE;
	gObj[aIndex].WarehouseCount = 0;
	gObj[aIndex].Money -= _Zen[8];
	

	GDGetWarehouseList(aIndex,gObj[aIndex].AccountID);
	func.LevelUPSend(aIndex);
	func.MsgUser(aIndex,1,"%s Baú aberto com sucesso ",gObj[aIndex].Name);	
}

void Commands::Classe(unsigned short aIndex, char * String, BYTE Tipo)
{
	if (!this->_Active[9])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado.");
		return;
	}
	if (this->_OnlyGM[9])
	{
		if (gObj[aIndex].AuthorityCode < 1)
		{
			func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
			return;
		}
	}
	else if (gObj[aIndex].Level < this->_Level[9])
	{
		func.MsgUser(aIndex,1,"Você não possui level %d", this->_Level[9]);
		return;
	}
	else if(gObj[aIndex].Money < this->_Zen[9])
	{
		func.MsgUser(aIndex,1,"Você não possui Zen %d", this->_Zen[9]);
		return;
	}
	
	else if (this->_Vip[9] == 1)
	{
		if(Custom[aIndex].VipIndex < 1)
		{
			func.MsgUser(aIndex,1,"Somente Vips");
			return;
		}
	}

	switch(Tipo)
	{	
		case 0: gObj[aIndex].DbClass = DB_DARK_WIZARD;								break;
		case 1: gObj[aIndex].DbClass = DB_SOUL_MASTER;								break;
		case 2: gObj[aIndex].DbClass = DB_DARK_KNIGHT;								break;
		case 3: gObj[aIndex].DbClass = DB_BLADE_KNIGHT;								break;
		case 4: gObj[aIndex].DbClass = DB_FAIRY_ELF;								break;
		case 5: gObj[aIndex].DbClass = DB_MUSE_ELF;									break;
		case 6: gObj[aIndex].DbClass = DB_MAGIC_GLADIATOR;							break;
		case 7: gObj[aIndex].DbClass = DB_DARK_LORD; 
				gObj[aIndex].AddLeadership;	
				gObj[aIndex].Leadership = 25;
				break;
		



		default:break;
	}
	gObj[aIndex].Money -= _Zen[9];
	func.MsgUser(aIndex,1,"%s Você mudou de classe",gObj[aIndex].Name);
	gObj[aIndex].CloseType  = 1;
	gObj[aIndex].CloseCount = 1;
}
void Commands::Dice(int aIndex){
	if (!this->_Active[30])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado.");
		return;
	}
	else if(gObj[aIndex].Money < this->_Zen[57])
	{
		func.MsgUser(aIndex,1,"Você não possui Zen %d", this->_Zen[9]);
		return;
	}
	else if (this->_Vip[57] == 1)
	{
		if(Custom[aIndex].VipIndex < 1)
		{
			func.MsgUser(aIndex,1,"Somente Vips");
			return;
		}
	}
	char msg[25];
	int Dice = rand() % 5;
	Dice++;
	sprintf(msg,"Dados: %d",Dice);
	func.GreenChatSend(gObj[aIndex].Name,msg,aIndex);
}
//===================================================================================
// [#] - Comandos Game Master
//===================================================================================
//SetPts
void Commands::SetPts(int aIndex, char* msg , int Status) {
	char tName[11];
	char* aName = gObj[aIndex].Name;
	int Pontos = 1;
	char log[255];
	sscanf(msg, "%s %d", tName, &Pontos);
	int tIndex = func.Get_PlayerIndex(tName);
	if (!this->_Active[12])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}
		
		else
		{
			int SetPtsGM = 0;
			for (int x = 1; x < GMSystemCount; x++)
			{
				if ( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
				{
					SetPtsGM = GMSystemInfo[x].GMSetPts;
				}
			}

			if (gObj[aIndex].AuthorityCode < 1)
			{
				func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
				return;
			}

			if (SetPtsGM == 0)
			{
				GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!", aIndex, 1);
				return;
			}
			else if (strlen(msg) < 1)
			{
				GCServerMsgStringSend("use /setpts <nome> <pontos> ex: /setpts DraconicK 32767", aIndex, 1);
				return;
			}
			
			if (gObj[tIndex].Connected < 3)
			{
				func.MsgUser(aIndex, 1, "O Personagem não se encontra.");
				return;
			}

			if (Status == 0)
			{
				gObj[tIndex].LevelUpPoint = Pontos;
				func.MsgUser(aIndex, 1, "Setado %d pontos", Pontos);
				func.MsgUser(tIndex, 1, "% Setou %d pontos",aName, Pontos);
				sprintf(log, "Pontos Setado Player: %s Pontos: %d", tName, Pontos);
				LogSystem::DKLog(gObj[aIndex].Name, log);
			}
			else if (Status == 1)
			{
				if (Pontos > 32768)
				{
					func.MsgUser(tIndex, 1, "Limite de pontos permitidos 32767");
					return;
				}
				else
				{
					gObj[tIndex].Strength = Pontos;
					func.MsgUser(aIndex, 1, "Setado %d pontos em Força", Pontos);
					func.MsgUser(tIndex, 1, "%s Setou %d pontos em Força",aName, Pontos);
					sprintf(log, "Pontos Setado Player: %s Pontos em Força: %d", tName, Pontos);
					LogSystem::DKLog(gObj[aIndex].Name, log);
				}
			}
			else if (Status == 2)
			{
				if (Pontos > 32767)
				{
					func.MsgUser(aIndex, 1, "Limite de pontos permitidos 32767");
					return;
				}
				else
				{
					gObj[tIndex].Dexterity = Pontos;
					func.MsgUser(aIndex, 1, "Setado %d pontos em Agilidade ", Pontos);
					func.MsgUser(tIndex, 1, "% Setou %d pontos em Agilidade ",aName, Pontos);
					sprintf(log, "Pontos Setado Player: %s Pontos em Agilidade: %d", tName, Pontos);
					LogSystem::DKLog(gObj[aIndex].Name, log);
				}
			}
			else if (Status == 3)
			{
				if (Pontos > 32767)
				{
					func.MsgUser(aIndex, 1, "Limite de pontos permitidos 32767");
					return;
				}
				else
				{
					gObj[tIndex].Vitality = Pontos;
					func.MsgUser(aIndex, 1, "Setado %d pontos em Vitalidade", Pontos);
					func.MsgUser(tIndex, 1, "% Setou %d pontos em Vitalidade",aName, Pontos);
					sprintf(log, "Pontos Setado Player: %s Pontos em Vitalidade: %d", tName, Pontos);
					LogSystem::DKLog(gObj[aIndex].Name, log);
				}
			}
			else if (Status == 4)
			{
				if (Pontos > 32767)
				{
					func.MsgUser(aIndex, 1, "Limite de pontos permitidos 32767");
					return;
				}
				else
				{
					gObj[tIndex].Energy = Pontos;
					func.MsgUser(aIndex, 1, "Setado %d pontos em Energia", Pontos);
					func.MsgUser(tIndex, 1, "%s Setou %d pontos em Energia",aName, Pontos);
					sprintf(log, "Pontos Setado Player: %s Pontos em Energia: %d", tName, Pontos);
					LogSystem::DKLog(gObj[aIndex].Name, log);
				}
			}
			else if (Status == 5)
			{
				if (gObj[tIndex].Class != 4)
				{
					func.MsgUser(aIndex, 1, "Personamge deve ser DarkLord!");
					return;
				}
				else if (Pontos > 32767)
				{
					func.MsgUser(aIndex, 1, "Limite de pontos permitidos 32767");
					return;
				}
				else
				{
					gObj[tIndex].Leadership = Pontos-75;
					func.MsgUser(aIndex, 1, "Setado %d pontos em Comando", Pontos);
					func.MsgUser(tIndex, 1, "%s Setou %d pontos em Comando",aName, Pontos);
					sprintf(log, "Pontos Setado Player: %s Pontos em Comando: %d", tName, Pontos);
					LogSystem::DKLog(gObj[aIndex].Name, log);
				}
			}
			else if (Status == 6)
			{
				Custom[tIndex].Resets = Pontos-1;
				Manager.ExecFormat("UPDATE MuOnline.dbo.Character SET Resets = %d WHERE Name = '%s'",Pontos,&gObj[tIndex].Name);
				gObj[tIndex].Level = 400;
				func.MsgUser(aIndex, 1, "Setado %d Resets", Pontos);
				func.MsgUser(tIndex, 1, "%s Setou %d Resets", aName, Pontos);
				sprintf(log, "Resets Setado Player: %s Resets: %d", tName, Pontos);
				func.UpdateCharacter(tIndex, false);
				func.LevelUPSend(tIndex);
				Reset.InitExec(tIndex);
			}
			gObj[tIndex].MaxLife = gObj[tIndex].VitalityToLife * gObj[tIndex].Vitality;
			gObj[tIndex].Life = gObj[tIndex].MaxLife;
			gObj[tIndex].AddLife = 0;
			gObj[tIndex].MaxMana = gObj[tIndex].EnergyToMana * gObj[tIndex].Energy;
			gObj[tIndex].Mana = gObj[tIndex].MaxMana;
			gObj[tIndex].AddMana = 0;
			gObjSetBP(gObj[tIndex].m_Index);
			gObj[tIndex].BP = gObj[tIndex].MaxBP;
			gObj[tIndex].AddBP = 0;

			func.UpdateCharacter(tIndex, false);

			func.LevelUPSend(tIndex);
		}
		
}


void Commands::Goto(int aIndex, char* msg) {
	if (!this->_Active[24])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}
	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
		return;
	}


	else if (strlen(msg) < 1)
	{
		GCServerMsgStringSend("use /goto nome ex: /goto DraconicK", aIndex, 1);
		return;
	}
	char tName[11];
	char log[255];
	sscanf(msg, "%s", tName);
	int tIndex = func.Get_PlayerIndex(tName);
	if (gObj[tIndex].Connected < 3)
	{
		func.MsgUser(aIndex, 1, "O Personagem não se encontra.");
		return;
	}
	int map, x, y;
	map = gObj[tIndex].MapNumber;
	x = gObj[tIndex].X;
	y = gObj[tIndex].Y;
	gObjTeleport(aIndex, map, x, y);
	func.MsgUser(aIndex, 1, "Teleportado para %s",gObj[tIndex].Name);
	func.MsgUser(tIndex, 1, "%s foi até você", gObj[aIndex].Name);
}


void Commands::Recall(int aIndex, char* msg) {
	if (!this->_Active[25])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}
	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
		return;
	}


	else if (strlen(msg) < 1)
	{
		GCServerMsgStringSend("use /recall nome ex: /recall DraconicK", aIndex, 1);
		return;
	}
	char tName[11];
	char log[255];
	sscanf(msg, "%s", tName);
	int tIndex = func.Get_PlayerIndex(tName);
	if (gObj[tIndex].Connected < 3)
	{
		func.MsgUser(aIndex, 1, "O Personagem não se encontra.");
		return;
	}
	int map, x, y;
	map = gObj[aIndex].MapNumber;
	x = gObj[aIndex].X;
	y = gObj[aIndex].Y;
	gObjTeleport(tIndex, map, x, y);
	func.MsgUser(tIndex, 1, "Teleportado para %s", gObj[aIndex].Name);
	func.MsgUser(aIndex, 1, "%s foi trazido até você", gObj[tIndex].Name);
}

// SetLevel
void Commands::SetLevel(int aIndex, char* msg){
	if (!this->_Active[11])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}

	int SetLevelGM = 0;
	for (int x = 1; x < GMSystemCount; x++)
	{
		if ( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			SetLevelGM = GMSystemInfo[x].GMSetLevel;
		}
	}

	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
		return;
	}

	if (SetLevelGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!", aIndex, 1);
		return;
	}



	else if (strlen(msg) < 1)
	{
		GCServerMsgStringSend("use /setlevel nome level ex: /setlevel DraconicK 400", aIndex, 1);
		return;
	}
	int level = 1;
	char tName[11];
	char log[255];
	sscanf(msg, "%s %d", tName, &level);
	int tIndex = func.Get_PlayerIndex(tName);
	int charlvl = gObj[tIndex].Level;
	int uppoints = 0;
	if (gObj[tIndex].Connected < 3)
	{
		func.MsgUser(aIndex, 1, "O Personagem não se encontra.");
		return;
	}
	if (charlvl  == level){
		func.MsgUser(aIndex, 1, "Você deve setar um level diferente do atual"); return;
	}
	if (charlvl < level) {
		uppoints = level * 5 - charlvl * 5;
		gObj[tIndex].LevelUpPoint += uppoints;
	}
	if (charlvl > level) {
		Commands::ReAdicionar(tIndex);
		int diferença = charlvl - level;
		uppoints = diferença * 5;
		gObj[tIndex].LevelUpPoint -= uppoints;
	}
	gObj[tIndex].Experience = 0;
	gObj[tIndex].Level = level;
	func.UpdateCharacter(tIndex, false);
	func.LevelUPSend(tIndex);
	gObj[tIndex].Experience = 0;
	gObj[tIndex].Level = level;
	func.UpdateCharacter(tIndex, false);
	func.LevelUPSend(tIndex);
	sprintf(log, "Level Setado Player: %s Level: %d", tName, level);
	func.MsgUser(aIndex, 1, log);
	LogSystem::DKLog(gObj[aIndex].Name, log);
	
}


//Reload
void Commands::Reload(int aIndex, char* msg) {
	if (!this->_Active[10])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}
	int ReloadGM = 0;
	for (int x = 1; x < GMSystemCount; x++)
	{
		if ( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			ReloadGM = GMSystemInfo[x].GMReload;
		}
	}

	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
		return;
	}

	if (ReloadGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!", aIndex, 1);
		return;
	}
	


	else if (strlen(msg) < 1)
	{
		GCServerMsgStringSend("use /reload <num> ex: /reload 0", aIndex, 1);
		return;
	}

	int ecv = atoi(msg);
	switch (ecv) {
	case 0: {
		Loaddll();
		LogSystem::DKLog(gObj[aIndex].Name,"Configs dll recarregada.");
		GCServerMsgStringSend("Config recarregada com sucerro.", aIndex, 1); }
		break;
	

	case 1: {
		GameMonsterAllCloseAndReLoad();
		LogSystem::DKLog(gObj[aIndex].Name, "Monstros e spots recarregados.");
		GCServerMsgStringSend("Monstros e Spots recarregados com sucesso.", aIndex, 1); }
		break;

	case 2: {
		ShopDataLoad();
		LogSystem::DKLog(gObj[aIndex].Name, "Shops recarregados.");
		GCServerMsgStringSend("Shops recarregados com sucesso.", aIndex, 1); }
		break;

	case 3: {
		ReadCommonServerInfo();
		LogSystem::DKLog(gObj[aIndex].Name, "Commonserv recarregado.");
		GCServerMsgStringSend("Commonserv recarregado com sucesso.", aIndex, 1); }
			break;

	case 4: {
		ReadEventInfo(MU_EVENT_ALL);
		LogSystem::DKLog(gObj[aIndex].Name, "Eventos recarregado.");
		GCServerMsgStringSend("Eventos recarregado com sucesso.", aIndex, 1); }
			break;

	case 5: {
		ReadGameEtcInfo(MU_ETC_ALL);
		LogSystem::DKLog(gObj[aIndex].Name, "ETC recarregado.");
		GCServerMsgStringSend("ETC recarregado com sucesso.", aIndex, 1); }
			break;

	default: {
		func.MsgUser(aIndex, 1, "Opção inexistente");
		func.MsgUser(aIndex, 1, "0 = DLL | 1 = Monstros e Spots ");
		func.MsgUser(aIndex, 1, "2 = Shops | 3 = Commonserv ");
		func.MsgUser(aIndex, 1, "4 = Eventos | 5 = ETC "); }
		LogSystem::DKLog(gObj[aIndex].Name, "Função inexistente.");
		break;
	}

}
void Commands::SetQuest(int aIndex, char* msg) {
	if (!this->_Active[18])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}
	int SetQuestGM = 0;
	for (int x = 1; x < GMSystemCount; x++)
	{
		if ( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			SetQuestGM = GMSystemInfo[x].GMSetQuest;
		}
	}

	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
		return;
	}

	if (SetQuestGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!", aIndex, 1);
		return;
	}

	else if (strlen(msg) < 1)
	{
		GCServerMsgStringSend("use /setquest <nome> <tipo> <id> ex: /setquest draconick 1 0", aIndex, 1);
		return;
	}
	char tName[11];
	int tipo, id;
	sscanf(msg, "%s %d %d", tName, &tipo, &id);
	int tIndex = func.Get_PlayerIndex(tName);
	switch (tipo) {
	case 0: {
		QuestUser[tIndex].Quest_Num = id;
		QuestUser[tIndex].Quest_kill = 0;
		QuestUser[tIndex].Quest_Start = 0;
		Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Num = %d WHERE Name='%s'", id, &gObj[tIndex].Name);
		Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Start = 0 WHERE Name='%s'", gObj[tIndex].Name);
		Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Kill = 0 WHERE Name='%s'", gObj[tIndex].Name);
		func.MsgUser(aIndex, 1, "[Quest] Main Setada");
		break;
	}
	case 1: {
		QuestBoss[tIndex].Quest_Num = id;
		QuestBoss[tIndex].Quest_kill = 0;
		QuestBoss[tIndex].Quest_Start = 0;
		Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Boss_Num = %d WHERE Name='%s'", id, &gObj[tIndex].Name);
		Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Boss_Start = 0 WHERE Name='%s'", gObj[tIndex].Name);
		Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Boss_Kill = 0 WHERE Name='%s'", gObj[tIndex].Name);
		func.MsgUser(aIndex, 1, "[Quest] Boss Setada");
		break;
	}
	case 2: {
		QuestLoot[tIndex].Quest_Num = id;
		QuestLoot[tIndex].Quest_kill = 0;
		QuestLoot[tIndex].Quest_Start = 0;
		Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Loot_Num = %d WHERE Name='%s'", id, &gObj[tIndex].Name);
		Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Loot_Start = 0 WHERE Name='%s'", gObj[tIndex].Name);
		Manager.ExecFormat("UPDATE [MuOnline].[dbo].[Character] SET Quest_Loot_Kill = 0 WHERE Name='%s'", gObj[tIndex].Name);
		func.MsgUser(aIndex, 1, "[Quest] Loot Setada");
		break;
	}
	default: {
		func.MsgUser(aIndex, 1, "Opção inexistente");
		func.MsgUser(aIndex, 1, "0 = Main | 1 = Boss ");
		func.MsgUser(aIndex, 1, "2 = Loot ");
		break;
	}
	}
}

void Commands::ClearInvCommand(int aIndex, char* IpBuffer) // Oks !!
{
	int ClrInvCode = atoi(IpBuffer);

	 if (strlen(IpBuffer) < 1)
	{
		GCServerMsgStringSend("O Sistema vai do nº 1 até 4.              ", aIndex, 1);
		GCServerMsgStringSend("nº 1 Limpa a parte de baixo do inventário.", aIndex, 1);
		GCServerMsgStringSend("nº 2 Limpa a parte de cima do inventário. ", aIndex, 1);
		GCServerMsgStringSend("nº 3 Limpa a todo o inventário.           ", aIndex, 1);
		GCServerMsgStringSend("nº 4 Zera o Zen o inventário.           ", aIndex, 1);
		return;
	}
	 if (ClrInvCode > 4 && ClrInvCode <= 0)
	{
		GCServerMsgStringSend("O Sistema vai do nº 1 até 4.              ", aIndex, 1);
		GCServerMsgStringSend("nº 1 Limpa a parte de baixo do inventário.", aIndex, 1);
		GCServerMsgStringSend("nº 2 Limpa a parte de cima do inventário. ", aIndex, 1);
		GCServerMsgStringSend("nº 3 Limpa a todo o inventário.           ", aIndex, 1);
		GCServerMsgStringSend("nº 4 Zera o Zen o inventário.           ", aIndex, 1);
		return;
	}

	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if (!this->_Active[20])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}
	if (gObj->Level < this->_Level[10])
	{
		MsgOutput(aIndex, "%s Você não tem level suficiente! Requerido: %d", gObj->Name, this->_Level[10]);
		return;
	}
	if (gObj->Money < this->_Zen[10])
	{
		MsgOutput(aIndex, "%s você não tem Zen suficiente! Requerido: %d", gObj->Name, this->_Zen[10]);
		return;
	}
	if (Custom[aIndex].VipIndex < this->_Vip[10])
	{
		GCServerMsgStringSend("Seu VIP não tem privilégios suficientes para usar o comando!", aIndex, 1);
		return;
	}

	GCMoneySend(aIndex, gObj->Money -= this->_Zen[10]);

	switch (ClrInvCode)
	{
		//==============================================================
		//-- Clear down part of inventory
		//==============================================================
	case 1:
	{
		for (int i = 12; i<76; i++)
		{
			gObjInventoryDeleteItem(aIndex, i);
			GCInventoryItemDeleteSend(aIndex, i, 1);
		}
		GCServerMsgStringSend("Você apagou a parte de baixo do Inventário", aIndex, 1);
		return;
	}
	break;
	//==============================================================
	//-- Clear up part of inventory
	//==============================================================
	case 2:
	{
		for (int i = 0; i<12; i++)
		{
			gObjInventoryDeleteItem(aIndex, i);
			GCInventoryItemDeleteSend(aIndex, i, 1);
		}
		GCServerMsgStringSend("Você limpou a parte de cima do inventário", aIndex, 1);
		return;
	}
	break;
	//==============================================================
	//-- Clear all inventory
	//==============================================================
	case 3:
	{
		for (int i = 0; i<76; i++)
		{
			gObjInventoryDeleteItem(aIndex, i);
			GCInventoryItemDeleteSend(aIndex, i, 1);
			gObjMakePreviewCharSet(aIndex);
		}
		GCServerMsgStringSend("Você limpou todo o inventário", aIndex, 1);
		return;
	}
	break;
	//==============================================================
	//-- Clear all Zen
	//==============================================================
	case 4:
		gObj->Money = 0;
		GCMoneySend(aIndex, gObj->Money);
		func.MosterAdd(3, gObj->MapNumber, gObj->X, gObj->Y);
		GCServerMsgStringSend("Você jogou todo seu Zen no chao.", aIndex, 1);
		GCServerMsgStringSend("E uma aranha pegou.", aIndex, 1);
		break;
	}
}
void Commands::QuestInfo(int aIndex) {
	if (!this->_Active[22])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}
	if (QuestUser[aIndex].Quest_Start == 0) {
		func.MsgUser(aIndex, 0, "Não há quest iniciada.");
		return;
	}
	bool classe = (gObj[aIndex].DbClass == DB_FAIRY_ELF || gObj[aIndex].DbClass == DB_MUSE_ELF)&& (QuestUser[aIndex].Quest_Num < Qest_PGW_ELF.Count);
	if (classe) {
		func.MsgUser(aIndex, 0, "[Quest] %s", Qest_PGW_ELF.Number[QuestUser[aIndex].Quest_Num].msg);
		func.MsgUser(aIndex, 0, "[Quest] %s [%d/%d]", Qest_PGW_ELF.Number[QuestUser[aIndex].Quest_Num].msg2, QuestUser[aIndex].Quest_kill, Qest_PGW_ELF.Number[QuestUser[aIndex].Quest_Num].Coun);
		}
	if (!classe) {
		func.MsgUser(aIndex, 0, "[Quest] %s", Qest_PGW.Number[QuestUser[aIndex].Quest_Num].msg);
		func.MsgUser(aIndex, 0, "[Quest] %s [%d/%d]", Qest_PGW.Number[QuestUser[aIndex].Quest_Num].msg2, QuestUser[aIndex].Quest_kill, Qest_PGW.Number[QuestUser[aIndex].Quest_Num].Coun);
		}
}

void Commands::Ping(int aIndex) {
	if (!this->_Active[23])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}

	func.MsgUser(aIndex, 0, "Pong");
	return;	
}


void Commands::OpenCashShopCommand(int aIndex,char* msg)
{/*
	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	PMSG_TALKRESULT pResult;
	PMSG_TALKREQUEST* lpMsg;
	PMSG_SHOPITEMCOUNT	pShopItemCount;
	
	int ShopNum = (atoi(msg)+12);

	//ShopNum = gObj[DealerNumber].ShopNumber;
	if(ShopNum == 11 || ShopNum == 12)
	{
		ShopNum = 13;
	}

	if(ShopNum > (ShopL.ShopCont+12))
	{
		ShopNum = (ShopL.ShopCont+12);
	}
	

	lpObj->ShopNumber = ShopNum ;
	lpObj->TargetShopNumber = ShopNum;
	lpObj->m_IfState.use = 1;
	lpObj->m_IfState.type = 3;
	lpObj->m_ShopTime = 0;

	pResult.h.c = 0xC3;
	pResult.h.headcode = 0x30;
	pResult.h.size = sizeof(pResult);
	pResult.result = 0;

	DataSend(aIndex, (LPBYTE)(&pResult), (DWORD)(pResult.h.size));
	
	int lOfs = 0;
	BYTE SendByte[1024];
	//PMSG_SHOPITEMCOUNT pShopItemCount;

	lOfs += sizeof( pShopItemCount );
		int size = lOfs+ShopC[ShopNum].SendItemDataLen;
		
		pShopItemCount.h.c			= 0xC2;
		pShopItemCount.h.headcode	= 0x31;
		pShopItemCount.h.sizeH		= HIBYTE(size);
		pShopItemCount.h.sizeL		= LOBYTE(size);
		pShopItemCount.Type = 0;
		pShopItemCount.count		= ShopC[ShopNum].ItemCount;
		memcpy(SendByte, &pShopItemCount, sizeof( pShopItemCount ));
		memcpy(SendByte+lOfs, ShopC[ShopNum].SendItemData, ShopC[ShopNum].SendItemDataLen);
		//MsgOutput(aIndex,"[Loja Pessoal]Você possui %d moedas",pObj[aIndex].mCash);
		DataSend(aIndex, (LPBYTE)SendByte, size);
		*/
}



void Commands::MakeSet(int aIndex, char* msg) {
	if (!this->_Active[13])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}
	int MakeSetGM = 0;
	for (int x = 1; x < GMSystemCount; x++)
	{
		if ( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			MakeSetGM = GMSystemInfo[x].GMMakeSet;
		}
	}

	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
		return;
	}

	if (MakeSetGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!", aIndex, 1);
		return;
	}



	else if (strlen(msg) < 1)
	{
		GCServerMsgStringSend("use /makeset <nome> ex: /makeset dragon", aIndex, 1);
		return;
	}
	char str[30];
	sscanf(msg, "%s", str);
	int set = Commands::calcset(str);
	char drophelm[100];
	char droparmor[100];
	char dropgloves[100];
	char droppants[100];
	char dropboots[100];
	if (set == 0) { GCServerMsgStringSend("Digite um nome valido", aIndex, 1); return; }
	if (set == stormcrow || set == thunderkawk || set == huricane) {
		sprintf(droparmor, "%d %d 13 255 1 1 28 63 6", 8, set);
		sprintf(dropgloves, "%d %d 13 255 1 1 28 63 6", 9, set);
		sprintf(droppants, "%d %d 13 255 1 1 28 63 6", 10, set);
		sprintf(dropboots, "%d %d 13 255 1 1 28 63 6", 11, set);
		Commands::makecomprar(aIndex, droparmor, "MAKE SET");
		Commands::makecomprar(aIndex, dropgloves, "MAKE SET");
		Commands::makecomprar(aIndex, droppants, "MAKE SET");
		Commands::makecomprar(aIndex, dropboots, "MAKE SET");
	}
	else {
		sprintf(drophelm, "%d %d 13 255 1 1 28 63 6", 7, set);
		sprintf(droparmor, "%d %d 13 255 1 1 28 63 6", 8, set);
		sprintf(dropgloves, "%d %d 13 255 1 1 28 63 6", 9, set);
		sprintf(droppants, "%d %d 13 255 1 1 28 63 6", 10, set);
		sprintf(dropboots, "%d %d 13 255 1 1 28 63 6", 11, set);
		Commands::makecomprar(aIndex, drophelm,"MAKE SET");
		Commands::makecomprar(aIndex, droparmor, "MAKE SET");
		Commands::makecomprar(aIndex, dropgloves, "MAKE SET");
		Commands::makecomprar(aIndex, droppants, "MAKE SET");
		Commands::makecomprar(aIndex, dropboots, "MAKE SET");
	}
	LogSystem::DKLog(gObj[aIndex].Name, "Criou um set full");
	GCServerMsgStringSend("Set criado com sucesso", aIndex, 1);
}

//Comando comprar
void Commands::Comprar(int aIndex, char* msg) {
	
	if (!this->_Active[14])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}
	char  str[20] = "";
	int qtd = 1;
	char cmd[255] = "";
	sscanf(msg, "%s %d", str,&qtd);
	int index = 0;
	int id = 0;
	int lvl = 0;
	int dur = 0;
	int opt = 0;
	int exc = 0;
	int luck = 0;
	int skill = 0;
	int preco = 0;
	int existe = 0;
	int exib;
	for (int x = 0; x < GoldShopCount; x++)
	{
		if (!strcmp(GoldShopInfo[x].itemnome, str) || !strcmp(GoldShopInfo[x].itemexib, str))
		{
			exib = x;
			index = GoldShopInfo[x].itemindex;
			id = GoldShopInfo[x].itemid;
			lvl = GoldShopInfo[x].itemlvl;
			dur = GoldShopInfo[x].itemdur;
			opt = GoldShopInfo[x].itemopt;
			exc = GoldShopInfo[x].itemexc;
			luck = GoldShopInfo[x].itemluck;
			skill = GoldShopInfo[x].itemskill;
			preco = GoldShopInfo[x].itempreco;
			existe = 1;
		}
	}
	
	
		if (strlen(msg) < 1)
	{
		GCServerMsgStringSend("use /Comprar <id> <quantia> ex: /comprar 01 10", aIndex, 1);
		return;
	}
		if (existe == 1) {
			if (qtd < 1) { qtd = 1; }
			preco = preco * qtd;
			sprintf(cmd, "%d %d %d %d %d %d %d %d", index, id, lvl, dur, skill, luck, opt, exc);
			if (preco <= Custom[aIndex].mCash) {
				Custom[aIndex].mCash -= preco;
				Manager.ExecFormat(this->_QueryComprar, preco , gObj[aIndex].AccountID);
				for (int i = 1; i <= qtd; i++) {
					Commands::makecomprar(aIndex, cmd, GoldShopInfo[exib].itemexib);
				}
				char xxx[2][255];
				sprintf(xxx[0], "Seu saldo atual: %d, valor pago: %d.", Custom[aIndex].mCash, preco);
				sprintf(xxx[1], "Compra do item %s, quantia %d", GoldShopInfo[exib].itemexib, qtd);
				func.FireWork(aIndex);
				GCServerMsgStringSend(xxx[1], aIndex, 1);
				GCServerMsgStringSend("Efetuada com sucesso.", aIndex, 1);
				GCServerMsgStringSend(xxx[0], aIndex, 1);
			}
			else {
				char xxx[255] = "";
				sprintf(xxx, "Seu saldo: %d, preço do item: %d", Custom[aIndex].mCash, preco);
				GCServerMsgStringSend("Saldo em gold insulficiente.", aIndex, 1);
				GCServerMsgStringSend(xxx, aIndex, 1);
			}
		}
		else {
			GCServerMsgStringSend("item inexistente.", aIndex, 1);
		}
}
void Commands::Listar(int aIndex, char* msg) {
	if (!this->_Active[15])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}
	if (strlen(msg) < 1)
	{
		GCServerMsgStringSend("use /Listar <pagina> ex: /Listar 1", aIndex, 1);
		return;
	}
	int pag = atoi(msg);
	char xxx[255][255];
	int paginas = GoldShopCount / 5;
	for (int x = 0; x <= GoldShopCount; x++)
	{
		sprintf(xxx[x], " Nome: %s, ID: %s, Preço: %d", GoldShopInfo[x].itemexib, GoldShopInfo[x].itemnome, GoldShopInfo[x].itempreco);
	}
	if (pag <= paginas) {
		for (int x = pag * 5 - 5; x <= pag * 5; x++) {
			GCServerMsgStringSend(xxx[x], aIndex, 1);
		}
	}
	char xx[255] = "";
	sprintf(xx, "Total de paginas: %d", paginas);
	GCServerMsgStringSend(xx, aIndex, 1);

}
void Commands::Jail(int aIndex, char * msg, int type) {
	if (!this->_Active[29])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}
	int JailGM = 0;
	for (int x = 1; x < GMSystemCount; x++)
	{
		if ( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			JailGM = GMSystemInfo[x].GMJail;
		}
	}

	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
		return;
	}

	if (JailGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!", aIndex, 1);
		return;
	}



	else if (strlen(msg) < 1)
	{
		switch (type) {
		case 1:
			GCServerMsgStringSend("use /jail <nome> <horas> ex: /jail draconick 12", aIndex, 1);
			break;
		case 2:
			GCServerMsgStringSend("use /unjail <nome> ex: /unjail draconick", aIndex, 1);
			break;
		}
		return;
	}

	int horas = 0;
	int jaula = 0;
	char name[11];
	char log[255];
	sscanf(msg, "%s %d %d", name,&jaula, &horas);
	int tIndex = func.Get_PlayerIndex(name);

	if (gObj[tIndex].Connected < 3)
	{
		func.MsgUser(aIndex, 1, "O Personagem não se encontra.");
		return;
	}

	switch (type) {
	case 1:
		Custom[tIndex].jail = 1;
		Manager.ExecFormat("UPDATE[MuOnline].[dbo].[Character] SET jail = 1, jailtempo = %d, jaula = %d WHERE Name = '%s'",horas,jaula,name);
		sprintf(log, "Prendeu o jogador %s por %d horas", name, horas);
		gObj[tIndex].m_PK_Level = 6;
		gObj[aIndex].m_PK_Count = 20;
		gObj[tIndex].m_PK_Time = 100;
		GCPkLevelSend(aIndex, gObj[tIndex].m_PK_Level);

		break;
	case 2:
		Custom[tIndex].jail = 0;
		gObj[tIndex].m_PK_Level = 3;
		gObj[tIndex].m_PK_Time = 0;
		GCPkLevelSend(aIndex, gObj[tIndex].m_PK_Level);
		Manager.ExecFormat("UPDATE[MuOnline].[dbo].[Character] SET jail = 0, jailtempo = 0, jaula = 0 WHERE Name = '%s'",name);
		sprintf(log, "Soltou o jogador %s por bom comportamento", name);
		break;
	}
	
	LogSystem::DKLog(gObj[aIndex].Name, log);
}
void Commands::Premiar(int aIndex, char* msg)
{
	int PremiarGM = 0;
	for(int x=1;x < GMSystemCount;x++)
	{
		if( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			PremiarGM = GMSystemInfo[x].GMPremiar;
		}
	}

	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex,1,"Exclusivo apenas para gamemaster.");
		return;
	}

	if(PremiarGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!",aIndex,1);
		return;
	}



	else if (strlen(msg) < 1)
	{
		return;
	}

	int num = {-1};
	char tName[11];
	sscanf(msg,"%s %d",tName,&num);
	int tIndex = func.Get_PlayerIndex(tName);

	if (gObj[tIndex].Connected < 3)
	{
		func.MsgUser(aIndex,1,"O Personagem não se encontra.");
		return;
	}

	Manager.ExecFormat(this->_Query,num,gObj[tIndex].AccountID);
	char log[255];
	sprintf(log, "Premiar - Jogador: %s Golds: %d", tName, num);
	LogSystem::DKLog(gObj[aIndex].Name, log);
	func.MsgAllUser(0,this->_Notice,tName,num);
}

void Commands::Make(int aIndex, char * msg)
{
	int MakeGM = 0;
	for (int x = 1; x < GMSystemCount; x++)
	{
		if ( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			MakeGM = GMSystemInfo[x].GMMake;
		}
	}

	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
		return;
	}

	if (MakeGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!", aIndex, 1);
		return;
	}

	if (strlen(msg) < 1)
	{
		GCServerMsgStringSend("Modo de Uso : /make <tipo> <id> <lvl> <dur> <skill> <sorte> <opt> <exc>", aIndex, 1);
		return;
	}
	else
	{
		char cmd[255];
		int ItemType = 0, ItemNr = 0, ItemLevel = 0, ItemDur = 0, ItemSkill = 0, ItemLuck = 0, ItemOpt = 0, ItemExc = 0, ItemAnc = 0;
		sscanf_s(msg, "%d %d %d %d %d %d %d %d %d", &ItemType, &ItemNr, &ItemLevel, &ItemDur, &ItemSkill, &ItemLuck, &ItemOpt, &ItemExc, &ItemAnc);
		sprintf(cmd, "%d %d %d %d %d %d %d %d %d", ItemType, ItemNr, ItemLevel, ItemDur, ItemSkill, ItemLuck,  ItemOpt, ItemExc, ItemAnc);
		Commands::makecomprar(aIndex, cmd, "Make Do GM");
	}
}

void Commands::MoveAll(int aIndex, char* msg)
{
	int MoveAllGM = 0;
	for(int x=1;x < GMSystemCount;x++)
	{
		if( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			MoveAllGM = GMSystemInfo[x].GMMoveAll;
		}
	}
	
	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex,1,"Exclusivo apenas para gamemaster.");
		return;
	}

	if(MoveAllGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!",aIndex,1);
		return;
	}

	else if (strlen(msg) < 1)
	{
		return;
	}

	int Mapa,X,Y;
	sscanf(msg,"%d %d %d",&Mapa, &X, &Y);


	func.MsgUser(aIndex,1,"Movidos com sucesso.");
	LogSystem::DKLog(gObj[aIndex].Name, "Move all");
}

void Commands::Skin(int aIndex, char* msg)
{
	int SkinGM = 0;
	for(int x=1;x < GMSystemCount;x++)
	{
		if( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			SkinGM = GMSystemInfo[x].GMSkin;
		}
	}

	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex,1,"Exclusivo apenas para gamemaster.");
		return;
	}

	if(SkinGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!",aIndex,1);
		return;
	}

	else if (strlen(msg) < 1)
	{
		return;
	}

	int skinnum = {-1};
	char tName[11];
	sscanf(msg,"%s %d",tName,&skinnum);
	int tIndex = func.Get_PlayerIndex(tName);

	if (gObj[tIndex].Connected < 3)
	{
		func.MsgUser(aIndex,1,"Personagem não se encontra.");
		return;
	}

	gObj[tIndex].m_Change = skinnum;
	gObjViewportListProtocolCreate(&gObj[tIndex]);

	if (tIndex == aIndex)
	{
		func.MsgUser(aIndex,1,"%s Mudou de skin.",gObj[aIndex].Name);
		LogSystem::DKLog(gObj[aIndex].Name, "Mudou a skin");
	}
	else
	{
		func.MsgUser(aIndex,1,"Skin adicionada.");
		func.MsgUser(tIndex,1,"Skin adicionada por %s",gObj[aIndex].Name);
		char log[255];
		sprintf(log, "Trocou a skin de %s skin: %d", tName, skinnum);
		LogSystem::DKLog(gObj[aIndex].Name, log);
	}
}

void Commands::Move(int aIndex, char* msg)
{
	int MoveGM = 0;
	for(int x=1;x < GMSystemCount;x++)
	{
		if( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			MoveGM = GMSystemInfo[x].GMMove;
		}
	}
	
	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex,1,"Exclusivo apenas para gamemaster.");
		return;
	}

	if(MoveGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!",aIndex,1);
		return;
	}

	else if (strlen(msg) < 1)
	{
		return;
	}

	int Mapa,X,Y;
	char tName[11];
	sscanf(msg,"%s %d %d %d",&tName,&Mapa,&X,&Y);
	int tIndex = func.Get_PlayerIndex(tName);

	if (gObj[tIndex].Connected < 3)
	{
		func.MsgUser(aIndex,1,"Personagem não se encontra.");
		return;
	}
	else
	{
		gObjTeleport(gObj[tIndex].m_Index,Mapa,X,Y);
		char log[255];
		sprintf(log, "Moveu o jogador %s para o mapa %d CordX %d CordY %d", tName,Mapa,X,Y);
		LogSystem::DKLog(gObj[aIndex].Name, log);
	}
}

void Commands::Visible(int aIndex, LPCSTR IpBuffer, BYTE BuffCode)
{	
	int VisibleGM = 0;
	for(int x=1;x < GMSystemCount;x++)
	{
		if( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			VisibleGM = GMSystemInfo[x].GMVisible;
		}
	}
	
	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex,1,"Exclusivo apenas para gamemaster.");
		return;
	}

	if(VisibleGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!",aIndex,1);
		return;
	}

	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	switch(BuffCode)
	{
	case 1:

		gObj[aIndex].m_Change = 255 ;
		gObj[aIndex].AuthorityCode = 8;
		gObjViewportListProtocolCreate(&gObj[aIndex]);
		GCMagicAttackNumberSend(lpObj,0x46,aIndex,1);
		func.MsgUser(aIndex,1,"%s Ficou Invisivel!",gObj[aIndex].Name);
		LogSystem::DKLog(gObj[aIndex].Name, "Ficou Invisivel");
		break;

	case 2:

		gObj[aIndex].m_Change = -1;
		gObj[aIndex].AuthorityCode = 32;
		gObjViewportListProtocolCreate(&gObj[aIndex]);
		GCMagicAttackNumberSend(lpObj,0x46,aIndex,1);
		func.MsgUser(aIndex,1,"%s Ficou Visivel!",gObj[aIndex].Name);
		LogSystem::DKLog(gObj[aIndex].Name, "Ficou visivel");
		break;
	}
}

void Commands::FakeName(int aIndex, char name[11])
{
	int FakeNameGM = 0;
	for (int x = 1; x < GMSystemCount; x++)
	{
		if ( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			FakeNameGM = GMSystemInfo[x].GMFakeName;
		}
	}

	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
		return;
	}

	if (FakeNameGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!", aIndex, 1);
		return;
	}

	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

		if(strlen(Custom[aIndex].OriName) == 0){ lstrcpy(Custom[aIndex].OriName , lpObj->Name); }
		lstrcpy(lpObj->Name , name);
		gObjViewportListProtocolCreate(&gObj[aIndex]);
		GCMagicAttackNumberSend(lpObj, 0x46, aIndex, 1);
		func.MsgUser(aIndex, 1, "%s Trocou o nome para %s", Custom[aIndex].OriName,&gObj[aIndex].Name);
		char log[255];
		sprintf(log, "Trocou o nome para: %s",gObj[aIndex].Name);
		LogSystem::DKLog(Custom[aIndex].OriName, log);

}

void Commands::ChangeName(int aIndex, char name[11])
{
	
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if (strlen(Custom[aIndex].OriName) == 0) { lstrcpy(Custom[aIndex].OriName, lpObj->Name); }
	lstrcpy(lpObj->Name, name);
	gObjViewportListProtocolCreate(&gObj[aIndex]);
	GCMagicAttackNumberSend(lpObj, 0x46, aIndex, 1);
	func.MsgUser(aIndex, 1, "%s Trocou o nome para %s", Custom[aIndex].OriName, &gObj[aIndex].Name);
	char log[255];
	sprintf(log, "Trocou o nome para: %s", gObj[aIndex].Name);
	LogSystem::DKLog(Custom[aIndex].OriName, log);

}



void Commands::Spawn(int aIndex, char * msg) {
	if (!this->_Active[19])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}
	int SpawnGM = 0;
	for (int x = 1; x < GMSystemCount; x++)
	{
		if (!strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			SpawnGM = GMSystemInfo[x].GMSpawn;
		}
	}

	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
		return;
	}

	if (SpawnGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!", aIndex, 1);
		return;
	}
	if (strlen(msg) < 1)
	{
		GCServerMsgStringSend("Modo de Uso : /spawn <qtd> <mob> <map> <x> <y>", aIndex, 1);
		return;
	}
	int map , x , y, mob , qtd;
	sscanf(msg, "%d %d %d %d %d %d", &qtd,&mob,&map,&x,&y);
	for(int i = 0; i<qtd; i++){

		int mIndex = gObjAddMonster(map);

		if (mIndex >= 0)
		{
			gObjSetMonster(mIndex, mob);
			OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(mIndex);
			gObj->Class = mob;
			gObj->MapNumber = map;
			gObj->Dir = gObj[aIndex].Dir;
			gObj->X = x;
			gObj->Y = y;
			/*
			//gObj->m_RecallMon				= mIndex;
			//gObj->TargetNumber				= -1;
			gObj->TX						= gObj->X;
			gObj->TY						= gObj->Y;
			gObj->MTX						= gObj->X;
			gObj->MTY						= gObj->Y;
			gObj->m_OldX					= gObj->X;
			gObj->m_OldY					= gObj->Y;
			gObj->StartX					= (BYTE)(gObj->X);
			gObj->StartY					= (BYTE)(gObj->Y);
			//gObj->m_ActState.Emotion		= 0;
			//gObj->m_ActState.Attack			= 0;
			//gObj->m_ActState.EmotionCount	= 0;        
			gObj->PathCount					= 0;
			gObj->m_MoveRange				= 0;
			//gObj->m_PosNum					= -1;
			gObj->ShopNumber				= 14;
			*/
		}

	}
}
void Commands::Pet(int aIndex, char * msg) {
	if (!this->_Active[26])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}

	else if (this->_Vip[26] == 1)
	{
		if (Custom[aIndex].VipIndex < 1)
		{
			func.MsgUser(aIndex, 1, "Somente Vips");
			return;
		}
	}
	if (gObj[aIndex].Level < this->_Level[26])
	{
		func.MsgUser(aIndex, 1, "Voce só pode usar no lvl: %d", this->_Level[26]);
		return;
	}
	if (gObj[aIndex].Money < this->_Zen[26])
	{
		func.MsgUser(aIndex, 1, "Voce não tem Zen sulficiente: %d", this->_Level[26]);
		return;
	}
	if (strlen(msg) < 1)
	{
		GCServerMsgStringSend("Modo de Uso : /pet <mob>", aIndex, 1);
		return;
	}
	int mob, x, y;
	sscanf(msg, "%d", &mob);
	if (gObj[aIndex].AuthorityCode < 1) {
		if (mob > 10 || mob < 0) {
			GCServerMsgStringSend("Pets vão de 0 a 10", aIndex, 1);
			return;
		}
	}
	else if (mob > 100 || mob < 0) {
			GCServerMsgStringSend("Pets vão de 0 a 100", aIndex, 1);
			return;
	}
	x = gObj[aIndex].X;
	y = gObj[aIndex].Y;
	LPOBJ lpObj = &gObj[aIndex];
	Bot.CallPet(lpObj->m_Index, mob, x - 1, y + 1);
	gObj[aIndex].Money -= this->_Zen[26];
}


void Commands::GoQuest(int aIndex) {
	if (!this->_Active[28])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}

	else if (this->_Vip[28] == 1)
	{
		if (Custom[aIndex].VipIndex < 1)
		{
			func.MsgUser(aIndex, 1, "Somente Vips");
			return;
		}
	}
	if (gObj[aIndex].Level < this->_Level[28])
	{
		func.MsgUser(aIndex, 1, "Voce só pode usar no lvl: %d", this->_Level[26]);
		return;
	}
	if (gObj[aIndex].Money < this->_Zen[28])
	{
		func.MsgUser(aIndex, 1, "Voce não tem Zen sulficiente: %d", this->_Level[26]);
		return;
	}
	if (QuestUser[aIndex].Quest_Start == 0) {
		func.MsgUser(aIndex, 0, "Não há quest iniciada.");
		return;
	}
	int map, x, y;
	map = 0;
	x = 130;
	y = 130;
	bool classe = (gObj[aIndex].DbClass == DB_FAIRY_ELF || gObj[aIndex].DbClass == DB_MUSE_ELF) && (QuestUser[aIndex].Quest_Num < Qest_PGW_ELF.Count);
	if (classe) {
		map = Qest_PGW_ELF.Number[QuestUser[aIndex].Quest_Num].map;
		x = Qest_PGW_ELF.Number[QuestUser[aIndex].Quest_Num].x;
		y = Qest_PGW_ELF.Number[QuestUser[aIndex].Quest_Num].y;
		if(Qest_PGW_ELF.Number[QuestUser[aIndex].Quest_Num].teleport == 0){
			func.MsgUser(aIndex, 0, "Essa quest não permite teleporte.");
			return;
		}
	}
	if (!classe) {
		map = Qest_PGW.Number[QuestUser[aIndex].Quest_Num].map;
		x = Qest_PGW.Number[QuestUser[aIndex].Quest_Num].x;
		y = Qest_PGW.Number[QuestUser[aIndex].Quest_Num].y;
		if(Qest_PGW.Number[QuestUser[aIndex].Quest_Num].teleport == 0){
			func.MsgUser(aIndex, 0, "Essa quest não permite teleporte.");
			return;
		}
	}
	gObjTeleport(aIndex,map,x,y);
	gObj[aIndex].Money -= this->_Zen[26];
}

void Commands::mBot(int aIndex, char * msg) {
	if (!this->_Active[27])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}

	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
		return;
	}


	if (strlen(msg) < 1)
	{
		GCServerMsgStringSend("Modo de Uso : /bot <name>", aIndex, 1);
		return;
	}
	int map, mob, x, y,dir;
	char * name = "x";
	sscanf(msg, "%s",name);
	x = gObj[aIndex].X;
	y = gObj[aIndex].Y;
	map = gObj[aIndex].MapNumber;
	dir = gObj[aIndex].Dir;

	Bot.MakeBot(name, map, x, y, dir);



}
void Commands::Drop(int aIndex,char * msg)
{
	int DropGM = 0;
	for(int x=1;x < GMSystemCount;x++)
	{
		if( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			DropGM = GMSystemInfo[x].GMDrop;
		}
	}

	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex,1,"Exclusivo apenas para gamemaster.");
		return;
	}

	if(DropGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!",aIndex,1);
		return;
	}

	if(strlen(msg) < 1) 
	{
		GCServerMsgStringSend("Modo de Uso : /drop <tipo> <nr> <lvl> <dur> <skill> <sorte> <opt> <exc> <anc>",aIndex,1);
		return;
	}
	else 
	{
		int ItemType = 0, ItemNr = 0, ItemLevel = 0, ItemDur = 0, ItemSkill = 0, ItemLuck = 0, ItemOpt = 0, ItemExc = 0, ItemAnc = 0;
		sscanf_s(msg, "%d %d %d %d %d %d %d %d %d %d", &ItemType, &ItemNr, &ItemLevel, &ItemDur, &ItemSkill, &ItemLuck, &ItemOpt, &ItemExc, &ItemAnc);

		DWORD Item = ItemType * 32 + ItemNr;
		ItemSerialCreateSend(aIndex,gObj[aIndex].MapNumber,gObj[aIndex].X,gObj[aIndex].Y, Item, ItemLevel, ItemDur, ItemSkill, ItemLuck, ItemOpt,-1 , ItemExc, ItemAnc);
		func.FireWork(aIndex);
		GCServerMsgStringSend("Item criado com sucesso.",aIndex,1);
		char log[255];
		sprintf(log, "Dropou o item %d %d %d %d %d %d %d %d %d", ItemType, ItemNr, ItemLevel, ItemDur, ItemSkill, ItemLuck, ItemOpt, ItemExc, ItemAnc);
		LogSystem::DKLog(gObj[aIndex].Name, log);

	}
}

void Commands::StormCommand(int aIndex)
{
	int ChuvaGM = 0;
	for(int x=1;x < GMSystemCount;x++)
	{
		if( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
		{
			ChuvaGM = GMSystemInfo[x].GMChuva;
		}
	}

	if (gObj[aIndex].AuthorityCode < 1)
	{
		func.MsgUser(aIndex,1,"Exclusivo apenas para gamemaster.");
		return;
	}

	if(ChuvaGM == 0)
	{
		GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!",aIndex,1);
		return;
	}

	if(gObj[aIndex].MapNumber != 0)
	{
		func.MsgUser(aIndex,1,"[Storm] Você precisa estar em lorencia!");
		func.MsgUser(aIndex,1,"[Storm] pra usar o comando!");
		return;
	}

	Storm.ItemDrop(aIndex);								
	func.AllSendServerMsg("Drop de Items em Lorencia");
	LogSystem::DKLog(gObj[aIndex].Name, "Usou storm");
}


void Commands::ComandoSortear(int aIndex) {
	if (!this->_Active[31])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}
		
		else
		{
			int SorteioGM = 0;
			for (int x = 1; x < GMSystemCount; x++)
			{
				if ( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
				{
					SorteioGM = GMSystemInfo[x].GMSorteio;
				}
			}

			if (gObj[aIndex].AuthorityCode < 1)
			{
				func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
				return;
			}

			if (SorteioGM == 0)
			{
				GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!", aIndex, 1);
				return;
			}
		}
	int pRecv[1000];
	int iTarget = 0;
	// ---
	for(int i = OBJ_STARTUSERINDEX; i < OBJECT_MAX; i++)
	{
		if(gObj[i].Connected >= 3)
		{
			pRecv[iTarget++] = i;
		}
	}
	// ---
	if(iTarget > 0)
	{
		int Index = rand() % iTarget;
		int Target = pRecv[Index];
		func.MsgAllUser(0, "%s Sorteou %s.",gObj[aIndex].Name, gObj[Target].Name);
	}
}


void Commands::EventStart(int aIndex, char * msg) {
	
	if (!this->_Active[32])
	{
		func.MsgUser(aIndex, 1, "Comando Desligado..");
		return;
	}
		
		else
		{
			int EventGM = 0;
			for (int x = 1; x < GMSystemCount; x++)
			{
				if ( !strcmp(GMSystemInfo[x].Name, gObj[aIndex].Name ) || !strcmp(GMSystemInfo[x].Name, Custom[aIndex].OriName))
				{
					EventGM = GMSystemInfo[x].GMEvent;
				}
			}

			if (gObj[aIndex].AuthorityCode < 1)
			{
				func.MsgUser(aIndex, 1, "Exclusivo apenas para gamemaster.");
				return;
			}

			if (EventGM == 0)
			{
				GCServerMsgStringSend("Seu [GM] Não pode usar esse Comando !!", aIndex, 1);
				return;
			}
		}
	int Event = atoi(msg);
	switch(Event){
	case 1: DevilRun();
		break;
	case 2: BCRun();
		break;
	case 3: CCRun();
		break;
	default: {
				func.MsgUser(aIndex, 1, "User /EventStart nº");
				func.MsgUser(aIndex, 1, "1 = Devil Square");
				func.MsgUser(aIndex, 1, "2 = BloodCastle");
				func.MsgUser(aIndex, 1, "3 = Chaos Castle");
			 }
		break;
	}
}

//Função adicional
int Commands::calcset(char * setname) {
	
	if (strcmp(setname,"dragon")==0) { return this->dragon; }
	else if (strcmp(setname, "pad") == 0) { return this->pad; }
	else if (strcmp(setname, "legendary") == 0) { return this->legendary; }
	else if (strcmp(setname, "bone") == 0) { return this->bone; }
	else if (strcmp(setname, "leather") == 0) { return this->leather; }
	else if (strcmp(setname, "scale") == 0) { return this->scale; }
	else if (strcmp(setname, "sphinx") == 0) { return this->sphinx; }
	else if (strcmp(setname, "brass") == 0) { return this->brass; }
	else if (strcmp(setname, "plate") == 0) { return this->plate; }
	else if (strcmp(setname, "vine") == 0) { return this->vine; }
	else if (strcmp(setname, "silk") == 0) { return this->silk; }
	else if (strcmp(setname, "wind") == 0) { return this->wind; }
	else if (strcmp(setname, "spirit") == 0) { return this->spirit; }
	else if (strcmp(setname, "guardian") == 0) { return this->guardian; }
	else if (strcmp(setname, "stormcrow") == 0) { return this->stormcrow; }
	else if (strcmp(setname, "blackdragon") == 0) { return this->blackdragon; }
	else if (strcmp(setname, "darkphoenix") == 0) { return this->darkphoenix; }
	else if (strcmp(setname, "grandsoul") == 0) { return this->grandsoul; }
	else if (strcmp(setname, "divine") == 0) { return this->divine; }
	else if (strcmp(setname, "thunderkawk") == 0) { return this->thunderkawk; }
	else if (strcmp(setname, "greatdragon") == 0) { return this->greatdragon; }
	else if (strcmp(setname, "darksoul") == 0) { return this->darksoul; }
	else if (strcmp(setname, "huricane") == 0) { return this->huricane; }
	else if (strcmp(setname, "redspirit") == 0) { return this->redspirit; }
	else if (strcmp(setname, "lightplate") == 0) { return this->lightplate; }
	else if (strcmp(setname, "adamantine") == 0) { return this->adamantine; }
	else if (strcmp(setname, "darksteel") == 0) { return this->darksteel; }
	else if (strcmp(setname, "darkmaster") == 0) { return this->darkmaster; }
	else if (strcmp(setname, "dk01") == 0) { return this->dragonknight; }
	else if (strcmp(setname, "dk02") == 0) { return this->venonmist; }
	else if (strcmp(setname, "dk03") == 0) { return this->phoenixlord; }
	
	else { return 0; }
}

void Commands::makecomprar(int aIndex, char * msg, char * itemname)
{		
		int ItemType = 0, ItemNr = 0, ItemLevel = 0, ItemDur = 0, ItemSkill = 0, ItemLuck = 0, ItemOpt = 0, ItemExc = 0, ItemAnc = 0;
		sscanf_s(msg, "%d %d %d %d %d %d %d %d %d", &ItemType, &ItemNr, &ItemLevel, &ItemDur, &ItemSkill, &ItemLuck, &ItemOpt, &ItemExc, &ItemAnc);

		DWORD Item = ItemType * 32 + ItemNr;
		//func.ItemSerialCreateSendEx(aIndex, 235, 0, 0, Item, ItemLevel, ItemDur, ItemSkill, ItemLuck, ItemOpt, -1, ItemExc, ItemAnc);
		ItemSerialCreateSend(aIndex, 235, 0, 0, Item, ItemLevel, ItemDur, ItemSkill, ItemLuck, ItemOpt, -1, ItemExc, ItemAnc);
		char log[255];
		sprintf(log, "Comprou o item %s %d %d %d %d %d %d %d %d %d",itemname, ItemType, ItemNr, ItemLevel, ItemDur, ItemSkill, ItemLuck, ItemOpt, ItemExc, ItemAnc);
		LogSystem::DKLog(gObj[aIndex].Name, log);
}

Commands Command;