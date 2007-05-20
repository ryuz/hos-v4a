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


/**< %jp{物理アドレス取得} */
void Lan9000Hal_GetPhysicalAddr(C_LAN9000HAL *self, unsigned char ubPhysicalAddr[6])
{
	unsigned short uhData;

	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 1);

	uhData = LAN9000HAL_REG_READ(self, LAN9000HAL_B1_IA0_1);
	ubPhysicalAddr[0] = (unsigned char)((uhData >> 0) & 0xff);
	ubPhysicalAddr[1] = (unsigned char)((uhData >> 8) & 0xff);
	
	uhData = LAN9000HAL_REG_READ(self, LAN9000HAL_B1_IA2_3);
	ubPhysicalAddr[2] = (unsigned char)((uhData >> 0) & 0xff);
	ubPhysicalAddr[3] = (unsigned char)((uhData >> 8) & 0xff);

	uhData = LAN9000HAL_REG_READ(self, LAN9000HAL_B1_IA4_5);
	ubPhysicalAddr[4] = (unsigned char)((uhData >> 0) & 0xff);
	ubPhysicalAddr[5] = (unsigned char)((uhData >> 8) & 0xff);
}


/* end of file */
