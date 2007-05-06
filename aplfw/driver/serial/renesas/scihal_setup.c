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


/* %jp{SCIの初期化} */
void SciHal_Setup(C_SCIHAL *self)
{
	*SCIHAL_REG_SCR(self) = 0;
	*SCIHAL_REG_SMR(self) = 0;
	*SCIHAL_REG_SCR(self) = 0x30;														/* %jp{送受信許可} */
}


/* end of file */
