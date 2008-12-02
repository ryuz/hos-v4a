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
#include "hosaplfw.h"
#include "system/system/system.h"
#include "system/sysapi/sysapi.h"
#include "system/file/console.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "driver/serial/mn103/mn103scdrv.h"
#include "driver/console/vt100/vt100drv.h"
#include "application/syscmd/shell/shell.h"
#include "application/filecmd/filelist/filelist.h"
#include "application/utility/memdump/memdump.h"
#include "application/utility/memwrite/memwrite.h"
#include "application/utility/memtest/memtest.h"
#include "application/utility/keytest/keytest.h"
#include "application/example/hello/hello.h"
#include "boot.h"

#define REG_PCNT	((volatile unsigned short *)0x0000aff2)
#define REG_CKCTR	((volatile unsigned short *)0x00008280)

#define REG_P2MD	((volatile unsigned char *)0x0000a032)
#define REG_P2DIR	((volatile unsigned char *)0x0000a022)

#define REG_TM14BR	((volatile unsigned char *)0x0000A1C8)
#define REG_TM14BC	((volatile unsigned char *)0x0000A1D0)
#define REG_TM14MD	((volatile unsigned char *)0x0000A1C0)


int Boot_Process(VPARAM Param);

unsigned long	g_uwSystemHeap[(4 * 1024 + 128) / sizeof(unsigned long)];


/* ブートタスク */
void Boot_Task(VP_INT exinf)
{
	T_SYSTEM_INITIALIZE_INF	SysInf;
	
	
	/*************************/
	/*    固有初期設定       */
	/*************************/
	
	/* クロック設定 */
	*REG_PCNT  = 0x0000;
	*REG_CKCTR = 0x00b3;
	
	/* SC0 ポート設定 */
	*REG_P2MD  = 0x6c;
	*REG_P2DIR = 0x6c;
	
	*REG_TM14BR = 4 - 1;
	*REG_TM14MD = 0x40;
	*REG_TM14MD = 0x80;
	
	*((volatile unsigned char *)0x0000A028) = 0x10;
	*((volatile unsigned char *)0x0000A038) = 0x10;
	
	
	/*************************/
	/*       初期化          */
	/*************************/
	
	/* システム初期化 */
	SysInf.pSysMemBase     = (void *)g_uwSystemHeap;
	SysInf.SysMemSize      = sizeof(g_uwSystemHeap);
	SysInf.SysMemAlign     = 4;
	SysInf.pIoMemBase      = NULL;
	SysInf.SystemStackSize = 256;
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
	
	/* SCデバドラ生成 */
	hDriver = Mn103ScDrv_Create((void*)0x0000a110, 14*4+0, 14*4+1, 32);	/* SC1生成 */
	File_AddDevice("com1", hDriver);									/* /dev/com1 に登録 */
	
	/* シリアルを開く */
	hTty = File_Open("/dev/com1", FILE_OPEN_READ | FILE_OPEN_WRITE);
	
	/* シリアル上にコンソールを生成( /dev/con1 に登録) */
	hDriver = Vt100Drv_Create(hTty);
	File_AddDevice("con1", hDriver);
	
	/* コンソールを開く */
	hCon = File_Open("/dev/con1", FILE_OPEN_READ | FILE_OPEN_WRITE);
	
	
	/*************************/
	/*     標準入出力設定    */
	/*************************/
	
	Process_SetTerminal(HANDLE_NULL, hTty);
	Process_SetConIn(HANDLE_NULL, hCon);
	Process_SetConOut(HANDLE_NULL, hCon);
	Process_SetStdIn(HANDLE_NULL, hCon);
	Process_SetStdOut(HANDLE_NULL, hCon);
	Process_SetStdErr(HANDLE_NULL, hCon);
	
	
	/*************************/
	/*     コマンド登録      */
	/*************************/
	
	Command_AddCommand("sh",       Shell_Main);
	Command_AddCommand("hello",    Hello_Main);
	Command_AddCommand("memdump",  MemDump_Main);
	Command_AddCommand("memwrite", MemWrite_Main);
/*	Command_AddCommand("memtest",  MemTest_Main);	*/
/*	Command_AddCommand("ls",       FileList_Main);	*/
	
	
	/* 起動メッセージ */
	StdIo_PutString(
			"\n\n"
			"================================================================\n"
			" Hyper Operating System  Application Framework\n"
			"\n"
			"                          Copyright (C) 1998-2008 by Project HOS\n"
			"                          http://sourceforge.jp/projects/hos/\n"
			"================================================================\n"
			"\n");
	
	/*************************/
	/*      シェル起動       */
	/*************************/
	
	for ( ; ; )
	{
		Command_Execute("sh -exe -his 0 -buf 128 -i", NULL);
	}
	
	
	return 0;
}



/* end of file */
