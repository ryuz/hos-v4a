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


#include "system/sysapi/sysapi.h"
#include "system/handle/handleobj.h"
#include "system/file/fileobj.h"

struct c_syncdrv;


/* ファイルブジェクト基本クラス定義 */
typedef struct c_syncfile
{
	C_FILEOBJ			FileObj;			/**< ファイルオブジェクトを継承 */
	
	struct c_syncfile	*pNext;				/**< イベント監視リスト連結用 */
	struct c_syncfile	*pPrev;				/**< イベント監視リスト連結用 */

	char				cWriteMode;			/**< 書込みモード */
	char				cReadMode;			/**< 読込みモード */
	char				cIoMode;			/**< I/O制御モード */
	
	HANDLE				hEventWrite;		/**< 書込み受信イベントハンドル */
	HANDLE				hEventRead;			/**< 読込み受信イベントハンドル */
	HANDLE				hEventIo;			/**< I/O受信イベントハンドル */
	
	SYSPRC_HANDLE		hPrcWrite;			/**< 書込み待ちプロセスハンドル */
	SYSPRC_HANDLE		hPrcRead;			/**< 読込み待ちプロセスハンドル */
	SYSPRC_HANDLE		hPrcIo;				/**< I/O受信待ちプロセスハンドル */
} C_SYNCFILE;


#ifdef __cplusplus
extern "C" {
#endif

HANDLE  SyncFile_Create(struct c_syncdrv *pSyncDrv);
void    SyncFile_Delete(C_SYNCFILE *self);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__syncfile_h__ */


/* end of file */
