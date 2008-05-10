/** 
 * Hyper Operating System  Application Framework
 *
 * @file  pcattextdrv.h
 * @brief %jp{PC/AT text mode driver 公開ヘッダファイル}%en{PC/AT text mode driver public header file}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__pcattextdrv_h__
#define __HOS__pcattextdrv_h__


#include "hosaplfw.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE PcatTextDrv_Create(void *pRegBase, void *pVramBase);		/**< %jp{生成}%en{create} */
void   PcatTextDrv_Delete(HANDLE hDriver);						/**< %jp{削除}%en{delete} */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__pcattextdrv_h__ */


/* end of file */
