#include "Principal.h"

//============================================================================
// Custom Conditional Text of Jewels
//============================================================================
char * Went_text		= "Novas Joias";
char * fixchaos			= "Usado em combinações chaos.";
char * Jewel25			= "Eleva o nível do Item para +13";
char * Jewel26			= "Adiciona Option+28 ao Item";
char * Jewel27			= "Adiciona Skill ao Item";
char * Jewel28			= "Eleva o nível do Item para +14/+15";
char * Jewel29			= "Torna o seu Item Excellent";
char * Ancient			= "Adiciona a opção Ancient ao Item";
char * Luck				= "Adiciona a opção Luck ao Item";

WORD	dwItemPrice_Pointer;
DWORD	dwItemPrice_Money;

#define Naked(Function) void __declspec(naked) Function()

//============================================================================
// Custom Jewels Color Item ASM
//============================================================================
void __declspec(naked) JewelsColor()
{
	_asm
	{
		//Original Soul
		cmp cx, ITEMGET(14, 14);
		je AddColor;

		//Jewel_of_Dragon
		cmp cx, ITEMGET(12, 15);
		je AddColor;

		//Jewel_of_Dragon
		cmp cx, ITEMGET(12, 25);
		je AddColor;

		//Jewel_of_Eternal
		cmp cx, ITEMGET(12, 26);
		je AddColor;

		//Jewel_of_Skill
		cmp cx, ITEMGET(12, 27);
		je AddColor;

		//Jewel_of_Rainbow
		cmp cx, ITEMGET(12, 28);
		je AddColor;

		//Jewel_of_Mystical
		cmp cx, ITEMGET(12, 29);
		je AddColor;
		//

		//Ancient Medal
		cmp cx, ITEMGET(14, 27);
		je AddColor;

		//jewel of Luck
		cmp cx, ITEMGET(14, 30);
		je AddColor;


		mov edx, COLOR_ADR_RETURN
			jmp edx;

AddColor:
		mov edx, COLOR_ADR_ALLOW
			jmp edx;
	}
}




//============================================================================
// Custom Descripcion Item ASM
//============================================================================
//	Color de la tabla:
//	//------------------------------------------------------------------------
//	0x00 = Branco
//	0x01 = azul
//	0x02 = roxo
//	0x03 = amarelo
//	0x04 = verde
//	0x05 = cor texto branco,fundo vermelho
//	0x06 = margenta
//	0x07 = cor texto branco,fundo azul
//	0x08 = cor texto branco,fundo beige
//	0x09 = cor texto verde,fundo azul
//	0x0A = gris
//	0x0B = púrpura (escuro)

//============================================================================
// Custom InfoText Switch in ASM
//============================================================================
__declspec(naked) void JewelInfoText()
{
	_asm
	{
		//------------------------------------------------------------------------
		// Original 
		//------------------------------------------------------------------------
		MOV ECX,DWORD PTR SS:[EBP+0x10]
		CMP WORD PTR DS:[ECX],0x18F
		JNZ Item1
		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH fixchaos
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],EBX
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX

Item1:
		MOV ECX,DWORD PTR SS:[EBP+0x10]
		CMP WORD PTR DS:[ECX],0x199
		JNZ item2
		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH Jewel25
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],0x09
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX

		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH Went_text
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],0x05
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX
		JMP Exit
item2:
		MOV ECX,DWORD PTR SS:[EBP+0x10]
		CMP WORD PTR DS:[ECX],0x19A
		JNZ item3
		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH Jewel26
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],0x09
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX

		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH Went_text
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],0x05
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX
		JMP Exit
item3:
		MOV ECX,DWORD PTR SS:[EBP+0x10]
		CMP WORD PTR DS:[ECX],0x19B
		JNZ item4
		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH Jewel27
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],0x09
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX

		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH Went_text
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],0x05
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX
		JMP Exit
item4:
		MOV ECX,DWORD PTR SS:[EBP+0x10]
		CMP WORD PTR DS:[ECX],0x19C
		JNZ item5
		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH Jewel28
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],0x09
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX

		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH Went_text
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],0x05
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX
		JMP Exit
item5:
		MOV ECX,DWORD PTR SS:[EBP+0x10]
		CMP WORD PTR DS:[ECX],0x19D
		JNZ item6
		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH Jewel29
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],0x09
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX

		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH Went_text
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],0x05
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX
		JMP Exit
item6:
		MOV ECX,DWORD PTR SS:[EBP+0x10]
		CMP WORD PTR DS:[ECX],0x1DB
		JNZ item7
		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH Ancient
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],0x09
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX

		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH Went_text
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],0x05
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX
		JMP Exit
item7:
		MOV ECX,DWORD PTR SS:[EBP+0x10]
		CMP WORD PTR DS:[ECX],0x1DE
		JNZ Exit
		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH Luck
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],0x09
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX

		LEA EAX,DWORD PTR DS:[EAX+EAX*0x4]
		PUSH Went_text
		LEA EDX,DWORD PTR DS:[EAX+EAX*0x4]
		LEA EAX,DWORD PTR DS:[EDX*0x4+0x7803D98]
		PUSH EAX
		mov esi, 0x0064A747
		CALL esi
		MOV EAX,DWORD PTR DS:[0x7836438]
		ADD ESP,0x8
		MOV DWORD PTR DS:[EAX*0x4+0x7804E88],0x05
		MOV DWORD PTR DS:[EAX*0x4+0x7833B48],EBX
		INC EAX
		MOV DWORD PTR DS:[0x7836438],EAX
		JMP Exit
	
/*item8:
			MOV ECX, DWORD PTR SS : [EBP + 0x10]
			CMP WORD PTR DS : [ECX], 0x17E
			JNZ Exit
			LEA EAX, DWORD PTR DS : [EAX + EAX * 0x4]
			PUSH Ancient
			LEA EDX, DWORD PTR DS : [EAX + EAX * 0x4]
			LEA EAX, DWORD PTR DS : [EDX * 0x4 + 0x7803D98]
			PUSH EAX
			mov esi, 0x0064A747
			CALL esi
			MOV EAX, DWORD PTR DS : [0x7836438]
			ADD ESP, 0x8
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7804E88], 0x09
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7833B48], EBX
			INC EAX
			MOV DWORD PTR DS : [0x7836438], EAX

			LEA EAX, DWORD PTR DS : [EAX + EAX * 0x4]
			PUSH Went_text
			LEA EDX, DWORD PTR DS : [EAX + EAX * 0x4]
			LEA EAX, DWORD PTR DS : [EDX * 0x4 + 0x7803D98]
			PUSH EAX
			mov esi, 0x0064A747
			CALL esi
			MOV EAX, DWORD PTR DS : [0x7836438]
			ADD ESP, 0x8
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7804E88], 0x05
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7833B48], EBX
			INC EAX
			MOV DWORD PTR DS : [0x7836438], EAX
			JMP Exit
*/
	Exit:
		mov esi,0x0058E634
		jmp esi
	}
} 

Naked (DisplayBigJewel)
{
	_asm
	{
		CMP ESI, 0x397
		JE Exit

		CMP ESI, 0x392
		JE Exit

		CMP ESI, 0x393
		JE Exit

		CMP ESI, 0x394
		JE Exit

		CMP ESI, 0x395
		JE Exit

		CMP ESI, 0x396
		JE Exit

		mov edi, 0x005B61CC

		jmp edi

	Exit:
		mov edi, 0x005B64EC 


		jmp edi
	}
}

//============================================================================
// Custom Jewel Switch in ASM
//============================================================================
__declspec(naked) void JewelsSwitcher()
{
	_asm
	{
		//Original
		CMP SI, ITEMGET(14, 14)
			JE ItemAllowed

			//JewelOfDragon
			CMP SI, ITEMGET(12, 25)
			JE ItemAllowed

			//JewelOfEternal
			CMP SI, ITEMGET(12, 26)
			JE ItemAllowed

			//JewelOfLuck
			CMP SI, ITEMGET(12, 27)
			JE ItemAllowed

			//JewelOfMystical
			CMP SI, ITEMGET(12, 28)
			JE ItemAllowed

			//JewelOfRainbow
			CMP SI, ITEMGET(12, 29)
			JE ItemAllowed

			//Jewel of exelent
			cmp SI, ITEMGET(14, 27);
			JE ItemAllowed;

			//jewel of Luck
			cmp SI, ITEMGET(14, 30);
			JE ItemAllowed;

			//jewel of guardian
			cmp SI, ITEMGET(14, 31);
			JE ItemAllowed;

			cmp SI, ITEMGET(7, 31);
			JE ItemAllowed;

		mov eax, 0x005A1518 //1.00L
			jmp eax

ItemAllowed :
		mov eax, 0x005A1536 //1.00L
			jmp eax
	}
}

//============================================================================
// Custom Jewel MoveItems1 in ASM
//============================================================================
__declspec(naked) void JewelsMoveItems1()
{
	_asm
	{
		//Original
		CMP DX, ITEMGET(14, 14)
			JE ItemMove1

			//JewelofDragon
			CMP DX, ITEMGET(12, 25)
			JE ItemMove1

			//JewelOfEternal
			CMP DX, ITEMGET(12, 26)
			JE ItemMove1

			//JewelOfLuck
			CMP DX, ITEMGET(12, 27)
			JE ItemMove1

			//JewelOfMystical
			CMP DX, ITEMGET(12, 28)
			JE ItemMove1

			//JewelOfRainbow
			CMP DX, ITEMGET(12, 29)
			JE ItemMove1

			//Ancient Metal
			CMP DX, ITEMGET(14, 27);
			JE ItemMove1

			//jewel of Luck
			CMP DX, ITEMGET(14, 30);
			JE ItemMove1

			mov eax, 0x005ADABE
			jmp eax

ItemMove1 :
		mov eax, 0x005ADAC9
			jmp eax
	}
}

//============================================================================
// Custom Jewel MoveItems2 in ASM
//============================================================================
__declspec(naked) void JewelsMoveItems2()
{
	_asm
	{
		//Original
		CMP DX, ITEMGET(14, 14)
			JE ItemMove2

			//// BoxGreen
			//CMP DX, ITEMGET(12, 25)
			//JE ItemMove2

			////BoxPurple
			//CMP DX, ITEMGET(12, 26)
			//JE ItemMove2

			////BoxRed
			//CMP DX, ITEMGET(12, 27)
			//JE ItemMove2


			mov eax, 0x005B479C
			jmp eax

ItemMove2 :
		mov eax, 0x005B5A02
			jmp eax
	}
}

//============================================================================
// Custom Init Modules
//============================================================================
void Joias()
{
	//Hook JewelColor
	BYTE JewelsColors[] = { 0xFF, 0x25, 0xE0, 0x9F, 0x96, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90 };
	memcpy((int*)0x0058B77E, JewelsColors, sizeof(JewelsColors));
	*(unsigned int*)0x00969FE0 = (unsigned int)JewelsColor;
	//Hook JewelText
	SetNop(0x0058E5B0,129);
	HookOffset((DWORD)&JewelInfoText, 0x0058E5B0, 0xE9);
	//Hook JewelsSwitcher
	BYTE JewelsSwitchers[] = { 0xFF, 0x25, 0x00, 0x9F, 0x96, 0x00, 0x90 };
	memcpy((int*)0x005A1511, JewelsSwitchers, sizeof(JewelsSwitchers));
	*(unsigned int*)0x00969F00 = (unsigned int)JewelsSwitcher;
	//Hook JewelMoveItem1
	BYTE ItemMove1[] = { 0xFF, 0x25, 0xD5, 0x9F, 0x96, 0x00, 0x90 };
	memcpy((int*)0x005ADAB7, ItemMove1, sizeof(ItemMove1));
	*(unsigned int*)0x00969FD5 = (unsigned int)JewelsMoveItems1;
	//Hook JewelMoveItem2
	BYTE ItemMove2[] = { 0xFF, 0x25, 0xB0, 0x9F, 0x96, 0x00, 0x90 };
	memcpy((int*)0x005B4791, ItemMove2, sizeof(ItemMove2));
	*(unsigned int*)0x00969FB0 = (unsigned int)JewelsMoveItems2;
	//Hook ModelsLoad
	ModelsLoad();
	//Hook Big Jewels
	//SetNop(0x005B61C0, 12);
	//HookOffset((DWORD)&DisplayBigJewel, 0x005B61C0, 0xE9);
}


