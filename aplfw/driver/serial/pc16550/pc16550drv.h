/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  pc16550drv.h
 * @brief %jp{16550互換シリアル用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__pc16550drv_h__
#define __HOS__pc16550drv_h__


#include "hosaplfw.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE Pc16550Drv_Create(void *pRegAddr, unsigned int uiRegStep, int iIntNum, long lSysClock, int iBufSize);	/**< 生成 */
void   Pc16550Drv_Delete(HANDLE hDriver);																		/**< 削除 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__pc16550drv_h__ */


/* end of file */
