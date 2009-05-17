/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scihdl.h
 * @brief %jp{SCI用ハードウェアアクセス層}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__renesas__scihal_h__
#define __HOS__renesas__scihal_h__


#define SCIHAL_INT_TIE		0x80				/* 送信割込み許可 */
#define SCIHAL_INT_RIE		0x40				/* 受信割込み許可 */
#define SCIHAL_INT_TEIE		0x04				/* 受信割込み許可 */


/* SCI用ハードウェアアクセス層 */
typedef struct c_scihal
{
	volatile unsigned char	*pRegBase;			/* レジスタのベースアドレス */
	unsigned long			ulSysClock;			/* システムクロック周波数 */
} C_SCIHAL;


#ifdef __cplusplus
extern "C" {
#endif

/* SCI用ハードウェアアクセス層 */
void SciHal_Create(C_SCIHAL *self, void *pRegAddr, unsigned long ulSysClock);	/**< コンストラクタ */
void SciHal_Delete(C_SCIHAL *self);												/**< デストラクタ */
void SciHal_Setup(C_SCIHAL *self);												/**< %jp{SCIの初期化} */
void SciHal_SetSpeed(C_SCIHAL *self, unsigned long ulSpeed);					/**< %jp{SCIの速度設定} */
void SciHal_Stop(C_SCIHAL *self);												/**< %jp{SCIの停止} */
int  SciHal_SendChar(C_SCIHAL *self, int c);									/**< %jp{1文字送信} */
int  SciHal_RecvChar(C_SCIHAL *self);											/**< %jp{1文字受信} */
void SciHal_EnableInterrupt(C_SCIHAL *self, unsigned char flag);				/**< %jp{割込み許可} */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__renesas__scihal_h__ */


/* end of file */
