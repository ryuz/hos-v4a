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


/** %jp{パケット送信} */
int Lan9000Hal_Send(C_LAN9000HAL *self, const void *pData, int iSize)
{
	unsigned short uhData;
	unsigned char  *pubData;
	int            i;
	
	pubData = (unsigned char *)pData;
	
	
	/* バッファ割り当て未完了ならリターン */
	if ( !(LAN9000HAL_REG_READ(self, LAN9000HAL_B2_INTERRUPT) & LAN9000HAL_ISTATUS_ALLOCINT) )
	{
		return 0;
	}
		
	/* Write allocated packet number, setup the write pointer */
	uhData = LAN9000HAL_REG_READ(self, LAN9000HAL_B2_PNR) & 0x3f;
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B2_PNR, uhData << 8);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B2_POINTER, 0x4000);
	
	/* Write the packet buffer Status word/Byte count (Status + Byte count + pktsize + Control) */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B2_DATA1, 0x0000);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B2_DATA1, ((iSize+6) & ~1));

	/* Write the packet buffer Address/Size/Data */
	for ( i= 0; i < iSize / 2; i++ )
	{
		uhData  = *pubData++;
		uhData |= (*pubData++) << 8;
		LAN9000HAL_REG_WRITE(self, LAN9000HAL_B2_DATA1, uhData);
	}
	if ( iSize % 2 == 1 )
	{
		uhData  = *pubData;
		uhData |= 0x3000;
	}
	else
	{
		uhData = 0x1000;
	}
	
	/* Write Control word (Even data, No CRC) */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B2_DATA1, uhData);
	
	/* Queue the packet */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 2);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B2_MMU_COMMAND, 0x00c0);

	/* 送信バッファ割り当て要求 */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 2);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B2_MMU_COMMAND, 0x0020);
	
	return iSize;
}


/* end of file */

