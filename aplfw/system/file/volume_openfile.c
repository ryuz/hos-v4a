
#include <stdio.h>
#include "volume.h"
#include "volumeobj.h"


HANDLE Volume_OpenFile(HANDLE hVolume, const char *pszPath, int iMode)
{
	C_VOLUMEOBJ *self;
	
	self = (C_VOLUMEOBJ *)hVolume;
	
	if ( self->pMethods->pfncOpenFile == NULL )
	{
		return HANDLE_NULL;
	}

	return self->pMethods->pfncOpenFile(hVolume, pszPath, iMode);
}

