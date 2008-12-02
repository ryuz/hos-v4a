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
#include "system/system/system.h"
#include "system/sysapi/sysapi.h"
#include "system/file/console.h"
#include "system/process/process.h"
#include "system/command/command.h"
/* #include "driver/ether/lan9118/lan9118drv.h" */
#include "driver/tcpip/ipether/ipether.h"
#include "driver/tcpip/tcpip/tcpip.h"
#include "driver/serial/at91/at91usartdrv.h"
#include "driver/console/vt100/vt100drv.h"
#include "driver/volume/fat/fatvol.h"
#include "application/syscmd/shell/shell.h"
#include "application/flashcmd/norflashcmd/norflashcmd.h"
#include "application/utility/memdump/memdump.h"
#include "application/utility/memwrite/memwrite.h"
#include "application/utility/memtest/memtest.h"
#include "application/utility/keytest/keytest.h"
#include "application/utility/timecmd/timecmd.h"
#include "application/netcmd/ethersnoop/ethersnoop.h"
#include "application/example/hello/hello.h"
#include "boot.h"
#include "ostimer.h"


long			g_SystemHeap[32 * 1024 / sizeof(long)];


/* IP層生成情報 */
static const T_IPETHER_INF IpEtherInf =
{
	{192, 168,   0, 100},		/* IPアドレス */
	{255, 255, 255,   0},		/* サブネットマスク */
	{192, 168,   0,   1},		/* デフォルトゲートウェイアドレス */
};


int Boot_Process(VPARAM Param);

/* ブートタスク */
void Boot_Task(VP_INT exinf)
{
	T_SYSTEM_INITIALIZE_INF	SysInf;

	
	/*************************/
	/*    固有初期設定       */
	/*************************/
	
	
	
	/*************************/
	/*       初期化          */
	/*************************/
	
	/* システム初期化 */
	memset(&SysInf, 0, sizeof(SysInf));
	SysInf.pSysMemBase     = g_SystemHeap;
	SysInf.SysMemSize      = sizeof(g_SystemHeap);
	SysInf.SysMemAlign     = 4;
	SysInf.pIoMemBase      = NULL;
	SysInf.SystemStackSize = 1024;
	SysInf.pfncBoot        = Boot_Process;
	SysInf.BootParam       = (VPARAM)0;
	SysInf.BootStackSize   = 4096;
	System_Initialize(&SysInf);
}


/* ブートプロセス */
int Boot_Process(VPARAM Param)
{
	HANDLE	hTty;
	HANDLE	hCon;
	HANDLE	hDriver;
	
	
	OsTimer_Initialize();
	
	
	/*************************/
	/*   デバイスドライバ    */
	/*************************/
	
#if 0
	/* LAN9118デバドラ生成 (/dev/eth0 に登録) */
	Lan9118Drv_Create(&g_Lan9118Drv[0], (void *)0x40000000, 24);
	File_AddDevice("eth0", (C_DRVOBJ *)&g_Lan9118Drv[0]);
	
	/* Ether上にIP層構築 (/dev/ip0 に登録) */
	IpEther_Create(&g_IpEther[0], "/dev/eth0", &IpEtherInf);
	File_AddDevice("ip0", (C_DRVOBJ *)&g_IpEther[0]);

	/* IP層の上にTCP/IP層構築 (/dev/tcpip0 に登録) */
	TcpIp_Create(&g_TcpIp[0], "/dev/ip0");
	File_AddDevice("tcpip0", (C_DRVOBJ *)&g_TcpIp[0]);
#endif	
	
	/* AT91 USARTデバドラ生成 (/dev/com0 に登録) */
	hDriver = At91UsartDrv_Create((void *)0xfffc0000, 2, 32000000, 64);
	File_AddDevice("com0", hDriver);

	/* AT91 USARTデバドラ生成 (/dev/com1 に登録) */
	hDriver = At91UsartDrv_Create((void *)0xfffc4000, 3, 32000000, 64);
	File_AddDevice("com1", hDriver);
	
	/* AT91 USARTデバドラ生成 (/dev/com2 に登録) */
	hDriver = At91UsartDrv_Create((void *)0xfffc8000, 4, 32000000, 64);
	File_AddDevice("com2", hDriver);
	
	/* シリアルを開く */
	hTty = File_Open("/dev/com0", FILE_OPEN_READ | FILE_OPEN_WRITE);
	
	/* シリアル上にコンソールを生成(/dev/con0 に登録) */
	hDriver = Vt100Drv_Create(hTty);
	File_AddDevice("con0", hDriver);
	
	/* コンソールを開く */
	hCon = File_Open("/dev/con0", FILE_OPEN_READ | FILE_OPEN_WRITE);
	

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
	
	Command_AddCommand("hsh",      Shell_Main);
	Command_AddCommand("hello",    Hello_Main);
	Command_AddCommand("memdump",  MemDump_Main);
	Command_AddCommand("memwrite", MemWrite_Main);
	Command_AddCommand("memtest",  MemTest_Main);
	Command_AddCommand("keytest",  KeyTest_Main);
	Command_AddCommand("time",     TimeCmd_Main);
	Command_AddCommand("norflash", NorFlashCmd_Main);
	Command_AddCommand("ethsnoop", EtherSnoop_Main);
	
	/* 起動メッセージ */
	StdIo_PutString(
			"\n\n"
			"================================================================\n"
			" Hyper Operating System  Application Framework\n"
			"\n"
			"                          Copyright (C) 1998-2007 by Project HOS\n"
			"                          http://sourceforge.jp/projects/hos/\n"
			"================================================================\n"
			"\n");
	
	/*************************/
	/*      シェル起動       */
	/*************************/
	
	Command_Execute("hsh -i", NULL);
	
	return 0;
}



/* end of file */
