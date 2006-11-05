/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ne2000drv.c
 * @brief %jp{NE2000互換Ether用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__ne2000drv_h__
#define __HOS__ne2000drv_h__


#include "ne2000hal.h"
#include "system/sysapi.h"


/* NE2000互換NIC制御ドライバクラス */
typedef struct c_ne2000drv
{
	int           iOpenCount;
	SYSEVT_HANDLE hEvtSend;
	SYSEVT_HANDLE hEvtRecv;
	SYSMTX_HANDLE hMtx;
	C_NE2000HAL   Ne2000Hal;
} C_NE2000DRV;


#ifdef __cplusplus
extern "C" {
#endif

void Ne2000Drv_Create(C_NE2000DRV *self, void *pRegAddr, int iIntNum);		/**< コンストラクタ */
void Ne2000Drv_Delete(C_NE2000DRV *self);									/**< デストラクタ */
void Ne2000Drv_Open(C_NE2000DRV *self);										/**< オープン初期化 */
void Ne2000Drv_Close(C_NE2000DRV *self);									/**< クローズ */
int  Ne2000Drv_Read(C_NE2000DRV *self, void *pRecvBuf, int iSize);			/**< 書き込み */
int  Ne2000Drv_Write(C_NE2000DRV *self, const void *pData, int iSize);		/**< 読み出し */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__ne2000drv_h__ */


/* end of file */
