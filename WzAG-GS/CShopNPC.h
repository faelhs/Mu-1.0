#pragma once


class CShopNPC
{
public:
	void Load();
	void Talk(OBJECTSTRUCT* Npc, OBJECTSTRUCT* Player);
	BYTE ShopNumber() const;

private:
	int		_index;
	BYTE	_shopNumber;
};
extern CShopNPC CShopnpc;