/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9000drv.h
 * @brief %jp{LAN9000ファミリー用デバイスドライバ ローカルヘッダファイル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__lan9000drv_local_h__
#define __HOS__lan9000drv_local_h__


#include "lan9000drv.h"
#include "system/file/syncdrv_local.h"
#include "system/sysapi/sysapi.h"
#include "lan9000hal.h"



/* LAN9000ファミリー用ドライバ制御部 */
typedef struct c_lan9000drv
{
	C_SYNCDRV		SyncDrv;		/* 同期機能付きデバイスドライバを継承 */

	C_LAN9000HAL	Lan9000Hal;		/* ハードウェア制御クラス */
	int				iOpenCount;		/* オープンカウンタ */
	int				iIntNum;		/* 割込み番号 */
	SYSISR_HANDLE	hIsr;			/* 割込みサービスハンドル */
	SYSMTX_HANDLE	hMtx;			/* 排他制御ミューテックス */
} C_LAN9000DRV;



#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR  Lan9000Drv_Constructor(C_LAN9000DRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNum);	/**< コンストラクタ */
void      Lan9000Drv_Destructor(C_LAN9000DRV *self);																	/**< デストラクタ */

HANDLE    Lan9000Drv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      Lan9000Drv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  Lan9000Drv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  Lan9000Drv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE Lan9000Drv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE Lan9000Drv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  Lan9000Drv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

void      Lan9000Drv_Isr(VPARAM Param);			/* 割込み処理 */


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__lan9000drv_local_h__ */


/* end of file */
