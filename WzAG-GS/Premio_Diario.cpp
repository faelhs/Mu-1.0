#include "StdAfx.h"

Premio_Diario::Premio_Dia PremioDiario[7400];
bool Premio_Diario::load() {
	this->_ativo   = GetPrivateProfileInt("Premio diario", "Active", 1, CFG_PremioDiario) > 0 ? true : false;
	this->valor[1] = GetPrivateProfileInt("Premio diario", "Dia 1", 1, CFG_PremioDiario);
	this->valor[2] = GetPrivateProfileInt("Premio diario", "Dia 2", 2, CFG_PremioDiario);
	this->valor[3] = GetPrivateProfileInt("Premio diario", "Dia 3", 3, CFG_PremioDiario);
	this->valor[4] = GetPrivateProfileInt("Premio diario", "Dia 4", 4, CFG_PremioDiario);
	this->valor[5] = GetPrivateProfileInt("Premio diario", "Dia 5", 5, CFG_PremioDiario);
	this->valor[6] = GetPrivateProfileInt("Premio diario", "Dia 6", 6, CFG_PremioDiario);
	this->valor[7] = GetPrivateProfileInt("Premio diario", "Dia 7", 7, CFG_PremioDiario);
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
	char Usr[11];
	char buff[10];
	char hoje[11];
	Data UltimoLogin;
	SYSTEMTIME now;
	
	GetLocalTime(&now);
	
	lstrcpy(Usr, gObj[aIndex].AccountID);

	PremioDiario[aIndex].dia = Manager.getpremiodia(Usr);
	PremioDiario[aIndex].ultimo_recebido = Manager.getpremiodata(Usr);
	ParseData(PremioDiario[aIndex].ultimo_recebido, &UltimoLogin);
	

	sprintf(hoje, "%02d/%02d/%02d", now.wDay, now.wMonth, now.wYear);

	int dias = now.wDay - UltimoLogin.dia;
	int meses = now.wMonth - UltimoLogin.mes;
	int anos = now.wYear - UltimoLogin.ano;
	if(dias < 0){dias = 0;}
	if(meses < 0){meses = 0;}
	if(anos < 0){anos = 0;}
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
		darpremio(aIndex, PremioDiario[aIndex].dia, hoje);
		return;
	}
}
void Premio_Diario::ParseData(char str[11], Data *Alvo)
{
	// 0, 1 = dia
	// 2    = /
	// 3, 4 = mes
	// 5    = /
	// 6, 7 = ano
	// 8    = NULO
	char _dia[3] = {
		str[0],
		str[1]
	};
	char _mes[3] = {
		str[3],
		str[4]
	};
	char _ano[5] = {
		str[6],
		str[7],
		str[8],
		str[9]
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

	for (int x = 0 ; x < 7; x++){
		int y = x+1;
		if (group.GetSection(x, Section))
			{
				this->_Count[y] = Section.RowCount;
				for (int i = 0; i < Section.RowCount; i++)
				{
					
					Day[y][i].ItemType = Section.Rows[i].GetInt(0);
					Day[y][i].ItemIndex = Section.Rows[i].GetInt(1);
					Day[y][i].ItemLevel = Section.Rows[i].GetInt(2);
					Day[y][i].ItemLuck = Section.Rows[i].GetInt(3);
					Day[y][i].ItemSkill = Section.Rows[i].GetInt(4);
					Day[y][i].ItemDur = Section.Rows[i].GetInt(5);
					Day[y][i].ItemOpt = Section.Rows[i].GetInt(6);
					Day[y][i].ItemExc = Section.Rows[i].GetInt(7);
				}
			}
	}
}
void Premio_Diario::darpremio(int aIndex,int dia,char * date) {
	char cmd[255];
	Manager.setpremiodia(gObj[aIndex].AccountID, PremioDiario[aIndex].dia+1);
	Manager.setpremiodata(gObj[aIndex].AccountID, date);
	Manager.ExecFormat("UPDATE[MuOnline].[dbo].[MEMB_INFO] SET gold = gold + %d WHERE memb___id = '%s'", this->valor[dia], gObj[aIndex].AccountID);;
	for (int i = 0; i < this->_Count[dia]; i++){
		sprintf(cmd, "%d %d %d %d %d %d %d %d", Day[dia][i].ItemType, Day[dia][i].ItemIndex, Day[dia][i].ItemLevel, Day[dia][i].ItemDur, Day[dia][i].ItemSkill, Day[dia][i].ItemLuck, Day[dia][i].ItemOpt, Day[dia][i].ItemExc);
		Command.makecomprar(aIndex, cmd, "Premio Diario");
	}
	func.MsgUser(aIndex, 1, "Obrigado por jogar conosco.");
	func.MsgUser(aIndex, 1, "Hoje é seu %d° login diario",dia);
	func.MsgUser(aIndex, 1, "Ganhou %d Gold.", this->valor[dia]);
}
Premio_Diario Pdiario;