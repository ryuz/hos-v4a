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
void XxxxDrv_Close(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr)
{
	C_XXXXDRV	*self;
	C_FILEPTR	*pFile;
	
	/* upper cast */
	self  = (C_XXXXDRV *)pFileObj;
	pFile = (C_FILEPTR *)pFilePtr;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		/* クローズ処理 */
	}
	
	/* ディスクリプタ削除 */
	FilePtr_Delete((HANDLE)pFile);	
}


/* end of file */
