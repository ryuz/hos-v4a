/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  vt100drv_create.c
 * @brief %jp{VT100 ターミナルドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "vt100drv_local.h"
#include "system/sysapi/sysapi.h"



/**< コンストラクタ */
void Vt100Drv_Constructor(C_VT100DRV *self, const T_DRVOBJ_METHODS *pMethods, HANDLE hTty)
{
	/* 親クラスコンストラクタ */
	DrvObj_Constructor(&self->DrvObj, pMethods);
	
	/* メンバ変数初期化 */
	self->hTty      = hTty;
	self->iEscNum   = 0;
	self->iEscState = VT100DRV_ESC_IDLE;
}


/* end of file */
