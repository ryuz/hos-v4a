/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysvol.h
 * @brief %jp{システムボリューム}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "sysvol_local.h"
#include "system/sysapi/sysapi.h"



FILE_ERR SysVol_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_SYSVOL    *self;
	C_SYSVOLDIR *pDir;
	
	/* upper cast */
	self = (C_SYSVOL *)pDrvObj;
	pDir = (C_SYSVOLDIR *)pFileObj;
	
	switch ( iFunc )
	{
	case FILE_IOCTL_DIR_READ:
		{
			T_FILE_FILEINF *pFileInf;
			
			pFileInf = (T_FILE_FILEINF *)pInBuf;
			
			if ( self->DevTable[pDir->iReadPtr].pDrvObj != NULL )
			{
				strcpy(pFileInf->szFileName, self->DevTable[pDir->iReadPtr].szName);
				pFileInf->FileSize  = 0;
				pFileInf->Attribute = self->DevTable[pDir->iReadPtr].iAttr;
				pDir->iReadPtr++;
				return FILE_ERR_OK;
			}
		}
		break;
	}

	return FILE_ERR_NG;
}




/* end of file */

