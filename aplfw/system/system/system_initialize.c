/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "system/sysapi/sysapi.h"
#include "system/system/system_local.h"
#include "system/file/file.h"
#include "system/command/command.h"


/* システムクラス */
C_SYSTEM g_System;


/* システムの初期化 */
void System_Initialize(void *pMem, MEMSIZE Size)
{
	C_SYSTEM	*self;
	
	self = &g_System;

	/* システムAPIの初期化 */
	SysApi_Initialize(pMem, Size);
	
	/* システムクラスの初期化 */
	g_System.hEvtProc  = SysEvt_Create(SYSEVT_ATTR_AUTOCLEAR);
	g_System.iProcHead = 0;
	g_System.iProcTail = 0;
	
	/* システムプロセスの開始 */
	self->hPrcProc = SysPrc_Create(System_Process, (VPARAM)self, 1024, 1);
	SysPrc_Start(self->hPrcProc);

	
	/* ファイルシステム初期化 */
	File_Initialize();
	
	/* コマンドシステム初期化 */
	Command_Initialize();
}


/* end of file */
