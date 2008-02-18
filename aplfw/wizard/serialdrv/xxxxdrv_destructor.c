/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_destructor.c
 * @brief %jp{$OBJNAME_JP$ デストラクタ}%en{$OBJNAME_EN$  destructor}
 *
 * $COPYRIGHT$
 */


#include "xxxxdrv_local.h"


/** デストラクタ */
void XxxxDrv_Destructor(C_XXXXDRV *self)
{
	void	*pMem;

	/* 割込みサービスルーチン削除 */
	SysIsr_Delete(self->hIsr);
	
	/* バッファ削除 */
	pMem = StreamBuf_RefBufAddr(&self->StmBufRecv);
	StreamBuf_Delete(&self->StmBuf);
	SysMem_Free(pMem);
	
	/* 親クラスデストラクタ */
	SyncDrv_Destructor(&self->SyncDrv);
}


/* end of file */
