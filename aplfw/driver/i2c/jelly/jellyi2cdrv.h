/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  jellyi2cdrv.h
 * @brief %jp{Jelly I2C デバイスドライバ 公開ヘッダファイル}
 *
 * Copyright (C) 2006-2010 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__jellyi2cdrv_h__
#define __HOS__jellyi2cdrv_h__


#include "hosaplfw.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE JellyI2cDrv_Create(void *pRegBase, unsigned long ulBaseClock);	/**< 生成 */
void   JellyI2cDrv_Delete(HANDLE hDriver);								/**< 削除 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__jellyi2cdrv_h__ */


/* end of file */
