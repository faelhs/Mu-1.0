#ifndef _CGUSEITEMRECV_H
#define _CGUSEITEMRECV_H

void ReadyCGUseItemRecv();
void CGUseItemRecvEx(PMSG_USEITEM* lpMsg,int aIndex);
void deleteRecv(int aIndex, char slot, char target);
void UseItemRecv(PMSG_USEITEM* lpMsg,int aIndex);
#endif