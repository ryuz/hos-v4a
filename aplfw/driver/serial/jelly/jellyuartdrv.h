/** 
 * Hyper Operating System  Application Framework
 *
 * @file  jellyuartdrv.h
 * @brief %jp{JellyUart 公開ヘッダファイル}%en{JellyUart public header file}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__jellyuartdrv_h__
#define __HOS__jellyuartdrv_h__


#include "hosaplfw.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE JellyUartDrv_Create(void *pRegBase, int iIntNumRx, int iIntNumTx, int iBufSize);	/**< %jp{生成}%en{create} */
void   JellyUartDrv_Delete(HANDLE hDriver);												/**< %jp{削除}%en{delete} */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__jellyuartdrv_h__ */


/* end of file */
