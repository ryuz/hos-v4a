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
	int				i;
	
	/* upper cast */
	self = (C_LAN9118DRV *)pDrvObj;
	
	/* オープン処理 */
	if ( self->iOpenCount == 0 )
	{
		/* Ready待ち */
		if ( !(Lan9118Drv_RegRead(self, LAN9118_PMT_CTRL) & 0x00000001) )
		{
			return HANDLE_NULL;
		}
		
		/* Soft Reset */
		Lan9118Drv_RegWrite(self, LAN9118_HW_CFG, 0x00000001);
		for ( i = 0; (Lan9118Drv_RegRead(self, LAN9118_HW_CFG) & 0x00000001); i++ )
		{
			if ( i >= 50 )
			{
				return HANDLE_NULL;	/* timeout */
			}
			SysTim_Wait(1);
		}
		
		/* set LED */
		Lan9118Drv_RegWrite(self, LAN9118_GPIO_CFG, 0x70000000);
		
		/* set SF */
		Lan9118Drv_RegWrite(self, LAN9118_HW_CFG, Lan9118Drv_RegRead(self, LAN9118_HW_CFG) | 0x00100000);
		
		/* MAC取得 */
		Lan9118Drv_GetMacAddress(self, self->ubMacAddr);
		
		/* PHYリセット */
		Lan9118Drv_RegWrite(self, LAN9118_PMT_CTRL, 0x00000400);
		for ( i = 0; (Lan9118Drv_RegRead(self, LAN9118_HW_CFG) & 0x00000400); i++ )
		{
			if ( i >= 50 )
			{
				return HANDLE_NULL;	/* timeout */
			}
			SysTim_Wait(1);
		}
		
		/* ゴシエーション */
		Lan9118Drv_PhyRegWrite(self, 4, 0x01e1);	/* オートネゴシエーション */
		Lan9118Drv_PhyRegWrite(self, 0, 0x1200);	/* ネゴシエーション開始 */
		SysTim_Wait(3000);
		
	/*	Lan9118Drv_PhyRegRead();	*/
		
		
		SysInt_Enable(self->iIntNum);
	}

	/* create file descriptor */
	if ( (pFile = SysMem_Alloc(sizeof(*pFile))) == NULL )
	{
		return HANDLE_NULL;
	}
	ChrFile_Create(pFile, &self->SyncDrv, NULL);
	
	self->iOpenCount++;
	
	
	return (HANDLE)pFile;
}


/* end of file */
