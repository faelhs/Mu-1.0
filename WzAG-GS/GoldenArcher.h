
class cNpc
{
public:
	bool Load();
	void Gowther(OBJECTSTRUCT* Npc, OBJECTSTRUCT* lpObj);
    static BOOL NPCTalk(OBJECTSTRUCT* lpNpc, OBJECTSTRUCT* lpObj);

private:
	bool				_Active;
	int				    _Type;
	int				    _Index;
	int				    _Level;
	int				    _Quantity;
	char				_Notice[3][160];
	char				_Query[100];
};

extern cNpc Npc;