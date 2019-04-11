#include"StdAfx.h"

CShopNPC CShopnpc;

void CShopNPC::Load(){
		short X, Y;
		BYTE Map   = 0;

		this->_index	 = gObjAddMonster(Map);
		this->_shopNumber = 1;
		
			X= 130;
			Y= 130;
			
			gObjSetMonster(this->_index, 201);
			OBJECTSTRUCT* lpNpc = &gObj[this->_index];
			lpNpc->Class                    = 201;
			lpNpc->MapNumber                = Map;
			lpNpc->X                        = X;
			lpNpc->Y                        = Y;
			lpNpc->Dir						= (rand() % 7);
			//lpNpc->m_RecallMon				= this->_index;
			//lpNpc->TargetNumber				= -1;
			lpNpc->TX						= lpNpc->X;
			lpNpc->TY						= lpNpc->Y;
			lpNpc->MTX						= lpNpc->X;
			lpNpc->MTY						= lpNpc->Y;
			lpNpc->m_OldX					= lpNpc->X;
			lpNpc->m_OldY					= lpNpc->Y;
			lpNpc->StartX					= (BYTE)(lpNpc->X);
			lpNpc->StartY					= (BYTE)(lpNpc->Y);
			lpNpc->m_ActState.Emotion		= 0;
			lpNpc->m_ActState.Attack		= 0;
			lpNpc->m_ActState.EmotionCount	= 0;        
			lpNpc->PathCount				= 0;
			lpNpc->m_MoveRange				= 0;
			lpNpc->m_PosNum					= -1;
			lpNpc->ShopNumber				= this->_shopNumber;
			gObjViewportListProtocolCreate(&gObj[this->_index]);
		
}