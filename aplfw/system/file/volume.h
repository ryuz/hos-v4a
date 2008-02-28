/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  volume.h
 * @brief %jp{ボリュームオブジェクト}
 *
 * %jp{ディスクドライブなどの単位をボリュームとして扱う}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__volume_h__
#define __HOS__volume_h__

#include "file.h"

#ifdef __cplusplus
extern "C" {
#endif

HANDLE   Volume_OpenFile(HANDLE hVolume, const char *pszPath, int iMode);		/* ファイルを開く */
FILE_ERR Volume_Shutdown(HANDLE hVolume);										/* シャットダウンする */
FILE_ERR Volume_MakeDir(HANDLE hVolume, const char *pszPath);					/* サブディレクトリを作成 */
FILE_ERR Volume_Remove(HANDLE hVolume, const char *pszPath);					/* ファイルを削除 */

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__volume_h__ */


/* end of file */
