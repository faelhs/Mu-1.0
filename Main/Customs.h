#pragma once

void Customs();
void ChkParametro();
void Initialize();
void Finalize();

#define ErrorDir	"Data/Customs/Log"
#define DumpLog		"Data/Customs/Log/Error.dmp"
#define ErrorLog	"Data/Customs/Log/Error.log"
#define BWINI		"Data/Customs/BW.ini"
#define AUTOCLICK_LEFT		70001
#define AUTOCLICK_RIGHT		70002

extern HWND         Window;
extern HHOOK        m_Keyboard;
extern HMODULE		m_Glow;
extern HMODULE		m_Cam;
extern HMODULE		m_Min;
extern BYTE         MouseState;
extern bool         FireTeam;
extern bool         RunningFG;
extern bool         AutoClick[3];

LRESULT CALLBACK KeyboardHookProc(int Code, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcEx(HWND Window, UINT Message, WPARAM W, LPARAM L);