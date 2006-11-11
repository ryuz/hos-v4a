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
#include "system/sysapi/sysapi.h"
#include "driver/serial/renesas/scifile.h"


long g_SystemHeap[8 * 1024 / sizeof(long)];

// C_SCIHAL g_SciHal;
C_SCIDRV        g_SciDrv[2];
SYSEVT_HANDLE   g_hEvt;
SYSEVT_HANDLE   g_hEvt2;
C_STREAMBUF     g_StmBuf;



/** %jp{初期化ハンドラ} */
void Sample_Initialize(VP_INT exinf)
{
	g_hEvt  = SysEvt_Create();
	g_hEvt2 = SysEvt_Create();
}

void SysDbg_PutChar(int c)
{
}

char g_Buf[16];

void Sample_Startup(VP_INT exinf)
{
	T_SYSFILE_DEVINF devinf;

	iset_flg((ID)g_hEvt, 1);
	set_flg((ID)g_hEvt, 1);

	/*************************/
	/*       初期化          *
	/*************************/
	
	/* システム初期化 */
	System_Initialize(g_SystemHeap, sizeof(g_SystemHeap));

	/* SCIデバドラ生成 */
	SciDrv_Create(&g_SciDrv[0], (void *)0xffffb0, 52, 20000000L, 64);	/* SCI0 */
	SciDrv_Create(&g_SciDrv[1], (void *)0xffffb8, 56, 20000000L, 64);	/* SCI1 */
	
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
		int c;

		hFile = File_Open("/dev/com1", FILE_MODE_READ | FILE_MODE_WRITE);
		for ( ; ; )
		{
			File_Read(hFile, &c, 1);		/* 1文字読み込み */

			File_PrintHexByte(hFile, c);
			File_PutChar(hFile, '\r');
			File_PutChar(hFile, '\n');
		}
	}
}

void Sample_Task(VP_INT exinf)
{
}



/* end of file */
