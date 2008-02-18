/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv.h
 * @brief %jp{$OBJNAME_JP$ 公開ヘッダファイル}%en{$OBJNAME_EN$ public header file}
 *
 * $COPYRIGHT$
 */


#ifndef __ZZZZ__xxxxdrv_h__
#define __ZZZZ__xxxxdrv_h__


#include "hosaplfw.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE XxxxDrv_Create(void *pRegBase, int iIntNum);		/**< %jp{生成}%en{create} */
void   XxxxDrv_Delete(HANDLE hDriver);					/**< %jp{削除}%en{delete} */

#ifdef __cplusplus
}
#endif


#endif	/* __ZZZZ__xxxxdrv_h__ */


/* end of file */
