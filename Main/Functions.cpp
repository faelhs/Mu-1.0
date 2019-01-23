#include "Principal.h"

void Hook(BYTE Type, DWORD Offset, DWORD Function)
{
	*(BYTE*)  (Offset) = Type;
	*(DWORD*) (Offset + 1) = Function - (Offset + 5);
}

void SetNop(DWORD Offset,int Size)
{
	for (int n = 0; n < Size; n++)
	{
		*(BYTE*) (Offset + n) = 0x90;
	}
}

DWORD SetOp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress, const BYTE cmd)
{
	BYTE btBuf[5];
	DWORD dwShift	= (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 5;

	btBuf[0]		= cmd;
	memcpy( (LPVOID) & btBuf[1], (LPVOID) & dwShift, sizeof(ULONG_PTR));

	return WriteMemory(dwEnterFunction, (LPVOID) btBuf, sizeof(btBuf));
}

void HookOffset(DWORD my, DWORD tohook, BYTE type)
{
	*(BYTE*)tohook = type;
	*(DWORD*)(tohook+1) = my - (tohook+5);
}
void WriteJmp(DWORD dwWriteOffset, DWORD dwDstJmp)
{
	if(dwWriteOffset)
	{
		__try
		{
			DWORD dwP = UnProtect(dwWriteOffset, 10);
			SetByte(dwWriteOffset, 0xE9);
			HookThis(dwDstJmp, dwWriteOffset);
			Protect(dwWriteOffset, 10, dwP);
		}
		__finally{}
	}
}

void SetByte(DWORD dwOffset, BYTE btValue)
{
	__try
	{
		DWORD dwP = UnProtect(dwOffset, 1);
		*(BYTE*)(dwOffset)=btValue;
		Protect(dwOffset, 1, dwP);
	}
	__finally{}
}

void Protect(DWORD dwAddr, DWORD size, DWORD dwProtection)
{
	DWORD old = 0;
	VirtualProtect((LPVOID)dwAddr, size, dwProtection, &old);
}

DWORD UnProtect(DWORD dwAddr, DWORD size)
{
	DWORD old = 0;
	VirtualProtect((LPVOID)dwAddr, size, PAGE_EXECUTE_READWRITE, &old);
	return old;
}

void HookThis(DWORD dwMyFuncOffset, DWORD dwJmpOffset)
{
	*(DWORD*)(dwJmpOffset+1) = dwMyFuncOffset -(dwJmpOffset+5);
}

DWORD SetHook(const LPVOID dwMyFuncOffset, const LPVOID dwJmpOffset, const BYTE cmd)
{
	BYTE btBuf[5];
	// ----
	DWORD dwShift	= (ULONG_PTR)dwMyFuncOffset - ((ULONG_PTR)dwJmpOffset + 5);
	// ----
	btBuf[0] = cmd;
	// ----
	memcpy( (LPVOID) & btBuf[1], (LPVOID) & dwShift, sizeof(ULONG_PTR));
	// ----
	return WriteMemory(dwJmpOffset, (LPVOID) btBuf, sizeof(btBuf));
}

DWORD WriteMemory(const LPVOID lpAddress, const LPVOID lpBuf, const UINT uSize)
{
    DWORD dwErrorCode   = 0;
    DWORD dwOldProtect  = 0;
	// ----
    int iRes = VirtualProtect(lpAddress, uSize, PAGE_EXECUTE_READWRITE, & dwOldProtect);
	// ----
    if ( iRes == 0 )
    {
        dwErrorCode = GetLastError();
        return dwErrorCode;
    }
	// ----
    memcpy(lpAddress, lpBuf, uSize);
	// ----
    DWORD dwBytes   = 0;
	// ----
    iRes = VirtualProtect(lpAddress, uSize, dwOldProtect, & dwBytes);
	// ----
    if ( iRes == 0 )
    {
        dwErrorCode = GetLastError();
        return dwErrorCode;
    }
	// ----
    return 0x00;
}

bool FileExists(char * name)
{
	if(CreateFile(name,0,0,0,OPEN_EXISTING,0,0) == INVALID_HANDLE_VALUE)
		return false;
	return true;
}