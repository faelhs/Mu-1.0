#include "Principal.h"
#include "Customs.h"

extern "C" __declspec(dllexport) void Cust()
{
}

BOOL APIENTRY DllMain(HINSTANCE Instance, DWORD Reason, LPVOID Reserved)
{
	switch(Reason)
	{
	case DLL_PROCESS_ATTACH:
		{
			DWORD OldProtect;
			if(VirtualProtect((LPVOID)(0x401000), 2834430, PAGE_EXECUTE_READWRITE, &OldProtect) == TRUE)
			{
				Initialize();
			}
		}
		break;
	case DLL_PROCESS_DETACH:
		{
			Finalize();

		}
		break;
	}

	return TRUE;
}