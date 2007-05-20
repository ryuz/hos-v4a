/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9000hdl_create.c
 * @brief %jp{LAN9000用ハードウェアアクセス層}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9000hal_local.h"



/** %jp{割り込み許可} */
void Lan9000Hal_EnableInterrupt(C_LAN9000HAL *self, unsigned char flag)
{
	LAN9000HAL_WRITE_IER(self, flag);
}



/* end of file */
