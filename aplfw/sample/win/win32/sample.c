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


long         g_SystemHeap[8 * 1024 / sizeof(long)];
C_WINSOCKDRV g_WinSockDrv[1];
C_VT100DRV   g_Vt100Drv[1];



/** %jp{初期化ハンドラ} */
void Sample_Initialize(VP_INT exinf)
{
}

/* 初期化タスク */
void Sample_Startup(VP_INT exinf)
{
	HANDLE         hTty;
	HANDLE         hCon;
	

	/*************************/
	/*       初期化          */
	/*************************/
	
	/* システム初期化 */
	System_Initialize(g_SystemHeap, sizeof(g_SystemHeap));



	/*************************/
	/*     デバドラ登録      */
	/*************************/

	/* WinSock用擬似シリアルデバドラ生成 */
	WinSockDrv_Create(&g_WinSockDrv[0], 9997, 1, 64);
	
	/*  /dev/com0 に登録 */
	File_AddDevice("com0", (C_DRVOBJ *)&g_WinSockDrv[0]);

	/* /dev/com0 の上に VT100コンソールを形成 */
	hTty = File_Open("/dev/com0", FILE_OPEN_READ | FILE_OPEN_WRITE);
	Vt100Drv_Create(&g_Vt100Drv[0], hTty);

	/*  /dev/con0 に登録 */
	File_AddDevice("con0", (C_DRVOBJ *)&g_Vt100Drv[0]);

	/* コンソールを開く */
	hCon = File_Open("/dev/con0", FILE_OPEN_READ | FILE_OPEN_WRITE);


	/*************************/
	/*     コマンド登録      */
	/*************************/
	Command_Initialize();
	Command_AddCommand("hsh",     Shell_Main);
	Command_AddCommand("hello",   Hello_Main);
	
	
	/*************************/
	/*  システムプロセス起動 */
	/*************************/
	
	System_Boot(hTty, hCon, "hsh", 1024);
}



/* end of file */
