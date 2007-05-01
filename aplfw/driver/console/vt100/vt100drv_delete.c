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


/** デストラクタ */
void Vt100Drv_Delete(C_DRVOBJ *pDrvObj)
{
	C_VT100DRV			*self;
	
	/* upper cast */
	self = (C_VT100DRV *)pDrvObj;

	/* 親クラスデストラクタ */
	DrvObj_Delete(&self->DrvObj);
}


/* end of file */
