/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  chrfile.h
 * @brief %jp{同期機能付きデバイスドライバ用ファイルディスクリプタ}
 *
 * %jp{ファイルディスクリプタとして機能するクラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__syncfile_h__
#define __HOS__syncfile_h__


#include "hosaplfw.h"


struct c_syncdrv;


#ifdef __cplusplus
extern "C" {
#endif

HANDLE   SyncFile_Create(struct c_syncdrv *pSyncDrv, int iMode);
void     SyncFile_Delete(HANDLE hFile);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__syncfile_h__ */


/* end of file */
