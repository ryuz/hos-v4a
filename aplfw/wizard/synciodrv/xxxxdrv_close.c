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
	C_XXXXFILE	*pFile;
	
	/* upper cast */
	self  = (C_XXXXDRV *)pDrvObj;
	pFile = (C_XXXXFILE *)pFileObj;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		SysInt_Disable(self->iIntNum);
	}
	
	/* ディスクリプタ削除 */
	SyncFile_Delete((HANDLE)pFile);	
}


/* end of file */
