

#include "vt100drv_local.h"


FILE_SIZE Vt100Drv_Read(C_VT100DRV *self, void *pBuf, FILE_SIZE Size)
{
	char       *pcBuf;
	FILE_SIZE  i;
	int        c;

	pcBuf = (char *)pBuf;
	
	for ( i = 0; i < Size; i++ )
	{
		c = Vt100Drv_GetCh(self);
		if ( c < 0 )
		{
			break;
		}
	}
	
	return i;
}

