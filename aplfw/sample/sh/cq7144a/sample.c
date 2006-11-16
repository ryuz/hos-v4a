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
#include "system/file/filesys.h"
#include "system/sysapi/sysapi.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "system/shell/shell.h"
#include "driver/serial/renesas/scifile.h"
#include "apl/hello/hello.h"
#include "regs_sh7144.h"


long     g_SystemHeap[16 * 1024 / sizeof(long)];
C_SCIDRV g_SciDrv[4];


int System_Boot(VPARAM Param);



void Sample_Task(VP_INT exinf)
{
	T_SYSFILE_DEVINF devinf;
	T_PROCESS_INFO   ProcInfo;
	HANDLE           hFile;
	
	/*************************/
	/*    固有初期設定       */
	/*************************/
	
	*REG_STANDBY_MSTCR1 &= ~0x0002;	/* %jp{SCI1のスタンバイモードを解除} */
	*REG_PFC_PACRL2 |= 0x0100;		/* %jp{端子設定} */
	
	*REG_INTC_IPRF = ((*REG_INTC_IPRF & 0xfff0) | 0x0001);
	
	/*************************/
	/*       初期化          *
	/*************************/
	
	/* システム初期化 */
	System_Initialize(g_SystemHeap, sizeof(g_SystemHeap));
	
	/* SCIデバドラ生成 */
	SciDrv_Create(&g_SciDrv[0], (void *)REG_SCI0_SMR, 128, 24000000L, 64);	/* SCI0 */
	SciDrv_Create(&g_SciDrv[1], (void *)REG_SCI1_SMR, 132, 24000000L, 64);	/* SCI1 */
	SciDrv_Create(&g_SciDrv[2], (void *)REG_SCI2_SMR, 168, 24000000L, 64);	/* SCI2 */
	SciDrv_Create(&g_SciDrv[3], (void *)REG_SCI3_SMR, 172, 24000000L, 64);	/* SCI3 */
	
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
	Command_AddCommand("hsh",   Shell_Main);
	Command_AddCommand("hello", Hello_Main);
	
	/*************************/
	/*  システムプロセス起動 */
	/*************************/
	
	hFile = File_Open("/dev/com1", FILE_MODE_READ | FILE_MODE_WRITE);
	
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
