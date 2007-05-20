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



/* PHYレジスタ読み出し  */
unsigned short Lan9000Hal_PhyRegRead(C_LAN9000HAL *self, unsigned short uhAddr, unsigned short uhReg)
{
	unsigned short uhData;
	unsigned short uhMask;
	unsigned short uhSaveMgmt;
	int            i;
	
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 3);

	uhSaveMgmt = LAN9000HAL_REG_READ(self, LAN9000HAL_B3_MGMT);
	
	uhMask = LAN9000HAL_REG_READ(self, LAN9000HAL_B3_MGMT) & 0xfff0;
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask | 0x0009);
	
	/* プリアンブル */
	for ( i = 0; i < 32; i++ )
	{
		LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask | 0x0009);
		LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask | 0x000d);
	}

	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask | 0x0008);

	/* スタート */
	Lan9000Hal_Mii0(self);
	Lan9000Hal_Mii1(self);
	
	/* リード */
	Lan9000Hal_Mii1(self);
	Lan9000Hal_Mii0(self);
	
	/* アドレス出力 */
	for ( i = 0; i < 5; i++ )
	{
		if ( uhAddr & 0x10 )
		{
			Lan9000Hal_Mii1(self);
		}
		else
		{
			Lan9000Hal_Mii0(self);
		}
		uhAddr <<= 1;
	}
	
	/* レジスタ出力 */
	for ( i = 0; i < 5; i++ )
	{
		if ( uhReg & 0x10 )
		{
			Lan9000Hal_Mii1(self);
		}
		else
		{
			Lan9000Hal_Mii0(self);
		}
		uhReg <<= 1;
	}

	Lan9000Hal_MiiZ(self);
	
	/* データ読み出し */
	uhData = 0;
	for ( i = 0; i < 16; i++ )
	{
		uhData <<= 1;
		LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask);
		LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask | 0x0004);
		uhData |= ((LAN9000HAL_REG_READ(self, LAN9000HAL_B3_MGMT) & 0x0002) >> 1);
		LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask);
	}
	
	Lan9000Hal_MiiZ(self);
	
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhSaveMgmt);
	
	SysTim_Wait(1);
	
	return uhData;
}


/* endof file */
