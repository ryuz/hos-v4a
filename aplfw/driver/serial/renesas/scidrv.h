/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.h
 * @brief %jp{SCI用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__renesas_scidrv_h__
#define __HOS__renesas_scidrv_h__


#include "scihal.h"
#include "library/stmbuf.h"
#include "system/sysapi/sysapi.h"


/* SCI用ドライバ制御部 */
typedef struct c_scidrv
{
	int           iOpenCount;
	SYSEVT_HANDLE hEvtSend;
	SYSEVT_HANDLE hEvtRecv;
	SYSMTX_HANDLE hMtxSend;
	SYSMTX_HANDLE hMtxRecv;
	C_SCIHAL      SciHal;
	C_STREAMBUF   StmBuf;
} C_SCIDRV;



#ifdef __cplusplus
extern "C" {
#endif

/* SCI用デバイスドライバ */
void SciDrv_Create(C_SCIDRV *self, void *pRegAddr, int iIntNum, long lSysClock, int iBufSize);	/**< コンストラクタ */
void SciDrv_Delete(C_SCIDRV *self);																/**< デストラクタ */
void SciDrv_Open(C_SCIDRV *self);																/**< オープン初期化 */
void SciDrv_Close(C_SCIDRV *self);																/**< クローズ */
int  SciDrv_Read(C_SCIDRV *self, void *pRecvBuf, int iSize);									/**< 書き込み */
int  SciDrv_Write(C_SCIDRV *self, const void *pData, int iSize);								/**< 読み出し */
int  SciDrv_SetSpeed(C_SCIDRV *self, long lBps);												/**< bps設定 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__renesas_scidrv_h__ */


/* end of file */
