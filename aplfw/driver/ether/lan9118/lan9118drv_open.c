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


/** オープン */
HANDLE Lan9118Drv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_LAN9118DRV	*self;
	C_CHRFILE		*pFile;
	
	/* upper cast */
	self = (C_LAN9118DRV *)pDrvObj;
	
	/* オープン処理 */
	if ( self->iOpenCount == 0 )
	{
		/* Ready待ち */
		if ( !(LAN9118_REG_READ(self, LAN9118_PMT_CTRL) & 0x00000001) )
		{
			return HANDLE_NULL;
		}
		
		/* Soft Reset */
		LAN9118_REG_WRITE(self, LAN9118_HW_CFG, 0x00000001);
		while ( (LAN9118_REG_READ(self, LAN9118_HW_CFG) & 0x00000001) )
		{
			SysTim_Wait(1);
		} 
		
		/* set LED */
		LAN9118_REG_WRITE(self, LAN9118_GPIO_CFG, 0x70000000);
		
		/* set SF */
		LAN9118_REG_WRITE(self, LAN9118_HW_CFG, LAN9118_REG_READ(self, LAN9118_HW_CFG) | 0x00100000);
		
		
		
		
		SysInt_Enable(self->iIntNum);
	}

	/* create file descriptor */
	if ( (pFile = SysMem_Alloc(sizeof(*pFile))) == NULL )
	{
		return HANDLE_NULL;
	}
	ChrFile_Create(pFile, pDrvObj, NULL);
	
	self->iOpenCount++;
	
	
	return (HANDLE)pFile;
}


/* end of file */
