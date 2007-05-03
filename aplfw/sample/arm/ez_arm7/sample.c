/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  sample.c
 * @brief %jp{サンプルプログラム}%en{Sample program}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kernel.h"
#include "kernel_id.h"
#include "system/sysapi/sysapi.h"
#include "system/file/console.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "system/shell/shell.h"
#include "driver/serial/pc16550/pc16550drv.h"
#include "driver/console/vt100/vt100drv.h"
#include "apl/hello/hello.h"
#include "apl/util/memdump/memdump.h"
#include "apl/util/memwrite/memwrite.h"
#include "apl/util/memtest/memtest.h"
#include "apl/util/keytest/keytest.h"


long         g_SystemHeap[64 * 1024 / sizeof(long)];
C_PC16550DRV g_Pc16550Drv[1];
C_VT100DRV   g_Vt100Drv[1];


int System_Boot(VPARAM Param);


#define PINSEL0		((volatile UW *)0xe002c000)

void Sample_Task(VP_INT exinf)
{
	T_PROCESS_INF	ProcInfo;
	HANDLE			hTty;
	HANDLE			hCon;
	
	/*************************/
	/*    固有初期設定       */
	/*************************/
	*PINSEL0 = (*PINSEL0 & 0xfffffff0) | 0x05;

	
	/*************************/
	/*       初期化          */
	/*************************/
	
	/* システム初期化 */
	System_Initialize(g_SystemHeap, sizeof(g_SystemHeap));
	File_Initialize();
	Command_Initialize();


	/*************************/
	/*   デバイスドライバ    */
	/*************************/
	
	/* 16550デバドラ生成 (/dev/com0 に登録) */
	Pc16550Drv_Create(&g_Pc16550Drv[0], (void *)0xe000c000, 2, 6, (14700000/4), 64);
	File_AddDevice("com0", (C_DRVOBJ *)&g_Pc16550Drv[0]);

	/* シリアル上にコンソールを生成( /dev/com0 に登録) */
	hTty = File_Open("/dev/com0", FILE_OPEN_READ | FILE_OPEN_WRITE);
	Vt100Drv_Create(&g_Vt100Drv[0], hTty);
	File_AddDevice("con0", (C_DRVOBJ *)&g_Vt100Drv[0]);
	
	
	/*************************/
	/*     コマンド登録      */
	/*************************/
	Command_AddCommand("hsh",      Shell_Main);
	Command_AddCommand("hello",    Hello_Main);
	Command_AddCommand("memdump",  MemDump_Main);
	Command_AddCommand("memwrite", MemWrite_Main);
	Command_AddCommand("memtest",  MemTest_Main);
	Command_AddCommand("keytest",  KeyTest_Main);
	
	
	/*************************/
	/*  システムプロセス起動 */
	/*************************/
	
	hCon = File_Open("/dev/con0", FILE_OPEN_READ | FILE_OPEN_WRITE);
	ProcInfo.hTty     = hTty;
	ProcInfo.hConsole = hCon;
	ProcInfo.hStdIn   = hCon;
	ProcInfo.hStdOut  = hCon;
	ProcInfo.hStdErr  = hCon;
	Process_CreateEx(System_Boot, 0, 4096, PROCESS_PRIORITY_NORMAL, &ProcInfo);
	
	return;
}


/* システムプロセス */
int System_Boot(VPARAM Param)
{
	/* シェル起動 */
	return Command_Execute("hsh", NULL);
}



/* end of file */
