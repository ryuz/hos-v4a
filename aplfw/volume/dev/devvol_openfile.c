#include <stdio.h>
#include <string.h>
#include "devvol_local.h"
#include "system/sysapi/sysapi.h"
#include "system/file/drvobj.h"


/* ファイルを開く */
HANDLE DevVol_OpenFile(HANDLE hVolume, const char *pszPath, int iMode)
{
	C_DEVVOL *self;
	int      i;

	self = (C_DEVVOL *)hVolume;
	
	
	/* 先頭の'/'を読み飛ばし */
	pszPath++;
	
	/* デバイスを検索 */
	for ( i = 0; i < DEVVOL_MAX_DEVICE; i++ )
	{
		if ( strcmp(pszPath, self->DevTable[i].szName) == 0 )
		{
			break;
		}
	}
	if ( i >= DEVVOL_MAX_DEVICE )
	{
		return HANDLE_NULL;
	}
	
	return DrvObj_vOpen(self->DevTable[i].pDrvObj, pszPath, iMode);
}


/* end of file */

