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
#include "system/system/system.h"
#include "system/sysapi/sysapi.h"
#include "system/file/console.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "system/shell/shell.h"
#include "driver/serial/renesas/scidrv.h"
#include "driver/console/vt100/vt100drv.h"
#include "apl/hello/hello.h"
#include "apl/util/memdump/memdump.h"
#include "apl/util/memwrite/memwrite.h"
#include "apl/util/memtest/memtest.h"
#include "apl/util/keytest/keytest.h"
#include "regs_sh7144.h"


long		g_SystemHeap[16 * 1024 / sizeof(long)];
C_SCIDRV	g_SciDrv[4];
C_VT100DRV	g_Vt100Drv[1];



void Sample_Task(VP_INT exinf)
{
	HANDLE			hTty;
	HANDLE			hCon;
	
	
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
	
	
	
	/*************************/
	/*   デバイスドライバ    */
	/*************************/
	
	/* SCIデバドラ生成 */
	SciDrv_Create(&g_SciDrv[0], (void *)REG_SCI0_SMR, 128, 24000000L, 64);	/* SCI0 */
	SciDrv_Create(&g_SciDrv[1], (void *)REG_SCI1_SMR, 132, 24000000L, 64);	/* SCI1 */
	SciDrv_Create(&g_SciDrv[2], (void *)REG_SCI2_SMR, 168, 24000000L, 64);	/* SCI2 */
	SciDrv_Create(&g_SciDrv[3], (void *)REG_SCI3_SMR, 172, 24000000L, 64);	/* SCI3 */
	
	File_AddDevice("com0", (C_DRVOBJ *)&g_SciDrv[0]);	/* SCI0 を /dev/com0 に登録 */
	File_AddDevice("com1", (C_DRVOBJ *)&g_SciDrv[1]);	/* SCI1 を /dev/com0 に登録 */
	File_AddDevice("com2", (C_DRVOBJ *)&g_SciDrv[2]);	/* SCI2 を /dev/com0 に登録 */
	File_AddDevice("com3", (C_DRVOBJ *)&g_SciDrv[3]);	/* SCI3 を /dev/com0 に登録 */
	
	
	/* シリアルを開く */
	hTty = File_Open("/dev/com0", FILE_OPEN_READ | FILE_OPEN_WRITE);
	
	/* シリアル上にコンソールを生成( /dev/con0 に登録) */
	Vt100Drv_Create(&g_Vt100Drv[0], hTty);
	File_AddDevice("con0", (C_DRVOBJ *)&g_Vt100Drv[0]);
	
	/* コンソールを開く */
	hCon = File_Open("/dev/con0", FILE_OPEN_READ | FILE_OPEN_WRITE);
	
	
	
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
	System_Boot(hTty, hCon, "hsh", 4096);
}



/* end of file */
