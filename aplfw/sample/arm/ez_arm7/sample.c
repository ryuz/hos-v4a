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


#define REG_PLLCON		((volatile UB *)0xe01fc080)
#define REG_PLLCFG		((volatile UB *)0xe01fc084)
#define REG_PLLSTAT		((volatile UH *)0xe01fc088)
#define REG_PLLFEED		((volatile UB *)0xe01fc08c)
#define REG_PINSEL0		((volatile UW *)0xe002c000)
#define REG_BCFG0		((volatile UW *)0xffe00000)


void Sample_Task(VP_INT exinf)
{
	HANDLE			hTty;
	HANDLE			hCon;
	
	/*************************/
	/*    固有初期設定       */
	/*************************/
	
	/* PLL設定 */
#if 0
	*REG_PLLCFG   = ((0x1 << 5) | (0x3 << 0));	/* M=4, P=2 (Fosc=14.7MHz, Fcco=235.2MHz, cclk=58.8MHz) */
	*REG_PLLCON  |= 0x01;
	*REG_PLLFEED  = 0xaa;
	*REG_PLLFEED  = 0x55;
	while ( !(*REG_PLLSTAT & 0x0400) )
		;
	*REG_PLLCON  |= 0x02;
	*REG_PLLFEED  = 0xaa;
	*REG_PLLFEED  = 0x55;
#endif
	
	/* Pin設定 */
	*REG_PINSEL0 = (*REG_PINSEL0 & 0xfffffff0) | 0x05;
	*REG_BCFG0   = ((0x1 << 28) | (0x02 << 11) | (0x02 << 5) | (0x02 << 0));
//	*REG_BCFG0   = ((0x1 << 28) | (0x0f << 11) | (0x0f << 5) | (0x0f << 0));
	
	
	/*************************/
	/*       初期化          */
	/*************************/
	
	/* システム初期化 */
	System_Initialize(g_SystemHeap, sizeof(g_SystemHeap));
	
	
	/*************************/
	/*   デバイスドライバ    */
	/*************************/
	
	/* 16550デバドラ生成 (/dev/com0 に登録) */
	Pc16550Drv_Create(&g_Pc16550Drv[0], (void *)0xe000c000, 2, 6, 14700000/4, 64);
	File_AddDevice("com0", (C_DRVOBJ *)&g_Pc16550Drv[0]);

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
