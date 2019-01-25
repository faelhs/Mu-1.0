#include "Principal.h"

std::vector<HEALTH_BAR> HealthBar;

void cHealthBar::ClearNewHealthBar()
{
	HealthBar.clear();
}

void cHealthBar::InsertNewHealthBar(short Index, BYTE Rate)
{
	HEALTH_BAR Bar;

	Bar.Index = Index;
	Bar.Rate = Rate;

	HealthBar.push_back(Bar);
}

HEALTH_BAR* cHealthBar::GetNewHealthBar(short Index)
{
	for (std::vector<HEALTH_BAR>::iterator it = HealthBar.begin(); it != HealthBar.end(); ++it)
	{
		if (it->Index == Index)
		{
			return &(*it);
		}
	}

	return NULL;
}

void cHealthBar::DrawHealthBar()
{ 
	((void(*)())0x00581D70)();

	int PosX, PosY, LifeProgress;
	float LifeBarWidth = 38.0f;
	char LifeDisplay[20];

	VAngle Angle;

	HEALTH_BAR* NewHealthBar;

	for (int n = 0; n < 400; n++)
	{
		DWORD ViewPort = *(DWORD*)(0x073C81E4) + (n * 1068);

		if ((*(BYTE*)ViewPort != 0x0) && (*(BYTE*)(ViewPort + 132) == 2))
		{
			NewHealthBar = HPBar.GetNewHealthBar(*(WORD*)(ViewPort + 492));

			if (NewHealthBar == 0)
			{
				continue;
			}

			int LifePercent = NewHealthBar->Rate / 10;

			Angle.X = *(float*)(ViewPort + 16); 
			Angle.Y = *(float*)(ViewPort + 20);
			Angle.Z = *(float*)(ViewPort + 308) + *(float*)(ViewPort + 24) + 100.0f;

			GetPosFromAngle(&Angle, &PosX, &PosY);

			PosX -= (int)floor(LifeBarWidth / (double) 2.0);

			if ((CursorX >= PosX) && ((float)CursorX <= (float)PosX + LifeBarWidth) && (CursorY >= PosY - 2) && (CursorY < PosY + 6))
			{
				FixText(0, 0, "");
				wsprintf(LifeDisplay, "HP: %d0%%", LifePercent); // (char*)(ViewPort + 457) = Mobs Name
				glColor3f(1.0f, 1.0f, 1.0f);
				Text(PosX + 6, PosY - 6, LifeDisplay, 0, 0, 0);
			}

			SetBlend(true);

			glColor4f(0.0, 0.0, 0.0, 0.5);
			DrawBarForm((float)(PosX + 1), (float)(PosY + 1), LifeBarWidth + 4.0f, 5.0f, 0.0f, 0);
			GLSwitchBlend();

			glColor3f(0.2f, 0.0, 0.0);
			DrawBarForm((float)PosX, (float)PosY, LifeBarWidth + 4.0f, 5.0f, 0.0, 0);

			glColor3f(0.19607843f, 0.039215688f, 0.0);
			DrawBarForm((float)(PosX + 2), (float)(PosY + 2), LifeBarWidth, 1.0f, 0.0, 0);

			if (LifePercent > 10)
			{
				LifeProgress = 10;
			}
			else
			{
				LifeProgress = LifePercent;
			}

			for (int i = 0; i < LifeProgress; i++)
			{
				if (LifePercent >= 10) {
					glColor3f(0.01039216f, 0.939215688f, 0.0);
				}
				if (LifePercent < 10) {
					glColor3f(0.58039216f, 0.539215688f, 0.0);
				}
				if (LifePercent < 5) {
					glColor3f(0.98039216f, 0.039215688f, 0.0);
				}
				DrawBarForm((float)(i * 4 + PosX + 2), (float)(PosY + 2), 3.0, 2.0, 0.0, 0);
			}
			GLSwitch();
		}

		GLSwitch();

		glColor3f(1.0, 1.0, 1.0);
	}
}

void cHealthBar::DrawHealthBarOri()
{ 
	((void(*)())0x00581D70)();

	int PosX, PosY, LifeProgress;
	float LifeBarWidth = 38.0f;
	char LifeDisplay[20];

	VAngle Angle;

	HEALTH_BAR* NewHealthBar;

	for (int n = 0; n < 400; n++)
	{
		DWORD ViewPort = *(DWORD*)(0x073C81E4) + (n * 1068);

		if ((*(BYTE*)ViewPort != 0x0) && (*(BYTE*)(ViewPort + 132) == 2))
		{
			NewHealthBar = HPBar.GetNewHealthBar(*(WORD*)(ViewPort + 492));

			if (NewHealthBar == 0)
			{
				continue;
			}

			int LifePercent = NewHealthBar->Rate / 10;

			Angle.X = *(float*)(ViewPort + 16); 
			Angle.Y = *(float*)(ViewPort + 20);
			Angle.Z = *(float*)(ViewPort + 308) + *(float*)(ViewPort + 24) + 100.0f;

			GetPosFromAngle(&Angle, &PosX, &PosY);

			PosX -= (int)floor(LifeBarWidth / (double) 2.0);

			if ((CursorX >= PosX) && ((float)CursorX <= (float)PosX + LifeBarWidth) && (CursorY >= PosY - 2) && (CursorY < PosY + 6))
			{
				FixText(0, 0, "");
				wsprintf(LifeDisplay, "HP: %d0%%", LifePercent); // (char*)(ViewPort + 457) = Mobs Name
				glColor3f(1.0f, 1.0f, 1.0f);
				Text(PosX + 6, PosY - 6, LifeDisplay, 0, 0, 0);
			}

			SetBlend(true);

			glColor4f(0.0, 0.0, 0.0, 0.5);
			DrawBarForm((float)(PosX + 1), (float)(PosY + 1), LifeBarWidth + 4.0f, 5.0f, 0.0f, 0);
			GLSwitchBlend();

			glColor3f(0.2f, 0.0, 0.0);
			DrawBarForm((float)PosX, (float)PosY, LifeBarWidth + 4.0f, 5.0f, 0.0, 0);

			glColor3f(0.19607843f, 0.039215688f, 0.0);
			DrawBarForm((float)(PosX + 2), (float)(PosY + 2), LifeBarWidth, 1.0f, 0.0, 0);

			if (LifePercent > 10)
			{
				LifeProgress = 10;
			}
			else
			{
				LifeProgress = LifePercent;
			}

			for (int i = 0; i < LifeProgress; i++)
			{
				if (LifePercent >= 10) {
					glColor3f(0.01039216f, 0.939215688f, 0.0);
				}
				if (LifePercent < 10) {
					glColor3f(0.58039216f, 0.539215688f, 0.0);
				}
				if (LifePercent < 5) {
					glColor3f(0.98039216f, 0.039215688f, 0.0);
				}
				DrawBarForm((float)(i * 4 + PosX + 2), (float)(PosY + 2), 3.0, 2.0, 0.0, 0);
			}

			GLSwitch();
		}

		GLSwitch();

		glColor3f(1.0, 1.0, 1.0);
	}
}


cHealthBar HPBar;