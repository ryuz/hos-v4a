/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  jellyi2cdrv_constructor.h
 * @brief %jp{Jelly I2C デバイスドライバ}
 *
 * Copyright (C) 2006-2010 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "jellyi2cdrv_local.h"


/** コンストラクタ */
FILE_ERR JellyI2cDrv_Constructor(C_JELLYI2CDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, unsigned long ulBaseClock)
{
	FILE_ERR	ErrCode;
	
	/* 親クラスコンストラクタ呼び出し */
	if ( (ErrCode = SyncDrv_Constructor(&self->SyncDrv, pMethods, SYNCDRV_FACTOR_NUM)) != FILE_ERR_OK )
	{
		return ErrCode;
	}
	
	/* メンバ変数初期化 */
	self->pRegBase    = pRegBase;
	self->ulBaseClock = ulBaseClock;
	self->iOpenCount  = 0;
	
	return FILE_ERR_OK;
}


/* end of file */
