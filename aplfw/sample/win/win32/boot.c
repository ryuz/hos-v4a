/**
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  sample.c
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
#include "hosaplfw.h"
#include "system/system/system.h"
#include "system/sysapi/sysapi.h"
#include "system/file/file.h"
#include "system/file/console.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "driver/serial/winsock/winsockdrv.h"
#include "driver/console/vt100/vt100drv.h"
#include "application/syscmd/shell/shell.h"
#include "application/syscmd/shell/shell.h"
#include "application/syscmd/commandlist/commandlist.h"
#include "application/syscmd/processlist/processlist.h"
#include "application/syscmd/whiteboardcmd/whiteboardcmd.h"
#include "application/filecmd/filelist/filelist.h"
#include "application/filecmd/filecopy/filecopy.h"
#include "application/filecmd/filedump/filedump.h"
#include "application/filecmd/filecat/filecat.h"
#include "application/fatcmd/fatmount/fatmount.h"
#include "application/utility/timecmd/timecmd.h"
#include "application/utility/memdump/memdump.h"
#include "application/utility/memwrite/memwrite.h"
#include "application/utility/memtest/memtest.h"
#include "application/utility/keytest/keytest.h"
#include "application/example/hello/hello.h"
#include "boot.h"


long	g_SystemHeap[1 * 1024 * 1024 / sizeof(long)];


int Boot_Process(VPARAM Param);

/* ブートタスク */
void Boot_Task(VP_INT exinf)
{
	T_SYSTEM_INITIALIZE_INF	SysInf;
	
	
	/*************************/
	/*       初期化          */
	/*************************/
	
	/* システム初期化 */
	SysInf.pSysMemBase     = g_SystemHeap;
	SysInf.SysMemSize      = sizeof(g_SystemHeap);
	SysInf.SysMemAlign     = 16;
	SysInf.pIoMemBase      = NULL;
	SysInf.IoMemSize       = 0;
	SysInf.IoMemAlign      = 16;
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
	
	
	/*************************/
	/*     デバドラ登録      */
	/*************************/

	/* WinSock用擬似シリアルデバドラ生成 */
	hDriver = WinSockDrv_Create(9997, 1, 64);
	File_AddDevice("com0", hDriver);
	
	/* ターミナルを開く */
	hTty = File_Open("/dev/com0", FILE_OPEN_READ | FILE_OPEN_WRITE);
	
	/* /dev/com0 の上に VT100コンソールを形成 */
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
	Command_Initialize();
	Command_AddCommand("sh",         Shell_Main);
	Command_AddCommand("help",       CommandList_Main);
	Command_AddCommand("hello",      Hello_Main);
	Command_AddCommand("whiteboard", WhiteboardCmd_Main);
	Command_AddCommand("time",       TimeCmd_Main);
	Command_AddCommand("memdump",    MemDump_Main);
	Command_AddCommand("memwrite",   MemWrite_Main);
	Command_AddCommand("ps",         ProcessList_Main);
	Command_AddCommand("ls",         FileList_Main);
	Command_AddCommand("cp",         FileCopy_Main);
	Command_AddCommand("cat",        FileCat_Main);
	Command_AddCommand("hello",      Hello_Main);
	
	/* 起動メッセージ */
	StdIo_PutString(
			"\n\n"
			"================================================================\n"
			" Hyper Operating System  Application Framework\n"
			"\n"
			"                          Copyright (C) 1998-2010 by Project HOS\n"
			"                          http://sourceforge.jp/projects/hos/\n"
			"================================================================\n"
			"\n");
	
	/*************************/
	/*      シェル起動       */
	/*************************/
	
	Command_Execute("sh -i", NULL);

	return 0;
}



/* end of file */
