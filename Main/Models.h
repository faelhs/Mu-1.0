#pragma once

#define FuckAdder 505
#define ITEM_IN_MAIN(x,y) ((x)*32+(y)+FuckAdder)

#define LoadModel_Offset	 0x005E43D5
#define BMDModelLoad	     0x005E10E0
#define ReturnOffset	     0x005E43EB
#define OpenTexture		     0x005E0CA0

void ModelsLoad();
void PatchMainForLoadModels();
