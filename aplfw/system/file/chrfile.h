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


#include "system/handle/handleobj.h"
#include "system/file/fileobj.h"

struct c_chrdrv;


/* ファイルブジェクト基本クラス定義 */
typedef struct c_chrfile
{
	C_FILEOBJ			FileObj;		/* ファイルオブジェクトを継承 */
	
	struct c_chrfile	*pNext;			/* イベント監視リスト連結用 */
	struct c_chrfile	*pPrev;			/* イベント監視リスト連結用 */
	
	HANDLE				hEventWrite;	/* 書込みイベント */
	HANDLE				hEventRead;		/* 読込みイベント */
	char				cWriteMode;		/* 書込みモード */
	char				cReadMode;		/* 読込みモード */
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
