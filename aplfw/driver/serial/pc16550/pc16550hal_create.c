/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  pc16550hdl_create.c
 * @brief %jp{PC16550用ハードウェアアクセス層}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pc16550hal_local.h"


/** コンストラクタ */
void Pc16550Hal_Create(C_PC16550HAL *self, void *pRegAddr, unsigned int uiRegStep, unsigned long ulBaseClock)
{
	self->pRegBase    = pRegAddr;
	self->uiRegStep   = uiRegStep;
	self->ulBaseClock = ulBaseClock;
}


/* end of file */
