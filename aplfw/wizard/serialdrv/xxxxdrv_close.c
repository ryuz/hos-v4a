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
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_XXXXDRV *)pFileObj;
	pFile = (C_SYNCFILE *)pFilePtr;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		SysInt_Disable(self->iIntNum);
		StreamBuf_Clear(&self->StmBufRecv);
	}
	
	/* ディスクリプタ削除 */
	SyncFile_Delete((HANDLE)pFile);	
}


/* end of file */
