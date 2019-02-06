#ifndef ADDONS_MAIN_TRANCE
#define ADDONS_MAIN_TRANCE
#define _WIN32_WINNTS 0x501
#define WIN32_LEAN_AND_MEAN	
#define _MAX_PATH1 65535
void LoadAddons();
static HINSTANCE Instance;
unsigned int GetCRC(char * filename);
void GetCamCoords(double* x_cam, double* y_cam, double* z_cam);
void InitDisplay();
void ChangeSky();
bool CanDrawSky();
void Display();
void DisplayText(char * text);
bool FileExists(char * name);
void Fix_RotateDmg();
#endif