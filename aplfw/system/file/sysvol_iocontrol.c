/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysvol.h
 * @brief %jp{システムボリューム}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "sysvol_local.h"
#include "system/sysapi/sysapi.h"



FILE_ERR SysVol_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_SYSVOL		*self;
	C_SYSVOLFILE	*pFile;
	
	/* upper cast */
	self  = (C_SYSVOL *)pDrvObj;
	pFile = (C_SYSVOLFILE *)pFileObj;
	
	switch ( iFunc )
	{
	case FILE_IOCTL_DIR_READ:
		{
			T_FILE_FILEINF *pFileInf;
			
			pFileInf = (T_FILE_FILEINF *)pInBuf;
			
			if ( self->DevTable[pFile->iReadPtr].hDriver != HANDLE_NULL )
			{
				strcpy(pFileInf->szFileName, self->DevTable[pFile->iReadPtr].szName);
				pFileInf->FileSize  = 0;
				pFileInf->Attribute = self->DevTable[pFile->iReadPtr].iAttr;
				pFile->iReadPtr++;
				return FILE_ERR_OK;
			}
		}
		break;
	}

	return FILE_ERR_NG;
}




/* end of file */

