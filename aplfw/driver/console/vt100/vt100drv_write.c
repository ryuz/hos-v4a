

#include "vt100drv_local.h"


FILE_SIZE Vt100Drv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_VT100DRV	*self;
	const char	*pcBuf;
	FILE_SIZE	i;
	
	/* upper cast */
	self = (C_VT100DRV *)pDrvObj;
	
	/* '\n' -> '\r\n' へ変換 */
	pcBuf = (const char *)pData;
	for ( i = 0; i < Size; i++ )
	{
		if ( pcBuf[i] == '\n' )
		{
			File_Write(self->hTty, "\r\n", 2);
		}
		else
		{
			File_Write(self->hTty, &pcBuf[i], 1);
		}
	}
	
	return i;
}

