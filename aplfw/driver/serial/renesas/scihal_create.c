/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scihdl.c
 * @brief %jp{SCI用ハードウェアアクセス層}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scihal_local.h"


/** コンストラクタ */
void SciHal_Create(C_SCIHAL *self, void *pRegAddr, unsigned long ulSysClock)
{
	self->pRegBase   = pRegAddr;
	self->ulSysClock = ulSysClock;
}


/* end of file */
