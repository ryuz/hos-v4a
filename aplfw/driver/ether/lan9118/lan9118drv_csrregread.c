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


/* read SCR register */
unsigned long Lan9118Drv_CsrRegRead(C_LAN9118DRV *self, unsigned char ubAddr)
{
	volatile unsigned long ulDummy;
	
	/* dummy read (wait) */
	ulDummy = Lan9118Drv_RegRead(self, LAN9118_BYTE_TEST);
	
	/* busy check */
	if ( Lan9118Drv_RegRead(self, LAN9118_MAC_CSR_CMD) & 0x80000000 )
	{
		return 0;
	}
	
	/* read command */
	Lan9118Drv_RegWrite(self, LAN9118_MAC_CSR_CMD,  ubAddr | 0xc0000000);
	
	/* dummy read (wait) */
	ulDummy = Lan9118Drv_RegRead(self, LAN9118_BYTE_TEST);

	/* busy check */
	if ( Lan9118Drv_RegRead(self, LAN9118_MAC_CSR_CMD) & 0x80000000 )
	{
		return 0;
	}

	/* read */	
	return Lan9118Drv_RegRead(self, LAN9118_MAC_CSR_DATA);
}


/* end of file */
