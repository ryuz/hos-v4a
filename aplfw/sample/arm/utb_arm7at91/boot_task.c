/**
 * Hyper Operating System  Application Framework Library
 *   μTeaboard/ARM7-AT91 用サンプルプログラム
 *
 * @file  boot_task.c
 * @brief %jp{サンプルプログラム}%en{Sample program}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kernel.h"
#include "kernel_id.h"
#include "boot_task.h"
#include "system/system/system.h"
#include "system/sysapi/sysapi.h"
#include "system/file/console.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "system/shell/shell.h"
#include "driver/ether/lan9000/lan9000drv.h"
#include "driver/tcpip/ipether/ipether.h"
#include "driver/tcpip/tcpip/tcpip.h"
#include "driver/serial/at91/at91usartdrv.h"
#include "driver/console/vt100/vt100drv.h"
#include "application/example/hello/hello.h"
#include "application/utility/memdump/memdump.h"
#include "application/utility/memwrite/memwrite.h"
#include "application/utility/memtest/memtest.h"
#include "application/utility/keytest/keytest.h"
#include "application/utility/timecmd/timecmd.h"
#include "application/netcmd/ethersnoop/ethersnoop.h"


long			g_SystemHeap[32 * 1024 / sizeof(long)];

C_AT91USARTDRV	g_At91UsartDrv[3];
C_VT100DRV		g_Vt100Drv[1];



void Boot_Task(VP_INT exinf)
{
	HANDLE			hTty;
	HANDLE			hCon;
	
	/*************************/
	/*    固有初期設定       */
	/*************************/
	
	
	
	/*************************/
	/*       初期化          */
	/*************************/
	
	/* システム初期化 */
	System_Initialize(g_SystemHeap, sizeof(g_SystemHeap));
	
	
	/*************************/
	/*   デバイスドライバ    */
	/*************************/
	
	/* At91UartDrvデバドラ生成 (/dev/com0 に登録) */
	At91UsartDrv_Create(&g_At91UsartDrv[0], (void *)0xfffc0000, 2, 32000000, 64);
	File_AddDevice("com0", (C_DRVOBJ *)&g_At91UsartDrv[0]);

	/* At91UartDrvデバドラ生成 (/dev/com1 に登録) */
	At91UsartDrv_Create(&g_At91UsartDrv[1], (void *)0xfffc4000, 3, 32000000, 64);
	File_AddDevice("com1", (C_DRVOBJ *)&g_At91UsartDrv[0]);

	/* At91UartDrvデバドラ生成 (/dev/com2 に登録) */
	At91UsartDrv_Create(&g_At91UsartDrv[2], (void *)0xfffc8000, 4, 32000000, 64);
	File_AddDevice("com2", (C_DRVOBJ *)&g_At91UsartDrv[0]);
	
	
	/* シリアルを開く */
	hTty = File_Open("/dev/com0", FILE_OPEN_READ | FILE_OPEN_WRITE);
	
	/* シリアル上にコンソールを生成(/dev/con0 に登録) */
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
	Command_AddCommand("time",     TimeCmd_Main);
	Command_AddCommand("ethsnoop", EtherSnoop_Main);
	
	/*************************/
	/*  システムプロセス起動 */
	/*************************/
	System_Boot(hTty, hCon, "hsh", 4096);
}



/* end of file */
