/**
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9000hal.h
 * @brief %jp{LAN9000シリーズ用ハードウェアアクセス層}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "system/sysapi/sysapi.h"
#include "lan9000hal_local.h"


/** %jp{コンストラクタ} */
void Lan9000Hal_Create(C_LAN9000HAL *self, void *pRegAddr)
{
	/* メンバ変数初期化 */
	self->pRegBase = pRegAddr;
	self->ubPhysicalAddr[0] = 0;
	self->ubPhysicalAddr[1] = 0;
	self->ubPhysicalAddr[2] = 0;
	self->ubPhysicalAddr[3] = 0;
	self->ubPhysicalAddr[4] = 0;
	self->ubPhysicalAddr[5] = 0;
}


/* end of file */

