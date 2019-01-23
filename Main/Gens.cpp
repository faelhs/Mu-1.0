#include "Principal.h"

std::vector<GENS> GensHealthBar;

void cGens::ClearNewGensHealthBar()
{
	GensHealthBar.clear();
}

void cGens::InsertNewGensHealthBar(short Index, BYTE Rate , short gen)
{
	GENS Bar;

	Bar.Index = Index;
	Bar.Rate = Rate;
	Bar.gen = gen;
	GensHealthBar.push_back(Bar);
}

GENS* cGens::GetNewGensHealthBar(short Index)
{
	for (std::vector<GENS>::iterator it = GensHealthBar.begin(); it != GensHealthBar.end(); ++it)
	{
		if (it->Index == Index)
		{
			return &(*it);
		}
	}

	return NULL;
}

void cGens::DrawGensHealthBar()
{
	((void(*)())0x00581D70)();

	int PosX, PosY, LifeProgress;
	float LifeBarWidth = 52.0f;
	char LifeDisplay[20];
	char GenDisplay[40];
	VAngle AngleGen;

	GENS* NewGensHealthBar;

	for (int n = 0; n < 400; n++)
	{
		DWORD ViewPort = *(DWORD*)(0x073C81E4) + (n * 1068);

		if ((*(BYTE*)ViewPort != 0x0) && (*(BYTE*)(ViewPort + 132) != 3))
		{
			NewGensHealthBar = GensHPBar.GetNewGensHealthBar(*(WORD*)(ViewPort + 492));

			if (NewGensHealthBar == 0)
			{
				continue;
			}

			int LifePercent = NewGensHealthBar->Rate / 10;

			AngleGen.X = *(float*)(ViewPort + 16);
			AngleGen.Y = *(float*)(ViewPort + 20);
			AngleGen.Z = *(float*)(ViewPort + 308) + *(float*)(ViewPort + 24) + 100.0f;

			GetPosFromAngle(&AngleGen, &PosX, &PosY);

			PosX -= (int)floor(LifeBarWidth / (double) 2.0);

			if ((CursorX >= PosX) && ((float)CursorX <= (float)PosX + LifeBarWidth) && (CursorY >= PosY - 2) && (CursorY < PosY + 6))
			{
				FixText(0, 0, "");
				wsprintf(LifeDisplay, "HP: %d0%% %s", LifePercent, (char*)(ViewPort + 457)); // (char*)(ViewPort + 457) = Mobs Name
				glColor3f(1.0f, 1.0f, 1.0f);
				Text(PosX + 1, PosY + 6, LifeDisplay, 0, 0, 0);
			}
			if(NewGensHealthBar->gen == 1) {
				FixText(0, 0, "");
				wsprintf(GenDisplay, "| Facção Black |"); // (char*)(ViewPort + 457) = Mobs Name
				glColor3f(1.0f, 1.0f, 1.0f);
				Text(PosX+1, PosY - 6, GenDisplay, 0, 0, 0);
			}
			if (NewGensHealthBar->gen == 2) {
				FixText(0, 0, "");
				wsprintf(GenDisplay, "| Facção White |"); // (char*)(ViewPort + 457) = Mobs Name
				glColor3f(1.0f, 1.0f, 1.0f);
				Text(PosX+1 , PosY - 6, GenDisplay, 0, 0, 0);
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

			glColor3f(0.98039216f, 0.039215688f, 0.0);

			for (int i = 0; i < LifeProgress; i++)
			{
				DrawBarForm((float)(i * 4 + PosX + 3), (float)(PosY + 2), 15.5, 2.0, 0.0, 0);
			}

			GLSwitch();
		}

		GLSwitch();

		glColor3f(1.0, 1.0, 1.0);
	}
}

void cGens::DrawGensHealthBarOri()
{
	((void(*)())0x00581D70)();

	int PosX, PosY, LifeProgress;
	float LifeBarWidth = 38.0f;
	char LifeDisplay[20];

	VAngle AngleGen;

	GENS* NewGensHealthBar;

	for (int n = 0; n < 400; n++)
	{
		DWORD ViewPort = *(DWORD*)(0x073C81E4) + (n * 1068);

		if ((*(BYTE*)ViewPort != 0x0) && (*(BYTE*)(ViewPort + 132) == 2))
	{
			NewGensHealthBar = GensHPBar.GetNewGensHealthBar(*(WORD*)(ViewPort + 492));

			if (NewGensHealthBar == 0)
			{
				continue;
			}

			int LifePercent = NewGensHealthBar->Rate / 10;

			AngleGen.X = *(float*)(ViewPort + 16);
			AngleGen.Y = *(float*)(ViewPort + 20);
			AngleGen.Z = *(float*)(ViewPort + 308) + *(float*)(ViewPort + 24) + 100.0f;

			GetPosFromAngle(&AngleGen, &PosX, &PosY);

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

			glColor3f(0.98039216f, 0.039215688f, 0.0);

			for (int i = 0; i < LifeProgress; i++)
			{
				DrawBarForm((float)(i * 4 + PosX + 2), (float)(PosY + 2), 3.0, 2.0, 0.0, 0);
			}

			GLSwitch();
		}
		
		
		GLSwitch();

		glColor3f(1.0, 1.0, 1.0);
	}
}


cGens GensHPBar;