#pragma once
#pragma warning (disable: 4996 4091 4101 4018 4309 4099 4102 4800 4244 4482 4305 4005)

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <time.h>
#include <process.h>
#include <WinSock2.h>
#include <ShellAPI.h>
#include <vector>
#include <gl\gl.h>
#include <gl\glu.h>

#pragma comment(lib,"user32.lib")
#pragma comment(lib,"OpenGL32.lib")
#pragma comment(lib,"Detours.lib")

#include "Fog.h"
#include "Customs.h"
#include "detours.h"
#include "Functions.h"
#include "Protocol.h"
#include "Packets.h"
#include "Offsets.h"
#include "Preview.h"
#include "HealthBar.h"
#include "MiniMap.h"
#include "Jewels.h"
#include "ExpBar.h"
#include "Models.h"
#include "Camera.h"
#include "glaux.h"

		LRESULT CALLBACK KeyboardProc(int, WPARAM, LPARAM);
	LRESULT CALLBACK MouseProc(int, WPARAM, LPARAM);
	BOOL MouseSetHook(BOOL);
	BOOL KeyboardSetHook(BOOL);