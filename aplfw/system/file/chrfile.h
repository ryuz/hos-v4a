/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  chrfile.h
 * @brief %jp{キャラクタ型デバイスドライバ用ファイルディスクリプタ}
 *
 * %jp{ファイルディスクリプタとして機能するクラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__chrfile_h__
#define __HOS__chrfile_h__


#include "system/sysapi/sysapi.h"
#include "system/handle/handleobj.h"
#include "system/file/fileobj.h"

struct c_chrdrv;


/* ファイルブジェクト基本クラス定義 */
typedef struct c_chrfile
{
	C_FILEOBJ			FileObj;			/**< ファイルオブジェクトを継承 */
	
	struct c_chrfile	*pNext;				/**< イベント監視リスト連結用 */
	struct c_chrfile	*pPrev;				/**< イベント監視リスト連結用 */

	char				cWriteMode;			/**< 書込みモード */
	char				cReadMode;			/**< 読込みモード */
	char				cIoMode;			/**< I/O制御モード */
	
	HANDLE				hEventWrite;		/**< 書込み受信イベントハンドル */
	HANDLE				hEventRead;			/**< 読込み受信イベントハンドル */
	HANDLE				hEventIo;			/**< I/O受信イベントハンドル */
	
	SYSPRC_HANDLE		hPrcWrite;			/**< 書込み待ちプロセスハンドル */
	SYSPRC_HANDLE		hPrcRead;			/**< 読込み待ちプロセスハンドル */
	SYSPRC_HANDLE		hPrcIo;				/**< I/O受信待ちプロセスハンドル */
} C_CHRFILE;


#ifdef __cplusplus
extern "C" {
#endif

void    ChrFile_Create(C_CHRFILE *self, struct c_chrdrv *pChrDrv, const T_FILEOBJ_METHODS *pMethods);
void    ChrFile_Delete(C_CHRFILE *self);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__chrfile_h__ */


/* end of file */
