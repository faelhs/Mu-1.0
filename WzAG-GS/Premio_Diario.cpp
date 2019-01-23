#include "StdAfx.h"

Premio_Diario::Premio_Dia PremioDiario[7400];
bool Premio_Diario::load() {
	this->_ativo   = GetPrivateProfileInt("Premio diario", "Active", 1, CFG_PremioDiario) > 0 ? true : false;
	this->valor[0] = GetPrivateProfileInt("Premio diario", "Dia 1", 1, CFG_PremioDiario);
	this->valor[1] = GetPrivateProfileInt("Premio diario", "Dia 2", 2, CFG_PremioDiario);
	this->valor[2] = GetPrivateProfileInt("Premio diario", "Dia 3", 3, CFG_PremioDiario);
	this->valor[3] = GetPrivateProfileInt("Premio diario", "Dia 4", 4, CFG_PremioDiario);
	this->valor[4] = GetPrivateProfileInt("Premio diario", "Dia 5", 5, CFG_PremioDiario);
	this->valor[5] = GetPrivateProfileInt("Premio diario", "Dia 6", 6, CFG_PremioDiario);
	this->valor[6] = GetPrivateProfileInt("Premio diario", "Dia 7", 7, CFG_PremioDiario);
	if (!this->_ativo) {
		return false;
	}
	else {
		Pdiario.LoadPremios();
		return true;
	}
}
void Premio_Diario::premiar(int aIndex) {

	if (!this->_ativo) {
		return;
	}	
	char test[255];
	char dateStr[9];
	_strdate(dateStr);
	Data Hoje;
	Data UltimoLogin;
	char Usr[11];
	lstrcpy(Usr, gObj[aIndex].AccountID);
	PremioDiario[aIndex].dia = Manager.getpremiodia(Usr);
	PremioDiario[aIndex].ultimo_recebido = Manager.getpremiodata(Usr);
	ParseData(PremioDiario[aIndex].ultimo_recebido, &UltimoLogin);
	ParseData(dateStr, &Hoje);
	int dias = Hoje.dia - UltimoLogin.dia;
	int meses = Hoje.mes - UltimoLogin.mes;
	int anos = Hoje.ano - UltimoLogin.ano;
	int diferenca = dias + meses + anos;
	bool reinicio = (diferenca > 1 || PremioDiario[aIndex].dia > 7);
	bool jarecebeu = (diferenca <= 0);
	
	if (reinicio) {
		PremioDiario[aIndex].dia = 1;
	}
	if (jarecebeu) {
		func.MsgUser(aIndex, 1, "Obrigado por jogar conosco.");
		func.MsgUser(aIndex, 1, "Você já recebeu seu premio hoje.");
		return;
	}
	if (!jarecebeu) {
		darpremio(aIndex, PremioDiario[aIndex].dia, dateStr);
		return;
	}
}
void Premio_Diario::ParseData(char str[9], Data *Alvo)
{
	// 0, 1 = mes
	// 2    = /
	// 3, 4 = dia
	// 5    = /
	// 6, 7 = ano
	// 8    = NULO
	char _dia[3] = {
		str[3],
		str[4],
		0
	};
	char _mes[3] = {
		str[0],
		str[1],
		0
	};
	char _ano[3] = {
		str[6],
		str[7],
		0
	};
	Alvo->dia = atoi(_dia);
	Alvo->mes = atoi(_mes);
	Alvo->ano = atoi(_ano);
	return;
}
void Premio_Diario::LoadPremios() {
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   Section;
	token.ParseFile(std::string(CFG_PremioDiario), group);
	if (group.GetSection(0, Section))
	{
		this->_Count[0] = Section.RowCount;
		for (int i = 0; i < Section.RowCount; i++)
		{
			Day1[i].ItemType = Section.Rows[i].GetInt(0);
			Day1[i].ItemIndex = Section.Rows[i].GetInt(1);
			Day1[i].ItemLevel = Section.Rows[i].GetInt(2);
			Day1[i].ItemLuck = Section.Rows[i].GetInt(3);
			Day1[i].ItemSkill = Section.Rows[i].GetInt(4);
			Day1[i].ItemDur = Section.Rows[i].GetInt(5);
			Day1[i].ItemOpt = Section.Rows[i].GetInt(6);
			Day1[i].ItemExc = Section.Rows[i].GetInt(7);
		}
	}
	if (group.GetSection(1, Section))
	{
		this->_Count[1] = Section.RowCount;

		for (int i = 0; i < Section.RowCount; i++)
		{
			Day2[i].ItemType = Section.Rows[i].GetInt(0);
			Day2[i].ItemIndex = Section.Rows[i].GetInt(1);
			Day2[i].ItemLevel = Section.Rows[i].GetInt(2);
			Day2[i].ItemLuck = Section.Rows[i].GetInt(3);
			Day2[i].ItemSkill = Section.Rows[i].GetInt(4);
			Day2[i].ItemDur = Section.Rows[i].GetInt(5);
			Day2[i].ItemOpt = Section.Rows[i].GetInt(6);
			Day2[i].ItemExc = Section.Rows[i].GetInt(7);
			
		}
	}
	if (group.GetSection(2, Section))
	{
		this->_Count[2] = Section.RowCount;

		for (int i = 0; i < Section.RowCount; i++)
		{
			Day3[i].ItemType = Section.Rows[i].GetInt(0);
			Day3[i].ItemIndex = Section.Rows[i].GetInt(1);
			Day3[i].ItemLevel = Section.Rows[i].GetInt(2);
			Day3[i].ItemLuck = Section.Rows[i].GetInt(3);
			Day3[i].ItemSkill = Section.Rows[i].GetInt(4);
			Day3[i].ItemDur = Section.Rows[i].GetInt(5);
			Day3[i].ItemOpt = Section.Rows[i].GetInt(6);
			Day3[i].ItemExc = Section.Rows[i].GetInt(7);
		}
	}
	if (group.GetSection(3, Section))
	{
		this->_Count[3] = Section.RowCount;

		for (int i = 0; i < Section.RowCount; i++)
		{
			Day4[i].ItemType = Section.Rows[i].GetInt(0);
			Day4[i].ItemIndex = Section.Rows[i].GetInt(1);
			Day4[i].ItemLevel = Section.Rows[i].GetInt(2);
			Day4[i].ItemLuck = Section.Rows[i].GetInt(3);
			Day4[i].ItemSkill = Section.Rows[i].GetInt(4);
			Day4[i].ItemDur = Section.Rows[i].GetInt(5);
			Day4[i].ItemOpt = Section.Rows[i].GetInt(6);
			Day4[i].ItemExc = Section.Rows[i].GetInt(7);
		}
	}
	if (group.GetSection(4, Section))
	{
		this->_Count[4] = Section.RowCount;

		for (int i = 0; i < Section.RowCount; i++)
		{
			Day5[i].ItemType = Section.Rows[i].GetInt(0);
			Day5[i].ItemIndex = Section.Rows[i].GetInt(1);
			Day5[i].ItemLevel = Section.Rows[i].GetInt(2);
			Day5[i].ItemLuck = Section.Rows[i].GetInt(3);
			Day5[i].ItemSkill = Section.Rows[i].GetInt(4);
			Day5[i].ItemDur = Section.Rows[i].GetInt(5);
			Day5[i].ItemOpt = Section.Rows[i].GetInt(6);
			Day5[i].ItemExc = Section.Rows[i].GetInt(7);
		}
	}
	if (group.GetSection(5, Section))
	{
		this->_Count[5] = Section.RowCount;

		for (int i = 0; i < Section.RowCount; i++)
		{
			Day6[i].ItemType = Section.Rows[i].GetInt(0);
			Day6[i].ItemIndex = Section.Rows[i].GetInt(1);
			Day6[i].ItemLevel = Section.Rows[i].GetInt(2);
			Day6[i].ItemLuck = Section.Rows[i].GetInt(3);
			Day6[i].ItemSkill = Section.Rows[i].GetInt(4);
			Day6[i].ItemDur = Section.Rows[i].GetInt(5);
			Day6[i].ItemOpt = Section.Rows[i].GetInt(6);
			Day6[i].ItemExc = Section.Rows[i].GetInt(7);
		}
	}
	if (group.GetSection(6, Section))
	{
		this->_Count[6] = Section.RowCount;

		for (int i = 0; i < Section.RowCount; i++)
		{
			Day7[i].ItemType = Section.Rows[i].GetInt(0);
			Day7[i].ItemIndex = Section.Rows[i].GetInt(1);
			Day7[i].ItemLevel = Section.Rows[i].GetInt(2);
			Day7[i].ItemLuck = Section.Rows[i].GetInt(3);
			Day7[i].ItemSkill = Section.Rows[i].GetInt(4);
			Day7[i].ItemDur = Section.Rows[i].GetInt(5);
			Day7[i].ItemOpt = Section.Rows[i].GetInt(6);
			Day7[i].ItemExc = Section.Rows[i].GetInt(7);
		}
	}
}
void Premio_Diario::darpremio(int aIndex,int dia,char * date) {
	char cmd[255];

	int n = dia - 1;
	Manager.setpremiodia(gObj[aIndex].AccountID, PremioDiario[aIndex].dia);
	PremioDiario[aIndex].ultimo_recebido = date;
	Manager.setpremiodata(gObj[aIndex].AccountID, PremioDiario[aIndex].ultimo_recebido);
	Manager.ExecFormat("UPDATE[MuOnline].[dbo].[MEMB_INFO] SET gold = gold + %d WHERE memb___id = '%s'", this->valor[n], gObj[aIndex].AccountID);;
	for (int i = 0; i < this->_Count[n]; i++)
	{
		switch (dia) {
		case 1: 
			sprintf(cmd, "%d %d %d %d %d %d %d %d", Day1[i].ItemType, Day1[i].ItemIndex, Day1[i].ItemLevel, Day1[i].ItemDur, Day1[i].ItemSkill, Day1[i].ItemLuck, Day1[i].ItemOpt, Day1[i].ItemExc);
			break;
		case 2: 
			sprintf(cmd, "%d %d %d %d %d %d %d %d", Day2[i].ItemType, Day2[i].ItemIndex, Day2[i].ItemLevel, Day2[i].ItemDur, Day2[i].ItemSkill, Day2[i].ItemLuck, Day2[i].ItemOpt, Day2[i].ItemExc);
			break;
		case 3: 
			sprintf(cmd, "%d %d %d %d %d %d %d %d", Day3[i].ItemType, Day3[i].ItemIndex, Day3[i].ItemLevel, Day3[i].ItemDur, Day3[i].ItemSkill, Day3[i].ItemLuck, Day3[i].ItemOpt, Day3[i].ItemExc);
			break;
		case 4: 
			sprintf(cmd, "%d %d %d %d %d %d %d %d", Day4[i].ItemType, Day4[i].ItemIndex, Day4[i].ItemLevel, Day4[i].ItemDur, Day4[i].ItemSkill, Day4[i].ItemLuck, Day4[i].ItemOpt, Day4[i].ItemExc);
			break;
		case 5: 
			sprintf(cmd, "%d %d %d %d %d %d %d %d", Day5[i].ItemType, Day5[i].ItemIndex, Day5[i].ItemLevel, Day5[i].ItemDur, Day5[i].ItemSkill, Day5[i].ItemLuck, Day5[i].ItemOpt, Day5[i].ItemExc);
			break;
		case 6: 
			sprintf(cmd, "%d %d %d %d %d %d %d %d", Day6[i].ItemType, Day6[i].ItemIndex, Day6[i].ItemLevel, Day6[i].ItemDur, Day6[i].ItemSkill, Day6[i].ItemLuck, Day6[i].ItemOpt, Day6[i].ItemExc);
			break;
		case 7: 
			sprintf(cmd, "%d %d %d %d %d %d %d %d", Day7[i].ItemType, Day7[i].ItemIndex, Day7[i].ItemLevel, Day7[i].ItemDur, Day7[i].ItemSkill, Day7[i].ItemLuck, Day7[i].ItemOpt, Day7[i].ItemExc);
			break;
		}
		Command.makecomprar(aIndex, cmd, "Premio Diario");
	}
	func.MsgUser(aIndex, 1, "Obrigado por jogar conosco.");
	func.MsgUser(aIndex, 1, "Hoje é seu %d° login diario",dia);
	func.MsgUser(aIndex, 1, "Ganhou %d Gold.", this->valor[n]);
}
Premio_Diario Pdiario;