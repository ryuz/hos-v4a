/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  streampipe.c
 * @brief %jp{ストリームパイプ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "streampipe_local.h"


/** デストラクタ */
void StreamPipe_Destructor(C_STREAMPIPE	*self)
{
	void	*pMem;
	
	/* バッファ削除 */
	pMem = StreamBuf_RefBufAddr(&self->StreamBuf);
	StreamBuf_Delete(&self->StreamBuf);
	SysMem_Free(pMem);
	
	/* 親クラスデストラクタ呼び出し */
	SyncDrv_Destructor(&self->SyncDrv);
}


/* end of file */
