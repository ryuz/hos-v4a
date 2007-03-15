
#include "volumeobj.h"


void VolumeObj_Create(C_VOLUMEOBJ *self, const T_VOLUMEOBJ_METHODS *pVolumeObjMethods)
{
	HandleObj_Create(&self->HandleObj, &pVolumeObjMethods->HandlObjMethods);	
}


