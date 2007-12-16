/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9118drv_read.c
 * @brief %jp{SMSC LAN9118シリーズ用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9118drv_local.h"


/** %jp{受信} */
FILE_SIZE Lan9118Drv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_LAN9118DRV	*self;
	C_CHRFILE		*pFile;
	unsigned char	*pubBuf;
	unsigned long	uwData;
	int				iSize;
	FILE_SIZE		i;
	
	
	/* upper cast */
	self  = (C_LAN9118DRV *)pDrvObj;
	pFile = (C_CHRFILE *)pFileObj;
	
	pubBuf = (unsigned char *)pBuf;

	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtxRecv);
	
	/* 受信チェック */
	if ( !(Lan9118Drv_RegRead(self, LAN9118_INT_STS) & 0x00000008) )
	{
		/* ブロッキングなら受信イベントを待つ */
		SysMtx_Unlock(self->hMtxRecv);
		if ( ChrDrv_WaitReadSignal(&self->ChrDrv, pFile) != FILE_ERR_OK )
		{
			return 0;
		}
		SysMtx_Lock(self->hMtxRecv);
	}
	
	/* 受信サイズ取得 */
	uwData = Lan9118Drv_RegRead(self, LAN9118_RX_STATUS_FIFO);
	iSize  = (uwData >> 16);
	
	/* 受信エラーチェック */
	if ( uwData & 0x00008000 )
	{
		Lan9118Drv_RegWrite(self, LAN9118_RX_DP_CTL, 0x80000000);
		while ( (Lan9118Drv_RegRead(self, LAN9118_RX_DP_CTL) & 0x80000000) != 0 )
			;

		SysMtx_Unlock(self->hMtxRecv);	/* クリティカルセクションを出る */
		return 0;
	}
	
	/* データ受信 */
	for( i = 0; i < (iSize + 5) / 4; i++ )
	{
		uwData = Lan9118Drv_RegRead(self, LAN9118_RX_DATA_FIFO);
		
		*pubBuf++ = ((uwData >>  0) & 0xff);
		*pubBuf++ = ((uwData >>  8) & 0xff);
		*pubBuf++ = ((uwData >> 16) & 0xff);
		*pubBuf++ = ((uwData >> 24) & 0xff);
	}
	
	/* 受信ステータス割込み要因をクリア */
	Lan9118Drv_RegWrite(self, LAN9118_INT_STS, 0x00000008);
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtxRecv);
	
	return iSize;
}


/* end of file */
