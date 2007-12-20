/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv_local.h
 * @brief %jp{Renesas H8/SH用 SCIデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__scidrv_local_h__
#define __HOS__scidrv_local_h__


#include "scidrv.h"
#include "system/file/syncdrv_local.h"
#include "system/sysapi/sysapi.h"
#include "library/container/streambuf/streambuf.h"
#include "scihal.h"


/* SCI用ドライバ制御部 */
typedef struct c_scidrv
{
	C_SYNCDRV		SyncDrv;		/* 同期機能付きデバイスドライバを継承 */

	C_SCIHAL		SciHal;			/* ハードウェア抽象化クラス */

	int				iOpenCount;		/* オープンカウンタ */
	int				iIntNum;		/* 割込み番号 */
	SYSISR_HANDLE	hIsrRxErr;		/* 受信エラー割込みサービスルーチンハンドル */
	SYSISR_HANDLE	hIsrRx;			/* 受信割込みサービスルーチンハンドル */
	SYSISR_HANDLE	hIsrTx;			/* 送信割込みサービスルーチンハンドル */
	SYSISR_HANDLE	hIsrTxEnd;		/* 送信完了割込みサービスルーチンハンドル */
	
	C_STREAMBUF		StmBufRecv;		/* 受信バッファ */
} C_SCIDRV;


#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR  SciDrv_Constructor(C_SCIDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNum, unsigned long ulSysClock, int iBufSize);	/**< コンストラクタ */
void      SciDrv_Destructor(C_SCIDRV *self);																											/**< デストラクタ */

HANDLE    SciDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      SciDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  SciDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  SciDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE SciDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE SciDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  SciDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

void      SciDrv_IsrRxErr(VPARAM Param);	/* 受信エラー割込み */
void      SciDrv_IsrRx(VPARAM Param);		/* 受信割込み */
void      SciDrv_IsrTx(VPARAM Param);		/* 送信エンプティー割込み */
void      SciDrv_IsrTxEnd(VPARAM Param);	/* 送信終了割込み */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__scidrv_local_h__ */


/* end of file */
