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
#include "system/file/filesys.h"
#include "system/sysapi/sysapi.h"
#include "driver/serial/renesas/scidrv.h"
#include "driver/serial/renesas/scifile.h"
#include "driver/serial/panasonic/scdrv.h"
#include "driver/serial/panasonic/scfile.h"


long g_SystemHeap[8 * 1024 / sizeof(long)];

// C_SCIHAL g_SciHal;
C_SCIDRV        g_SciDrv[2];
SYSEVT_HANDLE   g_hEvt;
SYSEVT_HANDLE   g_hEvt2;
C_STREAMBUF     g_StmBuf;

C_SCDRV        g_ScDrv[1];

#define REG_SC3_CTR				((volatile unsigned short *)0x9C00C010)
#define REG_SC3_RB				((volatile unsigned char *)0x9C00C014)
#define REG_SC3_TB				((volatile unsigned char *)0x9C00C018)
#define REG_SC3_STR 			((volatile unsigned char *)0x9C00C01D)


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

	{
		T_SCDRV_REGS ScRegs;
		ScRegs.puhCtr = REG_SC3_CTR;
		ScRegs.pubRb  = REG_SC3_RB;
		ScRegs.pubTb  = REG_SC3_TB;
		ScRegs.pubStr = REG_SC3_STR;
		ScDrv_Create(&g_ScDrv[0], &ScRegs, 15*4 + 2, 15*4 + 3, 64);

		/* SCI1 を /dev/com1 に登録 */
		strcpy(devinf.szName, "com3");
		devinf.pfncCreate = ScFile_Create;
		devinf.ObjSize    = sizeof(C_SCFILE);
		devinf.pParam     = &g_ScDrv[0];
		SysFile_AddDevice("/dev", &devinf);
	}

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

			File_PutChar(hFile, c + 1);
			File_PutChar(hFile, '\r');
			File_PutChar(hFile, '\n');
		}
	}
}

void Sample_Task(VP_INT exinf)
{
}



/* end of file */
