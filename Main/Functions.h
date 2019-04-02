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

DWORD SetDword(const LPVOID dwOffset, const DWORD dwValue);
DWORD SetRange(const LPVOID dwAddress, const USHORT wCount, const BYTE btValue);
DWORD SetHook1(const LPVOID dwMyFuncOffset, const LPVOID dwJmpOffset, const BYTE cmd);
DWORD ReadMemory(const LPVOID lpAddress, LPVOID lpBuf, const UINT uSize);
DWORD SetByte1(const LPVOID dwOffset, const BYTE btValue);
DWORD GetByte(const LPVOID dwOffset, BYTE & btValue);
DWORD GetWord(const LPVOID dwOffset, WORD & wValue);
DWORD SetDword(const LPVOID dwOffset, const DWORD dwValue);
DWORD GetDword(const LPVOID dwOffset, DWORD & dwValue);
DWORD SetFloat(const LPVOID dwOffset, const float fValue);
DWORD GetFloat(const LPVOID dwOffset, float & fValue);
DWORD SetJmp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress);
DWORD SetJg(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress);
DWORD SetJa(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress);
void Kill(char *szxProcName);