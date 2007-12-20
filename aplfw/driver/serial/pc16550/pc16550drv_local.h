/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  pc16550drv_local.h
 * @brief %jp{16550互換シリアル用デバイスドライバ ローカルヘッダファイル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__pc16550drv_local_h__
#define __HOS__pc16550drv_local_h__



#include "pc16550drv.h"
#include "system/file/syncdrv_local.h"
#include "system/file/syncfile.h"
#include "library/container/streambuf/streambuf.h"
#include "system/sysapi/sysapi.h"
#include "pc16550hal.h"



/* PC16550用ドライバ制御部 */
typedef struct c_pc16550drv
{
	C_SYNCDRV		SyncDrv;		/* 同期機能付きデバイスドライバを継承 */

	C_PC16550HAL	Pc16550Hal;		/* ハードウェア制御クラス */
	int				iOpenCount;		/* オープンカウンタ */
	int				iIntNum;		/* 割込み番号 */
	SYSISR_HANDLE	hIsr;			/* 割込みサービスルーチンハンドル */

	C_STREAMBUF		StmBufRecv;		/* 受信バッファ */
} C_PC16550DRV;


#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR  Pc16550Drv_Constructor(C_PC16550DRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegAddr, unsigned int uiRegStep, int iIntNum, long lSysClock, int iBufSize);	/**< コンストラクタ */
void      Pc16550Drv_Destructor(C_PC16550DRV *self);

HANDLE    Pc16550Drv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      Pc16550Drv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  Pc16550Drv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  Pc16550Drv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE Pc16550Drv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE Pc16550Drv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  Pc16550Drv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

void      Pc16550Drv_Isr(VPARAM Param);			/* 割込み処理 */


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__pc16550drv_h__ */


/* end of file */
