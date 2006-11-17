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
#include "system/file/filesys.h"
#include "system/sysapi/sysapi.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "system/shell/shell.h"
#include "driver/serial/winsock/winsockfile.h"
#include "apl/hello/hello.h"


#include "driver/serial/renesas/scidrv.h"
#include "driver/serial/renesas/scifile.h"
#include "driver/serial/panasonic/scdrv.h"
#include "driver/serial/panasonic/scfile.h"


long         g_SystemHeap[8 * 1024 / sizeof(long)];
C_WINSOCKDRV g_WinSockDrv[1];



int System_Boot(VPARAM Param);


/** %jp{初期化ハンドラ} */
void Sample_Initialize(VP_INT exinf)
{
}

/* 初期化タスク */
void Sample_Startup(VP_INT exinf)
{
	T_SYSFILE_DEVINF DevInf;
	T_PROCESS_INFO   ProcInfo;
	HANDLE           hFile;
	
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
	strcpy(DevInf.szName, "com0");
	DevInf.pfncCreate = WinSockFile_Create;
	DevInf.ObjSize    = sizeof(C_WINSOCKFILE);
	DevInf.pParam     = &g_WinSockDrv[0];
	SysFile_AddDevice("/dev", &DevInf);

	/*************************/
	/*     コマンド登録      */
	/*************************/
	Command_Initialize();
	Command_AddCommand("hsh",   Shell_Main);
	Command_AddCommand("hello", Hello_Main);
	
	/*************************/
	/*  システムプロセス起動 */
	/*************************/

	hFile = File_Open("/dev/com0", FILE_MODE_READ | FILE_MODE_WRITE);

	ProcInfo.hTty    = hFile;
	ProcInfo.hStdIn  = hFile;
	ProcInfo.hStdOut = hFile;
	ProcInfo.hStdErr = hFile;
	Process_CreateEx(System_Boot, 0, 1024, PROCESS_PRIORITY_NORMAL, &ProcInfo);

	return;
}


/* システムプロセス */
int System_Boot(VPARAM Param)
{
	/* シェル起動 */
	return Command_Execute("hsh");
}



/* end of file */
