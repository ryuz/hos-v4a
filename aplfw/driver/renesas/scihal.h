/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scihdl.h
 * @brief %jp{SCI用ハードウェアアクセス層}
 *
 * @version $Id: scihal.h,v 1.1 2006-11-05 16:11:07 ryuz Exp $
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__renesas_scihal_h__
#define __HOS__renesas_scihal_h__


#define SCIHAL_INT_TIE		0x80				/* 送信割り込み許可 */
#define SCIHAL_INT_RIE		0x40				/* 受信割り込み許可 */
#define SCIHAL_INT_TEIE		0x04				/* 受信割り込み許可 */


/* SCI用ハードウェアアクセス層 */
typedef struct c_scihal
{
	volatile unsigned char *pRegBase;			/* レジスタのベースアドレス */
	long                   lSysClock;			/* システムクロック周波数 */
} C_SCIHAL;


#ifdef __cplusplus
extern "C" {
#endif

/* SCI用ハードウェアアクセス層 */
void SciHal_Create(C_SCIHAL *self, void *pRegAddr, long lSysClock);					/**< コンストラクタ */
void SciHal_Delete(C_SCIHAL *self);													/**< デストラクタ */
void SciHal_Setup(C_SCIHAL *self, long bps);										/**< %jp{SCIの初期化} */
void SciHal_Stop(C_SCIHAL *self);													/**< %jp{SCIの停止} */
int  SciHal_SendChar(C_SCIHAL *self, int c);										/**< %jp{1文字送信} */
int  SciHal_RecvChar(C_SCIHAL *self);												/**< %jp{1文字受信} */
void SciHal_EnableInterrupt(C_SCIHAL *self, unsigned char flag);					/**< %jp{割り込み許可} */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__renesas_scihal_h__ */


/* end of file */
