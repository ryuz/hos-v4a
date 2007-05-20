/**
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9000hal.h
 * @brief %jp{LAN9000シリーズ用ハードウェアアクセス層}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "system/sysapi/sysapi.h"
#include "lan9000hal_local.h"


/** %jp{パケット受信} */
int Lan9000Hal_Recv(C_LAN9000HAL *self, void *pBuf, int iSize)
{
	unsigned short	uhData;
	unsigned short	uhStatus;
	unsigned short	uhSize;
	unsigned char	*pubBuf;
	int				i;
		
	pubBuf = (unsigned char *)pBuf;
		
	/* 受信チェック */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 2);
	if ( !(LAN9000HAL_REG_READ(self, LAN9000HAL_B2_INTERRUPT) & 0x0001) )
	{
		return 0;
	}

	/* Packet number */
	uhData = LAN9000HAL_REG_READ(self, LAN9000HAL_B2_FIFO_PORTS);
	
	/* Read the Status word and Byte count */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B2_POINTER, 0xE000);
		
	uhStatus = LAN9000HAL_REG_READ(self, LAN9000HAL_B2_DATA1);
	uhSize   = LAN9000HAL_REG_READ(self, LAN9000HAL_B2_DATA1) - 6;
	
	/* Read the packet buffer Address/Size/Data */
	for( i = 0; i < uhSize / 2; i++ )
	{
		uhData = LAN9000HAL_REG_READ(self, LAN9000HAL_B2_DATA1);
		*pubBuf++ = (unsigned char)((uhData >> 0) & 0xff);
		*pubBuf++ = (unsigned char)((uhData >> 8) & 0xff);
	}
	if ( uhSize % 2 == 1 )
	{
		uhData = LAN9000HAL_REG_READ(self, LAN9000HAL_B2_DATA1);
		*pubBuf++ = (unsigned char)((uhData >> 0) & 0xff);
	}
		
	/* メモリ開放 */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B2_MMU_COMMAND, 0x0080);
	
	/* エラーパケットは破棄 */
	if ( uhStatus & 0xac00 )
	{
		return 0;
	}
	
	/* サイズを返す */
	return (int)uhSize;
}


/* end of file */

