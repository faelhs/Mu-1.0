//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 99.60T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "StdAfx.h"

void LogSystem::CustomLog(char * Text)
{
	return;
	SYSTEMTIME now;
	GetLocalTime(&now);

	TCHAR LogTexto[512];
	FILE *stream;

	TCHAR logString[512];

	wsprintf(logString,"Log\\%02d_%02d_%02d_SQL_Log.txt", now.wYear, now.wMonth,now.wDay );
	stream=fopen(logString, "a+");
	fprintf(stream,"%02d:%02d:%02d -[B&W] %s\n", now.wHour, now.wMinute, now.wSecond, Text);
	fclose(stream);
}
void LogSystem::DKLog(char * Text , char* Text2 , ...)
{
	SYSTEMTIME now;
	GetLocalTime(&now);

	TCHAR LogTexto[512];
	FILE *stream;

	TCHAR logString[512];
	LogAddFunc("[B&W] %s : %s", Text,Text2, 3);
	wsprintf(logString, "Log\\%02d_%02d_%02d_DKLog.txt", now.wYear, now.wMonth, now.wDay);
	stream = fopen(logString, "a+");
	fprintf(stream, "%02d:%02d:%02d - [B&W] %s : %s\n", now.wHour, now.wMinute, now.wSecond, Text, Text2);
	fclose(stream);
}