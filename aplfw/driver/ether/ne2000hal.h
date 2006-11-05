/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ne2000hdl.h
 * @brief %jp{NE2000互換Ether用ハードウェアアクセス層}
 *
 * @version $Id: ne2000hal.h,v 1.1 2006-11-05 16:19:44 ryuz Exp $
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__ne2000hal_h__
#define __HOS__ne2000hal_h__


/* NE2000互換NIC制御ドライバクラス */
typedef struct c_ne2000hal
{
	volatile unsigned char *pubRegBase;				/* レジスタのベースアドレス */
	unsigned char          ubPhysicalAddr[6];		/* 物理アドレス */
} C_NE2000HAL;


#ifdef __cplusplus
extern "C" {
#endif

void Ne2000Hal_Create(C_NE2000HAL *self, void *pRegAddr);				/**< コンストラクタ */
void Ne2000Hal_Delete(C_NE2000HAL *self);								/**< デストラクタ */
void Ne2000Hal_Setup(C_NE2000HAL *self);								/**< 初期化 */
void Ne2000Hal_Stop(C_NE2000HAL *self);									/**< 停止 */
int  Ne2000Hal_Recv(C_NE2000HAL *self, void *pRecvBuf);					/**< %jp{パケット受信} */
int  Ne2000Hal_Send(C_NE2000HAL *self, const void *pData, int iSize);	/**< %jp{パケット送信} */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__ne2000hal_h__ */

