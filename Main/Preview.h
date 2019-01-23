#if !defined(OBJECT_PREVIEW_H)
#define OBJECT_PREVIEW_H

#if (_MSC_VER > 1000)
#pragma once
#endif /* _MSC_VER > 1000 */

#pragma pack(push, 1)
struct SObjectPreview
{
	BYTE gap0[2];
	WORD word2;
	DWORD dword4;
	BYTE byte8;
	BYTE gap9[3];
	float fScalarMode;
	float float10;
	float float14;
	float float18;
	BYTE gap1C[60];
	DWORD dword58;
	BYTE gap5C[8];
	DWORD dword64;
	DWORD dword68;
	BYTE gap6C[12];
	DWORD dword78;
	BYTE gap7C[8];
	BYTE byte84;
	BYTE gap85[8];
	BYTE byte8D;
	BYTE gap8E[6];
	BYTE byte94;
	BYTE gap95[79];
	BYTE byteE4;
	BYTE gapE5[43];
	DWORD dword110;
	DWORD dword114;
	BYTE gap118[20];
	DWORD dword12C;
	DWORD dword130;
	DWORD dword134;
	BYTE gap138[52];
	DWORD dword16C;
	BYTE gap170[86];
	WORD word1C6;
	BYTE btCtlCode;
	char Name[25];
	BYTE gap1CA[46];
	short HelmSlot;
	BYTE _HelmLevel;
	BYTE HelmExcellent;
	BYTE HelmAncient;
	BYTE gap213[27];
	short ArmorSlot;
	BYTE _ArmorLevel;
	BYTE ArmorExcellent;
	BYTE ArmorAncient;
	BYTE gap233[27];
	short PantsSlot;
	BYTE _PantsLevel;
	BYTE PantsExcellent;
	BYTE PantsAncient;
	BYTE gap253[27];
	short GlovesSlot;
	BYTE _GlovesLevel;
	BYTE GlovesExcellent;
	BYTE GlovesAncient;
	BYTE gap273[27];
	short BootsSlot;
	BYTE _BootsLevel;
	BYTE BootsExcellent;
	BYTE BootsAncient;
	BYTE gap293[27];
	WORD WeaponFirstSlot;
	BYTE WeaponFirstLevel;
	BYTE WeaponFirstExcellent;
	BYTE WeaponFirstAncient;
	BYTE gap2B4[27];
	WORD WeaponSecondSlot;
	BYTE WeaponSecondLevel;
	BYTE WeaponSecondExcellent;
	BYTE WeaponSecondAncient;
	BYTE gap2D3[27];
	short WingsSlot;
	BYTE WingsLevel;
	BYTE WingsExcellent;
	BYTE WingsAncient;
	BYTE gap2D3_01[27];
	short PetSlot;
	BYTE PetLevel;
	BYTE PetExcellent;
	BYTE PetAncient;
	BYTE gap2D3_02[67];
	BYTE btStateCode;
	BYTE gap2D3_04[20];
	BYTE m_btPkLevel;
	BYTE gap2D3_03[4];
	BYTE byte36D;
	WORD word36E;
	BYTE gap370[14];
	WORD word37E;
	BYTE gap380[2];
	BYTE byte382;
	BYTE gap383[9];
	DWORD dword38C;
	BYTE gap390[12];
	WORD word39C;
	BYTE gap39E[62];
	BYTE byte3DC;
};
#pragma pack(pop)


#define __object_render ((LPVOID (__cdecl*)(DWORD Arg1, DWORD m_iMonsterID, DWORD Arg3, DWORD Arg4, DWORD Arg5)) 0x004FAF70)

#define _find_object_1 ((LPVOID (__cdecl*)(DWORD m_iMonsterID, DWORD Arg3, DWORD Arg4, DWORD Arg5)) 0x0042A170)
#define _find_object_2 ((LPVOID (__cdecl*)(DWORD m_iMonsterID, DWORD Arg3, DWORD Arg4, DWORD Arg5)) 0x00425BF0)
#define _find_object_3 ((LPVOID (__cdecl*)(DWORD m_iMonsterID, DWORD Arg3, DWORD Arg4, DWORD Arg5)) 0x00430800)

#define _unlock_object ((bool (__cdecl*)(LPVOID lpRender)) 0x004F9EC0)

class CObjectPreview
{
public:
	bool Loading();
	// ----
	bool _render_handler(DWORD m_iMonsterID, DWORD Arg2, DWORD Arg3, DWORD Arg4, LPVOID lpObjectView);
	// ----
	static LPVOID Render1(DWORD m_iMonsterID, DWORD Arg2, DWORD Arg3, DWORD Arg4);
	static LPVOID Render2(DWORD m_iMonsterID, DWORD Arg2, DWORD Arg3, DWORD Arg4);
	static LPVOID Render3(DWORD m_iMonsterID, DWORD Arg2, DWORD Arg3, DWORD Arg4);
	// ----
	static LPVOID Render(DWORD Arg1, DWORD m_iMonsterID, DWORD Arg3, DWORD Arg4, DWORD Arg5);
};

extern CObjectPreview _obj_preview;

#endif /* OBJECT_PREVIEW_H */