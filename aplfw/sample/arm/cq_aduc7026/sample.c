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
#include "system/file/confile.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "system/shell/shell.h"
#include "driver/serial/pc16550/pc16550file.h"
#include "apl/hello/hello.h"



long         g_SystemHeap[1 * 1024 / sizeof(long)];
C_PC16550DRV g_Pc16550Drv[1];


int System_Boot(VPARAM Param);



void Sample_Task(VP_INT exinf)
{
	T_FILE_DEVINF   DevInf;
	T_PROCESS_INFO  ProcInfo;
	HANDLE          hTty;
	HANDLE          hCon;
	
	/*************************/
	/*    固有初期設定       */
	/*************************/
	*((volatile UB *)0xfffff404) = 0x11;	/* GP1CON */

	
	/*************************/
	/*       初期化          */
	/*************************/
	
	/* システム初期化 */
	System_Initialize(g_SystemHeap, sizeof(g_SystemHeap));
	
	/* 16550デバドラ生成 */
	Pc16550Drv_Create(&g_Pc16550Drv[0], (void *)0xffff0700, 4, 1, 20889600L, 64);	/* SCI0 */
	
	/* 16550 を /dev/com0 に登録 */
	strcpy(DevInf.szName, "com0");
	DevInf.pfncCreate = Pc16550File_Create;
	DevInf.ObjSize    = sizeof(C_PC16550FILE);
	DevInf.pParam     = &g_Pc16550Drv[0];
	File_AddDevice(&DevInf);
	
	
	/*************************/
	/*     コマンド登録      */
	/*************************/
	Command_Initialize();
	Command_AddCommand("hsh",   Shell_Main);
	Command_AddCommand("hello", Hello_Main);
	
	/*************************/
	/*  システムプロセス起動 */
	/*************************/
	hTty = File_Open("/dev/com0", FILE_MODE_READ | FILE_MODE_WRITE);
	
	strcpy(DevInf.szName, "con0");
	DevInf.pfncCreate = ConsoleFile_Create;
	DevInf.ObjSize    = sizeof(C_CONSOLEFILE);
	DevInf.pParam     = hTty;
	File_AddDevice(&DevInf);
	hCon = File_Open("/dev/con0", FILE_MODE_READ | FILE_MODE_WRITE);
	
	ProcInfo.hTty    = hTty;
	ProcInfo.hStdIn  = hCon;
	ProcInfo.hStdOut = hCon;
	ProcInfo.hStdErr = hCon;
	Process_CreateEx(System_Boot, 0, 1024, PROCESS_PRIORITY_NORMAL, &ProcInfo);
	
	return;
}


/* システムプロセス */
int System_Boot(VPARAM Param)
{
	/* シェル起動 */
	return Command_Execute("hsh", NULL);
}



/* end of file */
