#pragma once
class cOffProtocol
{
public:
	cOffProtocol(void);
	virtual ~cOffProtocol(void);
	void SendGetRequest(char *message, ...);
	void Init(void);
	void ICSPJoinIdPassRequest(LPBYTE aRecv,int aIndex);
	static void Login_Timer(void * lpParam);
};extern cOffProtocol OffProtocol;
