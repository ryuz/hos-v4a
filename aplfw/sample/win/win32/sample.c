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
#include "system/file/file.h"
#include "system/file/confile.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "system/shell/shell.h"
#include "driver/serial/winsock/winsockfile.h"
#include "driver/console/vt100/vt100con.h"
#include "apl/hello/hello.h"
#include "apl/memdump/memdump.h"


long         g_SystemHeap[8 * 1024 / sizeof(long)];
C_WINSOCKDRV g_WinSockDrv[1];
C_VT100DRV   g_Vt100Drv[1];


int System_Boot(VPARAM Param);


/** %jp{初期化ハンドラ} */
void Sample_Initialize(VP_INT exinf)
{
}

/* 初期化タスク */
void Sample_Startup(VP_INT exinf)
{
	T_FILE_DEVINF  DevInf;
	T_PROCESS_INF  ProcInf;
	HANDLE         hTty;
	HANDLE         hCon;
	
	/*************************/
	/*       初期化          */
	/*************************/
	
	/* システム初期化 */
	System_Initialize(g_SystemHeap, sizeof(g_SystemHeap));
	File_Initialize();


	/*************************/
	/*     デバドラ登録      */
	/*************************/

	/* WinSock用擬似シリアルデバドラ生成 */
	WinSockDrv_Create(&g_WinSockDrv[0], 9997, 1, 64);
	
	/*  /dev/com0 に登録 */
	strcpy(DevInf.szName, "com0");
	DevInf.pfncCreate = WinSockFile_Create;
	DevInf.ObjSize    = sizeof(C_WINSOCKFILE);
	DevInf.pParam     = &g_WinSockDrv[0];
	File_AddDevice(&DevInf);


	/* /dev/com0 の上に VT100コンソールを形成 */
	hTty = File_Open("/dev/com0", FILE_MODE_READ | FILE_MODE_WRITE);
	Vt100Drv_Create(&g_Vt100Drv[1], hTty);

	/*  /dev/con0 に登録 */
	strcpy(DevInf.szName, "con0");
	DevInf.pfncCreate = Vt100Con_Create;
	DevInf.ObjSize    = sizeof(C_VT100CON);
	DevInf.pParam     = &g_Vt100Drv[1];
	File_AddDevice(&DevInf);

	hCon = File_Open("/dev/con0", FILE_MODE_READ | FILE_MODE_WRITE);

	
	/*************************/
	/*     コマンド登録      */
	/*************************/
	Command_Initialize();
	Command_AddCommand("hsh",     Shell_Main);
	Command_AddCommand("hello",   Hello_Main);
	Command_AddCommand("memdump", MemDump_Main);
	
	
	/*************************/
	/*  システムプロセス起動 */
	/*************************/
	
	ProcInf.hTty     = hTty;
	ProcInf.hConsole = hCon;
	ProcInf.hStdIn   = hCon;
	ProcInf.hStdOut  = hCon;
	ProcInf.hStdErr  = hCon;
	Process_CreateEx(System_Boot, 0, 1024, PROCESS_PRIORITY_NORMAL, &ProcInf);

	return;
}


/* システムプロセス */
int System_Boot(VPARAM Param)
{
	/* シェル起動 */
	return Command_Execute("hsh", NULL);
}



/* end of file */
