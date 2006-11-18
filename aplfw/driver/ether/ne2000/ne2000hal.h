/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ne2000hdl.h
 * @brief %jp{NE2000互換Ether用ハードウェアアクセス層}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__ne2000hal_h__
#define __HOS__ne2000hal_h__


/* NE2000互換NIC制御ドライバクラス */
typedef struct c_ne2000file
{
	volatile unsigned char *pubRegBase;			/* レジスタのベースアドレス */
	unsigned char          ubPhysicalAddr[6];	/* 物理アドレス */
} C_NE2000HAL;

#ifdef __cplusplus
extern "C" {
#endif

void    Ne2000Hal_Create(C_NE2000HAL *self, void *pRegAddr);							/**< %jp{コンストラクタ} */
void    Ne2000Hal_Delete(C_NE2000HAL *self);											/**< %jp{デストラクタ} */
void    Ne2000Hal_Setup(C_NE2000HAL *self);												/**< %jp{初期化} */
void    Ne2000Hal_Stop(C_NE2000HAL *self);												/**< %jp{停止} */
int     Ne2000Hal_Recv(C_NE2000HAL *self, void *pRecvBuf, int iSize);					/**< %jp{パケット受信} */
int     Ne2000Hal_Send(C_NE2000HAL *self, const void *pData, int iSize);				/**< %jp{パケット送信} */
#define Ne2000Hal_GetPhysicalAddr(self)	((const unsigned char *)(self->ubPhysicalAddr))	/**< %jp{物理アドレス取得} */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__ne2000hal_h__ */


/* end of file */
