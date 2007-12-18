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


/* 削除 */
void Vt100Drv_Delete(HANDLE hDriver)
{
	C_VT100DRV			*self;
	
	/* upper cast */
	self = (C_VT100DRV *)hDriver;

	/* 親クラスデストラクタ */
	Vt100Drv_Destructor(self);
	
	/* メモリ開放 */
	SysMem_Free(self);
}



/* end of file */
