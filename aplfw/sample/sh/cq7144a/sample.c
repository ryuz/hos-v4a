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
#include "driver/serial/renesas/scifile.h"
#include "regs_sh7144.h"


long     g_SystemHeap[16 * 1024 / sizeof(long)];
C_SCIDRV g_SciDrv[4];



/** %jp{初期化ハンドラ} */
void Sample_Initialize(VP_INT exinf)
{
	System_Initialize(g_SystemHeap, sizeof(g_SystemHeap));
}

int Shell_InputTty(HANDLE hTty, char *pszBuf, int iBufSize);

void Sample_Task(VP_INT exinf)
{
	T_SYSFILE_DEVINF devinf;
	
	
	/*************************/
	/*    固有初期設定       */
	/*************************/
	
	*REG_STANDBY_MSTCR1 &= ~0x0002;	/* %jp{SCI1のスタンバイモードを解除} */
	*REG_PFC_PACRL2 |= 0x0100;		/* %jp{端子設定} */
	
	
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
	/*     ちょいテスト      *
	/*************************/
	{
		HANDLE hFile;
		char c;
		char buf[256];
		
		hFile = File_Open("/dev/com1", FILE_MODE_READ | FILE_MODE_WRITE);
		
		for ( ; ; )
		{
			File_PutChar(hFile, 'X');
			dly_tsk(100);
		}
		
		File_PutString(hFile, "Hello!\r\n");
		
		Shell_InputTty(hFile, buf, sizeof(buf));
		
		for ( ; ; )
		{
			c = File_GetChar(hFile);
			
			File_PrintHexByte(hFile, c);
			File_PutChar(hFile, '\r');
			File_PutChar(hFile, '\n');
		}
	}
}

void Sample_Print(VP_INT exinf)
{
}

/* end of file */
