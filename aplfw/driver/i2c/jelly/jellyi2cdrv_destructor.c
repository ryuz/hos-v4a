/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  jellyi2cdrv_destructor.c
 * @brief %jp{Jelly I2Cデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "jellyi2cdrv_local.h"


/** デストラクタ */
void JellyI2cDrv_Destructor(C_JELLYI2CDRV *self)
{
	/* 親クラスデストラクタ */
	SyncDrv_Destructor(&self->SyncDrv);
}


/* end of file */
