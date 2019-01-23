#include "Principal.h"

std::vector<HEALTH_BAR> HealthBar;
std::vector<QUESTS> Quests;

void cHealthBar::ClearNewHealthBar()
{
	HealthBar.clear();
}
void cHealthBar::ClearNewQuests()
{
	Quests.clear();
}
void cHealthBar::InsertNewHealthBar(short Index, BYTE Rate, short gen, short qqnt, short qcnt, short qtip)
{
	HEALTH_BAR Bar;

	Bar.Index = Index;
	Bar.Rate = Rate;
	Bar.gen = gen;
	Bar.qqtd = qqnt;
	Bar.qcnt = qcnt;
	Bar.qtip = qtip;
	HealthBar.push_back(Bar);
}
void cHealthBar::GetQuests(short Index, short qqnt, short qcnt, short qtip)
{
	QUESTS qBar;
	qBar.Index = Index;
	qBar.qqtd = qqnt;
	qBar.qcnt = qcnt;
	qBar.qtip = qtip;
	Quests.push_back(qBar);
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
QUESTS* cHealthBar::GetNewQuests(short Index)
{
	for (std::vector<QUESTS>::iterator it = Quests.begin(); it != Quests.end(); ++it)
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
	char GenDisplay[50];
	VAngle Angle;

	HEALTH_BAR* NewHealthBar;

	for (int n = 0; n < 400; n++)
	{
		DWORD ViewPort = *(DWORD*)(0x073C81E4) + (n * 1068);

		if ((*(BYTE*)ViewPort != 0x0))
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
				wsprintf(LifeDisplay, "HP: %d0%% %s", LifePercent, (char*)(ViewPort + 457)); // (char*)(ViewPort + 457) = Mobs Name
				glColor3f(1.0f, 1.0f, 1.0f);
				Text(PosX + 1, PosY + 6, LifeDisplay, 0, 0, 0);
			}
			if (NewHealthBar->gen == 1) {
				FixText(0, 0, "");
				wsprintf(GenDisplay, "| Facção Black |"); // (char*)(ViewPort + 457) = Mobs Name
				glColor3f(1.0f, 1.0f, 1.0f);
				Text(PosX + 1, PosY - 6, GenDisplay, 0, 0, 0);
			}
			if (NewHealthBar->gen == 2) {
				FixText(0, 0, "");
				wsprintf(GenDisplay, "| Facção White |"); // (char*)(ViewPort + 457) = Mobs Name
				glColor3f(1.0f, 1.0f, 1.0f);
				Text(PosX + 1, PosY - 6, GenDisplay, 0, 0, 0);
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
				DrawBarForm((float)(i * 4 + PosX + 2), (float)(PosY + 2), 4.0, 3.0, 0.0, 0);
			}

			GLSwitch();
		}

		GLSwitch();

		glColor3f(1.0, 1.0, 1.0);
	}
}
//Load logo :D
int channels = 3;
unsigned char header[54];
unsigned int dataPos;
unsigned int width, height;
unsigned int imageSize;
unsigned char* data;

GLuint cHealthBar::loadBMP_custom(const char * imagepath) {

	FILE * file = fopen(imagepath, "rb");
	if (!file) { printf("Image could not be opened\n"); return 0; }

	if (fread(header, 1, 54, file) != 54) {
		printf("Not a correct BMP file\n");
		return 0;
	}

	if (header[0] != 'B' || header[1] != 'M') {
		printf("Not a correct BMP file\n");
		return 0;
	}


	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);


	if (imageSize == 0)    imageSize = width*height*channels;
	if (dataPos == 0)      dataPos = 54;


	data = (unsigned char *)malloc(imageSize);


	fread(data, 1, imageSize, file);

	int i;
	for (i = 0; i < width * height; ++i) {
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];
		data[index] = R;
		data[index + 2] = B;
	}


	fclose(file);

}
void cHealthBar::DrawHealthBarOri()
{ 
	((void(*)())0x00581D70)();
	int PosX, PosY, LifeProgress;
	float LifeBarWidth = 37.5f;
	char LifeDisplay[20];
	char GenDisplay[50];
	char QuestDisplay[50];
	VAngle Angle;

	HEALTH_BAR* NewHealthBar;
	for (int n = 0; n < 400; n++)
	{
		DWORD ViewPort = *(DWORD*)(0x073C81E4) + (n * 1068);
		
		if ((*(BYTE*)ViewPort != 0x0) )
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
				Text(PosX + 1, PosY + 6, LifeDisplay, 0, 0, 0);
			}
				if (NewHealthBar->qtip > 0) {
					FixText(0, 0, "");
					if (NewHealthBar->qtip == 1) {
						if (NewHealthBar->qcnt < NewHealthBar->qqtd) {
							wsprintf(QuestDisplay, "|Quest| %d / %d ", (short*)NewHealthBar->qcnt, (short*)NewHealthBar->qqtd);
						}
						if (NewHealthBar->qcnt >= NewHealthBar->qqtd) {
							wsprintf(QuestDisplay, "|Quest| Completa ");
						}
					}
					if (NewHealthBar->qtip == 2) {
						if (NewHealthBar->qcnt < NewHealthBar->qqtd) {
							wsprintf(QuestDisplay, "|Loot| %d / %d ", (short*)NewHealthBar->qcnt, (short*)NewHealthBar->qqtd);
						}
						if (NewHealthBar->qcnt >= NewHealthBar->qqtd) {
							wsprintf(QuestDisplay, "|Loot| Completa ");
						}
					}
					if (NewHealthBar->qtip == 3) {
						if (NewHealthBar->qcnt < NewHealthBar->qqtd) {
							wsprintf(QuestDisplay, "|Boss| %d / %d ", (short*)NewHealthBar->qcnt, (short*)NewHealthBar->qqtd);
						}
						if (NewHealthBar->qcnt >= NewHealthBar->qqtd) {
							wsprintf(QuestDisplay, "|Boss| Completa ");
						}
					}
					glColor3f(1.0f, 1.0f, 1.0f);
					Text(PosX + 3, PosY - 10, QuestDisplay, 0, 0, 0);
				}
			
			if (NewHealthBar->gen == 1) {
				FixText(0, 0, "");
				wsprintf(GenDisplay, " |  Black  | "); // (char*)(ViewPort + 457) = Mobs Name
				glColor3f(1.0f, 1.0f, 1.0f);
				Text(PosX + 3, PosY - 10, GenDisplay, 0, 0, 0);
			}
			if (NewHealthBar->gen == 2) {
				FixText(0, 0, "");
				wsprintf(GenDisplay, " |  White  | "); // (char*)(ViewPort + 457) = Mobs Name
				glColor3f(1.0f, 1.0f, 1.0f);
				Text(PosX + 2, PosY - 10, GenDisplay, 0, 0, 0);
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