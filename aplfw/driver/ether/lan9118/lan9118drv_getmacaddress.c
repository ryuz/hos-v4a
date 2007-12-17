/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9118drv_open.c
 * @brief %jp{SMSC LAN9118シリーズ用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9118drv_local.h"


/* MACアドレス取得 */
void Lan9118Drv_GetMacAddress(C_LAN9118DRV *self, unsigned char ubAddr[6])
{
	unsigned long ulLow;
	unsigned long ulHi;
	
	/* 読み出し */
	ulHi  = Lan9118Drv_CsrRegRead(self, 2);
	ulLow = Lan9118Drv_CsrRegRead(self, 3);
	
	/* 格納 */
	ubAddr[0] = ((ulHi  >>  8) & 0xff);
	ubAddr[1] = ((ulHi  >>  0) & 0xff);
	ubAddr[2] = ((ulLow >> 24) & 0xff);
	ubAddr[3] = ((ulLow >> 16) & 0xff);
	ubAddr[4] = ((ulLow >>  8) & 0xff);
	ubAddr[5] = ((ulLow >>  0) & 0xff);
}


/* end of file */
