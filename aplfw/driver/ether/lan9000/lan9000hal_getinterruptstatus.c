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


/**< %jp{割込み状態取得} */
unsigned short Lan9000Hal_GetInterruptStatus(C_LAN9000HAL *self)
{
	unsigned short uhOldBank;
	unsigned short uhStatus;
	
	/* バンクを保存 */
	uhOldBank = LAN9000HAL_REG_READ(self, LAN9000HAL_BANK);
	
	/* 割込み状態取得 */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 2);
	uhStatus = LAN9000HAL_REG_READ(self, LAN9000HAL_B2_INTERRUPT);
	
	/* バンクを復帰 */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, uhOldBank);
	
	return uhStatus;
}


/* end of file */
