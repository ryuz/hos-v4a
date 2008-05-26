/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "system/sysapi/sysapi.h"
#include "system/system/system_local.h"
#include "system/file/file.h"
#include "system/command/command.h"


/* システムクラス */
C_SYSTEM g_System;


static void System_BootProcess(VPARAM Param1, VPARAM Param2);


/* システムの初期化 */
void System_Initialize(const T_SYSTEM_INITIALIZE_INF *pInf)
{
	C_SYSTEM				*self;
	T_PROCESS_CREATE_INF	*pProcessInf;
	
	self = &g_System;

	/* システムAPIの初期化 */
	SysApi_Initialize(pInf->pSysMemBase, pInf->SysMemSize, pInf->SysMemAlign,
							pInf->pIoMemBase, pInf->IoMemSize, pInf->IoMemAlign);
	
	/* ファイルシステム初期化 */
	File_Initialize();
	
	/* コマンドシステム初期化 */
	Command_Initialize();
	
	
	/* システム変数の初期化 */
	g_System.hEvtProc  = SysEvt_Create(SYSEVT_ATTR_AUTOCLEAR);
	g_System.iProcHead = 0;
	g_System.iProcTail = 0;
	
	/* プロセス生成情報用メモリ確保 */
	pProcessInf = (T_PROCESS_CREATE_INF *)SysMem_Alloc(sizeof(T_PROCESS_CREATE_INF));
	memset(pProcessInf, 0, sizeof(T_PROCESS_CREATE_INF));
	
	/* システムプロセスの起動 */
	pProcessInf->pszCommandLine = "[system]";
	pProcessInf->pfncEntry      = System_Process;			/* 起動アドレス */
	pProcessInf->Param          = (VPARAM)self;				/* ユーザーパラメータ */
	pProcessInf->StackSize      = pInf->SystemStackSize;	/* スタックサイズ */
	pProcessInf->Priority       = 1;						/* プロセス優先度 */
	pProcessInf->hTerminal      = HANDLE_NULL;				/* ターミナル */
	pProcessInf->hConIn         = HANDLE_NULL;				/* コンソール入力 */
	pProcessInf->hConOut        = HANDLE_NULL;				/* コンソール出力 */
	pProcessInf->hStdIn         = HANDLE_NULL;				/* 標準入力 */
	pProcessInf->hStdOut        = HANDLE_NULL;				/* 標準出力 */
	pProcessInf->hStdErr        = HANDLE_NULL;				/* 標準エラー出力 */
	pProcessInf->pszCurrentDir  = "";						/* カレントディレクトリ */
	Process_Constructor(&self->Process, NULL, pProcessInf);
	
	/* ブートプロセスの起動依頼 */
	pProcessInf->pszCommandLine = "[boot]";
	pProcessInf->pfncEntry      = pInf->pfncBoot;			/* 起動アドレス */
	pProcessInf->Param          = pInf->BootParam;			/* ユーザーパラメータ */
	pProcessInf->StackSize      = pInf->BootStackSize;		/* スタックサイズ */
	pProcessInf->Priority       = PROCESS_PRIORITY_NORMAL;	/* プロセス優先度 */
	pProcessInf->hTerminal      = HANDLE_NULL;				/* ターミナル */
	pProcessInf->hConIn         = HANDLE_NULL;				/* コンソール入力 */
	pProcessInf->hConOut        = HANDLE_NULL;				/* コンソール出力 */
	pProcessInf->hStdIn         = HANDLE_NULL;				/* 標準入力 */
	pProcessInf->hStdOut        = HANDLE_NULL;				/* 標準出力 */
	pProcessInf->hStdErr        = HANDLE_NULL;				/* 標準エラー出力 */
	pProcessInf->pszCurrentDir  = "";						/* カレントディレクトリ */
	System_RequestProc(System_BootProcess, (VPARAM)self, (VPARAM)pProcessInf);
}


/* ブートプロセスをシステムプロセスの子プロセスとして開始 */
void System_BootProcess(VPARAM Param1, VPARAM Param2)
{
	C_SYSTEM				*self;
	T_PROCESS_CREATE_INF	*pProcessInf;

	self        = (C_SYSTEM *)Param1;
	pProcessInf = (T_PROCESS_CREATE_INF *)Param2;
	
	/* ブートプロセスをシステムプロセスの子プロセスとして開始 */
	self->hBootProcess = Process_Create(pProcessInf);
	
	/* プロセス生成情報用メモリ開放 */
	SysMem_Free(pProcessInf);
}



/* end of file */
