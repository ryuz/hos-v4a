/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "sysapi_local.h"
#include "kernel.h"


C_SYSMEMHEAP		SysMem_SysMemHeap;			/* システムメモリ */
C_VALMEMHEAP		SysMem_ValMemHeap;			/* システムヒープメモリ */

SYSMTX_HANDLE		SysIo_hMtx;					/* I/O用ヒープメモリ管理用ミューテックス */
C_VALMEMHEAP		*SysIo_pValMemHeap = NULL;	/* I/O用ヒープメモリ */

T_SYSPRC_INF		*SysPrc_InfTbl;				/* プロセス管理用テーブル */
T_SYSINT_INF		*SysInt_InfTbl;				/* INT管理用テーブル */



/* システムの初期化 */
void SysApi_Initialize(void *pMem, MEMSIZE MemSize, MEMSIZE MemAlign, void *pIoMem, MEMSIZE IoMemSize, MEMSIZE IoMemAlign)
{
	/* メモリ管理の初期化 */
	ValMemHeap_Constructor(&SysMem_ValMemHeap, pMem, MemSize, MemAlign);			/* メモリヒープ生成 */
	SysMemHeap_Constructor(&SysMem_SysMemHeap, (C_MEMHEAP *)&SysMem_ValMemHeap);
	
	/* プロセス管理テーブルメモリ確保 */
	SysPrc_InfTbl = (T_SYSPRC_INF *)SysMem_Alloc(sizeof(T_SYSPRC_INF) * (_kernel_max_tskid + 1));
	memset(SysPrc_InfTbl, 0, sizeof(T_SYSPRC_INF) * _kernel_max_tskid);

	/* ISR管理テーブルメモリ確保 */
	SysInt_InfTbl = (T_SYSINT_INF *)SysMem_Alloc(sizeof(T_SYSINT_INF) * (_kernel_max_intno - _kernel_min_intno + 1));
	memset(SysInt_InfTbl, 0, sizeof(T_SYSINT_INF) * (_kernel_max_intno - _kernel_min_intno + 1));
	
	/* I/O用メモリ管理 */
	if ( pIoMem != NULL )
	{
		SysIo_hMtx = SysMtx_Create(SYSMTX_ATTR_NORMAL);								/* メモリ管理用排他制御用ミューテックス生成 */	
		SysIo_pValMemHeap = SysMem_Alloc(sizeof(C_VALMEMHEAP));
		ValMemHeap_Constructor(SysIo_pValMemHeap, pIoMem, IoMemSize, IoMemAlign);	/* メモリヒープ生成 */	
	}
}


/* end of file */
