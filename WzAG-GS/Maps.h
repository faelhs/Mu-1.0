#ifndef _MAPS_H
#define _MAPS_H

void ReadyNewMaps();

#define MAPLIMIT 36

#define MAP_BASE 0x9561278 //0x7342000 
#define MAP_SIZE 0x50698
#define DIR_BASE 0x9FBEC10

typedef void(*pMapItemInit)(void);
extern pMapItemInit MapItemInit;
typedef void(*pLoadMapAttr)(const char*, int);
extern pLoadMapAttr LoadMapAttr;
typedef const char*(*pGetNewPath)(const char*, int);
extern pGetNewPath GetNewPath;

void LoadMapAttribute(unsigned int index, const char *name);
void LoadMaps();
void MapsFix();

#endif //~MAPS_H