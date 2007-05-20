/**
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9000hal.h
 * @brief %jp{LAN9000シリーズ用ハードウェアアクセス層}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9000hal_local.h"


/**< %jp{割込みマスク設定} */
void Lan9000Hal_SetInterruptMask(C_LAN9000HAL *self, unsigned short uhIntMask)
{
	unsigned short uhOldBank;
	
	/* バンクを保存 */
	uhOldBank = LAN9000HAL_REG_READ(self, LAN9000HAL_BANK);
	
	/* 割込みマスク設定 */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 2);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B2_INTERRUPT, (uhIntMask & 0xff00));
	
	/* バンクを復帰 */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, uhOldBank);
}


/* end of file */
