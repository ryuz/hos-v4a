/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "system/system/system.h"
#include "system/sysapi/sysapi.h"
#include "system/file/file.h"
#include "system/command/command.h"


/* システムの初期化 */
void System_Initialize(void *pMem, MEMSIZE Size)
{
	/* システムAPIの初期化 */
	SysApi_Initialize(pMem, Size);
	
	/* ファイルシステム初期化 */
	File_Initialize();
	
	/* コマンドシステム初期化 */
	Command_Initialize();	
}


/* end of file */
