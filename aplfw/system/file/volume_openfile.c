
#include <stdio.h>
#include "volume.h"
#include "volumeobj.h"


HANDLE Volume_OpenFile(HANDLE hVolume, const char *pszPath, int iMode)
{
	C_VOLUMEOBJ *self;
	
	self = (C_VOLUMEOBJ *)hVolume;
	
	if ( VolumeObj_GetMethods(self)->pfncOpenFile != NULL )
	{
		return VolumeObj_GetMethods(self)->pfncOpenFile(hVolume, pszPath, iMode);
	}

	return HANDLE_NULL;
}

