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


#include "system/file/chrfile.h"
#include "system/file/drvobj.h"



/* デバイスドライバオブジェクト基本クラス */
typedef struct c_chrdrv
{
	C_DRVOBJ	DrvObj;			/* DrvObjクラスを継承 */
	
	char		iWriteSignal;	/* 書込み状態 */
	char		iReadSignal;	/* 読出し状態 */
	C_CHRFILE	*pMonHead;		/* 状態監視オブジェクトの連結ポインタ */
} C_CHRDRV;


#ifdef __cplusplus
extern "C" {
#endif

void ChrDrv_Create(C_CHRDRV *self, const T_DRVOBJ_METHODS *pMethods);		/**< コンストラクタ */
void ChrDrv_Delete(C_DRVOBJ *self);											/**< デストラクタ */

void ChrDrv_WriteSignal(C_CHRDRV *self);		/**< 書込み可能になったことを通知 */
void ChrDrv_ReadSignal(C_CHRDRV *self);			/**< 読込み可能になったことを通知 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__chrdrv_h__ */


/* end of file */
