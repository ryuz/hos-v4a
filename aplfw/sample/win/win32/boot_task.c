/**
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  sample.c
 * @brief %jp{サンプルプログラム}%en{Sample program}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kernel.h"
#include "kernel_id.h"
#include "hosaplfw.h"
#include "system/system/system.h"
#include "system/sysapi/sysapi.h"
#include "system/file/file.h"
#include "system/file/console.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "system/shell/shell.h"
#include "driver/serial/winsock/winsockdrv.h"
#include "driver/console/vt100/vt100drv.h"
#include "application/example/hello/hello.h"
#include "boot_task.h"


long	g_SystemHeap[8 * 1024 / sizeof(long)];


int Boot_Process(VPARAM Param);

/* ブートタスク */
void Boot_Task(VP_INT exinf)
{
	T_SYSTEM_INITIALIZE_INF	SysInf;
	
	
	/*************************/
	/*       初期化          */
	/*************************/
	
	/* システム初期化 */
	SysInf.pHeapMem        = g_SystemHeap;
	SysInf.HeapSize        = sizeof(g_SystemHeap);
	SysInf.SystemStackSize = 1024;
	SysInf.pfncBoot        = Boot_Process;
	SysInf.BootParam       = (VPARAM)0;
	SysInf.BootStackSize   = 4096;
	System_Initialize(&SysInf);
}




/* ブートプロセス */
int Boot_Process(VPARAM Param)
{
	HANDLE	hTty;
	HANDLE	hCon;
	HANDLE	hDriver;
	

	/*************************/
	/*     デバドラ登録      */
	/*************************/

	/* WinSock用擬似シリアルデバドラ生成 */
	hDriver = WinSockDrv_Create(9997, 1, 64);
	File_AddDevice("com0", hDriver);
	
	/* ターミナルを開く */
	hTty = File_Open("/dev/com0", FILE_OPEN_READ | FILE_OPEN_WRITE);

	/* /dev/com0 の上に VT100コンソールを形成 */
	hDriver = Vt100Drv_Create(hTty);
	File_AddDevice("con0", hDriver);

	/* コンソールを開く */
	hCon = File_Open("/dev/con0", FILE_OPEN_READ | FILE_OPEN_WRITE);


	/*************************/
	/*     標準入出力設定    */
	/*************************/
	
	Process_SetTerminal(HANDLE_NULL, hTty);
	Process_SetConsole(HANDLE_NULL, hCon);
	Process_SetStdIn(HANDLE_NULL, hCon);
	Process_SetStdOut(HANDLE_NULL, hCon);
	Process_SetStdErr(HANDLE_NULL, hCon);
	

	/*************************/
	/*     コマンド登録      */
	/*************************/
	Command_Initialize();
	Command_AddCommand("hsh",     Shell_Main);
	Command_AddCommand("hello",   Hello_Main);
	
	
	/* 起動メッセージ */
	StdIo_PutString(
			"\n\n"
			"================================================================\n"
			" Hyper Operating System  Application Flamework\n"
			"\n"
			"                          Copyright (C) 1998-2007 by Project HOS\n"
			"                          http://sourceforge.jp/projects/hos/\n"
			"================================================================\n"
			"\n");
	
	/*************************/
	/*      シェル起動       */
	/*************************/
	
	Command_Execute("hsh", NULL);

	return 0;
}



/* end of file */
