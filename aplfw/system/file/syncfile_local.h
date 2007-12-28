/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  syncfile.h
 * @brief %jp{同期機能付きデバイスドライバ用ファイルディスクリプタ}
 *
 * %jp{ファイルディスクリプタとして機能するクラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__syncfile_local_h__
#define __HOS__syncfile_local_h__

#include "syncfile.h"
#include "system/file/fileobj_local.h"
#include "system/file/syncdrv_local.h"
#include "system/sysapi/sysapi.h"


/* 同期オブジェクト */
typedef struct t_syncfile_syncobj
{
	int					Mode;			/**< 同期モード */
	VPARAM				ErrCode;		/**< エラーコード */
	SYSEVT_HANDLE		hEvt;			/**< 同期イベント */
	T_FILE_SYNCINF		Inf;			/**< 同期情報 */
} T_SYNCFILE_SYNCOBJ;


/* ファイルブジェクト基本クラス定義 */
typedef struct c_syncfile
{
	C_FILEOBJ			FileObj;		/**< ファイルオブジェクトを継承 */
	
	struct c_syncfile	*pNext;			/**< イベント監視リスト連結用 */
	struct c_syncfile	*pPrev;			/**< イベント監視リスト連結用 */

	T_SYNCFILE_SYNCOBJ	*pSyncObj;		/**< 同期オブジェクト */
} C_SYNCFILE;


#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR SyncFile_Constructor(C_SYNCFILE *self, const T_FILEOBJ_METHODS *pMethods, struct c_syncdrv *pSyncDrv, int iMode);
void     SyncFile_Destructor(C_SYNCFILE *self);

void     SyncFile_SetSignal(C_SYNCFILE *self, int iFactor);															/**< シグナルのセット */
#define  SyncFile_ClearSignal(self, iFactor)		do { SysEvt_Clear((self)->pSyncObj[iFactor].hEvt); } while(0)	/**< シグナルのクリア */
#define  SyncFile_WaitSignal(self, iFactor)			do { SysEvt_Wait((self)->pSyncObj[iFactor].hEvt); } while(0)	/**< シグナルを待つ */
#define  SyncFile_RefSignal(self, iFactor)			(SysEvt_RefStatus((self)->pSyncObj[iFactor].hEvt))				/**< シグナルの状態参照 */

#define  SyncFile_SetSyncMode(self, iFactor, x)		do { ((self)->pSyncObj[iFactor].Mode) = (x); } while(0)			/**< 同期モード設定 */
#define  SyncFile_GetSyncMode(self, iFactor)		((self)->pSyncObj[iFactor].Mode)								/**< 同期モード取得 */

#define  SyncFile_SetSyncInf(self, iFactor, x)		do { ((self)->pSyncObj[iFactor].Inf) = (x); } while(0)			/**< 同期情報設定 */
#define  SyncFile_GetSyncInf(self, iFactor)			((self)->pSyncObj[iFactor].Inf)									/**< 同期情報取得 */

#define  SyncFile_SetErrCode(self, iFactor, x)		do { ((self)->pSyncObj[iFactor].ErrCode) = (x); } while(0)		/**< エラーコード設定 */
#define  SyncFile_GetErrCode(self, iFactor)			((self)->pSyncObj[iFactor].ErrCode)								/**< エラーコード取得 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__syncfile_h__ */


/* end of file */
