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



/** 初期化 */
int Lan9000Hal_Setup(C_LAN9000HAL *self)
{
	int iTimeOut;
	
	/* リセット処理 */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 0);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B0_RCR, 0x8000);

	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 1);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B1_CONFIG, LAN9000HAL_REG_READ(self, LAN9000HAL_B1_CONFIG) | 0x8000);
	SysTim_Wait(50);

	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 0);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B0_RCR,  0x0000);
	SysTim_Wait(50);

	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 2);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B2_MMU_COMMAND,  0x0040);
	
	
	/* ANEG処理 */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 0);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B0_RPCR, 0x0800);
	SysTim_Wait(100);
	
	Lan9000Hal_PhyRegWrite(self, 0, 0, 0x8000);
	SysTim_Wait(50);

	Lan9000Hal_PhyRegWrite(self, 0, 0, 0x3000);
	SysTim_Wait(1500);
	
	iTimeOut = 0;
	while ( !(Lan9000Hal_PhyRegRead(self, 0, 1) & 0x0020) )
	{
		if ( iTimeOut++ > 200 )
		{
			return (-1);
		}
		SysTim_Wait(10);
	}
	
	/* Configure the Transmit and Receive registers to allow external loopback */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 0);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B0_RPCR, 0x0800);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B0_TCR, 0x0881);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B0_RCR, 0x0302);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 1);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B1_CONFIG, LAN9000HAL_REG_READ(self, LAN9000HAL_B1_CONFIG) | 0x8000);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B1_CONTROL,  0x5a10);	
	SysTim_Wait(1);
	
	/* 送信バッファ割り当て要求 */
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_BANK, 2);
	LAN9000HAL_REG_WRITE(self, LAN9000HAL_B2_MMU_COMMAND, 0x0020);
	
	return 0;
}



/* endof file */
