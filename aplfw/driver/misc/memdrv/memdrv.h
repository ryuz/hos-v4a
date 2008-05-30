/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memdrv.h
 * @brief %jp{メモリマップドファイル用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__memdrv_h__
#define __HOS__memdrv_h__


#include "system/file/drvobj.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE MemDrv_Create(void *pMemAddr, FILE_POS MemSize, FILE_POS IniSize, int iAttr);	/**< 生成 */
void   MemDrv_Delete(HANDLE hDriver);													/**< 削除 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__memdrv_h__ */


/* end of file */
