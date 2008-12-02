/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  boot.c
 * @brief %jp{ブート部}%en{boot}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kernel.h"
#include "kernel_id.h"
#include "system/system/system.h"
#include "system/sysapi/sysapi.h"
#include "system/file/console.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "driver/console/pcattext/pcattextdrv.h"
#include "driver/console/vt100/vt100drv.h"
#include "driver/serial/pc16550/pc16550drv.h"
#include "application//syscmd/shell/shell.h"
#include "application//syscmd/commandlist/commandlist.h"
#include "application//syscmd/processlist/processlist.h"
#include "application/utility/timecmd/timecmd.h"
#include "application/utility/memdump/memdump.h"
#include "application/utility/memwrite/memwrite.h"
#include "application/utility/memtest/memtest.h"
#include "application/utility/keytest/keytest.h"
#include "application/example/hello/hello.h"
#include "boot.h"
#include "ostimer.h"


/* システムヒープ */
long	g_SystemHeap[256 * 1024 / sizeof(long)];



int Boot_Process(VPARAM Param);



void Boot_Task(VP_INT exinf)
{
	T_SYSTEM_INITIALIZE_INF	SysInf;
	
	
	/*************************/
	/*    固有初期設定       */
	/*************************/
	
	
	
	/*************************/
	/*       初期化          */
	/*************************/
	
	/* システム初期化 */
	SysInf.pSysMemBase     = g_SystemHeap;
	SysInf.SysMemSize      = sizeof(g_SystemHeap);
	SysInf.SysMemAlign     = 32;
	SysInf.pIoMemBase      = NULL;
	SysInf.SystemStackSize = 2048;
	SysInf.pfncBoot        = Boot_Process;
	SysInf.BootParam       = (VPARAM)0;
	SysInf.BootStackSize   = 2048;
	System_Initialize(&SysInf);
}


/* ブートプロセス */
int Boot_Process(VPARAM Param)
{
	T_PROCESS_CREATE_INF	ProcInf;
	HANDLE					hProcess;
	HANDLE					hDriver;
	HANDLE					hConOut;
	HANDLE					hConIn;
	
	
	/*************************/
	/*   デバイスドライバ    */
	/*************************/
	
	/* タイマ初期化 */	
/*	OsTimer_Initialize();	*/
	
	/* 16550デバドラ生成 (/dev/com0 に登録) */
/*
	hDriver = Pc16550Drv_Create((void *)0x03f8, 0, 4, 1843200, 256);
	File_AddDevice("com1", hDriver);
	hDriver = Pc16550Drv_Create((void *)0x02f8, 0, 3, 1843200, 256);
	File_AddDevice("com2", hDriver);
*/
	
	
	/* コンソールを生成( /dev/con0 に登録) */
	hDriver = PcatTextDrv_Create((void *)0, (void *)0x000b8000);
	File_AddDevice("screen0", hDriver);
	
	/* コンソールを開く */
	hConOut = File_Open("/dev/screen0", FILE_OPEN_READ | FILE_OPEN_WRITE);
	
	
	
	/*************************/
	/*     標準入出力設定    */
	/*************************/
	
	Process_SetConIn(HANDLE_NULL, hConIn);
	Process_SetConOut(HANDLE_NULL, hConOut);
	Process_SetStdIn(HANDLE_NULL, hConIn);
	Process_SetStdOut(HANDLE_NULL, hConOut);
	Process_SetStdErr(HANDLE_NULL, hConOut);
	
	
	/*************************/
	/*     コマンド登録      */
	/*************************/
	Command_AddCommand("sh",       Shell_Main);
	Command_AddCommand("ps",       ProcessList_Main);
	Command_AddCommand("help",     CommandList_Main);
	Command_AddCommand("time",     TimeCmd_Main);
	Command_AddCommand("memdump",  MemDump_Main);
	Command_AddCommand("memwrite", MemWrite_Main);
	Command_AddCommand("memtest",  MemTest_Main);
	Command_AddCommand("keytest",  KeyTest_Main);
	Command_AddCommand("hello",    Hello_Main);
	
	
	/*************************/
	/*    起動メッセージ     */
	/*************************/
	StdIo_PutString(
			"\n\n"
			"================================================================\n"
			" Hyper Operating System  Application Framework\n"
			"\n"
			"                          Copyright (C) 1998-2008 by Project HOS\n"
			"                          http://sourceforge.jp/projects/hos/\n"
			"================================================================\n"
			"\n");
	
	
	/*************************/
	/*      シェル起動       */
	/*************************/
	
	/* プロセスの生成*/
	ProcInf.pszCommandLine = "sh -i";								/* 実行コマンド */
	ProcInf.pszCurrentDir  = "";									/* 起動ディレクトリ */
	ProcInf.pfncEntry      = NULL;									/* 起動アドレス */
	ProcInf.Param          = 0;										/* ユーザーパラメータ */
	ProcInf.StackSize      = 2048;									/* スタックサイズ */
	ProcInf.Priority       = PROCESS_PRIORITY_NORMAL;				/* プロセス優先度 */
	ProcInf.hTerminal      = Process_GetTerminal(HANDLE_NULL);		/* ターミナル */
	ProcInf.hConIn         = Process_GetConIn(HANDLE_NULL);			/* コンソール入力 */
	ProcInf.hConOut        = Process_GetConOut(HANDLE_NULL);		/* コンソール出力 */
	ProcInf.hStdIn         = Process_GetStdIn(HANDLE_NULL);			/* 標準入力 */
	ProcInf.hStdOut        = Process_GetStdOut(HANDLE_NULL);		/* 標準出力 */
	ProcInf.hStdErr        = Process_GetStdErr(HANDLE_NULL);		/* 標準エラー出力 */
	for ( ; ; )
	{
		hProcess = Process_CreateEx(&ProcInf);
		Process_WaitExit(hProcess);
		Process_Delete(hProcess);
	}
}



/* end of file */
