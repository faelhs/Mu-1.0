/*
Code: Add new monsters to MuOnline client
Credits: DoS.Ninja
Web: ninja-researcher.blogspot.com
*/
#ifndef HOOK_H
#define HOOK_H

//Opcode const
#define _asm_call	0xE8
#define _asm_push	0x68
#define _asm_jmp	0xE9
#define _asm_jmps	0xEB//jmp short
#define _asm_jes	0x74
#define _asm_jnzs	0x75
#define _asm_jnz2	0x0F85//jmp short
#define _asm_nop	0x90
#define _asm_retn	0xC3
#define _asm_push_eax 0x50

#define MEMORY4(value) *(unsigned int*)(value)
#define MEMORY2(value) *(unsigned short*)(value)
#define MEMORY1(value) *(unsigned char*)(value)

void Access(DWORD dwOffset, int t_size);
void HookAddress(DWORD dwAddrOffst, DWORD dwNewOffst, BYTE new_Cmd);

#endif