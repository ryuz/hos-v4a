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
#include "kernel.h"
#include "kernel_id.h"
#include "system/sysapi/sysapi.h"
#include "system/process/process.h"
#include "system/file/filesys.h"
#include "system/command/command.h"
#include "system/shell/shell.h"
#include "driver/serial/renesas/scifile.h"
#include "apl/hello/hello.h"


long     g_SystemHeap[16 * 1024 / sizeof(long)];
C_SCIDRV g_SciDrv[2];

int System_Boot(VPARAM Param);


void Sample_Startup(VP_INT exinf)
{
	T_SYSFILE_DEVINF devinf;
	T_PROCESS_INFO   ProcInfo;
	HANDLE           hFile;
	
	/*************************/
	/*       初期化          *
	/*************************/
	
	/* システム初期化 */
	System_Initialize(g_SystemHeap, sizeof(g_SystemHeap));
	
	/* SCIデバドラ生成 */
	SciDrv_Create(&g_SciDrv[0], (void *)0xffffb0, 52, 20000000L, 64);	/* SCI0 */
	SciDrv_Create(&g_SciDrv[1], (void *)0xffffb8, 56, 20000000L, 64);	/* SCI1 */
	
	/* SCI0 を /dev/com0 に登録 */
	strcpy(devinf.szName, "com0");
	devinf.pfncCreate = SciFile_Create;
	devinf.ObjSize    = sizeof(C_SCIFILE);
	devinf.pParam     = &g_SciDrv[0];
	SysFile_AddDevice("/dev", &devinf);
	
	/* SCI1 を /dev/com1 に登録 */
	strcpy(devinf.szName, "com1");
	devinf.pfncCreate = SciFile_Create;
	devinf.ObjSize    = sizeof(C_SCIFILE);
	devinf.pParam     = &g_SciDrv[1];
	SysFile_AddDevice("/dev", &devinf);
	
	hFile = File_Open("/dev/com1", FILE_MODE_READ | FILE_MODE_WRITE);
	File_PutString(hFile, "XXXX");
	
	/*************************/
	/*     コマンド登録      */
	/*************************/
	Command_Initialize();
	Command_AddCommand("hsh",   Shell_Main);
	Command_AddCommand("hello", Hello_Main);
	
	/*************************/
	/*  システムプロセス起動 */
	/*************************/

	ProcInfo.hTty    = hFile;
	ProcInfo.hStdIn  = hFile;
	ProcInfo.hStdOut = hFile;
	ProcInfo.hStdErr = hFile;
	Process_CreateEx(System_Boot, 0, 1024, PROCESS_PRIORITY_NORMAL, &ProcInfo);
}


/* システムプロセス */
int System_Boot(VPARAM Param)
{
	/* シェル起動 */
	return Command_Execute("hsh");
}



/* end of file */
