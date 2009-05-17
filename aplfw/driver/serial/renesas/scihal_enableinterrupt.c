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



/** %jp{割込み許可} */
void SciHal_EnableInterrupt(C_SCIHAL *self, unsigned char flag)
{
	unsigned char scr;

	scr   = *SCIHAL_REG_SCR(self);
	scr  &= ~(SCIHAL_INT_TIE | SCIHAL_INT_RIE| SCIHAL_INT_TEIE);
	flag &= (SCIHAL_INT_TIE | SCIHAL_INT_RIE | SCIHAL_INT_TEIE);
	scr  |= flag;
	*SCIHAL_REG_SCR(self) = scr;
}



/* end of file */
