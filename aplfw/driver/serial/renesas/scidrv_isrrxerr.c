/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{Renesas H8/SH用 SCIデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"



/* 受信エラー割込み */
void SciDrv_IsrRxErr(VPARAM Param)
{
	SciDrv_IsrRx(Param);
}


/* end of file */
