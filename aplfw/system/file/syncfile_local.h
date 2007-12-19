/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  syncfile.h
 * @brief %jp{同期機能付きデバイスドライバ用ファイルディスクリプタ}
 *
 * %jp{ファイルディスクリプタとして機能するクラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__syncfile_local_h__
#define __HOS__syncfile_local_h__

#include "syncfile.h"
#include "system/file/fileobj_local.h"
#include "syncdrv_local.h"

#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR SyncFile_Constructor(C_SYNCFILE *self, const T_FILEOBJ_METHODS *pMethods, struct c_syncdrv *pSyncDrv);
void     SyncFile_Destructor(C_SYNCFILE *self);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__syncfile_h__ */


/* end of file */
