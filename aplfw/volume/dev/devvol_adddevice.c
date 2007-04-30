
#include "devvol_local.h"


FILE_ERR DevVol_AddDevice(C_DEVVOL *self, const T_FILE_DEVINF *pDevInf)
{
	int i;
	
	/* テーブルの空きを検索 */
	for ( i = 0; i < DEVVOL_MAX_DEVICE; i++ )
	{
		if ( self->DevTable[i].pDrvObj == NULL )
		{
			self->DevTable[i] = *pDevInf;
			return FILE_ERR_OK;
		}
	}
	
	return FILE_ERR_NG;	
}
