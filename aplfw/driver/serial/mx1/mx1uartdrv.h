/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mx1uartdrv.h
 * @brief %jp{Freescale MX1 UART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__mx1uartdrv_h__
#define __HOS__mx1uartdrv_h__


#include "hosaplfw.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE Mx1UartDrv_Create(void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize);	/**< 生成 */
void   Mx1UartDrv_Delete(HANDLE hDriver);														/**< 削除 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__mx1uartdrv_h__ */


/* end of file */
