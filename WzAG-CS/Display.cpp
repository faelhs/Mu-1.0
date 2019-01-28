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

char * TitleText[1] =
{
	" _=| PGBrasil-CS |=_ "
};

char * TitleTexta[1] =
{
	" Private Games Brasil - Desenvolvido por Black & White Team "
};

cDisplay::cDisplay()
{
	this->Font = CreateFontA(80, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 5, DEFAULT_PITCH | FF_DONTCARE, "Impact");
	this->Fonta = CreateFontA(80, 0, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 5, DEFAULT_PITCH | FF_DONTCARE, "Impact");
	this->Fontb = CreateFontA(18, 0, 0, 0, FW_EXTRALIGHT, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 5, DEFAULT_PITCH | FF_DONTCARE, "Verdana");
	this->Background = CreateSolidBrush(RGB(0,250,0));
	this->Backgrounda = CreateSolidBrush(RGB(0, 220, 0));
	this->Backgroundb = CreateSolidBrush(RGB(0, 200, 0));
}

cDisplay::~cDisplay()
{
	DeleteObject(this->Font);
	DeleteObject(this->Background);
}

void cDisplay::ViewPaint(HWND hWnd, short aIndex)
{
	char Buffer[256];

	int iMonsterCount = 0;
	int iFreeCount = 0;
	int iVipCount = 0;
	int Staffers = 0;
	int iTotalCount = 0;
	
	for (int i = 0; i < OBJECT_MAX; i++)
	{
		if (i < OBJECT_MIN)
		{
			if (gObj[i].Type != PLAYER && gObj[i].Connected == 3)
			{
				iMonsterCount++;
			}
		}
		else
		{
			if (gObj[i].Type == PLAYER && gObj[i].Connected == 3)
			{
				if (Custom[i].VipIndex == 0 && gObj[i].Authority == 1)
				{
					iFreeCount++;
				}

				if (Custom[i].VipIndex > 0 && gObj[i].Authority == 1)
				{
					iVipCount++;
				}

				if (gObj[i].Authority > 1)
				{
					Staffers++;
				}

				iTotalCount++;
			}
		}
	}

	TotalUser = iTotalCount;

	wsprintf(Buffer,"MOBS: %d - FREE: %d  -  VIP: %d  -  GM: %d  -  ONLINE: %d  -  MAX: %d", iMonsterCount,iFreeCount,iVipCount,Staffers,iTotalCount,ServerMaxUser);
	
	RECT rect;
	RECT recta;
	RECT rectb;

	HDC hDC = GetDC(hWnd);
	HDC hDCa = GetDC(hWnd);
	HDC hDCb = GetDC(hWnd);

	int OldBkMode = SetBkMode(hDC, TRANSPARENT);
	int OldBkModea = SetBkMode(hDCa, TRANSPARENT);
	int OldBkModeb = SetBkMode(hDCb, TRANSPARENT);

	GetClientRect(hWnd, &rect);
	GetClientRect(hWnd, &recta);
	GetClientRect(hWnd, &rectb);
	
	recta.top = 0;
	recta.bottom = 30;
	rect.top = 30;
	rect.bottom = 160;
	rectb.top = 160;
	rectb.bottom = 190;

	SetTextColor(hDC, RGB(171, 171, 171));
	SetTextColor(hDCa, RGB(171, 171, 171));
	SetTextColor(hDCb, RGB(171, 171, 171));

	FillRect(hDC, &rect, Display.Background);
	FillRect(hDCa, &recta, Display.Backgrounda);
	FillRect(hDCb, &rectb, Display.Backgroundb);

	HFONT pOldFont = (HFONT)SelectObject(hDC, Display.Font);
	HFONT pOldFonta = (HFONT)SelectObject(hDCa, Display.Font);
	HFONT pOldFontb = (HFONT)SelectObject(hDCb, Display.Font);

	SetTextColor(hDC, RGB(255, 255, 255));
	SetTextColor(hDCa, RGB(255, 255, 255));
	SetTextColor(hDCb, RGB(255, 255, 255));

	TextOutA(hDC, 380, 50, TitleText[0], strlen(TitleText[0]));
	
	SelectObject(hDC, pOldFont);
	SelectObject(hDCa, pOldFonta);
	SelectObject(hDCb, pOldFontb);

	SetBkMode(hDC, OldBkMode);
	SetBkMode(hDCa, 0);
	SetBkMode(hDCb, 0);

	SetTextColor(hDCa, RGB(100, 255, 100));
	SetTextColor(hDCb, RGB(100, 255, 100));

	TextOut(hDCa, 465, 168, Buffer, strlen(Buffer));
	TextOut(hDCb, 475, 6, TitleTexta[0], strlen(TitleTexta[0]));
	
	ReleaseDC(hWnd, hDC);
	ReleaseDC(hWnd, hDCa);
	ReleaseDC(hWnd, hDCb);
}

void cDisplay::LogTextPaintProcEx(HWND hWnd)
{
	HDC hdc;

	int total;
	int n;

	hdc=GetDC(hWnd);

	int iOldBkMode = SetBkMode (hdc,TRANSPARENT); 

	n = Display.m_cline;

	total = 28;
	HFONT pOldFont = (HFONT)SelectObject(hdc, Display.Fontb);
	while(total-- != 0)
	{
		switch (Display.LogTextViewType[n])
		{
		case 2: 
			SetTextColor(hdc, RGB(207,3,18));        
			break;
		case 3:  
			SetTextColor(hdc, RGB(0,100,0));         
			break;
		case 4:
			SetTextColor(hdc, RGB(0,0,255));         
			break;	
		case 5:
			SetTextColor(hdc, RGB(155,0,0));
			break;
		case 6:  
			SetTextColor(hdc, RGB(0,0,100));         
			break;
		case 7:  
			SetTextColor(hdc, RGB(210,30,150));         
			break;
		case 8:  
			SetTextColor(hdc, RGB(255,255,0));         
			break;
		case 9:  
			SetTextColor(hdc, RGB(160,32,240));         
			break;
		case 10:  
			SetTextColor(hdc, RGB(255,69,0 ));         
			break;
		case 11:  
			SetTextColor(hdc, RGB(0,255,255));         
			break;
		case 12:  
			SetTextColor(hdc, RGB(255,215,0));         
			break; 
		default:  
			SetTextColor(hdc, RGB(171, 171, 171));
			break;	
		}

		if (strlen(Display.LogText[n]) > 1)
		{
		    TextOut(hdc,0,total *15 + 200,Display.LogText[n], strlen(Display.LogText[n]));
		}

		n--;

		if (n < 0)
		{
			n = 28 -1;
		}
	}

	SetBkMode(hdc,iOldBkMode);
	ReleaseDC(hWnd, hdc);
}

void cDisplay::LogTextAddEx(BYTE type, char* msg, int len)
{
	if (len > 180 -1)
	{
		len = 180 -1;
	}

	Display.m_cline++;

	if (Display.m_cline > 28 -1)
	{
		Display.m_cline = 0;
	}

	Display.LogText[Display.m_cline][0] = 0;
	memcpy(&Display.LogText[Display.m_cline],msg,len);
	Display.LogText[Display.m_cline][1+ len] = 0;
	Display.LogText[Display.m_cline][len] = 0;
	Display.LogTextLength[Display.m_cline]= len;
	Display.LogTextViewType[Display.m_cline] = type;
}

cDisplay Display;