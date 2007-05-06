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


/* %jp{SCIの速度設定} */
void SciHal_SetSpeed(C_SCIHAL *self, unsigned long ulSpeed)
{
	*SCIHAL_REG_BRR(self) = (self->ulSysClock + (16 * ulSpeed)) / (32 * ulSpeed) - 1;	/* %jp{ボーレート設定} */
}


/* end of file */
