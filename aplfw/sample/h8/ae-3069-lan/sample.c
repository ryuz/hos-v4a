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
#include "system/system/system.h"
#include "system/sysapi/sysapi.h"
#include "system/file/console.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "system/shell/shell.h"
#include "driver/console/vt100/vt100drv.h"
#include "driver/serial/renesas/scidrv.h"
#include "application/example/hello/hello.h"
#include "application/utility/memdump/memdump.h"


#define SYSCR		((volatile unsigned char *)0xfee012)
#define IPRB		((volatile unsigned char *)0xfee019)



void Sample_Startup(VP_INT exinf)
{
	HANDLE	hTty;
	HANDLE	hCon;
	HANDLE	hDriver;
	
	/*************************/
	/*       固有設定        */
	/*************************/
	*SYSCR &= ~0x08;		/* UIビットを割込みマスクに使う */
	*IPRB  |=  0x0e;		/* SCI1の割込み優先度を上げる */
	
	
	/*************************/
	/*       初期化          */
	/*************************/
	
	/* システム初期化 */
	System_Initialize((void *)0x00500000, 0x00100000);
	
	
	/*************************/
	/*     デバドラ登録      */
	/*************************/
	
	/* SCI0 を /dev/com0 に登録 */
	hDriver = SciDrv_Create((void *)0xffffb0, 52, 20000000L, 64);	/* SCI0 */
	SysFile_AddDevice("com0", hDriver);
	
	/* SCI1 を /dev/com1 に登録 */
	hDriver = SciDrv_Create((void *)0xffffb8, 56, 20000000L, 64);	/* SCI1 */
	SysFile_AddDevice("com1", hDriver);
	
	
	/* シリアルを開く */
	hTty = File_Open("/dev/com1", FILE_OPEN_READ | FILE_OPEN_WRITE);
	
	/* シリアル上にコンソールを生成( /dev/con1 に登録) */
	hDriver = Vt100Drv_Create(hTty);
	File_AddDevice("con1", hDriver);
	
	/* コンソールを開く */
	hCon = File_Open("/dev/con1", FILE_OPEN_READ | FILE_OPEN_WRITE);
	
	
	
	/*************************/
	/*     コマンド登録      */
	/*************************/
	Command_AddCommand("hsh",     Shell_Main);		/* シェルの登録 */
	Command_AddCommand("hello",   Hello_Main);		/* Hello World の登録 */
	Command_AddCommand("memdump", MemDump_Main);
	
	
	
	/*************************/
	/*  システムプロセス起動 */
	/*************************/
	System_Boot(hTty, hCon, "hsh", 4096);
}



/* end of file */
