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

class cDisplay
{
public:
	cDisplay();
	~cDisplay();

public:
	static void ViewPaint(HWND hWnd, short aIndex);
	static void LogTextPaintProcEx(HWND hWnd);
	static void LogTextAddEx(BYTE type, char *msg, int len);

private:
	HFONT  Font;
	HFONT  Fonta;
	HFONT  Fontb;
	HBRUSH Background;
	HBRUSH Backgrounda;
	HBRUSH Backgroundb;
	int    m_cline;	                                       
	char   LogText[30][180];
	short  LogTextLength[30];
	BYTE   LogTextViewType[30];
};

extern cDisplay Display;