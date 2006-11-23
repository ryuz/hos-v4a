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
#include "system/file/stdfile.h"
#include "system/command/command.h"
#include "system/shell/shell.h"
#include "driver/serial/renesas/scifile.h"
#include "apl/hello/hello.h"


#define SYSCR		((volatile unsigned char *)0xfee012)
#define IPRB		((volatile unsigned char *)0xfee019)

/* long     g_SystemHeap[16 * 1024 / sizeof(long)]; */
C_SCIDRV g_SciDrv[2];


int System_Boot(VPARAM Param);


void Sample_Startup(VP_INT exinf)
{
	T_SYSFILE_DEVINF devinf;
	T_PROCESS_INFO   ProcInfo;
	HANDLE           hFile;
	
	/*************************/
	/*       固有設定        */
	/*************************/
	*SYSCR &= ~0x08;		/* UIビットを割込みマスクに使う */
	*IPRB  |=  0x0e;		/* SCI1の割り込み優先度を上げる */
	
	/*************************/
	/*       初期化          */
	/*************************/
	
	/* システム初期化 */
/*	System_Initialize(g_SystemHeap, sizeof(g_SystemHeap));	*/
	System_Initialize((void *)0x00500000, 0x00100000);
	
	/*************************/
	/*     デバドラ登録      */
	/*************************/
	
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
	
	
	/*************************/
	/*     コマンド登録      */
	/*************************/
	Command_Initialize();
	Command_AddCommand("hsh",   Shell_Main);	/* シェルの登録 */
	Command_AddCommand("hello", Hello_Main);	/* Hello World の登録 */
	
	
	/*************************/
	/*  システムプロセス起動 */
	/*************************/
	hFile = File_Open("/dev/com1", FILE_MODE_READ | FILE_MODE_WRITE);
	ProcInfo.hTty    = hFile;
	ProcInfo.hStdIn  = hFile;
	ProcInfo.hStdOut = hFile;
	ProcInfo.hStdErr = hFile;
	Process_CreateEx(System_Boot, 0, 1024, PROCESS_PRIORITY_NORMAL, &ProcInfo);
}


/* システムプロセス */
int System_Boot(VPARAM Param)
{
	StdIo_PutString("\r\nHOS Application Platform  Ver 0.01\r\n");
	
	/* シェル起動 */
	return Command_Execute("hsh");
}



/* end of file */