/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.h
 * @brief %jp{Renesas H8/SH用 SCIデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__renesas_scidrv_h__
#define __HOS__renesas_scidrv_h__


#include "hosaplfw.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE SciDrv_Create(void *pRegBase, int iIntNum, unsigned long ulSysClock, int iBufSize);	/**< 生成 */
void   SciDrv_Delete(HANDLE hDriver);														/**< 削除 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__renesas_scidrv_h__ */


/* end of file */
