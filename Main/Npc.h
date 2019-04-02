#define __object_render ((LPVOID (__cdecl*)(DWORD Arg1, DWORD m_iMonsterID, DWORD Arg3, DWORD Arg4, DWORD Arg5)) 0x004FAF70)

struct struct_dword30
{
	BYTE gap0[4];
	DWORD dword4;
	BYTE gap8[8];
	BYTE byte10;
	DWORD dword14;
	BYTE gap18[12];
	DWORD dword24;
	BYTE gap28[12];
	DWORD dword34;
	BYTE gap38[12];
	DWORD dword44;
	BYTE gap48[12];
	DWORD dword54;
	BYTE gap58[8];
	BYTE byte60;
	DWORD dword64;
	BYTE gap68[12];
	DWORD dword74;
	BYTE gap78[12];
	DWORD dword84;
	BYTE gap88[12];
	DWORD dword94;
	BYTE gap98[12];
	DWORD dwordA4;
};


struct struct_v2_2
{
	BYTE gap0[36];
	WORD word24;
	WORD word26;
	BYTE gap28[8];
	struct_dword30 *dword30;
	BYTE gap34[32];
	DWORD dword54;
};
class CObjectPreview
{
public:
	bool Loading();
	static LPVOID Render(DWORD m_iMonsterID, DWORD Arg1, DWORD Arg3, DWORD Arg4, DWORD Arg5);

};

extern CObjectPreview _obj_preview;



////////////////////////////////
#define MAX_MONSTERS		 50
#define BMDTexture			338
#define Kundum_MonsterShow	((int(__cdecl*)(int MonsterIndex, int a2, int a3, int a4)) 0x0042A170)//ok
#define LoadMonsterBMD		((char(__cdecl*)(int BMDNumber)) 0x005E5CC0)	//Sumar 296 ?
#define LoadTextureMonster	((int(__cdecl*)(int a1, int Texture, int a3, int a4, int a5)) 0x004F9E00)//ok
#define Unk_MonsterFunc		((int(__cdecl*)(int a1)) 0x004F9EC0)//ok
#define gLoad_LoadTexture	((char(__cdecl*)(int a1, int Folder, const char *File, signed int Texture)) 0x005E10E0)//ok
#define GetBMDTexture(BMDFile)((BMDFile + BMDTexture))

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


typedef struct
{
	int Index;
	float Size;
	char Name[15];

} Monster_Attribute;

enum CustomMonster
{
	CRAZY_DK = 201,
	CRAZY_SM = 202,
	CRAZY_ME = 203,
	CRAZY_MG = 204,
	CRAZY_DL = 205,
	ShadowPhantomSoldier = 206,

	//Land of Trials: 
	Land_Lizard = 207,
	Land_Fire = 208,
	Land_Queen = 209,
	Land_Poison = 210,
	Land_Axe = 211,
	Land_Erohim = 212,

	//Crywolf: 
	Cry_Death = 213,
	Cry_Solam = 214,
	Cry_Were = 215,
	Cry_Bow = 216,
	Cry_Lance = 217,
	Cry_Hammer = 218,
	Cry_Balista = 219,

	//Aida: 
	Aida_Witch = 220,
	Aida_Blue = 221,
	Aida_Death = 222,
	Aida_Forest = 223,
	Aida_Deaths = 224,
	Aida_Hell = 225,

	//Raklion
	Rakion_IceWalker = 276,
	Raklion_Mamoth = 277,
	Raklion_Ice = 278,
	Raklion_Spider = 279,
	Raklion_Higher = 280,
	Raklion_Selupan = 281,

};
class CMonsters
{
public:
	void Init();
	void Load_Atributtes();
	int	AddNewMonster(int MonsterFileBMD, int a2, int a3, int a4, int MobIndex);


private:
	Monster_Attribute Monster_Atributte[MAX_MONSTERS];
	int	AtributteCount;
	void SetMonsterAtributte(int MonsterStructure, int MonsterID);
	float GetSize(int MonsterID);
	char* GetName(int MonsterID);
	//float GetSizes(int MonsterID);
	//char * GetNames(int MonsterID);
	

}; extern CMonsters Monsters;

int	NewMonster_Switch(int MonsterIndex, int a2, int a3, int a4);



