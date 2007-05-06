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


/* %jp{SCIの停止} */
void SciHal_Stop(C_SCIHAL *self)
{
	*SCIHAL_REG_SCR(self) = 0;										/* %jp{停止} */
}


/* end of file */
