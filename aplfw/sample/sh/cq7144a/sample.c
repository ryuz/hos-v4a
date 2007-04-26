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
#include "hosaplfw.h"
#include "system/sysapi/sysapi.h"
#include "system/file/file.h"
#include "system/file/confile.h"
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
	T_FILE_DEVINF    DevInf;
	T_PROCESS_INFO   ProcInfo;
	HANDLE           hTty;
	HANDLE           hCon;
	
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
	File_Initialize();
	Command_Initialize();
	
	
	/* SCIデバドラ生成 */
	SciDrv_Create(&g_SciDrv[0], (void *)REG_SCI0_SMR, 128, 24000000L, 64);	/* SCI0 */
	SciDrv_Create(&g_SciDrv[1], (void *)REG_SCI1_SMR, 132, 24000000L, 64);	/* SCI1 */
	SciDrv_Create(&g_SciDrv[2], (void *)REG_SCI2_SMR, 168, 24000000L, 64);	/* SCI2 */
	SciDrv_Create(&g_SciDrv[3], (void *)REG_SCI3_SMR, 172, 24000000L, 64);	/* SCI3 */
	
	/* SCI0 を /dev/com0 に登録 */
	strcpy(DevInf.szName, "com0");
	DevInf.pfncCreate = SciFile_Create;
	DevInf.ObjSize    = sizeof(C_SCIFILE);
	DevInf.pParam     = &g_SciDrv[0];
	File_AddDevice(&DevInf);
	
	/* SCI1 を /dev/com1 に登録 */
	strcpy(DevInf.szName, "com1");
	DevInf.pfncCreate = SciFile_Create;
	DevInf.ObjSize    = sizeof(C_SCIFILE);
	DevInf.pParam     = &g_SciDrv[1];
	File_AddDevice(&DevInf);
	
	
	/*************************/
	/*     コマンド登録      */
	/*************************/
	Command_AddCommand("hsh",   Shell_Main);
	Command_AddCommand("hello", Hello_Main);
	
	/*************************/
	/*  システムプロセス起動 */
	/*************************/
	hTty = File_Open("/dev/com1", FILE_MODE_READ | FILE_MODE_WRITE);
	
	
	strcpy(DevInf.szName, "con1");
	DevInf.pfncCreate = ConsoleFile_Create;
	DevInf.ObjSize    = sizeof(C_CONSOLEFILE);
	DevInf.pParam     = hTty;
	File_AddDevice(&DevInf);
	hCon = File_Open("/dev/con1", FILE_MODE_READ | FILE_MODE_WRITE);
	
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
	StdIo_PutString("\n\n"
		"-------------------------------------------------------------\n"
		" HOS-V4 Advance\n"
		"  HOS Application Framework\n"
		"\n"
		"                      Copyright (C) 1996-2007 by Project HOS \n"
		"-------------------------------------------------------------\n");
	
	/* シェル起動 */
	return Command_Execute("hsh", NULL);
}



/* end of file */
