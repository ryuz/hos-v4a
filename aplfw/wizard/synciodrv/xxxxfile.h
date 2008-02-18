/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxfile.h
 * @brief %jp{$OBJNAME_JP$ 公開ヘッダファイル}%en{$OBJNAME_EN$ public header file}
 *
 * $COPYRIGHT$
 */


#ifndef __ZZZZ__xxxxfile_h__
#define __ZZZZ__xxxxfile_h__


#include "xxxxdrv_local.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE XxxxFile_Create(C_XXXXDRV *pXxxxDrv, int iMode);
void   XxxxFile_Delete(HANDLE hFile);

#ifdef __cplusplus
}
#endif


#endif	/*  __ZZZZ__xxxxfile_h__ */


/* end of file */
