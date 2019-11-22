#if !defined(RECONNECT_SYSTEM_H)
#define RECONNECT_SYSTEM_H

#if (_MSC_VER > 1000)
#pragma once
#endif /* _MSC_VER > 1000 */

#pragma pack(push, 1)
struct CONNECTEX_LOGIN
{
	PBMSG_HEAD2	h;
	char		AccountID[10];
	char		Password[10];
	char		Name[10];
	DWORD		TickCount;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct CONNECTEX_CLOSE
{
	PBMSG_HEAD2_DEV	h;
};
#pragma pack(pop)

struct SDHP_IDPASS
{
	PBMSG_HEAD_DEV h;
	char Id[10];
	char Pass[10];
	short Number;
	char IpAddress[17];
};

class CReconnectSystem
{
public:
	bool _send_login(int UserIndex, CONNECTEX_LOGIN * Data);
	bool _send_game(int UserIndex);
	bool _send_close(int UserIndex);
	// ----
	static bool JoinResult(BYTE btResult, int aIndex);
private:
	bool PacketCheckTime2(LPOBJ lpObj);
};

extern CReconnectSystem * gReconnectSystem;

#endif /* RECONNECT_SYSTEM_H */