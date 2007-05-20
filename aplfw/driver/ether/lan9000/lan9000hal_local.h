/**
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9000hal.h
 * @brief %jp{LAN9000シリーズ用ハードウェアアクセス層}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__lan9000hal_local_h__
#define __HOS__lan9000hal_local_h__


#include "lan9000hal.h"


/* レジスタアドレスの算出 */
#define LAN9000HAL_REG_ADDR(self, offset)			((volatile unsigned short *)((char *)(self)->pRegBase + ((offset))))

/* レジスタ読み書き */
#define LAN9000HAL_REG_WRITE(self, offset, data)	do { *LAN9000HAL_REG_ADDR((self), (offset)) = (unsigned short)(data); } while (0)
#define LAN9000HAL_REG_READ(self, offset)			(*LAN9000HAL_REG_ADDR((self), (offset)))


/* レジスタ */
#define LAN9000HAL_BANK				0x0e 	/* Bank */

#define LAN9000HAL_B0_TCR			0x00 	/* Transmit Control Register */
#define LAN9000HAL_B0_EPH_STATUS	0x02 	/* EPH Status Register */
#define LAN9000HAL_B0_RCR			0x04 	/* Receive Control Register */
#define LAN9000HAL_B0_COUNTER		0x06 	/* Counter Register */
#define LAN9000HAL_B0_MIR			0x08 	/* Memory Information Register */
#define LAN9000HAL_B0_RPCR			0x0a

#define LAN9000HAL_B1_CONFIG		0x00	/* Configuration Register */
#define LAN9000HAL_B1_BASE			0x02 	/* Base Address Register */
#define LAN9000HAL_B1_IA0_1			0x04 	/* Individual Register 0-1 */
#define LAN9000HAL_B1_IA2_3			0x06 	/* Individual Register 2-3 */
#define LAN9000HAL_B1_IA4_5			0x08 	/* Individual Register 4-5 */
#define LAN9000HAL_B1_GENERAL		0x0a 	/* General Address Register */
#define LAN9000HAL_B1_CONTROL		0x0c 	/* Control Register */

#define LAN9000HAL_B2_MMU_COMMAND	0x00 	/* MMU Command Register / Auto TX Start Register */
#define LAN9000HAL_B2_PNR			0x02 	/* Packet Number Register / Allocation Result Register */
#define LAN9000HAL_B2_FIFO_PORTS	0x04 	/* FIFO Ports Register */
#define LAN9000HAL_B2_POINTER		0x06 	/* Pointer Register */
#define LAN9000HAL_B2_DATA1			0x08 	/* Data High Register */
#define LAN9000HAL_B2_DATA2			0x0a 	/* Data Low Register */
#define LAN9000HAL_B2_INTERRUPT		0x0c 	/* Interrupt Status Register */

#define LAN9000HAL_B3_MT0_1			0x00
#define LAN9000HAL_B3_MT2_3			0x02
#define LAN9000HAL_B3_MT4_5			0x04
#define LAN9000HAL_B3_MT6_7			0x06
#define LAN9000HAL_B3_MGMT			0x08
#define LAN9000HAL_B3_REVISION		0x0a
#define LAN9000HAL_B3_ERCV			0x0c



#ifdef __cplusplus
extern "C" {
#endif

void           Lan9000Hal_Mii0(C_LAN9000HAL *self);																				/* MIIに0を書き込む */
void           Lan9000Hal_Mii1(C_LAN9000HAL *self);																				/* MIIに1を書き込む */
int            Lan9000Hal_MiiIn(C_LAN9000HAL *self);																			/* MIIからビットデータを読み込む */
void           Lan9000Hal_MiiZ(C_LAN9000HAL *self);																				/* MIIをhigh-Zをにする */
void           Lan9000Hal_PhyRegWrite(C_LAN9000HAL *self, unsigned short uhAddr, unsigned short uhReg, unsigned short uhData);	/* PHYレジスタ書込み  */
unsigned short Lan9000Hal_PhyRegRead(C_LAN9000HAL *self, unsigned short uhAddr, unsigned short uhReg);							/* PHYレジスタ読み出し  */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__LAN9000hal_local_h__ */


/* end of file */
