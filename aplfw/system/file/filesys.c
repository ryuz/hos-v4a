/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "filesys.h"
#include "system/sysapi/sysapi.h"
#include "system/memory/memory.h"


#define FILE_MAX_DEVICE		16

/* デバイスの登録テーブル */
static T_SYSFILE_DEVINF SysFile_DevTable[FILE_MAX_DEVICE];


/* ファイルシステムの初期化 */
void SysFile_Initialize(void)
{
}