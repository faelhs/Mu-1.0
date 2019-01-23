#pragma once

void Hook(BYTE Type, DWORD Offset, DWORD Function);
void SetNop(DWORD Offset,int Size);
void HookOffset(DWORD my, DWORD tohook, BYTE type);
void WriteJmp(DWORD dwWriteOffset, DWORD dwDstJmp);
void SetByte(DWORD dwOffset, BYTE btValue);
void Protect(DWORD dwAddr, DWORD size, DWORD dwProtection);
DWORD UnProtect(DWORD dwAddr, DWORD size);
void HookThis(DWORD dwMyFuncOffset, DWORD dwJmpOffset);
DWORD SetHook(const LPVOID dwMyFuncOffset, const LPVOID dwJmpOffset, const BYTE cmd);
DWORD WriteMemory(const LPVOID lpAddress, const LPVOID lpBuf, const UINT uSize);
bool FileExists(char * name);
DWORD SetOp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress, const BYTE cmd);