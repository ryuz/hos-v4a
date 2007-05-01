
#include <string.h>
#include "devvol_local.h"


FILE_ERR DevVol_AddDevice(C_DEVVOL *self, const char *pszName, struct c_drvobj *pDrvObj)
{
	int i;
	
	/* テーブルの空きを検索 */
	for ( i = 0; i < DEVVOL_MAX_DEVICE; i++ )
	{
		if ( self->DevTable[i].pDrvObj == NULL )
		{
			strcpy(self->DevTable[i].szName, pszName);
			self->DevTable[i].pDrvObj = pDrvObj;
			return FILE_ERR_OK;
		}
	}
	
	return FILE_ERR_NG;	
}
