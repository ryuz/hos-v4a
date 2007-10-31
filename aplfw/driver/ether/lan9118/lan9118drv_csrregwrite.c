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


/* write SCR register */
void Lan9118Drv_CsrRegWrite(C_LAN9118DRV *self, unsigned char ubAddr, unsigned long ulData)
{
	volatile unsigned long ulDummy;
	
	/* dummy read (wait) */
	ulDummy = Lan9118Drv_RegRead(self, LAN9118_BYTE_TEST);
	
	/* busy check */
	if ( Lan9118Drv_RegRead(self, LAN9118_MAC_CSR_CMD) & 0x80000000 )
	{
		return;
	}
	
	/* write */
	Lan9118Drv_RegWrite(self, LAN9118_MAC_CSR_DATA, ulData);
	Lan9118Drv_RegWrite(self, LAN9118_MAC_CSR_CMD,  ubAddr | 0x80000000);
		
	/* dummy read (wait) */
	ulDummy = Lan9118Drv_RegRead(self, LAN9118_BYTE_TEST);
}


/* end of file */
