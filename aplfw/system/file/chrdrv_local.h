/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  chrdrv.h
 * @brief %jp{キャラクタ型デバイスドライバの基本クラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__chrdrv_local_h__
#define __HOS__drvobj_local_h__


#include "system/file/chrdrv.h"


#ifdef __cplusplus
extern "C" {
#endif

void ChrDrv_WriteSignal(C_DRVOBJ *self);		/**< 書込み可能になったことを通知 */
void ChrDrv_ReadSignal(C_DRVOBJ *self);			/**< 読込み可能になったことを通知 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__drvobj_h__ */


/* end of file */
