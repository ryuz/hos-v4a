/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxfile.h
 * @brief %jp{$OBJNAME_JP$ ローカルヘッダファイル}%en{$OBJNAME_EN$ private header file}
 *
 * $COPYRIGHT$
 */


#ifndef __ZZZZ__xxxxfile_local_h__
#define __ZZZZ__xxxxfile_local_h__


#include "xxxxfile.h"
#include "system/file/syncfile_local.h"
#include "system/sysapi/sysapi.h"


/* ファイルディスクリプタ */
typedef struct c_xxxxfile
{
	C_SYNCFILE	SyncFile;			/* 継承 */

	/* ここに必要なメンバを追加 */	
} C_XXXXFILE;


#ifdef __cplusplus
extern "C" {
#endif

void  XxxxFile_Constructor(C_XXXXFILE *self, const T_FILEOBJ_METHODS *pMethods, C_XXXXDRV *pXxxxDrv, int iMode);
void  XxxxFile_Destructor(C_XXXXFILE *self);

#ifdef __cplusplus
}
#endif



#endif	/*  __ZZZZ__xxxxfile_local_h__ */


/* end of file */
