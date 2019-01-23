//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # DARK PLUGIN - POWERED BY FIRE TEAM
// # GAME SERVER: 99.60T (C) WEBZEN.
// # VERSÃO: 1.0.0.0
// # Autor: Maykon
// # Skype: Maykon.ale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// # O Senhor é meu pastor e nada me faltará!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct CharacterBalancer
{
	short WizardAttack[4];
	short KnightAttack[4];
	short ElfAttack[16];
	short GladiatorAttack[8];
	short LordAttack[8];
	short AttackSpeed[5];
	short MagicSpeed[5];
	short SuccessfulBlocking[5];
	short Defense[5];
	short MagicDamageMin[5];
	short MagicDamageMax[5];
};

class CBalancer
{
public:
	CBalancer();
	~CBalancer();

public:
	void LoadSettings();
	static void gObjCalCharacter(int aIndex);

public:
	CharacterBalancer Character;
};

extern CBalancer Balancer;