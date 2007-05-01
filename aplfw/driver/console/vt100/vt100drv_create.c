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


const T_DRVOBJ_METHODS  Vt100Drv_Methods = 
	{
		Vt100Drv_Delete,
		Vt100Drv_Open,
		Vt100Drv_Close,
		Vt100Drv_IoControl,
		Vt100Drv_Seek,
		Vt100Drv_Read,
		Vt100Drv_Write,
		Vt100Drv_Flush,
	};



/**< コンストラクタ */
void Vt100Drv_Create(C_VT100DRV *self, HANDLE hTty)
{
	/* 親クラスコンストラクタ */
	DrvObj_Create(&self->DrvObj, &Vt100Drv_Methods);

	self->hTty = hTty;
}


/* end of file */
