/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  chrdrv.h
 * @brief %jp{キャラクタ型デバイスドライバの基本クラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__chrdrv_h__
#define __HOS__chrdrv_h__


#include "system/sysapi/sysapi.h"
#include "system/file/chrfile.h"
#include "system/file/drvobj.h"



/* デバイスドライバオブジェクト基本クラス */
typedef struct c_chrdrv
{
	C_DRVOBJ		DrvObj;				/**< DrvObjクラスを継承 */
	
	SYSEVT_HANDLE	hMtx;				/**< 排他制御ミューテックス */
	volatile int	iStatus;			/**< ステータス */
	
	C_CHRFILE		*pFileHead;			/**< 状態監視オブジェクトの連結ポインタ */
} C_CHRDRV;


#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR ChrDrv_Create(C_CHRDRV *self, const T_DRVOBJ_METHODS *pMethods);	/**< コンストラクタ */
void     ChrDrv_Delete(C_CHRDRV *self);										/**< デストラクタ */

void     ChrDrv_SetWriteSignal(C_CHRDRV *self);								/**< 書込み可能になった可能性があることを通知 */
void     ChrDrv_ClearWriteSignal(C_CHRDRV *self);							/**< 書込み可能シグナルのクリア */
FILE_ERR ChrDrv_WaitWriteSignal(C_CHRDRV *self, C_CHRFILE *pFile);			/**< 書込み可能になった可能性があるまで待つ */
int      ChrDrv_RefWriteSignal(C_CHRDRV *self);								/**< 書込み可能状況参照 */

void     ChrDrv_SetReadSignal(C_CHRDRV *self);								/**< 読込み可能になったことを通知 */
void     ChrDrv_ClearReadSignal(C_CHRDRV *self);							/**< 読込み可能シグナルのクリア */
FILE_ERR ChrDrv_WaitReadSignal(C_CHRDRV *self, C_CHRFILE *pFile);			/**< 読込み可能になった可能性があるまで待つ */
int      ChrDrv_RefReadSignal(C_CHRDRV *self);								/**< 読込み可能状況参照 */

void     ChrDrv_SetIoSignal(C_CHRDRV *self);								/**< I/Oの完了シグナルを通知 */
void     ChrDrv_ClearIoSignal(C_CHRDRV *self);								/**< I/Oのシグナルのクリア */
FILE_ERR ChrDrv_WaitIoSignal(C_CHRDRV *self, C_CHRFILE *pFile);				/**< I/Oの完了まで待つ */
int      ChrDrv_RefIoSignal(C_CHRDRV *self);								/**< I/Oの完了状況参照 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__chrdrv_h__ */


/* end of file */
