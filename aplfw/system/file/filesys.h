/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  filesys.h
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__filesys_h__
#define __HOS__filesys_h__


#include "system/handle/handle.h"


/* デバイス情報 */
typedef struct t_sysfile_devinf
{
	char	szName[FILE_MAX_NAME];						/* ファイル名 */
	FILEERR	(*pfncCreate)(HANDLE hFile, void *pParam);	/* コンストラクタアドレス */
	int     ObjSize;									/* オブジェクトのサイズ */
	void    *pParam;									/* オブジェクトの生成パラメータ */
} T_SYSFILE_DEVINF;


#ifdef __cplusplus
extern "C" {
#endif

/* システムAPI */
void     SysFile_Initialize(void);													/* ファイルシステムの初期化 */
FILEERR  SysFile_AddDevice(const char *pszPath, const T_SYSFILE_DEVINF *pDevInf);	/* デバイスファイルの追加 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__filesys_h__ */


/* end of file */
