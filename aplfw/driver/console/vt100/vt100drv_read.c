

#include "vt100drv_local.h"


FILE_SIZE Vt100Drv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_VT100DRV *self;
	char       *pcBuf;
	FILE_SIZE  i;
	int        c;

	/* upper cast */
	self = (C_VT100DRV *)pDrvObj;

	pcBuf = (char *)pBuf;
	
	for ( i = 0; i < Size; i++ )
	{
		c = Vt100Drv_GetCh(self);
		if ( c < 0 )
		{
			break;
		}
		*pcBuf++ = (char)c;
	}
	
	return i;
}

