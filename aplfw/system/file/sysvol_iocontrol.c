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
			T_FILE_FILEINF	*pFileInf;
			const char		*pszName;
			
			pFileInf = (T_FILE_FILEINF *)pInBuf;
			
			if ( pFile->posRead == ASSOC_POS_NULL )
			{
				pFile->posRead = Assoc_GetFirst(&self->asDevice);
			}
			else
			{
				pFile->posRead = Assoc_GetNext(&self->asDevice, pFile->posRead);
			}

			if ( pFile->posRead != ASSOC_POS_NULL )
			{
				T_SYSVOL_DEVINF	*pDevInf;
				
				pDevInf = (T_SYSVOL_DEVINF *)Assoc_GetAt(&self->asDevice, pFile->posRead, &pszName);
				strcpy(pFileInf->szFileName, pszName);
				pFileInf->FileSize  = 0;
				pFileInf->Attribute = pDevInf->iAttr;				
				if ( File_GetDriverInformation(pDevInf->hDriver, pFileInf->szInformation, sizeof(pFileInf->szInformation)) != FILE_ERR_OK )
				{
					pFileInf->szInformation[0] = '\0';
				}
				pFileInf->szInformation[sizeof(pFileInf->szInformation) - 1] = '\0';
				return FILE_ERR_OK;
			}
		}
		break;
	}

	return FILE_ERR_NG;
}




/* end of file */

