/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  pc16550hal.h
 * @brief %jp{16550用ハードウェアアクセス層}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__pc16550hal_h__
#define __HOS__pc16550hal_h__


#define PC16550HAL_IER_ERBFI		0x01
#define PC16550HAL_IER_ETBEI		0x02
#define PC16550HAL_IER_ELSI			0x04
#define PC16550HAL_IER_EDSSI		0x08

#define PC16550HAL_LSR_DR			0x01
#define PC16550HAL_LSR_THRE			0x20

#define PC16550HAL_IIR_RLS			0x06	/* Receive Line Status */
#define PC16550HAL_IIR_RDA			0x04	/* Receiver Data Available */
#define PC16550HAL_IIR_CTI			0x0c	/* Character Timeout Intication */
#define PC16550HAL_IIR_THRE			0x02	/* Transmitter Holding Register Empty */
#define PC16550HAL_IIR_MS			0x00	/* MODEM Status */


/* 16550用ハードウェアアクセス層 */
typedef struct c_pc16550hal
{
	volatile unsigned char *pRegBase;			/* レジスタのベースアドレス */
	unsigned long          ulBaseClock;			/* ベースクロック周波数 */
	int                    uiRegStep;			/* レジスタアドレスのシフト値 */
	int                    iTxFree;				/* 送信FIFOの空きサイズ */
} C_PC16550HAL;


#ifdef __cplusplus
extern "C" {
#endif

/* PC16550用ハードウェアアクセス層 */
void Pc16550Hal_Create(C_PC16550HAL *self, void *pRegAddr, unsigned int uiRegStep, unsigned long ulBaseClock);	/**< コンストラクタ */
void Pc16550Hal_Delete(C_PC16550HAL *self);													/**< デストラクタ */
void Pc16550Hal_Setup(C_PC16550HAL *self);													/**< %jp{PC16550の初期化} */
void Pc16550Hal_Stop(C_PC16550HAL *self);													/**< %jp{PC16550の停止} */
void Pc16550Hal_SetSpeed(C_PC16550HAL *self, unsigned long ulSpeed);
int  Pc16550Hal_SendChar(C_PC16550HAL *self, int c);										/**< %jp{1文字送信} */
int  Pc16550Hal_RecvChar(C_PC16550HAL *self);												/**< %jp{1文字受信} */
void Pc16550Hal_EnableInterrupt(C_PC16550HAL *self, unsigned char flag);					/**< %jp{割込み許可} */
int  Pc16550Hal_GetInterruptStatus(C_PC16550HAL *self);										/**< %jp{割込み状態取得} */
int  Pc16550Hal_GetStatus(C_PC16550HAL *self);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__pc16550hal_h__ */


/* end of file */
