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
#include "application/example/hello/hello.h"
#include "application/utility/memdump/memdump.h"
#include "application/utility/memwrite/memwrite.h"
#include "application/utility/memtest/memtest.h"
#include "application/utility/keytest/keytest.h"
#include "boot.h"


long         g_SystemHeap[64 * 1024 / sizeof(long)];


#define REG_PLLCON		((volatile UB *)0xe01fc080)
#define REG_PLLCFG		((volatile UB *)0xe01fc084)
#define REG_PLLSTAT		((volatile UH *)0xe01fc088)
#define REG_PLLFEED		((volatile UB *)0xe01fc08c)
#define REG_PINSEL0		((volatile UW *)0xe002c000)
#define REG_BCFG0		((volatile UW *)0xffe00000)


int Boot_Process(VPARAM Param);


void Boot_Task(VP_INT exinf)
{
	T_SYSTEM_INITIALIZE_INF	SysInf;
	
	
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
	*REG_BCFG0   = ((0x1 << 28) | (0x03 << 11) | (0x03 << 5) | (0x03 << 0));
//	*REG_BCFG0   = ((0x1 << 28) | (0x0f << 11) | (0x0f << 5) | (0x0f << 0));
	
	
	/*************************/
	/*       初期化          */
	/*************************/
	
	/* システム初期化 */
	SysInf.pHeapMem        = g_SystemHeap;
	SysInf.HeapSize        = sizeof(g_SystemHeap);
	SysInf.SystemStackSize = 1024;
	SysInf.pfncBoot        = Boot_Process;
	SysInf.BootParam       = (VPARAM)0;
	SysInf.BootStackSize   = 1024;
	System_Initialize(&SysInf);
}


/* ブートプロセス */
int Boot_Process(VPARAM Param)
{
	HANDLE	hTty;
	HANDLE	hCon;
	HANDLE	hDriver;
	
	
	/*************************/
	/*   デバイスドライバ    */
	/*************************/
	
	/* 16550デバドラ生成 (/dev/com0 に登録) */
	hDriver = Pc16550Drv_Create((void *)0xe000c000, 2, 6, 14700000/4, 64);
	File_AddDevice("com0", hDriver);

	/* シリアルを開く */
	hTty = File_Open("/dev/com0", FILE_OPEN_READ | FILE_OPEN_WRITE);
	
	/* シリアル上にコンソールを生成( /dev/con0 に登録) */
	hDriver = Vt100Drv_Create(hTty);
	File_AddDevice("con0", hDriver);
	
	/* コンソールを開く */
	hCon = File_Open("/dev/con0", FILE_OPEN_READ | FILE_OPEN_WRITE);
	
	
	/*************************/
	/*     標準入出力設定    */
	/*************************/
	
	Process_SetTerminal(HANDLE_NULL, hTty);
	Process_SetConsole(HANDLE_NULL, hCon);
	Process_SetStdIn(HANDLE_NULL, hCon);
	Process_SetStdOut(HANDLE_NULL, hCon);
	Process_SetStdErr(HANDLE_NULL, hCon);
	
	
	/*************************/
	/*     コマンド登録      */
	/*************************/
	Command_AddCommand("hsh",      Shell_Main);
	Command_AddCommand("hello",    Hello_Main);
	Command_AddCommand("memdump",  MemDump_Main);
	Command_AddCommand("memwrite", MemWrite_Main);
	Command_AddCommand("memtest",  MemTest_Main);
	Command_AddCommand("keytest",  KeyTest_Main);
	
	
	/* 起動メッセージ */
	StdIo_PutString(
			"\n\n"
			"================================================================\n"
			" Hyper Operating System  Application Flamework\n"
			"\n"
			"                          Copyright (C) 1998-2008 by Project HOS\n"
			"                          http://sourceforge.jp/projects/hos/\n"
			"================================================================\n"
			"\n");
	
	/*************************/
	/*      シェル起動       */
	/*************************/
	
	Command_Execute("hsh -i", NULL);
}



/* end of file */
