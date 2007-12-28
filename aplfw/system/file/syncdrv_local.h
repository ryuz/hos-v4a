/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  syncdrv.h
 * @brief %jp{同期機能付きデバイスドライバの基本クラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__syncdrv_local_h__
#define __HOS__syncdrv_local_h__


#include "syncdrv.h"
#include "system/file/drvobj_local.h"
#include "system/sysapi/sysapi.h"



/* 処理要因定義 */
#define SYNCDRV_FACTOR_WRITE		0
#define SYNCDRV_FACTOR_READ			1
#define SYNCDRV_FACTOR_IOCTL		2

#define SYNCDRV_FACTOR_NUM			3

struct c_syncfile;

/* デバイスドライバオブジェクト基本クラス(抽象クラス) */
typedef struct c_syncdrv
{
	C_DRVOBJ			DrvObj;				/**< DrvObjクラスを継承 */

	struct c_syncfile	*pFileHead;			/**< ファイルオブジェクトの連結ポインタ */
	
	SYSEVT_HANDLE		hMtx;				/**< 排他制御ミューテックス */
	
	int					iSyncFactorNum;		/**< 同期要因の数 */
	struct c_syncfile	**ppBusyFile;		/**< 処理中ファイルオブジェクト */
} C_SYNCDRV;


#include "system/file/syncfile_local.h"


#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR SyncDrv_Constructor(C_SYNCDRV *self, const T_DRVOBJ_METHODS *pMethods, int iSyncFactorNum);	/**< コンストラクタ */
void     SyncDrv_Destructor(C_SYNCDRV *self);															/**< デストラクタ */

#define  SyncDrv_GetSyncFactorNum(self)		((self)->iSyncFactorNum)									/**< 同期要因数取得 */

FILE_ERR SyncDrv_StartProcess(C_SYNCDRV *self, struct c_syncfile *pSyncFile, int iFactor);				/**< 処理の開始 */
void     SyncDrv_EndProcess(C_SYNCDRV *self, int iFactor, VPARAM ErrCode);								/**< 処理の完了 */
void     SyncDrv_SendSignal(C_SYNCDRV *self, int iFactor);												/**< シグナルの送信 */

FILE_ERR SyncDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__drvobj_h__ */


/* end of file */
