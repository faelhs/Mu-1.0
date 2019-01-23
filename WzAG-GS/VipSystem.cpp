#include "StdAfx.h"

VipExp Vips;

void VipSettings()
{
	Vips.Exp1 = GetPrivateProfileIntA("VipSystem", "ExpVip1",		2000,	CFG_VIP);
	Vips.Exp2 = GetPrivateProfileIntA("VipSystem", "ExpVip2",		3000,	CFG_VIP);
	Vips.Exp3 = GetPrivateProfileIntA("VipSystem", "ExpVip3", 5000, CFG_VIP);
	Vips.Exp4 = GetPrivateProfileIntA("VipSystem", "ExpVip4", 5000, CFG_VIP);
	Vips.Exp5 = GetPrivateProfileIntA("VipSystem", "ExpVip5", 5000, CFG_VIP);
	
	Vips.Drop1 = GetPrivateProfileIntA("VipSystem", "DropVip1",		20,	CFG_VIP);
	Vips.Drop2 = GetPrivateProfileIntA("VipSystem", "DropVip2",		30,	CFG_VIP);
	Vips.Drop3 = GetPrivateProfileIntA("VipSystem", "DropVip3",		50,	CFG_VIP);
	Vips.Drop4 = GetPrivateProfileIntA("VipSystem", "DropVip4", 50, CFG_VIP);
	Vips.Drop5 = GetPrivateProfileIntA("VipSystem", "DropVip5", 50, CFG_VIP);

}

void VipSystem(int aIndex)
{
	VipSettings();

	switch (Custom[aIndex].VipIndex)
	{

	case 1:
		{
			float * EXPERIENCE = (float *)(getAddExperience);
			(*EXPERIENCE) = Vips.Exp1;
			SetDrop( GetDrop() + Vips.Drop1 );
			
		}
		break; 
	case 2:
		{
			float * EXPERIENCE = (float *)(getAddExperience);
			(*EXPERIENCE) = Vips.Exp2;
			SetDrop( GetDrop() + Vips.Drop2);

		}
		break; 
	case 3:
		{
			float * EXPERIENCE = (float *)(getAddExperience);
			(*EXPERIENCE) = Vips.Exp3;
			SetDrop( GetDrop() + Vips.Drop3);
		}
		break;
	case 4:
	{
		float * EXPERIENCE = (float *)(getAddExperience);
		(*EXPERIENCE) = Vips.Exp4;
		SetDrop(GetDrop() + Vips.Drop4);
	}
	break;
	case 5:
	{
		float * EXPERIENCE = (float *)(getAddExperience);
		(*EXPERIENCE) = Vips.Exp5;
		SetDrop(GetDrop() + Vips.Drop5);
	}
	break;
	}
}