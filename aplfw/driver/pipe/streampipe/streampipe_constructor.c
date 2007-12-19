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


/** コンストラクタ */
FILE_ERR StreamPipe_Constructor(C_STREAMPIPE *self, const T_DRVOBJ_METHODS *pMethods, int iBufSize)
{
	FILE_ERR	ErrCode;
	void 		*pMem;

	/* バッファ確保 */
	if ( (pMem = SysMem_Alloc(iBufSize)) == NULL )
	{
		return FILE_ERR_NG;
	}
	
	/* 親クラスコンストラクタ呼び出し */
	if ( (ErrCode = SyncDrv_Constructor(&self->SyncDrv, pMethods, SYNCDRV_FACTOR_NUM)) != FILE_ERR_OK )
	{
		SysMem_Free(pMem);
		return ErrCode;
	}

	/* メンバ変数初期化 */
	self->iOpenCount = 0;
	
	/* バッファ生成 */
	StreamBuf_Create(&self->StreamBuf, iBufSize, pMem);
	
	return FILE_ERR_OK;
}


/* end of file */
