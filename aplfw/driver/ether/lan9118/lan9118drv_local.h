/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9118drv_local.h
 * @brief %jp{SMSC LAN9118シリーズ用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__lan9118drv_local_h__
#define __HOS__lan9118drv_local_h__


#include "lan9118drv.h"


#define LAN9118_ID_REV			0x50
#define LAN9118_IRQ_CFG			0x54
#define LAN9118_INT_STS			0x58
#define LAN9118_INT_EN			0x5c
#define LAN9118_BYTE_TEST		0x64
#define LAN9118_FIFO_INT		0x68
#define LAN9118_RX_CFG			0x6c
#define LAN9118_TX_CFG			0x70
#define LAN9118_HW_CFG			0x74
#define LAN9118_RX_DP_CTL		0x78
#define LAN9118_RX_FIFO_INF		0x7c
#define LAN9118_TX_FIFO_INF		0x80
#define LAN9118_PMT_CTRL		0x84
#define LAN9118_GPIO_CFG		0x88
#define LAN9118_GPT_CFG			0x8c
#define LAN9118_GPT_CNT			0x90
#define LAN9118_WORD_SWAP		0x98
#define LAN9118_FREE_RUN		0x9c
#define LAN9118_RX_DROP			0xa0
#define LAN9118_MAC_CSR_CMD		0xa4
#define LAN9118_MAC_CSR_DATA	0xa8
#define LAN9118_AFC_CFG			0xac
#define LAN9118_E2P_CMD			0xb0
#define LAN9118_E2P_DATA		0xb4

#define LAN9118_CSR_MAC_CR		0x01
#define LAN9118_CSR_ADDRH		0x02
#define LAN9118_CSR_ADDRL		0x03
#define LAN9118_CSR_HASHH		0x04
#define LAN9118_CSR_HASHL		0x05
#define LAN9118_CSR_MII_ACC		0x06
#define LAN9118_CSR_MII_DATA	0x07
#define LAN9118_CSR_FLOW		0x08
#define LAN9118_CSR_VLAN1		0x09
#define LAN9118_CSR_VLAN2		0x0a
#define LAN9118_CSR_WUFF		0x0b
#define LAN9118_CSR_WUCSR		0x0c



#ifdef __cplusplus
extern "C" {
#endif

HANDLE         Lan9118Drv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void           Lan9118Drv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR       Lan9118Drv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS       Lan9118Drv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE      Lan9118Drv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE      Lan9118Drv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR       Lan9118Drv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

void           Lan9118Drv_Isr(VPARAM Param);			/* 割込み処理 */

#define        Lan9118Drv_RegWrite(self, offset, val)	do { *(unsigned long *)((char *)(self)->pRegBase + (offset)) = (val); } while(0)
#define        Lan9118Drv_RegRead(self, offset)			(*((unsigned long *)((char *)(self)->pRegBase + (offset))))
void           Lan9118Drv_CsrRegWrite(C_LAN9118DRV *self, unsigned char ubAddr, unsigned long uwData);
unsigned long  Lan9118Drv_CsrRegRead(C_LAN9118DRV *self, unsigned char ubAddr);
void           Lan9118Drv_PhyRegWrite(C_LAN9118DRV *self, unsigned char ubAddr, unsigned short uhData);
unsigned short Lan9118Drv_PhyRegRead(C_LAN9118DRV *self, unsigned char ubAddr);

void           Lan9118Drv_GetMacAddress(C_LAN9118DRV *self, unsigned char ubAddr[6]);		/* MACアドレス取得 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__armuartdrv_h__ */


/* end of file */
