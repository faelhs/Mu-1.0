//###############################################################################################
// Project   :: ACTeaM Classic 0.97d
// GameServer:: 0.96.40				
// Company   :: Advanced CoderZ MU DevelopmenT © 2013
// Revised   :: 28/03/2014
// Coded     :: Mr.Haziel Developer								
//###############################################################################################

#include "StdAfx.h"

GENS pGens;

void ReadyGenSystem()
{
	ReadyGenConfigs();
}

//=============================================================================================
//--  Load Configs 
//=============================================================================================
void ReadyGenConfigs()
{
	pGens.ISGENS = GetPrivateProfileIntA("Facção", "Active", 1, CFG_Faccao);
	pGens.Gens_Level = GetPrivateProfileIntA("Facção", "NeedLevel", 50, CFG_Faccao);
	pGens.Gens_Zen = GetPrivateProfileIntA("Facção", "NeedZen", 1000000, CFG_Faccao);
	pGens.Gens_Resets = GetPrivateProfileIntA("Facção", "NeedRes", 50, CFG_Faccao);
	GetPrivateProfileStringA("Facção", "Nome Fac 1", "Black", pGens.nameblack, 20, CFG_Faccao);
	GetPrivateProfileStringA("Facção", "Nome Fac 2", "White", pGens.namewhite, 20, CFG_Faccao);
	GetPrivateProfileStringA("Facção", "Black", "/black", pGens.CMDDuprian, 20, CFG_Faccao);
	GetPrivateProfileStringA("Facção", "White", "/white", pGens.CMDVanert, 20, CFG_Faccao);
	GetPrivateProfileStringA("Facção", "Exit", "/sairfac", pGens.CMDExitGens, 20, CFG_Faccao);
	GetPrivateProfileStringA("Facção", "Rank", "/rankf", pGens.CMDRankGens, 20, CFG_Faccao);
}

//###############################################################################################
//-- Gens Struct Information Help 
//###############################################################################################
// m_GensState   = 0  -->  Jogador Normal 
// m_GensState   = 1  -->  Jogador black 
// m_GensState   = 2  -->  Jogador white
// m_GensScore_D = Pontos da Gens  white 
// m_GensScore_V = Pontos da Gens  black 
//-----------------------------------------------------------------------------------------------


//###############################################################################################
//-- Function Check All  
//###############################################################################################
bool CheckGensSystem(int aIndex)
{
	LPOBJ pObj = (LPOBJ)OBJECT_POINTER(aIndex);

	//---------------------------------------------------------------
	//-- Verificação de Ligado ou desligado 
	//---------------------------------------------------------------
	if (pGens.ISGENS != TRUE)
	{
		MsgOutput(aIndex, "%s : Sistema de Gens está Desligado", pObj->Name);
		return FALSE;
	}

	//---------------------------------------------------------------
	//-- Verificação de  Level
	//---------------------------------------------------------------
	if (pObj->Level < pGens.Gens_Level)
	{
		MsgOutput(aIndex, "%s Você Não Tem Level Suficiente! Requerido: %d", pObj->Name, pGens.Gens_Level);
		return FALSE;
	}
	//---------------------------------------------------------------
	//-- Verificação de  Resets
	//---------------------------------------------------------------

	if (Custom[aIndex].Resets < pGens.Gens_Resets)
	{
		MsgOutput(aIndex, "%s Você Não Tem Resets Suficiente! Requerido: %d", pObj->Name, pGens.Gens_Resets);
		return FALSE;
	}
	//---------------------------------------------------------------
	//-- Verificação de Money
	//---------------------------------------------------------------
	if (pObj->Money < pGens.Gens_Zen)
	{
		MsgOutput(aIndex, "%s Você Não Tem Zen Suficiente! Requerido: %d", pObj->Name, pGens.Gens_Zen);
		return FALSE;
	}

	//---------------------------------------------------------------
	//-- Verificação de Vip
	//---------------------------------------------------------------
	if (Custom[aIndex].VipIndex < pGens.Gens_Vip)
	{
		GCServerMsgStringSend("Seu VIP não tem privilégios suficientes para usar o comando!", aIndex, 1);
		return FALSE;
	}


	return TRUE;

}

//=============================================================================================
//-- Function Gens Prococol Commands
//=============================================================================================
void GensProtocol(PMSG_CHATDATA * lpMsg, int aIndex)
{
	LPOBJ pObj = (LPOBJ)OBJECT_POINTER(aIndex);

	if (_memicmp(lpMsg->message, pGens.CMDDuprian, strlen(pGens.CMDDuprian)) == 0)
	{
		DuprianCommand(aIndex);
	}

	if (_memicmp(lpMsg->message, pGens.CMDVanert, strlen(pGens.CMDVanert)) == 0)
	{
		VanertCommand(aIndex);
	}

	if (_memicmp(lpMsg->message, pGens.CMDExitGens, strlen(pGens.CMDExitGens)) == 0)
	{
		ExitGensCommand(aIndex);
	}
	if (_memicmp(lpMsg->message, pGens.CMDRankGens, strlen(pGens.CMDRankGens)) == 0)
	{
		RankGensCommand(aIndex);
	}

}
//=============================================================================================
//-- Black Command :)
//=============================================================================================
void DuprianCommand(int aIndex)
{
	LPOBJ pObj = (LPOBJ)OBJECT_POINTER(aIndex);

	if (CheckGensSystem(aIndex) != TRUE)
	{
		return;
	}

	if (Custom[aIndex].m_GensState == 2)
	{
		MsgOutput(aIndex, "%s Você está na | %s |", pObj->Name,pGens.namewhite);
		return;
	}

	if (Custom[aIndex].m_GensState == 1)
	{
		MsgOutput(aIndex, "%s Você Já está na | %s |", pObj->Name,pGens.nameblack);
		return;
	}

	Custom[aIndex].m_GensState = 1; //--> Duprian OK

	GCMoneySend(aIndex, pObj->Money -= pGens.Gens_Zen);

	//MSG
	char msg[150] = { 0 };
	wsprintf(msg, "Bem Vindo %s Agora você pertence a | %s |", pObj->Name,pGens.nameblack);
	GCServerMsgStringSend(msg, aIndex, 0);
	wsprintf(msg, "| %s |",pGens.nameblack);

	ChatTargetSend(pObj, msg, aIndex);
	//ShowBox(lpObj->m_Index, 1, 31, 0);

	// Log
	LogSystem::DKLog(pObj->AccountID, "[GENSYSTEM|%s|%s] Joined the Black Family ", pObj->AccountID, pObj->Name);

	func.LevelUPSend(aIndex);
	Manager.gensenter(pObj->Name, 1);   //--> Execult SQL Gens Duprian 
}

//=============================================================================================
//-- White Command :)
//=============================================================================================
void VanertCommand(int aIndex)
{
	LPOBJ pObj = (LPOBJ)OBJECT_POINTER(aIndex);

	if (CheckGensSystem(aIndex) != TRUE)
	{
		return;
	}

	if (Custom[aIndex].m_GensState == 1)
	{
		MsgOutput(aIndex, "%s Você está na | %s |", pObj->Name, pGens.nameblack);
		return;
	}

	if (Custom[aIndex].m_GensState == 2)
	{
		MsgOutput(aIndex, "%s Você Já está na | %s |", pObj->Name, pGens.namewhite);
		return;
	}

	Custom[aIndex].m_GensState = 2; //--> Vanert OK

	GCMoneySend(aIndex, pObj->Money -= pGens.Gens_Zen);

	//MSG
	char msg[150] = { 0 };
	wsprintf(msg, "Bem Vindo %s Agora você pertence a | %s |", pObj->Name, pGens.namewhite);
	GCServerMsgStringSend(msg, aIndex, 0);
	wsprintf(msg,"| %s |", pGens.namewhite);

	ChatTargetSend(pObj, msg, aIndex);
	//ShowBox(lpObj->m_Index, 1, 31, 0);

	// Log
	LogSystem::DKLog(pObj->AccountID, "[GENSYSTEM|%s|%s] Joined the White Family ", pObj->AccountID, pObj->Name);

	func.LevelUPSend(aIndex);
	Manager.gensenter(pObj->Name, 2);     //--> Execult SQL Gens Vanert  
}

//=============================================================================================
//-- Exit Gens Command :)
//=============================================================================================
void ExitGensCommand(int aIndex)
{
	LPOBJ pObj = (LPOBJ)OBJECT_POINTER(aIndex);

	if (CheckGensSystem(aIndex) != TRUE)
	{
		return;
	}

	GCMoneySend(aIndex, pObj->Money -= pGens.Gens_Zen);

	//MSG
	char msg[100] = { 0 };
	wsprintf(msg, " %s você Saiu da facção", pObj->Name);
	GCServerMsgStringSend(msg, aIndex, 0);


	// Log
	LogSystem::DKLog(pObj->AccountID, "[GENSYSTEM|%s|%s] Exit Gens Family ", pObj->AccountID, pObj->Name);

	func.LevelUPSend(aIndex);

	Custom[aIndex].m_GensState = 0;	  //--> Exit Gens  OK
	Manager.gensexit(pObj->Name);     //--> Execult SQL Exit Gens

}


void RankGensCommand(int aIndex) {
	int White = Manager.gensrank(2);
	int Black = Manager.gensrank(1);
	func.MsgUser(aIndex, 0, "| %s | %d",pGens.nameblack, Black);
	func.MsgUser(aIndex, 0, "| %s | %d",pGens.namewhite, White);
}
//=============================================================================================
//-- Gens Display
//=============================================================================================
bool GensDisplay(OBJECTSTRUCT* lpObj, OBJECTSTRUCT* lpTargetObj, void * lpMagic, BOOL magicsend, BYTE MSBFlag, int AttackDamage)
{

	//m_PK_Level = 3;

	return TRUE;

}

//============================================================================================
//-- Gens Ranking
//============================================================================================
void GensRanking(LPOBJ pObj, LPOBJ lpTargetObj)
{
	if (Custom[pObj->m_Index].m_GensState != Custom[lpTargetObj->m_Index].m_GensState)
	{

		if (Custom[pObj->m_Index].m_GensState == 1 && Custom[lpTargetObj->m_Index].m_GensState == 2)
		{
			MsgOutput(pObj->m_Index, "%s Você Ganhou com +1 ponto para sua facção !!", pObj->Name);
			Custom[pObj->m_Index].m_GensScore_D = Manager.gensrank(2);
			Custom[pObj->m_Index].m_GensScore_D++;
			Manager.genscore(1);
		}

		if (Custom[pObj->m_Index].m_GensState == 2 && Custom[lpTargetObj->m_Index].m_GensState == 1)
		{
			MsgOutput(pObj->m_Index, "%s Você Ganhou com +1 ponto para sua facção !!", pObj->Name);
			Custom[pObj->m_Index].m_GensScore_V = Manager.gensrank(2);
			Custom[pObj->m_Index].m_GensScore_V++;
			Manager.genscore(2);
		}

	}
}


//============================================================================================
//-- Gens SQL Ranking
//============================================================================================
void GensRankingSave(int aIndex)
{
	LPOBJ pObj = (LPOBJ)OBJECT_POINTER(aIndex);

	if (Custom[pObj->m_Index].m_GensState == 1) //white
	{
		 Manager.genscore(1);
	}

	if (Custom[pObj->m_Index].m_GensState == 2) //black
	{
		 Manager.genscore(2);
	}


}
