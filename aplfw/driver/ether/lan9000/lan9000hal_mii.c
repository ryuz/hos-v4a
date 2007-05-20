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


/* MIIに0を書き込む */
void Lan9000Hal_Mii0(C_LAN9000HAL *self)
{
	unsigned short uhMask;
	
	uhMask = LAN9000HAL_REG_READ(self, LAN9000HAL_B3_MGMT) & 0xfff0;
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask | 0x0008);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask | 0x000c);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask | 0x0008);	
}

/* MIIに1を書き込む */
void Lan9000Hal_Mii1(C_LAN9000HAL *self)
{
	unsigned short uhMask;
	
	uhMask = LAN9000HAL_REG_READ(self, LAN9000HAL_B3_MGMT) & 0xfff0;
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask | 0x0009);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask | 0x000d);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask | 0x0009);	
}

/* MIIからビットデータを読み込む */
int Lan9000Hal_MiiIn(C_LAN9000HAL *self)
{
	unsigned short uhMask;
	int            iData;

	uhMask = LAN9000HAL_REG_READ(self, LAN9000HAL_B3_MGMT) & 0xfff0;
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask | 0x0040);
	iData = ((LAN9000HAL_REG_READ(self, LAN9000HAL_B3_MGMT) >> 1) & 1);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask);
	
	return iData;
}

/* MIIをhigh-Zをにする */
void Lan9000Hal_MiiZ(C_LAN9000HAL *self)
{
	unsigned short uhMask;

	uhMask = LAN9000HAL_REG_READ(self, LAN9000HAL_B3_MGMT) & 0xfff0;
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask | 0x000c);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B3_MGMT, uhMask);	
}




/* endof file */
