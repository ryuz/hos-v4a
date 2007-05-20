/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9000hal.h
 * @brief %jp{LAN9000シリーズ用ハードウェアアクセス層}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__lan9000hal_h__
#define __HOS__lan9000hal_h__



#define LAN9000HAL_ISTATUS_RCVINT			0x0001
#define LAN9000HAL_ISTATUS_TXINT			0x0002
#define LAN9000HAL_ISTATUS_TX_EMPTYINT		0x0004
#define LAN9000HAL_ISTATUS_ALLOCINT			0x0008
#define LAN9000HAL_ISTATUS_RX_OVRNINT		0x0010
#define LAN9000HAL_ISTATUS_EPHINT			0x0020
#define LAN9000HAL_ISTATUS_ERCVINT			0x0040
#define LAN9000HAL_ISTATUS_MDINT			0x0080

#define LAN9000HAL_IMASK_RCVINT				0x0100
#define LAN9000HAL_IMASK_TXINT				0x0200
#define LAN9000HAL_IMASK_TX_EMPTYINT		0x0400
#define LAN9000HAL_IMASK_ALLOCINT			0x0800
#define LAN9000HAL_IMASK_RX_OVRNINT			0x1000
#define LAN9000HAL_IMASK_EPHINT				0x2000
#define LAN9000HAL_IMASK_ERCVINT			0x4000
#define LAN9000HAL_IMASK_MDINT				0x8000


/* ハードウェアアクセス層 */
typedef struct c_lan9000hal
{
	void			*pRegBase;			/* レジスタのベースアドレス */
	unsigned char	ubPhysicalAddr[6];	/* 物理アドレス */
} C_LAN9000HAL;


#ifdef __cplusplus
extern "C" {
#endif

void           Lan9000Hal_Create(C_LAN9000HAL *self, void *pRegAddr);								/**< %jp{コンストラクタ} */
void           Lan9000Hal_Delete(C_LAN9000HAL *self);												/**< %jp{デストラクタ} */
int            Lan9000Hal_Setup(C_LAN9000HAL *self);												/**< %jp{初期化} */
void           Lan9000Hal_Stop(C_LAN9000HAL *self);													/**< %jp{停止} */
int            Lan9000Hal_Recv(C_LAN9000HAL *self, void *pBuf, int iSize);							/**< %jp{パケット受信} */
int            Lan9000Hal_Send(C_LAN9000HAL *self, const void *pData, int iSize);					/**< %jp{パケット送信} */
void           Lan9000Hal_SetInterruptMask(C_LAN9000HAL *self, unsigned short uhIntMask);			/**< %jp{割込みマスク設定} */
unsigned short Lan9000Hal_GetInterruptStatus(C_LAN9000HAL *self);									/**< %jp{割込み状態取得} */
void           Lan9000Hal_GetPhysicalAddr(C_LAN9000HAL *self, unsigned char ubPhysicalAddr[6]);		/**< %jp{物理アドレス取得} */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__lan9000hal_h__ */


/* end of file */
