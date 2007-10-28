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
	
	SYSEVT_HANDLE	hMtx;				/* 排他制御ミューテックス */
	SYSEVT_HANDLE	hEvtWrite;			/* 書込みイベント */
	SYSEVT_HANDLE	hEvtRead;			/* 読込みイベント */
	
	C_CHRFILE		*pFileHead;			/**< 状態監視オブジェクトの連結ポインタ */
} C_CHRDRV;


#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR ChrDrv_Create(C_CHRDRV *self, const T_DRVOBJ_METHODS *pMethods);	/**< コンストラクタ */
void     ChrDrv_Delete(C_CHRDRV *self);										/**< デストラクタ */

#define  ChrDrv_Lock(self)				SysMtx_Lock((self)->hMtx)			/**< 書込み可能になった可能性があることを通知 */
#define  ChrDrv_Unlock(self)			SysMtx_Unlock((self)->hMtx)			/**< 書込み可能になった可能性があるまで待つ */

void     ChrDrv_SetWriteSignal(C_CHRDRV *self);								/**< 書込み可能になった可能性があることを通知 */
#define  ChrDrv_WaitWriteSignal(self)	SysEvt_Wait((self)->hEvtWrite)		/**< 書込み可能になった可能性があるまで待つ */
#define  ChrDrv_RefWriteSignal(self)	SysEvt_Ref((self)->hEvtWrite)		/**< 書込み可能状況参照 */

void     ChrDrv_SetReadSignal(C_CHRDRV *self);								/**< 読込み可能になったことを通知 */
#define  ChrDrv_WaitReadSignal(self)	SysEvt_Wait((self)->hEvtRead)		/**< 読込み可能になった可能性があるまで待つ */
#define  ChrDrv_RefReadSignal(self)		SysEvt_Ref((self)->hEvtRead)		/**< 読込み可能状況参照 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__chrdrv_h__ */


/* end of file */
