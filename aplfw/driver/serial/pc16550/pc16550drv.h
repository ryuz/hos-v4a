/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.h
 * @brief %jp{16550互換シリアル用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__pc16550drv_h__
#define __HOS__pc16550drv_h__


#include "pc16550hal.h"
#include "system/sysapi/sysapi.h"
#include "library/container/stmbuf/stmbuf.h"


/* PC16550用ドライバ制御部 */
typedef struct c_pc16550drv
{
	int           iOpenCount;
	int           iIntNum;
	SYSEVT_HANDLE hEvtSend;
	SYSEVT_HANDLE hEvtRecv;
	SYSMTX_HANDLE hMtxSend;
	SYSMTX_HANDLE hMtxRecv;
	C_PC16550HAL  Pc16550Hal;
	C_STREAMBUF   StmBuf;
} C_PC16550DRV;



#ifdef __cplusplus
extern "C" {
#endif

/* PC16550用デバイスドライバ */
void Pc16550Drv_Create(C_PC16550DRV *self, void *pRegAddr, int iRegStep, int iIntNum, long lSysClock, int iBufSize);	/**< コンストラクタ */
void Pc16550Drv_Delete(C_PC16550DRV *self);																/**< デストラクタ */
void Pc16550Drv_Open(C_PC16550DRV *self);																/**< オープン初期化 */
void Pc16550Drv_Close(C_PC16550DRV *self);																/**< クローズ */
int  Pc16550Drv_Read(C_PC16550DRV *self, void *pRecvBuf, int iSize);									/**< 書き込み */
int  Pc16550Drv_Write(C_PC16550DRV *self, const void *pData, int iSize);								/**< 読み出し */
int  Pc16550Drv_SetSpeed(C_PC16550DRV *self, long lBps);												/**< bps設定 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__pc16550drv_h__ */


/* end of file */
