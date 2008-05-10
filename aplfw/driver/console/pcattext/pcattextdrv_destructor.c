/** 
 * Hyper Operating System  Application Framework
 *
 * @file  pcattextdrv_destructor.c
 * @brief %jp{PC/AT text mode driver デストラクタ}%en{PC/AT text mode driver  destructor}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pcattextdrv_local.h"


/** デストラクタ */
void PcatTextDrv_Destructor(C_PCATTEXTDRV *self)
{
	/* 親クラスデストラクタ */
	DrvObj_Destructor(&self->DrvObj);
}


/* end of file */
