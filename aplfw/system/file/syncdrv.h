/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  syncdrv.h
 * @brief %jp{同期機能付きデバイスドライバの基本クラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__syncdrv_h__
#define __HOS__syncdrv_h__


#include "system/sysapi/sysapi.h"
#include "system/file/syncfile.h"
#include "system/file/drvobj.h"


/* デバイスドライバオブジェクト基本クラス */
typedef struct c_syncdrv
{
	C_DRVOBJ		DrvObj;				/**< DrvObjクラスを継承 */
	
	SYSEVT_HANDLE	hMtx;				/**< 排他制御ミューテックス */
	volatile int	iStatus;			/**< ステータス */
	
	C_SYNCFILE		*pFileHead;			/**< 状態監視オブジェクトの連結ポインタ */
} C_SYNCDRV;


#ifdef __cplusplus
extern "C" {
#endif

HANDLE   SyncDrv_Create(void);														/**< 生成 */
void     SyncDrv_Delete(HANDLE hDriver);											/**< 削除 */

void     SyncDrv_SetWriteSignal(C_SYNCDRV *self);									/**< 書込みシグナルのセット */
void     SyncDrv_ClearWriteSignal(C_SYNCDRV *self);									/**< 書込みシグナルのクリア */
FILE_ERR SyncDrv_WaitWriteSignal(C_SYNCDRV *self, C_SYNCFILE *pFile);				/**< 書込みシグナルを待つ */
int      SyncDrv_RefWriteSignal(C_SYNCDRV *self);									/**< 書込みシグナルの状態参照 */

void     SyncDrv_SetReadSignal(C_SYNCDRV *self);									/**< 読込みシグナルのセット */
void     SyncDrv_ClearReadSignal(C_SYNCDRV *self);									/**< 読込みシグナルのクリア */
FILE_ERR SyncDrv_WaitReadSignal(C_SYNCDRV *self, C_SYNCFILE *pFile);				/**< 読込みシグナルを待つ */
int      SyncDrv_RefReadSignal(C_SYNCDRV *self);									/**< 読込みシグナルの状態参照 */

void     SyncDrv_SetIoControlSignal(C_SYNCDRV *self);								/**< I/O制御シグナルのセット */
void     SyncDrv_ClearIoControlSignal(C_SYNCDRV *self);								/**< I/O制御シグナルのクリア */
FILE_ERR SyncDrv_WaitIoControlSignal(C_SYNCDRV *self, C_SYNCFILE *pFile);			/**< I/O制御シグナルを待つ */
int      SyncDrv_RefIoControlSignal(C_SYNCDRV *self);								/**< I/O制御シグナルの状態参照 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__syncdrv_h__ */


/* end of file */
