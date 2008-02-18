/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_close.c
 * @brief %jp{$OBJNAME_JP$ クローズ}%en{$OBJNAME_EN$  close}
 *
 * $COPYRIGHT$
 */


#include "xxxxdrv_local.h"


/** クローズ */
void XxxxDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_XXXXDRV	*self;
	C_FILEOBJ	*pFile;
	
	/* upper cast */
	self  = (C_XXXXDRV *)pDrvObj;
	pFile = (C_FILEOBJ *)pFileObj;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		/* クローズ処理 */
	}
	
	/* ディスクリプタ削除 */
	FileObj_Delete((HANDLE)pFile);	
}


/* end of file */
